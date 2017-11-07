#include <stdio.h>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(){
	
	string input;
	list<char> str;
	int N;

	cin >> input;

	for(int i=0; i<input.size(); i++){
		str.push_back(input[i]);
	}

	cin >> N;


	list<char>::iterator iter;
	iter = str.end();

	for(int i=0; i<N; i++){
		
		char command;
		cin >> command;

		if(command == 'L'){
			if(iter != str.begin()) iter--;		
		}
		else if(command == 'D'){
			if(iter != str.end()) iter++;
		}
		else if(command == 'B'){
			if(iter != str.begin()){
				iter--;
				iter = str.erase(iter);
			}	
		}
		else if(command == 'P'){
			cin >> command;
			str.insert(iter, command);
		}
		
	}
	
	for(iter = str.begin(); iter!=str.end(); iter++){
		cout << *iter;
	}
	cout << endl;


	return 0;
}
