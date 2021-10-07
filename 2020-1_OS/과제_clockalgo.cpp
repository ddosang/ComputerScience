//clock 알고리즘
#include <stdio.h>
#include <stdlib.h>


struct MEMORY {
	int page_num; // 메모리 위치에 보관중인 페이지 번호
	int reference_bit; //최근에 참조 되었는지
	int dirty_bit; //wirte인지?
};
struct PAGE {
	int memory_location;
	int valid_bit;
};
struct PAGE page[200000];



int main(int argc, char* argv[]) {
	int pg = 0, op = 0;
	int pagefault = 0, diskloca = 0, diskwrite = 0, diskhead = 0;
	int clock = 0, memoryfull = 0;
	//diskloca 현재 위치, diskwrite 쓰기 횟수, diskhead 이동 거리
	//currentmemory 현재 메모리 clock 시계 바늘 위치 memoryfull 메모리가 꽉 찼는지 알아보기
	int i = 0, j = 0;

	int memory_size = atoi(argv[1]);
	FILE* input_file = fopen("a.txt", "r");
	struct MEMORY* memory = (struct MEMORY*)malloc(memory_size * sizeof(struct MEMORY));

	
	for (int i = 0; i < memory_size; i++) {
		memory[i].reference_bit = 0;
		memory[i].dirty_bit = 0;
	}
	for (int i = 0; i < 200000; i++) {
		page[i].valid_bit = 0;
	}

	while (!feof(input_file)) {
		fscanf(input_file, "%d %d", &pg, &op);
		if (page[pg].valid_bit == 1) {
			memory[page[pg].memory_location].reference_bit = 1;
			if (op == 1) {
				memory[page[pg].memory_location].dirty_bit = 1;
			} //else 해야되는거 아닌가? 일단 0으로 바껴도 전에 1이었으면 내려갈때 써야됨.
		}
		else {
			pagefault++; //pagefault 증가
			memoryfull++; 
			if (memoryfull > memory_size) {  //빈 공간이 없는 경우
				while (memory[clock].reference_bit == 1) { //클락 바늘 이동시키며 reference_bit 1 -> 0,
					memory[clock].reference_bit = 0;       //0인 페이지 탐색
					clock = (clock + 1) % memory_size;
				}
				
				page[memory[clock].page_num].valid_bit = 0; //쫓겨나는 페이지의 valid_bit 0으로 리셋
				if (memory[clock].dirty_bit == 1) { //쫓겨나는 페이지의 dirty_bit 1이면 
					diskhead += abs(diskloca - memory[clock].page_num / 1000); //쓰러 메모리에 있는 페이지로 가야함.
					diskloca = memory[clock].page_num / 1000; 
					diskwrite++; //디스크 헤드 이동 거리, 쓰기 횟수 증가
				}
			}
			diskhead += abs(diskloca - pg / 1000); //요청 페이지 읽어오면서 디스크 헤드 이동 거리 증가
			diskloca = pg / 1000; 

			memory[clock].page_num = pg; //클락 바늘이 가리키는 위치에 새로 들어온 페이지 번호 입력
			if (op == 1) {
				memory[clock].dirty_bit = 1;
			}
			else {
				memory[clock].dirty_bit = 0;
			} //dirty_bit 세팅

			memory[clock].reference_bit = 0; //새로 들어온 페이지의 reference_bit 0으로 셋팅
			page[pg].memory_location = clock; // memory_location에 프레임 번호 지정
			page[pg].valid_bit = 1; // valid_bit 1로 세팅
			clock = (clock + 1) % memory_size;
		}
	}
	printf("%d %d %d ", pagefault, diskwrite, diskhead);
}