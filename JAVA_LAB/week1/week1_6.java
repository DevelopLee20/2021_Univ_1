public class week1_6{
	public static void main(String[] args) {
		double pi = 3.0;
		double four = 4.0;
		int i = 0;
		int count = 0;
		
		while ( i != 300 ) {
			i += 2;
			
			if ( count % 2 == 0 ) {
				pi = pi + four/(i*(i+1)*(i+2));
				count = count + 1;
			}
			else {
				pi = pi - four/(i*(i+1)*(i+2));
				count = count + 1;
			}
		}
		
		System.out.println("pi = "+pi);
	}
}