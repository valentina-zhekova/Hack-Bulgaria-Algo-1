/*
Closest Coffee Store:
Given a graph of connected points of interests and a starting point
returns the closest coffee store to that point or -1 if there is no
reachable coffee store from this location.

Input:
The first line of the standard input will contain the number of poits - N; N e [1, 1000]
The next N lines will each contain N integer representing the adjacency
matrix of the points - 1 if there is a point and 0 otherwise.
The next line will contain the index of the starting point (zero-based).
The next line will contain N integers representing the coffee store property array:
if the i-th number in that array is 1, this means that there is a coffee store at point i.

Output:
On a single line on the standard output, print the distance to the nearest coffee store.
Print -1 in case there is no reachable coffee store from this location.
*/

#include <iostream>
#include <queue>
using namespace std;

bool** loadMap(int N) {
    bool** map = new bool*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new bool[N];
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    return map;
}

bool* loadStores(int N) {
    bool* stores = new bool[N];
    for (int i = 0; i < N; i++) {
        cin >> stores[i];
    }
    return stores;
}

int nearestStore(int start, bool** map, bool* stores, int N) {
    int result = -1;
    bool* visited = new bool[N];
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    queue<pair<int, int>> next;
    next.push(pair<int, int>(start, 0));
    int distance, goTo;
    pair<int, int> head;
    while(!next.empty()) {
        head = next.front();
        goTo = head.first;
        distance = head.second;
        next.pop();
        visited[goTo] = true;
        if(stores[goTo]) {
            result = distance;
            break;
        }
        for (int i = 0; i < N; i ++) {
            if (map[goTo][i] && !visited[i]) {
                next.push(pair<int, int>(i, distance + 1));
            }
        }
    }
    delete [] visited;
    return result;
}

int main() {
    int N;
    cin >> N;

    bool** map = loadMap(N);

    int startPoint;
    cin >> startPoint;

    bool* stores = loadStores(N);

    cout << nearestStore(startPoint, map, stores, N) << endl;

    for (int i = 0; i < N; i++) {
        delete [] map[i];
    }
    delete map;
    delete [] stores;

    cin.get();
    return 0;
}
