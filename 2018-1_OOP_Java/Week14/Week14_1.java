import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class Week14_1 {
	public static void main(String[] args) {

		MyFrame f = new MyFrame(); //frame 인스턴스 생성
	}
}
class MyFrame extends JFrame{
	JPanel panel = new JPanel();
	JButton button = new JButton("Click!");
	
	public MyFrame() {
		setTitle("나 잡아봐~라!"); //title 설정
		setSize(300,300); //크기 설정
		setResizable(false); //크기 못바꿈
		setDefaultCloseOperation(EXIT_ON_CLOSE); //창 닫으면 꺼지도록
		setVisible(true); //보이도록
		
		panel.add(button);//패널에 버튼 추가
		button.addMouseListener(new myMouseEvent()); //버튼에 마우스리스너 붙임
		add(panel);
	}
	
	class myMouseEvent extends MouseAdapter{
		int x,y;
		
		public void mouseEntered(MouseEvent e) {
			button.setLocation(100,100); //버튼 위치 설정
			x = (int)(Math.random()*250);
			y = (int)(Math.random()*250); //x,y좌표 랜덤생성
			
			if((x - e.getX())<=50 && (y - e.getY())<=50){
				mouseClicked(e);
			}//범위에 들어가면 잡히도록
			else{
				button.setLocation(x,y);
				System.out.println("x="+x+",\ty="+y);
			}//랜덤한 위치로 도망감
		}
		public void mouseClicked(MouseEvent e) {
			System.out.println("윽,,, 잡혔다 ㅠㅠ");
		}//잡힘
	}
}

