#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

// INT_MAX

void put_str(char *str, int *rtrn)
{
    if(!str)
        str = "(null)";
    while(*str)
    {
        *rtrn += write(1, str, 1);
        str++;
    }
}

void put_digit(long long int n, int base,int *rtrn)
{
    char *nums;
    long long nbr;
    
    nbr = n;
    nums = "0123456789abxcdef";
    if(nbr < 0)
    {
        nbr *= -1;
        *rtrn += write(1, "-", 1);
    }
    if(nbr > base)// 250:0 , 25:5 , 
    {
        put_digit(nbr/base, base, rtrn);  //250/10  
        rtrn += write(1, &nums[nbr%base], 1);
    }
    else
        rtrn += write(1, &nums[nbr], 1);
}
int ft_printf(char *format, ...)
{
    int     rtrn;
    va_list ptr;

    rtrn = 0;
    va_start(ptr, format);
    while(*format)
    {
        if(*format == '%' && *(format + 1))
        {
            format++;
            if(*format == 'd')
                put_digit((long long int)va_arg(ptr, int), 10, &rtrn);
            else if(*format == 's')
                put_str(va_arg(ptr, char *), &rtrn);
            else if(*format == 'x')
                put_digit((long long int)va_arg(ptr, unsigned int), 16, &rtrn);
        }
        else
            rtrn += write(1, format, 1);
        format++;
    }
    return(va_end(ptr), rtrn);
}
#include <stdio.h>

int main()
{
    ft_printf("your str is %s\n", "string");
    printf("your str is %s\n", "string");

    ft_printf("your digit is %d\n", -21474836480055);
    // printf("your digit is %d\n", -2147483648);

    ft_printf("your hex_digit is %x\n", 18);
    printf("your hex_digit is %x\n", 18);

    return 0;
}
