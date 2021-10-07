//clock �˰���
#include <stdio.h>
#include <stdlib.h>


struct MEMORY {
	int page_num; // �޸� ��ġ�� �������� ������ ��ȣ
	int reference_bit; //�ֱٿ� ���� �Ǿ�����
	int dirty_bit; //wirte����?
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
	//diskloca ���� ��ġ, diskwrite ���� Ƚ��, diskhead �̵� �Ÿ�
	//currentmemory ���� �޸� clock �ð� �ٴ� ��ġ memoryfull �޸𸮰� �� á���� �˾ƺ���
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
			} //else �ؾߵǴ°� �ƴѰ�? �ϴ� 0���� �ٲ��� ���� 1�̾����� �������� ��ߵ�.
		}
		else {
			pagefault++; //pagefault ����
			memoryfull++; 
			if (memoryfull > memory_size) {  //�� ������ ���� ���
				while (memory[clock].reference_bit == 1) { //Ŭ�� �ٴ� �̵���Ű�� reference_bit 1 -> 0,
					memory[clock].reference_bit = 0;       //0�� ������ Ž��
					clock = (clock + 1) % memory_size;
				}
				
				page[memory[clock].page_num].valid_bit = 0; //�Ѱܳ��� �������� valid_bit 0���� ����
				if (memory[clock].dirty_bit == 1) { //�Ѱܳ��� �������� dirty_bit 1�̸� 
					diskhead += abs(diskloca - memory[clock].page_num / 1000); //���� �޸𸮿� �ִ� �������� ������.
					diskloca = memory[clock].page_num / 1000; 
					diskwrite++; //��ũ ��� �̵� �Ÿ�, ���� Ƚ�� ����
				}
			}
			diskhead += abs(diskloca - pg / 1000); //��û ������ �о���鼭 ��ũ ��� �̵� �Ÿ� ����
			diskloca = pg / 1000; 

			memory[clock].page_num = pg; //Ŭ�� �ٴ��� ����Ű�� ��ġ�� ���� ���� ������ ��ȣ �Է�
			if (op == 1) {
				memory[clock].dirty_bit = 1;
			}
			else {
				memory[clock].dirty_bit = 0;
			} //dirty_bit ����

			memory[clock].reference_bit = 0; //���� ���� �������� reference_bit 0���� ����
			page[pg].memory_location = clock; // memory_location�� ������ ��ȣ ����
			page[pg].valid_bit = 1; // valid_bit 1�� ����
			clock = (clock + 1) % memory_size;
		}
	}
	printf("%d %d %d ", pagefault, diskwrite, diskhead);
}