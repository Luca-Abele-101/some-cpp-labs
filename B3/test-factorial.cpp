#include <boost/test/unit_test.hpp>
#include <algorithm>
#include "factorial-container.hpp"

BOOST_AUTO_TEST_SUITE(test_factorial)

  BOOST_AUTO_TEST_CASE(factorials_are_same)
  {

    lutsaj::FactorialContainer container;
    auto it = container.begin();
    size_t factorial = 1;
    for (int i = 1; i < 10; i++)
    {
      factorial *= i;
      BOOST_REQUIRE_EQUAL(factorial, *it);
      it++;
    }
  }

BOOST_AUTO_TEST_SUITE_END()
