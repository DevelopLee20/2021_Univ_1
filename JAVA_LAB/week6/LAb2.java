// Person 클래스 선언
class Person{

    // Person 클래스의 멤버변수 선언
    String name;
    int id;

    // Person 클래스의 생성자 선언
    public Person(String name, int id){
        this.name = name;
        this.id = id;
    }

    // 내용을 출력해주는 메소드
    void printInfo(){
        System.out.printf("name: %s id: %d ",name,id);
    }
}

// Student 클래스는 Person 클래스를 상속 받는다.
class Student extends Person{

    // Student 클래스의 멤버 변수 선언
    double gpa;
    int credits;

    // Student 클래스의 생성자 메소드
    public Student(String name, int id, double gpa, int credits){
        // super 키워드를 사용해서 부모메소드의 생성자를 그대로 사용한다.
        super(name, id);
        this.gpa = gpa;
        this.credits = credits;
    }

    // Override를 통해서 부모메소드의 메소드를 조작한다.
    @Override
    void printInfo() {
        // super 키워드에 의해 부모메소드를 그대로 사용한 후 메소드를 수행한다.
        super.printInfo();
        System.out.printf("gpa: %lf credits: %d\n",gpa, credits);
    }
}

// Employee 클래스는 Person 클래스를 상속받는다.
class Employee extends Person{

    // Employee 클래스의 멤버변수 선언
    int salary;
    int years;

    // Employee 클래스의 생성자를 선언
    public Employee(String name, int id, int salary, int years){
        // super 키워드를 사용해서 부모메소드의 생성자를 먼저 사용한다.
        super(name, id);
        this.salary = salary;
        this.years = years;
    }

    // 오버라이딩을 통해서 부모메소드의 메소드를 수정한다.
    @Override
    void printInfo() {
        // super 키워드를 사용해서 부모메소드의 메소드를 먼저 사용한다.
        super.printInfo();
        System.out.printf("salary: %d years: %d\n",salary, years);
    }
}

// 메인 클래스
public class LAb2 {
    public static void main(String args[]){

        // 객체를 생성한다.
        Student st = new Student("steve jobs", 1, 3.9, 30);

        // Employee 객체는 배열로 생성되어서 각 요소가 객체를 가진다.
        Employee[] ep = new Employee[3];
        ep[0] = new Employee("Jeff Bezos", 2, 10000, 10);
        ep[1] = new Employee("Bill Gates", 3, 20000, 15);
        ep[2] = new Employee("steve jobs", 4, 30000, 20);

        // s1 변수는 st 객체의 name을 값으로 가진다.
        String s1 = st.name;

        for(int i=0; i<ep.length; i++){
            // s2 는 ep 객체의 배열의 name 값을 차례로 가진다.
            String s2 = ep[i].name;

            // equals를 사용해서 s1과 s2 문자열을 비교한다.
            if (s1.equals(s2)){
                ep[i].printInfo();
                break;
            }
        }
    }
}