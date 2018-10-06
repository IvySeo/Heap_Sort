/*Merge Sort and Quick Sort, and Insertion Sort, a simple double-loop sort whose time is O(n2). 
it runs of the program and it confirms our theoretical observations about the several algorithms' times. 
Heap Sort implementation by counting an appropriate characteristic operation. It observes how the algorithms' times, 
as represented by the counts of characteristic operations, increase as the number of values being sorted grows, 
by running the program on several instances of several problem sizes. Which is numbers of values to sort. 
This system for the number of characteristic operations each performs in sorting the random or same values. 
Heap Sort sorts in place and its time is always O(n log n). */

#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAX = 5000;
const int MIN = 0;



// Function Declaration
void heap_sort ( int heap_array[], int n, int &counter);
void reheap_down ( int heap_array[], int root, int last, int& counter);

int main()
{
    int num, seed, value;
    char input;
    int heap_counter =0;
    
    cout << "Enter the number of values to generate and sort, between 1 and 5000:" << endl;
    cin >> num;
    cout << "Enter an integer seed value:"<<endl;
    cin >> seed;
    srand(seed);

    
    int array_heap[num];

    for(int i = 0; i<num; i++)
    {

         value = rand()%5000 + 1;
        
        array_heap[i]= value;

    }

    //Ask the user for unsorted
    cout<<"Do you want to print unsorted values: ";
    cin>>input;
    if(input=='Y'||input=='y')
    {
        print(array_quick, num);
    }

    
    heap_sort ( array_heap, num, heap_counter);

    cout<<"Do you want to print sorted values: ";
    cin>>input;
    if(input=='Y'||input=='y')
    {   
        cout<<"\nHeap Sort: ";
        print(array_heap, num);
    }
     cout<<"\nHeap Sort count:\n"<<heap_counter;
  return 0;
}
void print(int arr[], int Size)
{
    for(int i = 0; i<Size; i++)
    {
        cout<<arr[i]<<endl;
    }
}



//Heap_sort
void heap_sort ( int heap_array[], int n, int &counter)
  {

    // Build the heap in an array
    for (int i=(n-2)/2; i>=0; --i)
      reheap_down(heap_array,i,n-1, counter);

    // Tear the heap down.
    for (int i=n-1; i>0; --i)
    {
      swap ( heap_array[0], heap_array[i] );
      reheap_down ( heap_array, 0, i-1, counter);
    }

  }

void reheap_down ( int a[], int root, int last, int& counter)
  // Swaps the element initially 
  {
    int parent;
    int max_child;
    bool completed;

    parent = root;
    completed = 0;


    // While loop which restores the heap property
    while (  last>2*parent && ! completed )
    {
        counter++;    // to keep the track of operations
      max_child = 2*parent + 1;
      if ( max_child < last && a[max_child+1] > a[max_child] )
        ++max_child;
      if ( a[parent] < a[max_child] )
      { // inbuilt swap function
        swap ( a[parent], a[max_child] );    
        parent = max_child;

      }
      else
        completed = 1;    // Boolean to get out of while loop
    }
}

int A[value_MAX];
    int B[value_MAX];
    int C[value_MAX];
    int value;
    char out;
    int seed;
    Sort Merge;
    Sort Quick;
    Sort I;

    cout<<"Enter the value of values to generate and sort , between 1 and 5000:"<<endl;
    cin>>value;  
    cout<<"Enter an integer seed value :"<<endl;
    cin>>seed;
    srand(seed);

    
    for (int i=0; i<value;i++)
    {
        A[i]=(rand()%5000)+1;
        B[i]=A[i];
        C[i]=B[i];
    }
    M.SortMerge ( A, 0, value) ;
    Q.SortQuick ( B, 0, value);

    I.SortInsert(C, value);
    cout<<"Print the values?"<<endl;

    cin>>out;
    if(out=='Y'|| out=='y')
    { 
        cout<<"Array: Merge Sort::"<<endl;
        for(int m=1; m<=value; m++)
        {
            cout<<A[m]<<" ";
        }
    
        cout<<endl<<"Array: Quick Sort::"<<endl;
        for(int q=1; q<=value; q++)
        {
           cout<<B[q]<<" ";
        }
        cout<<endl<<"Array: Insertion Sort::"<<endl;
        for(int i=1; i<=value; i++)
        {
             cout<<C[i]<<" ";
        }
    }
    cout<<" Count Merge Sort = "<<Merge.size()<<endl;
    cout<<"Count Quick Sort = "<<Quick.size()<<endl;
    cout<<"Count Insertion Sort = "<<I.size()<<endl;

	return 0;

#include <iostream>
#include <cctype>
#include <fstream>
#include "project9.h"
using namespace std;

void merge_sort ( Item a[], size_t low, size_t high )
  {
    size_t mid;

    if ( low < high )
    {
      mid = (low + high) / 2;
      merge_sort ( a, low, mid );
      merge_sort ( a, mid+1, high );
      merge ( a, low, mid, high );
    }
  }

void merge ( Item a[], size_t low, size_t mid, size_t high )
  {
    Item b[MAX];
    size_t i1, i2, index;

    for (size_t i=low; i<= high; ++i)
      b[i] = a[i];
  
    i1 = low;
    i2 = mid+1;
    index = low;
    while ( i1 <= mid && i2 <= high )
      if ( b[i1] < b[i2] )
        a[index++] = b[i1++];
      else
        a[index++] = b[i2++];

    while ( i1 <= mid )
      a[index++] = b[i1++];

    while ( i2 <= high )
      a[index++] = b[i2++];
  }

void quick_sort ( Item a[], int low, int high )
  {
    int i, j;

    if ( low < high )
    {
      qs_partition ( a, low, high, i, j );
      quick_sort ( a, low, i );
      quick_sort ( a, j, high );
    }
  }

void qs_partition ( Item a[], int low, int high, int &i, int &j )
  {
    Item pivot = a[low];
    int lastS1 = low - 1;
    int firstU = low;
    int firstS3 = high + 1;

    while ( firstU < firstS3 )
    {
      if ( a[firstU] < pivot )        // S1
      {
        ++lastS1;
        swap ( a[firstU],a[lastS1] );
        ++firstU;
      }
      else if ( a[firstU] == pivot )  // S2
        ++firstU;
      else  // a[firstU] > pivot      // S3
      {
        --firstS3;
        swap ( a[firstU], a[firstS3] );
      }
    }
    i = lastS1;
    j = firstS3;
  }

void qs_partition ( Item a[], int low, int high, int &i, int &j )
{
  Item pivot = a[low];
  int left = low+1;
  int right = high;

  while ( left <= right )
  {
    while ( left <= high && a[left] <= pivot )
      ++left;
    while ( a[right] > pivot )
      --right;
    if ( left < right )
      swap ( a[left], a[right] );
  }
  swap ( a[low], a[right] );
  i = right - 1;
  j = right + 1;
}


