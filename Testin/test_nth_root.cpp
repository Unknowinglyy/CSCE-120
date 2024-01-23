#include <iostream>
#include <cmath>
#include "./nth_root.h"
#include "test_helpers.h"

int main() {
    {   // MINIMUM REQUIREMENT (for this lab)
        // just call the function with various values of n and x
        bool pass = true;

        nth_root(2, 1);
        EXPECT_THROW(nth_root(0, 1), std::domain_error);
        EXPECT_THROW(nth_root(2, -1), std::domain_error);
        EXPECT_THROW(nth_root(4, -2), std::domain_error);
        EXPECT_THROW(nth_root(-2, 0), std::domain_error);
        nth_root(1, 2);
        nth_root(-1, 1);
        nth_root(-2, 1);
        nth_root(-6, 1);
        nth_root(-5, 1);
        nth_root(6, 1);
        nth_root(5, 1);
        nth_root(2, 0);
        nth_root(3, 1);
        nth_root(3, -2);
        nth_root(3, 3);
        nth_root(3, 1.235);
    }

    {   // TRY HARD
        // report the value
        double actual = nth_root(2, 1);
        std::cout << "nth_root(2, 1) = " << actual << std::endl;
		actual = nth_root(1, 2);
        std::cout << "nth_root(1, 2) = " << actual << std::endl;
		actual = nth_root(3, 1);
        std::cout << "nth_root(3, 1) = " << actual << std::endl;
		actual = nth_root(5, 1);
        std::cout << "nth_root(5, 1) = " << actual << std::endl;
    }

    {   // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1);
        double expected = 1;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
		actual = nth_root(3, 1);
        expected = 1;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=3, x=1)" << std::endl;
            std::cout << "  expected nth_root(3, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=3, x=1)" << std::endl;
        }
		actual = nth_root(2, 4);
        expected = 2;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=4)" << std::endl;
            std::cout << "  expected nth_root(2, 4) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=3, x=1)" << std::endl;
        }
    }
}
