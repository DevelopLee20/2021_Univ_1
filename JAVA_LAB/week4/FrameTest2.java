package JAVA_LAB.week4;
import javax.swing.*;
import java.lang.Math;

public class FrameTest2 {
    public static void main(String args[]){
        int a = 30; int b = 30;
        JFrame f = new JFrame("Frame Test");
        f.setSize(300,200);
        f.setLocation(a,20);
        f.setVisible(true);

        JFrame fm = new JFrame("Frame Test");
        fm.setSize(300,200);
        fm.setLocation(b,300);
        fm.setVisible(true);

        while(a < 1600 || b < 1600){
            a = a + (int)(Math.random() * 5);
            b = b + (int)(Math.random() * 5);
            f.setLocation(a,20);
            fm.setLocation(b,300);
        }

        if ( a >= 1600 )
            System.out.println("No.1 Win!");
        else
            System.out.println("No.2 Win!");
    }
}
