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
	string name;
	int kor;
	int eng;
	int math;
};

bool cmp(const Person &u, const Person &v) {
	if (u.kor > v.kor) {
		return true;
	} else if (u.kor == v.kor) {
		if (u.eng < v.eng) {
			return true;
		} else if (u.eng == v.eng) {
			if (u.math > v.math) {
				return true;
			} else if (u.math == v.math) {
				return u.name < v.name;
			}
		}
	}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	vector<Person> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i].name >> p[i].kor >> p[i].eng >> p[i].math;
	}
	sort(p.begin(), p.end(), cmp);
	for (int i = 0; i < n; ++i) {
		cout << p[i].name << '\n';
	}

	return 0;
}