import java.util.Scanner;

class Game{
	Scanner kb = new Scanner(System.in);
	private int input, com;
	public void start() {
		System.out.println("가위바위보게임을 시작합니다.");
	}//게임 시작
	public void input() {
		try{
			System.out.println("당신의 선택은?");
			System.out.println("가위(1) 바위(2) 보(3)");
			input = kb.nextInt();
			if(input < 1 || input > 3)
				throw new OutOfBoundaryException("범위가 잘못되었습니다.");
			
			com = (int)(Math.random()*3)+1;
			if(com == 1)
				System.out.println("컴퓨터는 가위를 냈습니다.");
			else if(com == 2)
				System.out.println("컴퓨터는 바위를 냈습니다.");
			else if(com == 3)
				System.out.println("컴퓨터는 보를 냈습니다.");
		}catch(OutOfBoundaryException oe){
			System.out.println(oe.getMessage());
			System.out.println("");
		}
	}//사용자에게서 가위 바위 보를 입력받고 범위를 벗어나면 예외 처리
	//컴퓨터가 낸 값을 보여줌.
	public int compare() {
		int a = 0;
		if(1<=input && input<=3){
		if(input == com)
			a = 1;
		else if(input+1 == com) //컴퓨터  이김
			a = 2;
		else if(input-2 == com) //컴퓨터 이김
			a = 2;
		else if(input-1 == com) //당신 이김
			a = 3;
		else if(input+2 == com) //당신 이김
			a = 3;
		}		return a;
	}
	public void writeOutput() {
		if(compare()==1){
			System.out.println("비김");
			System.out.println("");}
		else if(compare()==2){
			System.out.println("컴퓨터 승");
			System.out.println("");}
		else if(compare()==3){
			System.out.println("당신 승");
			System.out.println("");}
	}//비교한 결과를 가져와서 1이면 비김 2면 컴퓨터 승 3이면 당신 승을 출력해준다.
}
public class Week10_2 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		Game g = new Game();
		int i = 0, j = 0;
		
		g.start();
		while(i<3 && j<3){
			g.input();
			if(g.compare()==3) i++; //사용자가 이기면 i 증가
			else if(g.compare()==2) j++;//컴퓨터가 이기면 j 증가
			g.writeOutput();	
		}//둘중 하나가 3이 되면 중단.
		if(i==3)
			System.out.println("당신이 이겼습니다.");
		if(j==3)
			System.out.println("컴퓨터가 이겼습니다.");
		System.out.println("게임을 종료합니다.");
	}
}
class OutOfBoundaryException extends Exception{
	OutOfBoundaryException(String msg) {
		super(msg);
	}
}//범위를 벗어난 예외 사용자 정의