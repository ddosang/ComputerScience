import java.util.Scanner;

class Car{
	private String emg;
	private int number;
	private String car_type;
	private String req;
	
	Car(){
		this(null, 0, null, null);
	}
	Car(String emg, int number, String car_type, String req){
		this.emg = emg;
		this.number = number;
		this.car_type = car_type;
		this.req = req;
	}//생성자 정의
	
	public String getEmg(){
		return emg;
	}
	public int getNumber(){
		return number;
	}
	public String getCar_Type(){
		return car_type;
	}
	public String getReqPerson(){
		return req;
	}
	public String getStr(){
		return getEmg()+getNumber()+getCar_Type()+getReqPerson();
	}
}//Car class와 getter method 정의

class FireEngine extends Car{
	FireEngine(){
		super("Fire", 119, "FireEngine", "Firemen");
		//super 를 이용해 그 class에 해당되는 값들을 넣어 부모의 생성자를 부른다.
	}
	public String toString(){
		return getStr();
	}
}//Car class 를 상속받은 FireEngine 과 toString method overriding

class Ambulance extends Car{
	Ambulance(){
		super("Patient", 119, "Ambulance", "Doctor");
	}	
	public String toString(){
		return getStr();
	}
}//Car class 를 상속받은 Ambulance 과 toString method overriding

class PoliceCar extends Car{
	PoliceCar(){
		super("Thief", 112, "PoliceCar", "Policemen");
	}	
	public String toString(){
		return getStr();
	}
}//Car class 를 상속받은 PoliceCar 과 toString method overriding
class Emergency{
	Car cc[] = new Car[10];
	int i;
	
	void EM_Call(Car c){
		if(c instanceof FireEngine){
			FireEngine fe = (FireEngine)c;
			System.out.println("Call "+c.getNumber());
			cc[i++] =  fe;
		}//FireEngine인 경우 c를 fe에 대입하고
		//어디로 전화할지 출력하고, Car 배열 cc[i]에 fe대입 후 i를 1 증가시킴
		else if(c instanceof Ambulance){
			Ambulance am = (Ambulance)c;
			System.out.println("Call "+am.getNumber());
			cc[i++] =  am;
		}//Ambulance인 경우 c를 am에 대입
		else if(c instanceof PoliceCar){
			PoliceCar po = (PoliceCar)c;
			System.out.println("Call "+po.getNumber());
			cc[i++] = po;
		}//PoliceCar인 경우 c를 po에 대입
	}
	void EM_record(){
		System.out.printf("Emergency\tNumber\tCar_Type\tRequird\n");
		for(int j = 0; j<i ; j++)	
			System.out.printf("%s\t\t%d\t%s\t%s\n", cc[j].getEmg(), cc[j].getNumber(), cc[j].getCar_Type(), cc[j].getReqPerson());
	}//지금까지의 기록을 출력
}//Emergency 

public class Week8_2 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		
		int choice=0, i=0;
		FireEngine fe = new FireEngine();
		Ambulance am = new Ambulance();
		PoliceCar po = new PoliceCar();
		Emergency e = new Emergency();
		//class 각각 인스턴스 생성
		
		while(true){
			System.out.println("What kind of Emergency?");
			System.out.println("1.Fire  2.Patient  3.Thief  4.Record  5.End");
			choice = kb.nextInt();
			
			if(choice == 1){
				e.EM_Call(fe);
			}
			else if(choice == 2){
				e.EM_Call(am);
			}
			else if(choice == 3){
				e.EM_Call(po);
			}//1~3을 입력하면 각각 긴급상황에 맞게 EM_Call 메서드 사용
			else if(choice ==4){
				e.EM_record();
			}//4를 입력하면 record 출력
			else{
				System.out.println("Finished");
				break;
			}//1~4가 아니면 while loop를 빠져나감
		}
	}
}
