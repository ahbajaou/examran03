#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


void    ft_putstr(const char *str, int *len)
{
    int i = 0;
    if (!str)
        write(1,"(null)\n",8);
    while (str[i])
    {
        *len += write(1,&str[i],1);
        i++;
    }
}

void    ft_putnbr(int nbr,int *len,int base)
{
    char *hex = "0123456789abcdef";
    if (nbr < 0)
    {
        nbr *= -1;
        len += write(1,"-",1);
    }
    if (nbr >= base)
        ft_putnbr((nbr / base),len,base);
    len += write(1,&hex[nbr % base],1);
}
int ft_printf(const char *str, ...)
{
    int i = 0;
    int len = 0 ;
    va_list ptr;

    va_start(ptr,str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 's')
                ft_putstr(va_arg(ptr, char *),&len);
            if (str[i] == 'd')
                ft_putnbr(va_arg(ptr,int),&len,10);
            if (str[i] == 'x')
                ft_putnbr(va_arg(ptr,int),&len,16);
        }
        else
            len += write(1,&str[i],1);
        i++;
    }
    return (va_end(ptr),len);
}
