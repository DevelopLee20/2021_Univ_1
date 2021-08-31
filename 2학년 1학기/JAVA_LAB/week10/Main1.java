import javax.swing.*; // 자바 윈도우창 라이브러리
import java.awt.*;    // JFrame 라이브러리

public class Main1 extends JFrame{
    
    // button과 panel 객체 생성
    JButton button1 = new JButton("노란색");
    JButton button2 = new JButton("핑크색");
    JPanel panel = new JPanel();

    public Main1(){

        // 람다식을 통해서 색상을 변경해줌
        button1.addActionListener(e -> {
            panel.setBackground(Color.yellow);
        });

        // 람다식을 통해서 색상을 변경해줌
        button2.addActionListener(e -> {
            panel.setBackground(Color.pink);
        });

        panel.add(button1); // 판넬에 버튼을 추가
        panel.add(button2); // 판넬에 버튼을 추가

        add(panel);         // 창에 판넬을 추가

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        setTitle("이벤트 예제"); // 제목 설정
        setSize(400,200);       // 윈도우 창 크기 설정
        setVisible(true);       // 화면에 창 보이게 하기
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화

    }

    public static void main(String args[]){
        Main1 main = new Main1();   // Main1 객체 생성
    }
}
