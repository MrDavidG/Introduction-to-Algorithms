//
//  main.cpp
//  QuickSort
//
//  Created by 高大伟 on 2017/3/23.
//  Copyright © 2017年 高大伟. All rights reserved.
//

#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <time.h>
using namespace std;

int Partition(vector<int> &A, int p, int r)
{
    int x=A[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
            i++;
            int mtmp=A[j];
            A[j]=A[i];
            A[i]=mtmp;
        }
    }
    int mtmp=A[r];
    A[r]=A[i+1];
    A[i+1]=mtmp;
    return i+1;
}

void QuickSort(vector<int> &A, int p, int r)
{
    if(p<r)
    {
        int q=Partition(A,p,r);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
}

int Random_Partition(vector<int> &A, int p, int r)
{
    srand((unsigned)time(NULL));
    int i=rand()%(r-p+1)+p;
    int mtmp=A[r];
    A[r]=A[i];
    A[i]=mtmp;
    return Partition(A, p, r);
}

void Random_QuickSort(vector<int> &A, int p,int r)
{
    if(p<r)
    {
        int q=Random_Partition(A,p,r);
        Random_QuickSort(A, p, q-1);
        Random_QuickSort(A, q+1, r);
    }
}

int main(int argc, const char * argv[]) {
    vector<int> A = {5,4,3,2,1};
    vector<int> B = A;
    cout<<"快速排序："<<endl;
    QuickSort(A, 0, (int)A.size()-1);
    for(int i : A)
        cout<<i<<"  ";
    cout<<endl<<"随机快速排序："<<endl;
    Random_QuickSort(B, 0, (int)B.size()-1);
    for(int i : B)
        cout<<i<<"  ";
    return 0;
}
