/*
Online median:
Inserts a number to a collection and returns the
median of the collection on each insert.
A median of the collection is the element which stays
on position ceiling((Length-1)/2) in the
zero-based sorted list of the items.

Input:
The first line of the input contains a number:
N - the count of integers that are present
    in the second line of the input; N <= 500000

Output:
Each line of the output contains a number
which is the median of the collection after
corresponding number of iterations over the input.

Limits: (differ...)
Time <= 1s
Memory <= 10mb
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// maybe not what is wanted...
void insertionSort(vector<int>& collection, int newElement) {
    collection.push_back(newElement);
    int index = collection.size() - 2;
    while (collection[index] > newElement && index > 0) {
        collection[index + 1] = collection[index];
        index--;
    }
    collection[index + 1] = newElement;
}

int main() {
    int number;
    cin >> number;
    int N = number;

    vector<int> collection;
    cin >> number;
    collection.push_back(number);
    cout << collection[0] << endl;
    N--;
    int medianIndex;
    while (N > 0) {
        cin >> number;
        insertionSort(collection, number);
        medianIndex = collection.size() / 2;
        cout << collection[medianIndex] << endl;
        N--;
    }

    cin.get();
    return 0;
}
