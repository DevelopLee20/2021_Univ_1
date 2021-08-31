class Prime{
	boolean check(int num) {
		for (int i=2; i<num; ++i) {
			if ( num % i == 0 ) {
				return true;
			}
		}
		return false;
	}
}

public class week1_5_2{
	public static void main(String[] args) {
		int num = 34;
		Prime pr = new Prime();
		
		for (int i=2; i<num/2+1; ++i) {
			boolean flag = pr.check(i);
			
			if (!flag) {
				int div = num - i;
				
				flag = pr.check(div);
				
				if(!flag)
					System.out.println(num+" = "+i+" + "+div);
			}
		}
	}
}