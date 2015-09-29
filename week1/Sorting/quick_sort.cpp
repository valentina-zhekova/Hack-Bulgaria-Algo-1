#include <iostream>
#include <vector>
using namespace std;

// in-place

// return the index of smallest between start, mid, end
int pivot(vector<int> sequence, first, last) {
    int mid = first + (last - first) / 2;
    int min = first;
    if (last < min) min = last;
    if (mid < min) min = mid;
    return min;
}

vector<int> quick_sort(vector<int> sequence, first, last) {
    int p = pivot(sequence, first, last);

    vector<int> temp =
}

vector<int> sort(vector<int> sequence) {
}

int main(){
    vector<int> test;
    test.push_back(2);
    test.push_back(-1);
    test.push_back(1);
    test.push_back(5);
    test.push_back(3);

    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << "\n";

    test = sort(test);
    for (int i = 0; i < test.size() - 1; i++) {
        if (test[i] > test[i + 1]) {
            cout << "problem " << test[i] << " \n";
            break;
        }
    }
    cout << "ook\n";

    cin.get();
    return 0;
}
