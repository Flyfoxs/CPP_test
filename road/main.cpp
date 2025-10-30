#include<bits/stdc++.h>
using namespace std;
int n,d;
long long qzh[100010];//前缀和
int zd[100010];//站点
struct node{
	int v,a;//距离，价格  
	int jy_jl; //加油距离,
	bool is_jy;
	float sy_y; //剩余的油
	int next_zd; //下一个加油站
	int total_jl; //总距离
}va[100010];
int main(){
	freopen("road.in","r",stdin);
	// freopen("road.out","w",stdout);
	cin>>n>>d;
	// cin>>va[0].v;
	// qzh[0]=va[0].v;
	for(int i=0;i<=n-2;i++){
		cin>>va[i].v;
		cout<<"距离="<<va[i].v<<endl;
		// qzh[i]=qzh[i-1]+va[i].v;
	}//输入距离

	qzh[0]=0;
	va[0].total_jl=0;
	va[0].sy_y=0;
	for(int i=1; i<n; i++){
		qzh[i]=va[i-1].v+qzh[i-1];
		va[i].total_jl=qzh[i];
		va[i].sy_y=ceil(va[i].total_jl*1.0/d) - va[i].total_jl*1.0/d;
	}
	// qzh[n-1]=qzh[n-2]+va[n-2].v;
	for(int i=0;i<n;i++){
		cout<<"qzh["<<i<<"]="<<qzh[i]<<endl;
	}
//	cout<<endl;
	for(int i=0;i<n;i++){
		cin>>va[i].a;
		cout<<"加油站"<<i<<", 价格="<<va[i].a<<endl;
	}//输入价格
	// zd[0]=0;
	int tmp_1=0;
	int last_jg=999999999;
	for(int i=0;i<n;i++){
		if(va[i].a<last_jg){
		    last_jg=va[i].a;
			cout<<"加油站"<<i<<", 价格="<<last_jg<<endl;
			zd[tmp_1]=i;
			tmp_1++;
			va[i].is_jy=true;
		}else{
			va[i].is_jy=false;
		}
	}
	zd[tmp_1]=n-1;
	//打印加油站
	for(int i=0;i<=tmp_1;i++){
		va[i].next_zd=zd[i+1];
		int tmp_s=qzh[zd[i+1]]-qzh[zd[i]];//两点之间的距离
		va[zd[i]].jy_jl=tmp_s;
		cout << left << setw(10) << "qzh=" << setw(8) << qzh[i]
		     << setw(10) << "距离=" << setw(8) << tmp_s
		     << setw(6)  << "zd=" << setw(4) << zd[i]
		     << setw(12) << "next_zd=" << setw(6) << zd[i+1]
		     << setw(14) << "剩余的油=" << setw(10) << fixed << setprecision(4) << va[i].sy_y
		     << setw(14) << "下一站距离=" << setw(10) << va[i].jy_jl
		     << endl;
	}
//	cout<<endl;
	double sy_q=0;//剩余的油 
	int ans=0;
	for(int i=0;i<tmp_1;i++){
		
		int tmp_s=qzh[zd[i+1]]-qzh[zd[i]];//两点之间的距离
		
		double xy_y=tmp_s*1.0/d-sy_q;//需要用的油
		double jia_y = ceil(xy_y); //需要添加的油
	 
		ans=ans+jia_y*va[zd[i]].a; //钱
//		sy_q=ceil(xy_y)*d*1.0-tmp_s;
//		cout<<zd[i+1]<<" "<<zd[i]<<endl;
		sy_q = sy_q + jia_y - tmp_s*1.0/d;
		cout<<"i="<<i<<", 距离="<<tmp_s<<"， 需要的油="<<xy_y<<"， 钱"<<ans<<" 剩余的油"<<sy_q<<endl;
	}
	cout<<ans;
	return 0;
}


/**
 * 
4 6279
90560 55497 63624
171 103 126 112


4522

 */