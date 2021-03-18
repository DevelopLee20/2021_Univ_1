import java.util.*;

public class week3_5{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("연산을 입력하세요: ");
		String what = sc.next();
		
		System.out.print("숫자 2개를 입력하세요: ");
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