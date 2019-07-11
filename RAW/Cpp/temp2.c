#include<stdio.h>


int main()
{
    char x[100];
    gets(x);
    test(x);
}

void test(char x[100]){
puts(x);
}
