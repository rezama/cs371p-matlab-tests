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
        Matrix<int> t(3, 3, 4);
        CPPUNIT_ASSERT(x.size() == 0);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(z.size() == 2);
        CPPUNIT_ASSERT(t.size() == 3);}

    // ----------
    // test_index
    // ----------

    void test_index () {
        const Matrix<int> x(1,1);
		const Matrix<int> y(2,2);
		const Matrix<int> z(5, 5, 8);
        CPPUNIT_ASSERT(x[0][0] == 0);
		CPPUNIT_ASSERT(y[1][1] == 0);
		CPPUNIT_ASSERT(z[2][4] == 8);}

    // -----------
    // test_equals
    // -----------

    void test_equals (){
      try{
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
		Matrix<int> x1(1, 1, 1);
        Matrix<int> y1(1, 1, 1);
        Matrix<bool> z1(1, 1);
        Matrix<bool> t1(1, 1, 1);
		Matrix<int> x2(1, 1, 1);
        Matrix<int> y2(1, 1, 0);
        Matrix<bool> z2;
        Matrix<bool> t2(1, 1, 1);
        z = (x == y);
		z1 = (x1 == y1);
		z2 = (x2 == y2);

  	    CPPUNIT_ASSERT(z.eq(t));
        CPPUNIT_ASSERT(z1.eq(t1));
		CPPUNIT_ASSERT(!z2.eq(t2));
	  }
	  catch(std::invalid_argument& a){
		std::cout << "Caught exception" << std::endl;}
     }

    // --------------
    // test_less_than
    // --------------

    void test_less_than () {
	try{
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
   		Matrix<int> x1(1, 1, 1);
        Matrix<int> y1(1, 1, 0);
        Matrix<bool> z1;
        Matrix<bool> t1(1, 1, 0);
		Matrix<int> x2(1, 1, 0);
        Matrix<int> y2(1, 1, 1);
        Matrix<bool> z2;
        Matrix<bool> t2(1, 1, 1);
		z = (x < y);
		z1 = (x1 < y1);
		z2 = (x2 < y2);
   		CPPUNIT_ASSERT(z.eq(t));
		CPPUNIT_ASSERT(z1.eq(t1));
		CPPUNIT_ASSERT(z2.eq(t2));
	}
	catch(std::invalid_argument& a){
		std::cout << "Caught exception" << std::endl;}
	}



    // ---------
    // test_plus
    // ---------

    void test_plus () {
	try{
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
        Matrix<int> x1(1, 1, 1);
        Matrix<int> y1(1, 1, 1);
        Matrix<int> z1(1, 1, 2);
        x1 += 1;
        CPPUNIT_ASSERT(x1.eq(z1));
        x1 += y1;
        z1 += 1;
        CPPUNIT_ASSERT(x1.eq(z1));
        Matrix<int> x2(2, 2, 3);
        Matrix<int> y2(2, 2, 4);
        Matrix<int> z2(2, 2, 5);
        x2 += 2;
        CPPUNIT_ASSERT(x2.eq(z2));
        x2 += y2;
        z2 += 4;
        CPPUNIT_ASSERT(x2.eq(z2));
	}
	catch(std::invalid_argument& a){
		std::cout << "Caught exception" << std::endl;}
	}
	


    // ----------
    // test_minus
    // ----------

    void test_minus () {
	try{
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
        Matrix<int> x1(1, 1, 2);
        Matrix<int> y1(1, 1, 1);
        Matrix<int> z1(1, 1, 1);
        x1 -= 1;
        CPPUNIT_ASSERT(x1.eq(z1));
        x1 -= y1;
        z1 -= 1;
        CPPUNIT_ASSERT(x1.eq(z1));
        Matrix<int> x2(2, 2, 3);
        Matrix<int> y2(2, 2, 4);
        Matrix<int> z2(2, 2, 1);
        x2 -= 2;
        CPPUNIT_ASSERT(x2.eq(z2));
        x2 -= y2;
        z2 -= 4;
        CPPUNIT_ASSERT(x2.eq(z2));
		}
	catch(std::invalid_argument& a){
		std::cout << "Caught exception" << std::endl;}
	}



    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies () {
	try{
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
        Matrix<int> x1(1, 1, 2);
        Matrix<int> y1(1, 1, 1);
        Matrix<int> z1(1, 1, 2);
        x1 *= 1;
        CPPUNIT_ASSERT(x1.eq(z1));
        x1 *= y1;
        z1 *= 1;
        CPPUNIT_ASSERT(x1.eq(z1));
        Matrix<int> x2(2, 2, 3);
        Matrix<int> y2(2, 2, 4);
        Matrix<int> z2(2, 2, 6);
        x2 *= 2;
        CPPUNIT_ASSERT(x2.eq(z2));
        x2 *= y2;
        z2 *= 8;
        CPPUNIT_ASSERT(x2.eq(z2));
	}
	catch(std::invalid_argument& a){
		std::cout << "Caught exception" << std::endl;}
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
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_index);
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_multiplies);
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
