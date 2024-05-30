#include <stdio.h>

//문자열의 대소문자를 변경하여 출력 (배열 x)
int main(void) {

    char ch;
    int diff= 'A'-'a';

    fputs("문자열 입력 : ",stdout);
    while (1)
    {
        ch=getchar();

        if(ch == '\n')
            break;

        else if('a' <= ch && ch<='z')
            putchar(ch+diff);

        else if('A' <= ch && ch<='Z')
            putchar(ch-diff);
        else
            putchar(ch);
    }
    return 0;
}
