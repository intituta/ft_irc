/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:16:23 by kferterb          #+#    #+#             */
/*   Updated: 2022/11/04 09:16:24 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Server.hpp"

int main(int ac, char** av) {
    if (ac != 3) {
        std::cerr << "Usage: << ./ircserv <port> <password> >>\n";
        return 1;
    }

    Server Server(atoi(av[1]), std::string(av[2]));
    Server.start();
    return 0;
}