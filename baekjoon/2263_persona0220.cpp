#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, in[100010], post[100010];

void solve(int in_left,int in_right,int post_left,int post_right){
	if(post_left > post_right) return;

	printf("%d ", post[post_right]);

	solve(in_left, in[post[post_right]] -1, post_left, in[post[post_right]] -1 -in_left + post_left);
	solve(in[post[post_right]]+1, in_right, post_right - in_right + in[post[post_right]], post_right -1);
}

int main(){
	
	scanf("%d", &n);
	int temp;
	for(int i=0; i<n; i++){
		scanf("%d", &temp);
		in[temp] = i;
	} 
	for(int i=0; i<n; i++){
		scanf("%d", &post[i]);
	}

	solve(0, n-1, 0, n-1);

	return 0;
}

