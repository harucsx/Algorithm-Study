#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

ll count(ll n, ll c){
	//1에서 n까지 c의 개수


	ll now = c;

	ll ret = 0;
	while(n >= now){
		ret += n/now;
		now *= c;
	}
	return ret;
}


int main(){
	
	ll n,m;
	scanf("%lld %lld", &n, &m);
	if(m > n/2) m = n-m;

	ll two = count(n, 2) - count(n-m, 2) - count(m,2);
	ll five = count(n, 5) - count(n-m, 5) - count(m, 5);

	cout << min(two, five) <<endl;

	return 0;
}

