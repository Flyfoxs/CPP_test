#include <bits/stdc++.h>
using namespace std;
//3203：【AHOI2021初中】坑（hole）（2） #60分
//https://www.luogu.com.cn/problem/solution/P7622
const long long inf = 1e13;

struct rat{
    int          id;
    long long    a;
    long long    left_hole=-1*inf;
    long long    right_hole=inf;
};

vector<rat> rats;


bool check_done(long long left_step, long long right_step){
    for(int i=0;i<rats.size();i++){
        // printf("rats[i].left_hole=%lld rats[i].right_hole=%lld left_step=%lld right_step=%lld\n", rats[i].left_hole, rats[i].right_hole, left_step, right_step);

        if(rats[i].left_hole  <= left_step || rats[i].right_hole <= right_step){
            continue;
        } else{
            return false;
        }

    }
    // printf("true left_step=%lld right_step=%lld, rats.size()=%d\n", left_step, right_step, rats.size());
    return true;
}


int main() {
    freopen("hole.in", "r", stdin);
    // freopen("hole.out", "w", stdout);
    int n, m; //rats, holes
    cin >> n >> m;
    rats.resize(n);
    vector<long long> holes(m+2);


    for(int i=0;i<n;i++){
        rats[i].id = i + 1;
        cin >> rats[i].a ;
    }

    holes[0] = -inf;
    for(int i=1;i<m;i++){ //Holes
        cin>>holes[i];
    }
    holes[m+1] = inf;


    //rats
    sort(rats.begin(), rats.end(), [](rat a, rat b){
        return a.a < b.a;
    });

    //holes
    sort(holes.begin(), holes.end());

    // for(int i=0;i<m+2;i++){
    //     cout<<"holes["<<i<<"]="<<holes[i]<<endl;
    // }




    for(int j=0;j<rats.size();j++){
    

        for(int i=0;i<holes.size()-1;i++){
            // cout<<"3. rats[j].a="<<rats[j].a<< " holes[i]="<<holes[i]<<" holes[i+1]="<<holes[i+1]<<endl;
            if(rats[j].a == holes[i]){
                rats[j].left_hole = 0;
                rats[j].right_hole = 0;
                break;
            }


            if(holes[i]< rats[j].a && rats[j].a< holes[i+1]){
                rats[j].left_hole = rats[j].a - holes[i];
                rats[j].right_hole = holes[i+1] - rats[j].a;
                break;
            }


        }
    }

    // sort(rats.begin(), rats.end(), [](rat a, rat b){
    //     return a.id < b.id;
    // });
    // for(int i=0;i<rats.size();i++){
    //     printf("%15lld %15lld %4d \n", rats[i].left_hole, rats[i].right_hole, rats[i].id, rats[i].a);
    // }

 
    // for(int i=0;i<rats.size();i++){
    //    printf("a: %lld left:%lld right:%lld\n", rats[i].a, rats[i].left_hole, rats[i].right_hole);
    // }
    // cout<< check_done(3,1)<<endl;
    // return 0;

    // long long ans = 0;
    // for(int i=0;i<rats.size();i++){
    //     ans += min(rats[i].left_hole, rats[i].right_hole);
    // }
    // cout<<ans<<endl;

    // cout<< check_done(17601465,17601465)<<endl;
    long long min_step = inf;
    long long big_left_hole = -inf;
    long long big_right_hole = -inf;
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
         long long left_step = rats[i].left_hole;
         big_left_hole = max(big_left_hole, left_step);
         long long right_step = rats[j].right_hole;
         big_right_hole = max(big_right_hole, right_step);
        // cout<<"left_step="<<left_step<<" right_step="<<right_step << "id_i="<<rats[i].id<<" id_j="<<rats[j].id<<endl;
        if(check_done(left_step, right_step)){
            min_step = min(min_step, 2*left_step + right_step);
            min_step = min(min_step, left_step + 2*right_step);
            // printf("min_step=%lld left_step=%lld right_step=%lld\n", min_step, left_step, right_step);
        }
       }
    }

    //是不是走到头就可以了
    min_step = min(min_step, big_left_hole );
    min_step = min(min_step, big_right_hole );
    
    cout<<min_step<<endl;

    return 0;
}


/**
 g++-14 -o main.out main.cpp && ./main.out
 */