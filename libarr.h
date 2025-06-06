#ifndef LIB_ARR_H
#define LIB_ARR_H

#include <stdlib.h>

#define len(arr)   sizeof(arr)/sizeof(*arr)

int print   (int *arr, int len);
int get     (int *arr, int index); // index out of range is your fault
int update  (int *arr, int index, int val);
int insert  (int *arr, int index, int val);
int append  (int *arr, int len, int val); // I know that pass `len' to every function is stupid, but it was the simplest solution
int delete  (int *arr, int len, int index);
int search (int *arr, int len, int val);
void sort_asc   (int *arr, int len);
void sort_desc  (int *arr, int len);
int merge  (int *arr, int len, int *arr_one, int len_arr_one, int *arr_two, int len_arr_two);
int split_by_index  (int *arr, int len, int *arr_one, int *arr_two, int index);
int reverse (int *arr, int len);
int *slice (int *arr, int *arr_result, int len, int from, int to);
int map     (char op, int *arr, int len);
int *filter(int *arr, int len, int min, int max);
int reduce  (int *arr, int len, char oper);
int *check_duplicate(int *arr, int *arr_result, int len);

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

// TODO: maybe delete this?
int insert(int *arr, int index, int val)
{
    return update(arr, index, val);
}

int append(int *arr, int len, int val)
{
    static int last_appended_index = 0;
    if (last_appended_index < len) return arr[last_appended_index++] = val;
    return 0;
}

int delete(int *arr, int len, int index)
{
    if (index > len) {
        return 0;
    }
    return arr[index] = 0;
}

int search(int *arr, int len, int val)
{
    for (int i = 0; i < len; ++i)
        if (arr[i] == val) return i;
    return -1;
}

int compar_asc(const void *a, const void *b)
{
    const int *_a = a, *_b = b;
    return (*_a > *_b) - (*_a < *_b);
}

void sort_asc(int *arr, int len)
{
    qsort(arr, len, sizeof(*arr), compar_asc);
}

int compar_desc(const void *a, const void *b)
{
    const int *_a = a, *_b = b;
    return (*_a < *_b) - (*_a > *_b);
}

void sort_desc(int *arr, int len)
{
    qsort(arr, len, sizeof(*arr), compar_desc);
}

int merge(int *arr, int len, int *arr_one, int len_arr_one, int *arr_two, int len_arr_two)
{
    int i = 0;
    for (int j = 0; j < len_arr_one; ++j) {
        arr[i++] = arr_one[j];
        if (i >= len) return 0;
    }
    for (int k = 0; k < len_arr_two; ++k) {
        arr[i++] = arr_two[k];
        if (i >= len) return 0;
    }
    return 1;
}

int split_by_index(int *arr, int len, int *arr_one, int *arr_two, int index)
{
    if (index >= len) return 0;
    if (index <= 0) return 0;
    if (len <= 0) return 0;

    int i = 0;
    int j = 0;
    int k = 0;
    while (i < index)
        arr_one[j++] = arr[i++];
    while (i < len)
        arr_two[k++] = arr[i++];
    return 1;
}

int reverse(int *arr, int len)
{
    if (len <= 0) return 0;
    int t;
    int i = 0;

    while (i < len/2) {
        t = arr[i];
        arr[i] = arr[len-i-1];
        arr[len-i-1] = t;
        i++;
    }
    return i;
}

int *slice(int *arr, int *arr_result, int len, int from, int to)
{
    // TODO: check it properly 100% here is a bug :)
    if (len <= 0 || from < 0 || from >= len || to <= 0 || to >= len) return (void *)0;

    int j = 0;
    for (int i = 0; i < len; ++i) {
        if (i >= from && i <= to)
            arr_result[j++] = arr[i];
    }
    return arr_result;
}

int map(char op, int *arr, int len)
{
    int result = 0;

    switch (op) {
        case '+': {
            for (int i = 0; i < len; ++i)
                result += arr[i];
            break;
        }
        case '-': {
            for (int i = 0; i < len; ++i)
                result -= arr[i];
            break;
        }
        case '*': {
            result = 1;
            for (int i = 0; i < len; ++i)
                result *= arr[i];
            break;
        }
        case '/': {
            int i = 0;
            for (; i < len; ++i)
                result += arr[i];
            result /= i;
            break;
        }
        default : {
            return 0;
        }
    }
    return result;
}

int *filter(int *arr, int len, int min, int max)
{
    for (int i = 0; i < len; ++i) {
        if (arr[i] < min || arr[i] > max)
            arr[i] = 0;
    }
    return arr;
}

int reduce(int *arr, int len, char oper)
{
    return map(oper, arr, len);
}

int *check_duplicate(int *arr, int *arr_result, int len)
{
    qsort(arr, len, sizeof(*arr), compar_asc);

    int j = 0, i = 0;
    for (; i < len; ++i) {
        if (arr[i] != arr[i-1])
            arr_result[j++] = arr[i];
        else
            arr_result[j++] = 0;
    }
    // one more
    if (arr[i] != arr[i-1])
        arr_result[j++] = arr[i];
    else
        arr_result[j++] = 0;

    return arr_result;
}

#endif // LIB_ARR_IMPLEMENTATION
#endif // LIB_ARR_H
