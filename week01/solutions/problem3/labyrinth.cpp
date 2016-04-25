#include <iostream>

using namespace std;

const int MAX = 100;

char labyrinth[MAX][MAX];
int m, n;

void readLabyrinth() {
    cin >> m >> n;
    cin.ignore();
    for (int i = 0; i < m; i++)
        cin.getline(labyrinth[i], n + 1);
}

void printLabyrinth() {
    for (int i = 0; i < m; i++)
        cout << labyrinth[i] << endl;
}

void findStart(int &x, int &y) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (labyrinth[i][j] == 'o') {
                x = i;
                y = j;
                return;
            }
}

bool findTreasure(int x, int y, int moves) {
    if (x < 0 || x >= m || y < 0 || y >= n || labyrinth[x][y] == '#' || labyrinth[x][y] == '^')
        return false;
    if (labyrinth[x][y] == '$') {
        cout << "Found the treasure at (" << x << ", " << y << ")";
        cout << " in " << moves << " steps." << endl;
        return true;
    }

    // mark visited
    labyrinth[x][y] = '^';

    if (findTreasure(x + 1, y, moves + 1) ||
        findTreasure(x - 1, y, moves + 1) ||
        findTreasure(x, y + 1, moves + 1) ||
        findTreasure(x, y - 1, moves + 1))
        return true;

    // mark dead end
    labyrinth[x][y] = 'x';

    return false;
}

int main() {
    readLabyrinth();
    printLabyrinth();
    int startX, startY;
    findStart(startX, startY);
    cout << "Starting from (" << startX << ", " << startY << ")" << endl;
    findTreasure(startX, startY, 0);
    printLabyrinth();

    return 0;
}

/*
 * example:
 *
7 5
.#.##
o#.#.
.#...
.#$#.
.###.
.....
.####
*/