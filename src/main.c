/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:42:24 by bdesbos           #+#    #+#             */
/*   Updated: 2017/01/28 15:17:14 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_source_init(t_shell *sh)
{
	static char	*args[2] = {"./.init", NULL};

	if (!access(args[0], F_OK))
		bi_source(sh, args);
}

int			main(int ac, char **av, char **env)
{
	t_shell *sh;

	shell_init((sh = get_shell()), env);
	shell_source_init(sh);
	shell_start(sh, ac, av);
	return (0);
}
