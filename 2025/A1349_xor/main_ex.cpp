#include <bits/stdc++.h>
using namespace std;

int cal(vector<long long>& nums, int target) {
    unordered_set<long long> seen;
    seen.insert(0);
    long long prefix = 0;
    int count = 0;
    for (long long x : nums) {
        prefix ^= x;
        if (seen.count(prefix ^ target)) {
            count++;
            seen.clear();
            seen.insert(0);
            prefix = 0;
        }
        seen.insert(prefix);
    }
    cout<<count<<endl;
    return count;
}

 
int main()
{
    // vector<long long> temp = {2, 1, 2, 2, 2, 1};

    // cal(temp, 2);

    // return 0;

    // xor
    freopen("input.in", "r", stdin);
    // freopen("xor.out", "w", stdout);
    int n;
    cin >> n;

    long long target;
    cin>>target;
    vector<long long> a(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cal(a, target);
    cout<<endl;
    return 0;
}



/**
 g++-14 -o main.out main_ex.cpp && ./main.out
 */