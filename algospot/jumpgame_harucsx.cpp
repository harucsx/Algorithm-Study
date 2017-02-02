#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int VISITED_TRUE = - 1;
const int VISITED_FALSE = -2;

bool jumpgame(int x, int y, vector<vector<int> >& board) {
    int size = board.size();

    if (x < 0 || y < 0 || x >= size || y >= size)
        return false;

    if (x == size - 1 && y == size - 1)
        return true;

    if (board[x][y] == VISITED_TRUE)
        return true;

    if (board[x][y] == VISITED_FALSE)
        return false;

    bool result = jumpgame(x + board[x][y], y, board) || jumpgame(x, y + board[x][y], board);
    board[x][y] = result ? VISITED_TRUE : VISITED_FALSE;

    return result;
}

int main(int argc, char **argv) {
    int TC;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        vector<vector<int> > board;
        unsigned size;
        cin >> size;

        for (int l = 0; l < size; ++l) {
            vector<int> row;
            row.resize(size);
            board.push_back(row);
        }

        for (int k = 0; k < size; ++k) {
            for (int j = 0; j < size; ++j) {
                cin >> board[k][j];
            }
        }

        cout << (jumpgame(0, 0, board) ? "YES" : "NO") << endl;
    }

    return 0;
}
