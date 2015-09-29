/*
Thieves:
You and a bunch of thieves are planning a robbery at the local museum.
Unfortunately, your backpack can only carry up to W kilograms.
You have the list of all the items in the museum, their weights and their values.
You want to figure out which items should you take in order to maximize their value
but still be able to fit them in the backpack. Of course, you are more interested
in the value you will get rather than the items.

Input:
The first line will contain:
N - the number of items
W- the capacity of your backpack.
The next N lines will contain 2 integers each
- the weight and the value of the i-th item.

Output:
Output the maximum value you can fit in the backpack.

Limits:
1 <= N <= 1000
1 <= W <= 10000
1 <= item_weight <= 100
1 <= item_value <= 100
*/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> load_items(int N) {
    int weight, value;
    vector<pair<int, int>> result;
    for(int i = 0; i < N; i++) {
        cin >> weight;
        cin >> value;
        result.push_back(pair<int, int>(weight, value));
    }
    return result;
}

int maxValue(vector<pair<int, int>> data) {
    int result = 0;
    for (int i = data.size() - 1; i >= 0; i--) {
        for (int j =)
    }
    return result;
}

int main() {
    int N, M;
    cin >> N;
    cin >> M;

    vector<pair<int, int>> items = load_items(N);

    // P(C, I) = max {P(C-aI, I-1) + vI; P(C, I-1)} // at last search the max, cap may be...
    cout << maxValue(items) << endl;

    cin.get();
    return 0;
}
