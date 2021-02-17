#include <stdio.h>
#include <iostream>
#include "Tensor.h"

int main()
{
    size_t M = 3;
    size_t s[M] = {3,4,5};
    int a[60];
    a[0] = 1;
    Tensor<int> e(M,s);
    //e.mas[0] = 1;
    //for(size_t i=0;i<1;i++)
    size_t j[3] = {3,4,5};
    std::cout << e(j)<<std::endl;
    std::cout << e.get_size(3)<<std::endl;
    return 0;
}