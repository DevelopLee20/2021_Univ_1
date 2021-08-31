import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JRadioButton;

public class Test {
  public static void main(String args[]) {
    JFrame frame = new JFrame();
    Container contentPane = frame.getContentPane();
    contentPane.setLayout(new GridLayout(0, 1));
    ButtonGroup group = new ButtonGroup();
    JRadioButton option = new JRadioButton("French Fries", true);
    group.add(option);
    contentPane.add(option);
    option = new JRadioButton("Onion Rings", false);
    group.add(option);
    contentPane.add(option);
    option = new JRadioButton("Ice Cream", false);
    group.add(option);
    contentPane.add(option);
    frame.setSize(200, 200);
    frame.show();
  }
}
       