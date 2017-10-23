#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define FOR(var, ed) for(int var = 0 ; var < ed; var++)
using namespace std;

int tc, n, m;
vector<double> locations;
void input(){
    cin >> n >> m;
    locations.clear();
    locations.resize(m);
    FOR(i, m)
        cin >> locations[i];
}
// 결정문제
bool decision(const vector<double>& locations, int cameras, double max){
    double current = -1;
    FOR(i, locations.size()){
        if(current <= locations[i]){
            cameras --;
            current = locations[i]+max;
        }
        if(cameras == 0) return true;
    }
    return false;
}
// 최적화문제
double optimize(const vector<double>& locations, int cameras){
    double low = 0, high = 241;
    // *** decision(low) && !dicision(high)가 될 때 까지!!!!
    FOR(i, 100){
        double mid = (low+high)/2.0;
        //간격이 mid이상 되도록 할 수 있으면 답은 [mid, high]에 있다
        if(decision(locations, cameras, mid)) low = mid;
            //간격이 mid이상 되도록 할 수 없으면 답은 [low, mid]에 있다
        else high = mid;
    }
    return low;
}
int main(){
    cin >> tc;
    while(tc--){
        input();
        sort(locations.begin(), locations.end());
        cout << fixed << setprecision(2);
        cout << optimize(locations, n) << endl;

    }
}