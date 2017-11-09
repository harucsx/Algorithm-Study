#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;
ll n;

void solve(ll down, ll up, ll now){

	if(n < down || n > up) {
		if(now>0){
			solve(down + -2*now, up, now*-2);
		}
		else{
			solve(down, up + -2*now, now*-2);
		}
	}

	if(now<0){
		if(n < down - now){
			n -= now;
			printf("1");
		}
		else printf("0");
	}
	else{
		if(n > up - now){
			n-= now;
			printf("1");
		}
		else printf("0");
	}

}

int main(){
	
	cin >> n;
	solve(0, 1, 1);	

	return 0;
}

