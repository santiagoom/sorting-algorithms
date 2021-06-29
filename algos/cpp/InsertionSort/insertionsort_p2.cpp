#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    void insertSort(vector<int> &array) {
        for (int i = 1; i < array.size(); ++i) {
            int key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{40, 70, 50, 30, 35, 80, 65, 55, 60, 45};
    CppUtils::print_1d_vector(nums);
    so->insertSort(nums);
    CppUtils::print_1d_vector(nums);
    cout << "new file!" << endl;
    delete so;
    return 0;
}
