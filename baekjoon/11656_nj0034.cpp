#include <iostream>
#include <algorithm>

using namespace std;

string s;
string tail[1000];

int main() {
    freopen("input.txt", "r", stdin);
    cin >> s;

    for (int i = 0; i < s.length(); ++i) {
        tail[i].append(s, i, s.length());
    }

    sort(tail, tail + s.length());
    for (int j = 0; j < s.length(); ++j) {
        cout << tail[j] << endl;
    }
    return 0;
}