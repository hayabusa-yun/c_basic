#include <stdio.h>

int SumOfArray(int * arrPtr, int arrLen)
{
    int total=0;
    int i;

    for(i=0; i<arrLen; i++)
        total+=arrPtr[i];

    return total;
}

int main(void) {

    int arr1[3]= {5, 10, 15};
    int arr2[5]= {1,2,3,4,5};

    int sumOfArrResult;

    sumOfArrResult= SumOfArray(arr1, sizeof(arr1) / sizeof(int));
    printf("5, 10, 15의 합 : %d \n", sumOfArrResult);

    sumOfArrResult= SumOfArray(arr2, sizeof(arr2) / sizeof(int));
    printf("1, 2, 3, 4, 5의 합 : %d \n", sumOfArrResult);

    return 0;
}
