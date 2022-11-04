/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:16:00 by kferterb          #+#    #+#             */
/*   Updated: 2022/11/04 09:16:01 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Server.hpp"
#include "Client.hpp"

class Server;
class Client;

class Bot {
    typedef std::vector<Client>::iterator iterClient;
private:
    Bot(Bot const &other);
    Bot &operator=(Bot const &other);

public:
    Bot();
    ~Bot();

    void getInfoClient(Client &client, Server &server);

    std::string getLine(std::string str);
    std::string getStrFd(int fd);
    void getInfoBot(Client &client, Server &server);
};