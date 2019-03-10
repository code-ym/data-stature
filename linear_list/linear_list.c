#include "linear_list.h"

int main(int argc, char const* argv[])
{
    linear_list test_list;
    InitLinearList(&test_list);
    for (int i = 0; i < INIT_CAPACITY; i++)
        Insert(rand() % 100, i, &test_list);
    qsort(test_list.elem, test_list.length, sizeof(int), Cmp);
    Display(&test_list);

    system("pause");
    return 0;
}

linear_list* InitLinearList(linear_list* L)
{
    L->capacity = INIT_CAPACITY;
    L->length = 0;
    L->elem = (int*)malloc(L->capacity * sizeof(int));
    memset(L->elem, 0, L->capacity * sizeof(int));
    return L;
}

void Display(linear_list* L)
{
    for (int i = 0; i < L->length; i++)
        printf("线性表的第%d个元素为： %d\n", i + 1, L->elem[i]);
}

int* AllocListElem(linear_list* L)
{
    int* new_list_elem = (int*)malloc(L->capacity * sizeof(int));
    memset(new_list_elem, 0, L->capacity * sizeof(int));
    memcpy(new_list_elem, L->elem, L->length * sizeof(int));
    return new_list_elem;
}

linear_list* Resize(linear_list* L)
{
    if (L->length < 0.25 * L->capacity && L->length > 0) {
        L->capacity *= 0.5;
        int* new_elem = AllocListElem(L);
        free(L->elem);
        L->elem = new_elem;
        return L;
    }

    if (L->length > 0.75 * L->capacity && L->length > 0) {
        L->capacity *= 2;
        int* new_elem = AllocListElem(L);
        free(L->elem);
        L->elem = new_elem;
        return L;
    }
}

int Insert(int E, int P, linear_list* L)
{
    Resize(L);
    for (int i = L->length; i >= P; i--) {
        L->elem[i] = L->elem[i - 1];
        L->elem[P] = E;
    }
    L->length++;
    return E;
}

int Remove(int lo, int hi, linear_list* L)
{
    if (lo < 0 || hi > L->length || lo > L->length)
        printf("区间范围错误！\n");

    while (hi < L->length)
        L->elem[lo++] = L->elem[hi++];
    L->length -= hi - lo;
    Resize(L);
}

int BinSearch(int E, int lo, int hi, linear_list* L)
{
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (L->elem[mid] < E)
            lo = mid + 1;
        else
            hi = mid;
    }
    return hi;
}

int Cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}