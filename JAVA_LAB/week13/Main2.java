import java.util.HashSet;

public class Main2 {
    public Main2(){
        HashSet<Integer> lotto = new HashSet<Integer>(6);
        int cnt = 0;

        while(cnt != 6){
            int rand = (int)(Math.random()*44+1);
            if(!lotto.contains(rand)){
                lotto.add(rand);
                cnt++;
            }
        }
        System.out.println("Lotto [set="+lotto+"]");
    }
    public static void main(String args[]){
        Main2 main = new Main2();
    }
}
