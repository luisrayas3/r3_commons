#ifndef R3_COMMONS_TESTING_H_
#define R3_COMMONS_TESTING_H_

#include <stdbool.h>
#include <stdio.h>

#undef NDEBUG

#define TEST(TEST_FUNC, TEST_CASE)                  \
  fprintf(stderr, "\nTESTING "#TEST_FUNC"%s:\n",    \
          *(#TEST_CASE) ? " ("#TEST_CASE")" : "");

#define HAS_STR(FMT, ...) (FMT)[0]

#define CHECK_SAME(VALUE, EXPECTATION, ...)                     \
  do {                                                          \
    void* VALUE_ = VALUE;                                       \
    void* EXPECTATION_ = EXPECTATION;                           \
    if( VALUE_ != EXPECTATION_ ) {                              \
      fprintf(stderr, "ERROR @ " __FILE__ ", %i:\n", __LINE__); \
      fprintf(stderr, "    " #VALUE " != " #EXPECTATION "\n");  \
      fprintf(stderr, "    %p != %p\n", VALUE_, EXPECTATION_);  \
      fprintf(stderr, "" __VA_ARGS__);                          \
      if( HAS_STR("" __VA_ARGS__) ) fprintf(stderr, "\n");      \
    }                                                           \
  } while( false )

#define CHECK_EQ(VALUE, EXPECTATION, ...)                            \
  do {                                                          \
    float VALUE_ = VALUE;                                       \
    float EXPECTATION_ = EXPECTATION;                           \
    if( VALUE_ != EXPECTATION_ ) {                              \
      fprintf(stderr, "ERROR @ " __FILE__ ", %i:\n", __LINE__); \
      fprintf(stderr, "    " #VALUE " != " #EXPECTATION "\n");  \
      fprintf(stderr, "    %f != %f\n", VALUE_, EXPECTATION_);  \
      fprintf(stderr, "" __VA_ARGS__);                          \
      if( HAS_STR("" __VA_ARGS__) ) fprintf(stderr, "\n");      \
    }                                                           \
  } while( false )

#define CHECK_NE(VALUE, EXPECTATION, ...)                           \
  do {                                                          \
    float VALUE_ = VALUE;                                       \
    float EXPECTATION_ = EXPECTATION;                           \
    if( VALUE_ == EXPECTATION_ ) {                              \
      fprintf(stderr, "ERROR @ " __FILE__ ", %i:\n", __LINE__); \
      fprintf(stderr, "    " #VALUE " == " #EXPECTATION "\n");  \
      fprintf(stderr, "    %f == %f\n", VALUE_, EXPECTATION_);  \
      fprintf(stderr, "" __VA_ARGS__);                          \
      if( HAS_STR("" __VA_ARGS__) ) fprintf(stderr, "\n");      \
    }                                                           \
  } while( false )

#define CHECK_LT(VALUE, EXPECTATION, ...)                           \
  do {                                                          \
    float VALUE_ = VALUE;                                       \
    float EXPECTATION_ = EXPECTATION;                           \
    if( VALUE_ >= EXPECTATION_ ) {                              \
      fprintf(stderr, "ERROR @ " __FILE__ ", %i:\n", __LINE__); \
      fprintf(stderr, "    " #VALUE " >= " #EXPECTATION "\n");  \
      fprintf(stderr, "    %f >= %f\n", VALUE_, EXPECTATION_);  \
      fprintf(stderr, "" __VA_ARGS__);                          \
      if( HAS_STR("" __VA_ARGS__) ) fprintf(stderr, "\n");      \
    }                                                           \
  } while( false )

#define CHECK_APPROX_EQ(VALUE, EXPECTATION, ACCEPT_DELTA, ...)      \
  do {                                                          \
    float VALUE_ = VALUE;                                       \
    float EXPECTATION_ = EXPECTATION;                           \
    if( !( VALUE_ - EXPECTATION_ < ACCEPT_DELTA &&              \
           VALUE_ - EXPECTATION_ > -ACCEPT_DELTA ) ) {          \
      fprintf(stderr, "ERROR @ " __FILE__ ", %i:\n", __LINE__); \
      fprintf(stderr, "    " #VALUE " != " #EXPECTATION "\n");  \
      fprintf(stderr, "    %f != %f\n", VALUE_, EXPECTATION_);  \
      fprintf(stderr, "" __VA_ARGS__);                          \
      if( HAS_STR("" __VA_ARGS__) ) fprintf(stderr, "\n");      \
    }                                                           \
  } while( false )

#define CHECK_TRUE(VALUE, ...)                                        \
  do {                                                            \
      if( !(VALUE) ) {                                            \
        fprintf(stderr, "ERROR @ " __FILE__ ", %i:\n", __LINE__); \
        fprintf(stderr, "    " #VALUE " == false\n");             \
        fprintf(stderr, "" __VA_ARGS__);                          \
        if( HAS_STR("" __VA_ARGS__) ) fprintf(stderr, "\n");      \
      }                                                           \
  } while( false )

#define CHECK_FALSE(VALUE, ...)                                     \
  do {                                                          \
    if( VALUE ) {                                               \
      fprintf(stderr, "ERROR @ " __FILE__ ", %i:\n", __LINE__); \
      fprintf(stderr, "    " #VALUE " == true\n");              \
      fprintf(stderr, "" __VA_ARGS__);                          \
      if( HAS_STR("" __VA_ARGS__) ) fprintf(stderr, "\n");      \
    }                                                           \
  } while( false )


#endif  // R3_COMMONS_TESTING_H_
