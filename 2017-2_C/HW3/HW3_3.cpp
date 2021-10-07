#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct login_info {
	char id[20];
	char pw[20];
}LOGIN;
//LOGIN이라는 id와 pw를 가진 구조체 생성

int main(int argc, char *argv[]) {
	FILE *info;
	LOGIN *l = (LOGIN *)malloc(sizeof(LOGIN));
	LOGIN *k = (LOGIN *)malloc(sizeof(LOGIN));
	//로그인 포인터 l과 k 선언 후 동적 할당
	int i = 0, member = 0;
	//int형 변수 i와 member 선언 후 0으로 초기화
	char ch; //char형 변수 ch 선언

	info = fopen("passwd(1771076).txt", "r");
	//passwd(1771076).txt 파일을 읽기 전용으로 연다.

	fscanf(info, "%d", &member);
	printf("패스워드 파일을 읽었습니다. %d명의 사용자 정보가 있습니다.\n", member);
	//파일에서 첫줄의 숫자를 읽어온다.

	do {
		printf("ID를 입력하세요 : ");
		scanf(" %s", l->id);

		printf("PW를 입력하세요 : ");
		scanf(" %s", l->pw);
		//id와 pw를 입력받는다.

		for (i = 0; i<member; i++) {
			fscanf(info, "%s %s\n", (k + i)->id, (k + i)->pw);
		}//파일에서 id와 pw 문자열을 읽어와 k[i].id, k[i].pw에 저장한다

		for (i = 0; i<member; i++) {
			if (strcmp(l->id, (k + i)->id) == 0) {
				if (strcmp(l->pw, (k + i)->pw) == 0)
					printf("LOGIN OK!\n");
				else
					printf("LOGIN FAILED!\n");
			}
		}//입력받은 id,pw와 파일에 있는 id,pw가 모두 같을때 LOGIN Ok!를 출력

		printf("계속 하시겠습니까? <Y/N> ");
		scanf(" %c", &ch);
	} while (ch == 'y');
//do while 문을 이용해 마지막에 입력받는 문자가 y일때 반복하게 한다.

	free(l);
	l = { NULL };

	for (i = 0; i < member; i++) {
		free((k+i));
		k = { NULL };
	}
	//동적 메모리 해제
	fclose(info);
}
