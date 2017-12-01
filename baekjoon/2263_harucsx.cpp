#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

int N;
int tree[100011][2];
int find_index[100001];
vector<int> in, po;

void trav(int in_start, int in_end, int po_start, int po_end) {
    if (in_start > in_end || po_start > po_end) return;
    int root = po[po_end];
    int left = -1, right = -1;
    int sep_index = find_index[root];
    int left_count = sep_index - in_start;

    if (sep_index > in_start) {
        left = po[po_start + left_count - 1];
        tree[root][0] = left;
    }

    if (sep_index < in_end) {
        right = po[po_end - 1];
        tree[root][1] = right;
    }

    if (left > 0)
        trav(in_start, sep_index - 1, po_start, po_start + left_count - 1);
    if (right > 0)
        trav(sep_index + 1, in_end, po_start + left_count, po_end - 1);
}

void preorder(int n){
    if (n > N || n <= 0) return;

    printf("%d ", n);
    preorder(tree[n][0]);
    preorder(tree[n][1]);
}

int main() {
#ifdef HARUCSX_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N;
    in.resize(N + 1);
    po.resize(N + 1);

    for (int i = 1; i <= N; ++i)
        scanf("%d", &in[i]);

    for (int i = 1; i <= N; ++i)
        scanf("%d", &po[i]);

    for (int i = 1; i <= N; ++i)
        find_index[in[i]] = i;


    trav(1, N, 1, N);
    preorder(po[N]);

    return 0;
}
