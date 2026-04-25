#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    long long s;
    cin>>n>>s;

    vector<long long> xu(n);
    for(int i=0;i<n;i++){
        cin>>xu[i];
    }

    vector<long long> prefix(n+1,0);
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+xu[i];
    }
    for(int i=0;i<n;i++){
        int left=0,right=(n-i)/2;
        int max_k=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(mid==0){
                left=mid+1;
                continue;
            }
            int end1=i+mid-1;
            int end2=i+2*mid-1;
            if(end2>=n){
                right=mid-1;
                continue;
            }
            long long sum1=prefix[end1+1]-prefix[i];
            long long sum2=prefix[end2+1]-prefix[end1+1];

            if(sum1<=s && sum2<=s){
                max_k=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        cout<<2*max_k<<endl;
    }
    return 0;
}