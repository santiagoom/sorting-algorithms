package sort;

/**
 * 快速排序
 * @author shkstart
 * 2013-11-27
 */
public class QuickSort {
	private static void swap(sort.DataWrap[] data, int i, int j) {
		sort.DataWrap temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}

	private static void subSort(sort.DataWrap[] data, int start, int end) {
		if (start < end) {
			sort.DataWrap base = data[start];
			int i = start;
			int j = end + 1;
			while (true) {
				while (i < end && data[++i].compareTo(base) <= 0)
					;
				while (j > start && data[--j].compareTo(base) >= 0)
					;
				if (i < j) {
					swap(data, i, j);
				} else {
					break;
				}
			}
			swap(data, start, j);
			subSort(data, start, j - 1);
			subSort(data, j + 1, end);
		}
	}
	public static void quickSort(sort.DataWrap[] data){
		subSort(data,0,data.length-1);
	}
	public static void main(String[] args) {
		sort.DataWrap[] data = { new sort.DataWrap(9, ""), new sort.DataWrap(-16, ""),
				new sort.DataWrap(21, "*"), new sort.DataWrap(23, ""),
				new sort.DataWrap(-30, ""), new sort.DataWrap(-49, ""),
				new sort.DataWrap(21, ""), new sort.DataWrap(30, "*"),
				new sort.DataWrap(30, "") };
		System.out.println("排序之前：\n" + java.util.Arrays.toString(data));
		quickSort(data);
		System.out.println("排序之后：\n" + java.util.Arrays.toString(data));
	}
}
