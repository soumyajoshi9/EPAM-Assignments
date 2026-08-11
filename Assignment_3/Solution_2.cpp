//Time Complexity:O(N)
// O(N) (input)+O(N) (DP fill)=O(N)
// Space Complexity:O(N)
#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &points){

    vector<int> dp(n,0);

    dp[0] = points[0];
    dp[1] = max(points[0], points[1]);

    for (int i = 2; i < n; i++){
        int include = dp[i-2] + points[i];
        int exclude = dp[i-1] + 0;
        dp[i] = max(include, exclude);
    }

    return dp[n-1];


}

int main(){
    
    int n;
    cin >> n;

    vector<int> points;
  
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        points.push_back(a);
    }

    int ans = solve(n, points);

    cout << ans << endl;
    
    return 0;
}
