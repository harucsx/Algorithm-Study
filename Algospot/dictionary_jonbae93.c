#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

char word[50][1000][40];
int matrix[50][30][30];
int queue[50][30];
int rear[50];
int visited[50][30];

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

void dict(int test, int num) {
	for (int i = 0; i < num - 1; i++) {
		int len = min(strlen(word[test][i]), strlen(word[test][i + 1]));
		for (int j = 0; j < len; j++) {
			if (word[test][i][j] != word[test][i + 1][j]) {
				int a = word[test][i][j] - 'a';
				int b = word[test][i + 1][j] - 'a';
				matrix[test][a][b] = 1;
				break;
			}
		}
	}
} 

void dfs(int test, int vertex) {
	visited[test][vertex] = 1;
	for (int i = 0; i < 26; i++) {
		if (matrix[test][vertex][i] && !visited[test][i])
			dfs(test, i);
	}
	queue[test][rear[test]++] = vertex;
	return;
}

void allDfs(int test) {
	for (int i = 0; i < 26; i++) {
		if(!visited[test][i])
			dfs(test, i);
	}
}

// cycle: return 1, not : return 0
int isCycle(int test) {
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			if (matrix[test][queue[test][i]][queue[test][j]])
				return 1;
		}
	}
	return 0;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%s", word[t][j]);
		}
		dict(t, num);
		allDfs(t);
		
	}
	for (int t = 0; t < T; t++) {
		if (isCycle(t))
			printf("INVALID HYPOTHESIS");
		else {
			for (int j = 25; j >= 0; j--)
				printf("%c", (char)(queue[t][j] + (int)('a')));
		}
		printf("\n");
	}
	
}

