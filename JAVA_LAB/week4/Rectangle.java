// 2번 문제

package JAVA_LAB.week4;

public class Rectangle {
    // 클래스 내부에서만 사용 가능한 private 변수를 선언한다.
    private int x,y,w,h;

    // 생성자를 생성
    public Rectangle(int x1, int y1, int w1, int h1){
        x = x1;
        y = y1;
        w = w1;
        h = h1;
    }

    // getter 생성
    public int getterx(){ return x; }
    public int gettery(){ return y; }
    public int getterw(){ return w; }
    public int getterh(){ return h; }

    // setter 생성
    public void setterx(int x){ this.x = x; }
    public void settery(int y){ this.y = y; }
    public void setterw(int w){ this.w = w; }
    public void setterh(int h){ this.h = h; }

    // 넓이 값을 리턴한다.
    int getArea(){ return w*h; }
    // 높이와 넓이를 출력함
    void print(){ System.out.printf("(%d,%d) 높이: %d 너비: %d ",x,y,w,h); }
}