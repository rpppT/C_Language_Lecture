
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
	int [] num_seq;
	int i;
	int cur_data;
	int counter;
	int sum;
	
	Set<Integer> set = new HashSet<>();
	
	
	public void seq_calc(){
		if(counter >= num_seq.length-1){
			return;
		}
		cur_data = num_seq[counter];
		sum += cur_data;
		
		for(i = counter+1; i < num_seq.length; i++){
			if(cur_data < num_seq[i]){
				if((i + 1 < num_seq.length -1 ) && (cur_data < num_seq[i+1]) && (num_seq[i] > num_seq[i+1])){
					cur_data = num_seq[i+1];
					sum += num_seq[i+1];
					
					set.add(num_seq[i] + (sum - num_seq[i+1]));
				}else{
					sum += num_seq[i];
					cur_data = num_seq[i];					
				}
				
			}else{
				if(i + 1 < num_seq.length - 1 && cur_data <  num_seq[i+1] && num_seq[i] < num_seq[i+1]){
					cur_data = num_seq[i+1];
					sum += num_seq[i+1];
				}
			}
		}
		set.add(sum);
		counter++;
		sum = 0;
	
		seq_calc();
	}
	public Main() {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		scanner.nextLine();
		
		if((1 <= N) && (N <= 1000)){
			num_seq = new int[N];
			
			for(int i = 0; i<N; i++){
				num_seq[i] = scanner.nextInt();
				if(num_seq[i] < 1 || num_seq[i] > 1000)
					return;
			}
			if(N == 1){
				System.out.println(num_seq[0]);
				return;
			}else{
				
			seq_calc();
			List<Integer> list = new ArrayList<>(set);
			Collections.sort(list);
//			System.out.println(list);
			System.out.println(list.get(list.size()-1));				
			}
		}
	}

	public static void main(String[] args) {
		System.out.println( );
		new Main();
	}
}

