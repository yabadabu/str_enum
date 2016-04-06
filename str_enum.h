#ifndef INC_UTILS_STR_ENUM_H_
#define INC_UTILS_STR_ENUM_H_

#include "for_each.h"
#include <cstring>      // for the strcmp

#define STR_ENUM_EMIT_EQUAL(x,y)  x = y,
#define STR_ENUM_EMIT_FIRST_AS_STR(x,y)  #x,
#define STR_ENUM_EMIT_FIRST_AS_VAL(x,y)  x,

#define DECL_STR_ENUM( className, ... ) \
class className { \
public: \
  enum Value { FOR_EACH_PAIR( STR_ENUM_EMIT_EQUAL, __VA_ARGS__ ) } value; \
  className( Value new_v ) : value(new_v) { }           \
  className( const char* str ) : value((Value)0){           \
    static const char* enum_names[] = {  FOR_EACH_PAIR( STR_ENUM_EMIT_FIRST_AS_STR, __VA_ARGS__ ) nullptr }; \
    static const Value enum_vals[]  = {  FOR_EACH_PAIR( STR_ENUM_EMIT_FIRST_AS_VAL, __VA_ARGS__ ) }; \
    for( int i=0; enum_names[i]; ++i ) {  \
      if( strcmp( str, enum_names[i]) == 0 ) { \
        value = enum_vals[i]; return; \
      } \
    }  \
  }                 \
  const char* asStr() const {           \
    static const char* enum_names[] = {  FOR_EACH_PAIR( STR_ENUM_EMIT_FIRST_AS_STR, __VA_ARGS__ ) nullptr }; \
    static const Value enum_vals[]  = {  FOR_EACH_PAIR( STR_ENUM_EMIT_FIRST_AS_VAL, __VA_ARGS__ ) }; \
    for( int i=0; enum_names[i]; ++i )  \
      if( value == enum_vals[i] ) return enum_names[i]; \
    return ""; \
  }            \
};

#endif
