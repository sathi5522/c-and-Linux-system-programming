#include<stdio.h>

int main()
{

        struct obj{
                int a;
                int b;
        };
        struct obj ob[2];
        
        ob[0].a = 10;
        ob[0].b = 30;
        ob[1].a = 20;
        ob[1].b = 40;
        
        
        printf("%d %d %d %d\n",ob[0].a,ob[0].b,ob[1].a,ob[1].b);

        return 0;

}

