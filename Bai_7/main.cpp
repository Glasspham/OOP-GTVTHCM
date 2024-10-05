#include"Header.h"
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, W;
    vector<pair<int, int>> items;
    vector<vector<int>>dp;
    enter(n, W, items);
    solution(n, W, items);
    return 0;
}