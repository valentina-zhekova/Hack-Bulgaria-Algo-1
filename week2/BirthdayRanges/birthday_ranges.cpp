/*
Birthday ranges:
Given a vector of people's birthdays (numbers in the range 0-365)
and a vector of ranges (pairs of numbers in the range 0-365)
produces a vector of the number of people with birthday in the specific range.

Input:
The first line of the standard input will contain two integers:
N - the number of people; 1 <= N <= 100000
M - the number of ranges; 2 <= M <= 100000
The next line will contain N integers:
the i-th integer on that line indicates the birthday of the i-th person.
The following M lines will each contain two integer:
the range of days for which you should check the number of birthdays in.

Output:
For each of the M ranges, print a single line containing
the number of people who have birthdays in that range.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> load_birthdays(const int N) {
  vector<int> birthdays;
  string date;
  for (int i = 0; i < N - 1; i++) {
    getline(cin, date, ' ');
    birthdays.push_back(stoi(date));
  }
  getline(cin, date);
  birthdays.push_back(stoi(date));
  return birthdays;
}

vector<pair<int, int>> load_ranges(const int M) {
  vector<pair<int, int>> ranges;
  string date;
  for (int i = 0; i < M; i++) {
    getline(cin, date, ' ');
    int from = stoi(date);
    getline(cin, date);
    int to = stoi(date);
    ranges.push_back(pair<int, int>(from, to));
  }
  return ranges;
}

// for now use the idea of counting sort
vector<int> find_people_histogram(const vector<int> birthdays,
                                  const vector<pair<int, int>> ranges,
                                  const int N, const int M) {
  int days[366];
  for (int i = 0; i < 366; i++) {
    days[i] = 0;
  }

  for (int i = 0; i < N; i++) {
    days[birthdays[i]] ++;
  }

  for (int i = 1; i < 366; i++) {
    days[i] += days[i - 1];
  }

  vector<int> histogram;
  for (int i = 0; i < M; i++) {
    int from_exclusive = ranges[i].first - 1;
    int to_inclusive = ranges[i].second;
    histogram.push_back(days[to_inclusive] - days[from_exclusive]);
  }
  return histogram;
}

void show_result(const vector<int> data, const int length) {
  for (int i = 0; i < length; i++) {
    cout << data[i] << "\n";
  }
}

int main() {
  string number;
  getline(cin, number, ' ');
  int N = stoi(number);
  getline(cin, number);
  int M = stoi(number);

  vector<int> birthdays = load_birthdays(N);
  vector<pair<int, int>> ranges = load_ranges(M);
  vector<int> people_histogram = find_people_histogram(birthdays, ranges, N, M);

  show_result(people_histogram, M);

  cin.get();
  return 0;
}
