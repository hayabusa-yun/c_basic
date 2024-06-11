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

/** ������ ���� ��� ���� **/
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
    
    puts("********* ���� ���� �Է� *********");
    for(i=0; i<BOOK_INFO_NUM; i++)
    {
        printf("%d��° ���� ���� �Է�. \n", (i+1));
        
        fputs("���� ����: ", stdout);
        gets(book.bookTitle);
        
        fputs("���ǻ� ��: ", stdout);
        gets(book.bookPub);
        
        fputs("���� ����: ", stdout);
        scanf("%d", &(book.bookPrice));
        fflush(stdin);
        
        num=InsertList(&book);
        if(num==-1)
            printf("�Է¿� �����Ͽ����ϴ�. \n");
        else
            printf("%d��° �Է� �Ϸ�.......\n\n", num);
    }
    
    InitSortList();
    while(1)
    {
        puts("********* ���� ���� ��� *********");
        puts("���Ĺ�� ����...... ");
        puts("1.���� ���� ��, 2.���ǻ� ��, 3.���� ��, 4.���� ");
        fputs("�״��� ������? ", stdout);
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
        return -1; // -1�� �Է� ���и� �ǹ�
        
    /** �Է� ��ġ ã�� **/
    for(idx=0; idx<numOfData; idx++)
    {
        if(strcmp(bookInfoList[idx].bookTitle, bookPtr->bookTitle) >0) 
        {
            inputIdx=idx;
            break;
        }
    }
    
    /** �Է��� �����ϵ��� �ڸ��� ���� **/
    for(idx=numOfData; idx>inputIdx; idx--)
        bookInfoList[idx]=bookInfoList[idx-1];
    
    /** ���ο� ������ �Է� **/
    bookInfoList[inputIdx]=(*bookPtr);
    
    /** �Է� ���� �� �Էµ� ������ ���� ��ȯ **/
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
        printf("%d��° ���� ���� ���. \n", (i+1));
        printf("���� ����: %s \n", bookSortList[i]->bookTitle);
        printf("���ǻ� ��: %s \n", bookSortList[i]->bookPub);
        printf("���� ����: %d \n\n", bookSortList[i]->bookPrice);
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