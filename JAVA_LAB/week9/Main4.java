import javax.swing.*; // 윈도우 창을 위한 헤더파일
import java.awt.*;    // setLayout으로 레이아웃을 설정하기 위한 헤더파일

public class Main4 extends JFrame{  // JFrame을 상속받는다.

    // labels에 라벨로 사용할 내용을 미리 선언해 놓는다.
    private String[] labels = {
        "1", "2", "3", "4", "5", "6", "7", "8", "9", "*", "0",
        "#", "send", " ", "end"
    };

    public Main4(){

        // panel 객체와 textField 객체, 그리고 Button 객체를 생성한다.
        JPanel panel1 = new JPanel();
        JPanel panel2 = new JPanel();
        JPanel panel3 = new JPanel();
        JTextField text = new JTextField(34); // TextField의 길이를 결정함
        JButton b_clear = new JButton("clear");
        JPanel grid = new JPanel();

        panel1.add(text);   // panel1을 창에 표현한다.
        grid.setLayout(new GridLayout(5,3,1,1));    // GridLayout으로 그리드를 생성한다.

        // 반복문을 사용해서 button 객체를 생성해서 labels의 라벨을 하나씩 붙인다.
        for(int i=0; i<15; i++){
            JButton button = new JButton(labels[i]);
            grid.add(button);
        };

        // panel2의 레이아웃을 그리드로 설정한다.
        panel2.setLayout(new GridLayout(1,2,0,0));
        panel2.add(grid);    // grid를 panel2에 추가한다.
        panel2.add(b_clear); // b_clear를 panel2에 추가한다.

        panel3.add(panel1);  // panel3에 panel1을 추가한다.
        panel3.add(panel2);  // panel3에 panel2를 추가한다.
        add(panel3);         // panel3를 창에 표시한다.

        // 프로세스상에 남아있을 수 있는 java 윈도우창을 종료시킨다.
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("My Frame"); // 창의 제목을 설정
        setSize(400,220);     // 창의 크기를 설정
        setVisible(true);     // 창을 보여줌, false면 보이지 않기
        // 프로세스상에 남아있을 수 있는 java 윈도우창을 종료시킨다.
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public static void main(String args[]){
        Main4 main = new Main4(); // 객체를 생성한다.(생성자 실행시키기)
    } 
}