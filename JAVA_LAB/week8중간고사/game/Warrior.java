package game;   // game 패키지

public class Warrior extends Sprite {

    public Warrior(int x, int y){
        super(x,y,'@'); // Sprite 클래스의 생성자를 사용한다.
    }

    public void move(String enter){

        super.move();

        if (enter.equals("h") && x != 1 ){      // 입력된 값과 벽이 아니라면 이동한다.
            this.x--;   // 좌표를 조정한다.
        }

        else if (enter.equals("j") && y != 1 ){ // 입력된 값과 벽이 아니라면 이동한다.
            this.y--;   // 좌표를 조정한다.
        }

        else if (enter.equals("k") && y != 8 ){ // 입력된 값과 벽이 아니라면 이동한다.
            this.y++;   // 좌표를 조정한다.
        }

        else if (enter.equals("l") && x != 8 ){ // 입력된 값과 벽이 아니라면 이동한다.
            this.x++;   // 좌표를 조정한다.
        }   
    }
}
