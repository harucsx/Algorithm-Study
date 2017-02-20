//
// 시간초과............ㅠㅠ
//

#include<iostream>
#include<vector>

using namespace std;

int find_min(int a, int b, int c){
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}

int match(vector <int> pi, int st, int num){
    //st, st+1, st..+(num-1) 에서의 규칙
    vector<int> order;
    bool c1 = true, c2= true, c3= true, c4= true, c5= true;
    order.push_back(0);
    for(int i = st; i< st+num-1; i ++){
        order.push_back(pi[i+1]-pi[i]);
    }
    for(int i = 1; i<order.size(); i++) {
        if(c1 && order[i] != 0 ) c1 = false;
        if(c2 && order[i] != 1) c2 = false;
        if(c3 && order[i] != -1) c3 = false;
        //전의 규칙이랑 비교하는 애들이므로 2부터 검사
        if(i > 1) {
            if (c4 && order[i] != (-1) * order[i - 1]) c4 = false;
            if (c5 && order[i] != order[i - 1]) c5 = false;
        }
    }

    if(c1) return 1;
    else if(c2) return 2;
    else if(c3) return 2;
    else if(c4) return 4;
    else if (c5) return 5;
    else return 10;
}

int main(void){
//    freopen("input.txt", "r", stdin);
    int tc;
    string wc;
    scanf("%d ",&tc);
    while(tc-- > 0){
        string temp;
        vector<int> input;
        int pi[10001] = {0, };
        cin >> temp;
        //O(n)
        for(int i = 0; i < temp.length(); i++){
            if(temp[i] < '0' || temp[i] > '9')
                break;
            else input.push_back(temp[i]-'0');
        }
        //O(n)
        for(int i = 0 ; i <input.size(); i++){
            if(i < 2)
                pi[i] = 0;
            else if(i<5){
                pi[i] = match(input, 0, i+1);
            }
            else{
                int a1 = pi[i-3]+match(input, i-2, 3);
                int a2 = pi[i-4]+match(input, i-3, 4);
                int a3 = pi[i-5]+match(input, i-4, 5);
                pi[i] = find_min(a1, a2, a3);
            }
        }
        cout << pi[temp.length()-1] << endl;
    }
    return 0;
}

//#include<iostream>
//#include<vector>
//#include <limits.h>
//
//using namespace std;
//
//string N;
//int cache[10002];
//
//int classify(int a, int b){
//    string M = N.substr(a, b-a+1);
//    //모두 같음
//    if(M == string(M.size(), M[0])) return 1;
//    //등차수열
//    bool progressive = true;
//    for(int i = 0 ; i < M.size()-1; ++i)
//        if(M[i+1]-M[i]!=M[1]-M[0])
//            progressive = false;
//    //등차수열이고 공차가 1 또는 -1
//    if(progressive && abs(M[1]-M[0]) == 1)
//        return 2;
//    bool alternating = true;
//    for(int i = 0 ; i< M.size(); ++i)
//        if(M[i] != M[i%2])
//            alternating = false;
//    if(alternating) return 4;
//    if(progressive) return 5;
//    return 10;
//}
//
//int memorize(int begin){
//    cout<< begin;
//    if(begin == N.size()){
//        return 0;
//    }
//    int& ret = cache[begin];
//    if(ret != -1){
//        cout<< "here1"<<endl;
//        return ret;
//    }
//    ret = INT_MAX;
//    for(int L = 3; L<=5; L++)
//        if(begin + L <= N.size())
//            ret = min(ret, memorize(begin+L)+classify(begin, begin+L-1));
//    return ret;
//}
//
//int main(void){
//    freopen("input.txt", "r", stdin);
//    int tc;
//    scanf("%d ",&tc);
//    while(tc-- > 0){
//        memset(cache, 0, 10002);
//        cin >> N;
//        cout << memorize(0) << endl;
//    }
//    return 0;
//}