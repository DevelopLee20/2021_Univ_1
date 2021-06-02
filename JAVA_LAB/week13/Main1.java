import java.util.*;

public class Main1{
    public Main1(){

        // Double 형 ArrayList 선언, 크기는 10이다.
        ArrayList<Double> list = new ArrayList<Double>(10);
        
        // scanner 객체 생성
        Scanner sc = new Scanner(System.in);               

        int sum = 0;    // 입력값의 합이 저장된다.

        for(int i=0; i<10; i++){    // 10개의 double형 변수를 입력받는다.
            System.out.print("심사위원의 점수: ");
            Double num = sc.nextDouble();
            list.add(num);          // ArrayList에 추가한다.
            sum += num;             // sum변수에 더해준다.
        }

        // 최대값과 최소값이 저장된다.
        Double up = Collections.max(list);
        Double down = Collections.min(list);

        System.out.println("점수의 합: "+(sum-up-down));

        sc.close(); // 스캐너 객체를 닫아준다.
    }
    public static void main(String args[]){
        Main1 main = new Main1();
    }
}