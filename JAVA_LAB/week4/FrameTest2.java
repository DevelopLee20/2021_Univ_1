package JAVA_LAB.week4;
// 윈도우 창 출력이 가능한 라이브러리 임포트
import javax.swing.*;
// 랜덤 함수를 사용 가능한 라이브러리 임포트
import java.lang.Math;

public class FrameTest2 {
    public static void main(String args[]){
        // 기본 위치를 선언해준다.
        int a = 30; int b = 30;
        // 윈도우 창을 사용가능 한 객체를 f에 저장한다.
        JFrame f = new JFrame("Frame Test");
        // 윈도우 창의 사이즈 지정
        f.setSize(300,200);
        // 윈도우 창의 위치 지정
        f.setLocation(a,20);
        // 창의 보임을 true로 설정
        f.setVisible(true);

        // 윈도우 창을 사용가능 한 객체를 fm에 저장한다.
        JFrame fm = new JFrame("Frame Test");
        // 윈도우 창의 사이즈 지정
        fm.setSize(300,200);
        // 윈도우 창의 위치 지정
        fm.setLocation(b,300);
        // 창의 보임을 true로 설정
        fm.setVisible(true);

        // 윈도우 창 2개 중 하나라도 1600을 넘기면 반복을 종료
        while(a < 1600 || b < 1600){
            // 랜덤 함수를 통해서 랜덤 값을 더해줌
            // 이때 int형으로 바꾸어 주어야 윈도우 창의 사이즈를 지정할 수 있다.
            a = a + (int)(Math.random() * 5);
            b = b + (int)(Math.random() * 5);
            // 윈도우 창의 위치를 갱신 해준다.
            f.setLocation(a,20);
            fm.setLocation(b,300);
        }

        // 첫 번째 창이 먼저 도착 했을 때 if, 아니면 else 의 문장을 출력한다.
        if ( a >= 1600 )
            System.out.println("No.1 Win!");
        else
            System.out.println("No.2 Win!");
    }
}
