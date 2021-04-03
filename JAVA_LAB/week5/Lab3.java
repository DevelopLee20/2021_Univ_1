// 패키지명 작성
package JAVA_LAB.week5;

// Complex 클래스 작성
class Complex{

    // 사용할 변수 선언
    int real;
    int imag;

    // Complex 클래스의 생성자 생성
    public Complex(int real, int imag){
        this.real = real;
        this.imag = imag;
    }

    // 클래스의 속성을 출력
    void Print(){
        System.out.printf("%d+%di",real,imag);
    }
}

public class Lab3 {
    public static void main(String agrs[]){
        // Complex 객체를 cp에 생성 매개변수는 10,20
        Complex cp = new Complex(10,20);
        // 속성을 출력하는 Print() 메소드 호출
        cp.Print();
    }
}
