#include <lexer.hpp>
#include <token.hpp>

#include <iostream>
#include <iomanip>

int main( ) {
  using namespace solver::internal;

  Lexer lexer { "x + 30 - 20 = y" };

  std::cout << std::setw(10)
            << "Type" << " | " << "Inner"
            << std::endl
            << "--------------------"
            << std::endl;

  for ( auto token = lexer.next( );
        !token.is_one_of( Token::Type::Eof, Token::Type::Invalid );
        token = lexer.next( ) ) {
    std::cout << std::setw( 10 ) << Token::type_str( token.type( ) ) << " | "
              << token.inner( ) << std::endl;
  }

  return 0;
}