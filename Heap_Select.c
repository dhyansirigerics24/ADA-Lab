#include <stdio.h>
#include <time.h>

void heapcom(int a[], int n)
{
    int i, j, k, item;

    for(i = 1; i <= n; i++)
    {
        item = a[i];
        j = i;
        k = j / 2;

        while(k != 0 && item > a[k])
        {
            a[j] = a[k];
            j = k;
            k = j / 2;
        }

        a[j] = item;
    }
}

void adjust(int a[], int n)
{
    int item, i, j;

    j = 1;
    item = a[j];
    i = 2 * j;

    while(i <= n)
    {
        if((i + 1) <= n)
        {
            if(a[i] < a[i + 1])
                i++;
        }

        if(item < a[i])
        {
            a[j] = a[i];
            j = i;
            i = 2 * j;
        }
        else
            break;
    }

    a[j] = item;
}

void heapsort(int a[], int n)
{
    int i, temp;

    heapcom(a, n);

    for(i = n; i >= 1; i--)
    {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;

        adjust(a, i - 1);
    }
}

int main()
{
    int i, n, a[21], ch = 1;
    clock_t start, end;

    while(ch)
    {
        printf("\nEnter number of elements:\n");
        scanf("%d", &n);

        printf("\nEnter elements:\n");

        for(i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        start = clock();

        heapsort(a, n);

        end = clock();

        printf("\nSorted elements are:\n");

        for(i = 1; i <= n; i++)
            printf("%d\n", a[i]);

        printf("\nTime taken = %lf seconds\n",
               ((double)(end - start)) / CLOCKS_PER_SEC);

        printf("\nRun again? (0/1): ");
        scanf("%d", &ch);
    }

    return 0;
}
