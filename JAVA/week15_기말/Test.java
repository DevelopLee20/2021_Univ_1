addMouseMotionListener(new MouseMotionAdapter(){
    public void mouseDragged(MouseEvent e){
        if(event.getSource() == bcat){
            cat.site_save(e.getX(), e.getY());
            System.out.printf("cat X: %d Y: %d\n",e.getX(), e.getY());
        }

        if(event.getSource() == bper){
            per.site_save(e.getX(), e.getY());
            System.out.printf("per X: %d Y: %d\n",e.getX(), e.getY());
        }

        if(event.getSource() == bdog){
            dog.site_save(e.getX(), e.getY());
            System.out.printf("dog X: %d Y: %d\n",e.getX(), e.getY());
        }
    }
});

String name = "";

if(event.getSource() == bcat){
    name = "bcat";
}
if(event.getSource() == bper){
    name = "bper";
}
if(event.getSource() == bdog){
    name = "bdog";
}

public void mouse
name.site_save(e.getX(), e.getY());

class personalFrame {
    JTextField totalIncome = new JTextField(10);
    private JFrame frame3 = new JFrame("Personal Tax Calculator");
    JButton Calculate = new JButton("Calculate");
     JRadioButton residentTax = new JRadioButton("Resident Tax");
     JRadioButton nonresidentTax = new JRadioButton("Working Tax");
     JRadioButton workingTax = new JRadioButton("Non-working Tax");
    public personalFrame() {
        frame3.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame3.setSize(300, 100);
        frame3.setVisible(true);
        frame3.setLayout(new FlowLayout());
        frame3.add(new JLabel("Total Income "));
        frame3.add(totalIncome);
        frame3.add(Calculate);
        frame3.add(residentTax);
        frame3.add(nonresidentTax);
        frame3.add(workingTax);

        Calculate.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String Income = totalIncome.getText();
                Double totalIncome = Double.parseDouble(Income);
                double expenseTax = 0;
                double totalTax = totalIncome - expenseTax;
                String Tax = String.valueOf(totalTax);
                JOptionPane.showMessageDialog(null, "Tax payable is A$" + Tax, "Total tax", JOptionPane.INFORMATION_MESSAGE);
            }
        });
           residentTax.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ie){
                double expenseTax = 1000;
            }
        });
           nonresidentTax.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ie){
                 double expenseTax = 1500;
            }
        });
           workingTax.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ie){
                 double expenseTax = 2000;
            }
        });
    }
}

public class Test{
    public static void main(String args[]){
        new personalFrame();
    }
}