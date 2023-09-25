/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <thuynguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:42:56 by thuynguy          #+#    #+#             */
/*   Updated: 2023/09/25 17:49:11 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

std::string readUserInput( void ) {
    std::string input;
    
    std::cout << "Enter your command: " << std::endl;
    std::getline (std::cin, input);
    if (std::cin.eof()) {
        std::cout << std::endl;
        return std::string();
    }
    for ( std::string::iterator it=input.begin(); it!=input.end(); ++it)
        toupper(*it);
    return input;
}

#include "PhoneBook.class.hpp"

int main(void)
{
    PhoneBook   PhoneBook;
    std::string userInput;
    
    while (1) {
        userInput = readUserInput();
        if (userInput == "EXIT")
            break ;
        if (userInput == "ADD")
            PhoneBook.addContact();
        else {
            std::cout << "Please enter one of the three command: ";
            std::cout << "ADD, SEACH, AND EXIT" << std::endl;
        }
    }
    return 0;
}
