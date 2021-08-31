import javax.swing.*;

public class Main3 extends JFrame{
    
    // 사용할 텍스트에리어, 버튼, 판넬 객체 생성
    JTextArea area1 = new JTextArea(5,10);
    JTextArea area2 = new JTextArea(5,10);
    JButton button1 = new JButton("번역");
    JButton button2 = new JButton("취소");
    JPanel panel1 = new JPanel();
    JPanel panel2 = new JPanel();
    JPanel panel3 = new JPanel();

    public Main3(){

        panel1.add(area1);  // 판넬에 추가
        panel1.add(area2);  // 판넬에 추가
        panel2.add(button1);// 판넬에 추가
        panel2.add(button2);// 판넬에 추가
        panel3.add(panel1); // 판넬에 추가
        panel3.add(panel2); // 판넬에 추가

        add(panel3);        // 화면에 출력되도록 함

        // 번역 버튼이 눌렸을 때
        button1.addActionListener(e -> {
            // 텍스트에리어의 값을 읽어서 저장한 후
            String get = (String) area1.getText();
            // word 메소드에서 단어를 찾고 결과를 출력한다.
            area2.setText(word(get));
        });

        // 취소 버튼을 눌렀을 때 프로그램 종료
        button2.addActionListener(e -> {
            System.exit(0);
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        });

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        setTitle("English Translator");// 제목 설정
        setSize(270,180);              // 윈도우 창 크기 설정
        setVisible(true);              // 화면에 창 보이게 하기
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
    }

    String word(String get){ // 단어가 있는지 찾는 메소드
        String[][] word = { // 단어 10개를 저장하고 있다
            {"Apple", "사과"},
            {"Ball", "공"},
            {"Cat", "고양이"},
            {"Dog", "개"},
            {"Egg", "달걀"},
            {"Fruit", "과일"},
            {"Grap", "당기다"},
            {"Hope", "희망"},
            {"Interesting", "흥미로운"},
            {"Job", "직업"}
        };

        // 반복해서 단어를 찾는다.
        for(int i=0; i<10; i++){
            if(get.equals(word[i][0])){
                return word[i][1]; // 존재하면 그 뜻을 반환
            }
        }
        return "[오류] 모릅니다.";  // 없으면 오류를 반환
    }

    public static void main(String args[]){
        Main3 main = new Main3();
    }

}
