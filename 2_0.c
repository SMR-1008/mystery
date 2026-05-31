#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// 函数声明
double ten_to_two(double m);
double ten_to_eight(double m);
double ten_to_sixteen(double m);

double two_to_ten(double m);
double two_to_eight(double m);
double two_to_sixteen(double m);

double eight_to_ten(double m);
double eight_to_two(double m);
double eight_to_sixteen(double m);

double sixteen_to_ten(double m);
double sixteen_to_two(double m);
double sixteen_to_eight(double m);

// 辅助转换函数声明
double base_to_double(const char *str, int base);
void print_double_in_base(double val, int base);

int main()
{
    printf("进制转换(输入0退出程序)\n");
    printf("1:10to2    2:10to8    3:10to16\n");
    printf("4:2to10    5:2to8     6:2to16\n");
    printf("7:8to10    8:8to2     9:8to16\n");
    printf("10:16to10  11:16to2   12:16to8\n");

    while(1)
    {
        printf("\n请输入序号:");
        int count;
        double n;
        char str[100];

        // 避免输入非数字时产生死循环
        if (scanf("%d", &count) != 1)
        {
            while (getchar() != '\n');
            continue;
        }

        if (count == 0)
        {
            break;
        }

        if(count == 1)
        {
            scanf("%lf", &n);
            ten_to_two(n);
        }
        else if(count == 2)
        {
            scanf("%lf", &n);
            ten_to_eight(n);
        }
        else if(count == 3)
        {
            scanf("%lf", &n);
            ten_to_sixteen(n);
        }
        else if(count == 4)
        {
            scanf("%99s", str);
            n = base_to_double(str, 2);
            two_to_ten(n);
        }
        else if(count == 5)
        {
            scanf("%99s", str);
            n = base_to_double(str, 2);
            two_to_eight(n);
        }
        else if(count == 6)
        {
            scanf("%99s", str);
            n = base_to_double(str, 2);
            two_to_sixteen(n);
        }
        else if(count == 7)
        {
            scanf("%99s", str);
            n = base_to_double(str, 8);
            eight_to_ten(n);
        }
        else if(count == 8)
        {
            scanf("%99s", str);
            n = base_to_double(str, 8);
            eight_to_two(n);
        }
        else if(count == 9)
        {
            scanf("%99s", str);
            n = base_to_double(str, 8);
            eight_to_sixteen(n);
        }
        else if(count == 10)
        {
            scanf("%99s", str);
            n = base_to_double(str, 16);
            sixteen_to_ten(n);
        }
        else if(count == 11)
        {
            scanf("%99s", str);
            n = base_to_double(str, 16);
            sixteen_to_two(n);
        }
        else if(count == 12)
        {
            scanf("%99s", str);
            n = base_to_double(str, 16);
            sixteen_to_eight(n);
        }
        else
        {
            printf("警告！未找到对应转换");
        }
    }

    return 0;
}

// 辅助函数：将指定进制的字符串转换为 double
double base_to_double(const char *str, int base)
{
    double result = 0.0;
    int i = 0;
    int sign = 1;

    // 处理空白字符
    while (str[i] == ' ' || str[i] == '\t') i++;

    // 处理符号
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // 转换整数部分
    while (str[i] != '\0' && str[i] != '.') {
        int digit;
        char c = tolower((unsigned char)str[i]);
        if (isdigit((unsigned char)c)) {
            digit = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        } else {
            break;
        }
        if (digit >= base) break; // 超过当前进制范围

        result = result * base + digit;
        i++;
    }

    // 转换小数部分
    if (str[i] == '.') {
        i++;
        double factor = 1.0 / base;
        while (str[i] != '\0') {
            int digit;
            char c = tolower((unsigned char)str[i]);
            if (isdigit((unsigned char)c)) {
                digit = c - '0';
            } else if (c >= 'a' && c <= 'f') {
                digit = c - 'a' + 10;
            } else {
                break;
            }
            if (digit >= base) break;

            result += digit * factor;
            factor /= base;
            i++;
        }
    }

    return result * sign;
}

// 辅助函数：将 double 类型按指定进制输出，保留8位小数
void print_double_in_base(double val, int base)
{
    if (val < 0) {
        printf("-");
        val = -val;
    }

    double int_part;
    double frac_part = modf(val, &int_part);

    // 输出整数部分
    unsigned long long ip = (unsigned long long)int_part;
    if (ip == 0) {
        printf("0");
    } else {
        char buf[128];
        int idx = 0;
        while (ip > 0) {
            int digit = ip % base;
            if (digit < 10) {
                buf[idx++] = '0' + digit;
            } else {
                buf[idx++] = 'A' + (digit - 10);
            }
            ip /= base;
        }
        for (int j = idx - 1; j >= 0; j--) {
            putchar(buf[j]);
        }
    }

    // 输出小数点
    printf(".");

    // 加上微小的偏移量以减小 IEEE 754 精度丢失导致的显示偏差
    frac_part += 1e-11;
    if (frac_part >= 1.0) {
        frac_part = 0.99999999;
    }

    // 输出8位小数
    for (int i = 0; i < 8; i++) {
        frac_part *= base;
        int digit = (int)frac_part;
        if (digit >= base) digit = base - 1;
        if (digit < 10) {
            putchar('0' + digit);
        } else {
            putchar('A' + (digit - 10));
        }
        frac_part -= digit;
    }
}

// 十进制转二进制
double ten_to_two(double m)
{
    print_double_in_base(m, 2);
    return m;
}

// 十进制转八进制
double ten_to_eight(double m)
{
    print_double_in_base(m, 8);
    return m;
}

// 十进制转十六进制
double ten_to_sixteen(double m)
{
    print_double_in_base(m, 16);
    return m;
}

// 二进制转十进制
double two_to_ten(double m)
{
    printf("%.8f", m);
    return m;
}

// 二进制转八进制
double two_to_eight(double m)
{
    print_double_in_base(m, 8);
    return m;
}

// 二进制转十六进制
double two_to_sixteen(double m)
{
    print_double_in_base(m, 16);
    return m;
}

// 八进制转十进制
double eight_to_ten(double m)
{
    printf("%.8f", m);
    return m;
}

// 八进制转二进制
double eight_to_two(double m)
{
    print_double_in_base(m, 2);
    return m;
}

// 八进制转十六进制
double eight_to_sixteen(double m)
{
    print_double_in_base(m, 16);
    return m;
}

// 十六进制转十进制
double sixteen_to_ten(double m)
{
    printf("%.8f", m);
    return m;
}

// 十六进制转二进制
double sixteen_to_two(double m)
{
    print_double_in_base(m, 2);
    return m;
}

// 十六进制转八进制
double sixteen_to_eight(double m)
{
    print_double_in_base(m, 8);
    return m;
}