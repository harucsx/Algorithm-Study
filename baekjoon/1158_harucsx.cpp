#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    vector<int> v;

    int N, M;
    cin >> N >> M;

    v.reserve(N);

    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }


    while (!q.empty()) {
        for (int i = 0; i < M - 1; ++i) {
            int n = q.front();
            q.push(n);
            q.pop();
        }
        int n = q.front();
        v.push_back(n);
        q.pop();
    }

    cout << "<";
    for (int i = 0; i < N; ++i) {
        if (i == N - 1) {
            cout << v[i];
        } else {
            cout << v[i] << ", ";
        }
    }
    cout << ">";

    return 0;
}