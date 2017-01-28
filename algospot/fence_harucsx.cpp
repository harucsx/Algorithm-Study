#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int get_rect(int left, int right, vector<int> &height) {
    if (left == right)
        return height[left];

    int result, mid;
    int mid_left, mid_right, min_height;

    mid = (left + right) / 2;
    result = max(get_rect(left, mid, height), get_rect(mid + 1, right, height));

    mid_left = mid;
    mid_right = mid + 1;
    min_height = min(height[mid_left], height[mid_right]);
    result = max(result, (mid_right - mid_left + 1) * min_height);

    while (mid_left != left || mid_right != right){
        if (height[mid_left - 1] > height[mid_right+1] && mid_left > left) {
            mid_left--;
        } else if (height[mid_left - 1] < height[mid_right+1] && mid_right < right) {
            mid_right++;
        } else {
            if (mid_left > left)
                mid_left--;
            else
                mid_right++;
        }

        min_height = min(min_height, min(height[mid_left], height[mid_right]));
        result = max(result, (mid_right - mid_left + 1) * min_height);
    }

    return result;
}

int main(int argc, char **argv) {
    int TC;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        unsigned num;
        vector<int> height;

        cin >> num;
        height.resize(num);

        for (int j = 0; j < num; ++j) {
            cin >> height[j];
        }
        cout << get_rect(0, num - 1, height) << endl;
    }

    return 0;
}
