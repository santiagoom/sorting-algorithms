# include <iostream>
# include <vector>
# include <cppUtils.h>

using namespace std;

class Solution {
public:
    void bubbleSort(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            bool isSwap = false;
            for (int j = 1; j < nums.size() - i; ++j) {
                if (nums[j - 1] > nums[j]) {
                    swap(nums[j - 1], nums[j]);
                    isSwap = true;
                }
            }
            if (!isSwap)
                break;
        }
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{40, 70, 50, 30, 35, 80, 65, 55, 60, 45};
    CppUtils::print_1d_vector(nums);
    so->bubbleSort(nums);
    CppUtils::print_1d_vector(nums);
    cout << "new file!" << endl;
    delete so;
    return 0;
}
