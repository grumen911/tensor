

template <class T> 
class Tensor
{
public:
    size_t  M;   //Порядок тензора  
    size_t* s;   //Размерности тензора
    size_t  S;   //Кол-во объектов тензора
    T    *mas;   //Данные тензора
    Tensor() : M(0),s(nullptr),mas(nullptr) {};
    //Конструктор по умолчанию

    Tensor(size_t M1, size_t* s1, T *mas1);
    ///  \param (порядок, размерности, *массив )

    Tensor(size_t M1, size_t* s1);
    /// Инициализирует тензор типа <T> и выделяет ему память 
    /// \param (порядок, размерности)

    //Tensor(size_t M, const size_t&, const T(*_mas)){};//Конструктор из массива

    T operator()(size_t n[]); 
    //Оператор обращения к элементам тензора

    size_t func(size_t n[]); 
    // функция получения индекса в mas зная n = {i,j,k,....}

    size_t get_order(){ return M;};

    size_t get_size(size_t dim);
    
    Tensor(const Tensor& ten){}; 
    //Конструктор копирования

    ~Tensor(){} 
    //Деструктор класса

    
};
#include "Tensor.inl"