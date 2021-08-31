public class week2_3{
	public static void main(String args[]) {
		for(int i=0; i<11; i++) {
			for(int j=0; j<11; j++) {
				// 방정식이 성립하면 x값과 y값을 출력
				boolean check = 3*i+10*j == 100;
				if (check) {
					System.out.println("("+i+","+j+")");
				}
			}
		}
	}
}