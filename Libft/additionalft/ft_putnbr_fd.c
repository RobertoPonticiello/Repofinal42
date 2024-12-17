#include <unistd.h>

void    ft_putnbr_fd(int n, int fd)
{
        char    c;

        if (n == -2147483648)
        {
                write (fd, "-2", 2);
                write (fd, "147483648", 9);
        }
        else if (n < 0)
        {
                write (fd, "-", 1);
                n = -n;
                ft_putnbr(n);
        }
        else if (n <= 9)
        {
                c = n + '0';
                write (fd, &c, 1);
        }
        else
        {
                ft_putnbr(n / 10);
                c = (n % 10) + '0';
                write (fd, &c, 1);
        }
}
