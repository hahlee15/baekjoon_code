import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static int height[] = new int[9];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int sum = 0;
		
		for (int i = 0; i < 9; i++) {
			height[i] = Integer.parseInt(br.readLine());
			sum += height[i];
		}

		findDwarf(sum);		
		for(int p = 0; p < 7; p++) {
			bw.write(height[p] + "\n");
			bw.flush();
		}
		bw.close();
	}

	public static void findDwarf(int sum) {
		boolean end = false;
		int i = 0, j = 0;
		
		int diff = sum - 100;		
		
		for(i = 0; i < 8; i++) {
			for(j = i + 1; j < 9; j++) {
				if(diff == (height[i] + height[j])) {
					end = true;
					height[i] = 100;
					height[j] = 101;
					break;
				}
			}
			if(end == true) {
				break;
			}
		}

		quickSort(height, 0 , 8);
	}

	public static int partition(int arr[], int left, int right) {
		int pivot = arr[(left + right) / 2];

		while (left < right) {
			while ((arr[left] < pivot) && (left < right))
				left++;
			while ((arr[right] > pivot) && (left < right))
				right--;

			if (left < right) {
				int temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
			}
		}
		return left;
	}

	public static void quickSort(int arr[], int left, int right) {
		if (left < right) {
			int pivotNewIndex = partition(arr, left, right);

			quickSort(arr, left, pivotNewIndex - 1);
			quickSort(arr, pivotNewIndex + 1, right);
		}
	}
}