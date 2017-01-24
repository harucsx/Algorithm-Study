#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int main(int argc, char **argv) {
//    freopen("input.txt", "rb", stdin);
//    setbuf(stdout, NULL);

    int num, num_ans = 0;

    cin >> num;
    num_ans = num;

    for (int i = 0; i < num; ++i) {
        string input;
        cin >> input;

        set<char> char_set;
        pair<set<char>::iterator, bool> result;
        int len_input = input.size();
        char last_char = input.at(0);
        char_set.insert(last_char);

        for (int j = 1; j < len_input; ++j) {
            if (last_char == input.at(j))
                continue;

            result = char_set.insert(input[j]);
            last_char = input.at(j);
            if (!result.second) {
                num_ans--;
                break;
            }
        }
    }

    cout << num_ans << endl;
    return 0;
}
