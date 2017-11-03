#include <iostream>
#include <cstring>

using namespace std;

char word[110];
int c, C, num, blank, check;
string a = "abcdefghijklmnopqrstuvwxyz";
string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string d = "0123456789";

int main() {
    freopen("input.txt", "r", stdin);
    for (int i = 0; i < 110; ++i) {
        if(!fgets(word, 110, stdin))
            break;
        if (i) {
            cout << endl;
        }
        if(word[strlen(word)-1] == '\n'){
            blank--;
        }
        for (int j = 0; j < strlen(word); ++j) {
            for (int k = 0; k < 26; ++k) {
                if (word[j] == a[k]) {
                    c++;
                    check++;
                    break;
                }
                if (word[j] == A[k]) {
                    C++;
                    check++;
                    break;
                }
                if (k < 10) {
                    if (word[j] == d[k]) {
                        num++;
                        check++;
                        break;
                    }
                }
            }
            if (check == 1) {
                check--;
                continue;
            }
            blank++;
        }
        cout << c << " " << C << " " << num << " " << blank;
        c = C = num = blank = 0;
    }
    return 0;
}