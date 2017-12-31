/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:41:46 by vvinogra          #+#    #+#             */
/*   Updated: 2017/12/31 18:46:02 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_frac	*new_frac(void)
{
	t_frac *frac;

	frac = (t_frac *)malloc(sizeof(t_frac));
	frac->zoom = 1;
	frac->x_move = 0;
	frac->y_move = 0;
	frac->stop = 0;
	frac->nb = 0;
	frac->max_iter = 30;
	frac->color_nb = 1;
	frac->rgb = (t_rgb *)malloc(sizeof(t_rgb));
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	frac->im = create_new_im(frac->mlx);
	return (frac);
}

void	comparing(char **argv, int i, t_frac *frac)
{
	if (ft_strcmp(argv[i], "-m") == 0)
	{
		frac->nb = 1;
		solution_m(frac);
	}
	if (ft_strcmp(argv[i], "-j") == 0)
	{
		frac->nb = 2;
		solution_j(frac);
	}
	if (ft_strcmp(argv[i], "-b") == 0)
	{
		frac->nb = 3;
		solution_b(frac);
	}
	if (ft_strcmp(argv[i], "-p") == 0)
	{
		frac->nb = 4;
		solution_p(frac);
	}
	if (ft_strcmp(argv[i], "-t") == 0)
	{
		frac->nb = 5;
		solution_t(frac);
	}
}

void	helper_user(t_frac *frac)
{
	ft_putendl("Move down: down key");
	ft_putendl("Move up: up key");
	ft_putendl("Move left: left key");
	ft_putendl("Move right: right key");
	ft_putendl("Zoom in: plus(+) or mouse wheel");
	ft_putendl("Zoom out: minus(-) or mouse wheel");
	ft_putendl("Change colors: 1, 2, 3, 4, 5, 6, 7, 8, 9");
	ft_putendl("Reset: 0");
	ft_putendl("More iterations: *");
	ft_putendl("Less iterations: /");
	if (frac->nb == 6 || frac->nb == 2)
		ft_putendl("Stop mouse movements: TAB");
}

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_frac	*frac;

	if (argc != 2)
	{
		write(1, "Usage : ./fractol [-j, -m, -b, -p, -t, -j_s]\n", 45);
		exit(0);
	}
	frac = new_frac();
	if (ft_strcmp(argv[1], "-j_s") == 0)
	{
		frac->nb = 6;
		solution_j(frac);
	}
	comparing(argv, 1, frac);
	if (frac->nb == 0)
	{
		mlx_destroy_window(frac->mlx, frac->win);
		write(1, "Usage : ./fractol [-j, -m, -b, -p, -t, -j_s]\n", 45);
		exit(0);
	}
	mlx_hook(frac->win, 17, 1L << 17, exit_x, frac);
	helper_user(frac);
	mlx_loop(frac->mlx);
}
