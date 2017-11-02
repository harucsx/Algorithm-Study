#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char line[110];

    while(fgets(line, 105, stdin)){
        size_t len = strlen(line);
        int lower = 0, upper = 0, digit = 0, blank = 0;

        for (size_t i = 0; i < len; ++i) {
            if ('a' <= line[i] && line[i] <= 'z')
                lower++;
            else if ('A' <= line[i] && line[i] <= 'Z')
                upper++;
            else if ('0' <= line[i] && line[i] <= '9')
                digit++;
            else if (line[i] == ' ')
                blank++;
        }

        cout << lower << ' ' << upper << ' ' << digit << ' ' << blank << '\n';
    }

    return 0;
}
