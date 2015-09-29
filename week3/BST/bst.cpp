/*
BST:
Checks if a given binary tree is a Binary Search Tree.
The rule of the Binary Search Tree is that all nodes
in the left sub-tree of a given node must have a
value smaller than the value in the node, and all values
in the right sub-tree of that node must have
values larger than the value in the node.

Input:
The binary search tree will be given as an array.
The first line of the standard input will contain:
N - the length of the array; 1 <= N <= 100000
The second line will contain N space separated integers
- the values of the array.
The array will contain only positive integers (>=1).
If there is a 0 at some position in the array, this
means that there is no node at this position.
All numbers (except the zeroes) will be distinct.
The array representation of a binary tree is as follows:
- If i is the zero based index of the element in the array, then:
- If i == 0, then i is the root
- The left child of i is 2*i+1
- The right child of i is 2*i+2
- The parent of i is (i-1)/2

Output:
If the given binary tree is a valid binary search tree,
print YES on the console, otherwise print NO.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> load_nodes(const int N) {
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

bool isBinarySearchTree(const vector<int>& tree) {
    bool isBST = true;
    for (int index = tree.size() - 1; index > 0; index--) {
        int parentIndex = (index - 1) / 2;
        bool isRightChild = ((2 * parentIndex + 2) == index);
        //cout << "current"
        if (tree[index] != 0) {
            if ((isRightChild && (tree[index] <= tree[parentIndex])) ||
                (!isRightChild && (tree[index] > tree[parentIndex]))) {
                isBST = false;
                break;
            }
        }
    }
    return isBST;
}

int main() {
    string number;
    getline(cin, number);
    int N = stoi(number);

    vector<int> binaryTree = load_nodes(N);

    if (isBinarySearchTree(binaryTree)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    cin.get();
    return 0;
}
