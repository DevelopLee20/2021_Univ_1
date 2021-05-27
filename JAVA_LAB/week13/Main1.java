import java.util.*;

public class Main1{
    public Main1(){
        ArrayList<Double> list = new ArrayList<Double>(10);
        Scanner sc = new Scanner(System.in);
        int sum = 0;
        for(int i=0; i<10; i++){
            System.out.print("심사위원의 점수: ");
            Double num = sc.nextDouble();
            list.add(num);
            sum += num;
        }
        Double up = Collections.max(list);
        Double down = Collections.min(list);
        System.out.println("점수의 합: "+(sum-up-down));
        sc.close();
    }
    public static void main(String args[]){
        Main1 main = new Main1();
    }
}