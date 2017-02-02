/*
 *  아직 풀고 있는 문제입니다.
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

bool increase(vector<int> &list) {
    for (int i = 0; i < list.size() - 1; ++i) {
        if (list[i] > list[i + 1])
            return false;
    }
    return true;
}

int jlis(list<int> a, list<int> b) {
    vector<int> va(a.begin(), a.end());
    vector<int> vb(b.begin(), b.end());
    int max_a = 1, max_b = 1, result;
    list<int>::iterator i;

    a.remove(vb[0]);
    b.remove(va[0]);

    for (int j = 1; j < va.size(); ++j) {
        cout << "(" << va[j-1] << ", " << va[j] << ")" << endl;
        if (va[j] > va[j - 1])
            max_a++;
        else
            max_a = 1;
        b.remove(va[j]);
    }

    for (int j = 1; j < vb.size(); ++j) {
        cout << "(" << vb[j-1] << ", " << vb[j] << ")" << endl;
        if (vb[j] > vb[j - 1])
            max_b++;
        else
            max_b = 1;
        a.remove(vb[j]);
    }

    vector<int> da(a.begin(), a.end());
    vector<int> db(b.begin(), b.end());

    cout << "(a=" << max_a << ", b=" << max_b << ")" << endl;
    result = max_a + max_b;

    return result;
}

int main(int argc, char **argv) {
    /**************************************/
    freopen("input.txt", "r", stdin);
    setbuf(stdout, NULL);
    /**************************************/

    int TC;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        unsigned num_a, num_b;
        list<int> a, b;
        int num;

        cin >> num_a >> num_b;

        for (int j = 0; j < num_a; ++j) {
            cin >> num;
            a.push_back(num);
        }

        for (int j = 0; j < num_b; ++j) {
            cin >> num;
            b.push_back(num);
        }

        cout << jlis(a, b) << endl;
    }

    return 0;
}
