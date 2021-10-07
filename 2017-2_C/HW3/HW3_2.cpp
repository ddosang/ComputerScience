#include <stdio.h>
#include <stdlib.h>

typedef struct login_info {
	char id[20];
	char passwd[20];
}LOGIN; //구조체 login_info 형식 만들고 이름을 LOGIN으로 한다.

int main() {
	FILE *out;
	LOGIN *arr; //login_info 형식의 배열 포인터를 만든다.
	int member;

	out = fopen("passwd(1771076).txt", "w");
	//쓰기용으로 passwd(1771076).txt파일을 연다.

	printf("Input the number of members: ");
	scanf("%d", &member);
	arr = (LOGIN *)malloc(sizeof(LOGIN)*member);
	//회원 수를 입력받은 뒤 동적 메모리에 할당한다.

	for (int i = 0; i < member; i++) {
		printf("Input your ID and PASSWORD: ");
		scanf(" %s %s", arr[i].id, arr[i].passwd);
	}//아이디와 비밀번호를 입력받는다.

	fprintf(out, "%d\n", member);
	//입력받은 멤버 수를 passwd(1771076).txt파일에 출력한다.

	for (int i = 0; i < member; i++) {
		fprintf(out, "%s %s\n", arr[i].id, arr[i].passwd);
	}//입력받은 아이디와 비밀번호를 passwd(1771076).txt파일에 출력한다.

	free(arr); //동적 메모리를 해제한다.
	fclose(out); //파일을 닫는다.
	return 0;
}