import java.awt.*;
import javax.swing.*;


class MyFrame2 extends JFrame{
	public MyFrame2() {
		setSize(350,200); 
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Student Information");
		setLayout(new BorderLayout());
		
		JPanel panel = new JPanel(); //Panel 인스턴스 만듬
		JLabel label = new JLabel("STUDENT INFORMATION"); //Label 인스턴스 만듬
		
		panel.add(label); //label을 panel에 추가
		add(panel, BorderLayout.NORTH);//panel을 보더레이아웃 맨위에 추가
		pack();
		
		JPanel p = new JPanel(new GridLayout(5,2));//패널 p를 girdlayout으로 설정
		
		JLabel label1 = new JLabel("NAME");
		JTextField field1 = new JTextField();//이름과 칸
		
		JPanel p1 = new JPanel();
		JLabel label2 = new JLabel("GENDER");
		JRadioButton rb1 = new JRadioButton("Male");
		JRadioButton rb2 = new JRadioButton("Female");
		rb2.isSelected();
		p1.add(label2);
		p1.add(rb1);
		p1.add(rb2); //성별과 칸. 3개를 한번에 넣으려고 새로운 패널p1 만들어서 p패널에 추가해버림
		
		JLabel label3 = new JLabel("ID");
		JTextField field2 = new JTextField(); //ID와 칸
		
		JLabel label4 = new JLabel("DEPARTMENT");
		JTextField field3 = new JTextField(); //학과와 칸
		
		p.add(label1);
		p.add(field1);
		p.add(label2);
		p.add(p1);
		p.add(label3);
		p.add(field2);
		p.add(label4);
		p.add(field3);//p에 컴포넌트 추가
		
		
		ButtonGroup bg = new ButtonGroup();
		bg.add(rb1);
		bg.add(rb2); //버튼이 하나씩만 눌리게 그룹으로 만들어줌
		
		
		add(p, BorderLayout.CENTER); //p를 센터에 추가
		pack();
		
		JPanel p2 = new JPanel(new FlowLayout(FlowLayout.CENTER));
		JButton button1 = new JButton("Save");
		JButton button2 = new JButton("Cancel");
		p.add(button1);
		p.add(button2); //버튼 두개가 나오도록 출력
		
		add(p2, BorderLayout.SOUTH); //p2 패널을 맨 밑에 추가
		pack();
		
		setVisible(true);	//보이게
}
}
public class Week13_2 {
	public static void main(String[] args) {
		
		MyFrame2 f = new MyFrame2();
	}
}


