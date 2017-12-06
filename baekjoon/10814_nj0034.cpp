#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int n;

struct Person {
    int age;
    string name;
};

bool cmp(const Person &u, const Person &v) {
    return u.age < v.age;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<Person> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].age >> p[i].name;
    }
    stable_sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < n; ++i) {
        cout << p[i].age << " " << p[i].name << '\n';
    }

    return 0;
}