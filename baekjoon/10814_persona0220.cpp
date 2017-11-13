#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

typedef struct student{

	int num;
	int age;
	char name[150];

	bool operator < (student a){

		if(this->age < a.age) return true;
		else if(this->age > a.age) return false;
		else{
			if(this->num < a.num) return true;
			else if(this->num > a.num) return false;
		}

	}

}student;

int main(){

	int N;
	cin >> N;

	vector<student> students(N);
	for(int i=0; i<N; i++){
		cin >> students[i].age >> students[i].name;
		students[i].num = i;
	}

	sort(students.begin(), students.end());

	for(int i=0; i<N; i++){
		printf("%d %s\n", students[i].age, students[i].name);
	}

	return 0;
}
