import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class GraphFrame extends JFrame implements ActionListener{
	JPanel p1 = new JPanel();
	JLabel l1 = new JLabel("Kor"), l2 = new JLabel("Eng"), l3 = new JLabel("Math");
	JTextField t1 = new JTextField(4),  t2 = new JTextField(4),  t3 = new JTextField(4);
	JButton b = new JButton("Show Graph");
	GraphPanel p = new GraphPanel();
	int kor = 0, eng = 0, math = 0;
	String msg; //â�� ���� �͵�� ���� �͵��� �����ϱ� ���� ���� ����
	
	GraphFrame(){
		setSize(500,400);//size ����
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //â�� ������ �������� ����
		setTitle("Show Graph"); //title ����
		setLayout(new BorderLayout()); //layout ����
		setVisible(true); //���̵���
		
		add(p, BorderLayout.CENTER); //GraphPanel p�� ���Ϳ� �ִ´�

		b.addActionListener(this); //�׼Ǹ����� ����
		
		p1.add(l1);
		p1.add(t1);
		p1.add(l2);
		p1.add(t2);
		p1.add(l3);
		p1.add(t3);
		p1.add(b);
		add(p1, BorderLayout.SOUTH); //p1�� ���� �ִ�ĭ�� ��ư �ְ� ���̾ƿ� �ؿ� ����
	}
	
	class GraphPanel extends JPanel{
		
		public void paint(Graphics g) {
			g.setColor(Color.white);
			g.fillRect(0,0,500,400);
			g.setColor(Color.black);
			g.drawString("100", 70, 70);
			g.drawString("90", 70, 90);
			g.drawString("80", 70, 110);
			g.drawString("70", 70, 130);
			g.drawString("60", 70, 150);
			g.drawString("50", 70, 170);
			g.drawString("40", 70, 190);
			g.drawString("30", 70, 210);
			g.drawString("20", 70, 230);
			g.drawString("10", 70, 250);
			//���� ���� �׸�
			
			g.drawLine(100, 70, 400, 70);
			g.drawLine(100, 90, 400, 90);
			g.drawLine(100, 110, 400, 110);
			g.drawLine(100, 130, 400, 130);
			g.drawLine(100, 150, 400, 150);
			g.drawLine(100, 170, 400, 170);
			g.drawLine(100, 190, 400, 190);
			g.drawLine(100, 210, 400, 210);
			g.drawLine(100, 230, 400, 230);
			g.drawLine(100, 250, 400, 250);
			g.drawLine(100, 270, 400, 270);
			g.drawLine(100, 60, 100, 270);
			//�� 11�� �׸�
			
			g.drawString("KOR", 160, 290);
			g.drawString("ENG", 240, 290);
			g.drawString("MATH", 320, 290);
			//���� �� �׸�
			try {
				if(msg == "Wrong input") {
					throw new Exception(msg);
				}//msg �� wrong input�̸� ���ܸ� ����
				if(!(kor<0 || kor>100 || eng<0 || eng>100 || math<0 || math>100)) {
					g.setColor(Color.RED);
					g.drawRect(169,270-2*kor,8,2*kor);
					g.fillRect(169,270-2*kor,8,2*kor);
					g.drawRect(248,270-2*eng,8,2*eng);
					g.fillRect(248,270-2*eng,8,2*eng);
					g.drawRect(334,270-2*math,8,2*math);
					g.fillRect(334,270-2*math,8,2*math);
				}//���� �ȿ� ���� ���� �׷��� �׸�
				else {
					msg = "Wrong input";
					throw new Exception(msg);
				}//���� �ۿ� ������ ���� ����
			}catch(Exception e) {
				g.drawString(e.getMessage(),225,40);
			}//���� ��Ƽ� ���� �����
		}
	}

	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == b) {
			try{//��ư ������ kor, eng, math �����ϰ� repaint ȣ��
				msg = null;
				kor = Integer.parseInt(t1.getText());
				eng = Integer.parseInt(t2.getText());
				math = Integer.parseInt(t3.getText());
				repaint();
			}catch(Exception e1) {
				msg = "Wrong input";
				repaint();
			}//exception �߻��� repaint ȣ��
		}
	}
}



public class HW2_4 {
	public static void main(String args[]) {
		
		GraphFrame g = new GraphFrame(); //GraphFrame �ν��Ͻ� ����
	}
}
