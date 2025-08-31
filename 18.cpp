#include <bits/stdc++.h>
using namespace std;

int subArraySum(vector<int>&nums,int k){
    int n=nums.size();
    int count = 0;

    for(int i = 0;i<n;i++){
        int sum = 0;
        for(int j = i ;j<n;j++){
            sum = sum +nums[j];
            if(sum == k){
                count++;
            }
        }
    }
    return count ;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    cout<<subArraySum(nums,k)<<endl;
    return 0 ;
}