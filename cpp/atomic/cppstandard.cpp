#include <atomic>
#include <thread>
#include <iostream>
#include "stdlib.h"
using namespace std;

atomic<int> a{0};
int b = 0;
void thread_function1()
{

    a.store(1, memory_order_release);
    _sleep(25);
    b = 1;
}

void thread_function2()
{
    while (a.load(memory_order_acquire) != 1)
        ;
    cout << b << endl;
}

int main()
{
    thread thread1(thread_function1);
    thread thread2(thread_function2);
    thread1.join();
    thread2.join();
    system("pause");
}