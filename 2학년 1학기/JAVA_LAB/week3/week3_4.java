import java.util.*;

public class week3_4{
	public static void main(String[] args) {
		// Scanner 객체를 sc 변수에 생성한다.
		Scanner sc = new Scanner(System.in);
		
		System.out.print("키를 입력하세요: ");
		int cm = sc.nextInt();
		System.out.print("몸무게를 입력하세요: ");
		int kg = sc.nextInt();

		// 표준 몸무게가 저장됨
		int normal = (cm-100)*9/10;
		
		// 조건에 따라서 몸무게를 분류한다.
		if (kg > normal)
			System.out.println("과체중입니다.");
		else if (kg == normal)
			System.out.println("표준입니다.");
		else
			System.out.println("저체중입니다.");
		
		sc.close();
	}
}