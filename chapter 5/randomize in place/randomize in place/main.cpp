//
//  main.cpp
//  randomize in place
//
//  Created by 高大伟 on 2017/2/21.
//  Copyright © 2017年 高大伟. All rights reserved.
//

#include <iostream>
#include <vector>
#include<time.h>
#include <random>
#include "MyRandom.h"
using namespace std;

vector<int> randomize_in_place(vector<int> p_array)
{
    int mn=p_array.size();
    srand((unsigned)time(NULL));
    for(int i=0;i<mn;i++)
    {
        int mrand=randint(i,mn-1);
        //swap p_array[i] and p_array[mrand]
        int mtmp = p_array[i];
        p_array[i]=p_array[mrand];
        p_array[mrand]=mtmp;
    }
    return p_array;
}

int main(int argc, const char * argv[]) {
    vector<int> marray={1,2,3,4,5,6,7,8,9};
    vector<int> mres = randomize_in_place(marray);
    for(int i : mres)
        cout<<i<<" ";
}
