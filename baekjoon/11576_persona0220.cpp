#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int A,B, sum=0, base=1, n;
	int i,j;

	cin >> A >> B;
	cin >> n;

	int input[30];
	int output[100];

	for(i=0; i<n; i++){
		cin >> input[i];
	}

	for(i = n-1; i>=0; i--){
		sum += input[i]*base;
		base *= A;
	}

	i=0;
	while(sum){
		output[i++] = sum%B;
		sum /= B;
	}

	for(j=i-1; j>=0; j--){
		cout << output[j] << " ";
	}
	cout << endl;
	return 0;
}

