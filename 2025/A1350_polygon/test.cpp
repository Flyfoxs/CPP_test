#include <bits/stdc++.h>
using namespace std;

int maxNonOverlapping(vector<int>& nums, int target) {
    unordered_set<long long> seen;
    seen.insert(0);
    long long prefix = 0;
    int count = 0;
    for (int x : nums) {
        prefix += x;
        int is_target = seen.count(prefix - target);
        // cout<<"is_target="<<is_target<<" x="<<x<<" count="<<count<<" prefix="<<prefix<<" target="<<target<<" seen.count(prefix - target)="<<seen.count(prefix - target)<<endl;
        if (is_target) {
            count++;
            seen.clear();
            seen.insert(0);
            prefix = 0;
        }

        seen.insert(prefix);
    }
    cout<<"count="<<count<<endl;
    return count;
}

int main() {
    // vector<int> nums = {2, 1, 1, 1, 2};
    // vector<int> nums = {1, 1, 1, 4, 2, 1};
    vector<int> nums = {2,1,4,1};
    int target = 3;
    cout << maxNonOverlapping(nums, target) << endl;  // 输出 2
}