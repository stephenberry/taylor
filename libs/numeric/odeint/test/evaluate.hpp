/*
 * evaluate.hpp
 *
 *  Created on: Jun 9, 2011
 *      Author: karsten
 *
 *
 * Copyright Karsten Ahnert 2011.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef EVALUATE_HPP_
#define EVALUATE_HPP_

#include <iostream>
#include <tr1/array>

#include <boost/numeric/odeint/stepper/taylor/print_tree.hpp>

#include <boost/mpl/size_t.hpp>

template< class Eq1 , class Eq2 >
void evaluate_v1( const Eq1 &_eq1 , const Eq2 &_eq2 )
{
	using namespace boost::numeric::odeint::taylor_detail;

	Eq1 eq1 = _eq1;
	Eq2 eq2 = _eq2;

	print_tree( std::cout , 0 )( eq1 );
	std::cout << "\n\n";
	print_tree( std::cout , 0 )( eq2 );

	typedef std::tr1::array< double , 2 > state_type;
	typedef std::tr1::array< state_type , 10 > deriv_type;

	state_type x = {{ 0.25 , 0.75 }};

	deriv_type derivs;

	for( size_t i=0 ; i<10 ; ++i )
	{
		derivs[i][0] = 1.0 / double( i + 1 ) * eq1( x , derivs , i );
		derivs[i][1] = 1.0 / double( i + 1 ) * eq2( x , derivs , i );
	}

	for( size_t i=0 ; i<10 ; ++i )
	{
		std::cout << i << "\t" << derivs[i][0] << "\t" << derivs[i][1] << "\n";
	}
}


template< class Eq1 , class Eq2 >
void evaluate_v2( const Eq1 &_eq1 , const Eq2 &_eq2 )
{
    using namespace boost::numeric::odeint::taylor_detail;
    namespace mpl = boost::mpl;

    Eq1 eq1 = _eq1;
    Eq2 eq2 = _eq2;

    print_tree( std::cout , 0 )( eq1 );
    std::cout << "\n\n";
    print_tree( std::cout , 0 )( eq2 );

    typedef std::tr1::array< double , 2 > state_type;
    typedef std::tr1::array< state_type , 10 > deriv_type;

    state_type x = {{ 0.25 , 0.75 }};

    deriv_type derivs;

    derivs[0][0] = 1.0 / double( 0 + 1 ) * eq1( x , derivs , mpl::size_t< 0 >() );
    derivs[0][1] = 1.0 / double( 0 + 1 ) * eq2( x , derivs , mpl::size_t< 0 >() );
    derivs[1][0] = 1.0 / double( 0 + 1 ) * eq1( x , derivs , mpl::size_t< 1 >() );
    derivs[1][1] = 1.0 / double( 0 + 1 ) * eq2( x , derivs , mpl::size_t< 1 >() );
    derivs[2][0] = 1.0 / double( 0 + 1 ) * eq1( x , derivs , mpl::size_t< 2 >() );
    derivs[2][1] = 1.0 / double( 0 + 1 ) * eq2( x , derivs , mpl::size_t< 2 >() );
    derivs[3][0] = 1.0 / double( 0 + 1 ) * eq1( x , derivs , mpl::size_t< 3 >() );
    derivs[3][1] = 1.0 / double( 0 + 1 ) * eq2( x , derivs , mpl::size_t< 3 >() );
    derivs[4][0] = 1.0 / double( 0 + 1 ) * eq1( x , derivs , mpl::size_t< 4 >() );
    derivs[4][1] = 1.0 / double( 0 + 1 ) * eq2( x , derivs , mpl::size_t< 4 >() );
    derivs[5][0] = 1.0 / double( 0 + 1 ) * eq1( x , derivs , mpl::size_t< 5 >() );
    derivs[5][1] = 1.0 / double( 0 + 1 ) * eq2( x , derivs , mpl::size_t< 5 >() );
    derivs[6][0] = 1.0 / double( 0 + 1 ) * eq1( x , derivs , mpl::size_t< 6 >() );
    derivs[6][1] = 1.0 / double( 0 + 1 ) * eq2( x , derivs , mpl::size_t< 6 >() );
    derivs[7][0] = 1.0 / double( 0 + 1 ) * eq1( x , derivs , mpl::size_t< 7 >() );
    derivs[7][1] = 1.0 / double( 0 + 1 ) * eq2( x , derivs , mpl::size_t< 7 >() );
    derivs[8][0] = 1.0 / double( 0 + 1 ) * eq1( x , derivs , mpl::size_t< 8 >() );
    derivs[8][1] = 1.0 / double( 0 + 1 ) * eq2( x , derivs , mpl::size_t< 8 >() );
    derivs[9][0] = 1.0 / double( 0 + 1 ) * eq1( x , derivs , mpl::size_t< 9 >() );
    derivs[9][1] = 1.0 / double( 0 + 1 ) * eq2( x , derivs , mpl::size_t< 9 >() );

    for( size_t i=0 ; i<10 ; ++i )
    {
        std::cout << i << "\t" << derivs[i][0] << "\t" << derivs[i][1] << "\n";
    }
}



#endif /* EVALUATE_HPP_ */
