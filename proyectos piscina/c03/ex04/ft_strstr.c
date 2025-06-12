/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:32:13 by paguiler          #+#    #+#             */
/*   Updated: 2025/02/16 13:10:02 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strstr(char *str, char *to_find)
{
    int s;
    s = 0;
    int t;

    if(to_find[0] == '\0')
    {
        return str;
    }
    while(str[s])
    {
        t = 0;
        if(str[s] == to_find[0])
        {
            while(str[s + t] && to_find[t] && str[s + t] == to_find[t])
            {
                t++;
                if(to_find[t] == '\0')
                {
                    return &str[s];
                }
            }
        }
        s++;
    }
    return NULL;
}