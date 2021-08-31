import java.io.*;
import javax.swing.*;

// 메인 클래스는 JFrame을 상속 받음
public class Main extends JFrame{

    // File_Class 클래스
    // 암호화와 복호화에 필요한 key 값과 파일명을 가지고 있음
    class File_Class{ 

        int key = 40; // XOR 암호화 키값
        String name1 = "";
        String name2 = "";

        // 파일명 저장
        public File_Class(String name1, String name2){
            this.name1 = name1;
            this.name2 = name2;
        }
    }

    // 암호화 클래스 Encry
    class Encry extends File_Class{

        // 파일의 이름을 저장한다.
        public Encry(String name1, String name2){
            // super 키워드로 부모 생성자를 사용한다.
            super(name1, name2);
        }

        // 파일 2개를 받아서 value 값으로 XOR로 암호화 한다.
        public void Encryption() throws IOException{

            // BufferedReader로 일고, PrintWriter로 쓴다.
            try(BufferedReader input = new BufferedReader(new FileReader(super.name1));
            PrintWriter output = new PrintWriter(super.name2)){

                int value;

                // 하나씩 바이트를 불러서 암호화
                while((value = input.read()) != -1){
                    value = value ^ super.key;
                    output.write(value);
                }
                output.close();
            }
        }
    }

    // 파일 2개를 받아서 value 값과 XOR로 복호화 한다.
    class Decry extends File_Class{

        // 파일의 이름을 저장한다.
        public Decry(String name1, String name2){
            // super 키워드로 부모 생성자를 사용한다.
            super(name1, name2);
        }

        // 파일 2개를 받아서 value 값으로 XOR로 복호화 한다.
        public void Decryption() throws IOException{

            // BufferedReader로 일고, PrintWriter로 쓴다.
            try(BufferedReader input = new BufferedReader(new FileReader(super.name1));
            PrintWriter output = new PrintWriter(super.name2)){

                int value;

                // 하나씩 바이트를 불러서 암호화
                while((value = input.read()) != -1){
                    value = value ^ super.key;
                    output.write(value);
                }
                output.close();

            } catch(IOException e){
                e.printStackTrace();
            }
        }
    }

    // 라벨 객체 생성
    JLabel text_1 = new JLabel("입력 파일명");
    JLabel text_2 = new JLabel("출력 파일명");

    // 텍스트필드 객체 생성
    JTextField field_1 = new JTextField(10);
    JTextField field_2 = new JTextField(10);
    JTextField field_3 = new JTextField(23);

    // 버튼 객체 생성
    JButton button_1 = new JButton("암호화");
    JButton button_2 = new JButton("복호화");
    
    // 판넬 객체 생성
    JPanel panel_1 = new JPanel();
    JPanel panel_2 = new JPanel();
    JPanel panel_3 = new JPanel();

    public Main(){

        // 암호화 버튼을 누르면 작동
        button_1.addActionListener(e ->{

            // 파일명 텍스트 필드에서 불러오기
            String name1 = field_1.getText();
            String name2 = field_2.getText();

            field_3.setText("");

            try { // 암호화 객체 생성
                Encry file = new Encry(name1, name2);
                file.Encryption();

            } catch (IOException e1) {
                e1.printStackTrace();
            }

            field_1.setText(""); // 텍스트 필드 초기화
            field_2.setText(""); // 텍스트 필드 초기화
            field_3.setText("암호화에 성공했습니다."); // 암호화 성공 문장 출력
        });

        // 복호화 버튼을 누르면 작동
        button_2.addActionListener(e ->{

            // 파일명 텍스트 필드에서 불러오기
            String name1 = field_1.getText();
            String name2 = field_2.getText();

            field_3.setText("");

            try { // 복호화 객체 생성
                Decry file = new Decry(name1, name2);
                file.Decryption();

            } catch (IOException e1) {
                e1.printStackTrace();
            }

            field_1.setText(""); // 텍스트 필드 초기화
            field_2.setText(""); // 텍스트 필드 초기화
            field_3.setText("복호화에 성공했습니다."); // 복호화 성공 문장 출력
        });

        // 화면에 모든 컴포넌트 추가
        panel_1.add(text_1);
        panel_1.add(field_1);
        panel_1.add(button_1);

        panel_2.add(text_2);
        panel_2.add(field_2);
        panel_2.add(button_2);

        panel_3.add(panel_1);
        panel_3.add(panel_2);

        field_3.setEnabled(false);
        panel_3.add(field_3);

        add(panel_3);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
        setTitle("XOR 암호화 프로그램"); // 윈도우창 제목 설정
        setSize(340,170); // 윈도우창 사이즈 설정
        setVisible(true); // 윈도우창 보이게 설정
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프로세스 초기화
    }

    public static void main(String args[]){
        new Main();
    }
}