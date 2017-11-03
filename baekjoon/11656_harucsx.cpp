#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
#endif

    string word;
    vector<string> words;

    cin >> word;
    words.reserve(word.size());

    unsigned long len = word.size();

    for (int i = 0; i < len; ++i) {
        words.push_back(word);
        word = word.substr(1);
    }

    sort(words.begin(), words.end());

    for (int i = 0; i < words.size(); ++i) {
        cout << words[i] << '\n';
    }
    return 0;
}
