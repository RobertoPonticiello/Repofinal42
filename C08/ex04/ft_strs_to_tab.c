#include <stdlib.h>
#include "ft_stock_str.h"

// Funzione per calcolare la lunghezza di una stringa
int ft_strlen(char *str)
{
    int length = 0;
    while (str[length])
        length++;
    return length;
}

// Funzione per copiare una stringa
char *ft_strdup(char *src)
{
    int len = ft_strlen(src);
    char *copy = malloc((len + 1) * sizeof(char));
    int i = 0;

    if (!copy)
        return NULL;
    while (src[i])
    {
        copy[i] = src[i];
        i++;
#include <stdlib.h>
#include "ft_stock_str.h"

// Funzione per calcolare la lunghezza di una stringa
int ft_strlen(char *str)
{
    int length = 0;
    while (str[length])
        length++;
    return length;
}

// Funzione per copiare una stringa
char *ft_strdup(char *src)
{
    int len = ft_strlen(src);
    char *copy = malloc((len + 1) * sizeof(char));
    int i = 0;

    if (!copy)
        return NULL;
    while (src[i])
    {
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}

// Funzione principale
t_stock_str *ft_strs_to_tab(int ac, char **av)
{
    t_stock_str *array;
    int i = 0;

    array = malloc((ac + 1) * sizeof(t_stock_str));
    if (!array)
        return NULL;

    while (i < ac)
    {
        array[i].size = ft_strlen(av[i]);
        array[i].str = av[i];
        array[i].copy = ft_strdup(av[i]);
        if (!array[i].copy)
        {
            free(array);
            return NULL;
        }
        i++;
    }
    array[i].str = NULL;
    return array;
}
    }
    copy[i] = '\0';
    return copy;
}

// Funzione principale
t_stock_str *ft_strs_to_tab(int ac, char **av)
{
    t_stock_str *array;
    int i = 0;

    array = malloc((ac + 1) * sizeof(t_stock_str));
    if (!array)
        return NULL;

    while (i < ac)
    {
        array[i].size = ft_strlen(av[i]);
        array[i].str = av[i];
        array[i].copy = ft_strdup(av[i]);
        if (!array[i].copy)
        {
            free(array);
            return NULL;
        }
        i++;
    }
    array[i].str = NULL;
    return array;
}

