/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:23:14 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/14 12:09:33 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>

ssize_t	ft_do_write(int fd, const void *buf, size_t len)
{
	size_t	written;
	ssize_t	ret;

	written = 0;
	while (written < len)
	{
		ret = write(fd, (const char *)buf + written, len - written);
		if (ret == -1)
		{
			if (errno == EINTR)
				continue ;
			return (-1);
		}
		written += ret;
	}
	return ((ssize_t)written);
}
