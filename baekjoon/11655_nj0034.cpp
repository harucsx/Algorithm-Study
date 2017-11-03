#include <iostream>
#include <cstring>

using namespace std;

char word[101];
string a = "abcdefghijklmnopqrstuvwxyz";
string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    fgets(word, 101, stdin);
    for (int i = 0; i < strlen(word); ++i) {
        for (int j = 0; j < 26; ++j) {
            if (word[i] == a[j]) {
                cout << a[(j + 13) % 26];
                break;
            }
            if (word[i] == A[j]) {
                cout << A[(j + 13) % 26];
                break;
            }
            if (j == 25) {
                cout << word[i];
            }
        }
    }
    return 0;
}
