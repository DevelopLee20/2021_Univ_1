// 3번 문제

package JAVA_LAB.week4;

public class Date {
    // 클래스 내부에서만 사용가능한 변수 선언
    private int year, month, day;

    // 생성자 생성
    public Date(int year1, int month1, int day1){
        year = year1;
        month = month1;
        day = day1;
    }

    // getter 생성
    public int getterY(){ return year; }
    public int getterM(){ return month; }
    public int getterD(){ return day; }

    // setter 생성
    public void setterY(int year){ this.year = year; }
    public void setterM(int month){ this.month = month; }
    public void setterD(int day){ this.day = day; }

    // print1() 의 포멧에 따라서 출력
    void print1(){ System.out.printf("%d.%d.%d\n",year, month, day); }
    // print2() 의 포멧에 따라서 출력
    void print2(){
        // switch 문의 인자를 month로 사용해서 case에 따라서 구분한다.
        switch(month){
            case 1:
                System.out.printf("Jan %d, %d", day, year);
                break;
            case 2:
                System.out.printf("Feb %d, %d", day, year);
                break;
            case 3:
                System.out.printf("Mar %d, %d", day, year);
                break;
            case 4:
                System.out.printf("Api %d, %d", day, year);
                break;
            case 5:
                System.out.printf("May %d, %d", day, year);
                break;
            case 6:
                System.out.printf("Jun %d, %d", day, year);
                break;
            case 7:
                System.out.printf("Jul %d, %d", day, year);
                break;
            case 8:
                System.out.printf("Aug %d, %d", day, year);
                break;
            case 9:
                System.out.printf("Sep %d, %d", day, year);
                break;
            case 10:
                System.out.printf("Oct %d, %d", day, year);
                break;
            case 11:
                System.out.printf("Nob %d, %d", day, year);
                break;
            case 12:
                System.out.printf("Dec %d, %d", day, year);
                break;
        }
    }

    public static void main(String args[]){
        // dt에 Date 객체를 생성한다.
        Date dt = new Date(2021, 3, 31);
        // print1 의 포멧을 따른 문장을 출력한다.
        dt.print1();
        // print2 의 포멧을 따른 문장을 출력한다.
        dt.print2();
    }
}