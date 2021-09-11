#include <iostream>
using namespace std;
class TestClass
{
public:
    TestClass() = default;
    ~TestClass() = default;
    TestClass(const int i, const char c) : member_i(i), member_c(c) {}
    TestClass(const int i) : TestClass(i, 0) { member_c = 'T'; }

public:
    int member_i;
    char member_c;
};

int main()
{
    cout << "test allocator:" << endl;
    allocator<TestClass> alloc;
    auto p = alloc.allocate(0);
    alloc.construct(p, 10, 'c');
    cout << p->member_i << '\t' << p->member_c << endl;
    system("pause");
    return 0;
}