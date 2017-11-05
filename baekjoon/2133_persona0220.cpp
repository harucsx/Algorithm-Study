#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[100] = {0};

int main(){
	
	cin >> n;
	if(n%2 == 1){
		cout << 0 << endl;
		return 0;
	}
	
	d[0]=1;
	d[2]=3;
	for(int i=4;i<=n;i+=2){
		d[i]=3*d[i-2];
		for(int j=4;j<=i;j+=2){
			d[i]+=2*d[i-j];
		}
	}
	
	cout << d[n] << endl;
	return 0;
}

