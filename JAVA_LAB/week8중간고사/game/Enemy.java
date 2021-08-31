package game;   // game 패키지

public class Enemy extends Sprite{  // Sprite 클래스를 상속받는다.
    
    public Enemy(int x, int y){     // Enemy 클래스의 생성자
        super(x,y,'M');             // super 키워드로 Sprite 메소드의 생성자를 우선 호출한다.
    }

    public void move(Gold g){                   // Gold 객체를 매개변수로 받는다.
        int randoms = (int)(Math.random()*3);   // randoms 변수를 생성한다.

        super.move();   // Sprite 메소드의 move를 호출한다.

        // 랜덤 값에 따라서 캐릭터를 이동시킨다.
        if(randoms == 0){
            if ( x != 8 && x != g.x-1 ) this.x++;   // 매개변수로 받은 골드의 위치에는 접근 불가하도록 한다.
        }

        else if (randoms == 1){
            if ( y != 8 && y != g.y-1 ) this.y++;   // 매개변수로 받은 골드의 위치에는 접근 불가하도록 한다.
        }

        else if (randoms == 2){
            if ( x != 1 && x != g.x+1 ) this.x--;   // 매개변수로 받은 골드의 위치에는 접근 불가하도록 한다.
        }

        else{
            if ( y != 1 && y != g.y+1 ) this.y--;   // 매개변수로 받은 골드의 위치에는 접근 불가하도록 한다.
        }
    }
}
