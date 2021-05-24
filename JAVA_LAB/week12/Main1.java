import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Main1 extends JFrame implements MouseListener{
    JLabel[] number = new JLabel[10];
    int count = 0;

    public Main1(){
        for(int i=0; i<10; i++){
            int x = (int)(Math.random()*270);
            int y = (int)(Math.random()*270);
            number[i] = new JLabel(""+i);
            number[i].setLayout(null);
            number[i].setBounds(x,y,10,10);
            number[i].addMouseListener(this);
            add(number[i]);
        }

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        setTitle("게임");// 제목 설정
        setSize(300,300);           // 윈도우 창 크기 설정
        setVisible(true);           // 화면에 창 보이게 하기
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        int b_e_x = e.getX()+10;
        int a_e_x = e.getX()-10;
        int b_e_y = e.getY()+10;
        int a_e_y = e.getY()-10;
        System.out.println(e.getX()+"   "+e.getY());
        System.out.println(number[count].getX()+"   "+number[count].getY());
        if(number[count].getX() < b_e_x && number[count].getY() < b_e_y && number[count].getY() < a_e_x && number[count].getY() < a_e_y){
            number[count++].setVisible(false);
        }
    }

    @Override
    public void mousePressed(MouseEvent e) {
        
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void mouseExited(MouseEvent e) {        
    }

    public static void main(String args[]){
        Main1 main = new Main1();
    }
}