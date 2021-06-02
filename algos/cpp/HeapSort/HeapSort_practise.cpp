# include <iostream>
# include <vector>
# include <cppUtils.h>

using namespace std;

class Solution {
public:
    void heapSort(vector<int> &nums, int size) {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(nums, size, i);
        }

        for (int i = 1; i < size; i++) {
            swap(nums, 0, size - i);
            heapify(nums, size - i, 0);
        }
    }

private:
//    注意跳出条件 left < length && nums[left] > nums[largest]
    void heapify(vector<int> &nums, int length, int pos) {
        int largest = pos;
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;

        if (left < length && nums[left] > nums[largest])
            largest = left;
        if (right < length && nums[right] > nums[largest])
            largest = right;

        if (largest != pos) {
            swap(nums, pos, largest);
            heapify(nums, length, largest);
        }
    }

    void swap(vector<int> &nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};

int main() {
//    2019-12-31-2 20:51:37
//2019-12-31-2 21:08:12
    auto *so = new Solution();
    vector<int> nums{40, 70, 50, 30, 35, 80, 65, 55, 60, 45};
    CppUtils::print_1d_vector(nums);
    so->heapSort(nums, nums.size());
    CppUtils::print_1d_vector(nums);
    cout << "new file!" << endl;
    delete so;
    return 0;
}
