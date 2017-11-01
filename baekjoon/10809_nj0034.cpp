#include <iostream>
#include <cstring>

using namespace std;

char word[100];
int cursor;
string a = "abcdefghijklmnopqrstuvwxyz";

int main() {
    cin >> word;
    for (int j = 0; j < 26; ++j) {
        cursor = -1;
        for (int i = 0; i < strlen(word); ++i) {
            if (word[i] == a[j]) {
                cursor = i;
                break;
            }
        }
        if (cursor == -1) {
            cout << "-1";
        } else {
            cout << cursor;
        }
        if (j == 25) {
            break;
        } else {
            cout << " ";
        }
    }
    return 0;
}