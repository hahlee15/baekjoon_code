import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static int n, a, b;
	public static int[] parent;	
	
	public static void findRelation() {
		int i = 1, j = 1;
		int a_parent[] = new int[parent.length + 1];
		int b_parent[] = new int[parent.length + 1];
		a_parent[0] = a;
		b_parent[0] = b;
		
		while(true) {
			if(parent[a] == 0) {
				break;
			}
			a_parent[i] = parent[a];		
			i++;
			a = parent[a];
		}
		
		while(true) {
			if(parent[b] == 0) {
				break;
			}
			b_parent[j] = parent[b];
			j++;
			b = parent[b];
		}
		
		int ai = 0;
		int bi = 0;
		boolean breakfor = false;
		for(ai = 0;  ai < i; ai++) {
			for(bi = 0; bi < j; bi++) {
				if(a_parent[ai] == b_parent[bi]) {
					breakfor = true;
					break;
				}	
			}
			if(breakfor == true) {
				break;
			}
		}
		
		if(breakfor == false) {
			System.out.print(-1);
		}
		else {
			System.out.print(ai + bi);
		}		
	}
		
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String exn = br.readLine();
		n = Integer.parseInt(exn);
		String question[] = br.readLine().split(" ");
		
		a = Integer.parseInt(question[0]);
		b = Integer.parseInt(question[1]);

		parent = new int[n + 1];
		int x = 0;
		int y = 0;
		String exm = br.readLine();
		int m = Integer.parseInt(exm);		
		for(int i = 0; i < m; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
	         while (st.hasMoreTokens()) {
	            x = Integer.parseInt(st.nextToken());
	            y = Integer.parseInt(st.nextToken());	            
	         }		
			parent[y] = x;						//x는 y의 부모
		}
		findRelation();
	}
}