/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:45:18 by bdesbos           #+#    #+#             */
/*   Updated: 2017/01/31 15:38:17 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "shell.h"

void	interactive(t_shell *sh)
{
	int			ret;
	char		*line;

	shell_signals();
	sh->is_interactive = 1;
	while ((ret = get_line(shell_prompt(sh), &sh->line)) != -1)
	{
		line = sh->line;
		if (!ret)
		{
			ft_putendl("");
			exit_shell(NULL, 0);
		}
		if (line && *line)
		{
			if (!ft_strchr(line, '\n')
			&& ((sh->histo && ft_strcmp(sh->histo->value, line)) || !sh->histo))
				add_histo(&sh->histo, line, 1);
			sh->line = ft_str_replace(sh->line, "~", sh->store[HOMEDIR], 1);
			line = sh->line;
			shell_source_line(sh, line);
		}
		ft_putchar('\n');
		ft_memdel((void **)&sh->line);
	}
}

void	shell_start(t_shell *sh, int ac, char **av)
{
	if (ac != 1)
		bi_source(sh, av + 1);
	else if (!isatty(0))
		shell_source_fd(sh, 0);
	else
		interactive(sh);
	exit_shell(NULL, 0);
}
