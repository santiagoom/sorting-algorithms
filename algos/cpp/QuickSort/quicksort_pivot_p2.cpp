#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    void quickSort(vector<int> &arr, int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }

private:
    int partition(vector<int> &array, int low, int high) {
        int key = array[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; ++j) {
            if (array[j] < key) {
                i++;
                swap(array[i], array[j]);
            }
        }
        swap(array[i + 1], array[high]);
        return i + 1;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{40, 70, 50, 30, 35, 80, 65, 55, 60, 45};
    CppUtils::print_1d_vector(nums);
    so->quickSort(nums, 0, nums.size() - 1);
    CppUtils::print_1d_vector(nums);
    cout << "new file!" << endl;
    delete so;
    return 0;
}
