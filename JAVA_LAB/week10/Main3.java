import javax.swing.*;                 // 자바 윈도우창 라이브러리
import java.awt.*;                    // JFrame 라이브러리
import java.awt.event.ActionEvent;    // ActionEvent 라이브러리
import java.awt.event.ActionListener; // ActionListener 라이브러리

// Main3 함수는 JFrame을 상속받으면서 ActionListener 이벤트 처리를 해준다.
public class Main3 extends JFrame implements ActionListener{

    // 사용할 멤버 변수 선언
    float x = 0, y = 0;
    boolean C_x = true, C_y = true;
    String token = "";

    // 사용할 객체 생성
    JPanel panel1 = new JPanel();
    JPanel panel2 = new JPanel();
    JPanel panel3 = new JPanel();
    JTextField field = new JTextField(10);
    JPanel grid = new JPanel(new GridLayout(4,4,1,1));

    // 그리드에 들어갈 텍스트 배열
    String[] labels = {
        "1", "2", "3", "4", "5", "6", "7",
        "8", "9", "+", "-", "*", "/", "C", "=" 
    };

    public Main3(){
        field.setEnabled(false);  // 텍스트필드에 직접입력하지 못하게 한다.
        field.setHorizontalAlignment(JTextField.RIGHT); // 텍스트필드를 오른쪽 정렬한다.

        // 텍스트 배열을 불러와서 그리드에 순서대로 배열한다.
        for(int i=0; i<15; i++){
            JButton button = new JButton(labels[i]);
            button.addActionListener((ActionListener) this); // ActionListener을 생성한다.
            grid.add(button);   // 버튼을 grid에 추가함
        }

        panel1.add(field);  // 판넬에 추가
        panel2.add(grid);   // 판넬에 추가
        panel3.add(panel1); // 판넬에 추가
        panel3.add(panel2); // 판넬에 추가
        add(panel3);        // 판넬을 윈도우 창에 생성

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        setTitle("Java Calculator");// 제목 설정
        setSize(300,200);           // 윈도우 창 크기 설정
        setVisible(true);           // 화면에 창 보이게 하기
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
    } 

    @Override   // 오버라이딩
    public void actionPerformed(ActionEvent e){

        // 버튼이 무엇이 눌렸는지 읽어온다.
        JButton b = (JButton)e.getSource();

        // 버튼의 내용을 저장
        String input = b.getText();

        switch (input) {

            // 버튼이 연산 기호일 경우 token 에 저장
            case "+":
            case "-":
            case "/":
            case "*":   
                field.setText(""+input);
                token = input;
                System.out.println(token);
                break;

            // 초기화 한다.
            // x와 y가 입력되지 않았던 상황으로 돌아간다.
            case "C":
                field.setText(""+input);
                C_x = true;
                C_y = true;
                break;

            // = 을 입력받으면 token에 따라서 연산한다.
            case "=":
                if(token.equals("+")){
                    field.setText("" + (x+y));
                    x = x+y;
                    
                }
                else if(token.equals("-")){
                    field.setText("" + (x-y));
                    x = x-y;
                }
                else if(token.equals("*")){
                    field.setText("" + (x*y));
                    x = x*y;
                }
                else if(token.equals("/")){
                    field.setText("" + (x/y));
                    x = x/y;
                }
                C_y = true;
                break;

            // 숫자가 입력되면 x에 우선 저장한 후, y에 저장한다.
            // 초기화하면 다시 x부터 저장한다.
            default:
                if(C_x){
                    x = Integer.parseInt(b.getText());
                    field.setText(""+x);
                    C_x = false;
                    System.out.println(x);
                }
                else if(C_y){
                    y = Integer.parseInt(b.getText());
                    field.setText(""+y);
                    C_y = false;
                    System.out.println(y);
                }
                break;
        }
    }

    public static void main(String args[]){
        Main3 main = new Main3(); // Main2 객체 생성
    }
}
