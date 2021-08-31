import java.util.*;

public class week3_5{
	public static void main(String[] args) {
		// Scanner 객체를 sc 변수에 저장한다.
		Scanner sc = new Scanner(System.in);
		
		System.out.print("연산을 입력하세요: ");
		// 다음 입력되는 String 값을 띄어쓰기 없이 받느다.
		String what = sc.next();
		
		System.out.print("숫자 2개를 입력하세요: ");
		// 다음 입력되는 double 값을 입력받는다.
		double num1 = sc.nextDouble();
		double num2 = sc.nextDouble();
		
		if(what.equals("+"))
			System.out.println(num1 + "+" + num2 + "=" + (num1+num2));
		if(what.equals("-"))
			System.out.println(num1 + "-" + num2 + "=" + (num1-num2));
		if(what.equals("*"))
			System.out.println(num1 + "*" + num2 + "=" + (num1*num2));
		if(what.equals("/"))
			System.out.println(num1 + "/" + num2 + "=" + (num1/num2));
		
		sc.close();
	}
}