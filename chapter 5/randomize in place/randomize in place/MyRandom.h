//
//  MyRandom.h
//  randomize in place
//
//  Created by 高大伟 on 2017/2/21.
//  Copyright © 2017年 高大伟. All rights reserved.
//

#ifndef MyRandom_h
#define MyRandom_h


#endif /* MyRandom_h */
#ifndef Header_h
#define Header_h


#endif /* Header_h */
#include<random>
#include<vector>


/**
 product a random integer in [begin, end], where p_begin<p_end
 
 @param p_begin the range of random int
 @param p_end the range of random int
 @return an random integer in [begin, end]
 */
int randint(int p_begin, int p_end)
{
    int mres=random()%(p_end-p_begin+1)+p_begin;
    return mres;
}

int randint()
{
    return random();
}

/**
 return a random integer in the array p_array
 
 @param p_array the vector array of integer
 @return a random integer in the array
 */
int randint(std::vector<int> p_array)
{
    if(!p_array.empty())
        return p_array[randint(0,p_array.size()-1)];
    else
        return -1;
}

/**
 return a double in [p_begin, p_end], where p_begin<p_end
 
 @param p_begin the range of random double
 @param p_end the range of random double
 @return an random double in [begin, end]
 */
double randdouble(double p_begin,double p_end)
{
    if(p_begin<p_end)
    {
        double mres=(double)randint()/(double)RAND_MAX*(p_end-p_begin)+p_begin;
        return mres;
    }
    else
        return p_begin-1;
}
