// 패키지명 작성
package JAVA_LAB.week5;

class Witch{
    static int younger(Dog obj){
        obj.age = obj.age - 5;
        return obj.age;
    }
}

// Dog 클래스
class Dog{
    // 정적 변수로 몇 번 객체가 생성될 때마다 값은 초기화가 되지 않는다.
    static int count = 0;

    // 이름, 나이, 색상 변수를 선언
    String name;
    int age;
    String color;

    // Dog 클래스의 생성자
    public Dog(String name, int age, String color){
        // 입력된 값이 this에 인해 Dog의 변수에 저장된다.
        this.name = name;
        this.age = age;
        this.color = color;
    }

    // count의 값을 반환해준다
    int counting(){
        return count;
    }

    // 강아지의 속성을 출력해준다
    void Printdog(){
        count++;
        System.out.printf("강아지 #%d = \"%s\", %d, \"%s\"\n",count,name,age,color);
    }
}

public class Lab2 {
    public static void main(String args[]){

        // 강아지 3마리의 객체를 생성해준다.
        Dog dog1 = new Dog("Molly",10,"brown");
        Dog dog2 = new Dog("Daisy",6,"black");
        Dog dog3 = new Dog("Bella",7,"white");

        // Witch 클래스에서 younger 메소드의 인자를 생성한 Dog 객체로 지정
        Witch.younger(dog1);
        Witch.younger(dog2);
        Witch.younger(dog3);

        // 강아지의 속성을 출력하는 메소드를 호출한다.
        dog1.Printdog();
        dog2.Printdog();
        dog3.Printdog();

        // 정적변수인 count를 출력해준다.
        System.out.printf("현재까지 생성된 강아지의 수 = %d",dog3.counting());
    }
}
