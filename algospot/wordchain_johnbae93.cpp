//
// Created by John on 2017-03-08.
//[시간초과]
#include <iostream>
#include <vector>

using namespace std;

void makeMap(vector<string> &v, int map[100][100]){
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v.size(); ++j) {
            if(i == j)
                continue;
            if(v[i][v[i].size() - 1] == v[j][v[j].size() - 1])
                map[i][j] = 1;
        }
    }
}

int findSol(vector<string> &v, vector<string> &s, int cur_index, int visit[100]) {
    visit[cur_index] = 1;
    s.push_back(v[cur_index]);
    int isAllVisited = 1;
    int i;

    for (i = 0; i < v.size(); ++i) {
        if (visit[i] == 0) {
            isAllVisited = 0;
            if (v[cur_index][v[cur_index].size() - 1] == v[i][0]) {
                if (findSol(v, s, i, visit) == 0)
                    return 0;
            }
        }
    }

    if(isAllVisited == 1)
        return 0;
    else {
        s.pop_back();
        visit[cur_index] = 0;
        return -1;
    }

}

int main(){
    int T;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        int num;
        cin>>num;
        vector<string> v;

        string tmp;

        for (int j = 0; j < num; ++j) {
            cin>>tmp;
            v.push_back(tmp);
        }

        int sol;
        int visit[100] = {0, };
        int map[100][100] = {0, };



        for (int k = 0; k < num; ++k) {
            vector<string> s; //sequence
            makeMap(v, map);
            sol = findSol(v, s, k, visit);

            if(sol != -1) {
                vector<string>::iterator it;

                for (it = s.begin(); it != s.end() ; ++it) {
                    cout<<*it<<" ";
                }
                cout<<endl;
                break;
            }
        }
        if(sol == -1)
            cout<<"IMPOSSIBLE"<<endl;
    }
}
