#include <stdio.h>
#include <stdlib.h>

typedef struct login_info {
	char id[20];
	char passwd[20];
}LOGIN; //����ü login_info ���� ����� �̸��� LOGIN���� �Ѵ�.

int main() {
	FILE *out;
	LOGIN *arr; //login_info ������ �迭 �����͸� �����.
	int member;

	out = fopen("passwd(1771076).txt", "w");
	//��������� passwd(1771076).txt������ ����.

	printf("Input the number of members: ");
	scanf("%d", &member);
	arr = (LOGIN *)malloc(sizeof(LOGIN)*member);
	//ȸ�� ���� �Է¹��� �� ���� �޸𸮿� �Ҵ��Ѵ�.

	for (int i = 0; i < member; i++) {
		printf("Input your ID and PASSWORD: ");
		scanf(" %s %s", arr[i].id, arr[i].passwd);
	}//���̵�� ��й�ȣ�� �Է¹޴´�.

	fprintf(out, "%d\n", member);
	//�Է¹��� ��� ���� passwd(1771076).txt���Ͽ� ����Ѵ�.

	for (int i = 0; i < member; i++) {
		fprintf(out, "%s %s\n", arr[i].id, arr[i].passwd);
	}//�Է¹��� ���̵�� ��й�ȣ�� passwd(1771076).txt���Ͽ� ����Ѵ�.

	free(arr); //���� �޸𸮸� �����Ѵ�.
	fclose(out); //������ �ݴ´�.
	return 0;
}