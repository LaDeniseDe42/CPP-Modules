/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:22:45 by root              #+#    #+#             */
/*   Updated: 2023/11/15 12:07:57 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template< typename T, typename F>
void swap( T & a, F & b ) {
    T tmp = a;
    a = b;
    b = tmp;
}

template< typename T >
T const & min( T const & a, T const & b ) {
    return ( a < b ? a : b );
}

template< typename T >
T const & max( T const & a, T const & b ) {
    return ( a > b ? a : b );
}
