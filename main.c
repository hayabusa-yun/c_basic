#include <stdio.h>
#include <string.h>
#define STR_MAX 100

int CharNumOfString(char * str, char ch)
{
    int len= strlen(str);
    int chCnt=0;
    int i;

    for(i=0; i<len; i++)
    {
        if(str[i]==ch)
            chCnt++;
    }
    return chCnt;
}

int main(void) {
    char str[STR_MAX];
    char ch;

    fputs("대상 문자열 입력 : ", stdout);
    fgets(str, STR_MAX, stdin);

    fputs("세어 볼 문자 입력 :", stderr);
    ch=getchar();

    printf("%c의 개수 : %d \n", ch, CharNumOfString(str, ch));
    return 0;
}
