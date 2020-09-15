#pragma once

#include <string>
#include <string_view>

#include "./token.hpp"

namespace solver {
  namespace internal {
    class Lexer {
    private:
      const char * begin_ { };

    public:
      explicit Lexer( const char * begin );

      Token next( ) noexcept;
      Token single( Token::Type type ) noexcept;
      Token number( ) noexcept;

      [[nodiscard]] char peek( ) const noexcept;
      char               get( ) noexcept;
    };
  } // namespace internal
} // namespace solver