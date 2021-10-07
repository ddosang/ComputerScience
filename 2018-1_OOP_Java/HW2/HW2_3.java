
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class MyFrame extends JFrame implements ActionListener{
	String str1, str2, op, button;
	int n; double d;
	JTextField field = new JTextField();
	
	public MyFrame() {
		setSize(300,200);//size 설정
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //창을 닫으면 꺼지도록 설정
		setTitle("Calculator"); //title 설정
		setLayout(new BorderLayout()); //layout 설정
		
		field.setHorizontalAlignment(JTextField.RIGHT);
		add(field, BorderLayout.NORTH);
		pack(); //field를 보더레이아웃 맨위에 올림
		
		JPanel panel = new JPanel();
		panel.setLayout(new GridLayout(5,4));// grid layout을 패널의 레이아웃으로 설정
		
		
		makeButton("7", panel);
		makeButton("8", panel);
		makeButton("9", panel);
		makeButton("/", panel);
		makeButton("4", panel);
		makeButton("5", panel);
		makeButton("6", panel);
		makeButton("*", panel);
		makeButton("1", panel);
		makeButton("2", panel);
		makeButton("3", panel);
		makeButton("-", panel);
		makeButton("New", panel);
		makeButton("0", panel);
		makeButton("=", panel);
		makeButton("+", panel); //버튼을 만든다
		add(panel);  //패널을 추가한다
		pack();
		setVisible(true);
	}//생성자 : 그림 그림
	
	public void makeButton(String text, Container target) {
		JButton button = new JButton(text);
		button.setAlignmentX(CENTER_ALIGNMENT);
		button.addActionListener(this);
		target.add(button);
	}//make button method
	
	public void actionPerformed(ActionEvent e){
		button = e.getActionCommand();
		if(e.getActionCommand().equals("New")){
			field.setText(null);
			str1 = null; str2 = null; op = null;
		}//New button 누르면 생기는 현상
		if(button.equals("0")||button.equals("1")||button.equals("2")||button.equals("3")||button.equals("4")||button.equals("5")||button.equals("6")||button.equals("7")||button.equals("8")||button.equals("9")){
			field.setText(button);
			str1 = field.getText();
		}//숫자 button 누르면 생기는 현상
		if(button.equals("+") || button.equals("-")||button.equals("*")||button.equals("/")){
			field.setText(button);
			op = field.getText();
			str2 = str1;
			str1 = null;
		}//사칙연산 button 누르면 생기는 현상
		if(button.equals("=")){
			if(op.equals("+")) {
				n = Integer.parseInt(str2) +  Integer.parseInt(str1);
				field.setText(Integer.toString(n));
			}
			else if(op.equals("-")) {
				n = Integer.parseInt(str2) -  Integer.parseInt(str1);
				field.setText(Integer.toString(n));
			}
			else if(op.equals("*")) {
				n = Integer.parseInt(str2) *  Integer.parseInt(str1);
				field.setText(Integer.toString(n));
			}
			else if(op.equals("/")) {
				d = (double)Integer.parseInt(str2) / (double)Integer.parseInt(str1);
				field.setText(Double.toString(d));
			}
		}//= button 누르면 생기는 현상
	
	}
}

	public class HW2_3 {
		public static void main(String[] args) {
				
			MyFrame f = new MyFrame(); //MyFrame 인스턴스 만든다.
		}	

	}

