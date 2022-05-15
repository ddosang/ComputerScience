#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COUNT 50 // 50이 축이라서 0~49 결과값을 미리 저장할 것이다.
#define FUNC(x) ((x) * (x) - 100 * (x) + 100) // x = 50 이 축인 함수. -> 50 - a, 50 + a 는 함수 값이 같음.
#define TRUE 1
#define FALSE 0


int inputs[MAX_COUNT] = { 0 }; // 0 ~ MAX_COUNT - 1 를 채워놓고,
int outputs[MAX_COUNT] = { 0 }; // FUNC(0) ~ FUNC(MAX_COUNT - 1) 을 채워놓고

int main(void) {
    srand((unsigned int)time(NULL) % 1000);

    int num = (int)((double)rand() / RAND_MAX * 100);
    int result;

    for (int i = 0; i < MAX_COUNT; i++) {
        inputs[i] = i;
        outputs[i] = FUNC(i);
    }

    // 랜덤으로 한 숫자를 뽑아서 함수 결과값이 기존 것과 같은 값이 있는지를 확인해볼 예정.
    // 0~MAX_COUNT 사이에 있으면 안됨.
    while (0 <= num && num < MAX_COUNT) {
        num = (int)((double)rand() / RAND_MAX * 100);
    }

    result = FUNC(num);
    printf("뽑힌 수 %d, 결과값 %d\n", num, result);
    for(int i = 0; i < MAX_COUNT; i++) {
        if (result == outputs[i]) {
            printf("같은 결과값을 가지는 수 %d %d\n", i, num);
        }
    }


    return 0;
}
