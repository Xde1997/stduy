#include <iostream>
#include <list>
using namespace std;

class test
{
    int a;
    int b;
};

int main()
{
    auto a=new list<test*>();
    a->push_back(new test());
    return 0;
}