import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	public static int n, a, b;
	public static int[][] relation;

	public static void findRelation() {
		boolean[] visit = new boolean[n + 1];
		int[] count = new int[n + 1];
		Queue<Integer> q = new <Integer>LinkedList();

		q.offer(a);
		visit[a] = true;
		while (!q.isEmpty()) {
			int temp = q.poll();
			for (int j = 1; j < n + 1; j++) {
				if (relation[temp][j] == 1 && count[j] == 0) {
					q.offer(j);
					count[j] = count[temp] + 1;
				}
			}
		}

		if (count[b] == 0) {
			System.out.print(-1);
		} else {
			System.out.print(count[b]);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String exn = br.readLine();
		n = Integer.parseInt(exn);
		String question[] = br.readLine().split(" ");

		a = Integer.parseInt(question[0]);
		b = Integer.parseInt(question[1]);

		relation = new int[n + 1][n + 1];
		int x = 0;
		int y = 0;
		String exm = br.readLine();
		int m = Integer.parseInt(exm);
		for (int i = 0; i < m; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			while (st.hasMoreTokens()) {
				x = Integer.parseInt(st.nextToken());
				y = Integer.parseInt(st.nextToken());
				relation[x][y] = 1;
				relation[y][x] = 1;
			}
		}
		findRelation();
	}
}