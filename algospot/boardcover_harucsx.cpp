/*
 *
 *  문제가 하나 있는데 순서를 고정시켜야함.. 내일 해야지
 *
 */

#include <cstdio>
#include <iostream>

using namespace std;

int count_cover(int width, int height, int depth, bool board[20][20]) {
    int result = 0;
    int num_space = 0;

    bool block[4][4] = {{1, 1, 1, 0},
                        {0, 1, 1, 1},
                        {1, 0, 1, 1},
                        {1, 1, 0, 1}};

    int x[4] = {0, 0, 1, 1};
    int y[4] = {0, 1, 0, 1};

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (board[i][j])
                num_space++;
        }
    }

    /*
     *  DEBUG INFO
     */
    cout << "num_space : " << num_space << " depth : " << depth << endl;

    for (int l = 0; l < width; ++l) {
        for (int j = 0; j < height; ++j) {
            cout << board[l][j];
        }
        cout << endl;
    }

    if (num_space == 0) {
        return 1;
    } else if (num_space % 3 != 0) {
        return 0;
    } else if ((width * height) / 3 < depth) {
        return 0;
    }

    for (int i = 0; i < width - 1; ++i) {
        for (int j = 0; j < height - 1; ++j) {
            for (int type = 0; type < 4; ++type) {
                bool compair = true;

                for (int pos = 0; pos < 4; ++pos)
                    compair &= board[i + x[pos]][j + y[pos]] || !block[pos][type];

                if (compair) {
                    for (int pos = 0; pos < 4; ++pos)
                        board[i + x[pos]][j + y[pos]] ^= block[pos][type];

                    result += count_cover(width, height, ++depth, board);
                    depth--;

                    for (int pos = 0; pos < 4; ++pos)
                        board[i + x[pos]][j + y[pos]] ^= block[pos][type];
                }
            }
        }
    }

    return result;
}

int main(int argc, char **argv) {
    freopen("input.txt", "r", stdin);
    setbuf(stdout, NULL);

    int TC;

    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        int width, height;
        bool board[20][20];

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
