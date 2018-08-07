import java.io.*;
import java.lang.Integer;
import java.util.Arrays;

public class Main {
   public static void main(String[] args) throws Exception{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine().trim());   				//node 수
      String ex = br.readLine();                     					//각 node의 부모 index
      String[] temp = ex.split(" ");                  					//공백 기준으로 나누기
      int del = Integer.parseInt(br.readLine().trim()); 				//삭제할 node의 index
	      
	  int result = 0;                               					//결과값 변수
	  int root = 0;
	  int i = 0;                              					//index 변수
	  int[] node = new int[n];                  					//node를 저장할 배열
	  int[] del_child = new int[n];               				//삭제될 child들의 index 배열
	  for(i = 0; i < n; i++) {
	    node[i] = Integer.parseInt(temp[i]);      				//String을 int로 변환 후 node 배열에 넣기
	  }
	  
	  if(node[del] == -1) {						//root 삭제한 것
		  System.out.println("0");
	  }
	  
	  else {
		  for(i = 0; i < n; i++) {
			  if(node[i] == -1) {
				  root = i;					//root의 index를 표시
			  }
		  }
		  
		  int j = 0, k = 0;		   
		  while(true) {
			  node[del] = -1;                        			//삭제될 node는 -10로 바꿈
		     
			  for(i = 0; i < n; i++) {
				  if(node[i] != del) {                  		//부모 index가 삭제될 index가 아니면 continue
					  continue;
				  }
				  else {                	           			//맞을 경우 다 삭제될 것이므로 del_child 배열에 index 저장
		           del_child[j] = i;
		           j++;
		        }
		     }
			  
		     if(j == 0) {                        				//리프 노드를 하나 지워서 j값이 하나도 증가하지 않았을 때
		    	 break;
		     }
		     else {
		        del = del_child[k];               				//delete할 node를 본인의 자식에게로 토스
		        k++;
		        if(k > j) {						//del_child의 index만큼만 돌아야하므로 이보다 커지면 break
		        	break;
		        }
		     }                                       
		  }
		  
		  int hasChild[] = new int[n];					//leaf node가 있는지 확인할 배열
		  for(i = 0; i < n; i++) {
		     if((node[i] == -1) && (i != root)) {       //삭제된 node에는 -1이 들어있음 (그러나 root도 -1이 들어있었으므로 root일 경우는 제외)
		        hasChild[i] = -1;                     	//즉 삭제된 노드는 존재하지를 않으므로 -1로 check
		     }            
		     else {
		    	 if(i == root)
		    		 hasChild[i]++;
		    	 
		    	 else
		    		 hasChild[node[i]]++;                  	//부모 index에 check == 자식이 있다는 것 == 리프 노드가 아니라는 것
		     }         
		  }
		  
		  for(i = 0; i < n; i++) {
		     if(hasChild[i] == 0) {                     //자식이 없는, 즉  리프 노드는 check! (배열에서 초기화시켜둔 0 상태 그대로이므로)
		        result++;
		     }
		     else {
		        continue;
		     }
		  }
		  
		  if(result == 0) {								//root만 남은 것이므로
		   result = 1;
		  }
		  System.out.print(result);
	  }
	  
   }
}