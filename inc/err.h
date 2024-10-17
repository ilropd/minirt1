/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:13:20 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/15 15:35:52 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H

# include "minirt.h"

# define ERROR "\033[1;31mError\n\033[0m"
# define WARN "\033[1;33mWarning\n\033[0m"

/* Errors of file checking*/ 
# define NE_FILE "File doesn't exist\n"
# define E_FILE "File is empty\n"
# define RET_FILE "Cannot retrieve file information\n"
# define RO_FILE "Can't open or read file\n"
# define WF_FILE "Incorrect format of the file\n"

/* Errors of parsing */
# define ARGS "Wrong number of parameters\n"

/* Errors of memory allocation */




#endif
