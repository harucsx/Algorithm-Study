#include<iostream>
#include<math.h>
#include <vector>
#include <algorithm>
#define FOR(a, max) for(int a=0; a<max; a++)
using namespace std;

int testcase;
string temp;
int cache3[1001];
int cache4[10001];
int cache5[100001];
int pi[10001] = {0, };

int find_min(int a, int b, int c){
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}
void print(vector<int> &a) {
    for (int x : a) {
        cout << x << ' ';
    }
    cout << '\n';
}
int regex(int st, int num){

//    for(int i = st+1; i<=st+num; i++){
//        cout << temp[i];
//    }cout << endl;
    //st, st+1, st..+(num-1) 에서의 규칙
    vector<int> order;
    bool c1 = true, c2= true, c3= true, c4= true, c5= true;
    order.push_back(0);
    for(int i = st+1; i<= st+num-1; i++){
//        cout << temp[i+1] <<" "<< temp[i] << " "<< temp[i+1]-temp[i]<<endl;
        order.push_back(temp[i+1]-temp[i]);
    }
//    print(order);
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
//    cout << "in?" << endl;
    if(c1) return 1;
    else if(c2) return 2;
    else if(c3) return 2;
    else if(c4) return 4;
    else if (c5) return 5;
    else return 10;
}

int match(int index, int digit){
    int intoNumber = 0;
//    cout<<"checker1" << endl;

    for(int i = 0; i<digit; i++){
//        cout<<"checker2" << endl;
        intoNumber += (temp[index-i] - '0')*pow(10,i);
    }
//    cout << "number : " << intoNumber << endl;

    if(digit == 3){
        if(cache3[intoNumber]) return cache3[intoNumber];
        else{
            int result = regex(index-digit, digit);
            cache3[intoNumber] = result;
//            cout << "CHECK!!" << result <<endl;
            return result;
        }
    }else if(digit==4){
        if(cache4[intoNumber]) return cache4[intoNumber];
        else {
            int result = regex(index - digit, digit);
            cache4[intoNumber] = result;
//            cout << "CHECK!!" << result << endl;
            return result;
        }
    }else{
        if(cache5[intoNumber]) return cache5[intoNumber];
        else{
            int result = regex(index-digit, digit);

            cache5[intoNumber] = result;
//            cout << "CHECK!!" << result <<endl;
            return result;
        }
    }


}
int solve(){
    unsigned long length;
    cin >> temp;
    length = temp.length();
    cout << temp << endl;
    pi[3] = match(2,3);
    pi[4] = match(3,4);
    pi[5] = match(4,5);
    pi[6] = pi[3] + match(5,3);
    pi[7] = min(pi[4] + match(6,3), pi[3]+match(6,4));
    for(int index = 6; index < length; index++){
        pi[index] = find_min(pi[index-5]+match(index, 5), pi[index-4]+match(index,4), pi[index-3]+match(index,3));
    }
    for(int i = 1; i<length+1; i++)
        cout<<pi[i] <<" ";
    cout << endl;

    return pi[length-1];
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> testcase;
    while(testcase--){
//        solve();
        cout << solve() << endl;
    }

    memset(pi, 0, 10001);
    return 0;

}