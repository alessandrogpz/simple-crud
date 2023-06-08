#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(Test2)
{
    double x = 1.5;
    double y = 2.5;

    BOOST_TEST(x + y == 4);
}