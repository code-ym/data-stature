#include "linear_list.h"

int main(int argc, char const* argv[])
{
    linear_list test_list;
    InitLinearList(&test_list);
    ShowElem(&test_list);

    system("pause");
    return 0;
}

linear_list* InitLinearList(linear_list* L)
{
    L->capacity = INIT_CAPACITY;
    L->length = 0;
    L->elem = (int*)malloc(L->capacity * sizeof(int));
    for (int i = 0; i < L->capacity; i++)
        *(L->elem + i) = 0;
    return L;
}

void ShowElem(linear_list* L)
{
    for (int i = 0; i < L->capacity; i++)
        printf("线性表的第%d个元素为： %d\n", i + 1, *(L->elem + i));
}