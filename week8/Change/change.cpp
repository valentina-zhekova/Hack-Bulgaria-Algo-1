/*
Change:
Implement a program which finds all possible ways of building
a sum out of different coins. The coins you have are of value:
1, 2, 5, 10, 20, 50 and 100.

Input:
The input consists of a single line that contains the goal sum S.

Output:
Output the number of ways this sum could be build using coins of
any value amongst 1, 2, 5, 10, 20, 50 and 100. You could use as
many coins as you want from any value.

Limits:
1 <= S <= 1000
*/

#include <iostream>
using namespace std;

int countWays(int S) {
    int* f = new int[S+1];
    for (int i = 0; i < S+1; i++) {
        f[i] = 0;
    }
    f[0] = 1;
    int Coins[] = {1, 2, 5, 10, 20, 50, 100};
    for (int i = 0; Coins[i] <= S; i++) {
        for (int j = 0; j + Coins[i] <= S; j++) {
            f[j + Coins[i]] += f[j];
        }
    }
    // delete pointers
    return f[S];
}

int main() {
    int S;
    cin >> S;

    cout << countWays(S) << endl;

    cin.get();
    return 0;
}
