#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>&nums){
    int count  = 0;
    int ele = 0;
    for(int  i = 0;i<nums.size();i++){
        if(count == 0){
            ele = nums[i];
            count = 1;
        }
        else if(nums[i] == ele){
            count++;
        }
        else {
            count --;
        }
    }
    return ele;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    int ans = majorityElement(nums);
    cout<<ans<<endl;
    return 0;
}
