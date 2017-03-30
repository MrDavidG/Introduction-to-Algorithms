//
//  main.cpp
//  Select
//
//  Created by 高大伟 on 2017/3/30.
//  Copyright © 2017年 高大伟. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<double> &A, int p, int r)
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

int Randomzed_Partition(vector<double> &A, int p, int r)
{
    srand((unsigned)time(NULL));
    int i=rand()%(r-p+1)+p;
    int mtmp=A[r];
    A[r]=A[i];
    A[i]=mtmp;
    return Partition(A, p, r);
}

double Randomzed_Select(vector<double> &A, int p, int r, int i)
{
    if(p==r)
        return A[p];
    int q=Randomzed_Partition(A,p,r);
    int k=q-p+1;
    if(i==k)
        return A[q];
    else
        if(i<k)
            return Randomzed_Select(A, p, q-1, i);
        else
            return Randomzed_Select(A, q+1, r, i-k);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<double> marray={9,8,7,6,5,4,3,2,1};
    cout<<Randomzed_Select(marray, 0, (int)marray.size()-1, 8)<<endl;
    return 0;
}
