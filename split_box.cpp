#include <cstdlib>  // 包含atoi函数
#include <iostream> // 包含C++的输入输出库
#include <map>
using namespace std;
typedef long long ll;
const int N = 10000;
const int MAXX = 1e6 + 5;
map<int, ll> diff;
struct xz{
     int x1,y1,x2,y2;
}a[N];


void hs(map<int, ll>& diff, xz input_shap){
    for(long long i=input_shap.x1;i<input_shap.x2;i++){
        int height = input_shap.y2-input_shap.y1;
        // cout<<"i="<<i<<" diff[i]="<<diff[i] << " size="<<diff.size()<<endl;
        diff[i]+=height;
        // cout<<"i="<<i<<" diff[i]="<<diff[i] << " size="<<diff.size()<<endl;
    }
}
 

int main() {
    freopen("./input_data/number.in","r",stdin);
    long long n,h=0;
    cout<<"input n"<<endl;
    cin>>n;
    cout<<"input n="<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<"input a["<<i<<"]"<<endl;
        cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
        int mj = (a[i].x2-a[i].x1)*(a[i].y2-a[i].y1);
        h=h+mj;
        cout<<"mj="<<mj<<endl;
        hs(diff, a[i]);
    }

    cout<<diff.size()<<endl;
    cout<<"total_area="<<h<<endl;
    
    int sum =0;
    ll old_gap = 999999999;
    int sum_mj =0;
    int best_d = 0;
    map<int, ll>::iterator it;
    for (it = diff.begin(); it != diff.end(); ++it) {
        cout<<"key="<<it->first<<" value="<<it->second<<endl;
        sum_mj+=it->second;
        ll new_gap = 2*sum_mj-h;
        if(new_gap<=old_gap && new_gap>=0){
            best_d = it->first;
            cout<<"old_gap="<<old_gap<<" new_gap="<<new_gap<<" best_d="<<best_d<< " sum_mj="<<sum_mj<<" total_area="<<h<<endl;
            old_gap = new_gap;

        }else{
            cout<<"final old_gap="<<old_gap<<" new_gap="<<new_gap<<" best_d="<<best_d<< " sum_mj="<<sum_mj<<"current_pos="<<it->first<<endl;
            // break;
        }
        // cout << "Key: " << it->first << ", Value: " << it->second << " sum="<<sum<< endl;
        sum+=it->second;
    }
    cout<<"best_d="<<best_d+1<<endl;
    return 0;

}
