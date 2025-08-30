#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int,int>> arr;
    for (int i = 0; i < nums.size(); i++) {
        arr.push_back({nums[i], i});   // store value + index
    }

    sort(arr.begin(), arr.end());      // sort by value

    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = arr[left].first + arr[right].first;
        if (sum == target) {
            return {arr[left].second, arr[right].second}; // return original indices
        } 
        else if (sum < target) {
            left++;
        } 
        else {
            right--;
        }
    }
    return {};
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = twoSum(nums, target);
    if (!ans.empty()) {
        cout << ans[0] << " " << ans[1] << endl;
    } else {
        cout << "No solution" << endl;
    }
    return 0;
}
