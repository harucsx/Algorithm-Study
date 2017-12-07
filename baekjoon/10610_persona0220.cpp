#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	vector<int> v;
	
	int n;
	int sum = 0;
	bool havezero = false;

	while(scanf("%1d", &n) != EOF){

		if(n == 0) havezero = true;
		sum += n;
		v.push_back(n);
	
	}

	if(sum % 3 == 0 && havezero){
		sort(v.begin(), v.end(), greater<int>());
		
		for(int i=0; i<v.size(); i++){
			printf("%d", v[i]);	
		}
	}
	else{
		printf("-1\n");
	}


	
	return 0;
}

