#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> sequence, int first, int mid, int last) {
    cout << "Enter: ";
    for (int i = first; i <= last; i++) {
        cout << sequence[i] << " ";
    }
    cout << "\n";

    vector<int> result;
    int s1 = first;
    int s2 = mid + 1;
    //cout << first << " " << mid << " " << last << "\n";
    //cout << s1 << " " << s2 << "\n";

    int temp;
    while (s1 <= mid && s2 <= last) {
        if (sequence[s1] <= sequence[s2]) {
            temp = sequence[s1];
            s1++;
        } else {
            temp = sequence[s2];
            s2++;
        }
        result.push_back(temp);

    }

    cout << "Result1: ";
    for (int i = 0; i <= last - first; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    if (s1 <= mid) {
        while(s1 <= mid) {
            result.push_back(sequence[s1]);
            s1++;
        }
    } else if (s2 <= last) {

         while(s2 <= last) {
            result.push_back(sequence[s2]);
            s2++;
        }
    }

    cout << "Result2: ";
    for (int i = 0; i <= last - first; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    for (int i = first; i <= last; i++) {
        sequence[i] = result[i - first];
    }

    cout << "Leave: ";
    for (int i = first; i <= last; i++) {
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

vector<int> merge_sort(vector<int> sequence, int first, int last) {
    if (first != last) {
        int mid = first + (last - first) / 2;
        merge_sort(sequence, first, mid);
        merge_sort(sequence, mid + 1, last);
        merge(sequence, first, mid, last);
    }
    return sequence;
}

vector<int> sort(vector<int> sequence) {
    return merge_sort(sequence, 0, sequence.size() - 1);
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
