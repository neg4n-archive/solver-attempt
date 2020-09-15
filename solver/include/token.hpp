#pragma once
#include <string_view>
#include <variant>

namespace solver {
  namespace internal {
    class Token {
    public:
      enum class Type { Invalid, Plus, Minus, Variable, Constant, Eof };

    private:
      // It can be done using std::variant<std::string_view, char>
      // where type will be string_view when call provides length
      // and char if not. TODO?
      std::string_view inner_ { };
      Type             type_;

    public:
      explicit Token( Type type = Type::Invalid ) noexcept;
      Token( Type type, const char * begin, std::size_t length ) noexcept;
      Token( Type type, const char * begin, const char * end ) noexcept;

      template <typename... Ts>
      bool is_one_of( Token::Type type1,
                      Token::Type type2,
                      Ts... types ) const noexcept {
        if constexpr ( sizeof...( Ts ) <= 0 ) {
          return type_ == type1 || type_ == type2;
        } else {
          return type_ == type1 || is_one_of( type2, types... );
        }
      }

      [[nodiscard]] static constexpr const char *
      type_str( Token::Type type ) noexcept {
        constexpr const char * const names[] = { "Invalid",  "Plus",
                                                 "Minus",    "Variable",
                                                 "Constant", "Eof" };
        return names[ (int)type ];
      }

      [[nodiscard]] std::string_view inner( ) const noexcept;
      [[nodiscard]] Type             type( ) const noexcept;
    };
  } // namespace internal
} // namespace solver