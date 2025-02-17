/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:25:58 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/17 21:46:20 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

void	free_dptr(char **str)
{
	char	*temp;
	char	**copy;

	copy = str;
	while (*str)
	{
		temp = *str;
		str++;
		free(temp);
	}
	free(copy);
}
