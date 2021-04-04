// 패키지명 작성
package JAVA_LAB.week5;
import java.util.*;

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

    // 두 개의 Complex 생성된 객체를 받아서 두 객체의 속성값을 더해준다.
    Complex add(Complex o1, Complex o2){
        return new Complex(o1.real+o2.real,o1.imag + o2.imag);
    }
}

public class Lab4 {
    public static void main(String agrs[]){

        // Complex 객체를 생성
        Scanner sc = new Scanner(System.in);

        int real1 = sc.nextInt();
        int imag1 = sc.nextInt();
        int real2 = sc.nextInt();
        int imag2 = sc.nextInt();

        sc.close();

        Complex cp1 = new Complex(real1,imag1);
        Complex cp2 = new Complex(real2,imag2);

        // 두 객체를 더한 후 객체를 리턴한다
        Complex cp3 = cp1.add(cp1,cp2);
        
        // 생성된 cp3 객체에 두 객체의 속성값의 합을 구해준다

        // cp3 객체의 속성 값을 출력함
        cp3.Print();
        
    }
}
