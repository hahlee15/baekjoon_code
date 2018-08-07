import java.io.*;
import java.util.*;

public class Main {
	static int N;
	static int[] P;
	static int[] time;
	
	public static void ATM() {
		int answer = 0;
		Arrays.sort(P);
		
		int i = 1, j = 1;
		for(; i < N + 1; i++) {
			for(j = 1; j <= i; j++) {
				time[i] += P[j];
			}
			answer += time[i];
		}
		System.out.print(answer);
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		P = new int[N+1];
		time = new int[N+1];
		
		int i = 1;
		StringTokenizer st = new StringTokenizer(br.readLine());
		while(st.hasMoreTokens()) {
			P[i] = Integer.parseInt(st.nextToken());
			i++;
		}
		ATM();
	}
}