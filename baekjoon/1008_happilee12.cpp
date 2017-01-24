//
// Created by HANLEEKYEUNG on 2017. 1. 24..
//

/*
 *
문제  A/B를 계산하시오.
입력  첫째 줄에 A와 B가 주어진다. (0 < A,B < 10)
출력  첫째 줄에 A/B를 출력한다. 절대/상대 오차는 10-9 까지 허용한다.

*/

#include <iostream>

using namespace std;

int main()
{
    double a, b=0;
    cout << fixed;
    cout.precision(13);
    cin>> a >> b;
    cout << a/b;
}
