#include "BinHeap.h"
#define MinData -32768

struct HeapStruct
{
	int Capacity;
	int Size;
	int *Elements;
};

int
IsFull(PriorityQueue H)
{
	if (H->Capacity == H->Size)
	{
		return 1;
	}
	return 0;
}

int IsEmpty(PriorityQueue H)
{
	if(H->Size == 0)
		return 1
	return 0;
}

PriorityQueue 
Initialize( int MaxElements )
{
	PriorityQueue H;

	if(MaxElements < MinPQSize)
		Error( "Priority Queue size is too small" );

	H = malloc( sizeof( struct HeapStruct ) );
	if( H == NULL )
		FatalError( "Out of space !!!" );

	/* Allocate the array plus one extra for sentinel */
	H->Elements = malloc( (MaxElements + 1) * sizeof(int) );

	if(H->Elements == NULL)
		FatalError( "Out of space !!! " );

	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinData;

	return H;
}

void
Insert( int X, PriorityQueue H )
{
	int i;

	if( IsFull(H) )
	{
		Error("PriorityQueue is full ");
		return ;
	}

	for( i = ++H->Size; H->Elements[ i / 2 ] > X; i /= 2 )
		H->Elements[ i ] = H->Elements[ i / 2 ];
	H->Elements[ i ] = X;
}

int
DeleteMin( PriorityQueue H )
{
	int i, Child;
	int MinElement, LastElement;

	if (IsEmpty(H))
	{
		Error("PriorityQueue is Empty");
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];

	for (i = 0; i * 2 <= H->Size; i = Child)
	{
		/* find smaller Child */
		Child = i * 2;
		if( Child != H->Size && H->Elements[ Child + 1 ] < H->Elements[Child])
			Child++;

		/* Percolate one level */
		if(LastElement > H->Elements[Child])
			H->Elements[ i ] = H->Elements[Child]
		else
			break;
	}

	H->Elements[i] = LastElement;
	return MinElement;
}

void
PercolateDown(PriorityQueue H, int index)
{
	int i, Child;
	int indexVal = H->Elements[index];

	for(i = index; i * 2 <= H->Size; i = Child)
	{
		/* find smaller Child */
		Child = i * 2;
		if( Child != H->Size && H->Elements[ Child + 1 ] < H->Elements[Child])
			Child++;

		/* Percolate one level */
		if(indexVal > H->Elements[Child])
			H->Elements[ i ] = H->Elements[Child]
		else
			break;
	}
	H->Elements[ i ] = indexVal;
}

void
BuildHeap(PriorityQueue H, int N)
{
	int i;
	for(i = N / 2; i > 0; i--)
		PercolateDown(H, i);
}