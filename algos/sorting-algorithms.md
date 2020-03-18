# sorting-algorithms

## BubbleSort

技巧，使用一个标志位检查一个回合有没有交换的，如果没有，则表明已完成排序，则可以退出！

```cpp
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
```



## SelectSort2

选择排序的改进技巧是，不用每次都交换较小的，而是记录全局最小的位置（index），然后都一轮都比较完成之后替换一次。

```cpp
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
```



## InsertSort

发现比前一个数小的话才需要插入，依次向后移动，可以二分插入。

线性插入n^2,二分插入nlogn

```cpp
class Solution {
//    注意空位是j+1
public:
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
```



## MergeSort

merge完成之后，定义临时index将排序完成之后的数据复制到原先的位置。

```cpp
class Solution {
public:
    void mergeSort(vector<int> &nums, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }

private:
    void merge(vector<int> &nums, int start, int mid, int end) {
        vector<int> tempVec(nums.size(), 0);
        int right = mid + 1;
        int third = start;
        int temp = start;
        while (start <= mid && right <= end) {
            if (nums[start] <= nums[right]) {
                tempVec[third++] = nums[start++];
            } else {
                tempVec[third++] = nums[right++];
            }
        }
        while (right <= end) {
            tempVec[third++] = nums[right++];
        }
        while (start <= mid) {
            tempVec[third++] = nums[start++];
        }
        while (temp <= end) {
            nums[temp] = tempVec[temp];
            temp++;
        }
    }
};
```



## heapSort

堆排序的最大索引值2i+2比其长度n小1，即2i+2<n；

```cpp
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
```



## quickSort

```cpp
class Solution {
public:
    void quickSort(vector<int> &nums) {
        quickSortUtil(nums, 0, nums.size() - 1);
    }

private:
    void quickSortUtil(vector<int> &nums, int start, int end) {
        if (start < end) {
            int base = nums[start];
            int i = start;
            int j = end + 1;
            while (true) {
                while (i < end && nums[++i] <= base);
                while (j > start && nums[--j] >= base);
                if (i < j) {
                    swap(nums, i, j);
                } else {
                    break;
                }
            }
            swap(nums, start, j);
            quickSortUtil(nums, start, j - 1);
            quickSortUtil(nums, j + 1, end);
        }
    }

    void swap(vector<int> &nums, int a, int b) {
        int t = nums[a];
        nums[a] = nums[b];
        nums[b] = t;
    }
};
```





# Stability in sorting algorithms

## heapSort

不稳定

```
     /   \
   23    30
  /  \
30    30
```

## SelectSort2

不稳定

```
10* 10 5

5 10 10*
```

## quickSort

两个线程

```
1 7 8 2 2 
```

一个线程

```
2 8 8 3
```

