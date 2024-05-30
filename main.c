#include <stdio.h>
#include <string.h>
#define STR_LEN 20
#define STR_NUM 5

// 문자열을 입력 받고 정렬하여 출력
int main(void) {

    char strArr[5][STR_LEN];
    char tempStr[STR_LEN];
    int i,j;

    for(i=0; i<STR_NUM; i++)
    {
        printf("문자열 입력 %d : ", i+1);
        fgets(strArr,STR_LEN,stdin);
    }

    //문자열 정렬(버블정렬)
    for(i=0; i<STR_NUM-1; i++)
    {
        for(j=0; j<(STR_NUM-i)-1; j++)
        {
            if(strlen(strArr[j]) > strlen(strArr[j+1]))
            {
                strcpy(tempStr, strArr[j]);
                strcpy(strArr[j], strArr[j+1]);
                strcpy(strArr[j+1], tempStr);
            }
        }
    }

    //정렬된 문자열 출력
    for(i=0; i<STR_NUM; i++)
        puts(strArr[i]);
    return 0;
}
