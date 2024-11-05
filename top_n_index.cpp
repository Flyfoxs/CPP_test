#include <iostream>
using namespace std;

struct zdzx {
  int zd, zd1, zd2, zx, zx1, zx2;
};


zdzx gzdzx(int a[],int b[], int n) {

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j + 1] > a[j]) {
        int t = a[j];
        a[j] = a[j + 1];
        a[j + 1] = t;


        int t2 = b[j];
        b[j] = b[j + 1];
        b[j + 1] = t2;
      }
    }
  }
  zdzx xx;
  xx.zd = a[0];
  xx.zd1 = a[1];
  xx.zd2 = a[2];
  xx.zx = a[n - 1];
  xx.zx1 = a[n - 2];
  xx.zx2 = a[n - 3];
  return xx;
}

void print_order(int a[3]){
  for(int i=0;i<3;i++){
    for(int j=0;j<3-i-1;j++){
      if(a[j+1]<a[j]){
        int t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
      }
    }
  }

  for(int i=0;i<3;i++){
    cout<<a[i]<<" ";
  }
}

int main() {
  int n = 8;
  //    cin>>n;
  int b[n];

  for (int i = 0; i < n; i++) {
    b[i] = i+1;
  }

  int a[8] = {1, 8, 6, 4, 7, 2, 3, 5};


  zdzx s = gzdzx(a, b, n);

  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  for(int i=0;i<n;i++){
    cout<<b[i]<<" ";
  }
  cout << endl;
  
  int c[3] = {b[0], b[1], b[2]};
  print_order(c);

  cout << endl;

  int d[3] = {b[n-3], b[n-2], b[n-1]};
  print_order(d);

  cout << endl;
  return 0;
}