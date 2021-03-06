public class week1_5{
	public static void main(String[] args) {
		
		int num = 34;
		boolean flag;
		
		for (int i=2; i<num/2+1; ++i) {
			
			flag = false;
			
			for (int j=2; j<i; ++j) {
				if ( i % j == 0) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				
				flag = false;
				
				int div = num - i;
				
				for (int k=2; k<div; ++k) {
					if ( div % k == 0) {
						flag = true;
						break;
					}
				}
				
				if (!flag)
					System.out.println(num+" = "+i+" + "+div);
			}
		}
	}
}