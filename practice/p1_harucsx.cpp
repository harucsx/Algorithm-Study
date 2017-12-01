#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    int result = -1;
    vector<int> nums;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int in;
        cin >> in;
        nums.push_back(in);
    }

    sort(nums.begin(), nums.end());

    do {
        int local = 0;

        for (int i = 0; i < N - 1; ++i)
            local += abs(nums[i + 1] - nums[i]);

        result = max(result, local);
    } while (next_permutation(nums.begin(), nums.end()));

    cout << result;
    return 0;
}
