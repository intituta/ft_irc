/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:16:06 by kferterb          #+#    #+#             */
/*   Updated: 2022/11/04 09:16:07 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>
# include <list>
# include <vector>
# include "Channel.hpp"
# include "Message.hpp"
# include "Server.hpp"

class Channel;
class Message;

class Client
{
	public:
		Client();
		Client(int fd, const std::string& addres, const std::string& password);
		Client& operator=(const Client& source);
		~Client();

	private:
		int					    _fd;
		bool				    _status;
        bool                    _registration;
		std::string		    _address;
		std::string		    _buffer;
		std::string		    _nickname;
		std::string		    _password;
		std::string		    _username;
//		std::vector<Channel>	_channels;
	
	public:
		int			    getFd();
		bool		    getStatus();
		std::string&	getAddress();
		std::string&	getBuffer();
		std::string&	getNickname();
		std::string&	getPassword();
		std::string&    getUsername();
        bool            getRegistration();

		void	setStatus(bool status);
		void	setAddress(const std::string& address);
		void	setBuffer(const std::string& buffer);
		void	setNickname(const std::string& nickname);
		void	setPassword(const std::string& password);
		void	setUsername(const std::string& username);
        void    setRegistration(bool reg);
        bool    isCheckRegistration();

		void    execMessage(Server &server);
		void	parceBuffer(Message &msg);
};