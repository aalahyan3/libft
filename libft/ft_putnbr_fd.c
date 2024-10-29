/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:20:11 by aalahyan          #+#    #+#             */
/*   Updated: 2024/10/27 23:26:50 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	buff[12];
	int		i;

	nb = n;
	i = 0;
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	while (nb)
	{
		buff[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	i--;
	while (i >= 0)
		ft_putchar_fd(buff[i--], fd);
}
