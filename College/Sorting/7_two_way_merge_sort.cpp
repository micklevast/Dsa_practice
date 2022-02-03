// PS: two way merge sort algorithm

#include<iostream>
using namespace std;
class SortableList
{
public:
	SortableList(int mSize)
	{
		maxSize = mSize;
	  l= new int[maxSize];
		n = 0;
	}
	~SortableList()
	{
		delete[]l;
	}
	void Merge(int, int, int);
	void MergeSort(int,int);
	void Input();
	void Output();
	
   private:
		 int* l;
		 int maxSize;
		 int n;

};
void SortableList::Input()
{
	Cout < "please enter the number to sort":;
	for (int i = 0; i <= maxSize - 1; i++)
		cin >> l[i];
}
void SortableList::Output()
{
	Cout < "the sorted number is:;
	for (int i = 0; i <= maxSize - 1; i++)
		cout << l[i]<<' ';
}
void SortableList::MergeSort(int left,int right)
{
	If (left < right) // if the sequence length is greater than 1
	{
		int mid = (left + right) / 2;
		Mergesort (left, mid); // sort the left sequence
		Mergesort (mid + 1, right); // sort the right sequence
		Merge (left, mid, right); // merge
	}
}
void SortableList::Merge(int left, int mid, int right)
{
	int* temp= new int[right - left + 1];
	int i = left, j = mid + 1, k = 0;
	While ((I < = mid) & amp; (J < = right)) // judge whether the sequence is empty
		if (l[i] <= l[j])
			temp[k++] = l[i++];
		else temp[k++] = l[j++];
	while (i <= mid)
		Temp [K + +] = l [i + +]; // the right sequence is empty, and the left sequence is written in turn
	while (j <= right)
		Temp [K + +] = l [J + +]; // the left sequence is empty, and the right sequence is written in turn
	for (i = 0, k = left; k <= right;)
		L [K + +] = temp [i + +]; // put the temporarily arranged data in the array temp into the array L
}
int main()
{
	int m;
	Cout < "please enter the number of numbers to sort":;
	cin >> m;
	SortableList a1(m);
	a1.Input();
	a1.MergeSort(0, m-1);
	a1.Output();
}