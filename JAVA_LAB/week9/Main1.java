import javax.swing.*; // 윈도우 창을 위한 헤더파일

public class Main1 extends JFrame{  // Jframe을 상속받는다.

    public Main1(){ // Main1 클래스의 생성자
        JLabel text = new JLabel("자바는 재미있나요?"); // 윈도우에 출력할 문장
        JButton button1 = new JButton("Yes");         // Yes 버튼
        JButton button2 = new JButton("No");          // No 버튼

        text.setLocation(30,20);    // 위치를 직접설정
        text.setSize(150,15);       // 사이즈를 직접설정
        add(text);                  // text를 윈도우창에 추가한다.

        button1.setLocation(150,10);    // 위치를 직접설정
        button1.setSize(60,50);         // 사이즈를 직접설정
        add(button1);                   // button1을 윈도우창에 추가한다.

        button2.setLocation(220,10);    // 위치를 직접설정
        button2.setSize(60,50);         // 사이즈를 직접설정
        add(button2);                   // button2를 윈도우창에 추가한다.

        // 프로세스상에 남아있을 수 있는 java 윈도우창을 종료시킨다.
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);        // 레이아웃을 직접설정가능하게 Layout 규칙을 null로 설정
        setTitle("My Frame");   // 창의 제목을 설정
        setSize(400,200);       // 창의 크기를 설정
        setVisible(true);       // 창을 보여줌, false면 보이지 않기
        // 프로세스상에 남아있을 수 있는 java 윈도우창을 종료시킨다.
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String args[]){
        Main1 main = new Main1();   // 객체를 생성한다.(생성자 실행시키기)
    }
}
