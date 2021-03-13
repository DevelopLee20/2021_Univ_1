import java.util.*;

public class week2_2{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("투입한 돈: ");
		int money = sc.nextInt();
		
		System.out.print("물건 값: ");
		int good_price = sc.nextInt();
		
		int charge = money - good_price;
		System.out.println("거스름 돈: "+charge);
		
		System.out.println("500원 동전의 개수: "+(int)charge/500);
		System.out.println("100원 동전의 개수: "+(int)charge%500/100);
		
		sc.close();
	}
}