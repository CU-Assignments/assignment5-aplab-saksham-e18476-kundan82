#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right]; // Choose last element as pivot
        int i = left;
        for (int j = left; j < right; j++) {
            if (nums[j] >= pivot) { // Sort in descending order
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        int pivotIndex = partition(nums, left, right);
        if (pivotIndex == k)
            return nums[pivotIndex];
        else if (pivotIndex < k)
            return quickSelect(nums, pivotIndex + 1, right, k);
        else
            return quickSelect(nums, left, pivotIndex - 1, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k - 1);
    }
};

// Main function (only one allowed)
int argc() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "Output 1: " << sol.findKthLargest(nums1, k1) << endl;

    // Example 2
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "Output 2: " << sol.findKthLargest(nums2, k2) << endl;

    return 0;
}
