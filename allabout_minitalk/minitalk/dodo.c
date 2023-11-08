/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:12:34 by jchoi             #+#    #+#             */
/*   Updated: 2022/06/24 16:57:19 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include "libft.h"
#include <signal.h>
int	input_process(int argc, char *argv[], size_t *length)
{
	int	ret;
	int	pid;
	// 3개이고, 적절한 pid 인지는 모르겠군

	// 전달할 변수에, 이 client의 signal에 

	// pid, length를 보내조야(공유해야)해요
	char *ptr
	if (argc == 3)
	{
		if (6 < ft_strlen(argv[1]) && )
			pid = atoi(argv[1]);
		if (pid < 100000)
			;
		

		// 혹시 유효한 pid인지 99999초과 안하는지
		// 문자열이면 숫자로 바꿔야지
		*length = ft_strlen(argv[2]);
		

		return (1);
		return (0);
	}
	perror(" ");
	pidstr = getpid();
	write();
}


int	main(int argc, char *argv[])
{
	size_t	length;
	size_t	i;

	if (input_process(argc, argv, &length))
		return (write(1, "invalid argument\n", 18));
	
	i = 0;
	while (i < length)
	{
		// 시도 하고나서 0이라는 출력이 나오면 펜딩하고 잠시후 다시 요청하도록 합니다.
		// 1이라는 출력이 나오면 계속 합니다.
		//  
		pause();
		i++;
	}


	//print				char *message = "messege delivered from %d to %d \n";
	return (0);
}
