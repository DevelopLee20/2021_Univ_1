import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class Main1 extends JFrame implements ActionListener{
    
    Container contain = new Container();              // 라디오버튼 정렬
    JRadioButton radio1 = new JRadioButton("bird");   // radio 1
    JRadioButton radio2 = new JRadioButton("cat");    // radio 2
    JRadioButton radio3 = new JRadioButton("dog");    // radio 3
    JRadioButton radio4 = new JRadioButton("rabbit"); // radio 4
    JRadioButton radio5 = new JRadioButton("pig");    // radio 5
    ButtonGroup radio = new ButtonGroup();            // radio group/
    JLabel label = new JLabel();                      // 이미지 라벨
    ImageIcon icon;                                   // 이미지 아이콘
    
    public Main1(){
        // 버튼 그룹에 추가해서 중복 클릭을 방지한다.
        radio.add(radio1); // 버튼 그룹에 추가
        radio.add(radio2); // 버튼 그룹에 추가
        radio.add(radio3); // 버튼 그룹에 추가
        radio.add(radio4); // 버튼 그룹에 추가
        radio.add(radio5); // 버튼 그룹에 추가
        
        contain.add(radio1); // 라디오 버튼 세로 정렬
        contain.add(radio2); // 라디오 버튼 세로 정렬
        contain.add(radio3); // 라디오 버튼 세로 정렬
        contain.add(radio4); // 라디오 버튼 세로 정렬
        contain.add(radio5); // 라디오 버튼 세로 정렬
        contain.setLayout(new GridLayout(0, 1)); // 라디오 버튼 세로 정렬

        radio1.addActionListener((ActionListener) this); // 버튼을 액션 리스너 등록
        radio2.addActionListener(this); // 버튼을 액션 리스너 등록
        radio3.addActionListener(this); // 버튼을 액션 리스너 등록`
        radio4.addActionListener(this); // 버튼을 액션 리스너 등록
        radio5.addActionListener(this); // 버튼을 액션 리스너 등록

        add(contain, BorderLayout.WEST); // WEST 방향에 출력
        add(label); // 라벨 출력( 그림 출력 )

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        setTitle("Radio Button Demo");// 제목 설정
        setSize(400,300);           // 윈도우 창 크기 설정
        setVisible(true);           // 화면에 창 보이게 하기
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
    }

    @Override // 부모클래스의 메소드를 수정가능하게 함
    public void actionPerformed(ActionEvent e){

        // 어떤 라디오 인지 확인 한 후 다른 그림을 출력함
        if(e.getSource() == radio1){
            icon = new ImageIcon("art/bird.jpg");
        }

        if(e.getSource() == radio2){
            icon = new ImageIcon("art/cat.jpg");
        }

        if(e.getSource() == radio3){
            icon = new ImageIcon("art/dog.jpg");
        }

        if(e.getSource() == radio4){
            icon = new ImageIcon("art/rabbit.jpg");
        }

        if(e.getSource() == radio5){
            icon = new ImageIcon("art/pig.jpg");
        }
        label.setIcon(icon); // 생성된 그림을 icon으로 출력함
    }

    public static void main(String args[]){
        Main1 main = new Main1();
    }
}