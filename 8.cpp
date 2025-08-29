#include<bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums){
    int maxi = 0;
    int count = 0;
    for(int i = 0; i<nums.size();i++){
        if(nums[i]==1){
            count++;
        maxi = max(maxi,count);
        }
        else{
            count = 0;
        }
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans = findMaxConsecutiveOnes(nums);
    cout<<ans<<endl;

return 0 ;
}