#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

typedef struct student{

	char name[20];
	int kor;
	int eng;
	int math;

	bool operator < (student a){
		if (this->kor > a.kor) return true;
		else if(this->kor < a.kor) return false;
		else{
			if(this->eng < a.eng) return true;
			else if(this->eng > a.eng) return false;
			else{
				if(this->math > a.math) return true;
				else if(this->math < a.math) return false;
				else{
					if(strcmp(this->name, a.name) < 0) return true;
					else if(strcmp(this->name, a.name) > 0) return false;
				}
			}
		}
	}
}student;

int main(){

	int N;
	cin >> N;

	vector<student> students(N);

	for(int i=0; i<N; i++){
		cin >> students[i].name >> students[i].kor >> students[i].eng >> students[i].math;
	}

	sort(students.begin(), students.end());

	for(int i=0; i<N; i++){
		printf("%s\n", students[i].name);
	}

	return 0;
}
