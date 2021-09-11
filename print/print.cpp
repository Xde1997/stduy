#include "stdio.h"
#include "stdlib.h"
#include "wchar.h"
#include "locale.h"
int main(int argc,char** argv){
    char test[]="测试Test";
    setlocale(LC_ALL,"zh_CN.UTF-8");
    wchar_t wtest[]=L"0m~kiadwdjoaif";
    printf("printf:%S\n",wtest);
    wprintf(L"wprintf:%S\n",wtest);
    int ret=fwide(stdout,0);
    printf("file mode=%d\n",ret);
    system("pause");
}