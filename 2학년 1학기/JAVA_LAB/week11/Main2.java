import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class Main2 extends JFrame{
    
    // 사용할 라벨, 텍스트필드, 버튼, 판넬 객체 생성
    JLabel label1 = new JLabel("숫자를 추측하시오: ");
    JTextField field = new JTextField(10);
    JLabel label2 = new JLabel("숫자를 입력해주세요.");
    JButton button1 = new JButton("새 게임");
    JButton button2 = new JButton("종료");
    JPanel panel1 = new JPanel();
    JPanel panel2 = new JPanel();
    JPanel panel3 = new JPanel();
    int rand = (int)(Math.random()*100); // 랜덤한 값 저장

    public Main2(){

        // 새 게임 버튼을 누르면 rand 변수가 재 선언된다.
        button1.addActionListener(e -> {
            rand = (int)(Math.random()*100);
        });

        // 종료 버튼을 누르면 프로그램을 종료한다.
        button2.addActionListener(e -> {
            System.exit(0);
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        });

        // 만약 Enter 버튼이 눌렸을때 실행된다.
        field.addKeyListener(new KeyListener(){
            public void keyPressed(KeyEvent e){
                if(e.getKeyCode() == KeyEvent.VK_ENTER){ // Enter 버튼이 눌렸을때
                    int get = Integer.parseInt(field.getText()); // 텍스트필드의 값을 정수로 저장
                    if(get > rand){ // rand 값과 비교
                        panel2.setBackground(Color.blue);
                        label2.setText("너무 높습니다.");
                    }
                    else if(get < rand){ // rand 값과 비교
                        panel2.setBackground(Color.red);
                        label2.setText("너무 낮습니다.");
                    }
                    else{ // 정답일 경우
                        panel2.setBackground(Color.green);
                        label2.setText("정답입니다!");
                    }
                }
            }
            // 사용하지 않음
            public void keyReleased(KeyEvent e){ }
            public void keyTyped(KeyEvent e){ }
        });

        panel1.add(label1); // 판넬에 추가
        panel1.add(field);  // 판넬에 추가
        panel2.add(label2); // 판넬에 추가
        panel3.add(button1);// 판넬에 추가
        panel3.add(button2);// 판넬에 추가

        // 화면에 추가 북, 중앙, 서를 중심으로 출력
        add(panel1, BorderLayout.NORTH);
        add(panel2);
        add(panel3, BorderLayout.SOUTH);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        setTitle("숫자 게임");       // 제목 설정
        setSize(300,150);           // 윈도우 창 크기 설정
        setVisible(true);           // 화면에 창 보이게 하기
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
    }    

    public static void main(String args[]){
        Main2 main = new Main2();
    }
}
