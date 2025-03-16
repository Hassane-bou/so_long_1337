/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:36:47 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/06 21:54:29 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	b;

	i = 0;
	if (!s)
		return (NULL);
	b = (char)c;
	while (s[i])
	{
		if (b == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if (b == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*p;
	int		len;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	p = malloc(len * sizeof(char));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;
	int		len;

	if ((s1 == NULL || s1[0] == '\0') && s2 != NULL)
		return (ft_strdup(s2));
	if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = malloc(len * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}
