package game;   // game 패키지

public class Gold extends Sprite{

    public Gold(int x, int y){              // Gold 클래스의 생성자
        super(x,y,'G');                     // Sprite 클래스의 생성자를 호출한다.
    }

    public void set_gold(char[][] map){     // 골드의 최초 위치를 설정한다.
        map[this.y][this.x] = this.shape;
    }
}
