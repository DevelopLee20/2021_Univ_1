// 1번 문제

public class Counter { 
    // 외부에서 접근 불가한 integer 형 counter 변수를 선언한다.
    private int counter; 

    // Counter.java에 Counter 생성자를 선언한다.
    public Counter(int counter1){ 
        // private counter 변수를 저장한다.
        counter = counter1; 
    }

    void up(){
        // counter = counter + 1
        counter++; 
    }

    // getter 로써 counter  변수를 반환한다.
    public int getCount(){ return counter; } 
    // setter 로써 counter를 받아서 counter 변수로 저장한다.
    public void setCount( int counter ){ this.counter = counter; } 
}