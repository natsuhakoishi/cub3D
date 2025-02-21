/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parse2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 03:42:44 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/22 03:47:02 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

void	parse_colors(t_c3dmlx *c3d, char **split)
{
	int	i;

	i = 0;
	while (split[1][i])
	{
	if (split[1][i] != ',' && split[1][i] != '\n' && !ft_isdigit(split[1][i]))
		tutup_c3d(c3d, "Error: Invalid: Floor/Ceiling RGB Value\n", 1);
	i++;
	}
}

void	check_arr_size(char **str)
{
    int i;
    int count;

    i = -1;
    count = 0;
    while(str[++i])
        count++;
    if (count != 2)
    {
        if (!ft_strcmp(str[0], "\n"))
            return ;
        else
            tutup("Error: Invalid space/format for identifiers\n", 1);
    }
}
