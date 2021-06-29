#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    void selectSort(vector<int> &array) {
        for (int i = 0; i < array.size(); ++i) {
            int minIndex = i;
            for (int j = i + 1; j < array.size(); ++j) {
                if (array[minIndex] > array[j]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(array[i], array[minIndex]);
            }
        }
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{40, 70, 50, 30, 35, 80, 65, 55, 60, 45};
    CppUtils::print_1d_vector(nums);
    so->selectSort(nums);
    CppUtils::print_1d_vector(nums);
    cout << "new file!" << endl;
    delete so;
    return 0;
}
