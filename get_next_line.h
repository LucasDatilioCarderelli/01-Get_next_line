/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:37:19 by ldatilio          #+#    #+#             */
/*   Updated: 2021/09/23 14:34:46 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

/**	@brief	Description Write a function which returns a line read from a
 *			file descriptor.
 *	@param	fd	File descriptor to read from.
 *	@return	Read line: correct behavior. NULL if there is nothing else to read
 *			or an error occurred */
char	*get_next_line(int fd);

#endif
