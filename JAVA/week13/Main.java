import java.util.TimerTask;     // 쓰레드 TimerTask
import java.awt.BorderLayout;   // 레이아웃
import java.util.Timer;         // 쓰레드 Timer
import java.awt.event.*;        // 이벤트처리
import javax.swing.*;           // 윈도우창

class Monster{ // 몬스터 클래스 , 점수를 저장

    static int score = 0;

    public Monster(){

    }

    public void kill(){
        score += 1;
    }

    public int get_kill(){
        return score;
    }
}

public class Main extends JFrame{

    int location[][] = { // 몬스터 소환 좌표
        {200,100},{500,100},{800,100},{200,450},{500,450},{800,450}
    };
    JLabel label = new JLabel("점수: ");            // 점수 텍스트 라벨
    JLabel label1 = new JLabel("0");                // 점수 라벨
    JLabel icons = new JLabel();                    // 아이콘 라벨
    ImageIcon icon = new ImageIcon("monster.jpg");  // 아이콘 이미지
    JPanel panel = new JPanel();                    // 판넬
    Timer timer = new Timer();                      // 타이머 객체

    TimerTask task = new TimerTask(){   // 타이머태스크 객체

        @Override   // 부모 메소드를 수정
        public void run(){  // schedule 호출시 작동하는 메소드
            icons.setVisible(true);                                 // icons를 화면에 표시
            int rand = (int)(Math.random()*6);                      // 0~5의 변수 생성
            icons.setLocation(location[rand][0],location[rand][1]); // 몬스터의 위치 지정
            icons.setSize(200,200);                                 // icons의 크기를 설정
            icons.setIcon(icon);                                    // icons의 이미지를 icon으로 설정

            icons.addMouseListener(new MouseAdapter(){  // 마우스 이벤트 메소드
                public void mouseClicked(MouseEvent e){ // 마우스가 클릭 되었을 때 작동(몬스터 클릭시)
                    icons.setVisible(false);            // 아이콘을 삭제
                    new Monster().kill();                        // 몬스터를 죽였을때 점수 추가
                    label1.setText(""+new Monster().get_kill()); // 몬스터를 죽였을때 변화된 점수 표시
                }
            });
            add(icons); // icons를 화면에 추가
        }
    };

    public Main(){

        timer.schedule(task, 0, 1000); // TimerTask , 처음 딜레이 시간 , 반복 딜레이 시간

        this.setLayout(null);          // 레이아웃(위치)을 맘대로 조정가능

        panel.add(label);              // panel에 label을 추가
        panel.add(label1);             // panel에 label1을 추가
        panel.setSize(100,30);         // panel의 사이즈를 조정
        add(panel, BorderLayout.NORTH);// 판넬을 화면에 추가하고 화면내의 정렬은 북쪽(위)으로

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        setTitle("몬스터 게임");                         // 윈도우창 제목
        setSize(1200,800);                              // 윈도우창 크기
        setVisible(true);                               // 윈도우창 표시
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
    }

    public static void main(String args[]){
        Main main = new Main(); // Main 클래스의 생성자 실행
    }
}