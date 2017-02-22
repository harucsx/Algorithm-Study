//
// Created by John on 2017-02-20.
//
#include <iostream>
#include <vector>

using namespace std;

int findSol(vector<int> &v) {
    int sol = 0;
    for (int i = 0; i < v.size(); ++i) {

        int j = 0;
        int max = v[i];
        if(max * v.size() < sol)
            continue;
        int check_left = 0;
        int check_right = 0;
        while(true){
            j++;

            if(i - j >= 0 && v[i - j] >= v[i] && check_left == 0)
                max += v[i];
            else
                check_left = 1;

            if(i + j < v.size() && v[i + j] >= v[i] && check_right == 0)
                max +=v[i];
            else
                check_right = 1;

            if(check_left == 1 && check_right == 1)
                break;
        }
        if (max > sol)
            sol = max;
    }

    return sol;
}

int main() {
    int T;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        int num;
        cin>>num;

        vector<int> v;
        for (int j = 0; j < num; ++j) {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        int sol = findSol(v);
        cout<<sol<<endl;
    }

}
