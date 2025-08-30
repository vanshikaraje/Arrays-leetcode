#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums){
    int xorr = 0;
    for(int i = 0;i<nums.size();i++){
        xorr = xorr ^ nums[i];
    }
    return xorr;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    int ans = singleNumber(nums);
    cout<< ans <<endl;
    return 0;
}