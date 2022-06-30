#pragma once
#include <array>
#include <memory>
#include <type_traits>
#include <iostream>
#include <iomanip>

using byte = unsigned char ;

template< typename T > std::array< byte, sizeof(T) >  to_bytes( const T& object );

template< typename T >T& from_bytes( const std::array< byte, sizeof(T) >& bytes, T& object );

template< typename T > std::array< byte, sizeof(T) >  to_bytes( const T& object );

template< typename T >T& from_bytes( const std::array< byte, sizeof(T) >& bytes, T& object );