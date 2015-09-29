#include <iostream>
#include <vector>
using namespace std;

vector<int> sort(vector<int> sequence, int k) {
    int keys[k];
    for (int i = 0; i < sequence.size(); i++) {
        keys[sequence[i]] ++;
    }
    for (int i = 0; i < k - 1; i++) {
        keys[i + 1] += keys[i];
    }
    vector<int> result;
    for (int i = 0; i < sequence.size(); i++) {
        result[keys[sequence[i]]] = sequence[i];
        keys[sequence[i]] --;
    }
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

    test = sort(test, 6);
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
