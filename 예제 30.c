#include <stdio.h>
#include <string.h>
#define  STR_LEN    50
#define  BOOK_INFO_NUM   3

typedef struct bookInfo{
    char bookTitle[STR_LEN];
    char bookPub[STR_LEN];
    int bookPrice;
}bookInfo;

int numOfData=0;
bookInfo bookInfoList[BOOK_INFO_NUM];

/** 정렬을 위한 상수 정의 **/
enum{SORT_TITLE=1, SORT_PUB, SORT_PRICE, EXIT};
bookInfo * bookSortList[BOOK_INFO_NUM];

int InsertList(bookInfo* bookPtr);

void InitSortList(void);
void PrintSortList(void);

void SortByTitle(void);
void SortByPubName(void);
void SortByPrice(void);

int main(void)
{
    int i, num;
    int choice;
    bookInfo book;
    
    puts("********* 도서 정보 입력 *********");
    for(i=0; i<BOOK_INFO_NUM; i++)
    {
        printf("%d번째 도서 정보 입력. \n", (i+1));
        
        fputs("도서 제목: ", stdout);
        gets(book.bookTitle);
        
        fputs("출판사 명: ", stdout);
        gets(book.bookPub);
        
        fputs("도서 가격: ", stdout);
        scanf("%d", &(book.bookPrice));
        fflush(stdin);
        
        num=InsertList(&book);
        if(num==-1)
            printf("입력에 실패하였습니다. \n");
        else
            printf("%d번째 입력 완료.......\n\n", num);
    }
    
    InitSortList();
    while(1)
    {
        puts("********* 도서 정보 출력 *********");
        puts("정렬방식 선택...... ");
        puts("1.도서 제목 순, 2.출판사 순, 3.가격 순, 4.종료 ");
        fputs("그대의 선택은? ", stdout);
        scanf("%d", &choice);
        if(choice==EXIT)
            break;
        
        switch(choice)
        {
        case SORT_TITLE:
            SortByTitle();
            PrintSortList();
            break;
        
        case SORT_PUB:
            SortByPubName();
            PrintSortList();
            break;
        
        case SORT_PRICE:
            SortByPrice();
            PrintSortList();
            break;
        }
    }
        
    return 0;
}

int InsertList(bookInfo* bookPtr)
{
    int idx;
    int inputIdx=numOfData;
    
    if(numOfData >= BOOK_INFO_NUM)
        return -1; // -1은 입력 실패를 의미
        
    /** 입력 위치 찾기 **/
    for(idx=0; idx<numOfData; idx++)
    {
        if(strcmp(bookInfoList[idx].bookTitle, bookPtr->bookTitle) >0) 
        {
            inputIdx=idx;
            break;
        }
    }
    
    /** 입력이 가능하도록 자리를 마련 **/
    for(idx=numOfData; idx>inputIdx; idx--)
        bookInfoList[idx]=bookInfoList[idx-1];
    
    /** 새로운 데이터 입력 **/
    bookInfoList[inputIdx]=(*bookPtr);
    
    /** 입력 성공 시 입력된 데이터 개수 반환 **/
    return ++numOfData;
}

void InitSortList(void)
{	
    int i;
    for(i=0; i<BOOK_INFO_NUM; i++)
        bookSortList[i] = &bookInfoList[i];
}

void PrintSortList(void)
{
    int i;
    for(i=0; i<BOOK_INFO_NUM; i++)
    {
        printf("%d번째 도서 정보 출력. \n", (i+1));
        printf("도서 제목: %s \n", bookSortList[i]->bookTitle);
        printf("출판사 명: %s \n", bookSortList[i]->bookPub);
        printf("도서 가격: %d \n\n", bookSortList[i]->bookPrice);
    }
}

void SortByTitle(void)
{
    InitSortList();
}


void SortByPubName(void)
{
    int i, j;
    bookInfo * temp;
    
    for(i=0; i<BOOK_INFO_NUM-1 ;i++)
    {
        for(j=0; j<(BOOK_INFO_NUM-i)-1; j++)
        {
            if(strcmp(bookSortList[j]->bookPub, bookSortList[j+1]->bookPub) > 0)
            {
                temp=bookSortList[j];
                bookSortList[j]=bookSortList[j+1];
                bookSortList[j+1]=temp;
            }
        }
    }
}

void SortByPrice(void)
{
    int i, j;
    bookInfo * temp;
    
    for(i=0; i<BOOK_INFO_NUM-1 ;i++)
    {
        for(j=0; j<(BOOK_INFO_NUM-i)-1; j++)
        {
            if(bookSortList[j]->bookPrice > bookSortList[j+1]->bookPrice)
            {
                temp=bookSortList[j];
                bookSortList[j]=bookSortList[j+1];
                bookSortList[j+1]=temp;
            }
        }
    }
}