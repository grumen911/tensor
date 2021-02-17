
template<class T>
Tensor<T>::Tensor(size_t M1, size_t* s1, T *mas1)
{
    M = M1;
    s = s1;
    S = 1;
    for(int i=0;i<M;i++){
        S *= s[i];
    }
    mas = mas1;
};

template<class T>
Tensor<T>::Tensor(size_t M1, size_t* s1)
{
    M = M1;
    s = s1;
    S = 1;
    for(int i=0;i<M;i++){
        S *= s[i];
    }
    mas = new T[S];    
    for (int i = 0; i < S; i++)
        mas[i] = 69;
}

template<class T>
size_t Tensor<T>::func(size_t n[])
{// n - индексы
    size_t f = 1;
    for(size_t i=0;i<M;i++)
    {
       f = n[M-i-1] + s[M-i-1]*(f - 1) ;
    }
    return f;    
}

template<class T>
T Tensor<T>::operator()(size_t n[])
{// n - индексы
    for (size_t i=0; i<M; i++)
    {
        try {if(n[i] > s[i] || n[i]==0) throw std::range_error("test");}
        catch (std::range_error) { 
            std::cerr << "Error Tensor's index in Tensor<T>::operator()(size_t n[])" << std::endl;
            exit(-1);
        }
    }

    size_t f = 1;
    for(size_t i=0;i<M;i++)
    {
       f = n[M-i-1] + s[M-i-1]*(f - 1) ;
    }
    return mas[f-1];    
}
template<class T>
size_t Tensor<T>::get_size(size_t dim)
{ 
    try {if(dim == 0 || dim > M) throw std::range_error("test");}
    catch (std::range_error) { 
        std::cerr << "Error Tensor's dim in Tensor<T>::get_size(size_t dim)" << std::endl;
        exit(-1);
    }
    return s[dim-1];
}

int func(int m[],int n[], int M) // m - ограничения n - индексы
{
    int f = 1 ;
    for(int i=0;i<M;i++)
    {
       f = n[M-i-1] + m[M-i-1]*(f - 1) ;
    }
    return f;
}

    /* проверка функции func
        int m[4] = {3,4,5,6};
    {
    for(int k=1;k<=m[2];k++)
    {
    for(int j=1;j<=m[1];j++)
    { 
    for(int i=1;i<=m[0];i++)
    {
        int n[4] = {i,j,k,l};
        std::cout << func(m,n,4)<< std::endl;

    }
    }
    }
    }
    */