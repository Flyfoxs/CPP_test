#include <bits/stdc++.h>
using namespace std;

long long sum_mat(vector<vector<long long>> &mat, int left, int right)
{
    long long sum = 0;
    for (int i = left; i <= right; i++)
    {
        sum += mat[i][i];
    }
    // cout<<"left="<<left<<" right="<<right<<" sum="<<sum<<endl;
    return sum;
}

long long cal(vector<vector<long long>> &mat, int left, int right)
{

    if(left == right){
        return 0;
    }

    int size = mat.size();
    long long min_score = 0;
    long long sum_mat_value = sum_mat(mat, left, right);
    // cout<<"left="<<left<<" right="<<right<<" sum_mat_value="<<sum_mat_value<<endl;
    if(mat[left][right] > 0){
        // cout<<"return mat[left][right]="<<mat[left][right]<<endl;
        return mat[left][right];
    }

    if (left + 1 == right){
        min_score = sum_mat_value;
    } else {   
        // cout<<"else left="<<left<<" right="<<right<<" sum_mat_value="<<sum_mat_value<<endl;
        min_score = 999999999;
        for (int k = left; k < right; k++){
            long long left_score = cal(mat, left, k);
            long long right_score = cal(mat, k + 1, right);
            min_score = min(min_score, left_score + right_score + sum_mat_value);
            // cout<<"left="<<left<<" right="<<right<<" k="<<k<<" left_score="<<left_score<<" right_score="<<right_score<< " sum_mat_value="<<sum_mat_value<< " min_score="<<min_score<<endl;
        }
    }

    mat[left][right] = min_score;

    return min_score;
}

int main()
{
    freopen("input.in", "r", stdin);
    int n;
    cin >> n;
    vector<vector<long long>> mat(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i][i];
    }



    cout << cal(mat, 0, n - 1) << endl;

    //     for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
