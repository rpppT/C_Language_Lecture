	package 알고리즘;
	
	
	import java.util.Scanner;
	import java.util.Stack;
	
	public class Main {
		int n , x , y;
		int round;
		boolean x_check, y_check;
		
		Stack<Integer> stack = new Stack<>();
	
		public void func(int n, int x,  int y){
			int i, index  = 0, counter = 0;
			int pop_data;
			
			x_check = true;
		    y_check = true;
			
			if(n == 2){
				for(i = 1; i<=n; i++){
					if(x != i && y != i){
						round = -1;
						return;
					}
				}
			}
			
			
			if((x % 2 == 0 ) && (y + 1 == x)){
				round = round +1;
				return;
			}else if((x % 2 != 0) && (x+1 == y)){
				round = round +1;
				return;
			}
			
			if(n % 2 == 0 ){
				for(i=1; i<=n; i++)
					stack.push(i);
				
				while(stack.size() > 0){
					pop_data = stack.pop();
					counter++;
					
					if(pop_data == x && x_check ) { x = n / 2- index; x_check = false; }
					else if(pop_data == y && y_check) { y = n /2 - index; y_check = false;}
					
					if(counter == 2 ) { index++;  counter = 0; }
				}
				
				round = round +1;
				func(n/2, x,  y);
			}else{
				
				for(i=1; i<=n-1; i++)
					stack.push(i);
				
				while(stack.size() > 0){
					pop_data = stack.pop();
					counter++;
					
					if(pop_data == x && x_check ) { x = (n-1)/ 2- index;  x_check = false; }
					else if(pop_data == y && y_check) { y = (n-1) /2 - index;  y_check = false;}
			
					if(counter == 2 ) { index++;  counter = 0; }
				}
				if(n == x ){
					x = (n-1)/2 + 1;
				}else if(n == y){
					y = (n-1)/2 + 1;
				}
				
				round = round + 1;
				func((n+1)/2, x , y);
			}
			
			return;
		}
		
		public Main() {
			String [] string = new Scanner(System.in).nextLine().split("\\s+");
			n = Integer.parseInt(string[0]);
			x = Integer.parseInt(string[1]);
			y = Integer.parseInt(string[2]);
			
			func(n, x ,y);
			System.out.println(round);
		}
		
		public static void main(String[] args) {
			new Main();
		}
	}

