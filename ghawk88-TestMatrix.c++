// ------------------------------
// projects/matlab/TestMatrix.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
 * To test the program:
 *     g++ -ansi -pedantic -lcppunit -ldl -Wall TestMatrix.c++ -o TestMatrix.app
 *     valgrind TestMatrix.app >& TestMatrix.out
 */

// --------
// includes
// --------

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Matrix.h"

// ----------
// TestMatrix
// ----------

struct TestMatrix : CppUnit::TestFixture {
    // ----------------
    // test_constructor
    // ----------------

    void test_constructor_One () {
        Matrix<int> x;
        CPPUNIT_ASSERT(x.size() == 0);
    }

    void test_constructor_Two () {
        Matrix<int> y(3);
        Matrix<int> z(3, 3);
        Matrix<int> t(6, 3, 2);
        CPPUNIT_ASSERT(y.size() == 3);
        CPPUNIT_ASSERT(z.size() == 3);
        CPPUNIT_ASSERT(t.size() == 6);
    }

    void test_constructor_Three () {
        int r = 5;
        int c = 3;
        int T = 4;
        Matrix<int> t(r, c, T);
        CPPUNIT_ASSERT(t.size() == 5);
    }

    // ----------
    // test_index
    // ----------

    void test_index_One () {
        const Matrix<int> x(2,1,1);
        CPPUNIT_ASSERT(x[0][0] == 1);
    }

    void test_index_Two () {
        int r = 4;
        int c = 3;
        int T = 4;
        const Matrix<int> t(r, c, T);
        CPPUNIT_ASSERT(t.size() == (unsigned int) r);
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                CPPUNIT_ASSERT( t[i][j] == T);
    }

    void test_index_Three () {
        int r = 100;
        int c = 100;
        int T = 25;

        const Matrix<int> x(r, c);
        CPPUNIT_ASSERT(x.size() == (unsigned int) r);
        const Matrix<int> y(r, c);
        CPPUNIT_ASSERT(y.size() == (unsigned int) r);
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                CPPUNIT_ASSERT( y[i][j] == 0);
        const Matrix<int> z(r, c, T);
        CPPUNIT_ASSERT(z.size() == (unsigned int) r);
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                CPPUNIT_ASSERT( z[i][j] == T);

    }

    // -----------
    // test_equals
    // -----------

    void test_equals_One () {
        Matrix<int>  x(5,5,1);
        Matrix<int>  y(5,5,1);
        Matrix<bool> z;
        Matrix<bool> t(5,5,1);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
        t[4][4] = 0;
        CPPUNIT_ASSERT(!z.eq(t));
    }

    void test_equals_Two () {
        Matrix<int>  x(1,1,2);
        Matrix<int>  y(1,1,1);
        Matrix<bool> z;
        Matrix<bool> t(1,1,1);
        z = (x == y);
        CPPUNIT_ASSERT(!z.eq(t));
        y[0][0] = 2;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_equals_Three () {
        Matrix<int>  x(5,5,1);
        Matrix<int>  y(5,5,1);
        Matrix<bool> z;
        Matrix<bool> t(5,5,1);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
        t[4][4] = 0;
        CPPUNIT_ASSERT(!z.eq(t));
    }

    void test_diff_One () {
        Matrix<int>  x(5,5,1);
        Matrix<int>  y(5,5,0);
        Matrix<bool> z;
        Matrix<bool> t(5,5,1);
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));
        t[4][4] = 0;
        CPPUNIT_ASSERT(!z.eq(t));
    }

    void test_diff_Two () {
        Matrix<int>  x(1,1,2);
        Matrix<int>  y(1,1,1);
        Matrix<bool> z;
        Matrix<bool> t(1,1,0);
        z = (x != y);
        CPPUNIT_ASSERT(!z.eq(t));
        y[0][0] = 2;
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));
    }



    // --------------
    // test_less_than
    // --------------

    void test_less_than_One () {
        Matrix<int>  x(1,2,2);
        Matrix<int>  y(1,2,3);
        Matrix<bool> z;
        Matrix<bool> t(1,2,1);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_less_than_Two () {
        Matrix<int>  x(2,2,2);
        Matrix<int>  y(2,2,3);
        Matrix<bool> z;
        Matrix<bool> t(2,2,1);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));

        x[0][0] = 4;
        z = (x < y);
        t[0][0] = 0;
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_less_than_Three () {
        Matrix<int>  x(1,1,2);
        Matrix<int>  y(1,1,3);
        Matrix<bool> z;
        Matrix<bool> t(1,1,1);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));

        x[0][0] = 4;
        z = (x < y);
        t[0][0] = 0;
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_greater_than_One () {
        Matrix<int>  x(1,2,3);
        Matrix<int>  y(1,2,2);
        Matrix<bool> z;
        Matrix<bool> t(1,2,1);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));

    }

    void test_greater_than_Two () {
        Matrix<int>  x(1,1,3);
        Matrix<int>  y(1,1,2);
        Matrix<bool> z;
        Matrix<bool> t(1,1,1);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));

        x[0][0] = 1;
        z = (x > y);
        t[0][0] = 0;
        CPPUNIT_ASSERT(z.eq(t));
    }


    void test_greater_than_Three () {
        Matrix<int>  x(2,2,4);
        Matrix<int>  y(2,2,3);
        Matrix<bool> z;
        Matrix<bool> t(2,2,1);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));

        x[0][0] = 1;
        x[0][1] = 2;
        z = (x > y);
        t[0][0] = 0;
        t[0][1] = 0;
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_less_equal_One () {
        Matrix<int>  x(1,2,2);
        Matrix<int>  y(1,2,3);
        Matrix<bool> z;
        Matrix<bool> t(1,2,1);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));

    }

    void test_less_equal_Two () {
        Matrix<int>  x(1,1,2);
        Matrix<int>  y(1,1,3);
        Matrix<bool> z;
        Matrix<bool> t(1,1,1);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));

        x[0][0] = 5;
        z = (x <= y);
        t[0][0] = 0;
        CPPUNIT_ASSERT(z.eq(t));
    }


    void test_less_equal_Three () {
        Matrix<int>  x(2,2,2);
        Matrix<int>  y(2,2,3);
        Matrix<bool> z;
        Matrix<bool> t(2,2,1);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));

        x[0][0] = 5;
        x[0][1] = 5;
        z = (x <= y);
        t[0][0] = 0;
        t[0][1] = 0;
        CPPUNIT_ASSERT(z.eq(t));
    }
    void test_greater_equal_One () {
        Matrix<int>  x(1,2,2);
        Matrix<int>  y(1,2,3);
        Matrix<bool> z;
        Matrix<bool> t(1,2,1);
        z = (y >= x);
        CPPUNIT_ASSERT(z.eq(t));

    }

    void test_greater_equal_Two () {
        Matrix<int>  x(1,1,2);
        Matrix<int>  y(1,1,3);
        Matrix<bool> z;
        Matrix<bool> t(1,1,1);
        z = (y >= x);
        CPPUNIT_ASSERT(z.eq(t));

        x[0][0] = 5;
        z = (y >= x);
        t[0][0] = 0;
        CPPUNIT_ASSERT(z.eq(t));
    }


    void test_greater_equal_Three () {
        Matrix<int>  x(2,2,2);
        Matrix<int>  y(2,2,3);
        Matrix<bool> z;
        Matrix<bool> t(2,2,1);
        z = (y >= x);
        CPPUNIT_ASSERT(z.eq(t));

        x[0][0] = 5;
        x[0][1] = 5;
        z = (y >= x);
        t[0][0] = 0;
        t[0][1] = 0;
        CPPUNIT_ASSERT(z.eq(t));
    }
    // ---------
    // test_plus
    // ---------

    void test_plus_One () {
        Matrix<int> x(1,1,1);
        Matrix<int> y(1,1,3);
        Matrix<int> z(1,1,4);
        x += 0;
        CPPUNIT_ASSERT(x.eq(x));
        x += y;
        CPPUNIT_ASSERT(!x.eq(y));
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_plus_Two () {
        Matrix<int> x(2,2,0);
        Matrix<int> y(2,2,0);
        Matrix<int> z(2,2);
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_plus_Three () {
        Matrix<int> x(2,2,3);
        Matrix<int> y(2,2,4);
        Matrix<int> z(2,2,7);
        x[0][1] = 0;
        z[0][1] = 4;
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    // ----------
    // test_minus
    // ----------

    void test_minus_One () {
        Matrix<int> x(1,1,7);
        Matrix<int> y(1,1,3);
        Matrix<int> z(1,1,4);
        x -= 0;
        CPPUNIT_ASSERT(x.eq(x));
        x -= y;
        CPPUNIT_ASSERT(!x.eq(y));
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_minus_Two () {
        Matrix<int> x(2,2,0);
        Matrix<int> y(2,2,0);
        Matrix<int> z(2,2);
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_minus_Three () {
        Matrix<int> x(2,2,7);
        Matrix<int> y(2,2,4);
        Matrix<int> z(2,2,3);
        x[0][1] = 0;
        z[0][1] = -4;
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
    }
    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies_One () {
        Matrix<int> x(2,1,2);
        Matrix<int> y(1,2,2);
        Matrix<int> z(2,1,0);
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        Matrix<int> t(2,2,0);
        x *= y;
        CPPUNIT_ASSERT(x.eq(t));
    }

    void test_multiplies_Two () {
        Matrix<int> x(2,1,2);
        Matrix<int> y(1,2,2);
        Matrix<int> z(2,2,4);
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_multiplies_Three () {
        Matrix<double> x(1,1,3.5);
        Matrix<double> y(1,1,2.0);
        Matrix<double> z(1,1,7.0);
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    // -------------
    // test_iterator
    // -------------

    void test_iterator () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor_One);
    CPPUNIT_TEST(test_constructor_Two);
    CPPUNIT_TEST(test_constructor_Three);
    CPPUNIT_TEST(test_index_One);
    CPPUNIT_TEST(test_index_Two);
    CPPUNIT_TEST(test_index_Three);
    CPPUNIT_TEST(test_equals_One);
    CPPUNIT_TEST(test_equals_Two);
    CPPUNIT_TEST(test_equals_Three);
    CPPUNIT_TEST(test_diff_One);
    CPPUNIT_TEST(test_diff_Two);
    CPPUNIT_TEST(test_less_than_One);
    CPPUNIT_TEST(test_less_than_Two);
    CPPUNIT_TEST(test_less_than_Three);
    CPPUNIT_TEST(test_greater_than_One);
    CPPUNIT_TEST(test_greater_than_Two);
    CPPUNIT_TEST(test_greater_than_Three);
    CPPUNIT_TEST(test_less_equal_One);
    CPPUNIT_TEST(test_less_equal_Two);
    CPPUNIT_TEST(test_less_equal_Three);
    CPPUNIT_TEST(test_greater_equal_One);
    CPPUNIT_TEST(test_greater_equal_Two);
    CPPUNIT_TEST(test_greater_equal_Three);
    CPPUNIT_TEST(test_plus_One);
    CPPUNIT_TEST(test_plus_Two);
    CPPUNIT_TEST(test_plus_Three);
    CPPUNIT_TEST(test_minus_One);
    CPPUNIT_TEST(test_minus_Two);
    CPPUNIT_TEST(test_minus_Three);
    CPPUNIT_TEST(test_multiplies_One);
    CPPUNIT_TEST(test_multiplies_Two);
    CPPUNIT_TEST(test_multiplies_Three);
    CPPUNIT_TEST(test_iterator);
    CPPUNIT_TEST(test_const_iterator);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestMatrix.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestMatrix::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}
