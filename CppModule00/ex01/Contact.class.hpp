/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <thuynguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:52:38 by thuynguy          #+#    #+#             */
/*   Updated: 2023/09/25 15:43:38 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# include <iostream>
# include <string>

class Contact {

public:

    Contact( void );
    ~Contact( void );

    std::string getFirstName( void ) const;
    std::string getLastName( void ) const;
    std::string getNickName( void ) const;
    std::string getPhoneNumber( void ) const;
    std::string getDarkSecret( void ) const;
    void        setFirstName( std::string s );
    void        setLastName( std::string s );
    void        setNickName( std::string s );
    void        setPhoneNumber( std::string s );
    void        setDarkSecret( std::string s );
    
private:

    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkSecret;
};

#endif