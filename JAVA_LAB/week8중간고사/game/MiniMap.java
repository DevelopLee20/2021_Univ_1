package game;   // game 패키지

public class MiniMap {
    
    public MiniMap(char[][] map, Warrior w, Enemy e, Gold g){
        map[w.y][w.x] = w.shape;    // 정한 좌표에 캐릭터 모양을 설정함
        map[e.y][e.x] = e.shape;    // 정한 좌표에 적 모양을 설정함
        map[g.y][g.x] = g.shape;    // 정한 좌표에 골드 모양을 설정함
    }

    public void printer(char[][] map){

        // 반복문을 통해서 맵을 출력해준다.
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                System.out.printf("%c ",map[i][j]);
            }
            System.out.printf("\n");
        }
    }

    public void move_map(char[][] map, Warrior w, Enemy e){
        map[w.b_y][w.b_x] = ' ';    // 전의 좌표는 공백으로
        map[e.b_y][e.b_x] = ' ';    // 전의 좌표는 공백으로
        map[w.y][w.x] = w.shape;    // 새로운 좌표로 모양을 갱신
        map[e.y][e.x] = e.shape;    // 새로운 좌표로 모양을 갱신
    }

    public boolean isGameOver(Warrior w, Gold g){   // 게임 종료에 대해서 판단한다.
        return (w.x == g.x && w.y == g.y);          // boolean 값을 리턴한다.
    }
}
