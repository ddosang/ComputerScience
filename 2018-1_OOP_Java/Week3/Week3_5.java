
public class Week3_5 {

	public static void main(String[] args) {
		
		int[][] Score = new int[][]{ {90,87,85,69,71,80}, // 1그룹 6명
									 {83,74,95,62}, // 2그룹 4명
									 {93,66,87,88,79}, // 3그룹 5명
									 {65,96,79,84,89,90} /*4그룹 6명*/ };
									 
		// Score 라는 2차원 배열 생성
									 
		int total = 0;
		double avg = 0;
		
		System.out.println("<학생별 성적>");
		
		for(int i=0;i<Score.length;i++){
			System.out.printf("그룹%d:  ",i+1); //그룹[i+1]: 출력
			
			for(int j=0;j<Score[i].length;j++){
				System.out.printf("%d   ",Score[i][j]);
				//i열 j행에 있는 원소 출력
			}
			System.out.printf("\n");
			//i가 1 늘어날 때 마다 한 줄 띈다.
		}//중첩 for 문을 이용해 배열 안의 원소들을 행렬 형태로 출력
		
		System.out.println("<그룹별 평균>");
		
		for(int i=0;i<Score.length;i++){
			System.out.printf("그룹%d:  ",i+1);
			
			for(int j=0;j<Score[i].length;j++){
				total += Score[i][j]; //total에 i행 원소를 모두 더한다.
			}
			avg = (double)total / (double)Score[i].length;
			//total을 i행 원소 개수로 나눠서 평균을 구한다.
			System.out.printf("%.2f",avg);
			//구한 평균을 소숫점 둘째자리까지 출력
			total = 0; //다음 행의 평균을 계산하기 위해 total에 0을 대입.
			System.out.printf("\n");
		}
	}
}
