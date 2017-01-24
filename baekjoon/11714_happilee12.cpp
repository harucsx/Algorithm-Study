//
// Created by HANLEEKYEUNG on 2017. 1. 24.
//

/*
 *
문제  입력받은대로 출력
입력  입력이 주어진다. 입력은 최대 100줄로 이루어져 있고, 알파벳 소문자, 대문자, 공백, 숫자로만 이루어져 있다.
    각 줄은 100글자를 넘지 않으며, 빈 줄은 주어지지 않는다. 또, 각 줄은 공백으로 시작하지 않고, 공백으로 끝나지 않는다.
종료  eof

접근
 1. 입력은 최대 100이므로 100짜리 char배열 변수 선언
 2. cin.getline이 eof를 만나면 null을 반환할것    while(cin.getline(~)
 3. 받은건 a에 저장, 최대 101개 문자
 4. 그대로 출력
 */

#include <iostream>

using namespace std;

int main(){
    char a[100];
    while (cin.getline(a, 101))
        cout << a << endl;
}
