/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:41:14 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/12 14:42:35 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *storage, char *buffer)
{
	int		i;
	int		j;
	char	*res;

	if (!buffer)
		return (storage);
	if (!storage)
		return (ft_strdup(buffer));
	res = malloc(ft_strlen(storage) + ft_strlen(buffer) + 1);
	if (!res)
		return (free(storage), NULL);
	i = -1;
	while (storage[++i])
		res[i] = storage[i];
	j = 0;
	while (buffer[j])
		res[i++] = buffer[j++];
	res[i] = '\0';
	return (free(storage), res);
}

char	*ft_strchr(const char *storage, int spec)
{
	if (!storage)
		return (NULL);
	while (*storage)
	{
		if (*storage == (char)spec)
			return ((char *)storage);
		storage++;
	}
	if ((char)spec == '\0')
		return ((char *)storage);
	return (NULL);
}

size_t	ft_strlen(const char *storage)
{
	size_t	i;

	if (!storage)
		return (0);
	i = 0;
	while (storage[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *storage)
{
	char	*copy;
	int		i;

	i = 0;
	copy = malloc(ft_strlen(storage) + 1);
	if (!copy)
		return (NULL);
	while (storage[i])
	{
		copy[i] = storage[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
