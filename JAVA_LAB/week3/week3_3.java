public class week3_3{
	public static void main(String[] args) {
		// 첫번째 주사위가 나오는 수를 i에 저장
		for(int i=1; i<7; i++) {
			// 두번째 주사위가 나오는 수를 j에 저장
			for(int j=1; j<7; j++) {
				// i + j 의 합이 6일 경우 그 경우를 출력한다.
				if(i+j == 6)
					System.out.print("("+i+","+j+")"+" ,");
			}
		}
	}
}