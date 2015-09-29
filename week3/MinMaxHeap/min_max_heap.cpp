/*
Min/Max Heap:
Checks if a given binary tree is a min-max heap.
Min-max heap is a tree that maintains the
following property for every node:
● If node's level is odd number the value of node
is less than the values of all of the node's descendants.
● If node's level is even number the value of node
is bigger than the values of all of the node's descendants.
The level of the root of the tree is 1.
For the rest of the tree's nodes it's true that
the level of a node is node's parent's level + 1.
Note that the rule considers all descendants,
not just the direct children.

Input:
The tree will be given as an array.
The first line of the standard input will contain:
N - the length of the array; 1 <= N <= 100000
The second line will contain N space separated integers
- the values of the array.
The array will contain only positive integers (>=1).
The array representation of a binary tree is as follows:
If i is the zero based index of the element in the array, then:
- If i == 0, then i is the root
- The left child of i is 2*i+1
- The right child of i is 2*i+2
- The parent of i is (i-1)/2

Output:
If the given binary tree is a valid min-max heap,
print YES on the console, otherwise print NO.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> loadNodes(const int N) {
  vector<int> tree;
  string node;
  for (int i = 0; i < N - 1; i++) {
    getline(cin, node, ' ');
    tree.push_back(stoi(node));
  }
  getline(cin, node);
  tree.push_back(stoi(node));
  return tree;
}

vector<int> findIndices(const int lastIndex) {
  vector<int> indices;
  int current = 0;
  while (lastIndex >= current) {
    indices.push_back(current);
    current = current * 2 + 1;
  }
  return indices;
}

bool isMinMaxHeap(const vector<int>& tree) {
  vector<int> levelStartIndices = findIndices(tree.size() - 1);
  bool isLevelOdd = ((levelStartIndices.size() % 2) == 1);
  int lastLSIIndex = levelStartIndices.size() - 1;
  bool isMMH = true;
  for (int index = tree.size() - 1; index > 0; index--) {
    int current = tree[index];
    int pIndex = (index - 1) / 2;
    int parent = tree[pIndex];
    int grandparent = tree[(pIndex - 1) / 2];
    if (current != 0) {
      if (index == levelStartIndices[lastLSIIndex] - 1) {
        isLevelOdd = !isLevelOdd;
        lastLSIIndex --;
      }
      if (grandparent != parent) {
        bool oddRuleBroken = (isLevelOdd && !((grandparent < current)
                                              && (current < parent)));
        bool evenRuleBroken = (!isLevelOdd && !((parent < current)
                                                && (current < grandparent)));
        if (oddRuleBroken || evenRuleBroken) {
          isMMH = false;
          break;
        }
      } else {
        if (parent >= current) {
          isMMH = false;
          break;
        }
      }
    }
  }
  return isMMH;
}

int main() {
  string number;
  getline(cin, number);
  int N = stoi(number);

  vector<int> binaryTree = loadNodes(N);

  if (isMinMaxHeap(binaryTree)) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  cin.get();
  return 0;
}

