import java.util.*;

public class week3_2{
	public static void main(String[] args) {
		// scanner 객체를 sc 변수에 생성한다.
		Scanner sc = new Scanner(System.in);
		
		System.out.print("정수를 입력하세요: ");
		int num = sc.nextInt();
		
		// 입력받은 num 변수를 기준으로 switch case 사용
		switch(num) {
		case 1:
			System.out.println("ONE");
			break;
		case 2:
			System.out.println("TWO");
			break;
		case 3:
			System.out.println("THREE");
			break;
		case 4:
			System.out.println("FOUR");
			break;
		case 5:
			System.out.println("FIVE");
			break;
		case 6:
			System.out.println("SIX");
			break;
		case 7:
			System.out.println("SEVEN");
			break;
		case 8:
			System.out.println("EIGHT");
			break;
		case 9:
			System.out.println("NINE");
			break;
		
		// case가 없는 경우 default 문이 실행된다.
		default:
			System.out.println("OTHER");
			break;
		
		}
		
		sc.close();
	}
}