// 1번 문제

public class CounterTest {
    public static void main(String args[]){
        // Counter 객체를 ct 변수에 생성한다. 매개변수는 100으로 한다.
        Counter ct = new Counter(100);
        // up()을 두 번 호출한다.
        for(int i=0; i<2; i++){
            ct.up();
        }
        // getCount() 의 값을 불러온다.
        System.out.println(ct.getCount());
    }
}
