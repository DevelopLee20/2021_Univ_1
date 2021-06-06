import javax.swing.*; // 윈도우 창 출력 라이브러리

public class Main3 extends JFrame{ // JFrame을 상속 받음
    class MyThread extends Thread{ // Thread를 상속 받음

        private JLabel label;   // 사진을 출력할 라벨
        private int x, y;       // 좌표 저장
        private int count = 0;  // 애니메이션 반복횟수

        public MyThread(int x, int y){
            this.x = x; // x 좌표
            this.y = y; // y 좌표
            label = new JLabel(); // 라벨 객체를 생성 후 아이콘을 설정
            label.setIcon(new ImageIcon("txt_file/monster.jpg"));
            label.setBounds(x,y,200,200); // 좌표와 사이즈를 설정
            add(label); // 화면에 추가
        }

        public void cycle(){ // 애니메이션 한 단위를 저장
            x += 1; y += 1; // 좌표를 각각 1씩 더해줌
            label.setBounds(x,y,200,200); // 좌표를 더해준 좌표로 이동
        }

        public void run(){ // 쓰레드 부분
            
            while((count++) != 200){ // 200회 반복
                
                cycle();    // 애니메이션 1회
                repaint();  // Thread를 효율적으로 사용하게 메소드를 호출 해줌
                
                try{ // 쓰레드의 딜레이를 준다.
                    Thread.sleep(100);
                
                // 오류 발생시 오류 문장 출력
                } catch (InterruptedException e){
                    e.printStackTrace();
                }
            }
        }
    }

    public Main3(){
        setTitle("Java Animation"); // 윈도우창 제목 설정
        setSize(600,600);           // 윈도우창 크기 설정
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        setLayout(null);            // 레이아웃을 사용자지정 가능케함
        (new MyThread(0,0)).start();// 쓰레드 객체를 생성해서 .start()로 실행 시킴
        setVisible(true);           // 윈도우창 보이게 설정
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
    }

    public static void main(String args[]){
        new Main3();
    }
}
