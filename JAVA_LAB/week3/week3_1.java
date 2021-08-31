public class week3_1{
	public static void main(String[] args) {
		
		int sum = 0;
		
		// 1~100 까지의 숫자 중 3의 배수와 4의 배수만 sum에 더해준다.
		for(int i=1; i<101; i++) {
			if (i % 3 == 0)
				sum += i;
			else if (i % 4 == 0)
				sum += i;
		}
		
		System.out.println("3또는 4의 배수의 합 ="+sum);
	}
}