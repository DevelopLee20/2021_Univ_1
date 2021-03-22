public class week3{
	public static void main(String[] args) {
		
		// 모양이 저장된 shape 배열
		String[] shape = { "Clubs", "Diamonds", "Hearts", "Spades" };
		
		// 번호가 저장된 number 배열
		String[] number = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
		
		// 5개의 출력 즉, 5장의 카드를 뽑으면 반복을 종료 시킴
		int count = 0;

		// 5개의 뽑힌 카드가 저장될 list 배열
		String[] list = new String[5];
		
		while(count!=5) {

			// 모양이 결정된다. shape.length로 배열의 크기를 받는다.
			int random1 = (int) (Math.random()*shape.length);

			// 번호가 결정된다. number.length로 모양의 크기를 받는다.
			int random2 = (int) (Math.random()*number.length);

			// 뽑힌 카드의 정보는 check 변수에 저장된다.
			String check = shape[random1] + number[random2];
			
			// 이미 뽑힌 카드일 경우 = false, 새로운 카드일 경우 = true
			boolean in = true;
			
			// list의 값이 value 변수에 저장되며, equals를 통해서 뽑힌 카드인지 판단한다.
			for (String value: list) {
				if(check.equals(value)) {
					// 이미 뽑힌 카드면 in 변수를 false로 변경하고 반복 종료
					in = false;
					break;	
				}
			}
			
			// 만약 뽑히지 않은 카드일 경우 즉, in = true 일 경우, 출력하고, count++를 해준다.
			if(in) {
				System.out.println(shape[random1]+"의 "+number[random2]);
				list[count] = check;;
				count++;
			}
		}
	}
}