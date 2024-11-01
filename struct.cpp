#include <iostream> // 包含C++的输入输出库
#include <cstdlib>  // 包含atoi函数
using namespace std;

struct MaxMin{
    int max;
    int min;
};


MaxMin getMaxMin(int a[], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n-i-1; j++){

            if (a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }

        }
    }

    MaxMin maxMin;
    maxMin.max = a[n-1];
    maxMin.min = a[0];
    return maxMin;
}


int main(){
    int a[] = {12,2,3,4,5,6,7,8,9,10};
    MaxMin maxMin = getMaxMin(a, 10);
    cout << maxMin.max << " " << maxMin.min << endl;
}