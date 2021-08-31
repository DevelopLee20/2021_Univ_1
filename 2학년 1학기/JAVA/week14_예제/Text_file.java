import java.io.FileReader;

public class Text_file{
    public static void main(String args[]) throws Exception{
        FileReader fr = new FileReader("test.txt");
        int ch;
        while((ch = fr.read()) != -1){
            System.out.println((char) ch);
        }
        fr.close();
    }
}