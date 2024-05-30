#include <stdio.h>
#include <string.h>
#define STR_LEN 256
//문자열의 대소문자를 변경하여 출력

int main(void) {

    char str[STR_LEN];
    int strLen=0;
    int i;

    int diff='A' - 'a'; // 대문자와 소문자의 아스키코드 값의 차를 계산

    fputs("문자열 입력 : ", stdout);
    fgets(str, STR_LEN, stdin);
    strLen=strlen(str);

    for(i=0; i<strLen; i++)
    {
        if('a'<=str[i] && str[i]<='z') //소문자라면 12행의 계산 값을 더하여 대문자로 변경
            str[i]+=diff;

        else if('A'<=str[i] && str[i]<='Z') // 대문자라면 12행의 계산 값을 빼서 소문자로 변경
            str[i]-=diff;
        else
            ;
    }

    puts(str);
    return 0;
}
