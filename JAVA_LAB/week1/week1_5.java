public class week1_5{
	public static void main(String[] args) {
		
		int num = 34;
		boolean flag;
		
		// num 값을 절반으로 해서 2번 중복 출력되는 것을 방지한다.
		for (int i=2; i<num/2+1; ++i) {
			
			flag = false;
			
			// i 값이 소수인지 판단한다.
			for (int j=2; j<i; ++j) {
				if ( i % j == 0) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				
				flag = false;

				// num 값에서 소수 i를 뺀 값을 div에 대입한다.
				int div = num - i;
				
				// div 값이 소수인지 판단한다.
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