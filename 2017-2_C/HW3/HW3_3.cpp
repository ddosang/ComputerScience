#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct login_info {
	char id[20];
	char pw[20];
}LOGIN;
//LOGIN�̶�� id�� pw�� ���� ����ü ����

int main(int argc, char *argv[]) {
	FILE *info;
	LOGIN *l = (LOGIN *)malloc(sizeof(LOGIN));
	LOGIN *k = (LOGIN *)malloc(sizeof(LOGIN));
	//�α��� ������ l�� k ���� �� ���� �Ҵ�
	int i = 0, member = 0;
	//int�� ���� i�� member ���� �� 0���� �ʱ�ȭ
	char ch; //char�� ���� ch ����

	info = fopen("passwd(1771076).txt", "r");
	//passwd(1771076).txt ������ �б� �������� ����.

	fscanf(info, "%d", &member);
	printf("�н����� ������ �о����ϴ�. %d���� ����� ������ �ֽ��ϴ�.\n", member);
	//���Ͽ��� ù���� ���ڸ� �о�´�.

	do {
		printf("ID�� �Է��ϼ��� : ");
		scanf(" %s", l->id);

		printf("PW�� �Է��ϼ��� : ");
		scanf(" %s", l->pw);
		//id�� pw�� �Է¹޴´�.

		for (i = 0; i<member; i++) {
			fscanf(info, "%s %s\n", (k + i)->id, (k + i)->pw);
		}//���Ͽ��� id�� pw ���ڿ��� �о�� k[i].id, k[i].pw�� �����Ѵ�

		for (i = 0; i<member; i++) {
			if (strcmp(l->id, (k + i)->id) == 0) {
				if (strcmp(l->pw, (k + i)->pw) == 0)
					printf("LOGIN OK!\n");
				else
					printf("LOGIN FAILED!\n");
			}
		}//�Է¹��� id,pw�� ���Ͽ� �ִ� id,pw�� ��� ������ LOGIN Ok!�� ���

		printf("��� �Ͻðڽ��ϱ�? <Y/N> ");
		scanf(" %c", &ch);
	} while (ch == 'y');
//do while ���� �̿��� �������� �Է¹޴� ���ڰ� y�϶� �ݺ��ϰ� �Ѵ�.

	free(l);
	l = { NULL };

	for (i = 0; i < member; i++) {
		free((k+i));
		k = { NULL };
	}
	//���� �޸� ����
	fclose(info);
}
