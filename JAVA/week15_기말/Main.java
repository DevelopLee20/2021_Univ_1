import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;

public class Main extends JFrame{ // Main 클래스

    // Image_Thread 클래스는 Thread를 상속 받는다.
    class Image_Thread extends Thread{ 

        // X 좌표와 Y 좌표를 저장할 ArrayList
        ArrayList<Integer> list_x = new ArrayList<>();
        ArrayList<Integer> list_y = new ArrayList<>();
        private JLabel label; // 이미지를 저장할 Label
        int idx = 0; // 인덱스 저장
        int fix;     // 고정할 인덱스 저장
        
        // icon 이미지와 표시할 x, y 좌표를 받는다.
        public Image_Thread(String icon, int x, int y){
            label = new JLabel(); // 라벨 생성
            label.setIcon(new ImageIcon(icon)); // 라벨에 이미지 추가
            label.setSize(150,150); // 라벨의 크기 설정
            label.setLocation(x, y); // 라벨의 위치 설정
            add(label); // 라벨을 화면에 출력
        }

        public void site_save(){ // 좌표를 저장하는 메소드
            // 마우스 리스너 이벤트 생성
            addMouseMotionListener(new MouseMotionListener(){
                // 마우스가 드래그 되었을 때 작동
                public void mouseDragged(MouseEvent event){
                    int x = event.getX(); // 마우스의 x 좌표 저장
                    int y = event.getY(); // 마우스의 y 좌표 저장
                    list_x.add(x-20); // 전체 화면에서 메뉴만큼을 줄인다
                    list_y.add(y-90); // 전체 화면에서 메뉴만큼을 줄인다
                    idx++; // index + 1
                    repaint(); // 화면의 변화를 재적용
                }

                @Override
                public void mouseMoved(MouseEvent e) {}
            }); 
        }
    
        public void cycle(){ // 하나의 좌표를 출력하고 삭제한다.
            label.setBounds(list_x.get(0),list_y.get(0),150,150);
            list_x.remove(0);
            list_y.remove(0);
        }
    
        public void run(){

            // 고정된 index 값이 0이 될때까지 반복
            while(fix-- != 0){
                
                cycle();
                repaint(); // 변화 재적용
                
                try{
                    Thread.sleep(100); // 0.1초의 딜레이를 준다
                } catch (InterruptedException e){ // 오류를 대비한 예외 처리
                    e.printStackTrace();
                }
            }
        }

        public int r_index(){ // 인덱스 값을 반환함
            return this.idx;
        }

        public void fixing(){ // 고정 인덱스 저장함
            this.fix = this.idx;
        }
    }

    JPanel menu_panel = new JPanel(); // 메뉴 판낼

    JButton go = new JButton("재생"); // 재생 버튼
    
    // RadioButton 그룹
    JRadioButton bcat = new JRadioButton("고양이");
    JRadioButton bper = new JRadioButton("사람");
    JRadioButton bdog = new JRadioButton("강아지");
    ButtonGroup group = new ButtonGroup();

    // Image_Thread 클래스의 객체 생성
    Image_Thread cat = new Image_Thread("asset/Cat.PNG",100,100);
    Image_Thread per = new Image_Thread("asset/Person.PNG",200,200);
    Image_Thread dog = new Image_Thread("asset/Dog.PNG",300,300);

    public Main(){

        // go 버튼이 눌렸을 때 실행
        go.addActionListener(e ->{ 
            dog.fixing();
            cat.start();
            per.start();
            dog.start();
        });

        // 고양이 버튼이 눌렸을 때 실행
        bcat.addActionListener(e ->{
            cat.site_save();
        });

        // 사람 버튼이 눌렸을 때 실행
        bper.addActionListener(e ->{
            cat.fixing();
            per.site_save();
        });

        // 강아지 버튼이 눌렸을 때 실행
        bdog.addActionListener(e ->{
            per.fixing();
            dog.site_save();
        });

        // 버튼의 배경 설정
        bcat.setBackground(Color.WHITE);
        bper.setBackground(Color.WHITE);
        bdog.setBackground(Color.WHITE);

        // 라디오 버튼들을 그룹화
        group.add(bcat);
        group.add(bper);
        group.add(bdog);

        // 메뉴 판넬에 추가함
        menu_panel.add(go);
        menu_panel.add(bcat);
        menu_panel.add(bper);
        menu_panel.add(bdog);

        // 메뉴 주위에 박스로 둘러싸도록 함
        menu_panel.setBorder(BorderFactory.createTitledBorder("메뉴"));
        menu_panel.setBackground(Color.white); // 배경을 흰색으로 설정
        add(menu_panel, BorderLayout.NORTH); // 메뉴를 북쪽으로 정렬함

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        setTitle("애니메이션 프로그램"); // 윈도우창 이름 설정
        setSize(990,540); // 윈도우창 크기 설정
        setVisible(true); // 윈도우창 보이기 true
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
    }

    public static void main(String args[]){
        new Main(); // Main 클래스의 생성자 실행
    }
}