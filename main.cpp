#include <iostream> // 包含C++的输入输出库
#include <cstdlib>  // 包含atoi函数
using namespace std;


int main(){
    const int  c=4;
    const int  k=4;
    int xx=10;
    const int default_value = -1;

    int a[c][k];
    for(int i=0; i<c; i++)
        for (int j=0; j<k; j++)
            a[i][j]=default_value;


    int n = c*k;
    int i=0;
    int j=0;
    int d=0;
    for(int num=1; num<=n; num++){
        if (a[i][j] == default_value)
            a[i][j]=num;

        int change;
        if (d%4 == 0 && (a[i][j+1] > default_value || j==k-1)){
            cout<<i <<" " << j << " " << num << " " << d << " change0->1"<< endl;
            change = true;
        }else if(d%4 == 1 && (a[i+1][j] > default_value || i == c-1)){
            cout<<i <<" " << j << " " << num << " " << d << " change1->2"<< endl;
            change = true;
        }else if(d%4 == 2 &&  (a[i][j-1] > default_value || j==0)){
            cout<<i <<" " << j << " " << num << " " << d << " change2->3"<< endl;
            change = true;
        }else if(d%4 == 3 && (a[i-1][j] > default_value || i==0)) {
            cout<<i <<" " << j << " " << num << " " << d << " change3->0"<< endl;
            change = true;
        }else{
            cout<<i <<" " << j << " " << num << " " << d << " keep" << endl;
            change = false;
        }

        if(change)
            d++;

        if(d%4==0){
            j++;
        }else if(d%4==1){
            i++;
        }else if(d%4==2){
            j--;
        }else if(d%4==3){
            i--;
        }
    }

    for(int i1=0;i1<c;i1++){
        for(int j1=0;j1<k;j1++){
            cout<<a[i1][j1] << " ";
        }
        cout <<endl;
    }
    return 0;
}