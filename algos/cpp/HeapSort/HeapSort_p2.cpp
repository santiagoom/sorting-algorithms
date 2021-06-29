# include <iostream>
# include <vector>
# include <cppUtils.h>

using namespace std;

class Solution {
public:
    void heapSort(vector<int> &array, int size) {
        for (int i = size / 2 - 1; i >= 0; --i) {
            heapify(array, size, i);
        }
        for (int i = 1; i < size; ++i) {
            swap(array[0], array[size - i]);
            heapify(array, size - i, 0);
        }
    }

private:
    void heapify(vector<int> &array, int size, int pos) {
        int largest = pos;
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;
        if (left < size && array[left] > array[largest])
            largest = left;
        if (right < size && array[right] > array[largest])
            largest = right;
        if (largest != pos) {
            swap(array[largest], array[pos]);
            heapify(array, size, largest);
        }
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{40, 70, 50, 30, 35, 80, 65, 55, 60, 45};
    CppUtils::print_1d_vector(nums);
    so->heapSort(nums, nums.size());
    CppUtils::print_1d_vector(nums);
    cout << "new file!" << endl;
    delete so;
    return 0;
}
