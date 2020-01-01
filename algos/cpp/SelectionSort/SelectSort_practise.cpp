#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    void selectSort(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            int minIndex = i;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[minIndex])
                    minIndex = j;
            }
            if (minIndex != i) {
                swap(nums, minIndex, i);
            }
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
//2019-12-31-2 17:35:59
//2019-12-31-2 17:52:15
    auto *so = new Solution();
    vector<int> nums{40, 70, 50, 30, 35, 80, 65, 55, 60, 45};
    print_1d_vector(nums);
    so->selectSort(nums);
    print_1d_vector(nums);
    cout << "new file!" << endl;
    delete so;
    return 0;
}
