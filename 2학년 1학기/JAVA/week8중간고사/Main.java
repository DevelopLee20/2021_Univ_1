import java.util.Scanner; // 스캐너 헤더파일 임포트

class QuizItem{
    String problem;         // 문제명을 저장할 멤버 변수
    String correct_ans;     // 옳은 정답을 저장할 멤버 변수

    public QuizItem(String problem, String correct_ans){
        this.problem = problem;             // 문제명을 저장하는 생성자 부분
        this.correct_ans = correct_ans;     // 옳은 정답을 저장하는 생성자 부분
    }
}

class Multiple extends QuizItem{
    
    static int num = 1;                         // 문제 번호를 저장할 변수
    static int score = 0;                       // 점수를 저장할 변수
    String choice0, choice1, choice2, choice3;  // 4지선다를 저장할 변수
    String[] choice = new String[4];            // 4지선다를 배열로 합쳐서 저장해 사용한다

    public Multiple(String problem, String correnct_ans, String choice0, String choice1, String choice2, String choice3) {
        super(problem, correnct_ans);   // 부모클래스의 생성자 우선호출
        this.choice[0] = choice0;       // 첫번째 보기 저장
        this.choice[1] = choice1;       // 두번째 보기 저장
        this.choice[2] = choice2;       // 세번째 보기 저장
        this.choice[3] = choice3;       // 네번째 보기 저장
    }

    public boolean Answer(int cho){

        // 답의 여부를 저장할 check 변수
        boolean check = correct_ans.equals(this.choice[cho-1]);

        if(check){                                   // 답이 맞았으면
            System.out.print("맞았습니다.");          // 맞았다는 문장과
            score += 1;                              // 점수를 추가한다
        }

        System.out.println("현재점수: "+score);         // 현재 점수를 출력해준다
        System.out.println("\n");                      // 시각적으로 편하게 Enter 1회
        return check;                                  // 답의 여부를 리턴해준다
    }

    public void Print(){
        // 문제의 정보와 보기를 출력해준다.
        System.out.printf("%d번 문제\n%s\n(1) %s\n(2) %s\n(3) %s\n(4) %s\n",num++ , this.problem, this.choice[0], this.choice[1], this.choice[2], this.choice[3]);
        System.out.print("정답을 입력하세요: "); 
    }
}

public class Main{
    public static void main(String args[]){

        Multiple[] mul = new Multiple[10];      // Multiple 객체를 배열로 생성한다.
        Scanner sc = new Scanner(System.in);    // 스캐너 객체를 생성한다.

        // 문제 하나하나 총 10개를 생성한다.
        mul[0] = new Multiple("java 파일을 컴파일하면 생성되는 파일의 확장자명은?", ".class", ".class",".java",".md",".exe");
        mul[1] = new Multiple("우리가 사용하는 자바 버전은 어떤 것인가?", "Java SE", "Java EE","Java PE","Java ME","Java SE");
        mul[2] = new Multiple("자바 프로그램을 개발하는데 필요한 도구들은 모아놓은 키트를 무엇이라고 하는가?", "JDK", "JDA","JDK","JJK","SDK");
        mul[3] = new Multiple("안드로이드 애플리케이션은 ___ 언어로 개발할 수 있다, 틀린 것은?", "HTML", "코틀린","다트","자바","HTML");
        mul[4] = new Multiple("자바에서 입력을 위하여 사용하는 클래스는?", "Scanner", "Goo","Dart","Swing","Scanner");
        mul[5] = new Multiple("자바에서 나머지 연산자는?", "%", "%","*","-","+");
        mul[6] = new Multiple("자바에서 자료형은 기초형과 ___이 있다.", "참조형", "밥형","고급형","기초형","참조형");
        mul[7] = new Multiple("자바에서 이진수 앞에는 ___를 표시한다.", "0b", "0c","0a","0b","0x");
        mul[8] = new Multiple("객체들은 ___을 주고 받으면서 상호작용한다.", "메시지", "메시지","상태","밥","언어");+
        mul[9] = new Multiple("자바에서 객체를 생성하는 연산자는 ___이다.", "new", "good","new","obj","int");

        for(int i=0; i<10; i++){
            mul[i].Print();                 // 문제마다 문제 정보를 출력해준다.
            mul[i].Answer(sc.nextInt());    // 정답을 입력받아서 판단하는 Answer 메소드에 보내준다.
        }

        sc.close();     // 스캐너의 사용이 끝났으면 닫아준다.
    }
}