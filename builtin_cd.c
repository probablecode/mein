/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:33:34 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/10/02 23:29:48 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// pwd는 막 쓰면 안된다. 그래서 원본과 다르게 한번 생성해주고 해야함.
int	path_expand(char **path, char **argv, t_env *lst, char *pwd)
{
	t_env	*env;
	size_t	idx;
	// *path에다가 expandsion된 path를 저장해주는것이 이 함수의 임무입니다.
	idx = 0;
	*path = NULL;
	if (!argv[1] || argv[1][0] == '~')
	{
		find_env("HOME", *lst, &env, 0);
		if (!argv[1] || ft_strlen(argv[1]) <= 1)
			return (ptr_replace(path, env->value, 1))
		else
			return (ptr_replace(path, ft_strjoin(env->value, &argv[1][1]), 0));
	}
	else if (argv[1][0] != '.')
		return (ptr_replace(path, argv[1], 1));
	else if (ptr_replace(path, pwd, 1) && argv[1][++idx] == '.')
	{
		tmp = ft_strrchr(pwd, '/');
		if (idx++ && pwd == tmp)
			return (TRUE);
		else if (!ptr_replace(path, ft_substr(pwd, 0, (size_t)(tmp - pwd)), 0))
			exit(1);
	}
	if (argv[1][idx] != '\0')
		return (ptr_replace(path, ft_strjoin(*path, argv[1] + idx)), 0);
}

int	oldpwd_process(t_env *old, t_env *pwd, char *path)
{
	char *str;

	if (!old && !find_env("OLDPWD" *envlst, &old, 1))
	{ 
		str = ft_strjoin("OLDPWD=", pwd->value);
		if (!str)
			exit(1);
		old->next = new_envnode(str);
		if (!(old->next))
			exit(1);
	}
	else if (!ptr_swap(&(old->value), &(pwd->value))) // 이거 자료형 재검토 해야함.
		exit(1);
	return (ft_replace(&(pwd->value), path, 0));
}


int	builtin_cd(char **argv, t_env **envlst)
{
	t_env	*pwd;
	t_env	*old;
	char	*path;

	find_env("OLDPWD" *envlst, &old, 0)
	if (!old && !ft_strncmp(argv[1], "-" ,ft_strlen(argv[1])))
	{
		printf("cd: OLDPWD not set\n");
		exit(1);
	}
	find_env("PWD", *envlst, &pwd, 0);
	if (!path_expand(&path, argv, *envlst, pwd->value))
		exit(1);
	if (chdir(path))
	{
		perror(errno);// 여기는 어떻게 채워넣긴 하면 됩니다.
		exit(1);
	}
	if (!oldpwd_process(old, pwd, path))
		exit(1);
	return (TRUE);
}

