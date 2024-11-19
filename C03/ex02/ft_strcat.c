#include <unistd.h>

int	size(char *dest)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	s;

	s = size(dest);
	i = 0;
	while (src [i] != '\0')
	{
		dest[s + i] = src[i];
		i++;
	}
	dest[s + i] = '\0';
	return (dest);
}


/*#include <stdio.h>

char *ft_strcat(char *dest, char *src);

int main(void)
{
    char dest[50] = "Hello, "; // Dobbiamo fornire un buffer abbastanza grande
    char src[] = "world!";

    // Test concatenazione base
    printf("Prima della concatenazione:\n");
    printf("dest: \"%s\"\n", dest);
    printf("src: \"%s\"\n", src);

    // Chiamata alla funzione ft_strcat
    ft_strcat(dest, src);

    printf("\nDopo la concatenazione:\n");
    printf("dest: \"%s\"\n", dest);

    // Test con un'altra concatenazione
    char src2[] = " How are you?";
    ft_strcat(dest, src2);

    printf("\nDopo un'ulteriore concatenazione:\n");
    printf("dest: \"%s\"\n", dest);

    return 0;
}*/

