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

    void test_constructor () {
        Matrix<int> x;
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(x.size() == 0);}

    // -----------------
    // test_constructor2
    // -----------------

    void test_constructor2 () {
        Matrix<int> x;
        Matrix<double> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(y.size() == 2);}





    // ----------
    // test_index
    // ----------

    void test_index () {
        const Matrix<int> x(1, 1);
        CPPUNIT_ASSERT(x[0][0] == 0);}


    void test_index2 () {
        const Matrix<int> x(3, 3, 100);
        CPPUNIT_ASSERT(x[0][0] == 100);}



    // -----------
    // test_equals
    // -----------

    void test_equals_default () {
        Matrix<int>  z;
        Matrix<int>  t;
        CPPUNIT_ASSERT(z.eq(t));
    }


    void test_equals () {
        Matrix<int>  x(5,5,1);
        Matrix<int>  y(5,5,1);
        Matrix<bool> z;
        Matrix<bool> t(5,5,1);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
        t[4][4] = 0;
        CPPUNIT_ASSERT(!z.eq(t));
    }

    void test_equals2 () {
        Matrix<int>  z(3, 3, 4);
        Matrix<int>  t(3, 3, 4);
        CPPUNIT_ASSERT(z.eq(t));
        z[0][0] = 2;
        CPPUNIT_ASSERT(!z.eq(t));}



    // --------------
    // test_less_than
    // --------------

    void test_less_than () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}


    void test_less_than2 () {
        Matrix<int>  x(2, 3);
        Matrix<int>  y(2, 3);
        Matrix<bool> z;
        Matrix<bool> t(2, 3, 0);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
        x[0][0] = -5;
        t[0][0] = 1;
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
     }


//--------------------------------------------------------------------

    // ---------
    // test_plus
    // ---------

    void test_plus () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}


    void test_plus2 () {
        Matrix<int> x(4, 4, 5);
        Matrix<int> y(4, 4, 10);
        Matrix<int> z = x + y;
        Matrix<int> w(4, 4, 15);
        CPPUNIT_ASSERT(w.eq(z));}



    // ----------
    // test_minus
    // ----------

    void test_minus () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}


    void test_minus2 () {
        Matrix<int> x(4, 4, 6);
        Matrix<int> y(4, 4, 10);
        y -= x;
        Matrix<int> w(4, 4, 4);
        CPPUNIT_ASSERT(w.eq(y));}



    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_multiplies2 () {
        Matrix<int> x(4, 2, 2);
        Matrix<int> y(2, 5, 3);
        Matrix<int> z(4, 5, 12);
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}


    // -------------
    // test_iterator
    // -------------

    void test_iterator () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}


    void test_iterator2 () {
        Matrix<int> x(5,0);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b != e);
        b += 5;
        CPPUNIT_ASSERT(b == e);
    }

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    // -----------
    // test_not_equals1
    // -----------

    void test_not_equals () {
        Matrix<int>  x;
		Matrix<int>  y;
		Matrix<bool> z;
		Matrix<bool> t;
		z = (x != y);

		CPPUNIT_ASSERT(z.eq(t));
    }

    void test_not_equals2 () {
    Matrix<int>  x(1,1,1);
    Matrix<int>  y(1,1,1);
    Matrix<bool> z;
    Matrix<bool> t(1,1,false);
    z = (x != y);
    CPPUNIT_ASSERT(z.eq(t));
    x[0][0] = 2;
    t[0][0] = true;
    z = (x != y);
    CPPUNIT_ASSERT(z.eq(t));
  }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);

    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_constructor2);
    CPPUNIT_TEST(test_index);
    CPPUNIT_TEST(test_index2);
    CPPUNIT_TEST(test_equals_default);
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_equals2);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less_than2);
    CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(test_plus2);
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_minus2);
    CPPUNIT_TEST(test_multiplies);
    CPPUNIT_TEST(test_multiplies2);
    CPPUNIT_TEST(test_iterator);
    CPPUNIT_TEST(test_iterator2);
    CPPUNIT_TEST(test_const_iterator);
    CPPUNIT_TEST(test_not_equals);
    CPPUNIT_TEST(test_not_equals2);

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
