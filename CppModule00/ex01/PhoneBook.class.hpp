/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <thuynguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:44:08 by thuynguy          #+#    #+#             */
/*   Updated: 2023/09/25 17:51:54 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.class.hpp"

class PhoneBook {

public:

    PhoneBook( void );
    ~PhoneBook( void );

    void    addContact( void );

private:
    Contact _contacts[8];
    int     _index;
    //int     _numContacts;
    std::string _readInput( std::string const prompt);
    
    void    _trackIndex( void );
    
};

#endif