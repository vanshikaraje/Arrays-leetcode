#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2, 4, 1, 9, 7, 5};
    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int x : arr) {
        if (x > largest)
            secondLargest = largest, largest = x;
        else if (x > secondLargest && x != largest)
            secondLargest = x;
    }

    cout << largest << " " << secondLargest;
}
