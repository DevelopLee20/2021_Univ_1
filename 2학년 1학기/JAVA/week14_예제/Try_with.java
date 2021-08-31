import java.io.FileReader;
import java.io.IOException;

public class Try_with {
    public static void main(String args[]) throws Exception {
        try (FileReader fr = new FileReader("test.txt")){
            int ch;
            while((ch = fr.read()) != -1){
                System.out.print((char) ch);
            }
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
