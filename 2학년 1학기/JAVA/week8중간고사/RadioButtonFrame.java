// 퀴즈를 나타내는 클래스 정의
// public class QuizItem{
//     String problem;
//     String correnct_ans;
// };

// public multiple extends QuizItem{
//     String choice[4];
// }
// 상속
// 객체 배열 or ArrayList

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class RadioButtonFrame extends JFrame implements ActionListener{

    private JRadioButton small, medium, large;
    private JLabel text;
    private JPanel topPanel, sizePanel, resultPanel, midPanel;

    public RadioButtonFrame(){

        setTitle("퀴즈 게임 프로그램");
        setSize(500,350);

        topPanel = new JPanel();
        topPanel.add(new JLabel("퀴즈 게임"));
        add(topPanel);

        midPanel = new JPanel();
        midPanel.add(new JLabel("다음 중 ~~가 아닌것은?"));
        add(midPanel);

        sizePanel = new JPanel();
        
        small = new JRadioButton("Small");
        medium = new JRadioButton("medium");
        large = new JRadioButton("large");

        add(small);
        add(medium);
        add(large);

        // ButtonGroup size = new ButtonGroup();
        // size.add(small);
        // size.add(medium);
        // size.add(large);

        small.addActionListener(this);
        medium.addActionListener(this);
        large.addActionListener(this); 

        sizePanel.add(small);
        sizePanel.add(medium);
        sizePanel.add(large);

        add(sizePanel, BorderLayout.CENTER);

        resultPanel = new JPanel();
        text = new JLabel("none size");
        text.setForeground(Color.red);
        resultPanel.add(text);
        add(resultPanel, BorderLayout.SOUTH);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e){

        String sm = "Small";
        
        if (e.getSource() == small){
            text.setText(sm);
        }

        if (e.getSource() == medium){
            text.setText(sm);
        }

        if (e.getSource() == large){
            text.setText(sm);
        }
    }

    public static void main(String args[]){
        new RadioButtonFrame();
    }
}