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
	}//������ ����
	
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
}//Car class�� getter method ����

class FireEngine extends Car{
	FireEngine(){
		super("Fire", 119, "FireEngine", "Firemen");
		//super �� �̿��� �� class�� �ش�Ǵ� ������ �־� �θ��� �����ڸ� �θ���.
	}
	public String toString(){
		return getStr();
	}
}//Car class �� ��ӹ��� FireEngine �� toString method overriding

class Ambulance extends Car{
	Ambulance(){
		super("Patient", 119, "Ambulance", "Doctor");
	}	
	public String toString(){
		return getStr();
	}
}//Car class �� ��ӹ��� Ambulance �� toString method overriding

class PoliceCar extends Car{
	PoliceCar(){
		super("Thief", 112, "PoliceCar", "Policemen");
	}	
	public String toString(){
		return getStr();
	}
}//Car class �� ��ӹ��� PoliceCar �� toString method overriding
class Emergency{
	Car cc[] = new Car[10];
	int i;
	
	void EM_Call(Car c){
		if(c instanceof FireEngine){
			FireEngine fe = (FireEngine)c;
			System.out.println("Call "+c.getNumber());
			cc[i++] =  fe;
		}//FireEngine�� ��� c�� fe�� �����ϰ�
		//���� ��ȭ���� ����ϰ�, Car �迭 cc[i]�� fe���� �� i�� 1 ������Ŵ
		else if(c instanceof Ambulance){
			Ambulance am = (Ambulance)c;
			System.out.println("Call "+am.getNumber());
			cc[i++] =  am;
		}//Ambulance�� ��� c�� am�� ����
		else if(c instanceof PoliceCar){
			PoliceCar po = (PoliceCar)c;
			System.out.println("Call "+po.getNumber());
			cc[i++] = po;
		}//PoliceCar�� ��� c�� po�� ����
	}
	void EM_record(){
		System.out.printf("Emergency\tNumber\tCar_Type\tRequird\n");
		for(int j = 0; j<i ; j++)	
			System.out.printf("%s\t\t%d\t%s\t%s\n", cc[j].getEmg(), cc[j].getNumber(), cc[j].getCar_Type(), cc[j].getReqPerson());
	}//���ݱ����� ����� ���
}//Emergency 

public class Week8_2 {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		
		int choice=0, i=0;
		FireEngine fe = new FireEngine();
		Ambulance am = new Ambulance();
		PoliceCar po = new PoliceCar();
		Emergency e = new Emergency();
		//class ���� �ν��Ͻ� ����
		
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
			}//1~3�� �Է��ϸ� ���� ��޻�Ȳ�� �°� EM_Call �޼��� ���
			else if(choice ==4){
				e.EM_record();
			}//4�� �Է��ϸ� record ���
			else{
				System.out.println("Finished");
				break;
			}//1~4�� �ƴϸ� while loop�� ��������
		}
	}
}
