#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    void quickSort(vector<int> &nums) {
        quickSortUtil(nums, 0, nums.size() - 1);
    }

private:
    void quickSortUtil(vector<int> &nums, int start, int end) {
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
            quickSortUtil(nums, start, j - 1);
            quickSortUtil(nums, j + 1, end);
        }
    }

    void swap(vector<int> &nums, int a, int b) {
        int t = nums[a];
        nums[a] = nums[b];
        nums[b] = t;
    }
};

int main() {
//    2019-12-29-0 10:17:48
    auto *so = new Solution();
    vector<int> nums{40, 70, 50, 30, 35, 80, 65, 55, 60, 45};
    print_1d_vector(nums);
    so->quickSort(nums);
    print_1d_vector(nums);
    cout << "new file!" << endl;
    delete so;
    return 0;
}
