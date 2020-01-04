#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
//    注意空位是j+1
public:
//    bug without swap
//    void insertSort(vector<int> &nums) {
//        for (int i = 1; i < nums.size(); i++) {
//            int key = nums[i];
//            int j = i - 1;
//            while (j >= 0 && key < nums[j]) {
//                swap(nums, j, j + 1);
//                j = j - 1;
//            }
//            swap(nums, i, j + 1);
//        }
//    }
    void insertSort(vector<int> &nums) {
        for (int i = 1; i < nums.size(); i++) {
            int key = nums[i];
            int j = i - 1;
            while (j >= 0 && key < nums[j]) {
                nums[j + 1] = nums[j];
                j = j - 1;
            }
            nums[j + 1] = key;
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
//2019-12-31-2 18:15:48
//2019-12-31-2 18:32:38
    auto *so = new Solution();
    vector<int> nums{40, 70, 50, 30, 35, 80, 65, 55, 60, 45};
    print_1d_vector(nums);
    so->insertSort(nums);
    print_1d_vector(nums);
    cout << "new file!" << endl;
    delete so;
    return 0;
}
