#include <iostream>
#include <cctype>
#include <fstream>
#include "heap_sort.h"
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


