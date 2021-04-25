// 스캐너를 사용하기 위한 헤더파일 임포트
import java.util.Scanner;

// 보드를 출력해주는 클래스
class Print{
	void Printer(char[][] map) {
		// 보드의 크기만큼 반복해서 내용을 출력한다.
    	for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                System.out.printf("%c ",map[i][j]);
            }
            // 매 줄을 나누어준다.
            System.out.printf("\n");
        }
	}
}

// 사람과 몬스터가 모두 상속받는 부모 메소드
class Sprite{
	// 변화 전 좌표, 변화 후 좌표, 모양 변수 멤버 선언
	int b_x, x;
	int b_y, y;
	char shape;
	
	// 좌표와 모양을 설정해준다.
	public Sprite(int x, int y, char shape) {
		this.x = x;
		this.y = y;
		this.shape = shape;
	}
	
	// 자식 메소드들의 이동 전 좌표가 저장된다.
	public void move() {
		b_x = this.x;
		b_y = this.y;
	}
}

// 캐릭터 클래스이며 Sprite 클래스를 상속받는다.
class Warrior extends Sprite{
	
	// Warrior 클래스의 생성자
	public Warrior(int x, int y) {
		// super 키워드로 부모 클래스의 생성자를 사용한다.
		super(x,y,'@');
	}
	
	// 메소드 오버로딩으로 매개변수가 다르기 때문에 새로운 메소드이다.
	public void move(String enter) {
		
		// 부모클래스의 move 메소드를 사용한다.
		super.move();
		
		// equals로 enter와 문자열을 비교한다.
		// 각각 좌표가 튕겨나가지 않도록 조건문으로 막아준다.
		if (enter.equals("h")) {
			if (x != 1)
				this.x--;
		}
		else if (enter.equals("j")) {
			if (y != 1)
				this.y--;
		}
		else if (enter.equals("k")) {
			if (y != 8)
				this.y++;
		}
		else {
			if (x != 8)
				this.x++;
		}
	}
}

// 적 클래스이며 Sprite 클래스를 상속받는다.
class Enemy extends Sprite{
	
	// Enemy 클래스의 생성자
	public Enemy(int x, int y) {
		// super 키워드로 부모클래스의 메소드(생성자)를 사용한다.
		super(x,y,'M');
	}
	
	// 부모클래스의 move 메소드를 오버라이딩해서 필요한 대로 조작한다.
	@Override
	public void move() {
		// 0~3 랜덤 정수를 뽑는다.
		int randoms = (int)(Math.random()*3);
		System.out.printf("%d\n",randoms);
		
		// 부모클래스의 move 메소드를 사용한다.
		super.move();
		
		// 랜덤 숫자에 따라서 좌표를 랜덤으로 바꿔준다.
		// 조건문으로 맵 밖으로 튕겨나가지 않도록 한다.
		if (randoms == 0) {
			if (x != 8 && x != 4)
				this.x++;
		}
		
		else if (randoms == 1) {
			if (y != 8 && y != 4)
				this.y++;
		}
		
		else if (randoms == 2) {
			if (x != 1 && x != 6)
				this.x--;	
		}

		else {
			if (y != 1 && y != 6)
				this.y--;
		}
	}
}

public class week6{
    public static void main(String args[]){
    	
    	// 기본 맵 초기화
        char[][] map = {
            {'#','#','#','#','#','#','#','#','#','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#','#','#','#','#','#','#','#','#','#'}
        };
        
        // Scanner, Print, Warrior, Enemy 객체를 생성한다.
        Scanner sc = new Scanner(System.in);
        Print pt = new Print();
        Warrior hero = new Warrior(1,1);
        Enemy devil = new Enemy(6,6);
        
        // 스프라이트들의 기본 위치에 맵 초기화를 해준다.
        map[hero.y][hero.x] = hero.shape;
        map[devil.y][devil.x] = devil.shape;
        map[5][5] = 'G';
        
        while(true) {
        	
        	// 맵을 출력하는 클래스, Printer 메소드를 사용한다.
        	pt.Printer(map);
        	System.out.print("왼쪽(h), 위쪽(j), 아래쪽(k), 오른쪽(l): ");
        	
        	// 입력되는 문자열을 받아서 enter에 저장한 후, 좌표를 변경해준다.
        	String enter = sc.next();
        	hero.move(enter);
        	devil.move();
        	
        	// 스프라이트들의 좌표가 변경됨에 따라서 맵에 출력을 변경해준다.
        	map[hero.b_y][hero.b_x] = ' ';
        	map[devil.b_y][devil.b_x] = ' ';
        	map[devil.y][devil.x] = devil.shape;
        	map[hero.y][hero.x] = hero.shape;
        }
        
    }
}