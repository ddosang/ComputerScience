import java.awt.*;
import javax.swing.*;


class MyFrame2 extends JFrame{
	public MyFrame2() {
		setSize(350,200); 
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Student Information");
		setLayout(new BorderLayout());
		
		JPanel panel = new JPanel(); //Panel �ν��Ͻ� ����
		JLabel label = new JLabel("STUDENT INFORMATION"); //Label �ν��Ͻ� ����
		
		panel.add(label); //label�� panel�� �߰�
		add(panel, BorderLayout.NORTH);//panel�� �������̾ƿ� ������ �߰�
		pack();
		
		JPanel p = new JPanel(new GridLayout(5,2));//�г� p�� girdlayout���� ����
		
		JLabel label1 = new JLabel("NAME");
		JTextField field1 = new JTextField();//�̸��� ĭ
		
		JPanel p1 = new JPanel();
		JLabel label2 = new JLabel("GENDER");
		JRadioButton rb1 = new JRadioButton("Male");
		JRadioButton rb2 = new JRadioButton("Female");
		rb2.isSelected();
		p1.add(label2);
		p1.add(rb1);
		p1.add(rb2); //������ ĭ. 3���� �ѹ��� �������� ���ο� �г�p1 ���� p�гο� �߰��ع���
		
		JLabel label3 = new JLabel("ID");
		JTextField field2 = new JTextField(); //ID�� ĭ
		
		JLabel label4 = new JLabel("DEPARTMENT");
		JTextField field3 = new JTextField(); //�а��� ĭ
		
		p.add(label1);
		p.add(field1);
		p.add(label2);
		p.add(p1);
		p.add(label3);
		p.add(field2);
		p.add(label4);
		p.add(field3);//p�� ������Ʈ �߰�
		
		
		ButtonGroup bg = new ButtonGroup();
		bg.add(rb1);
		bg.add(rb2); //��ư�� �ϳ����� ������ �׷����� �������
		
		
		add(p, BorderLayout.CENTER); //p�� ���Ϳ� �߰�
		pack();
		
		JPanel p2 = new JPanel(new FlowLayout(FlowLayout.CENTER));
		JButton button1 = new JButton("Save");
		JButton button2 = new JButton("Cancel");
		p.add(button1);
		p.add(button2); //��ư �ΰ��� �������� ���
		
		add(p2, BorderLayout.SOUTH); //p2 �г��� �� �ؿ� �߰�
		pack();
		
		setVisible(true);	//���̰�
}
}
public class Week13_2 {
	public static void main(String[] args) {
		
		MyFrame2 f = new MyFrame2();
	}
}


