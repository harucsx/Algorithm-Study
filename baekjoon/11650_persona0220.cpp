#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	int N;
	cin >> N;

	vector<pair<int, int> > xy;

	for(int i=0; i<N; i++){
		int a, b;
		cin >> a >> b;

		xy.push_back(pair<int, int> (a, b) );
	}

	sort(xy.begin(), xy.end());

	for(int i=0; i<N; i++){
		cout << xy[i].first << " " << xy[i].second << '\n';
	}
	return 0;
}
