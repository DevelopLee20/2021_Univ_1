// rps 폴더에 있음을 알린다.
package rps;

// RoPaSi 클래스 선언
public class RoPaSi{

    // RoPaSi 클래스의 멤버 변수로, 가위바위보가 결정된다.
    int number;

    // 생성자로 받은 값을 그대로 this.number에 저장한다.
    public RoPaSi(int number){
        this.number = number;
    }
    
    // 메소드 오버로딩으로 매개변수에 따라서 다른 생성자가 호출된다.
    public RoPaSi(){
        this.number = (int)(Math.random()*3);
    }

    // this.number 멤버 변수를 리턴한다.
    public int getNumber(){
        return this.number;
    }

    // number의 값에 따라서 가위바위보 각각의 텍스트를 리턴한다.
    public String textReturn(){
        if (this.number == 0){
            return "가위";
        }
        else if (this.number == 1){
            return "바위";
        }
        else{
            return "보";
        }
    }
}