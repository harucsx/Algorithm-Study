#include <stdio.h>

int friend[60][11][11]; // pair : 1
int selected[60][11]; // selected : 1
int sol[60];

int findSol(int num, int pair, int start, int pairs, int *sol, int test);

int main() {
	int T;
	int num;
	int pair;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &num, &pair);
		
		for (int j = 0; j < pair; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			friend[i][a][b] = 1;
			friend[i][b][a] = 1;
		}
		findSol(num, pair, 0, 0, sol, i);
		
	}
	for (int i = 0; i < T; i++) {
		printf("%d\n", sol[i]);
	}
}

int findSol(int num, int pair, int start, int pairs, int *sol, int test) {
	if (pairs == num / 2) {
		//for (int i = 0; i < 10; i++) selected[i] = 0;
		(sol[test])++;
		return 1;
	} 

	for (int i = start; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (friend[test][i][j] == 1 && selected[test][i] == 0 && selected[test][j] == 0) {
				selected[test][i] = selected[test][j] = 1;
				findSol(num, pair, i + 1, pairs + 1, sol, test);
				selected[test][i] = selected[test][j] = 0;
			}

		}
		
	}
	return 0;
}
