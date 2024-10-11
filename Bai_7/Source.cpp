#include"Header.h"

void enter(int &n, int &W, vector<pair<int,int>> &items) {
    cin >> n >> W;
    items.resize(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> items[i].first >> items[i].second;
}

void trace_back(int n, int W, vector<vector<int>> &dp, vector<pair<int,int>> &items) {
    vector<int> result;
    int i = n, j = W;
    while(i) {
        if(dp[i][j] != dp[i - 1][j]) {
            result.push_back(i);
            j -= items[i].first;
        }
        --i;
    }
    for(int i = result.size() - 1; i >= 0; --i)
        cout << result[i] << ' ';
}

void solution(int n, int W, vector<pair<int,int>> &items) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j];
            if(j >= items[i].first)
                dp[i][j] = max(items[i].second + dp[i - 1][j - items[i].first], dp[i][j]);
        }
    }
    cout << dp[n][W] << endl;
    trace_back(n, W, dp, items);
}