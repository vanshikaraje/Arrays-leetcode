#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& nums){
    int missing = nums.size();
    for(int i = 0;i<nums.size();i++){
        missing = missing^i^nums[i];
    }
    return missing;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
   int ans = missingNumber (nums);
    
        cout<<ans<<" ";

    cout<<endl;
    return 0;
}