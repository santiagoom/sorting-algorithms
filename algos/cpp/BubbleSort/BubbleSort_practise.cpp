#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    void bubbleSort(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            bool flag = true;
            for (int j = 1; j < nums.size() - i; j++) {
                if (nums[j - 1] > nums[j]) {
                    swap(nums, j - 1, j);
                    flag = false;
                }
            }
            if (flag)
                break;
        }
    }

private:
    void swap(vector<int> &nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

};

int main() {
//    2019-12-31-2 17:19:30
//2019-12-31-2 17:26:37
    auto *so = new Solution();
    vector<int> nums{40, 70, 50, 30, 35, 80, 65, 55, 60, 45};
    print_1d_vector(nums);
    so->bubbleSort(nums);
    print_1d_vector(nums);
    cout << "new file!" << endl;
    delete so;
    return 0;
}
