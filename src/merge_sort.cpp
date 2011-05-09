#include <stdio.h>
#include <string.h>

void mergesort(int* a, int start, int end)
{
    if (start == end)
        return;
    if (end == start + 1)
    {
        // swap if necessary
        if (a[start] > a[end])
        {
            int t = a[start];
            a[start] = a[end];
            a[end] = t;
        }
        return;
    }

    int mid = (end - start) / 2 + start;
    
    mergesort(a, start, mid);
    mergesort(a, mid + 1, end);

    // now merge the two sublists
    int size = end - start + 1;
    int b[size];
    memcpy(b, a + start, size * sizeof(int));
    
    int l = start;
    int r = mid + 1;
    int *dest = a + start;
    while (true)
    {
        if (b[l - start] < b[r - start])
        {
            *(dest++) = b[l - start];
            ++l;
            if (l > mid)
                break;
        }
        else
        {
            *(dest++) = b[r - start];
            ++r;
            if (r > end)
                break;
        }
    }
    if (l > mid)
        // copy remaining entries from right half
        memcpy(dest, b + r - start, (end - r + 1) * sizeof(int));
    else
        // copy remaining entries from left half
        memcpy(dest, b + l - start, (mid - l + 1) * sizeof(int));
}

int main(int argc, char** argv)
{
    int a[7] = {3, 8, 9, 7, 1, 4, 6};
    
    for (int i = 0; i < 7; ++i)
        printf("%d ", a[i]);
    printf("\n");
    
    mergesort(a, 0, 6);
    
    for (int i = 0; i < 7; ++i)
        printf("%d ", a[i]);
    printf("\n");
}
