/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:39:13 by siokim            #+#    #+#             */
/*   Updated: 2022/07/13 17:17:56 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *filename)
{
	perror(filename);
	exit(1);
}

int	openfile(char *filename, char format)
{
	int	fdin;
	int	fdout;

	if (format == INFILE)
	{
		if (access(filename, F_OK) == -1)
			print_error(filename);
		fdin = open(filename, O_RDONLY);
		if (fdin == -1)
			print_error(filename);
		return (fdin);
	}
	else
	{
		fdout = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0755);
		if (fdout == -1)
			print_error(filename);
		return (fdout);
	}
}

char	*getpath(char **envp, char *command)
{
	int		i;
	char	*path;
	char	**paths;
	char	*tmp2;

	i = -1;
	while (envp[++i] != NULL)
		if (!ft_strncmp(envp[i], "PATH=", 5))
			break ;
	if (envp[i] == NULL)
		return (command);
	path = &envp[i][5];
	paths = ft_split(path, ':');
	i = -1;
	while (paths[++i])
	{
		tmp2 = ft_strjoin(ft_strjoin(paths[i], "/"), command);
		if (!access(tmp2, F_OK))
			return (tmp2);
		free(tmp2);
	}
	print_error(command);
	return (0);
}

void	pipex(char **envp, char *command)
{
	int		pipefd[2];
	int		pid;
	char	*path;
	char	**cmds;

	pipe(pipefd);
	pid = fork();
	if (pid > 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, 0, 0);
	}
	else if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		cmds = ft_split(command, ' ');
		path = getpath(envp, cmds[0]);
		execve(path, cmds, envp);
	}
	else
		print_error("fork_error");
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char	**argvs;
	int		fdin;
	int		fdout;

	if (argc == 5)
	{
		fdin = openfile(argv[1], INFILE);
		fdout = openfile(argv[4], OUTFILE);
		dup2(fdin, STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		pipex(envp, argv[2]);
		argvs = ft_split(argv[3], ' ');
		path = getpath(envp, argvs[0]);
		execve(path, argvs, envp);
	}
	return (1);
}
