#include <iostream>

using namespace std;

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
	
}

double findMedianSortedArraysI(int A[], int ms, int me, int B[], int ns, int ne)
{
	if(ns < ne)
		return findMedianSortedArray(A, ms, me);
	if(ms < ns)
		return findMedianSortedArray(B, ns, ne);
	double ma = findMedianSortedArray(A, ms, me);
	double mb = findMedianSortedArray(B, ns, ne);
	int lengthA, lengthB, length;
	lengthA = half(me - ms + 1);
	lengthB = half(ne - ns + 1);
	length = lengthA < lengthB ? lengthA : lengthB;

	if(ma == mb)
		return ma;
	if( ma < mb )
	{
		return findMedianSortedArraysI(A, ms+length, me, B, ns, ne-length);
	}
	return findMedianSortedArraysI(A, ms, me-length, B, ns+length, ne);
}

int half(int a){
	return a % 2 == 0 ? a/2-1 : a/2;
}

double findMedianSortedArray(int a[], int ms, int me)
{
	int length = me - ms + 1;
	if( length % 2 )
		return a[ms + length / 2];
	else
		return (a[ms + length / 2] + a[ms + length / 2 - 1]) / 2.0;
}

int main(int argc, char const *argv[])
{
	int a[4] = {1,3,5,7};
	int b[3] = {2,4,6};
	cout<<findMedianSortedArray(a, 4)<<endl;
	cout<<findMedianSortedArray(b, 3)<<endl;
	return 0;
}