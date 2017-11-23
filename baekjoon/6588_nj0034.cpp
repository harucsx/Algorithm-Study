#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

int n, p;
bool data[1000001];
int prime[1000000];

int main() {
	freopen("input.txt", "r", stdin);
	data[1] = true;
	for (int j = 2; j <= 1000000; ++j) {
		if (data[j]) {
			continue;
		} else {
			prime[p] = j;
			p++;
		}
		for (int k = 2 * j; k <= 1000000; k += j) {
			data[k] = true;
		}
	}
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		for (int l = 1; l < p; l++) {
			if (!data[n - prime[l]]) {
				printf("%d = %d + %d\n", n, prime[l], n - prime[l]);
				break;
			}
		}
	}
	return 0;
}