import java.awt.BorderLayout;
import java.awt.Color;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;

public class Main extends JFrame{

    class Image_Thread extends Thread{

        ArrayList<Integer> list_x = new ArrayList<>();
        ArrayList<Integer> list_y = new ArrayList<>();
        private JLabel label;
        int x, y;
        int idx = 0;
        int fix;
        
        public Image_Thread(String icon){
            label = new JLabel();
            label.setIcon(new ImageIcon(icon));
            label.setSize(150,150);
        }
    
        public void site_save(){
            addMouseMotionListener(new MouseMotionListener(){
                public void mouseDragged(MouseEvent event){
                    int x = event.getX();
                    int y = event.getY();
                    list_x.add(x-20);
                    list_y.add(y-90);
                    idx++;
                }

                @Override
                public void mouseMoved(MouseEvent e) {}
            }); 
        }
    
        public void cycle(){
            label.setBounds(list_x.get(0),list_y.get(0),150,150);
            list_x.remove(0);
            list_y.remove(0);
        }
    
        public void run(){

            if(!list_y.isEmpty()){
                add(label);
            }

            while(fix-- != 0){
                
                cycle();
                repaint();
                
                try{
                    Thread.sleep(100);
                } catch (InterruptedException e){
                    e.printStackTrace();
                }
            }
        }

        public int r_index(){
            return this.idx;
        }

        public void fixing(){
            this.fix = this.idx;
        }
    }

    JPanel menu_panel = new JPanel();

    JButton go = new JButton("재생");
    
    JRadioButton bcat = new JRadioButton("고양이");
    JRadioButton bper = new JRadioButton("사람");
    JRadioButton bdog = new JRadioButton("강아지");
    ButtonGroup group = new ButtonGroup();

    Image_Thread cat = new Image_Thread("asset/Cat.PNG");
    Image_Thread per = new Image_Thread("asset/Person.PNG");
    Image_Thread dog = new Image_Thread("asset/Dog.PNG");

    public Main(){

        go.addActionListener(e ->{
            dog.fixing();
            cat.start();
            per.start();
            dog.start();
        });

        bcat.addActionListener(e ->{
            cat.site_save();
        });

        bper.addActionListener(e ->{
            cat.fixing();
            per.site_save();
        });

        bdog.addActionListener(e ->{
            per.fixing();
            dog.site_save();
        });

        bcat.setBackground(Color.WHITE);
        bper.setBackground(Color.WHITE);
        bdog.setBackground(Color.WHITE);

        group.add(bcat);
        group.add(bper);
        group.add(bdog);

        menu_panel.add(go);
        menu_panel.add(bcat);
        menu_panel.add(bper);
        menu_panel.add(bdog);

        menu_panel.setBorder(BorderFactory.createTitledBorder("메뉴"));
        menu_panel.setBackground(Color.white);
        add(menu_panel, BorderLayout.NORTH);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("애니메이션 프로그램");
        setSize(990,540);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String args[]){
        new Main();
    }
}