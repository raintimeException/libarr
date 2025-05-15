#ifndef LIB_ARR_H
#define LIB_ARR_H

#include <stdio.h>

#define len(arr)   sizeof(arr)/sizeof(*arr)

int print(int *arr, int len);
int get(int *arr, int index);
int update(int *arr, int index, int val); //check if it quals -> do nothing
int insert(int *arr, int index, int val);
int append(int *arr, int len, int val);
int delete(int *arr, int index);
int search(int *arr, int val);
int sort_asc(int *arr);
int sort_desc(int *arr);
int merge(int *arr1, int *arr);
int split(int *arr, int *arr_one, int *arr_two); //maybe return [[],[]]?
int reverse(int *arr);
int *slice(int *arr, int from, int to);
int map(void (*fn)(int val), int *arr);
int *filter(int *arr, int min, int max);
int reduce(int *arr, char oper);
int *find(int *arr, int min, int max);
int *check_duplicate(int *arr);

#ifdef LIB_ARR_IMPLEMENTATION

int print(int *arr, int len)
{
    for (int i = 0; i < len; ++i)
        printf((i != len-1) ? " %d":" %d\n", arr[i]);
    return 0;
}

int get(int *arr, int index)
{
    return arr[index];
}

int update(int *arr, int index, int val)
{
    if (arr[index] == val)
        printf("INFO: Value %d is already at index %d!!!\n", val, index);
    arr[index] = val;
    return arr[index];
}

int insert(int *arr, int index, int val)
{
    update(arr, index, val);
}

int append(int *arr, int len, int val)
{
    static int last_appended_index = 0;
    if (last_appended_index < len) arr[last_appended_index++] = val;
    else printf("ERROR: Array is full\n");
}

int delete(int *arr, int index);
int search(int *arr, int val);
int sort_asc(int *arr);
int sort_desc(int *arr);
int merge(int *arr1, int *arr);
int split(int *arr, int *arr_one, int *arr_two); //maybe return [[],[]]?
int reverse(int *arr);
int *slice(int *arr, int from, int to);
int map(void (*fn)(int val), int *arr);
int *filter(int *arr, int min, int max);
int reduce(int *arr, char oper);
int *find(int *arr, int min, int max);
int *check_duplicate(int *arr);

#endif // LIB_ARR_IMPLEMENTATION
#endif // LIB_ARR_H
