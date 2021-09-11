#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main()
{
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < 10; i++)
    {
        cout << rand() << '\t';
    }
    cout << endl;
    system("pause");
    return 0;
}