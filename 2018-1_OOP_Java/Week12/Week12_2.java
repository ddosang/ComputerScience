package fallinlovewithyou;

import java.util.*;

public class Week12_2 {
	public static void main(String[] args) {
		
		Map<String, String> m = new HashMap<String,String>();
		Scanner kb = new Scanner(System.in);
		String ID, name, str, str1, maxID, minID;
		int maxLength, minLength;  //필요한 변수 선언

		System.out.println("학생 ID와 이름을 차례로 입력하세요.(종료시 0 0 입력)");
		while(true) {
			ID = kb.next();
			name = kb.next(); //ID, 이름 입력받는다.
			if(name.equals("0") && ID.equals("0")) { //둘다 0이면 break (하기전에 max, min 값을 위해 조작)
				System.out.println("<학생명단>");
				System.out.println("[ID]\t\t[NAME]");
				
				Set s = m.keySet();
				Iterator<String> it = s.iterator();
				
				Iterator<String> it2 = s.iterator(); //iterator 하나 더 선언해서
				str1 = it2.next();
				maxLength = m.get(str1).length();
				minLength = m.get(str1).length();
				maxID = str1;
				minID = str1;// max min 초기화 
	
				while(it.hasNext()) {
					str = it.next();
					System.out.println(str+"\t\t"+m.get(str)); //학생 명단 출력
					
					if(m.get(str).length() > maxLength){
						maxLength = m.get(str).length(); 
						maxID = str;
					} //max 값 정하기
					if(m.get(str).length() < minLength){
						minLength = m.get(str).length(); 
						minID = str;
					} //min 값 정하기
				}
				break;
			}
			m.put(ID, name);
		}		
		
		System.out.println("전체 학생수:"+m.size());
		System.out.println("<가장 긴 이름을 가진 학생>");
		System.out.println("ID:"+maxID+" Name:"+m.get(maxID)+" 길이:"+maxLength);
		System.out.println("<가장 짧은 이름을 가진 학생>");
		System.out.println("ID:"+minID+" Name:"+m.get(minID)+" 길이:"+minLength);
		//결과 출력
	}
}

 

