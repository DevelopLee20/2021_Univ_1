import java.util.*;

public class week3_6{
	public static void main(String[] args) {
		double[] score = {1.0,2.0,3.0,4.0};
		double big = score[0];
		double sum = 0;
		
		for (double value : score) {
			System.out.print(value+" ");
			sum += value;
			if (value > big)
				big = value;
		}
		System.out.print("\n");
		System.out.println("합은 "+sum);
		System.out.println("최대값은 "+big);
	}
}