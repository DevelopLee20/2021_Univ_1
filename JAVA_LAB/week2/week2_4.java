public class week2_4{
	public static void main(String args[]) {
		int one = 0; // 피보나치 첫번째 수
		int two = 1; // 피보나치 두번째 수
		System.out.print(one+", ");
		System.out.print(two+", ");
		
		for(int i=0; i<11; i++) {
			int next = one+two; // 다음 수를 저장
			System.out.print(next+", ");
			one = two; // 첫번째는 두번째로
			two = next; // 두번째는 세번째로
		}
	}
}