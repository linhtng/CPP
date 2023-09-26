/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <thuynguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:44:08 by thuynguy          #+#    #+#             */
/*   Updated: 2023/09/26 21:05:54 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include <iomanip>
# include "Contact.class.hpp"

class PhoneBook {

public:

    PhoneBook( void );
    ~PhoneBook( void );

    void    atYourService ( void );

private:
    Contact _contacts[8];
    int     _index;

    std::string _readInput( std::string const prompt );
    
    void    _addContact( void );
    void    _searchContact( void );
    void    _trackIndex( void );
    void    _displayContactList( void );
    void    _searchByIndex( void );
    void    _displayContactInfo( const int index );
};

#endif