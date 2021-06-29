# include <iostream>
# include <vector>
# include <cppUtils.h>

using namespace std;

class Solution {
public:
    void mergeSort(vector<int> &array, int start, int end) {
        if (start < end) {
            int middle = (start + end) / 2;
            mergeSort(array, start, middle);
            mergeSort(array, middle + 1, end);
            merge(array, start, end, middle);
        }
    }

private:
    void merge(vector<int> &array, int start, int end, int middle) {
        vector<int> tempVec(array.size(), 0);
        int right = middle + 1;
        int third = start;
        int temp = start;
        while (start <= middle && right <= end) {
            if (array[start] < array[right])
                tempVec[third++] = array[start++];
            else {
                tempVec[third++] = array[right++];
            }
        }
        while (start <= middle)
            tempVec[third++] = array[start++];

        while (right <= end)
            tempVec[third++] = array[right++];

        while (temp <= end) {
            array[temp] = tempVec[temp];
            temp++;
        }
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{40, 70, 50, 30, 35, 80, 65, 55, 60, 45};
    CppUtils::print_1d_vector(nums);
    so->mergeSort(nums, 0, nums.size() - 1);
    CppUtils::print_1d_vector(nums);
    delete so;
    return 0;
}
