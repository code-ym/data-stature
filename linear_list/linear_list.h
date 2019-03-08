#pragma once

#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 100

typedef struct
{
    int length;
    int capacity;
    int* elem;
} linear_list;

linear_list* InitLinearList(linear_list* L);
void ShowElem(linear_list *L);