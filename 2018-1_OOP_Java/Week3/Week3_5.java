
public class Week3_5 {

	public static void main(String[] args) {
		
		int[][] Score = new int[][]{ {90,87,85,69,71,80}, // 1�׷� 6��
									 {83,74,95,62}, // 2�׷� 4��
									 {93,66,87,88,79}, // 3�׷� 5��
									 {65,96,79,84,89,90} /*4�׷� 6��*/ };
									 
		// Score ��� 2���� �迭 ����
									 
		int total = 0;
		double avg = 0;
		
		System.out.println("<�л��� ����>");
		
		for(int i=0;i<Score.length;i++){
			System.out.printf("�׷�%d:  ",i+1); //�׷�[i+1]: ���
			
			for(int j=0;j<Score[i].length;j++){
				System.out.printf("%d   ",Score[i][j]);
				//i�� j�࿡ �ִ� ���� ���
			}
			System.out.printf("\n");
			//i�� 1 �þ �� ���� �� �� ���.
		}//��ø for ���� �̿��� �迭 ���� ���ҵ��� ��� ���·� ���
		
		System.out.println("<�׷캰 ���>");
		
		for(int i=0;i<Score.length;i++){
			System.out.printf("�׷�%d:  ",i+1);
			
			for(int j=0;j<Score[i].length;j++){
				total += Score[i][j]; //total�� i�� ���Ҹ� ��� ���Ѵ�.
			}
			avg = (double)total / (double)Score[i].length;
			//total�� i�� ���� ������ ������ ����� ���Ѵ�.
			System.out.printf("%.2f",avg);
			//���� ����� �Ҽ��� ��°�ڸ����� ���
			total = 0; //���� ���� ����� ����ϱ� ���� total�� 0�� ����.
			System.out.printf("\n");
		}
	}
}
