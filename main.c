#include <stdio.h>
#define STR_LEN 50

int main(void) {

    char name[STR_LEN];

    fputs("input char : ", stdout);
    fgets(name, sizeof name, stdin);
    // 포맷을 지정하지 않을 거라면 printf 함수보다는 puts 함수를 사용하는 것이 효율적
    // fputs를 사용한 이유는 puts는 개행을 하기 때문
    // fgets를 사용하면 공백을 포함하는 하나의 문장을 입력 받을 수 있다.

    fputs("inputed char : ", stdout);
    puts(name);

    return 0;
}
