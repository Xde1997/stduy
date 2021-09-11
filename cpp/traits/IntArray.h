#include <iostream>
using namespace std;
class IntArray
{
public:
    IntArray()
    {
        a = new int[10];
        for (int i = 0; i < 10; i++)
        {
            a[i] = i + 1;
        }
    }
    ~IntArray()
    {
        delete[] a;
    }
    int GetSum(int times)
    {
        int sum = 0;
        for (int i = 0; i < 10; i++)
        {
            sum += i;
        }
        cout << "int sum=" << sum << endl;
        return sum * times;
    }

private:
    int *a;
};
class FloatArray
{
public:
    FloatArray()
    {
        a = new float[10];
        for (int i = 0; i < 10; i++)
        {
            a[i] = i + 1;
        }
    }
    ~FloatArray()
    {
        delete[] a;
    }
    int GetSum(float times)
    {
        int sum = 0;
        for (int i = 0; i < 10; i++)
        {
            sum += i;
        }
        cout << "int sum=" << sum << endl;
        return sum * times;
    }

private:
    float *a;
};