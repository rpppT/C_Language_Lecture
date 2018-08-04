

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	Scanner scanner = new Scanner(System.in);
	int n_a, n_b;
	int i;

	
	Set<Integer> set_1 = new HashSet<>(), set_2 = new HashSet<>();
	
	public Main() {
		n_a = scanner.nextInt();
		n_b = scanner.nextInt();
		
		for(i = 0; i<n_a; i++) 
			if(!set_1.add(scanner.nextInt()))
				System.exit(0);
		for(i =0 ; i < n_b; i++)
			if(!set_2.add(scanner.nextInt()))
				System.exit(0);
		for(i = 0; i < set_2.size(); i++) {
			if(set_1.contains(new ArrayList<>(set_2).get(i))) {
				set_1.remove(new ArrayList<>(set_2).get(i));
				n_a  -= 1;
			}
		}
		if(n_a == 0 ) {
			System.out.println(n_a);
			System.exit(0);
		}
		System.out.println(n_a);
		for(i = 0; i<set_1.size(); i++)
		  System.out.print(new ArrayList<>(set_1).get(i)+" ");
	}	
	public static void main(String[] args) {
		new Main();
	}
}
