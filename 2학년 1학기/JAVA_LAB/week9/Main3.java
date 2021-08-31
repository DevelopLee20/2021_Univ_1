import javax.swing.*; // 윈도우 창을 위한 헤더파일
import java.awt.*;    // setLayout으로 레이아웃을 설정하기 위한 헤더파일

public class Main3 extends JFrame{ // JFrame을 상속받는다.

    // 라벨 목록을 모두 배열로 작성한다.
    private String[] labels = {
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "11", "12", "13", "14", "15", "16", "17", "18", "19"
    };

    public Main3(){

        int index = 0; // 인덱스를 표시하기 위한 변수
        JPanel grid = new JPanel(); // grid를 사용하기 위한 Panel 객체를 생성한다.
        grid.setLayout(new GridLayout(5,4,3,3));    // GridLayout으로 레이아웃을 그리드로 설정

        // 반복문을 사용하여, 그리드의 크기 만큼 객체를 생성하고, labels을 하나씩 가지도록 한다.
        for(int i=0; i<5; i++){
            for(int j=0; j<4; j++){
                JButton button = new JButton(labels[index++]);

                // 랜덤메소드를 사용해서 RGB색을 랜덤으로 지정한 다음, 객체를 생성한다.
                int R = (int)(Math.random()*256);
                int G = (int)(Math.random()*256);
                int B = (int)(Math.random()*256);
                Color color = new Color(R, G, B);

                button.setBackground(color);    // button의 뒷배경을 설정한다.
                grid.add(button);               // grid에 button을 추가한다.
            }
        }

        add(grid);  // grid를 창에 더해준다.

        // 프로세스상에 남아있을 수 있는 java 윈도우창을 종료시킨다.
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("My Frame"); // 창의 제목을 설정
        setSize(400,200);     // 창의 크기를 설정
        setVisible(true);     // 창을 보여줌, false면 보이지 않기
        // 프로세스상에 남아있을 수 있는 java 윈도우창을 종료시킨다.
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    
    public static void main(String args[]){
        Main3 main = new Main3(); // 객체를 생성한다.(생성자 실행시키기)
    }

}
