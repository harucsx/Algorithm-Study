#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

map<unsigned long long, int> cache;

unsigned long long get_max(int k) {
    unsigned long long result = 1;
    return result << k;
}

unsigned long long get_min_h(int k) {
    unsigned long long result = 1;

    for (int i = 0; i < k; ++i) {
        if (result < 5 || (result - 1) % 3 != 0)
            result *= 2;
        else
            result = (result - 1) / 3;
    }

    return result;
}

unsigned long long get_min(int k) {
    unsigned long long min_h = get_min_h(k);

    for (unsigned long long i = 2; i < min_h; ++i) {
        if (cache.find(i) == cache.end()) {
            unsigned long long value = i;
            int result = 0;

            while (value != 1U) {
                if (value % 2 == 0) {
                    value >>= 1;
                } else {
                    value = value * 3 + 1;
                }
                result++;
            }
            cache[i] = result;
        }

        if(cache[i] == k)
            return i;
    }
}

int main(int argc, char **argv) {
    /**************************************/
    freopen("input.txt", "r", stdin);
    setbuf(stdout, NULL);
    /**************************************/

    int TC;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        int num;

        cin >> num;
        cout << "Case #" << i + 1 << '\n';
        cout << get_min(num) << " " << get_max(num) << '\n';
    }

    return 0;
}
