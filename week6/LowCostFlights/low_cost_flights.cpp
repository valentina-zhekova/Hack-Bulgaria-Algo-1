/*
Having connecting flights might be annoying but sometimes
this is the only way to fit into the budget.
You are working on a low-cost flight search engine and you
want allow your clients to search for the cheapest possible
way to get from airport A to airport B.

Input:
N, 1 <= N <= 500 - the first line of input; the number of airports in your database.
N + 1 lines - each contain N integers indicating the cheapest direct flight between i and j.
              If there is 0 at that place, this means that there is no direct flight between i and j.
              All indices are 0-based.
M, 1 <= M <= 5000 - N + 3 line; the number of queries received on your server.
M lines - containing a single query - the source and the destination airport
          in the form of two different space separated integers, each between 0 and N-1.

Output:
For each of the queries, print the lowest possible price of flying between the requested airports.
If there is no way, print NO WAY for that query.
*/

#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <climits>
using namespace std;

int INVALID = -1;

int** load_airports(ifstream& file, int N) {
    string line;
    int** airports = new int *[N + 1];
    for (int r = 0; r <= N; r++) {
        getline(file, line);

        airports[r] = new int[N + 1];
        int c = 0;
        for (int j = 0; j < line.size(); j++) {
            if (line[j] != ' ') {
                if (line[j] == '0') {
                    airports[r][c] = INT_MAX;
                } else {
                    airports[r][c] = line[j] - '0'; // not good here!!!
                }
                c ++;
            }
        }
    }
    return airports;
}

int** load_queries(ifstream& file, int M) {
    string line;
    int** queries = new int *[M];
    for (int r = 0; r < M; r++) {
        getline(file, line);

        queries[r] = new int[2];
        int c = 0;
        for (int j = 0; j < line.size(); j++) {
            if (line[j] != ' ') {
                queries[r][c] = line[j] - '0'; // not good here!!!
                c ++;
            }
        }
    }
    return queries;
}

int* find_lowest_cost_flights(const int** airports, const int** queries, const int N, const int M) {
//Initialize dist[v] = INFINITY for all vertices, except dist[source] = 0
//Get an unvisited node v for which dist[v] is minimal. Mark v as visited.
//For each edge (v,u), update d[u] = min(d[u], d[v] + w(v,y)) (relaxation).
//Repeat 2. until there are no more edges.
}

template <size_t M>
void show_result(int (&flights)[M]) {
    for (int i = 0; i < M; i++) {
        if (flights[i] != INVALID) {
            cout << flights[i] << endl;
        } else {
            cout << "NO WAY" << endl;
        }
    }
}

int main() {
  string line;
  ifstream file ("low_cost_flights_input.txt");
  if (file.is_open()) {

    if (getline(file, line)) {
        int N = atoi(line.c_str());  // c_str?
        cout << "N: " << N << endl;

        int** airports = load_airports(file, N);

        if(getline(file, line)) {
            int M = atoi(line.c_str());

            int** queries = load_queries(file, M);

            int* flights = find_lowest_cost_flights(airports, queries, N, M);

            //show_result(flights);

            for (int i = 0; i < M; i++) {
                delete queries[i];
            }
            delete [] queries;
            //delete flights;
        }

        for (int i = 0; i <= N; i++) {
                delete airports[i];
        }
        delete [] airports;
    }

    file.close();
  } else {
    cout << "Unable to open the file." << endl;
  }

  // DELETE dynamic arrays!!!!!!

  cin.get();
  return 0;
}

