import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Line_copy {
    public static void main(String args[]){
        try(BufferedReader in = new BufferedReader(new FileReader("input.txt"));
        PrintWriter out = new PrintWriter(new FileWriter("output.txt"))){
            String line;
            while((line = in.readLine()) != null){
                out.println(line);
            }
        } catch(IOException e){
            e.printStackTrace();
        }
    }
}
