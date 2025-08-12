#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &arr, int n) {
    int largest = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main() {
    vector<int> arr = {2, 4, 1, 9, 7, 5};
    cout << "Largest element: " << largestElement(arr, arr.size()) << endl;
    return 0;
}
