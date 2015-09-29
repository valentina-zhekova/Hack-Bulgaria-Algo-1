#include <iostream>
#include <vector>
using namespace std;

vector<int> sort(vector<int> sequence) {
    vector<int> result = sequence;
    for (int i = 0; i < result.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < result.size(); j++) {
            if (result[min] > result[j]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = result[i];
            result[i] = result[min];
            result[min] = temp;
        }
    }
    return result;
}

int main(){
    vector<int> test;
    test.push_back(2);
    test.push_back(-1);
    test.push_back(1);
    test.push_back(5);
    test.push_back(3);

    test = sort(test);
    for (int i = 0; i < test.size() - 1; i++) {
        if (test[i] > test[i + 1]) {
            cout << "problem\n";
            break;
        }
    }
    cout << "ok\n";

    cin.get();
    return 0;
}
