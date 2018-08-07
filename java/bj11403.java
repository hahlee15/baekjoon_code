import java.io.*;

public class Main {
	static int[][] graph;
	static int N;
	static boolean[] visit;

	public static void dfs(int i) {
		for (int j = 1; j < N + 1; j++) {
			if (graph[i][j] == 1 && visit[j] == false) {
				visit[j] = true;
				dfs(j);
			}
		}
	}

	public static void main(String[] args) throws Exception {
		int i = 0, j = 0;
		String temp;
		String[] temp2;

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		temp = br.readLine();
		N = Integer.parseInt(temp);

		graph = new int[N + 1][N + 1];
		visit = new boolean[N + 1];

		for (i = 1; i < N + 1; i++) {
			temp = br.readLine();
			temp2 = temp.split(" ");
			for (j = 1; j < N + 1; j++) {
				graph[i][j] = Integer.parseInt(temp2[j - 1]);
			}
		}

		for (i = 1; i < N + 1; i++) {
			dfs(i);
			for (j = 1; j < N + 1; j++) {
				if (visit[j] == true) {
					graph[i][j] = 1;
				}
				visit[j] = false;
			}
		}

		for (i = 1; i < N + 1; i++) {
			for (j = 1; j < N + 1; j++) {
				System.out.print(graph[i][j] + " ");
			}
			System.out.println();
		}
	}
}