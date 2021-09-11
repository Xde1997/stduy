#include <regex.h>
#include <iostream>
#include <sys/types.h>
#include <stdio.h>
#include <cstring>
#include <sys/time.h>

using namespace std;

const int time = 1000000;
int main(int argc, char **argv)
{
    char pattern[512] = "finance\.sina\.cn|stock1\.sina\.cn|3g\.sina\.com\.cn.*(channel=finance|_finance$|ch=stock|/stoc k/)|dp.sina.cn/.*ch=9&";
    const size_t nmatch = 10;
    regmatch_t pm[10];
    int z;
    regex_t reg;
}