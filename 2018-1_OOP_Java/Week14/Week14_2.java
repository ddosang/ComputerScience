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
		setTitle("Plus Test"); //title ����
		setSize(300,200);//ũ�� ����
		setDefaultCloseOperation(EXIT_ON_CLOSE); //������ ��������
		
		setLayout(new BorderLayout());//layout ����
		
		t1.setHorizontalAlignment(JTextField.RIGHT);
		t2.setHorizontalAlignment(JTextField.RIGHT);
		t3.setHorizontalAlignment(JTextField.RIGHT);//textfield ���� �۾� ������ ����
		p1.add(t1);
		p1.add(l1);
		p1.add(t2);
		p1.add(l2);
		p1.add(t3);//�׸� + �׸� = �׸� �� �гο� �߰�
		
		add(p1, BorderLayout.NORTH);//p1�� ������ �ִ´�.
		
		b1.addActionListener(new MyListener());
		b2.addActionListener(new MyListener());//actionlistener ����
		
		p2.add(b1);
		p2.add(b2);//��ư p2�� �߰�
		
		add(p2, BorderLayout.CENTER);//p2 ����� �߰�
		
		p3.add(l3); //p3�� l3 ����
		add(p3, BorderLayout.SOUTH); //p3 �ǹؿ� �߰�
		
		setVisible(true); //���̰�
	}
		
		
	private class MyListener implements ActionListener{		
		public void actionPerformed(ActionEvent e1) {
			if(e1.getSource() == b1){//b1 ������
				try{
					int n1 = Integer.parseInt(t1.getText()); //exception �߻� ����
					int n2 = Integer.parseInt(t2.getText()); //exception �߻� ����
					int n3 = n1+n2;
					String str = Integer.toString(n3);
					t3.setText(str);
					l3.setText("You got the result.");
				}//���� �߻���  catch �ϵ��� ����
				catch(NumberFormatException e){
					t1.setText(null);
					t2.setText(null);
					t3.setText(null);
					l3.setText("Wrong input. Try again.");
				}//���� �߻��� ������ ��
			}else if(e1.getSource() == b2){ //b2 ������
				t1.setText(null);
				t2.setText(null);
				t3.setText(null);
				l3.setText("Try new data.");
			}
		}
	}
}
	
