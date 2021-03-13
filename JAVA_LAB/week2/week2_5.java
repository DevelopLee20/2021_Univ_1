import java.util.*;

public class week2_5{
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("경기장은 어디입니까? ");
		String stadium = sc.nextLine();
		System.out.print("이긴팀은 어디입니까? ");
		String win = sc.nextLine();
		System.out.print("진팀은 어디입니까? ");
		String lose = sc.nextLine();
		System.out.print("우수선수는 누구입니까? ");
		String mvp = sc.nextLine();
		System.out.print("스코어는 몇대? ");
		int score1 = sc.nextInt();
		System.out.print("몇 입니까? ");
		int score2 = sc.nextInt();
		sc.close();
		
		System.out.println("오늘 "+stadium+"에서 야구 경기가 열렸습니다.");
		System.out.println(win+"과 "+lose+"은 치열한 공방전을 펼쳤습니다.");
		System.out.println(mvp+"이 맹활약을 하였습니다.");
		System.out.println("결국 "+win+"가 "+lose+"을 "+score1+":"+score2+"로 이겼습니다.");
	}
}