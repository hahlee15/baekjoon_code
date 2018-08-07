import java.io.*;
import java.util.*;

public class Main {
	static int N;
	static int[][] relation;
	static int[] count;
	static int[] bacon;

	public static void kevin() {
		Queue<Integer> q = new <Integer>LinkedList();
		int temp = 0, i = 1, j = 1;
		
		for(i = 1; i < N + 1; i++) {
			q.offer(i);
			while(!q.isEmpty()) {
				temp = q.poll();
				for(j = 1; j < N + 1; j++) {
					if(relation[temp][j] == 1 && count[j] == 0 && j != i) {
						q.offer(j);
						count[j] = count[temp] + 1;
					}
				}
			}
			for(j = 1; j < N + 1; j++) {
				bacon[i] += count[j];
				count[j] = 0;
			}
		}
		
		int min = 10000;
		int mini = 0;
		for(j = 1; j < N + 1; j++) {
			if(min > bacon[j]) {
				min = bacon[j];
				mini = j;
			}
		}
		System.out.println(mini);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String temp = br.readLine();
		String[] temp2 = temp.split(" ");
		N = Integer.parseInt(temp2[0]);
		int M = Integer.parseInt(temp2[1]);
		relation = new int[N + 1][N + 1];
		count = new int[N + 1];
		bacon = new int[N + 1];

		int i = 0;
		int x = 0, y = 0;
		for (i = 0; i < M; i++) {
			temp = br.readLine();
			temp2 = temp.split(" ");
			x = Integer.parseInt(temp2[0]);
			y = Integer.parseInt(temp2[1]);
			relation[x][y] = 1;
			relation[y][x] = 1;
		}
		kevin();
	}
}
