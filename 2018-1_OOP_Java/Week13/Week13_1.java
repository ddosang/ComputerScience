import java.awt.*;
import javax.swing.*;

class MyFrame extends JFrame{
	public MyFrame() {
		setSize(300,200);//size 설정
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //창을 닫으면 꺼지도록 설정
		setTitle("Calculator"); //title 설정
		setLayout(new BorderLayout()); //layout 설정
		
		JTextField field = new JTextField();
		field.setHorizontalAlignment(JTextField.RIGHT);
		add(field, BorderLayout.NORTH);
		pack(); //field를 보더레이아웃 맨위에 올림
		
		JPanel panel = new JPanel();
		panel.setLayout(new GridLayout(5,4)); //grid layout을 패널의 레이아웃으로 설정
		
		makeButton("ON", panel);
		makeButton("AC", panel);
		makeButton("C", panel);
		makeButton("OFF", panel);
		makeButton("7", panel);
		makeButton("8", panel);
		makeButton("9", panel);
		makeButton("/", panel);
		makeButton("4", panel);
		makeButton("5", panel);
		makeButton("6", panel);
		makeButton("X", panel);
		makeButton("1", panel);
		makeButton("2", panel);
		makeButton("3", panel);
		makeButton("-", panel);
		makeButton("0", panel);
		makeButton(".", panel);
		makeButton("=", panel);
		makeButton("+", panel); //버튼을 만든다
		add(panel); // 패널을 추가한다
		pack();
		setVisible(true);
		
		
	}
	public void makeButton(String text, JPanel panel) {
		JButton button = new JButton(text);
		button.setAlignmentX(CENTER_ALIGNMENT);
		panel.add(button);
	}//make button method
}

public class Week13_1 {
	public static void main(String[] args) {
		
		MyFrame f = new MyFrame(); //MyFrame 인스턴스 만든다.
	}	
}
