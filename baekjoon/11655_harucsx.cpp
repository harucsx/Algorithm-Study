#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char line[110];

    while (fgets(line, 105, stdin)) {
        size_t len = strlen(line);

        for (size_t i = 0; i < len; ++i) {
            if ('a' <= line[i] && line[i] <= 'z') {
                line[i] += (line[i] + 13 > 'z') ? -13 : 13;
            } else if ('A' <= line[i] && line[i] <= 'Z') {
                line[i] += (line[i] + 13 > 'Z') ? -13 : 13;
            } else if (!(('0' <= line[i] && line[i] <= '9') || line[i] <= ' ')) {
                break;
            }
        }

        cout << line;
    }

    return 0;
}
