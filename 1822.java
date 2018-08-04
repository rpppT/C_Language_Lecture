package 알고리즘;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class SET {
	int n, m;
	Scanner scanner = new Scanner(System.in);
	Set<Integer> set = new HashSet<>();
	
	public void func(){
		
		n = scanner.nextInt();
		m = scanner.nextInt();

		while(n-- > 0){
			set.add(scanner.nextInt());
		}
		
		
		while(m-- > 0 ){
			int x = scanner.nextInt();
			if(set.contains(x)){
				set.remove(x);
			}
		}
		if(set.size() == 0 ){
			System.out.println(0);
			return;
		}
		System.out.println(set.size());
		ArrayList<Integer> list = new ArrayList<>(set);
		Collections.sort(list);
		
		for(int i = 0; i<set.size(); i++){
			System.out.print(list.get(i)+" ");
		}
	}
	public static void main(String[] args) {
		new SET().func();
	}
}

