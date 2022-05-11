/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:22:59 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/11 16:51:37 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    play(t_graph *graph)
{
        //mlx_key_hook(graph->win_ptr, keycatch, graph);
	mlx_loop(graph->mlx_ptr);
}