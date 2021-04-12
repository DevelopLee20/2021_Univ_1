import java.util.Scanner;

class Sprite{
    void public Setsite(int x, int y){
        
    }
}

class Warrior extends Sprite{
    int x, y;

    public Warrior(int x, int y){
        this.x = x;
        this.y = y;
    }
}

class Enemy extends Sprite{
    int x, y;

    public Enemy(int x, int y){
        this.x = x;
        this.y = y;
    }
}

class Gold extends Sprite{
    int x, y;
    
    public Gold(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class week6{
    public static void main(String args[]){
        char[][] map = {
            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
        };

        Warrior hero = new Warrior(1, 1);
        Enemy bad = new Enemy(10, 10);
        Gold gold = new Gold(5, 5);
        Scanner sc = new Scanner(System.in);

        while(true){
            System.out.print("왼쪽(h), 위쪽(j), 아래쪽(k), 오른쪽(l): ");
            String where = sc.next();
            System.out.println(where);
        }
    }
}