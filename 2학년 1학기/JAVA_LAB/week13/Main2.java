import java.util.HashSet;

public class Main2 {
    public Main2(){

        // HashSet를 정수형, 크기 6으로 설정한다.
        HashSet<Integer> lotto = new HashSet<Integer>(6);

        while(lotto.size() != 6){ // lotto의 size가 6일때까지 반복한다.
            // 1~45까지 랜덤하게 생성한다.
            lotto.add((int)(Math.random()*45+1));
        }

        System.out.println("Lotto [set="+lotto+"]");
    }

    public static void main(String args[]){
        Main2 main = new Main2();
    }
}