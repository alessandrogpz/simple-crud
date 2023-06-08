#include <boost/test/unit_test.hpp>
#include "../headers/checks.h"

BOOST_AUTO_TEST_CASE(TestIsValidEmail)
{
    // Test valid email
    BOOST_CHECK(isValidEmail(std::string("test@example.com")));

    // Test invalid email
    BOOST_CHECK(!isValidEmail(std::string("invalid_email")));
}
