#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>&nums){
    int n = nums.size();
    int pre = 1;
    int suff  =1;
    int ans = INT_MIN;
    for(int i = 0;i<n;i++){
        if(pre==0)pre =1;
        if(suff==0)suff =1;

        pre = pre*nums[i];
        suff = suff*nums[n-i-1];
        
        ans = max(ans,max(pre,suff));
    }
return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
        int result = maxProduct(nums);
        cout<<result<<endl;
    return 0;
}