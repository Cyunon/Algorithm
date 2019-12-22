#include<iostream>
using namespace std;

int n;
int x[100];
int sum=0;
void output(){
    cout << "第" << sum << "种放置方法为：";
    for(int i=1; i<=n; i++)
    {
       cout << "(" << i << "," << x[i] << "), ";
    }
    cout << endl;
}
int place(int k){
    for(int j=1;j<k;j++)
    {
        if(x[j]==x[k] || abs(x[j]-x[k])== abs(j-k))
           return 0;
    }
    return 1;
}
void BackTrace1(int n){
    int k;
    x[1]=0;
    k=1;
    while(k>=1){
        x[k]+=1;
        while((x[k]<=n && !(place(k)))){
             x[k]++;
        }
        if(x[k]<=n){
        if(k==n){
         sum++;
         output();
         }
        else{
            k++;
            x[k]=0;
        }
        }
        else{
            k--;
        }
    }
}
int main()
{
    cout << "请输入皇后个数：";
    cin >> n;
    cout << n << "皇后的放置方法为" << endl;
    BackTrace1(n);
    return 0;
}
