/*
Heap Sort:
Sort a sequence of integer numbers by heap sort.

Input:
On the first line of the standard input:
N - the length of the sequence; 1 <= N <= 200000
On the second line there will be N
space separated integer representing the sequence.
1 <= Ai <= INT_MAX

Output:
On a single line of the standard output,
print the numbers from the sorted sequence,
separated by space.

For now the heap will be represented with vector (array)
*/

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<int> load_sequence(const int N) {
  vector<int> sequence;
  string number;
  for (int i = 0; i < N - 1; i++) {
    getline(cin, number, ' ');
    sequence.push_back(stoi(number));
  }
  getline(cin, number);
  sequence.push_back(stoi(number));
  return sequence;
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
    if (data[current] < data[left_child]) {
      current = left_child;
    }
    right_child = left_child + 1;
    if ((right_child <= last) && (data[current] < data[right_child])) {
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

void heapify(vector<int>& data) {
  int start = (data.size() - 2) / 2;
  while (start >= 0) {
    shiftDown(data, start, data.size() - 1);
    start --;
  }
}

void heap_sort(vector<int>& data) {
  heapify(data);
  int last = data.size() - 1;
  while (last > 0) {
    swap(data, last, 0);
    last --;
    shiftDown(data, 0, last);
  }
}

void show_result(const vector<int>& data) {
  for (int i = 0; i < data.size() - 1; i++) {
    cout << data[i] << " ";
  }
  cout << data[data.size() - 1];
}

int main() {
  string number;
  getline(cin, number);
  int N = stoi(number);

  vector<int> numbers = load_sequence(N);
  heap_sort(numbers); // in place

  show_result(numbers);

  cin.get();
  return 0;
}
