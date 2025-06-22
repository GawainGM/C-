#include<stdio.h>
#include<string.h>
#define max 100
typedef struct {
    int num;
    char name[5];
}stuType;
typedef stuType elemType;
typedef struct
{
    elemType elem[max];
    int len;
}seqList;
void input(seqList* list);
int find(seqList* list, int num); //查找成功返回i，查找失败返回0
int main()
{
    seqList list;
    int num;
    int i=0;
    input(&list);
    scanf("%d", &num);
    i=find(&list,num);
    if(i>=0)
    printf("%s",list.elem[i].name);
    else
    printf("null");
    return 0;
}
void input(seqList* list)
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);
    list->len = n;
    if(list->len)
    for (i = 0;i < list->len;i++)
        scanf("%d %s", &list->elem[i].num, list->elem[i].name);
}
int find(seqList* list, int num)
{
    int i = 0;
    while (i < list->len)
    {
        if (num == list->elem[i].num)
            return i;
        i++;
    }
    return 0;
}
