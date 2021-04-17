// game 폴더에 있는 Die 파일을 임포트한다.
import game.Die;
// 스캐너를 사용할 수 있는 헤더파일을 임포트한다.
import java.util.Scanner;

// 메인 실행 함수
public class Main {
    public static void main(String args[]){

        // 유저와 컴퓨터의 객체를 생성하고, 스캐너 객체 또한 생성한다.
        Die User_die = new Die();
        Die Cpu_die = new Die();
        Scanner sc = new Scanner(System.in);

        // 현재 주사위의 면을 알려준다.
        // 1로 초기화 되어있기 때문에 둘 다 1의 값을 가진다.
        System.out.println("유저의 주사위: "+User_die.getValue());
        System.out.println("컴퓨터의 주사위 :"+Cpu_die.getValue());

        // 정수를 입력받아서, setValue 메소드의 매개변수로 사용한다.
        int num = sc.nextInt();
        sc.close();
        User_die.setValue(num);
        
        // 주사위를 굴렸다는 문장을 출력한 후 roll 메소드를 실행시킨다.
        System.out.println("주사위를 굴렸습니다!");
        System.out.println("컴퓨터의 주사위 :"+Cpu_die.roll());

        // 컴퓨터보다 유저의 값이 크면 유저가 이기고, 아니면 컴퓨터가 이긴다.
        if ( User_die.getValue() > Cpu_die.getValue() ){
            System.out.println("유저가 이겼습니다.");
        }
        else if ( User_die.getValue() < Cpu_die.getValue() ){
            System.out.println("컴퓨터가 이겼습니다.");
        }
        else{
            System.out.println("비겼습니다.");
        }
    }
}
