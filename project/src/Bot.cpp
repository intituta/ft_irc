/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:16:15 by kferterb          #+#    #+#             */
/*   Updated: 2022/11/04 09:16:16 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bot.hpp"

Bot::Bot() {};
Bot::~Bot() {};

void Bot::getInfoClient(Client &client, Server &server) {
    std::vector<Client> &tmp = server.getVectorCl();
    iterClient it = tmp.begin();
    iterClient ite = tmp.end();
    int onlyOne = 1;
    int fd = client.getFd();
    for(; it != ite; it++) {
        if ((*it).getRegistration()) {
            if (onlyOne == 1) {
                onlyOne = 0;
                std::string str = "-----------------------------\r\n";
                std::string str2 = ":" + client.getNickname() + "!" + client.getUsername() + "@127.0.0.1 " + "PRIVMSG " + client.getNickname() + " " + str;
                send(fd, str2.c_str(), str2.length(), 0);
                str = "|FD   |NICK      |USER      |\r\n";
                str2 = ":" + client.getNickname() + "!" + client.getUsername() + "@127.0.0.1 " + "PRIVMSG " + client.getNickname() + " " + str;
                send(fd, str2.c_str(), str2.length(), 0);
                str = "----------------------------\r\n";
                str2 = ":" + client.getNickname() + "!" + client.getUsername() + "@127.0.0.1 " + "PRIVMSG " + client.getNickname() + " " + str;
                send(fd, str2.c_str(), str2.length(), 0);
            }
            std::string str = "|" + getStrFd((*it).getFd()) + "|" + getLine((*it).getNickname()) + "|" + getLine((*it).getUsername()) + "|\r\n";
            std::string str2 = ":" + client.getNickname() + "!" + client.getUsername() + "@127.0.0.1 " + "PRIVMSG " + client.getNickname() + " " + str;
            send(fd, str2.c_str(), str2.length(), 0);
        }
    }
    if (onlyOne == 0) {
        std::string str = "-----------------------------\r\n";
        std::string str2 = ":" + client.getNickname() + "!" + client.getUsername() + "@127.0.0.1 " + "PRIVMSG " + client.getNickname() + " " + str;
        send(fd, str2.c_str(), str2.length(), 0);
    } else {
        std::string str = "Server empty..\r\n";
        std::string str2 = ":" + client.getNickname() + "!" + client.getUsername() + "@127.0.0.1 " + "PRIVMSG " + client.getNickname() + " " + str;
        send(fd, str2.c_str(), str2.length(), 0);
    }
}

std::string Bot::getLine(std::string str)
{
    std::string line;

    if (str.length() > 10)
    {
        line = str.substr(0, 9) + ".";
        return (line);
    } else if (str.length() < 10) {
        while (str.length() != 10) {
            str += " ";
        }
    }
    return str;
}

std::string Bot::getStrFd(int fd) {
    std::string str;
    str = std::to_string(fd);
    while (str.length() < 5) {
        str += " ";
    }
    return str;
}

void Bot::getInfoBot(Client &client, Server &server) {
    (void)server;
    std::string str = "Hellow! My name is Bot:)\r\nI have next commands:\r\nCLIENTS_INFO - information about clients on server.\n\r";
    std::string str2 = ":" + client.getNickname() + "!" + client.getUsername() + "@127.0.0.1 " + "PRIVMSG " + client.getNickname() + " " + str;
    send(client.getFd(), str2.c_str(), str2.length(), 0);
}
