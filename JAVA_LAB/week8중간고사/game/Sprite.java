package game;   // game 패키지

public class Sprite {
    
    // Sprite 클래스의 멤버를 설정한다.
    int b_x, x;
    int b_y, y;
    char shape;

    // Sprite 클래스의 생성자로써 모든 Sprite를 상속받은 객체가 사용한다.
    public Sprite(int x, int y, char shape){
        this.x = x;         // x좌표를 받아서 객체의 x 위치로 지정
        this.y = y;         // y좌표를 받아서 객체의 y 위치로 지정
        this.shape = shape; // 모양을 받아서 객체의 모양으로 지정
    }

    // 전의 좌표를 저장한다.
    public void move(){
        b_x = this.x;   // 이동 전 x좌표를 저장한다.
        b_y = this.y;   // 이동 전 y좌표를 저장한다.
    }
}
