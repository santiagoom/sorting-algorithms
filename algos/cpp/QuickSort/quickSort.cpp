#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    void quickSort(vector<int> &nums) {
        helper(nums, 0, nums.size() - 1);
    }
    void helper(vector<int> &nums, int start, int end) {
        if (start < end) {
            int base = nums[start];
            int i = start;
            int j = end + 1;

            while (true) {
                while (i < end && nums[++i] <= base);
                while (j > start && nums[--j] >= base);
                if (i < j) {
                    swap(nums, i, j);
                } else {
                    break;
                }
            }
            swap(nums, start, j);
            helper(nums, start, j - 1);
            helper(nums, j + 1, end);
        }
    }

    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{40, 70, 50, 30, 35, 80, 65, 55, 60, 45};
    print_1d_vector(nums);
    so->quickSort(nums);
    print_1d_vector(nums);
    delete so;
    return 0;
}
