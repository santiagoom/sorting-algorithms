# include <iostream>
# include <vector>
# include <cppUtils.h>

using namespace std;

class Solution {
public:
    void mergeSort(vector<int> &nums, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }

private:
    void merge(vector<int> &nums, int start, int mid, int end) {
        vector<int> tempVec(nums.size(), 0);
        int right = mid + 1;
        int third = start;
        int temp = start;
        while (start <= mid && right <= end) {
            if (nums[start] <= nums[right]) {
                tempVec[third++] = nums[start++];
            } else {
                tempVec[third++] = nums[right++];
            }
        }
        while (right <= end) {
            tempVec[third++] = nums[right++];
        }
        while (start <= mid) {
            tempVec[third++] = nums[start++];
        }
        while (temp <= end) {
            nums[temp] = tempVec[temp];
            temp++;
        }
    }
};

int main() {
//    2019-12-31-2 20:02:48
    auto *so = new Solution();
    vector<int> nums{40, 70, 50, 30, 35, 80, 65, 55, 60, 45};
    CppUtils::print_1d_vector(nums);
    so->mergeSort(nums, 0, nums.size() - 1);
    CppUtils::print_1d_vector(nums);
    delete so;
    return 0;
}
