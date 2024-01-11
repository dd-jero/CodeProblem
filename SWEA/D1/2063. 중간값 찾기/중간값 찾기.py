import java.util.Scanner;
import java.util.ArrayList;

class Solution {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> numbers = new ArrayList<Integer>();
		int num = sc.nextInt();
		int midIndex = num / 2;
		
		for(int i =0;i<num;i++)
		{
			int n = sc.nextInt();
			numbers.add(n);
			
		}
		numbers.sort(null);
		System.out.println(numbers.get(midIndex));
		
	}

}
