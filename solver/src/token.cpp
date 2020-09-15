#include "../include/token.hpp"

namespace solver {
  namespace internal {
    Token::Token( Type type ) noexcept : type_( type ) {}

    Token::Token( Token::Type  type,
                  const char * begin,
                  std::size_t  length = 1 ) noexcept
        : type_( type ), inner_( begin, length ) {}

    Token::Token( Type type, const char * begin, const char * end ) noexcept
        : type_( type ), inner_( begin, std::distance( begin, end ) ) {}

    [[nodiscard]] std::string_view Token::inner( ) const noexcept {
      return inner_;
    }
    Token::Type Token::type( ) const noexcept { return type_; }
  } // namespace internal
} // namespace solver