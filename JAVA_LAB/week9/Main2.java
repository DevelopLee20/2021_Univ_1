import javax.swing.*; // 윈도우 창을 위한 헤더파일

public class Main2 extends JFrame { // Jframe을 상속받는다.

    public Main2(){

        // Panel과 Label 객체를 생성한다.
        JPanel panel1 = new JPanel();
        JPanel panel2 = new JPanel();
        JPanel panel3 = new JPanel();
        JLabel text = new JLabel("자바 호텔에 오신 것을 환영합니다. 숙박일수를 입력하세요.");

        // text를 창에 추가한다.
        panel1.add(text);

        // 반복문을 이용해서 button 객체를 5개 생성시킨다.
        for(int i=1; i<6; i++){
            JButton button = new JButton(i+"일");
            panel2.add(button);
        }

        // panel1과 panel2을 panel3에 추가한다.
        panel3.add(panel1);
        panel3.add(panel2);
        
        // panel3를 창에 생성한다.
        add(panel3);
        
        // 프로세스상에 남아있을 수 있는 java 윈도우창을 종료시킨다.
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("My Frame"); // 창의 제목을 설정
        setSize(400,200);     // 창의 크기를 설정
        setVisible(true);     // 창을 보여줌, false면 보이지 않기
        // 프로세스상에 남아있을 수 있는 java 윈도우창을 종료시킨다.
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String args[]){
        Main2 main = new Main2(); // 객체를 생성한다.(생성자 실행시키기)
    }
}
