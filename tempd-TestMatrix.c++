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
#include "stdio.h"
#include <vector>


using namespace std;
// ----------
// TestMatrix
// ----------

template <typename T>
struct TestMatrix : CppUnit::TestFixture {

	// --------
	// typedefs
	// --------
	typedef typename T::iterator         iterator;
	typedef typename T::const_iterator   const_iterator;

    // ----------------
    // test_constructor
    // ----------------
	
	void test_vectors() {
		vector<int> x;
		vector<int> y;
		CPPUNIT_ASSERT( x == y);

	}

    void test_constructor () {
        T x;
		T y(2);
		T z(2, 3);
		T t(2, 3, 4);
        CPPUNIT_ASSERT(x.size()    == 0);
		CPPUNIT_ASSERT(y.size()    == 2);
		CPPUNIT_ASSERT(y[0].size() == 0);
		CPPUNIT_ASSERT(z.size()    == 2);
		CPPUNIT_ASSERT(z[0].size() == 3);
		CPPUNIT_ASSERT(t.size()    == 2);
		CPPUNIT_ASSERT(t[0].size() == 3);
		CPPUNIT_ASSERT(t[0][0]     == 4);
	}

    // ----------
    // test_index
    // ----------

    void test_index () {
		try{
			T x;
			x[0];
		}
		catch( domain_error& e ){
			CPPUNIT_ASSERT(true);
		}
		try{
			T y(2);
			y[0][0];
		}
		catch( domain_error& x ){
			CPPUNIT_ASSERT(false);
		}
		
		T t(2, 3, 4);
		t[1][2] = 5;
		CPPUNIT_ASSERT(t[1][2] == 5);
		CPPUNIT_ASSERT(t[0][0] == 4);
		CPPUNIT_ASSERT(t[0][0] != t[1][2]);
	}

    // -----------
    // test_equals
    // -----------

    void test_equals () {
        T  x;
        T  y;
        Matrix<bool> z;
        Matrix<bool> t;

        z = (x == y);
		t = (x == y);

        CPPUNIT_ASSERT(z.eq(t));}
	
	// ---------------
	// test_not_equals
	// ---------------

    void test_not_equals () {
        T  x;
        T  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x != y);
		t = (x != y);
		
		CPPUNIT_ASSERT(z.eq(t));
		
		T a (2, 2, 2);
		T b (2, 2, 3);
		z = (a != b);
		t = (a != b);
		CPPUNIT_ASSERT(z.eq(t));
	}


    // --------------
    // test_less_than
    // --------------

    void test_less_than () {
        T  x;
        T  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x < y);
		t = (x < y);
		
		CPPUNIT_ASSERT(z.eq(t));
		
		T a (2, 2, 2);
		T b (2, 2, 3);
		z = (a < b);
		t = (a < b);
		CPPUNIT_ASSERT(z.eq(t));
	}

    // ---------------------
    // test_less_than_equals
    // ---------------------

    void test_less_than_equals () {
        T  x;
        T  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x <= y);
		t = (x <= y);
		
		CPPUNIT_ASSERT(z.eq(t));
		
		T a (2, 2, 2);
		T b (2, 2, 3);
		T c (2,2,2);
		z = (a <= b);
		t = (a <= b);
		CPPUNIT_ASSERT(z.eq(t));
		t = (a <= c);
		CPPUNIT_ASSERT(z.eq(t));
	}

	// -----------------
	// test_greater_than
	// -----------------

    void test_greater_than () {
        T  x;
        T  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x > y);
		t = (x > y);
		
		CPPUNIT_ASSERT(z.eq(t));

		T a (2, 2, 2);
		T b (2, 2, 3);
		z = (b > a);
		t = (b > a);
		CPPUNIT_ASSERT(z.eq(t));
	}


	// ---------
    // test_plus
    // ---------

    void test_plus () {
        T x;
        T y;
        T z;
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
		T t(2,2,2);
		T u(2,2,2);
		t = t + u;
		CPPUNIT_ASSERT(t.eq(T(2,2,4)));
		u = (u + 2);
		CPPUNIT_ASSERT(u.eq(T(2,2,4)));
		CPPUNIT_ASSERT(u.eq(t));
		u += 2;
		CPPUNIT_ASSERT(u.eq(T(2,2,6)));
	}

    // ----------
    // test_minus
    // ----------

    void test_minus () {
        T x;
        T y;
        T z;
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
		T t(2,2,2);
		T u(2,2,2);
		t = t - u;
		CPPUNIT_ASSERT(t.eq(T(2,2,0)));
		u = (u - 2);
		CPPUNIT_ASSERT(u.eq(T(2,2,0)));
		CPPUNIT_ASSERT(u.eq(t));
		u -= 2;
		CPPUNIT_ASSERT(u.eq(T(2,2,-2)));
	}

    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies () {
        T x;
        T y;
        T z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
		T t(2,2,2);
		T u(2,2,2);
		t = t * u;
		CPPUNIT_ASSERT(t.eq(T(2,2,4)));
		u = (u * 2);
		CPPUNIT_ASSERT(u.eq(T(2,2,4)));
		CPPUNIT_ASSERT(u.eq(t));
		u *= 2;
		CPPUNIT_ASSERT(u.eq(T(2,2,8)));
	}

    // -------------
    // test_iterator
    // -------------

    void test_iterator () {
        T x;
		iterator b = x.begin();
        iterator e = x.end();
        CPPUNIT_ASSERT(b == e);

		T u(2,2,2);
		b = u.begin();
		e = u.end();

		CPPUNIT_ASSERT(b == (e - 2));
	}

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator () {
        const T x;
        const_iterator b = x.begin();
        const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);
		
		const T u(2,2,2);
		b = u.begin();
		e = u.end();

		CPPUNIT_ASSERT(b == (e - 2));
	}

	// -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
	CPPUNIT_TEST(test_vectors);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_index);
    CPPUNIT_TEST(test_equals);
	CPPUNIT_TEST(test_not_equals);
    CPPUNIT_TEST(test_less_than);
	CPPUNIT_TEST(test_less_than_equals);
	CPPUNIT_TEST(test_greater_than);
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
    tr.addTest(TestMatrix< Matrix<int> >::suite());
	tr.addTest(TestMatrix< Matrix<double> >::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
