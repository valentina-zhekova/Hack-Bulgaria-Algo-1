#include <iostream>
#include <vector>
using namespace std;

vector<int> sort(vector<int> sequence) {
    vector<int> result = sequence;
    for (int i = 1; i < result.size(); i++) {
        int temp = result[i];
        for (int j = i - 1; j >= 0; j--) {
            if (result[j] > temp) {
                result[j + 1] = result[j];
            } else { // awkward condition here...
                result[j + 1] = temp;
                break;
            }
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
    cout << "ook\n";

    cin.get();
    return 0;
}
