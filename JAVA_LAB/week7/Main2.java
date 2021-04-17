// 스캐너를 사용할 수 있는 헤더파일을 임포트한다.
import java.util.Scanner;
// rps 폴더의 RoPaSi 파일을 사용한다.
import rps.RoPaSi;

// 메인 실행 함수
public class Main2 {
    public static void main(String args[]){

        // 스캐너 객체를 생성한다.
        Scanner sc = new Scanner(System.in);

        // 숫자에 따라서 가위/바위/보 가 결정된다.
        System.out.print("하나를 선택하시오: 가위(0), 바위(1), 보(2): ");

        // user와 cpu 객체를 생성한다.
        RoPaSi user = new RoPaSi(sc.nextInt());
        RoPaSi cpu = new RoPaSi();

        // 스캐너 객체를 닫아준다.
        sc.close();

        // 컴퓨터의 값이 어떤 것인지 textReturn 메소드를 통해서 문장을 출력해준다.
        System.out.println("컴퓨터는 "+cpu.textReturn()+"를 냈습니다.");
        
        // 유저와 컴퓨터가 가위/바위/보를 낸 결과에 따라서 승패여부를 출력한다.
        if ((user.getNumber()+1)%3 == cpu.getNumber()%3){
            System.out.println("졌습니다.");
        }
        else if ((user.getNumber()-1)%3 == cpu.getNumber()%3){
            System.out.println("이겼습니다.");
        }
        else{
            System.out.println("비겼습니다.");
        }
    }
}
