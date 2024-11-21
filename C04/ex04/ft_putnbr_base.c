/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:33:32 by rpontici          #+#    #+#             */
/*   Updated: 2024/11/20 20:33:50 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

int     is_valid_base(char *base)
{
    int i, j;
    
    // La base deve avere almeno due caratteri
    if (ft_strlen(base) < 2)
        return 0;

    // Verifica se ci sono caratteri duplicati o invalidi
    for (i = 0; base[i]; i++) {
        // Verifica se ci sono caratteri '+' o '-'
        if (base[i] == '+' || base[i] == '-')
            return 0;
        for (j = i + 1; base[j]; j++) {
            // Verifica se ci sono caratteri duplicati
            if (base[i] == base[j])
                return 0;
        }
    }
    return 1;
}

void    ft_putnbr_base(int nbr, char *base)
{
    int base_len;
    char result[32]; // supponiamo che il numero non superi 32 bit
    int i = 0;

    // Verifica se la base è valida
    if (!is_valid_base(base))
        return;

    base_len = ft_strlen(base);

    // Gestisci il caso del numero negativo
    if (nbr == -2147483648) {
        write(1, "-", 1); // Stampa il segno
        write(1, "2", 1);  // Stampa "2" direttamente per -2147483648
        nbr = 147483648;   // Usa la parte positiva
    } else if (nbr < 0) {
        write(1, "-", 1);  // Stampa il segno negativo
        nbr = -nbr; // Rendiamo il numero positivo
    }

    // Conversione del numero
    if (nbr == 0) {
        result[i++] = base[0];  // Se il numero è 0, scriviamo il primo carattere della base
    } else {
        while (nbr > 0) {
            result[i++] = base[nbr % base_len];  // Otteniamo il carattere corrispondente al resto
            nbr = nbr / base_len;  // Dividiamo per la base
        }
    }

    // Stampa il numero in ordine inverso
    while (--i >= 0) {
        write(1, &result[i], 1);
    }
}

/*
int main(void)
{
    // Test con base esadecimale
    ft_putnbr_base(-255, "0123456789ABCDEF"); // Output: -FF

    // Test con base binaria
    ft_putnbr_base(42, "01"); // Output: 101010

    // Test con base ottale
    ft_putnbr_base(123, "poneyvif"); // Output: fey

    return 0;
}
*/
