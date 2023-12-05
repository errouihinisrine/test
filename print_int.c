/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:37:18 by ner-roui          #+#    #+#             */
/*   Updated: 2023/12/02 11:47:04 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

static int ft_count(int nbr)
{
    int digit = 0;
    while(nbr != 0 )
    {
        digit++;
        nbr /= 10;
    }
    return digit;
}
char *ft_itoa(int nbr)
{
    int n = nbr ;
    
    int i = ft_count(nbr);
    
    if(n < 0)
    {
        i++;
        nbr *= -1;
    }
    char *str = malloc((i + 1) * sizeof(char));
    if (!str)
    return NULL;
    
    str[i] = '\0';
    while (i -- > 0)
    {
        str[i] = nbr  % 10 + '0';
        nbr /= 10;
    }
    if (n < 0)
    {
        str[i] = '-';
    }
    return str;
}

int  ft_int(int n)

{
    int len;
    char *str;
    str = ft_itoa(n);
    len = ft_strlen(str);
    free(str);
    return len;
}
int main()
{
    int c = -1234475;
    printf("%d",ft_int(c));
  
}
