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

    void test_constructor_zero () {
        Matrix<int> x;
        CPPUNIT_ASSERT(x.size() == 0);}

    void test_constructor_neg () {
        Matrix<int> x(-1, -1, -1);
        CPPUNIT_ASSERT(x.size() == 0);}

    void test_constructor_one () {
        Matrix<int> y(2);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(y[0].size() == 0);}

    void test_constructor_two () {
        Matrix<int> z(2, 3);
        CPPUNIT_ASSERT(z.size() == 2);
        CPPUNIT_ASSERT(z[0].size() == 3);}

    void test_constructor_three () {
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(t.size() == 2);
        CPPUNIT_ASSERT(t[0].size() == 3);
        CPPUNIT_ASSERT(t[0][0] == 4);}

    // ----------
    // test_index
    // ----------

    void test_index () {
        const Matrix<int> x(1, 1);
        CPPUNIT_ASSERT(x[0][0] == 0);}

    void test_index_row () {
        const Matrix<int> x(2, 1);
        CPPUNIT_ASSERT(x[1][0] == 0);}

    void test_index_col () {
        const Matrix<int> x(1, 2);
        CPPUNIT_ASSERT(x[0][1] == 0);}

    void test_index_assign () {
        Matrix<int> x(2, 2);
        x[0][1] = 1;
        x[1][0] = -1;
        CPPUNIT_ASSERT(x[0][1] == 1);
        CPPUNIT_ASSERT(x[1][0] == -1);
        CPPUNIT_ASSERT(x[0][0] == 0);
        CPPUNIT_ASSERT(x[1][1] == 0);}

    // -----------
    // test_equals
    // -----------

    void test_equals_true () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, true);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_equals_false () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, false);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_not_equals_true () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, true);
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_not_equals_false () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, false);
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_less_than
    // --------------

    void test_less_than_true () {
        Matrix<int>  x(1, 1, 0);
        Matrix<int>  y(1, 1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, true);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_false () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, false);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_true () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, true);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_false () {
        Matrix<int>  x(1, 1, 0);
        Matrix<int>  y(1, 1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, false);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}

    // ---------
    // test_plus
    // ---------

    void test_plus_zero () {
        Matrix<int> x(1, 1, 0);
        Matrix<int> y(1, 1, 0);
        Matrix<int> z(1, 1, 0);
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_plus_one () {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, 1);
        Matrix<int> z(1, 1, 2);
        Matrix<int> zz(1, 1, 3);
        x += 1;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(zz));}

    void test_plus_neg () {
        Matrix<int> x(1, 1, 3);
        Matrix<int> y(1, 1, -1);
        Matrix<int> z(1, 1, 2);
        Matrix<int> zz(1, 1, 1);
        x += (-1);
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(zz));}

    void test_plus_two_by_two () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        Matrix<int> z(2, 2, 2);
        Matrix<int> zz(2, 2, 3);
        x += 1;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(zz));}

    // ----------
    // test_minus
    // ----------

    void test_minus_zero () {
        Matrix<int> x(1, 1, 0);
        Matrix<int> y(1, 1, 0);
        Matrix<int> z(1, 1, 0);
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_minus_one () {
        Matrix<int> x(1, 1, 3);
        Matrix<int> y(1, 1, 1);
        Matrix<int> z(1, 1, 2);
        Matrix<int> zz(1, 1, 1);
        x -= 1;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(zz));}

    void test_minus_neg () {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, -1);
        Matrix<int> z(1, 1, 2);
        Matrix<int> zz(1, 1, 3);
        x -= (-1);
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(zz));}

    void test_minus_two_by_two () {
        Matrix<int> x(2, 2, 3);
        Matrix<int> y(2, 2, 1);
        Matrix<int> z(2, 2, 2);
        Matrix<int> zz(2, 2, 1);
        x -= 1;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(zz));}

    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies_zero () {
        Matrix<int> x(1, 1, 0);
        Matrix<int> y(1, 1, 0);
        Matrix<int> z(1, 1, 0);
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_multiplies_one () {
        Matrix<int> x(1, 1, 2);
        Matrix<int> y(1, 1, 1);
        Matrix<int> z(1, 1, 2);
        x *= 1;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_multiplies_neg () {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, -1);
        Matrix<int> z(1, 1, -1);
        Matrix<int> zz(1, 1, 1);
        x *= (-1);
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(zz));}

    void test_multiplies_two_by_two () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 2);
        Matrix<int> z(2, 2, 2);
        Matrix<int> zz(2, 2, 4);
        x *= 2;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(zz));}

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
    CPPUNIT_TEST(test_constructor_zero);
    CPPUNIT_TEST(test_constructor_neg);
    CPPUNIT_TEST(test_constructor_one);
    CPPUNIT_TEST(test_constructor_two);
    CPPUNIT_TEST(test_constructor_three);
    CPPUNIT_TEST(test_index);
    CPPUNIT_TEST(test_index_row);
    CPPUNIT_TEST(test_index_col);
    CPPUNIT_TEST(test_index_assign);
    CPPUNIT_TEST(test_equals_true);
    CPPUNIT_TEST(test_equals_false);
    CPPUNIT_TEST(test_not_equals_true);
    CPPUNIT_TEST(test_not_equals_false);
    CPPUNIT_TEST(test_less_than_true);
    CPPUNIT_TEST(test_less_than_false);
    CPPUNIT_TEST(test_greater_than_true);
    CPPUNIT_TEST(test_greater_than_false);
    CPPUNIT_TEST(test_plus_zero);
    CPPUNIT_TEST(test_plus_one);
    CPPUNIT_TEST(test_plus_neg);
    CPPUNIT_TEST(test_plus_two_by_two);
    CPPUNIT_TEST(test_minus_zero);
    CPPUNIT_TEST(test_minus_one);
    CPPUNIT_TEST(test_minus_neg);
    CPPUNIT_TEST(test_minus_two_by_two);
    CPPUNIT_TEST(test_multiplies_zero);
    CPPUNIT_TEST(test_multiplies_one);
    CPPUNIT_TEST(test_multiplies_neg);
    CPPUNIT_TEST(test_multiplies_two_by_two);
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
    return 0;}
