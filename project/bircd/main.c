/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:15:47 by kferterb          #+#    #+#             */
/*   Updated: 2022/11/04 09:15:48 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bircd.h"

int	main(int ac, char **av)
{
  t_env	e;

  init_env(&e);
  get_opt(&e, ac, av);
  srv_create(&e, e.port);
  main_loop(&e);
  return (0);
}
