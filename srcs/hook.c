/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:42:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/12 16:28:27 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	keycatch(int keycode, t_graph *graph)
{
        if (keycode == 65307)
		return (close_loop(graph));
        return (0);
}

int    close_loop(t_graph *graph)
{
        mlx_loop_end(graph->mlx_ptr);
        return (0);
}