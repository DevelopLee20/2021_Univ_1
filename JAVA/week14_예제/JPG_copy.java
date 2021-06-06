import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class JPG_copy {
    public static void main(String args[]) throws IOException{
        String inputFileName = "";
        String outputFileName = "";

        try(InputStream InputStream = new FileInputStream(inputFileName);
        OutputStream outputStream = new FileOutputStream(outputFileName)){
            int c;
            while((c = InputStream.read()) != -1){
                outputStream.write(c);
            }
        }
    }
}
