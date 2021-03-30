// 3번 문제

package JAVA_LAB.week4;

public class Date {
    private int year, month, day;

    public Date(int year1, int month1, int day1){
        year = year1;
        month = month1;
        day = day1;
    }

    public int getterY(){ return year; }
    public int getterM(){ return month; }
    public int getterD(){ return day; }

    public void setterY(int year){ this.year = year; }
    public void setterM(int month){ this.month = month; }
    public void setterD(int day){ this.day = day; }

    void print1(){ System.out.printf("%d.%d.%d\n",year, month, day); }
    void print2(){
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
        Date dt = new Date(2021, 3, 31);
        dt.print1();
        dt.print2();
    }
}