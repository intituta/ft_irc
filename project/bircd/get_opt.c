/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:15:35 by kferterb          #+#    #+#             */
/*   Updated: 2022/11/04 09:15:36 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include "bircd.h"

void	get_opt(t_env *e, int ac, char **av)
{
  if (ac != 2)
    {
      fprintf(stderr, USAGE, av[0]);
      exit(1);
    }
  e->port = atoi(av[1]);
}

