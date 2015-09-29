/*
K Min:
Given an unsorted vector and an integer k finds
the k-th smallest element in the vector.

Input:
The first line of the standard input contains two integers:
N - the length of the vector; 1 <= N <= 1000000
k - we search the k-th smallest element; 1 <= k <= N/4
The second line of the standard input contains
N space separated integers - the numbers in the vector.

Output:
On a single line of the standard output,
print the value of the k-th smallest element.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> load_numbers(const int N) {
  vector<int> numbers;
  string number;
  for (int i = 0; i < N - 1; i++) {
    getline(cin, number, ' ');
    numbers.push_back(stoi(number));
  }
  getline(cin, number);
  numbers.push_back(stoi(number));
  return numbers;
}

void swap(vector<int>& data, int index1, int index2) {
  int temporary = data[index1];
  data[index1] = data[index2];
  data[index2] = temporary;
}

void shiftDown(vector<int>& data, int first, int last) {
  int parent = first;
  int current, left_child, right_child;
  while (parent * 2 + 1 <= last) {
    left_child = parent * 2 + 1;

    current = parent;
    if (data[current] > data[left_child]) {
      current = left_child;
    }
    right_child = left_child + 1;
    if ((right_child <= last) && (data[current] > data[right_child])) {
      current = right_child;
    }
    if (current == parent) {
      break;
    } else {
      swap(data, parent, current);
      parent = current;
    }
  }
}

// make min heap
void heapify(vector<int>& data) {
  int start = (data.size() - 2) / 2;
  while (start >= 0) {
    shiftDown(data, start, data.size() - 1);
    start --;
  }
}

void find_heap_level(const int k, int& start_index, int& end_index) {
  int level = -1;
  int next = level + 1;
  do {
    level ++;
    start_index = next;
    next = next * 2 + 1;
  } while (next < k);
  int power_of_two = 1;
  for (int i = 1; i <= level; i++) {
    power_of_two *= 2;
  } // fix later
  end_index = start_index + power_of_two - 1;
}

void show(vector<int> data) {
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int k_min(vector<int>& numbers, const int k) {
  heapify(numbers);
  cout << "Heapified: ";
  show(numbers);
  int start_index, end_index;
  find_heap_level(k, start_index, end_index);

  int searched = k - start_index - 1;
  cout << "SI: " << start_index << " EI: " << end_index << " search: " << searched << endl;
  vector<int> level;
  for (int i = start_index; (i <= end_index) && (i < numbers.size()); i++) {
    level.push_back(numbers[i]);
  }
  sort(level.begin(), level.end());
  cout << "LEVEL: ";
  show(level);
  return level[searched];
}

int main() {
  string number;
  getline(cin, number, ' ');
  int N = stoi(number);
  getline(cin, number);
  int k = stoi(number);
  vector<int> numbers = load_numbers(N);

  cout << k_min(numbers, k) << endl;

  cin.get();
  return 0;
}
