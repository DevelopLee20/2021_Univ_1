// game 폴더를 package로 가진다.
package game;

// Die 클래스
public class Die{
    
    // Die 클래스의 멤버 변수, 주사위의 숫자에 해당한다.
    int number;

    // 처음 주사위를 1로 설정한다.
    public Die(){
        this.number = 1;
    }

    // 주사위를 1~6이 랜덤으로 나오도록 하고, 멤버 변수의 값을 바꾸어준다.
    public int roll(){
        int random1 = (int)(Math.random()*6)+1;
        this.number = random1;
        return random1;
    }

    // 유저가 정한 주사위 면을 매개변수로 멤버 변수를 변경한다.
    public void setValue(int v){
        this.number = v;
    }

    // 클래스 내부 멤버의 값을 리턴한다.
    public int getValue(){
        return this.number;
    }

    // 현재 클래스의 멤버를 리턴한다.
    public String toString(){
        return "Die [number" + this.number + "]";
    }
}