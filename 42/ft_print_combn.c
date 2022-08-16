/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <zzz@yyy>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/01/01 00:00:00 by dmanoel-          #+#    #+#             */
/*   Updated: 9999/12/31 23:59:59 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	print_buffer(char buffer[9], int n);
void	r_number(char buffer[9], int n, int pos_to_work, int marker_value);

void	ft_print_combn(int n)
{
	char	buffer[9];

	r_number(buffer, n, 0, 0);
}

void	r_number(char buffer[9], int n, int pos_to_work, int marker_value)
{
	int	while_count;

	while_count = 0;
	if (pos_to_work == (n - 1))
	{
		while (marker_value < 10)
		{
			buffer[pos_to_work] = marker_value;
			print_buffer(buffer, n);
			marker_value = marker_value + 1;
		}
	}
	else
	{
		while (while_count <= (10 - n))
		{
			buffer[pos_to_work] = marker_value;
			r_number(buffer, n, pos_to_work + 1, marker_value + 1);
			while_count++;
			marker_value++;
		}
	}
}

void	print_buffer(char buffer[9], int n)
{
	int		count;
	char	value_to_print;

	count = 0;
	value_to_print = 0;
	while (count < n)
	{
		value_to_print = (buffer[count] + '0');
		write(1, &value_to_print, 1);
		count++;
	}
	if (buffer[0] + n != 10)
		write(1, ", ", 2);
}
