#include <iostream>

using namespace std;

int main() {
    string word;
    cin >> word;

    for (int i = 'a'; i <= 'z'; ++i) {
        cout << (int) word.find((char) i) << " ";
    }

    return 0;
}