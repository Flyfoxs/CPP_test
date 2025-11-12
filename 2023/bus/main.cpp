#include <bits/stdc++.h>
using namespace std;

struct road{
    int id;
    int from; //current station
    int to;
    int open_time;
    int go=0;
};

int n; //End station

int ans = -1;

map<int, vector<road>> road_list; //Road map

map<int, vector<int>> cost_map;

vector<int> used_road_id;

void dfs(int node_id, int time_cost) {
    // vector<int> dfs_result;
    // //cout<<"node_id="<<node_id<<", time_cost="<<time_cost<<endl;
    if(cost_map.count(node_id)){
        cost_map[node_id].push_back(time_cost);
    }else{
        // dfs_result.push_back(time_cost);
        // cost_map[node_id] = dfs_result;
        cost_map[node_id] = vector<int>{time_cost};
    }

    if(node_id == n){
        //cout<<"end, node_id="<<node_id<<", time_cost="<<time_cost<<endl;
        return;
    }
    

    vector<road> to_list = road_list[node_id];
    
    for(auto cur_road : to_list){
    // for(auto it = road_list[node_id].begin(); it != road_list[node_id].end(); it++){
        // int to = it->first;
        // node cur_road = it;
        //cout<<"hello"<<endl;
        int go_flag = used_road_id[cur_road.id];
        //cout<<"go_flag="<<go_flag<<endl;
        // //cout<<"go_flag="<<go_flag<<endl;
        //cout<<"node_id="<<node_id<<" from="<<cur_road.from<<" to="<<cur_road.to<<", open_time="<<cur_road.open_time<<endl;
        //cout<<"from="<<node_id<<" to="<<cur_road.to<<" time_cost="<<time_cost+1<<", open_time="<<cur_road.open_time<<" to size="<<  road_list[node_id].size()<<", go_flag="<<go_flag <<endl;
        if(time_cost>=cur_road.open_time && go_flag == 0){
            used_road_id[cur_road.id] = 1;
            dfs(cur_road.to, time_cost + 1);    
        }else{
            //cout<<"close, from="<<node_id<<" to="<<cur_road.to<<", time_cost="<<time_cost<<" open_time="<<cur_road.open_time<<" go_flag="<<go_flag<<endl;
        }
    }
    //cout<<"error, node_id="<<node_id<<", time_cost="<<time_cost<<endl;
    return ;
}


int main()
{
    // bus
    freopen("0_in.txt", "r", stdin); //74806409
    // freopen("output.out","w",stdout);

    // freopen("bus.in", "r", stdin); //74806409
    // freopen("bus.out","w",stdout);

    int m, k;
    cin >> n; //station cnt
    cin >> m; //road cnt
    cin >> k; //bus time gap
    //cout<<"n="<<n<<" m="<<m<<" k="<<k<<endl;
    for(int i=0;i<m;i++){
        road tmp;
        tmp.id = i;
        cin>>tmp.from;
        cin>>tmp.to;
        cin>>tmp.open_time;
        tmp.go = 0;

        if(road_list.count(tmp.from)){
            //cout<<"from="<<tmp.from<<" already exists"<<endl;
            road_list[tmp.from].push_back(tmp);
        }else{
            //cout<<"from="<<tmp.from<<" does not exist, create new list"<<endl;
            road_list[tmp.from] = vector<road>{tmp};
        }
    }


    // for(auto it = road_list.begin(); it != road_list.end(); it++){
    //     //cout<<"from="<<it->first<<endl;
    //     for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
    //         //cout<<"to="<<it2->first<<" open_time="<<it2->second.open_time<<" go="<<it2->second.go<<endl;
    //     }
    // }
    // return 0;

    //cout<<"road_list size="<<road_list.size()<<endl;
    for(auto it = road_list.begin(); it != road_list.end(); it++){
        //cout<<"from="<<it->first<<endl;
        for(int i=0;i<it->second.size();i++){
            //cout<<"to="<<it->second[i].to<<" open_time="<<it->second[i].open_time<<endl;
        }
    }

    for(int i=0;i<=24;i++){
        int start_time = i*k;
        if(start_time%k!=0){
            //cout<<"start_time="<<start_time<<" is not divisible by 3, continue"<<endl;
            continue;
        }
        cost_map.clear();
        used_road_id.clear();
        //cout<<"================" << start_time <<" i="<<i<<", ================"<<endl;

        used_road_id.resize(m, 0);
        used_road_id[0] = 1;
        dfs(1, start_time);

        vector<int> final_cost = cost_map[n];
        if(final_cost.size() == 0){
            //cout<<"no solution, start_time="<<start_time<<endl;
            continue;
        }
        
        for(int i=0;i<final_cost.size();i++){
            ans = final_cost[i];
            if(ans % k ==0){
                //cout<<"final_cost="<<ans<<" start_time="<<start_time<<" k="<<k<<endl;
                cout<<ans<<endl;

                return 0;
            }
        }
    }
    
    cout<<ans<<endl;
    return 0;
}



/**
 g++-14 -o main.out main.cpp && ./main.out

 74806409
 */