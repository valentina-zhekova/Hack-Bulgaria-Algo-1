/*
Bank Robbery:
You are making a plan to rob the city bank. You have the map of the city
which consists of N junctions and M streets between junctions.
You know that the bank is location at junction B,
the police department at junction P,
and you are planning to escape with a helicopter located at junction H.
When you start robbing the bank, the alarm will fire and the police will be notified.
They will send squads in all directions, starting from the police station.
They travel between two junction in 1 minute and they will spread in all possible directions.
You also pass a street between two junctions in 1 minute.
Now the question is, what is the maximum time you can stay in the bank
before you can head to the helicopter and be sure that the police will not reach you.

Input:
The first line of the input contains N and M.
The next M lines will contain two integers indicating that there
is a street between these two junctions. Streets are bi-directional.
The last line will contain the junctions B,P,H - where respectively
the bank, the police, and the helicopter are located.

Output:
Output the maximum number of minutes you can stay at the bank
but still be able to reach the helicopter uncaught.

Limits:
1 <= N <= 1000
1 <= M <= 10000
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void show(int**& data, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void loadStreets(int**& cityMap, int M) {
    int from, to;
    for (int i = 0; i < M; i++) {
        cin >> from;
        cin >> to;
        // input indicies are not zero based!
        cityMap[from - 1][to - 1] = 1;
        cityMap[to - 1][from - 1] = 1; // bi-directional
    }
    //cout << "OUT of load streets" << endl;
}

void policeTime(int**& cityMap, int N, int P) {
    int time = 1;
    vector<bool> visited;
    for (int i = 0; i < N; i++) {
        visited.push_back(false);
    }
    queue<pair<int, int>> toVisit;

    toVisit.push(pair<int, int>(P, time));
    int current, cTime;
    while (!toVisit.empty()) {
        current = toVisit.front().first;
        cTime = toVisit.front().second;
        toVisit.pop();
        visited[current] = true;
        time ++;
        for (int i = 0; i < N; i++) {
            if (cityMap[current][i] == 1 && !visited[i]) {
                cityMap[current][i] = cTime;
                cityMap[i][current] = cTime; // bi-directional
                toVisit.push(pair<int, int>(i, time));
            }
        }
        // does something miss here?
    }
}


int main() {
    int N, M;
    cin >> N;
    cin >> M;

    int** cityMap = new int*[N];
    for (int i = 0; i < N; i++) {
        cityMap[i] = new int[N];
        for (int j = 0; j < N; j++) {
            cityMap[i][j] = 0;
        }
    }

    loadStreets(cityMap, M);

    int B, P, H;
    cin >> B;
    B--;
    cin >> P;
    P--;
    cin >> H;
    H--; // also not zero based


    cout << "BEFORE:\n";
    show(cityMap, N);

    policeTime(cityMap, N, P);

    cout << "\nAFTER:\n";
    show(cityMap, N);

    cin.get();
    return 0;
}
