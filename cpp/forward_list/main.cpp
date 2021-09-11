#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> c = {3, 4};
    c.push_front(2);
    c.push_front(1);
    auto itr = c.before_begin();
    c.insert_after(itr, 0);
    for (auto it = c.begin(); it != c.end(); it++)
    {
        cout << *it << '\t';
    }
    cout << endl;
    system("pause");
}