import java.awt.event.*; // ActionListener 라이브러리
import javax.swing.*;    // 자바 윈도우창 라이브러리
import java.awt.*;       // 이벤트처리 라이브러리

public class TicTaeToe extends JFrame implements ActionListener{

    // 그리드 생성 (3x3 사이즈 틱택토 보드 객체 생성)
    JPanel grid = new JPanel(new GridLayout(3,3,1,1));
    int turn = 0;   // 틱택토의 턴을 저장할 멤버변수
    JButton[][] button = new JButton[3][3];

    public TicTaeToe(){ // TicTaeToe 클래스의 생성자

        // 틱택토 보드 객체 배열 생성

        // 반복문으로 객체 배열을 버튼으로 생성
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                button[i][j] = new JButton();         // 버튼 생성
                button[i][j].addActionListener(this); // 이벤트 처리 등록
                grid.add(button[i][j]);               // 그리드에 버튼 추가
            }
        }

        add(grid); // 그리드를 창에 생성

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        setTitle("Tic-Tac-Toe 프로그램"); // 제목 설정
        setSize(300,300);            // 윈도우 창 크기 설정
        setVisible(true);            // 화면에 창 보이게 하기
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
    }

    // 누구의 승리인지 확인하는 메소드
    public String check_win(){

        // 승자가 아직 공백이다.
        String winner = "";

        for(int i=0; i<3; i++){
            // 일자로 문양이 같은지 비교함, 각각 가로와 세로를 비교함
            boolean win3 = button[i][0].getText().equals(button[i][1].getText()) && button[i][1].getText().equals(button[i][2].getText());
            boolean win4 = button[0][i].getText().equals(button[1][i].getText()) && button[1][i].getText().equals(button[2][i].getText());

            if(win3){ // 문양이 같으면 승자를 저장
                winner = button[i][0].getText();
                break;
            }

            else if(win4){ // 문양이 같으면 승자를 저장
                winner = button[0][i].getText();
                break;
            }

            if(i==2){
                // 대각선으로 문양이 같은지 비교함
                boolean win1 = button[0][0].getText().equals(button[1][1].getText()) && button[1][1].getText().equals(button[2][2].getText());
                boolean win2 = button[0][2].getText().equals(button[1][1].getText()) && button[1][1].getText().equals(button[2][0].getText());
                
                if(win1){ // 문양이 같으면 승자를 저장
                    winner = button[0][0].getText();
                }

                else if(win2){ // 문양이 같으면 승자를 저장
                    winner = button[0][2].getText();
                }
            }
        }

        return winner;
    }

    public void actionPerformed(ActionEvent e){

        // 어떤 버튼을 눌렀는지에 대한 정보 변수
        JButton b = (JButton)e.getSource();

        // 공백일 경우에만 수를 둘 수 있음
        if(b.getText() == ""){
            if( turn % 2 == 0 ){
                b.setText("O");
            }
            else{
                b.setText("X");
            }
    
            turn++; // 한 턴을 추가한다
        }

        // 무승부 일 경우 룰에 의해서 보드를 초기화
        if( check_win().equals("") && turn % 9 == 0 ){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    button[i][j].setText("");
                }
            }
        }

        // 무승부가 아닐경우 누구의 승리인지 출력한다.
        else if( check_win().equals("") == false ){
            System.out.println(check_win()+" 의 승리입니다!");
        }
    }



    public static void main(String args[]){
        // 메인함수에서 클래스를 생성 및 생성자 실행
        TicTaeToe main = new TicTaeToe();
    }
}