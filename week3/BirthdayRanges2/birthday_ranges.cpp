/*
Birthday ranges:
Starts with a vector of people's birthdays
(numbers in the range 0-365) and can execute the following commands:
add [day] [number_of_people] - adds number_of_people new people who have birthdays on the day.
remove [day] [number_of_people] - removes number_of_people who have birthdays on the day.
You must ensure that the number of people for any given day is always positive.
1 <= number_of_people on each command <= 1000
count [start_day] [end_day] - returns the number of people who have birthdays in the range
                              between start_day and end_day inclusive.

Input:
The first line of the standard input will contain two integers:
N - the number of days in the initial vector; 1 <= N <= 500000
M - the number of commands; 2 <= M <= 500000
The next line will contain the initial vector with people's birthdays
- each number indicates that there is a single person whose birthday is on that day.
The next M lines will each contain a single command in the format specified above.

Output:
For each count command, print a single line on the standard output containing the result of the
command execution.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> load_birthdays(const int N) {
    vector<int> birthdays;
    for (int i = 0; i < 365; i++) {
        birthdays.push_back(0);
    }

    int day;
    for (int i = 0; i < N; i++) {
        cin >> day;
        birthdays[day] ++;
    }
    return birthdays;
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

    int parent;
    for (int i = data.size() - 1; i > 0; i -= 2) {
        parent = (i - 1) / 2;
        data[parent] = data[i] + data[i - 1];
    }
}

void add(vector<int>& birthdays, int day, int numberOfPeople) {
    int differ = (birthdays.size() + 1) / 2 - 1;
    day += differ;
    int parent = (day - 1) / 2;
    while (day > 0) {
        birthdays[day] += numberOfPeople;
        day = parent;
        parent = (day - 1) / 2;
    }
    birthdays[0] += numberOfPeople;
}

void remove(vector<int>& birthdays, int day, int numberOfPeople) {
    int differ = (birthdays.size() + 1) / 2 - 1;
    day += differ;
    int parent = (day - 1) / 2;
    int removed = (birthdays[day] < numberOfPeople) ? birthdays[day] : numberOfPeople;
    while (day > 0) {
        birthdays[day] -= removed;
        day = parent;
        parent = (day - 1) / 2;
    }
    birthdays[0] -= removed;
}

int rangeStartToIndex(vector<int>& data, int index) {
    int result = 0, parent;
    int differ = (data.size() + 1) / 2 - 1;
    index += differ;
    if (index == data.size() - 1) {
        result = data[0];
    } else {
        index ++;
        parent = (index - 1) / 2;
        while (index != 0) {
            if (index == parent * 2 + 2) {
                result += data[index - 1];
            }
            index = parent;
            parent = (index - 1) / 2;
        }
    }
    return result;
}

int count(vector<int>& birthdays, int from, int to) {
    int result;
    if (from == to) {
        result = birthdays[from];
    } else {
        int fromRange = rangeStartToIndex(birthdays, from - 1);
        int toRange = rangeStartToIndex(birthdays, to);
        result = toRange - fromRange;
    }
    return result;
}

int main() {
    int N, M;
    cin >> N;
    cin >> M;

    vector<int> birthdays = load_birthdays(N);
    buildBinaryIndexedTree(birthdays);

    string command;
    int day, people, from, to;
    for (int i = 0; i < M; i++) {
        cin >> command;
        if (command == "add") {
            cin >> day;
            cin >> people;
            add(birthdays, day, people);
        } else if (command == "remove") {
            cin >> day;
            cin >> people;
            remove(birthdays, day, people);
        } else if (command == "count") {
            cin >> from;
            cin >> to;
            cout << count(birthdays, from, to) << endl;
        }
    }

    cin.get();
    return 0;
}
