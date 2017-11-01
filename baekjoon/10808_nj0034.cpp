#include <iostream>
#include <cstring>

using namespace std;

char word[100];
int sum;
string a = "abcdefghijklmnopqrstuvwxyz";

int main() {
    cin >> word;
    for (int j = 0; j < 26; ++j) {
        sum = 0;
        for (int i = 0; i < strlen(word); ++i) {
            if (word[i] == a[j]) {
                sum++;
            }
        }
        cout << sum;
        if (j == 25) {
            break;
        } else {
            cout << " ";
        }
    }
    return 0;
}