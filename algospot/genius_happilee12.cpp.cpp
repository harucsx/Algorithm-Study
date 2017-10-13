//
// Created by HANLEEKYEUNG on 2017. 9. 10..
// not workin!!!!


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MOD = 10;

int main()
{
    int T;
    cin >> T;

    cout.precision(8);
    while(T--)
    {
        int N, K, M;
        cin >> N >> K >> M;

        int mLen[51];
        for(int i=0; i < N; i++)
            cin >> mLen[i];

        double nextProb[51][51];
        for(int i=0; i < N; i++)
            for(int j=0; j < N; j++)
                cin >> nextProb[i][j];

        int favor[11];
        for(int i=0; i < M; i++)
            cin >> favor[i];

        double ans[MOD][51] = {};
        bool changed[MOD][51] = {};

        ans[0][0] = 1;
        changed[0][0] = true;

        for(int i=1; i <= K; i++)
        {
            for(int j=0; j < N; j++)
            {
                changed[i % MOD][j] = false;
                ans[i % MOD][j] = 0;
                for(int k=0; k < N; k++)
                {
                    if(mLen[k] > i)
                        continue;

                    if(changed[(i-mLen[k]) % MOD][k])
                    {
                        changed[i % MOD][j] = true;
                        ans[i % MOD][j] += ans[(i-mLen[k]) % MOD][k] * nextProb[k][j];
                    }
                }
            }
        }

        for(int i=0; i < M; i++)
        {
            double ret = ans[K % MOD][favor[i]];
            for(int j=1; K-j >= 0 && j < mLen[favor[i]]; j++)
                ret += ans[(K-j) % MOD][favor[i]];
            cout << ret << " ";
        }
        cout << '\n';
    }
    return 0;
}
//#include <iostream>
//#include <vector>
//#include <cstring>
//using namespace std;
////define
//#define FOR(var, num) for(int var=0; var<num; var++)
//
//int numOfSongs;
//int k;
//int likes;
//int lengthOfSongs[50];
//double probMatrix[50][50];
////시간을 고려한 matrix
//double timeMatrix[50][200];
//double vector[200];
//
//void calc(){
//
//}
//int main(){
//        freopen("input.txt", "r", stdin);
//    int t; cin>>t;
//    while(t--){
//        cin >> numOfSongs; cin >> k; cin >> likes;
//        FOR(i, numOfSongs){
//            cin >> lengthOfSongs[i];
//        }
//        FOR(i, numOfSongs){
//            FOR(j, numOfSongs){
//                cin >> probMatrix[i][j];
//            }
//        }
//        while(likes--){
//            int song;
//            cin >> song;
//            double ret=0;
//            cout.precision(9);
//            cout << ret << " ";
//        }
//        cout << endl;
//    }
//}
////double probCache[5][50];
////void dp(int k){
////    for(int time = 1; time < k+1; time++){
////        FOR(song, numOfSongs){
////            probCache[time%5][song] = 0;
////            // probCache[time][song] 을 구할 것
////            FOR(i, numOfSongs){
////                if(time-lengthOfSongs[i] >= 0){
////                    probCache[time%5][song] += probCache[(time-lengthOfSongs[i])%5][i]*probMatrix[i][song];
////                }
////            }
////        }
////    }
////}
//
//
////int main(){
//////    freopen("input.txt", "r", stdin);
////    int t; cin>>t;
////    while(t--){
////        cin >> numOfSongs; cin >> k; cin >> likes;
////        //init cache
////        FOR(i, 5){
////            FOR(j, 50) probCache[i][j] = 0;
////        }
////        FOR(i, numOfSongs){
////            cin >> lengthOfSongs[i];
////        }
////        probCache[0][0] = 1;
////
////        FOR(i, numOfSongs){
////            FOR(j, numOfSongs){
////                cin >> probMatrix[i][j];
////            }
////        }
////        dp(k);
////        while(likes--){
////            int song;
////            cin >> song;
////            double ret=0;
////            FOR(l, lengthOfSongs[song]){
////                ret+= probCache[(k-l)%5][song];
////            }
////            cout.precision(9);
////            cout << ret << " ";
////        }
////        cout << endl;
////    }
////
////    return 0;
////}
//
