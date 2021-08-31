import java.io.*;

public class Main2 {

    // 예외처리 입출력을 위한 throws IOException
    public static void main(String args[]) throws IOException{

        // 파일 열기 시도
        try(FileReader in1 = new FileReader("txt_file/input1.txt");
            FileReader in2 = new FileReader("txt_file/input2.txt")){

                int ch1;                // 바이트 단위 저장
                int ch2;                // 바이트 단위 저장
                Boolean check = true;   // 파일의 같음 여부
                float count = 0;        // 전체 비교 횟수
                float correct = 0;      // 맞은 비교 횟수
                
                while(true){ // 무한 반복

                    // 파일1의 내용 읽기
                    if((ch1 = in1.read()) == -1){
                        ch1 = -1;
                    }

                    // 파일2의 내용 읽기
                    if((ch2 = in2.read()) == -1){
                        ch2 = -1;
                    }

                    // 파일1과 2 모두 읽을 내용이 없으면
                    if(ch1 == -1 && ch2 == -1){
                        break; // 반복 종료
                    }

                    count++; // 비교횟수 + 1

                    // 비교한 단어가 옳지 않으면
                    if(ch1 != ch2){
                        if(check){ // 파일이 같음을 false로 변경
                            check = false;
                        }
                    }

                    else{ // 비교한 단어가 옳으면
                        correct++; // 옳음 + 1
                    }
                }

                if(check){ // 파일이 같으면
                    System.out.println("2개의 파일이 일치합니다.");
                }
                else{ // 파일이 같지 않으면
                    System.out.println("2개의 파일이 일치하지 않습니다.");
                }

                // 정확도를 출력해준다. ( 백분율 표현을 위한 곱하기 100 )
                System.out.printf("%3.2f %% 만큼 일치합니다.", correct/count*100.0);

        // 파일 열기 실패시 오류 문장 출력
        } catch(IOException e){
            e.printStackTrace();
        }
    }
}
