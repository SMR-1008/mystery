#include<stdio.h>
int ten_to_eight(int m);
int ten_to_sixteen(int m);
int eight_to_sixteen(int m);
int sixteen_to_eight(int m);
int eight_to_ten(int m);
int sixteen_to_ten(int m);
int main()
{
    printf("进制转换(输入0退出程序)\n1:10to8\n2:10to16\n3:8to16\n4:16to8\n5:8to10\n6:16to10");
    while(1)
    {
        printf("\n请输入序号:");
        int n;
        int count;

        scanf("%d",&count);
        if(count==1)
        {
            scanf("%d",&n);
            ten_to_eight(n);
        }

        else if(count==2)
        {
            scanf("%d",&n);
            ten_to_sixteen(n);
        }
        else if(count==3)
        {
            scanf("%o",&n);
            eight_to_sixteen(n);
        }
        else if(count==4)
        {
            scanf("%x",&n);
            sixteen_to_eight(n);
        }
        else if(count==5)
        {
            scanf("%o",&n);
            eight_to_ten(n);
        }
        else if(count==6)
        {
            scanf("%x",&n);
            sixteen_to_ten(n);
        }
        else if(count==0)
        {
            break;
        }
        else
        {
            printf("警告！未找到对应转换");
        }
    }

    return 0;
}
    //十进制转八进制
   int ten_to_eight(int m)
    {
        printf("%o",m);
        return m;
    }



    //十进制转十六进制
    int ten_to_sixteen(int m)
    {
        printf("%x",m);
        return m;
    }



    //八进制转十六进制
    int eight_to_sixteen(int m)
    {
        printf("%x",m);
        return m;
    }


    //十六进制转八进制
    int sixteen_to_eight(int m)
    {
        printf("%o",m);
        return m;
    }


    //八进制转十进制
    int eight_to_ten(int m)
    {
        printf("%d",m);
        return m;
    }


    //十六进制转十进制
    int sixteen_to_ten(int m)
    {
        printf("%d",m);
        return m;
    }


