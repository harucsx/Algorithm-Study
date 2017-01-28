#include <cstdio>
#include <iostream>

using namespace std;

bool block[4][4] = {{1, 1, 1, 0},
                    {0, 1, 1, 1},
                    {1, 0, 1, 1},
                    {1, 1, 0, 1}};

int x[4] = {0, 0, 1, 1};
int y[4] = {0, 1, 0, 1};

int count_cover(int width, int height, int depth, bool board[21][21]) {
    int result = 0;
    int num_space = 0;
    int xpos = -1, ypos = -1;

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (board[i][j]){
                xpos = (xpos == -1) ? i : xpos;
                ypos = (ypos == -1) ? j : ypos;
                num_space++;
            }
        }
    }

    if (num_space == 0) {
        return 1;
    } else if (num_space % 3 != 0) {
        return 0;
    } else if ((width * height) / 3 < depth) {
        return 0;
    }

    for (int type = 0; type < 4; ++type) {
        bool compair = true;

        if (type == 3)
            ypos--;

        for (int pos = 0; pos < 4; ++pos)
            compair &= board[xpos + x[pos]][ypos + y[pos]] || !block[pos][type];

        if (compair) {
            for (int pos = 0; pos < 4; ++pos)
                board[xpos + x[pos]][ypos + y[pos]] ^= block[pos][type];

            depth++;
            result += count_cover(width, height, depth, board);
            depth--;

            for (int pos = 0; pos < 4; ++pos)
                board[xpos + x[pos]][ypos + y[pos]] ^= block[pos][type];
        }
    }

    return result;
}

int main(int argc, char **argv) {
    int TC;

    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        int width, height;
        bool board[21][21];

        cin >> width >> height;

        for (int k = 0; k < width; ++k) {
            for (int j = 0; j < height; ++j) {
                char tmp;
                cin >> tmp;

                board[k][j] = (tmp == '.');
            }
        }

        cout << count_cover(width, height, 0, board) << endl;
    }

    return 0;
}
