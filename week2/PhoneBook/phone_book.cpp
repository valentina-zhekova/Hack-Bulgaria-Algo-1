/*
Phone book:
Given a vector of pairs (names and phone numbers)
and another vector of phone numbers
finds the names that correspond to the phone numbers in the second vector.

Input:
The first line of the standard input will contain two integers:
N - the length of the phone book; 1 <= N <= 7000
M - the number of queries; 1 <= M <= 7000
Each of the following N lines will contain a space-separated
pair of an integer and a string representing
a phone number (at most 9 digits; no white spaces) and
a name (at most 30 characters; no white spaces).
The following M lines will contain a single integer -
each representing a phone number to look up.

Output:
For each of the M numbers to lookup,
print a single line on the standard output,
containing the name associated with the given number.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<int, string>> load_phone_book(const int N) {
  vector<pair<int, string>> phone_book;
  string data;
  int phone_number;
  for (int i = 0; i < N; i++) {
    getline(cin, data, ' ');
    phone_number = stoi(data);
    getline(cin, data);
    phone_book.push_back(pair<int, string>(phone_number, data));
  }
  return phone_book;
}

vector<int> load_phone_numbers(const int M) {
  vector<int> phone_numbers;
  string phone_number;
  for (int i = 0; i < M; i++) {
    getline(cin, phone_number);
    phone_numbers.push_back(stoi(phone_number));
  }
  return phone_numbers;
}

string binary_search(vector<pair<int, string>> phone_book, int number) {
  string name = "Anonymous";
  int left = 0;
  int right = phone_book.size() - 1;
  int middle;
  do {
    middle = (left + right) / 2;
    if (phone_book[middle].first >= number) {
      right = middle;
    } else {
      left = middle + 1;
    }
  } while (left < right); // always stops when equal
  if (phone_book[left].first == number) {
    name = phone_book[left].second;
  }
  return name;
}

vector<string> get_names(const vector<pair<int, string>> phone_book,
                         const vector<int> phone_numbers) {
  vector<string> names;
  for (int i = 0; i < phone_numbers.size(); i++) {
    names.push_back(binary_search(phone_book, phone_numbers[i]));
  }
  return names;
}

void show_result(const vector<string> data) {
  for (int i = 0; i < data.size(); i++) {
    cout << data[i] << "\n";
  }
}

int main() {
  string number;
  getline(cin, number, ' ');
  int N = stoi(number);
  getline(cin, number);
  int M = stoi(number);

  vector<pair<int, string>> phone_book = load_phone_book(N);
  sort(phone_book.begin(), phone_book.end());
  vector<int> phone_numbers = load_phone_numbers(M);
  vector<string> people = get_names(phone_book, phone_numbers);

  show_result(people);

  cin.get();
  return 0;
}
