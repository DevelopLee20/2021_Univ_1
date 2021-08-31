import java.io.*;

public class Main1 {
    // 오류입출력을 사용할 throws IOException
    public static void main(String args[]) throws IOException{ 

        // 파일 열기를 시도
        try(BufferedReader input = new BufferedReader(new FileReader("txt_file/input.txt"));
        PrintWriter output = new PrintWriter(new FileWriter("txt_file/output.txt"))){

            int ch; // 바이트 단위로 저장할 변수

            while((ch = input.read()) != -1){ // -1이면 파일의 끝
                if(Character.isLowerCase(ch)){ // 소문자 일 경우
                    ch = Character.toUpperCase(ch); // 대문자로 변경
                }
                output.write(ch); // PrintWriter로 연 파일에 쓰기
            }
        
        // 파일 열기 실패시(IOException Error) 오류 문장 출력 
        } catch(IOException e){
            e.printStackTrace();
        }
    }
}
