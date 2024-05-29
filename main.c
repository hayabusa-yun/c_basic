#include <stdio.h>
#define ARR_LEN 5
//버블정렬

int main(void) {

    int arr[ARR_LEN];
    int idx;
    int i, j;
    int temp;

    for(idx=0; idx<ARR_LEN; idx++)
    {
        printf("숫자 %d 입력 : ", idx+1);
        scanf("%d", &arr[idx]);
    }

    for (i=0; i<ARR_LEN-1; i++) {
        for(j=0; j<(ARR_LEN-i)-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    fputs("정렬된 출력 : ", stdout);

    for(i=0; i<ARR_LEN; i++)
        printf("%d", arr[i]);
    return 0;
}
