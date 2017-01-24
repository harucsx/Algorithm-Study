#include <stdio.h>

#pragma warning(disable:4996)

int visited[200000]; //visit : 1
int queue[200000][2];
int front, rear;

int findSol(int n, int k, int count) {
	visited[n] = 1;
	queue[rear][0] = n;
	queue[rear++][1] = count;

	int newn;
	while (rear != front) {
		newn = queue[front][0];
		if (newn == k) return queue[front][1];

		if (newn * 2 < 200000 && visited[newn * 2] == 0) {
			visited[newn * 2] = 1;
			queue[rear][0] = newn * 2;
			queue[rear++][1] = queue[front][1] + 1;
		}
		if (newn + 1 < 200000 && visited[newn + 1] == 0) {
			visited[newn + 1] = 1;
			queue[rear][0] = newn + 1;
			queue[rear++][1] = queue[front][1] + 1;
		}
		if (newn - 1 >= 0 && visited[newn - 1] == 0) {
			visited[newn - 1] = 1;
			queue[rear][0] = newn - 1;
			queue[rear++][1] = queue[front][1] + 1;
		}
		front++;
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", findSol(n, k, 0));
}