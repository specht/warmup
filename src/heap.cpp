#include <vector>
#include <stdio.h>

using namespace std;


typedef std::vector<int> Heap;


void insert(Heap& heap, int v)
{
	// append to end of heap
	heap.push_back(v);
	
	// sift up!
	int i = heap.size() - 1;
	while (i > 0 && heap[i] > heap[i >> 1])
	{
		int temp = heap[i];
		heap[i] = heap[i >> 1];
		heap[i >> 1] = temp;
		i >>= 1;
	}
}


int pop(Heap& h)
{
	// return head
	int result = h[0];
	
	// move last element to head
	h[0] = h[h.size() - 1];
	h.pop_back();
	
	// sift down!
	int i = 0;
	while (1)
	{
		// our node has no children, everything is fine. stop, hammertime!
		if (i << 1 + 1 >= h.size())
			break;
		int other = i * 2 + 1;
		if (other + 1 < h.size())
			if (h[other + 1] > h[other])
				++other;
		if (h[i] >= h[other])
			// heap is good!
			break;
		int temp = h[i];
		h[i] = h[other];
		h[other] = temp;
		i = other;
	}
	return result;
}


void print(const Heap h)
{
	for (int i = 0; i < h.size(); ++i)
		printf("%d ", h[i]);
	printf("\n");
	printf("\n");
}


int main(int argc, char** argv)
{
	Heap h;
	insert(h, 2);
	print(h);
	insert(h, 17);
	print(h);
	insert(h, 7);
	print(h);
	insert(h, 19);
	print(h);
	insert(h, 3);
	print(h);
	insert(h, 36);
	print(h);
	insert(h, 100);
	print(h);
	insert(h, 1);
	print(h);
	insert(h, 25);
	print(h);
	
	while (h.size() > 0)
	{
		printf("pop: %d\n", pop(h));
		print(h);
	}
	return 0;
}
