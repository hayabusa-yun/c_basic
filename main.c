#include <stdio.h>

int main(void) {

    /* EOF가 입력될 때까지 문자를 입력 받음
    int total = 0;
    char input;

    while(1)
    {
        fputs("Data input (ctrl + d to exit) : ", stdout);
        input=getchar();
        if(input==EOF)
            break;

        while (getchar() != '\n'); // fflush(stdin)의 대체
        total++;
        //printf("입력된 문자의 수 : %d \n", total);
    }

    printf("입력된 문자의 수 : %d \n", total);
    return 0;
     */

    int total=0;
    int input=0;
    int ret;

    while (1)
    {
        fputs("Data input ctrl + d to exit : ", stdout);
        ret=scanf("%d", &input); // fflush가 필요 없는 이유는 scanf는 공백을 데이터로 인정하지 않음
                                 // 단 %c(문자 입력)은 공백 문자를 데이터로 인정(아스키 값에 등록되어 있기 때문)
        if(ret==EOF)
            break;

        total+=input;
    }

    printf("총 합 : %d \n", total);
    return 0;
}
