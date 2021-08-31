import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame {
    public MyFrame() {

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setSize(300,150);
        setTitle("MyFrame");
        JPanel panel1 = new JPanel();
        JPanel panel2 = new JPanel();
        JPanel panel3 = new JPanel();
        JLabel Label = new JLabel("자바 호텔에 오신 것을 환영합니다. 숙박일수를 입력하세요.");
        panel1.add(Label);
        for(int i=1; i<6; i++){
            JButton Button = new JButton(i+"일");
            panel2.add(Button);
        }
        
        panel3.add(panel1);
        panel3.add(panel2);
        add(panel3);
        
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public static void main(String[] args) { 
        MyFrame f = new MyFrame();
    }
}