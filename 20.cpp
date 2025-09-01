#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElementNBy3(vector<int>& nums){
    int n = nums.size();
    int count1 = 0;
    int count2 = 0;
    int ele1 = 0;
    int ele2 = 0;
     for(int i = 0;i<n;i++){
        if(nums[i]==ele1){
            count1++;
        }
        else if(nums[i]==ele2){
            count2++;
        }
        else if(count1==0){
            ele1=nums[i];
            count1 = 1;
        }
        else if(count2==0){
            ele2=nums[i];
            count2=1;
        }else{
            count1--;
            count2--;
        }
     }
     count1 = 0;
     count2 = 0;
     for(int i  = 0;i<n;i++){
        if(nums[i]==ele1)count1++;
         else if(nums[i]==ele2)count2++;
     }
     vector<int>result;
     if(count1>n/3)result.push_back(ele1);
     if(count2>n/3)result.push_back(ele2);
     return result;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i= 0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>ans =  majorityElementNBy3(nums);
    if(!ans.empty()){
        for(int i = 0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"No majority element"<<endl;
    }
    return 0;
}