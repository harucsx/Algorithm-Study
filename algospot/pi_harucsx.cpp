#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int diff[10000][3];

int chartoi(char c) {
    return c - '0';
}

int get_diff(string number) {
    if (number.size() > 5 || number.size() < 3)
        return 0x70FFFFFF;

    set<int> s(number.begin(), number.end());

    if (s.size() == 1)
        return 1;

    if (s.size() == number.size()) {
        bool diff2or5 = true;

        int sub = chartoi(number[0]) - chartoi(number[1]);
        for (int i = 1; i < number.size() - 1; ++i) {
            if (chartoi(number[i]) - chartoi(number[i + 1]) != sub) {
                diff2or5 = false;
                break;
            }
        }

        if (diff2or5) {
            if (sub == 1 || sub == -1)
                return 2;
            else
                return 5;
        }
    }

    if (s.size() == 2) {
        bool diff4 = true;
        char first = number[0];
        char second = number[1];

        for (int i = 0; i < number.size(); ++i)
            if (number[i] != ((i % 2 == 0) ? first : second)) {
                diff4 = false;
                break;
            }

        if (diff4)
            return 4;
    }

    return 10;
}

int pi(string &number, int num) {
    if (num < 2)
        return 1000;

    for (int i = 0; i < 3; ++i)
        if (!diff[num][i]) {
            int len = i + 3;
            int start_pos = num - (i + 2);
            start_pos = (start_pos > 0) ? start_pos : 0;
            diff[num][i] = pi(number, num - len) + get_diff(number.substr(start_pos, len));
        }

    int result = min(diff[num][0], diff[num][1]);
    result = min(result, diff[num][2]);

    return result;
}

int main(int argc, char **argv) {
    int TC;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); ++j)
            diff[j][0] = diff[j][1] = diff[j][2] = 0;

        diff[2][0] = diff[2][1] = diff[2][2] = get_diff(str.substr(0, 3));
        diff[3][0] = diff[3][1] = diff[3][2] = get_diff(str.substr(0, 4));
        diff[4][0] = diff[4][1] = diff[4][2] = get_diff(str.substr(0, 5));

        cout << pi(str, str.size() - 1) << endl;
    }

    return 0;
}
