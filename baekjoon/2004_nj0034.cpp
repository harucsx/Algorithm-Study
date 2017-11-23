#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

long long int n, m;
long long int two, five;

long long int two_five(long long int n, long long int t_f) {
	long long int ans = 0;
	int mul = t_f;
	while (true) {
		if (n < t_f) {
			return ans;
		} else {
			ans += n / t_f;
			t_f *= mul;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	two = two_five(n, 2) - two_five(m, 2) - two_five(n - m, 2);
	five = two_five(n, 5) - two_five(m, 5) - two_five(n - m, 5);
	cout << min(two, five);

	return 0;
}