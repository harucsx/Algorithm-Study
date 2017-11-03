#include <iostream>
#include <cstring>

using namespace std;

char word[101];

int main() {
    freopen("input.txt", "r", stdin);
    cin >> word;
    cout << strlen(word);
    return 0;
}