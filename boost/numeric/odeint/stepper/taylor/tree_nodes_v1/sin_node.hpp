/*
 * sin_node.hpp
 *
 *  Created on: Jun 16, 2011
 *      Author: karsten
 *
 *
 * Copyright Karsten Ahnert 2011.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef SIN_NODE_HPP_
#define SIN_NODE_HPP_

#include <cassert>

#include <boost/numeric/odeint/stepper/taylor/unary_node.hpp>

namespace boost {
namespace numeric {
namespace odeint {
namespace taylor_detail {
namespace tree_nodes_v1 {


template< class Child , class Value = double >
struct sin_node : public unary_node< Child , Value >
{
	sin_node( const Child &child  )
	: unary_node< Child , Value >( child ) { }

	template< class State , class Derivs >
	Value operator()( const State &x , const Derivs &derivs , size_t which )
	{
		// assert( false );
		return 0.0;
	}

};

template< class Value , class Child >
sin_node< Child , Value > make_sin( const Child &child )
{
	return sin_node< Child , Value >( child );
}

} // namespace tree_nodes_v1

template< class Child , class Value >
void print_node( std::ostream &out , const tree_nodes_v1::sin_node< Child , Value > &node , size_t indent = 0 )
{
	print_unary_node( out , node , "Sin" , indent );
}





} // namespace taylor_detail
} // namespace odeint
} // namespace numeric
} // namespace boost



#endif /* SIN_NODE_HPP_ */
