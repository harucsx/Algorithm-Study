#include <iostream>
#include <vector>

using namespace std;

int main() {
    string word;
    vector<int> count;

    cin >> word;
    count.resize(26);

    for (int i = 0; i < word.size(); ++i) {
        count[word[i] - 'a']++;
    }

    for (int i = 0; i < 26; ++i) {
        cout << count[i] << " ";
    }

    return 0;
}