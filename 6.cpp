#include<bits/stdc++.h>
using namespace std;
void moveZeroesIndex(vector<int>& nums){
    int lastZeroIndex = 0;
    for(int i = 0;i<nums.size();i++){
        if(nums[i]!= 0){
            nums[lastZeroIndex] = nums[i];
            lastZeroIndex++;
        }
    }
    for(int i = lastZeroIndex;i<nums.size();i++){
        nums[i]=0;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    moveZeroesIndex(nums);
    for(int i = 0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0 ;
}