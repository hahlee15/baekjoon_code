import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static int[] dp;
	static int min = 0;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String temp = br.readLine();
		int N = Integer.parseInt(temp);
		int i = 0;

		dp = new int[N + 1];
		dp[0] = 0;
		dp[1] = 0;

		if (N == 0 || N == 1) {
			System.out.print(dp[N]);
		} else {
			for (i = 2; i < N + 1; i++) {
				dp[i] = dp[i - 1] + 1;
				if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
					dp[i] = dp[i / 2] + 1;
				}
                if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
					dp[i] = dp[i / 3] + 1;
				}
			}
			System.out.print(dp[N]);
		}
	}
}