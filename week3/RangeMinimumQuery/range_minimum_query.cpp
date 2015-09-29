/*
Range Minimum Query:
Starts with an initial list of number and then
implements the following two commands.
set [index] [value] - replaces the value at index in the list
                      with the specified value; index <= length of the list.
min [start_index] [end_index] - returns the minimum value from
                                the elements between start_index and end_index;
                                start_index <= end_index.
Indices in both operations are zero-based.!!!!!!!!
The first line of the input will contain two integers:
- the length of the list and the number of commands.
The second line of the input will contain the elements of the list, separated by space.
Each of the following lines will contain a single command in the format specified above.

Input:
The first line of the input contains two numbers:
N - the count of integers that are present in the array; N <= 1000000
K - the number of queries; K <= 100000
The second line of the input contains N integers.
Then follow K lines of the form set [index] [value] or min [start_index] [end_index].

Output:
M lines of integers if M is the number of min queries.

Limits: (differ...)
Time <= 0.6s
Memory <= 5mb
*/

#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

void print(vector<int>& data) {
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << "\n";
    }
}

vector<int> loadIntegers(int N) {
    vector<int> result;
    int number;
    for (int i = 0; i < N; i++) {
        cin >> number;
        result.push_back(number);
    }
    return result;
}

void buildBinaryIndexedTree(vector<int>& data) {
    int powerOfTwo = 0;
    int compareWith = 1;
    while (data.size() > compareWith) {
        compareWith *= 2;
        powerOfTwo ++;
    }

    while (data.size() < compareWith) {
        data.push_back(0);
    }

    data.insert(data.begin(), compareWith - 1, 0);

    int parent, minimal;
    for (int i = data.size() - 1; i > 0; i -= 2) {
        parent = (i - 1) / 2;
        minimal = (data[i - 1] < data[i]) ? data[i - 1] : data[i];
        data[parent] = minimal;
    }
}

void set(vector<int>& integers, int index, int value) {
    int offset = (integers.size() + 1) / 2 - 1;
    index += offset;
    integers[index] = value;
    int parent = (index - 1) / 2;
    bool update = integers[parent] > value;
    while (update && (index > 0)) {
        integers[parent] = value;
        index = parent;
        parent = (index - 1) / 2;
        update = integers[parent] > value;
    }
}

bool contains(vector<int>& data, int item) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == item) {
            return true;
        }
    }
    return false;
}

// return at each index is assigned first the min value
// if no same index or its parents find the next min
int rangeStartToIndex(vector<int>& data, int index, int avoidIndex) {
    int result = INT_MAX, parent, minimal;
    int resultIndex = -1;
    if (index == data.size() - 1) {
        result = data[0];
        resultIndex = 0;
    } else {
        vector<int> avoid;
        while (avoidIndex >= 0) {
            avoid.push_back(avoidIndex);
            avoidIndex = (avoidIndex - 1) / 2; // the parent
        }

        index ++;
        parent = (index - 1) / 2;
        while (index != 0) {
            if (index == parent * 2 + 2) {
                if ((data[index - 1] < result) && !(contains(avoid, (index - 1)))) {
                    result = data[index - 1];
                    resultIndex = index - 1;
                }
            }
            index = parent;
            parent = (index - 1) / 2;
        }
    }
    return resultIndex;
}

int min(vector<int>& integers, int from, int to) {
    int offset = (integers.size() + 1) / 2 - 1;
    from += offset;
    to += offset;
    int result;
    if (from == to) {
        result = integers[from];
    } else {
        int fromRangeMinIndex = rangeStartToIndex(integers, from - 1, -1);
        int toRangeMinIndex = rangeStartToIndex(integers, to, fromRangeMinIndex);
        result = integers[toRangeMinIndex];
    }
    return result;
}

vector<int> commands(vector<int>& integers, int K) {
    vector<int> output;
    string command;
    int index, value, from, to;
    for (int i = 0; i < K; i++) {
        cin >> command;
        if (command == "set") {
            cin >> index;
            cin >> value;
            set(integers, index, value);
        } else if (command == "min") {
            cin >> from;
            cin >> to;
            output.push_back(min(integers, from, to));
        }
    }
    return output;
}

int main() {
    int N, K;
    cin >> N;
    cin >> K;

    vector<int> integers = loadIntegers(N);
    buildBinaryIndexedTree(integers);

    vector<int> result = commands(integers, K);
    print(result);

    cin.get();
    return 0;
}
