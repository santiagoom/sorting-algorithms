package sort;

import java.util.Arrays;

/**
 * 桶式排序
 *
 * @author shkstart
 * 2013-11-27
 */
public class BucketSort {
    public static void bucketSort(sort.DataWrap[] data, int min, int max) {
        System.out.println("开始排序");
        int arrayLength = data.length;
        sort.DataWrap[] temp = new sort.DataWrap[arrayLength];
        int[] buckets = new int[max - min];
        for (int i = 0; i < arrayLength; i++) {
            buckets[data[i].data - min]++;
        }
        System.out.println(Arrays.toString(buckets));
        for (int i = 1; i < max - min; i++) {
            buckets[i] = buckets[i] + buckets[i - 1];
        }
        System.out.println(Arrays.toString(buckets));
        System.arraycopy(data, 0, temp, 0, arrayLength);
        for (int k = arrayLength - 1; k >= 0; k--) {
            data[--buckets[temp[k].data - min]] = temp[k];
        }
    }

    public static void main(String[] args) {
        sort.DataWrap[] data = {new sort.DataWrap(9, ""), new sort.DataWrap(5, ""),
                new sort.DataWrap(-1, ""), new sort.DataWrap(8, ""),
                new sort.DataWrap(5, "*"), new sort.DataWrap(7, ""),
                new sort.DataWrap(3, ""), new sort.DataWrap(-3, ""),
                new sort.DataWrap(1, ""), new sort.DataWrap(3, "*")};
        System.out.println("排序之前：\n" + java.util.Arrays.toString(data));
        bucketSort(data, -3, 10);
        System.out.println("排序之后：\n" + java.util.Arrays.toString(data));
    }
}
