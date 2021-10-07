import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Week14_2 {
	public static void main(String[] args) {
		
		MyFrame f = new MyFrame();
	}
}

class MyFrame extends JFrame {
	JPanel p = new JPanel(),p1 = new JPanel(), p2 = new JPanel(), p3 = new JPanel() ;
	JTextField t1 = new JTextField(5), t2 = new JTextField(5), t3 = new JTextField(5);
	JLabel l1 = new JLabel("+"), l2 = new JLabel("="), l3 = new JLabel();
	JButton b1 = new JButton("Confirm"), b2 = new JButton("New");

	public MyFrame() {
		setTitle("Plus Test"); //title 설정
		setSize(300,200);//크기 설정
		setDefaultCloseOperation(EXIT_ON_CLOSE); //닫으면 꺼지도록
		
		setLayout(new BorderLayout());//layout 설정
		
		t1.setHorizontalAlignment(JTextField.RIGHT);
		t2.setHorizontalAlignment(JTextField.RIGHT);
		t3.setHorizontalAlignment(JTextField.RIGHT);//textfield 안의 글씨 오른쪽 정렬
		p1.add(t1);
		p1.add(l1);
		p1.add(t2);
		p1.add(l2);
		p1.add(t3);//네모 + 네모 = 네모 로 패널에 추가
		
		add(p1, BorderLayout.NORTH);//p1을 맨위에 넣는다.
		
		b1.addActionListener(new MyListener());
		b2.addActionListener(new MyListener());//actionlistener 붙임
		
		p2.add(b1);
		p2.add(b2);//버튼 p2에 추가
		
		add(p2, BorderLayout.CENTER);//p2 가운데에 추가
		
		p3.add(l3); //p3에 l3 넣음
		add(p3, BorderLayout.SOUTH); //p3 맨밑에 추가
		
		setVisible(true); //보이게
	}
		
		
	private class MyListener implements ActionListener{		
		public void actionPerformed(ActionEvent e1) {
			if(e1.getSource() == b1){//b1 누르면
				try{
					int n1 = Integer.parseInt(t1.getText()); //exception 발생 가능
					int n2 = Integer.parseInt(t2.getText()); //exception 발생 가능
					int n3 = n1+n2;
					String str = Integer.toString(n3);
					t3.setText(str);
					l3.setText("You got the result.");
				}//예외 발생시  catch 하도록 설정
				catch(NumberFormatException e){
					t1.setText(null);
					t2.setText(null);
					t3.setText(null);
					l3.setText("Wrong input. Try again.");
				}//예외 발생시 수행할 것
			}else if(e1.getSource() == b2){ //b2 누르면
				t1.setText(null);
				t2.setText(null);
				t3.setText(null);
				l3.setText("Try new data.");
			}
		}
	}
}
	
