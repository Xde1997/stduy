#include <istream>
#include "IntArray.h"
using namespace std;

template <class T>
class Apply
{
public:
    float GetSum(T &t, float inarg)
    {
        return t.GetSum(inarg);
    }
};
template <class T>
class NumTraits
{
};

template <>
class NumTraits<IntArray>
{
public:
    typedef int resulttype;
    typedef int inputargtype;
};

template <>
class NumTraits<FloatArray>
{
public:
    typedef float resulttype;
    typedef float inputargtype;
};

template <class T>
class Apply2
{
public:
    typename NumTraits<T>::resulttype GetSum(T &obj, typename NumTraits<T>::inputargtype inputarg)
    {
        return obj.GetSum(inputarg);
    }
};

int main()
{
    IntArray intary;
    FloatArray floatary;
    Apply<IntArray> ai;
    Apply<FloatArray> af;

    cout << "1整形数组的和的3倍" << ai.GetSum(intary, 3) << endl;
    cout << "1浮点型数组的和的3.2倍" << af.GetSum(floatary, 3.2f) << endl;
    cout << endl;
    cout << endl;

    Apply2<IntArray> ai2;
    Apply2<FloatArray> af2;

    cout << "2整形数组的和的3倍" << ai2.GetSum(intary, 3) << endl;
    cout << "2浮点型数组的和的3.2倍" << af2.GetSum(floatary, 3.2f) << endl;
    system("pause");
    return 0;
}