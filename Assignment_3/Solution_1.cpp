//Time Complexity:O(N log N)
// O(N) (input)+O(NlogN) (sort)+O(N) (greedy scan)=O(N log N)
// Space Complexity:O(N)
#include<bits/stdc++.h>
using namespace std;

void distribution(int N, int B, vector<int> &stu){
    int count = 0;
    int max_stu = B;

    for (int i = 0; i < N; i++){
        if (max_stu >= stu[i]){
            count++;
            max_stu -= stu[i];
        }
    }
    cout<<count<<endl;
}

int main(){
    int N, B;

    cin >> N >> B;

    vector<int> stu;

    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        stu.push_back(a);
    }

    sort(stu.begin(), stu.end());

    distribution(N, B, stu);

    return 0;
}
