#include "../include/lexer.hpp"

namespace solver {
  namespace internal {
    Lexer::Lexer( const char * begin ) : begin_( begin ) {}

    Token Lexer::next( ) noexcept {
      while ( std::isspace( peek( ) ) )
        get( );

      switch ( peek( ) ) {
        case '+': return single( Token::Type::Plus );
        case '-': return single( Token::Type::Minus );
        case '(': return single(Token::Type::LeftParenthesis);
        case ')': return single(Token::Type::RightParenthesis);
        // @formatter:off
        case '0': case '1': case '2': case '3':
        case '4': case '5': case '6': case '7':
        case '8': case '9':
          return number( );
        case 'a': case 'b': case 'c': case 'd':
        case 'e': case 'f': case 'g': case 'h':
        case 'i': case 'j': case 'k': case 'l':
        case 'm': case 'n': case 'o': case 'p':
        case 'q': case 'r': case 's': case 't':
        case 'u': case 'v': case 'w': case 'x':
        case 'y': case 'z':
          return single(Token::Type::Variable);
        // @formatter:on
        case '\0': return Token( Token::Type::Eof, begin_, 1 );
        default: return Token( );
      }
    }

    Token Lexer::single( Token::Type type ) noexcept {
      return Token( type, begin_++, 1 );
    }

    Token Lexer::number( ) noexcept {
      const char * start = begin_;
      get( );
      while ( std::isdigit( peek( ) ) )
        get( );
      return Token( Token::Type::Constant, start, begin_ );
    }

    char Lexer::peek( ) const noexcept { return *begin_; }
    char Lexer::get( ) noexcept { return *begin_++; }
  } // namespace internal
} // namespace solver