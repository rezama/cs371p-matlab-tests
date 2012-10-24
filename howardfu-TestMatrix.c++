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

    // ----------
    // test_index
    // ----------

    void test_index_1 () {
        const Matrix<int> x(10,10,10);
        CPPUNIT_ASSERT(x[1][3] == 10);
        CPPUNIT_ASSERT(x[5][3] == 10);
        CPPUNIT_ASSERT(x[2][8] == 10);
        CPPUNIT_ASSERT(x[0][9] == 10);}

    void test_index_2 () {
        const Matrix<int> x(2,2,5);
        CPPUNIT_ASSERT(x[0][0] == 5);}

    void test_index_3 () {
        const Matrix<int> x(2,5,9);
        CPPUNIT_ASSERT(x[1][4] == 9);}

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
        Matrix<int>  x(5,5,1);
        Matrix<int>  y(5,5,1);
        Matrix<bool> z;
        Matrix<bool> t(5,5,true);
	z = (x == y); 
	        
        CPPUNIT_ASSERT(z.eq(t));}

    void test_equals_3 () {
        Matrix<int>  x(1,1);
        Matrix<int>  y(1,1);
        Matrix<bool> z;
        Matrix<bool> t(1,1,true);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    // -----------
    // test_not_equals
    // -----------

    void test_not_equals_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_not_equals_2 () {
        Matrix<int>  x(5,5,1);
        Matrix<int>  y(5,5,1);
        Matrix<bool> z;
        Matrix<bool> t(5,5,false);
	z = (x != y);	        
        CPPUNIT_ASSERT(z.eq(t));}

    void test_not_equals_3 () {
        Matrix<int>  x(1,1);
        Matrix<int>  y(1,1);
        Matrix<bool> z;
        Matrix<bool> t(1,1,false);
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_less_than
    // --------------

    void test_less_than_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_2 () {
        Matrix<int>  x(5,5,2);
        Matrix<int>  y(5,5,3);
        Matrix<bool> z;
        Matrix<bool> t(5,5,true);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_3 () {
        Matrix<int>  x(1,1,0);
        Matrix<int>  y(1,1,1);
        Matrix<bool> z;
        Matrix<bool> t(1,1,true);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_less_than_or_equal
    // --------------

    void test_less_than_or_equal_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_or_equal_2 () {
        Matrix<int>  x(5,5,3);
        Matrix<int>  y(5,5,3);
        Matrix<bool> z;
        Matrix<bool> t(5,5,true);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_or_equal_3 () {
        Matrix<int>  x(1,1,2);
        Matrix<int>  y(1,1,1);
        Matrix<bool> z;
        Matrix<bool> t(1,1,false);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_greater_than
    // --------------

    void test_greater_than_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_2 () {
        Matrix<int>  x(5,5,2);
        Matrix<int>  y(5,5,3);
        Matrix<bool> z;
        Matrix<bool> t(5,5,false);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_3 () {
        Matrix<int>  x(1,1,1);
        Matrix<int>  y(1,1,0);
        Matrix<bool> z;
        Matrix<bool> t(1,1,true);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_greater_than_or_equal
    // --------------

    void test_greater_than_or_equal_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_or_equal_2 () {
        Matrix<int>  x(5,5,3);
        Matrix<int>  y(5,5,3);
        Matrix<bool> z;
        Matrix<bool> t(5,5,true);
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_or_equal_3 () {
        Matrix<int>  x(1,1,1);
        Matrix<int>  y(1,1,2);
        Matrix<bool> z;
        Matrix<bool> t(1,1,false);
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));}

    // ---------
    // test_plus
    // ---------

    void test_plus_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = x + 0;
        CPPUNIT_ASSERT(x.eq(z));
        x = x + y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_plus_2 () {
        Matrix<int> x (1,1,1);
        Matrix<int> y (1,1,2);
        Matrix<int> z1(1,1,1);
	Matrix<int> z2(1,1,3);	
        x = x + 0;
        CPPUNIT_ASSERT(x.eq(z1));
        x = x + y;
        CPPUNIT_ASSERT(x.eq(z2));}

    void test_plus_3 () {
        Matrix<int> x (5,5,1);
        Matrix<int> y (5,5,2);
        Matrix<int> z1(5,5,1);
	Matrix<int> z2(5,5,3);
        x = x + 0;
        CPPUNIT_ASSERT(x.eq(z1));
        x = x + y;
        CPPUNIT_ASSERT(x.eq(z2));}

    // ----------
    // test_minus
    // ----------

    void test_minus_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = x - 0;
        CPPUNIT_ASSERT(x.eq(z));
        x = x - y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_minus_2 () {
        Matrix<int> x (1,1,1);
        Matrix<int> y (1,1,2);
        Matrix<int> z1(1,1,1);
	Matrix<int> z2(1,1,-1);	
        x = x - 0;
        CPPUNIT_ASSERT(x.eq(z1));
        x = x - y;
        CPPUNIT_ASSERT(x.eq(z2));}

    void test_minus_3 () {
        Matrix<int> x (5,5,4);
        Matrix<int> y (5,5,2);
        Matrix<int> z1(5,5,4);
	Matrix<int> z2(5,5,2);
        x = x - 0;
        CPPUNIT_ASSERT(x.eq(z1));
        x = x - y;
        CPPUNIT_ASSERT(x.eq(z2));}

    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = x * 0;
        CPPUNIT_ASSERT(x.eq(z));
        x = x * y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_multiplies_2 () {
        Matrix<int> x1(1,1,1);
	Matrix<int> x2(1,1,1);
        Matrix<int> y (1,1,2);
        Matrix<int> z1(1,1,0);
	Matrix<int> z2(1,1,2);	
        x1 = x1 * 0;
        CPPUNIT_ASSERT(x1.eq(z1));
        x2 = x2 * y;
        CPPUNIT_ASSERT(x2.eq(z2));}

    void test_multiplies_3 () {
        Matrix<int> x1(5,5,4);
	Matrix<int> x2(5,5,4);
        Matrix<int> y (5,5,2);
        Matrix<int> z1(5,5,0);
	Matrix<int> z2(5,5,40);
        x1 = x1 * 0;
        CPPUNIT_ASSERT(x1.eq(z1));
        x2 = x2 * y;
        CPPUNIT_ASSERT(x2.eq(z2));}

    // ----------------
    // test_plus_equals
    // ----------------

    void test_plus_equals_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_plus_equals_2 () {
        Matrix<int> x (1,1,1);
        Matrix<int> y (1,1,2);
        Matrix<int> z1(1,1,1);
	Matrix<int> z2(1,1,3);	
        x += 0;
        CPPUNIT_ASSERT(x.eq(z1));
        x += y;
        CPPUNIT_ASSERT(x.eq(z2));}

    void test_plus_equals_3 () {
        Matrix<int> x (5,5,1);
        Matrix<int> y (5,5,2);
        Matrix<int> z1(5,5,1);
	Matrix<int> z2(5,5,3);
        x += 0;
        CPPUNIT_ASSERT(x.eq(z1));
        x += y;
        CPPUNIT_ASSERT(x.eq(z2));}

    // -----------------
    // test_minus_equals
    // -----------------

    void test_minus_equals_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_minus_equals_2 () {
        Matrix<int> x (1,1,1);
        Matrix<int> y (1,1,2);
        Matrix<int> z1(1,1,1);
	Matrix<int> z2(1,1,-1);	
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z1));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z2));}

    void test_minus_equals_3 () {
        Matrix<int> x (5,5,4);
        Matrix<int> y (5,5,2);
        Matrix<int> z1(5,5,4);
	Matrix<int> z2(5,5,2);
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z1));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z2));}

    // ---------------------
    // test_multiplies_equal
    // ---------------------

    void test_multiplies_equals_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_multiplies_equals_2 () {
        Matrix<int> x1(1,1,1);
	Matrix<int> x2(1,1,1);
        Matrix<int> y (1,1,2);
        Matrix<int> z1(1,1,0);
	Matrix<int> z2(1,1,2);	
        x1 *= 0;
        CPPUNIT_ASSERT(x1.eq(z1));
        x2 *= y;
        CPPUNIT_ASSERT(x2.eq(z2));}

    void test_multiplies_equals_3 () {
        Matrix<int> x1(5,5,4);
	Matrix<int> x2(5,5,4);
        Matrix<int> y (5,5,2);
        Matrix<int> z1(5,5,0);
	Matrix<int> z2(5,5,40);
        x1 *= 0;
        CPPUNIT_ASSERT(x1.eq(z1));
        x2 *= y;
        CPPUNIT_ASSERT(x2.eq(z2));}

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
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_index_1);
    CPPUNIT_TEST(test_index_2);
    CPPUNIT_TEST(test_index_3);
    CPPUNIT_TEST(test_equals_1);
    CPPUNIT_TEST(test_equals_2);
    CPPUNIT_TEST(test_equals_3);
    CPPUNIT_TEST(test_not_equals_1);
    CPPUNIT_TEST(test_not_equals_2);
    CPPUNIT_TEST(test_not_equals_3);
    CPPUNIT_TEST(test_less_than_1);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
    CPPUNIT_TEST(test_less_than_or_equal_1);
    CPPUNIT_TEST(test_less_than_or_equal_2);
    CPPUNIT_TEST(test_less_than_or_equal_3);
    CPPUNIT_TEST(test_greater_than_1);
    CPPUNIT_TEST(test_greater_than_2);
    CPPUNIT_TEST(test_greater_than_3);
    CPPUNIT_TEST(test_greater_than_or_equal_1);
    CPPUNIT_TEST(test_greater_than_or_equal_2);
    CPPUNIT_TEST(test_greater_than_or_equal_3);
    CPPUNIT_TEST(test_plus_1);
    CPPUNIT_TEST(test_plus_2);
    CPPUNIT_TEST(test_plus_3);
    CPPUNIT_TEST(test_minus_1);
    CPPUNIT_TEST(test_minus_2);
    CPPUNIT_TEST(test_minus_3);
    CPPUNIT_TEST(test_multiplies_1);
    CPPUNIT_TEST(test_multiplies_2);
    CPPUNIT_TEST(test_multiplies_3);
    CPPUNIT_TEST(test_plus_equals_1);
    CPPUNIT_TEST(test_plus_equals_2);
    CPPUNIT_TEST(test_plus_equals_3);
    CPPUNIT_TEST(test_minus_equals_1);
    CPPUNIT_TEST(test_minus_equals_2);
    CPPUNIT_TEST(test_minus_equals_3);
    CPPUNIT_TEST(test_multiplies_equals_1);
    CPPUNIT_TEST(test_multiplies_equals_2);
    CPPUNIT_TEST(test_multiplies_equals_3);
    //CPPUNIT_TEST(test_iterator);
    //CPPUNIT_TEST(test_const_iterator);
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
