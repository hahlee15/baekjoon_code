import java.io.BufferedReader;
import java.util.*;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
	static int N,M,V;
	static int[][] node;
	static int[] queue;
	static boolean[] visitd;
	static boolean[] visitb;
	
	public static void dfs(int i) {
		visitd[i] = true;
		System.out.print(i + " ");
		for(int j = 1; j < N+1; j++) {
			if(node[i][j] == 1 && visitd[j] == false) {
				dfs(j);
			}
		}
	}
	
	public static void bfs(int i) {
		Queue <Integer> q = new <Integer> LinkedList();
		
		q.offer(i);
		visitb[i] = true;
		
		while(!q.isEmpty()) {
			int temp = q.poll();
			System.out.print(temp + " ");
			
			for(int j = 1; j < N+1; j++) {
				if(node[temp][j] == 1 && visitb[j] == false) {
					q.offer(j);
					visitb[j] = true;
				}
			}
		}
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String input2[] = input.split(" ");		
		
		N = Integer.parseInt(input2[0]);
		M = Integer.parseInt(input2[1]);
		V = Integer.parseInt(input2[2]);
				
		int from = 0, to = 0;		
		int i = 0;
		node = new int[N+1][N+1];
		visitd = new boolean[N+1];
		visitb = new boolean[N+1];
		for(; i < M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
	         while (st.hasMoreTokens()) {
	            from = Integer.parseInt(st.nextToken());
	            to = Integer.parseInt(st.nextToken());
	            
	         }
	         node[from][to] = 1;
			 node[to][from] = 1;
		}
		dfs(V);
		System.out.println();
		bfs(V);
	}
}
