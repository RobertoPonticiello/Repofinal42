/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:37:26 by rpontici          #+#    #+#             */
/*   Updated: 2024/12/21 12:57:03 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_list;
    t_list  *new_node;

    new_list = NULL;
    while (lst)
    {
        new_node = ft_lstnew(f(lst->content));
        if (!new_node)
        {
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        ft_lstadd_back(&new_list, new_node);
        lst = lst->next;
    }
    return (new_list);
}



static void	*double_content(void *content)
{
	int	*val;
	int	*new_val;

	val = (int *)content;
	new_val = (int *)malloc(sizeof(int));
	if (!new_val)
		return (NULL);
	*new_val = (*val) * 2;
	return (new_val);
}

/*
 * Funzione di "del" usata da ft_lstmap e ft_lstclear:
 * libera un contenuto generico (in questo caso intero).
 */
static void	free_content(void *content)
{
	free(content);
}

/*
 * Funzione di utilità per stampare la lista di interi.
 */
static void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d -> ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	int		*a;
	int		*b;
	int		*c;
	t_list	*lst;
	t_list	*mapped;

	/* Creiamo manualmente alcuni interi */
	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	c = malloc(sizeof(int));
	*a = 10;
	*b = 20;
	*c = 30;
	/* Creiamo la lista originale: [10, 20, 30] */
	lst = ft_lstnew(a);
	ft_lstadd_back(&lst, ft_lstnew(b));
	ft_lstadd_back(&lst, ft_lstnew(c));
	printf("Lista originale: ");
	print_list(lst);
	/* Usiamo ft_lstmap: raddoppia il contenuto di ogni nodo */
	mapped = ft_lstmap(lst, double_content, free_content);
	printf("Lista mappata:   ");
	print_list(mapped);
	/* Pulizia finale: liberiamo entrambe le liste */
	ft_lstclear(&lst, free_content);
	ft_lstclear(&mapped, free_content);
	return (0);
}
