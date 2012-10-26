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

    void test_constructor_1 () {
        Matrix<int> x;
        CPPUNIT_ASSERT(x.size() == 0);}

    void test_constructor_2 () {
        Matrix<int> y(2);
        CPPUNIT_ASSERT(y.size() == 2);}

    void test_constructor_3 () {
        Matrix<int> z(2, 3);
        CPPUNIT_ASSERT(z.size() == 2);
        CPPUNIT_ASSERT(z[0].size() == 3);
        CPPUNIT_ASSERT(z[1].size() == 3);}

    void test_constructor_4 () {
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(t.size() == 2);
        CPPUNIT_ASSERT(t[0].size() == 3);
        CPPUNIT_ASSERT(t[1].size() == 3);
        for (int i=0; i<2; ++i) {
            for (int j=0; j<3; ++j) {
                CPPUNIT_ASSERT(t[i][j] == 4);
            }
        }
    }

    // ----------
    // test_index
    // ----------

    void test_index_1 () {
        const Matrix<int> x(1, 1);
        CPPUNIT_ASSERT(x[0][0] == 0);}

    void test_index_2 () {
        const Matrix<int> x(1, 1, 1);
        CPPUNIT_ASSERT(x[0][0] == 1);}

    void test_index_3 () {
        const Matrix<int> x(2, 3, 4);
        for (int i=0; i<2; ++i) {
            for (int j=0; j<3; ++j) {
                CPPUNIT_ASSERT(x[i][j] == 4);
            }
        }
    }

    void test_index_4 () {
        const Matrix<int> x(20, 20, 20);
        for (int i=0; i<20; ++i) {
            for (int j=0; j<20; ++j) {
                CPPUNIT_ASSERT(x[i][j] == 20);
            }
        }
    }


    // -----------
    // test_equals
    // -----------

    void test_equals_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_equals_2 () {
        Matrix<int>  x(2, 2, 2);
        Matrix<int>  y(2, 2, 2);
        Matrix<bool> z;
        Matrix<bool> t(2, 2, 1);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_equals_3 () {
        Matrix<int>  x(3, 4, 5);
        Matrix<int>  y(3, 4, 6);
        Matrix<bool> z;
        Matrix<bool> t(3, 4, 0);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_equals_4 () {
        Matrix<int>  x(6, 3, 2);
        Matrix<int>  y(6, 3, 7);
        Matrix<bool> z;
        Matrix<bool> t(6, 3, 0);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}


    // -----------
    // test_notequals
    // -----------

    void test_notequals_1 () {
        Matrix<int>  x(2, 2, 2);
        Matrix<int>  y(2, 2, 2);
        Matrix<bool> z;
        Matrix<bool> t(2, 2, 0);
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_notequals_2 () {
        Matrix<int>  x(3, 4, 5);
        Matrix<int>  y(3, 4, 6);
        Matrix<bool> z;
        Matrix<bool> t(3, 4, 1);
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_notequals_3() {
        Matrix<int>  x(6, 3, 2);
        Matrix<int>  y(6, 3, 7);
        Matrix<bool> z;
        Matrix<bool> t(6, 3, 1);
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_less_than
    // --------------

    void test_less_than_1 () {
        Matrix<int>  x(1, 1, 0);
        Matrix<int>  y(1, 1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_2 () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 0);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_3 () {
        Matrix<int>  x(4, 6, 4);
        Matrix<int>  y(4, 6, 5);
        Matrix<bool> z;
        Matrix<bool> t(4, 6, 1);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_less_thanequals
    // --------------

    void test_less_thanequals_1 () {
        Matrix<int>  x(1, 1, 0);
        Matrix<int>  y(1, 1, 0);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_thanequals_2 () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 0);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_thanequals_3 () {
        Matrix<int>  x(4, 6, 4);
        Matrix<int>  y(4, 6, 5);
        Matrix<bool> z;
        Matrix<bool> t(4, 6, 1);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_greater_than
    // --------------

    void test_greater_than_1 () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_2 () {
        Matrix<int>  x(1, 1, 0);
        Matrix<int>  y(1, 1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 0);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_3 () {
        Matrix<int>  x(4, 6, 5);
        Matrix<int>  y(4, 6, 4);
        Matrix<bool> z;
        Matrix<bool> t(4, 6, 1);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_greater_thanequals
    // --------------

    void test_greater_thanequals_1 () {
        Matrix<int>  x(1, 1, 0);
        Matrix<int>  y(1, 1, 0);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_thanequals_2 () {
        Matrix<int>  x(1, 1, 0);
        Matrix<int>  y(1, 1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 0);
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_thanequals_3 () {
        Matrix<int>  x(4, 6, 5);
        Matrix<int>  y(4, 6, 4);
        Matrix<bool> z;
        Matrix<bool> t(4, 6, 1);
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));}

    // ---------
    // test_plus
    // ---------

    void test_plus_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_plus_2 () {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, 1);
        Matrix<int> z(1, 1, 2);
        Matrix<int> t(1, 1, 3);
        x += 1;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(t));}

    void test_plus_3 () {
        Matrix<int> x(4, 5, 6);
        Matrix<int> y(4, 5, 3);
        Matrix<int> z(4, 5, 7);
        Matrix<int> t(4, 5, 10);
        x += 1;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(t));}

    void test_plus_4 () {
        Matrix<int> x(2, 3, 1);
        Matrix<int> y(2, 3, 10);
        Matrix<int> z(2, 3, 3);
        Matrix<int> t(2, 3, 13);
        x += 2;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(t));}

    void test_plus_5 () {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        x[0][0] = 1;
        x[0][1] = 4;
        x[1][0] = 6;
        x[1][1] = 9;
        y[0][0] = 2;
        y[0][1] = 3;
        y[1][0] = 4;
        y[1][1] = 5;
        x += y;
        CPPUNIT_ASSERT(x[0][0] == 3);
        CPPUNIT_ASSERT(x[0][1] == 7);
        CPPUNIT_ASSERT(x[1][0] == 10);
        CPPUNIT_ASSERT(x[1][1] == 14);
    }


    // ----------
    // test_minus
    // ----------

    void test_minus_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_minus_2 () {
        Matrix<int> x(1, 1, 5);
        Matrix<int> y(1, 1, 1);
        Matrix<int> z(1, 1, 4);
        Matrix<int> t(1, 1, 3);
        x -= 1;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(t));}

    void test_minus_3 () {
        Matrix<int> x(4, 5, 6);
        Matrix<int> y(4, 5, 3);
        Matrix<int> z(4, 5, 5);
        Matrix<int> t(4, 5, 2);
        x -= 1;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(t));}

    void test_minus_4 () {
        Matrix<int> x(2, 3, 10);
        Matrix<int> y(2, 3, 8);
        Matrix<int> z(2, 3, 8);
        Matrix<int> t(2, 3, 0);
        x -= 2;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(t));}

    void test_minus_5 () {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        x[0][0] = 1;
        x[0][1] = 4;
        x[1][0] = 6;
        x[1][1] = 9;
        y[0][0] = 2;
        y[0][1] = 3;
        y[1][0] = 4;
        y[1][1] = 5;
        x -= y;
        CPPUNIT_ASSERT(x[0][0] == -1);
        CPPUNIT_ASSERT(x[0][1] == 1);
        CPPUNIT_ASSERT(x[1][0] == 2);
        CPPUNIT_ASSERT(x[1][1] == 4);
    }

    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_multiplies_2 () {
        Matrix<int> x(1, 1, 5);
        Matrix<int> y(1, 1, 1);
        Matrix<int> z(1, 1, 0);
        Matrix<int> t(1, 1, 0);
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(t));}

    void test_multiplies_3 () {
        Matrix<int> x(4, 5, 6);
        Matrix<int> y(4, 5, 3);
        Matrix<int> z(4, 5, 12);
        Matrix<int> t(4, 5, 36);
        x *= 2;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(t));}

    void test_multiplies_4 () {
        Matrix<int> x(2, 3, 10);
        Matrix<int> y(2, 3, 2);
        Matrix<int> z(2, 3, 30);
        Matrix<int> t(2, 3, 60);
        x *= 3;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(t));}

    void test_multiplies_5 () {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        x[0][0] = 1;
        x[0][1] = 4;
        x[1][0] = 6;
        x[1][1] = 9;
        y[0][0] = 2;
        y[0][1] = 3;
        y[1][0] = 4;
        y[1][1] = 5;
        x *= y;
        CPPUNIT_ASSERT(x[0][0] == 2);
        CPPUNIT_ASSERT(x[0][1] == 12);
        CPPUNIT_ASSERT(x[1][0] == 24);
        CPPUNIT_ASSERT(x[1][1] == 45);
    }

    // -------------
    // test_iterator
    // -------------

    void test_iterator_1 () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    void test_iterator_2 () {
        Matrix<int> x(1, 1);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b+1 == e);}

    void test_iterator_3 () {
        Matrix<int> x(4, 4);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b+4 == e);}

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator_1 () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    void test_const_iterator_2 () {
        const Matrix<int> x(1, 1);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b+1 == e);}

    void test_const_iterator_3 () {
        const Matrix<int> x(4, 4);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b+4 == e);}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_constructor_4);
    CPPUNIT_TEST(test_index_1);
    CPPUNIT_TEST(test_index_2);
    CPPUNIT_TEST(test_index_3);
    CPPUNIT_TEST(test_index_4);
    CPPUNIT_TEST(test_equals_1);
    CPPUNIT_TEST(test_equals_2);
    CPPUNIT_TEST(test_equals_3);
    CPPUNIT_TEST(test_equals_4);
    CPPUNIT_TEST(test_notequals_1);
    CPPUNIT_TEST(test_notequals_2);
    CPPUNIT_TEST(test_notequals_3);
    CPPUNIT_TEST(test_less_than_1);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
    CPPUNIT_TEST(test_less_thanequals_1);
    CPPUNIT_TEST(test_less_thanequals_2);
    CPPUNIT_TEST(test_less_thanequals_3);
    CPPUNIT_TEST(test_greater_than_1);
    CPPUNIT_TEST(test_greater_than_2);
    CPPUNIT_TEST(test_greater_than_3);
    CPPUNIT_TEST(test_greater_thanequals_1);
    CPPUNIT_TEST(test_greater_thanequals_2);
    CPPUNIT_TEST(test_greater_thanequals_3);
    CPPUNIT_TEST(test_plus_1);
    CPPUNIT_TEST(test_plus_2);
    CPPUNIT_TEST(test_plus_3);
    CPPUNIT_TEST(test_plus_4);
    CPPUNIT_TEST(test_plus_5);
    CPPUNIT_TEST(test_minus_1);
    CPPUNIT_TEST(test_minus_2);
    CPPUNIT_TEST(test_minus_3);
    CPPUNIT_TEST(test_minus_4);
    CPPUNIT_TEST(test_minus_5);
    CPPUNIT_TEST(test_multiplies_1);
    CPPUNIT_TEST(test_multiplies_2);
    CPPUNIT_TEST(test_multiplies_3);
    CPPUNIT_TEST(test_multiplies_4);
    CPPUNIT_TEST(test_multiplies_5);
    CPPUNIT_TEST(test_iterator_1);
    CPPUNIT_TEST(test_iterator_2);
    CPPUNIT_TEST(test_iterator_3);
    CPPUNIT_TEST(test_const_iterator_1);
    CPPUNIT_TEST(test_const_iterator_2);
    CPPUNIT_TEST(test_const_iterator_3);
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
    return 0;}