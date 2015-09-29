/*
Valid Directories:
Checks if a collection of directories and files is valid.
A valid collection of directories and files is one that
does not allow a path starting from directory and visiting
its children to end in the same directory.

Input:
The input is an adjacency matrix of the graph of directories and files.
The values in the matrix symbolize different type of relations.
For graph[a][b] the possible values are:
● 0 - There is no relation between nodes a and b
● 1 - Node b is a directory child of a
● 2 - Node b is a file child of a

The first line of the standard input will contain the number of entries N e [1, 1000]
The next N lines will contain N integers each, representing the adjacency matrix.
It is guaranteed that files will not have child entries in the input data.

Output:
On a single line on the standard output, print
true if the structure is valid, and false if it is not.
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool** loadData(int N) {
    bool** data = new bool*[N];
    int current;
    for (int i = 0; i < N; i++) {
        data[i] = new bool[N + 1];
        data[N] = false; // is there subdirectories at all
        for (int j = 0; j < N; j++) {
            cin >> current;
            data[i][j] = current % 2;
            data[i][N] = data[i][j] || data[i][N];
        }
    }
    return data;
}

bool isValid(bool** fs, int N, int row) {
    bool result = true;
    vector<pair<bool, int>> visited;
    for (int i = 0; i < N; i++) {
        visited.push_back(pair<bool, int>(false, N + 1));
    }
    queue<pair<int, int>> next;
    next.push(pair<int, int>(row, 0));
    pair<int, int> head;
    int current, time;
    while(result && !next.empty()) {
        head = next.front();
        current = head.first;
        time = head.second;
        next.pop();
        visited[current].first = true;
        visited[current].second = time;
        for (int i = 0; fs[current][N] && i < N; i++) {
            if (fs[current][i]) {
                if (visited[i].first && visited[i].second < time) {
                    result = false; // there is a cycle
                    break;
                } else {
                    next.push(pair<int, int>(i, time + 1));
                }
            }
        }
    }
    return result;
}

string validDirectories(bool** fs, int N) {
    bool valid = true;
    for (int row = 0; valid && row < N; row++) {
        if (fs[row][N] && !isValid(fs, N, row)) {
            valid = false;
            break;
        }
    }
    string result = (valid) ? "true" : "false";
    return result;
}

int main() {
    int N;
    cin >> N;

    bool** fs = loadData(N);

    cout << validDirectories(fs, N) << endl;

    for (int i = 0; i < N; i++) {
        delete [] fs[i];
    }
    delete fs;

    cin.get();
    return 0;
}
