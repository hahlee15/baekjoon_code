import java.io.*;
import java.util.*;

public class Main {
	static int M = 0, N = 0, day = 0;
	static int[][] box;
	static Queue<Integer> tomato = new <Integer>LinkedList();

	public static void how_days() {
		int row = 0, col = 0;

		while (!tomato.isEmpty()) {
			day = tomato.poll();
			row = tomato.poll();
			col = tomato.poll();

			if (col - 1 >= 0) {
				if (box[row][col - 1] == 0) {
					box[row][col - 1] = 1;
					tomato.offer(day + 1);
					tomato.offer(row);
					tomato.offer(col - 1);
				}
			}
			if (col + 1 < M) {
				if (box[row][col + 1] == 0) {
					box[row][col + 1] = 1;
					tomato.offer(day + 1);
					tomato.offer(row);
					tomato.offer(col + 1);
				}
			}
			if (row - 1 >= 0) {
				if (box[row - 1][col] == 0) {
					box[row - 1][col] = 1;
					tomato.offer(day + 1);
					tomato.offer(row - 1);
					tomato.offer(col);
				}
			}
			if (row + 1 < N) {
				if (box[row + 1][col] == 0) {
					box[row + 1][col] = 1;
					tomato.offer(day + 1);
					tomato.offer(row + 1);
					tomato.offer(col);
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		while (st.hasMoreTokens()) {
			M = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
		}
		box = new int[N][M];

		int i = 0, j = 0;
		for (i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			while (st.hasMoreTokens()) {
				for (j = 0; j < M; j++) {
					box[i][j] = Integer.parseInt(st.nextToken());
					if (box[i][j] == 1) {
						tomato.offer(0);
						tomato.offer(i);
						tomato.offer(j);
					}
				}
			}
		}

		how_days();

		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (box[i][j] == 0) {
					System.out.println(-1);
					return;
				}
			}
		}
		System.out.println(day);
	}
}