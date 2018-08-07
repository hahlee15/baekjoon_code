import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static int N;
	public static char[][] room;
	
	public static void findSeat() {
		int row[] = new int[N];
		int col[] = new int[N];
		
		int x = 0;
		int limit = N - 2;
		int possible = 0;
		
		int i = 0, j = 0;
		for(i = 0; i < N; i++) {
			x = 0;
			possible = 0;
			for(j = 0; j < N; j++) {
				if(room[i][j] == 'X') {
					possible = 0;
					x++;
					if(x > limit) {
						break;
					}
				}
				else {
					possible++;
					if(possible == 2) {
						row[i]++;
						
					}
				}
			}
		}
		
		
		for(j = 0; j < N; j++) {
			x = 0;
			possible = 0;
			for(i = 0; i < N; i++) {
				if(room[i][j] == 'X') {
					possible = 0;
					x++;
					if(x > limit) {
						break;
					}
				}
				else {
					possible++;
					if(possible == 2) {
						col[j]++;
					}
				}
			}
		}
		
		int rowcount = 0;
		int colcount = 0;
		for(i = 0; i < N; i++) {
			if(row[i] != 0) {
				rowcount += row[i];
			}
			if(col[i] != 0) {
				colcount += col[i];
			}
		}
		System.out.print(rowcount + " " + colcount);
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String Nex = br.readLine();
		N = Integer.parseInt(Nex);
		
		int i = 0;
		room = new char[N][N];
		for(; i < N; i++) {
			String info = br.readLine();
			room[i] = info.toCharArray();
		}
		findSeat();
	}
}