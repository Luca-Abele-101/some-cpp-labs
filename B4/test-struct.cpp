#include <boost/test/unit_test.hpp>

#include "data-struct.hpp"

#include <sstream>
#include <algorithm>

BOOST_AUTO_TEST_SUITE(testStruct)

  BOOST_AUTO_TEST_CASE(correctInput)
  {
    lutsaj::DataStruct dataStruct;
    std::stringstream stream("5,-2,razdvatri");
    stream >> dataStruct;
    BOOST_CHECK_EQUAL(dataStruct.key1, 5);
    BOOST_CHECK_EQUAL(dataStruct.key2, -2);
    BOOST_CHECK_EQUAL(dataStruct.str, "razdvatri");
  }

  BOOST_AUTO_TEST_CASE(incorrectInput)
  {
    lutsaj::DataStruct dataStruct;
    std::stringstream stream("corrupted_data");
    stream >> dataStruct;
    BOOST_CHECK(stream.fail());
  }

  BOOST_AUTO_TEST_CASE(sorting)
  {
    lutsaj::DataStruct dataStruct1;
    lutsaj::DataStruct dataStruct2;
    std::vector< lutsaj::DataStruct > vec;
    std::stringstream stream1("5,-5,NotError");
    std::stringstream stream2("0,  0,    NotErrorToo");
    stream1 >> dataStruct1;
    stream2 >> dataStruct2;
    vec.push_back(dataStruct1);
    vec.push_back(dataStruct2);
    std::sort(vec.begin(), vec.end());
    BOOST_CHECK_EQUAL(vec[0].key1, 0);
    BOOST_CHECK_EQUAL(vec[0].key2, 0);
    BOOST_CHECK_EQUAL(vec[0].str, "NotErrorToo");
    BOOST_CHECK_EQUAL(vec[1].key1, 5);
    BOOST_CHECK_EQUAL(vec[1].key2, -5);
    BOOST_CHECK_EQUAL(vec[1].str, "NotError");
  }

BOOST_AUTO_TEST_SUITE_END()
