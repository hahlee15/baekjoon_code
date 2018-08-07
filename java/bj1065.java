import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N;
	
	public static void hansoo() {
		int baek = 0, sip = 0, il = 0;
		int count = 99;
		
		if(N < 100) {
			System.out.println(N);
		} else if(100 <= N && N < 111) {
			System.out.println(99);
		} else {
			int i = 111;
			int temp = 0;
			
			for(; i <= N; i++) {
				temp = i;
				baek = temp / 100;
				temp -= (baek * 100);
				sip = temp / 10;
				temp -= (sip * 10);
				il = temp;
				
				if((il - sip) == (sip - baek)) {
					count++;
				}
			}
			System.out.println(count);
		} 
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());				
		
		hansoo();
	}
}