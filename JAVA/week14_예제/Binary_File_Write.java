import java.io.FileOutputStream;
import java.io.IOException;

public class Binary_File_Write {
    public static void main(String args[]){
        byte list[] = { 10, 20, 30, 40, 50, 60 };
        try(FileOutputStream out = new FileOutputStream("test.bin")){
            for(byte b : list){
                out.write(b);
            }
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
