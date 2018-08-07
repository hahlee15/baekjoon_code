import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static int[] stair;
	static int[] F;

	public static void maximum() {
		F[0] = 0;
		F[1] = stair[1];
		F[2] = stair[1] + stair[2];

		int i = 3;
		for (; i < n + 1; i++) {
			F[i] = findMax(stair[i] + F[i - 2], stair[i] + stair[i - 1] + F[i - 3]);
        }
	}

	public static int findMax(int a, int b) {
		int max = 0;
		if (a > b) {
			max = a;
		} else {
			max = b;
		}
		return max;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter (System.out));

		String temp = br.readLine();
		n = Integer.parseInt(temp);
		stair = new int[n + 1];
		F = new int[n + 1];

		int i = 1;
		for (; i < n + 1; i++) {
			temp = br.readLine();
			stair[i] = Integer.parseInt(temp);
		}
		maximum();
        bw.write(String.valueOf(F[n]));
        bw.flush();
        bw.close();
	}
}