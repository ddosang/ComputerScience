import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class Week14_1 {
	public static void main(String[] args) {

		MyFrame f = new MyFrame(); //frame �ν��Ͻ� ����
	}
}
class MyFrame extends JFrame{
	JPanel panel = new JPanel();
	JButton button = new JButton("Click!");
	
	public MyFrame() {
		setTitle("�� ��ƺ�~��!"); //title ����
		setSize(300,300); //ũ�� ����
		setResizable(false); //ũ�� ���ٲ�
		setDefaultCloseOperation(EXIT_ON_CLOSE); //â ������ ��������
		setVisible(true); //���̵���
		
		panel.add(button);//�гο� ��ư �߰�
		button.addMouseListener(new myMouseEvent()); //��ư�� ���콺������ ����
		add(panel);
	}
	
	class myMouseEvent extends MouseAdapter{
		int x,y;
		
		public void mouseEntered(MouseEvent e) {
			button.setLocation(100,100); //��ư ��ġ ����
			x = (int)(Math.random()*250);
			y = (int)(Math.random()*250); //x,y��ǥ ��������
			
			if((x - e.getX())<=50 && (y - e.getY())<=50){
				mouseClicked(e);
			}//������ ���� ��������
			else{
				button.setLocation(x,y);
				System.out.println("x="+x+",\ty="+y);
			}//������ ��ġ�� ������
		}
		public void mouseClicked(MouseEvent e) {
			System.out.println("��,,, ������ �Ф�");
		}//����
	}
}

