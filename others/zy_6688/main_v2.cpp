#include<bits/stdc++.h>
// 6688. 剪格子
using namespace std;
int a[10][10], he;
int m, n, ans =1000;
bool visited[10][10];
int dir[4][2] = {{-1, 0}, {0,-1}, {1,0}, {0,1}};

vector<pair<int, int>> pos_list;

void print_pos_list(int sum){
    cout<<"size="<<pos_list.size();

    for(int i=0;i<pos_list.size();i++){
        printf(" (%d,%d)", pos_list[i].first, pos_list[i].second);
    }
    cout<<" sum="<<sum<<endl;
    cout<<endl;
}


void dfs(int x, int y, int sum, int cnt){
    if(sum > he/2){
        return;
    }

    if(sum == he/2){
        if(visited[0][0]==1){

            ans = min(ans, cnt);
        }else{
            ans = min(ans, m*n-cnt);
        }
        return;
    }
    

    for(int i=0; i<4; i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny]){
            visited[nx][ny] = true;
            pos_list.push_back(make_pair(nx, ny));
            // print_pos_list(sum+a[nx][ny]);
            dfs(nx, ny, sum+a[nx][ny], cnt+1);
            pos_list.pop_back();
            visited[nx][ny] = false;
        }
    }
    return;
}

int main(){
    freopen("input.in", "r", stdin);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            he += a[i][j];
        }
    }


    if(he % 2 ==1){
        cout<<0<<endl;
    }else{

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                memset(visited, false, sizeof(visited));
                visited[i][j] = true;
                pos_list.clear();
                pos_list.push_back(make_pair(i, j));
                dfs(i, j, a[i][j], 1);
                if(ans != 1000) break;
             }
             if(ans != 1000) break; 
        }
        if(ans != 1000) cout<<ans<<endl;
        else cout<<0<<endl;
    }  
    return 0;
}

/**
g++-14 -o main.out main_v2.cpp && ./main.out
 */