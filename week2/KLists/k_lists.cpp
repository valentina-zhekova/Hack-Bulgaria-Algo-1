/*
K Lists:
Given K sorted lists of positive integers produces
a merged lists with all elements sorted in order.

Input:
On the first line of the standard input:
K - the number of lists to merge; 2 <= K <= 150
Each of the following K lines will contain
the space separated integers from the i-th list.
Each of those lines will end with -1 just as indication,
e.g. not included in the list; 2 <= length_of_a_list <= 10000

Output:
On a single line on the standard output, print the
sorted sequence which is the result of merging the K lists.
*/

#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

vector<list<int>> load_lists(const int K) {
  vector<list<int>> result;
  string number;
  list<int> data;
  for (int i = 0; i < K; i++) {
    data.clear();
    cin >> number;
    while (stoi(number) != -1) {
      data.push_back(stoi(number));
      cin >> number;
    }
    result.push_back(data);
  }
  return result;
}

list<int> merge_lists(vector<list<int>> lists) {
  list<int> merged;
  vector<list<int>::iterator> iterators;
  for (int i = 0; i < lists.size(); i++) {
    iterators.push_back(lists[i].begin());
  }

  int index_min;
  bool has_elements, is_smaller;
  do {
    index_min = -1;
    for (int i = 0; i < lists.size(); i++) {
      has_elements = (iterators[i] != lists[i].end());
      if (has_elements) {
        if (index_min == -1) {
          index_min = i;
        } else {
          is_smaller = (*iterators[i] < *iterators[index_min]);
          if (is_smaller) {
            index_min = i;
          }
        }
      }
    }
    if (index_min != -1) {
      merged.push_back(*iterators[index_min]);
      iterators[index_min] ++;
    }
  } while (index_min != -1); // fix later
  return merged;
}

void show_result(list<int> data) {
  list<int>::iterator current = data.begin();
  while (current != data.end()) {
    cout << *current << " ";
    current ++;
  }
  cout << endl;
}

int main() {
  string number;
  getline(cin, number);
  int K = stoi(number);
  vector<list<int>> lists = load_lists(K);

  list<int> merged = merge_lists(lists);

  show_result(merged);

  cin.get();
  return 0;
}
