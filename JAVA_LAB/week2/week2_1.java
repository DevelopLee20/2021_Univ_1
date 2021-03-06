import java.util.*;

// 정렬 알고리즘
// 버블 정렬 사용
class Glass{
	
	void array(int a, int b, int c) {
		for ( int i=0; i<2; i++ ) {
			
			if ( a > b ) {
				int swap = a;
				a = b;
				b = swap;
			}
			
			if ( b > c ) {
				int swap = b;
				b = c;
				c = swap;
			}
		}
		System.out.println("정렬된 숫자: "+a+" "+b+" "+c);
	}
}

public class week2_1{
	public static void main(String[] args) {
		int a, b, c;
		Scanner sc = new Scanner(System.in);
		Glass obj = new Glass(); // 클래스 객체 생성
		
		System.out.print("정수를 입력하시오: ");
		a = sc.nextInt();
		
		System.out.print("정수를 입력하시오: ");
		b = sc.nextInt();
		
		System.out.print("정수를 입력하시오: ");
		c = sc.nextInt();
		
		obj.array(a, b, c); // 버블정렬 메소드 사용
		
		sc.close();
	}
}