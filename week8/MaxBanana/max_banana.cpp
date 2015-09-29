/*
Max Banana:
A monkey starts jumping from the bottom left cell of a NxN grid.
Each cell of the grid contains a certain amount of bananas.
The monkey can jump only one cell to the right or one cell up.
Going back is not allowed. When the monkey is in a given cell,
it collects all the bananas which are there.
What is maximum number of bananas the monkey can collect going
only in the allowed directions?

Input:
The first line will contain N - the size of the grid.
The next N lines will contain N integers each -
the number of bananas in the corresponding cell in the grid.

Output:
Output the maximum number of bananas the monkey can collect.

Limits:
1 <= N <= 1000
0 <= bananas in each cell <= 1000
*/

#include <iostream>
using namespace std;

int maxBananaCollection(int** grid, int size) {
    for (int j = 1; j < size; j++) {
        grid[size - 1][j] += grid[size - 1][j - 1];
    }
    for (int i = size - 2; i >= 0; i--) {
        grid[i][0] += grid[i + 1][0];
    }
    int maxBenefit;
    for (int i = size - 2; i >= 0; i--) {
        for (int j = 1; j < size; j++) {
            maxBenefit = (grid[i+1][j] < grid[i][j-1]) ? grid[i][j-1] : grid[i+1][j];
            grid[i][j] += maxBenefit;
        }
    }
    return grid[0][size-1];
}

int main() {
    int N;
    cin >> N;

    int** bananasGrid = new int*[N];
    for (int i = 0; i < N; i++) {
        bananasGrid[i] = new int[N];
        for (int j = 0; j < N; j++) {
            cin >> bananasGrid[i][j];
        }
    }

    cout << maxBananaCollection(bananasGrid, N) << endl;

    for (int i = 0; i < N; i ++) {
        delete [] bananasGrid[i];
    }
    delete bananasGrid;

    cin.get();
    return 0;
}
