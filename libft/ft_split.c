/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:56:26 by aalahyan          #+#    #+#             */
/*   Updated: 2024/10/29 13:59:52 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_size(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			size++;
			s++;
		}
		while (*s && *s != c)
			s++;
	}
	return (size + 1);
}

static char	*get_word(char const *start, char c)
{
	char	*word;
	char	*word_start;
	char	*ptr;
	int		size;

	size = 0;
	ptr = (char *)start;
	while (*ptr && *ptr != c)
	{
		size++;
		ptr++;
	}
	word = malloc (sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	word_start = word;
	while (start < ptr)
		*word++ = *start++;
	*word = 0;
	return (word_start);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*word;
	int		i;

	if (!s)
		return (NULL);
	array = malloc(sizeof (char *) * (get_size(s, c)));
	if (!array)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			word = get_word(s, c);
			array[i++] = word;
			while (*s && *s != c)
				s++;
		}
	}
	array[i] = NULL;
	return (array);
}

/*
#include <stdio.h>
int main(void)
{
	char	**arr = ft_split("----wijd-ijds-isij-skjd---fff--", '-');
	if (*arr == NULL)
		printf("Error!");
	while (*arr != NULL)
		printf("%s\n", *arr++);
	printf("%s\n", *arr);
}*/