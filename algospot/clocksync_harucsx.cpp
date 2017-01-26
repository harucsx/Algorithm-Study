#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int clock_switch[10][16] = {{3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 3, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 0},
                            {0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 3},
                            {3, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 3, 0, 3, 0, 0, 0},
                            {3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
                            {0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
                            {0, 0, 0, 0, 3, 3, 0, 3, 0, 0, 0, 0, 0, 0, 3, 3},
                            {0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 3, 3, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0},
};

void clock_sync(vector<int> &click, int clock[16], int *value) {
    if (click.size() == 10) {
        int sum = 0;

        for (int i = 0; i < 16; ++i) {
            int rotated = clock[i];

            for (int j = 0; j < 10; ++j)
                rotated += click[j] * clock_switch[j][i];

            rotated %= 12;

            if (rotated > 0)
                return;
        }

        for (int l = 0; l < 10; ++l)
            sum += click[l];

        if (*value == -1 || sum < *value)
            *value = sum;

        return;
    }

    for (int i = 0; i < 4; ++i) {
        click.push_back(i);
        clock_sync(click, clock, value);
        click.pop_back();
    }
}

int main(int argc, char **argv) {
    int TC;

    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        int clock[16];
        int value = -1;
        vector<int> click;
        click.reserve(10);

        for (int l = 0; l < 16; ++l) {
            cin >> clock[l];
            clock[l] %= 12;
        }

        clock_sync(click, clock, &value);
        cout << value << endl;
    }

    return 0;
}
