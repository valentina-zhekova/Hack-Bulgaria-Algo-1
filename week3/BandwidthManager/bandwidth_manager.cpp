/*
Bandwidth Manager:
A router is a network device which receives packets and
forwards them on their route to the next network device.
In some cases due to network congestion it might happen
that the router receives more packets than it can send.
To ensure the best experience to the end user, the
router forwards the packets with a certain
priority using a program called Network Scheduler.
Write a simple network scheduler which forwards the packets
with protocol-based priority. Below is a list of protocols,
ordered by their priorities (highest priority first):
● ICMP
● UDP
● RTM
● IGMP
● DNS
● TCP
If two packets have the same protocol, the one
which came first should be forwarded first.
The network scheduler should implement the following commands:
rcv [protocol name] [payload] - receives a packet with the
                                specified protocol and payload;
                                2 <= payload size <= 128
send - returns the payload of the packet which has to be sent

Input:
The first line of the standard input will contain a single integer:
N - the number of commands; 1 <= N <= 100000
Each of the following N lines will contain a
single command in the format specified above.

Output:
After each send command, print the payload
of the packet that should be sent.
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Packet {
    int priority;
    int orderOfarrival;
    string payload;

    Packet(int priority, int orderOfArrival, string payload) {
        this->priority = priority;
        this->orderOfarrival = orderOfArrival;
        this->payload = payload;
    }
};

bool operator<(const Packet& left, const Packet& right) {
    return ((left.priority > right.priority) ||
            ((left.priority == right.priority) && (left.orderOfarrival > right.orderOfarrival)));
}

class BandwidthManager {
public:
    BandwidthManager() {
        protocolPriority["ICMP"] = 0;
        protocolPriority["UDP"] = 1;
        protocolPriority["RTM"] = 2;
        protocolPriority["IGMP"] = 3;
        protocolPriority["DNS"] = 4;
        protocolPriority["TCP"] = 5;

        for (int i = 0; i < 6; i++) {
            orderOfArrival[i] = 0;
        }
    }

    void rcv(string protocol, string payload) {
        int priority = protocolPriority[protocol];
        orderOfArrival[priority] ++;
        Packet newOne(priority, orderOfArrival[priority], payload);
        scheduler.push_back(newOne);
        bubble(scheduler.size() - 1);
    }

    string send() {
        string result = "Nothing to send!";
        if (!scheduler.empty()) {
            result = scheduler[0].payload;
            scheduler[0] = scheduler[scheduler.size() - 1];
            scheduler.pop_back();
            sink(0);
        }
        return result;
    }

private:
    void swap(int index1, int index2) {
        Packet temporary = scheduler[index1];
        scheduler[index1] = scheduler[index2];
        scheduler[index2] = temporary;
    }

    void bubble(int index) {
        int parent = (index - 1) / 2;
        while ((index != 0) && (scheduler[parent] < scheduler[index])) {
            swap(index, parent);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    int greaterChild(int current) {
        int LChild = current * 2 + 1;
        int RChild = current * 2 + 2;
        int limit = scheduler.size();
        int result = -1; // has no children
        if (LChild < limit && RChild < limit) {
            result = (scheduler[LChild] < scheduler[RChild]) ? RChild : LChild;
        } else if (LChild < limit) {
            result = LChild;
        }
        return result;
    }

    void sink(int index) {
        int toSwap = greaterChild(index);
        while ((toSwap != -1) && (scheduler[index] < scheduler[toSwap])) {
            swap(index, toSwap);
            index = toSwap;
            toSwap = greaterChild(index);
        }
    }

    int orderOfArrival[6];

    map<string, int> protocolPriority;

    vector<Packet> scheduler;
};

int main() {
    int N;
    cin >> N;

    BandwidthManager networkScheduler;

    string command, protocol, payload;
    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "rcv") {
            cin >> protocol;
            cin >> payload;
            networkScheduler.rcv(protocol, payload);
        } else if (command == "send") {
            cout << networkScheduler.send() << endl;
        }
    }

    cin.get();
    return 0;
}
