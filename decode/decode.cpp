//5844：[CSP-J 2022] 解密（decode）
#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("decode.in","r",stdin);
	// freopen("decode.out","w",stdout);
	long long k;
	cin>>k;
	for(long long ttt=0;ttt<k;ttt++){
		long long n,d,e;
		cin>>n>>d>>e;
		bool f=0;
		long long m = n-e*d+2;
        long long min_p = m/2;
		// cout<<"min_p="<<min_p<<endl;
		for(long long p=1; p<=min_p && p<=sqrt(n); p++){
			 
				long long q = m-p;
 
//				cout<<p<<" "<<q<<" "<<p-1<<" "<<q-1<<" "<<e*d-1<<endl;
					if((p-1)*(q-1)==e*d-1){
						f=1;
						cout<<p<<" "<<q<<endl;
						break;
					}
		}
		if(f==0){
			cout<<"NO"<<endl;
		}
		
	}
	
	return 0;
}

// g++-14 -o main.out decode.cpp && ./main.out