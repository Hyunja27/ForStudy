#include <stdio.h>
#include <stdlib.h>
void merge(int a[], int l, int mid, int r)
{
    int b[100] = {0,};
    int i = l, j = r, m = mid + 1, k = 0;
    while (i <= mid && m <= j)
    {
        if (a[i] <= a[m])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[m];
            m++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (m <= r)
    {
        b[k] = a[m];
        m++;
        k++;
    }
    while (k >= 0)
    {
        a[l + k] = b[k];
        k--;
    }
}
void sort(int a[], int l , int r)
{
    int mid = l + (r - l) / 2;
    if (l < r)
    {
        sort(a, l, mid);
        sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
    else
        return;
}

int main(void)
{
    int arr[9] = {90,40,10,20,60,70,80,50,30};
    int i = 0;
    puts("\n\n[initiation array]\n");
    for (i = 0; i < 9; i++)
    {
        printf("%d ",arr[i]);
    }
    sort(arr,0,8);
    puts("\n\n[merge sorted array]\n");
    for (i = 0; i < 9; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
