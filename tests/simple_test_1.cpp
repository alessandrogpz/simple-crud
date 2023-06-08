#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(Test1)
{
    int a = 2;
    int b = 3;

    BOOST_TEST(a + b == 5);
}