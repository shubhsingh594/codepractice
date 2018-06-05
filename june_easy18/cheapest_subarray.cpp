#include<bits/stdc++.h>
using namespace std;

int arr[100000];
long long  MAX = 100000000000; 
int main(){
    int t;
    cin>>t;
    int test;
    int n;int i;
    for (test=0;test<t;test++){
        cin>>n;
        for (i=0;i<n;i++){
            cin>>arr[i];
        }
        long long result = MAX;
        for(i=0;i<n-1;i++)
        {
            result = min(result,(long long )arr[i]+(long long)arr[i+1]);
        }
        cout <<result<<"\n";
    }

}