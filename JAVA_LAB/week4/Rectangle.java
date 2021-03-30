// 2번 문제

package JAVA_LAB.week4;

public class Rectangle {
    private int x,y,w,h;

    public Rectangle(int x1, int y1, int w1, int h1){
        x = x1;
        y = y1;
        w = w1;
        h = h1;
    }

    public int getterx(){ return x; }
    public int gettery(){ return y; }
    public int getterw(){ return w; }
    public int getterh(){ return h; }

    public void setterx(int x){ this.x = x; }
    public void settery(int y){ this.y = y; }
    public void setterw(int w){ this.w = w; }
    public void setterh(int h){ this.h = h; }

    int getArea(){ return w*h; }
    void print(){ System.out.printf("(%d,%d) 높이: %d 너비: %d ",x,y,w,h); }
}