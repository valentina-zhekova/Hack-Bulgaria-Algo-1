/*
Longest Common Substring:
Given two strings, find the longest substring
which is contained in both of them.

Input:
The first line will contain the first string and
the second line will contain the second string.

Output:
On a single line, print the longest common substring.
Spaces (leading or trailing) should be included in the result.

Limits:
1 <= length_of_string <= 1000
*/

#include <iostream>
#include <string>
using namespace std;

// * tricky part matches a lot of things
string longestSubstring(string w1, string w2) {
    int maxI = 0, maxJ = 0;
    int table[w1.size() + 1][w2.size() + 1];
    for (int i = 0; i < w1.size() + 1; i++) {
        table[i][0] = 0;
    }
    for (int j = 0; j < w2.size() + 1; j++) {
        table[0][j] = 0;
    }
    for (int i = 1; i < w1.size() + 1; i++) {
        for (int j = 1; j < w2.size() + 1; j++) {
            table[i][j] = table[i-1][j-1];
            if (w1[i] == w2[j]) {
                table[i][j]++;
            }
            if (table[i][j] > table[maxI][maxJ]) {
                maxI = i;
                maxJ = j;
            }
        }
    }

    return w2.substr(maxJ - table[maxI][maxJ], table[maxI][maxJ]);
}

int main() {
    string word1;
    string word2;

    getline(cin, word1);
    getline(cin, word2);

    cout << longestSubstring(word1, word2) << endl;

    cin.get();
    return 0;
}
