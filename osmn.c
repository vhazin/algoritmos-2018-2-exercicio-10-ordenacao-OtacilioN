#include <stdio.h>
#include <string.h>

#define MAX_CHILD_NAME_LENGTH 21
#define MAX_CHILDREN 101

typedef struct child_s
{
    char name[MAX_CHILD_NAME_LENGTH];
} child;

void swap(child *a, child *b);
int partition(child arr[], int low, int high);
void quickSort(child arr[], int low, int high);

int main(void)
{
    char tmp, x, counter = 0;
    child children[MAX_CHILDREN];
    int length;

    scanf("%d", &length);
    for (x = 0; x < length; x++)
    {
        scanf(" %c ", &tmp);
        if (tmp == '+')
            counter++;
        scanf("%s", children[x].name);
    }
    quickSort(children, 0, length - 1);
    for (x = 0; x < length; x++)
    {
        printf("%s\n", children[x].name);
    }
    printf("Se comportaram: %d | Nao se comportaram: %d\n", counter, length - counter);
    return 0;
}

void swap(child *a, child *b)
{
    child t = *a;
    *a = *b;
    *b = t;
}

int partition(child arr[], int low, int high)
{
    int i = (low - 1);
    int x = 0;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (strcmp(arr[j].name, arr[high].name) <= 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(child arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}