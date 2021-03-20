public class week3{
	public static void main(String[] args) {
		String[] shape = { "Clubs", "Diamonds", "Hearts", "Spades" };
		String[] number = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
		int count = 0;
		String[] list = new String[5];
		
		while(count!=5) {
			int random1 = (int) (Math.random()*shape.length);
			int random2 = (int) (Math.random()*number.length);
			String check = shape[random1] + number[random2];
			
			boolean in = true;
			
			for (String value: list) {
				if(check.equals(value)) {
					in = false;
					break;	
				}
			}
			
			if(in) {
				System.out.println(shape[random1]+"의 "+number[random2]);
				list[count] = check;;
				count++;
			}
		}
	}
}