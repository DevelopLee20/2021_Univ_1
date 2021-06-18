import javax.swing.*; // 자바 윈도우창 라이브러리

public class Main2 extends JFrame{
    
    // 텍스트와 텍스트필드 그리고 판넬 객체 생성
    JLabel text = new JLabel(" 마일을 입력하시오 ");
    JTextField field1 = new JTextField(10);
    JLabel point = new JLabel(" -> ");
    JTextField field2 = new JTextField(10);
    JButton button = new JButton("변환");
    JPanel panel1 = new JPanel();
    JPanel panel2 = new JPanel();
    JPanel panel3 = new JPanel();

    public Main2(){

        // 람다식을 이용해서 버튼 클릭시 마일에서 km로 연산해준다.
        button.addActionListener(e -> {
            float mile = Float.parseFloat(field1.getText()); // 텍스트를 받아서 실수형으로 파싱해준다.
            mile = (float)(mile * 1.609);   // km로 계산해준다.
            field2.setText(""+mile+" km");  // km를 출력해준다.
        });

        field2.setEnabled(false); // 텍스트 필드를 사용자가 입력 못하도록 막는다.
        panel1.add(text);   // 판넬에 추가
        panel1.add(field1); // 판넬에 추가
        panel1.add(point);  // 판넬에 추가
        panel1.add(field2); // 판넬에 추가
        panel2.add(button); // 판넬에 추가

        panel3.add(panel1); // 판넬에 추가
        panel3.add(panel2); // 판넬에 추가
        add(panel3);        // 판넬을 윈도우 창에 출력

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        setTitle("Mile -> Km"); // 제목 설정
        setSize(400,200);       // 윈도우 창 크기 설정
        setVisible(true);       // 화면에 창 보이게 하기
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
    }

    public static void main(String args[]){
        Main2 main = new Main2();  // Main2 객체 생성
    }
}
