import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String temp = br.readLine();
        String[] temp2 = temp.split(" ");
        
        int A = Integer.parseInt(temp2[0]);
        int B = Integer.parseInt(temp2[1]);
        
        System.out.print(A+B);
    }
}