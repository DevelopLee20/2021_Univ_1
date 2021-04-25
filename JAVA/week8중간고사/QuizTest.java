import java.util.*;

public class Q extends QuizItem {
    String[] choices;
    public Q(String[] prompt, String[] answer, String[] choices) {
       super(prompt, answer);
       this.choices = choices;
    }
}

public class QuizTest {

    String prompt;
    String answer;
    String choices;
    public static void main(String[] args) {
       Scanner scan = new Scanner(System.in);
       Q q = new Q(prompt, answer, choices);