#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

typedef std::vector<int> IntList;


void swap(IntList& list, int left, int right)
{
    int t = list[left];
    list[left] = list[right];
    list[right] = t;
}

void quicksort(IntList& list, int start, int end)
{
    if (end - start < 1)
        return;
    if (start == end - 1)
    {
        if (list[start] > list[end])
            swap(list, start, end);
        return;
    }
    int pivot = end;
    int left = start;
    int right = end - 1;
    do
    {
        while (list[left] <= list[pivot] && left < end)
            ++left;
        while (list[right] >= list[pivot] && right > start)
            --right;
        if (left < right)
            swap(list, left, right);
    } while (left < right);
    swap(list, left, pivot);
    pivot = left;
    quicksort(list, start, pivot - 1);
    quicksort(list, pivot + 1, end);
}


int main(int argc, char** argv)
{
    IntList b;
    b.push_back(3);
    b.push_back(8);
    b.push_back(9);
    b.push_back(7);
    b.push_back(1);
    b.push_back(4);
    b.push_back(6);
    
    for (IntList::const_iterator i = b.begin(); i != b.end(); ++i)
        printf("%d ", *i);
    printf("\n");

    quicksort(b, 0, b.size() - 1);

    for (IntList::const_iterator i = b.begin(); i != b.end(); ++i)
        printf("%d ", *i);
    printf("\n");

}
