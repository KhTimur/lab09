#include <iostream>
#include <iterator>
#include <algorithm>


void inser(int * begi, int *en)
{
    for(int *ptr  = begi; ptr != en; ptr++)
        for(int *j=ptr; j != begi && *(j-1)>*j;j--)
	    {
	      std::swap(*(j-1),*j);
            }
}

void inplmerg (int* begi, int* middle, int* en)
{
   int const siz = std::distance(begi, en);
   int num[siz];
   int k=0;
   int j=0;
   int i=0;
   while( ((begi+i)<middle) && ((middle+k)<en)  )
       if(*(begi+i) < *(middle+k))
          {
            num[j]=*(begi+i);
            i++;
            j++;
          }
       else
          {
            num[j]=*(middle+k);
            k++;
            j++;
          }
   while ((begi+i)<middle)
        {
            num[j]=*(begi+i);
            i++;
            j++;
        }
   while ((middle+k)<en)
        {
            num[j]=*(middle+k);
            k++;
            j++;
        }
   for (int i = 0; i<siz; i++)
      {
        *(begi+i)=num[i];
      }
}


void merge_sort(int * begi, int *en)
{
    int const siz = std::distance(begi, en);
    if (siz <= 1) return;
    int * const middle = begi+( siz / 2);
    merge_sort(begi, middle);
    merge_sort(middle, en);
    inplmerg(begi, middle, en);
}


void downHeap(int * t, int * en) {
  int const siz = std::distance(t, en);
  int *k= en-(siz/2)-1;
    while (k>=t)
    {
        int a=std::distance(t, k);
        if(*k> *(k+a))
            {
                std::swap(*k,*(k+a));
            }
        if(*k>*(k+a+1) && (k+a+1)!=en)
            {
                std::swap(*k,*(k+a+1));
            }
        k--;
    }
}




void heapSort(int *begi , int *en)
{

    int *t=begi;
    while(t<en)
    {
        downHeap(t, en);
        t++;
    }
}

int * Partition(  int * left, int * right)
  {
      int const siz = std::distance(left, right);
      int * pivot = left+(siz / 2);
      std::swap(*pivot, *(right-1));
      int * j=left;
      for (int * i=left; i<(right-1);i++)
      {
          if (*i<*(right-1))
          {
              std::swap(*i,*j);
              j++;
          }
      }
      std::swap(*j,*(right-1));
      return j;
  }

void quick_sort( int * begi, int * en )
{
     int const siz = std::distance(begi, en);
     if (siz>0)
     {
     int * g=Partition( begi, en);
     quick_sort( begi, g );
     quick_sort( g+1, en );
     }

}




