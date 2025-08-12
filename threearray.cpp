#include <iostream>
#include <vector>
using namespace std;

bool checkSortedAndRotated(vector<int>& nums) {
    int countBreaks = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        // Compare current element with next one (circular using %n)
        if (nums[i] > nums[(i + 1) % n]) {
            countBreaks++;
        }
        if (countBreaks > 1) return false; // More than 1 break = not sorted & rotated
    }
    return true;
}

int main() {
    // Example input
    vector<int> nums = {3, 4, 5, 1, 2};

    if (checkSortedAndRotated(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
