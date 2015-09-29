/*
Quadruplets 2:
Create a program that given four vectors of N (1 <= N <= 7000)
integer values, computes how many quadruplets (one element
from every vector) form a total sum of zero.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> load_numbers(const int N) {
  string number;
  vector<int> data;
  for (int i = 0; i < N - 1; i++) {
    getline(cin, number, ' ');
    data.push_back(stoi(number));
  }
  getline(cin, number);
  data.push_back(stoi(number));
  return data;
}

// optimize later searching for element won't be fast
vector<pair<int, int>> pair_and_sum(const vector<int> data1,
const vector<int> data2) {
  vector<int> paired;
  for (int i = 0; i < data1.size(); i++) {
    for (int j = 0; j < data2.size(); j++) {
      paired.push_back(data1[i] + data2[j]);
    }
  }
  sort(paired.begin(), paired.end());

  vector<pair<int, int>> result;
  int index = 0;
  while (index < paired.size()) {
    int occurrence = 0;
    int value = paired[index];
    while (paired[index] == value && index < paired.size()) {
      index ++;
      occurrence ++;
    }
    result.push_back(pair<int, int>(value, occurrence));
  }
  return result;
}

// fix later the way it check the occurance count
int binary_search(const vector<pair<int, int>> data, int element) {
  int occurrence = 0;
  int left = 0;
  int right = data.size() - 1;
  int middle;
  do {
    middle = (left + right) / 2;
    if (data[middle].first >= element) {
      right = middle;
    } else {
      left = middle + 1;
    }
  } while (left < right); // always stops when equal
  if (data[left].first == element) {
    occurrence = data[left].second;
  }
  return occurrence;
}

int number_quadruplets_with_zero_sum(const vector<int> nums1,
                                     const vector<int> nums2,
                                     const vector<int> nums3,
                                     const vector<int> nums4) {
  int zero_sum_quadruplets_count = 0;
  vector<pair<int, int>> paired1 = pair_and_sum(nums1, nums2);
  vector<pair<int, int>> paired2 = pair_and_sum(nums3, nums4);

  for (int i = 0; i < paired1.size(); i++) {
    int opposite = -paired1[i].first;
    int occurrence = binary_search(paired2, opposite);
    zero_sum_quadruplets_count += paired1[i].second * occurrence;
  }
  return zero_sum_quadruplets_count;
}

int main() {
  string number;
  getline(cin, number);
  int N = stoi(number);

  vector<int> nums1 = load_numbers(N);
  vector<int> nums2 = load_numbers(N);
  vector<int> nums3 = load_numbers(N);
  vector<int> nums4 = load_numbers(N);

  cout << number_quadruplets_with_zero_sum(nums1, nums2, nums3, nums4) << endl;

  cin.get();
  return 0;
}
