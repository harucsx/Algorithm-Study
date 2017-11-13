#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

int main(){
	
	int N;
	scanf("%d", &N);
	
	set<string, greater<string> > company;

	string name;
	string status;
	for(int i=0; i<N; i++){
		cin >> name >> status;

		if(status.compare("enter")==0){
			company.insert(name);
		}
		else if(status.compare("leave")==0){
			company.erase(company.find(name));
		}
	}

	set<string>::iterator it = company.begin();
	
	for(it =  company.begin(); it != company.end(); it++){
		cout << *it << "\n";
	}


	return 0;
}

