import java.awt.*;
import javax.swing.*;

class MyFrame extends JFrame{
	public MyFrame() {
		setSize(300,200);//size ����
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //â�� ������ �������� ����
		setTitle("Calculator"); //title ����
		setLayout(new BorderLayout()); //layout ����
		
		JTextField field = new JTextField();
		field.setHorizontalAlignment(JTextField.RIGHT);
		add(field, BorderLayout.NORTH);
		pack(); //field�� �������̾ƿ� ������ �ø�
		
		JPanel panel = new JPanel();
		panel.setLayout(new GridLayout(5,4)); //grid layout�� �г��� ���̾ƿ����� ����
		
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
		makeButton("+", panel); //��ư�� �����
		add(panel); // �г��� �߰��Ѵ�
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
		
		MyFrame f = new MyFrame(); //MyFrame �ν��Ͻ� �����.
	}	
}
