//
//  main.cpp
//  maximum subarray
//
//  Created by 高大伟 on 2016/12/16.
//  Copyright © 2016年 高大伟. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct maximum_subarray{
    int m_nLow,m_nHigh;
    double m_dSum;
    maximum_subarray(int p_nLow,int p_nHigh,double p_dSum)
    {
        m_nLow=p_nLow;
        m_nHigh=p_nHigh;
        m_dSum=p_dSum;
    }
    maximum_subarray()
    {
        m_nLow=0;
        m_nHigh=0;
        m_dSum=0;
    }
};

maximum_subarray FIND_MAX_CROSSING_SUBARRAY(vector<double> p_vecArray, int p_nLow, int p_nMid, int p_nHigh)
{
    //left
    double l_dSum=0;
    double l_dLeftSum=0;
    bool l_bFirst=true;
    int l_nMaxLeft=0;
    for(int i=p_nMid;i>=p_nLow;i--)
    {
        l_dSum+=p_vecArray[i];
        if(l_dSum>l_dLeftSum || l_bFirst)
        {
            l_dLeftSum=l_dSum;
            l_nMaxLeft=i;
            l_bFirst=false;
        }
    }
    //right
    l_dSum=0;
    double l_dRightSum=0;
    int l_nMAxRight=0;
    l_bFirst=true;
    for(int i=p_nMid+1;i<=p_nHigh;i++)
    {
        l_dSum+=p_vecArray[i];
        if(l_dSum>l_dRightSum || l_bFirst)
        {
            l_dRightSum=l_dSum;
            l_nMAxRight=i;
            l_bFirst=false;
        }
    }
    return maximum_subarray(l_nMaxLeft, l_nMAxRight, l_dLeftSum+l_dRightSum);
    
}

maximum_subarray FIND_MAXIMUM_SUBARRAY(vector<double> p_vecArray,int p_nLow,int p_nHigh)
{
    if(p_nLow==p_nHigh)
        return maximum_subarray(p_nLow,p_nHigh,p_vecArray[p_nLow]);
    else
    {
        int l_nMid=floor((p_nLow+p_nHigh)/2.0);
        maximum_subarray SLeftSubarray=FIND_MAXIMUM_SUBARRAY(p_vecArray, p_nLow, l_nMid);
        maximum_subarray SRightSubarray=FIND_MAXIMUM_SUBARRAY(p_vecArray, l_nMid+1, p_nHigh);
        maximum_subarray SCrossSubarray=FIND_MAX_CROSSING_SUBARRAY(p_vecArray, p_nLow, l_nMid, p_nHigh);
        if(SLeftSubarray.m_dSum>SRightSubarray.m_dSum)
            if(SLeftSubarray.m_dSum>SCrossSubarray.m_dSum)
                return SLeftSubarray;
            else
                return SCrossSubarray;
        else
            if(SRightSubarray.m_dSum>SCrossSubarray.m_dSum)
                return SRightSubarray;
            else
                return SCrossSubarray;
    }
}

int main(int argc, const char * argv[]) {
    //input
    int l_ntmp;
    vector<double> l_vecArray;
    cout<<"input the size of the array:"<<endl;
    int l_nSize;
    cin>>l_nSize;
    cout<<"input the array:"<<endl;
    for(int i=0;i<l_nSize;i++)
    {
        cin>>l_ntmp;
        l_vecArray.push_back(l_ntmp);
    }
    //FIND_MAXIMUM_SUBARRAY
    if(l_vecArray.size()!=0)
    {
        maximum_subarray SRes= FIND_MAXIMUM_SUBARRAY(l_vecArray,0,l_vecArray.size()-1);
        for(int i=SRes.m_nLow;i<=SRes.m_nHigh;i++)
        {
            cout<<l_vecArray[i]<<" ";
        }
        cout<<endl<<"sum: "<<SRes.m_dSum<<endl;
    }
    else
        cout<<"no input."<<endl;
}
