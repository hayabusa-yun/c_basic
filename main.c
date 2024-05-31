#include <stdio.h>

//row의 길이가 2인 int형 배열을 인자로 전달받는 함수
int SumOfArrayBy2(int (*arrPtr)[2], int column)
{
    int total = 0;
    int i, j;
    for(i=0; i<column; i++)
        for(j=0; j<2; j++)
            total+=arrPtr[i][j];

    return total;
}
//row의 길이가 3인 int형 배열을 인자로 전달받는 함수
int SumOfArrayBy3(int (*arrPtr)[3], int column)
{
    int total = 0;
    int i, j;
    for(i=0; i<column; i++)
        for(j=0; j<3; j++)
            total+=arrPtr[i][j];

    return total;
}

int main(void) {

    int arr3[2][2]={1, 3, 5, 7};
    int arr4[2][3]={1,2,3,4,5,6};

    int sumOfArrResult;

    sumOfArrResult= SumOfArrayBy2(arr3, 2);
    printf("1,3,5,7의 합 : %d\n", sumOfArrResult);

    sumOfArrResult= SumOfArrayBy3(arr4, 2);
    printf("1,2,3,4,5,6의 합 : %d\n", sumOfArrResult);
    return 0;
}
