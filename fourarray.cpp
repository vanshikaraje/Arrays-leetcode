#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0; // No elements

    int i = 0; // Pointer for unique elements

    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) { 
            i++;              // Move to next position
            nums[i] = nums[j]; // Place unique element here
        }
    }
    return i + 1; // Count of unique elements
}

int main() {
    // Example input
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int k = removeDuplicates(nums);

    cout << "Unique count (k) = " << k << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
