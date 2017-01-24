#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int count_pair(int num_student, bool pair[10][10], bool finished[10]) {
    int result = 0;
    int person1 = -1, person2;

    for (int i = 0; i < num_student; ++i) {
        if (!finished[i]) {
            person1 = i;
            break;
        }
    }

    if (person1 == -1){
        return 1;
    }


    for (person2 = person1 + 1; person2 < num_student; ++person2) {
        if (!finished[person2] && pair[person1][person2]) {
            finished[person1] = finished[person2] = true;
            result += count_pair(num_student, pair, finished);
            finished[person1] = finished[person2] = false;
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
        int num_student;
        int num_pair;
        bool pair[10][10];
        bool finished[10];

        memset(pair, 0, 100);
        memset(finished, 0, 10);

        cin >> num_student >> num_pair;

        for (int j = 0; j < num_pair; ++j) {
            int person1, person2;
            cin >> person1 >> person2;
            pair[person1][person2] = pair[person2][person1] = true;
        }

        cout << count_pair(num_student, pair, finished) << endl;
    }

    return 0;
}
