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