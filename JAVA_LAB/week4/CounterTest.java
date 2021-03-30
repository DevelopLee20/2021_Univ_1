// 1번 문제

package JAVA_LAB.week4;

public class CounterTest {
    public static void main(String args[]){
        Counter ct = new Counter(100);
        for(int i=0; i<2; i++){
            ct.up();
        }
        System.out.println(ct.getCount());
    }
}
