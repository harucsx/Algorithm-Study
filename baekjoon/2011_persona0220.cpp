#include <iostream>
#include <algorithm>
#include <string.h>

#define nanugi 1000000 

using namespace std;

char input[5010];
int cache[5010];
int len;

int solve(int start){
	if(input[start] == '0') return 0;

	if(start == len || start == len-1){
		return 1;
	}

	int &ret = cache[start];
	if(ret != -1) return ret;
	
	ret = 0;
	if((input[start] == '1') || (input[start] == '2' && (input[start+1] >='0' && input[start+1] <= '6'))){
		ret += solve(start+2);
		ret %= nanugi;
	}
	if(input[start+1] != '0')
		ret += solve(start+1);
	
	ret %= nanugi;
	return ret;
}


int main(){
	
	cin >> input;
	len = strlen(input);
	
	for(int i=0; i<5010; i++){
		cache[i] = -1;
	}
	
	cout << solve(0)%nanugi << endl;

	return 0;
}

