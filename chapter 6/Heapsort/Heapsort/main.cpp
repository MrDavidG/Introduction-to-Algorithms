//
//  main.cpp
//  Heapsort
//      the time cost is O(nlgn).
//  Created by 高大伟 on 2017/3/7.
//  Copyright © 2017年 高大伟. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int parent(int i)
{
    return floor(i/2);
}

int left(int i)
{
    return 2*i+1;
}

int right(int i)
{
    return 2*i+2;
}

template<class T> class myvector : public vector<T>{
public:
    int heap_size;
};

/**
 维护最大堆的性质

 @param parray <#parray description#>
 @param i the index of parray from 0 to parray.size()-1
 */
void max_heapify(myvector<int> &parray, int i)
{
    int l=left(i);
    int r=right(i);
    int mlargest;
    if(l<parray.heap_size &&parray[l]>parray[i])
        mlargest = l;
    else
        mlargest = i;
    if(r<parray.heap_size && parray[r]>parray[mlargest])
        mlargest=r;
    if(mlargest != i)
    {
        int mtmp=parray[i];
        parray[i]=parray[mlargest];
        parray[mlargest]=mtmp;
        max_heapify(parray, mlargest);
    }
}

/**
 O(n) to build a max-heap

 @param parray <#parray description#>
 */
void build_max_heap(myvector<int> &parray)
{
    parray.heap_size=parray.size();
    for(int i=floor(parray.size()/2)-1;i>=0;i--)
    {
        max_heapify(parray, i);
    }
}

void heapsort(myvector<int> &parray)
{
    build_max_heap(parray);
    for(int i=parray.size()-1;i>=1;i--)
    {
        int mtmp=parray[i];
        parray[i]=parray[0];
        parray[0]=mtmp;
        
        parray.heap_size--;
        max_heapify(parray, 0);
    }
}

int main(int argc, const char * argv[]) {
    myvector<int> mvec;
    for(int i=1;i<10;i++)
        mvec.push_back(i);
    heapsort(mvec);
    for(int i: mvec)
        cout<<i<<" ";
    return 0;
}
