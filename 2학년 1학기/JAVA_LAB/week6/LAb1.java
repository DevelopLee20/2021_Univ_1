// Circle 클래스 생성
class Circle{

    // Circle 클래스의 멤버변수 선언
    double radius = 1.0;
    String color = "red";

    // radius 를 지정
    public Circle(double radius){
        this.radius = radius;
    }

    // 메소드오버리딩으로 매개변수에 따라서 다른 생성자 메소드가 사용된다.
    public Circle(double radius, String color){
        this.radius = radius;
        this.color = color;
    }

    // radius의 getter
    public double getRadius() {
        return radius;
    }

    // color의 getter
    public String getColor(){
        return color;
    }

    // radius의 setter
    public void setRadius(double radius) {
        this.radius = radius;
    }

    // color의 setter
    public void setColor(String color) {
        this.color = color;
    }

    // 3.14를 곱해서 전체 면적을 출력해준다. (파이 * 반지름의 제곱 = 넓이)
    public double getArea(){
        return 3.14*radius*radius;
    }

    // 오버라이딩으로 부모메소드의 toString을 새로 사용한다.
	@Override
	public String toString() {
		return "Circle [radius=" + radius + ", color=" + color + "]";
	}
}

// Circle 클래스를 상속받는 피자 클래스
class Pizza extends Circle{

    // Pizza 클래스의 멤버변수 선언
    String type;
    int price;

    // Pizza 클래스의 생성자 메소드
    public Pizza(double radius, String color, String type, int price){
        // super 키워드에 의해서 radius와 color의 입력은 부모메소드가 한다.
        super(radius, color);
        this.type = type;
        this.price = price;
    }

    // 메소드오버리딩으로 매개변수에 따라서 다른 생성자 메소드가 실행된다.
    public Pizza(double radius, String type, int price){
        // super 키워드에 의해서 radius의 값은 부모메소드가 받는다.
        super(radius);
        this.type = type;
        this.price = price;
    }

    // 메소드 오버라이딩으로 부모메소드의 toString 메소드를 새로 작성한다.
    @Override
	public String toString() {
		return "Pizza [type=" + type + ", price=" + price + ", radius=" + radius + ", color=" + color + "]";
	}

    public String toString2(){
        return " Area: " + getArea();
    }
}

// 메인 클래스
public class LAb1{
    public static void main(String args[]){

        // 총 5개의 Pizza 객체를 생성한다. 이때 매개변수는 다 다르다.
        Pizza pizza1 = new Pizza(50,"blue", "Combination", 10);
        Pizza pizza2 = new Pizza(40, "Combination", 20);
        Pizza pizza3 = new Pizza(30,"white", "Cheese", 30);
        Pizza pizza4 = new Pizza(20, "Cheese", 40);
        Pizza pizza5 = new Pizza(10, "Normal", 50);

        // toString을 통한 출력 이후에, 가격을 출력해준다.
        System.out.print(pizza1.toString());
        System.out.println(pizza1.toString2());

        System.out.print(pizza2.toString());
        System.out.println(pizza2.toString2());

        System.out.print(pizza3.toString());
        System.out.println(pizza3.toString2());

        System.out.print(pizza4.toString());
        System.out.println(pizza4.toString2());

        System.out.print(pizza5.toString());
        System.out.println(pizza5.toString2());

    }
}