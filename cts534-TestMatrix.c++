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
        CPPUNIT_ASSERT(x.size() == 0);
		CPPUNIT_ASSERT(y.size() == 0);
		CPPUNIT_ASSERT(z.size() == 2);
		CPPUNIT_ASSERT(z.size() == t.size()); // size is num rows
	}
	
	void test_constructor_defaults () {
		Matrix<int> x;
        Matrix<int> y(0);
        Matrix<int> z(0, 0);
        Matrix<int> t(6, 0, 4);
		CPPUNIT_ASSERT(x.size() == 0);
		CPPUNIT_ASSERT(y.size() == x.size());
		CPPUNIT_ASSERT(z.size() == x.size());
		CPPUNIT_ASSERT(t.size() == x.size());
	}

	void test_constructor_types () {
		Matrix<int> x;
        Matrix<double> y(2);
        Matrix<long> z(2, 3);
        Matrix<float> t(2, 3, 4.0);
        CPPUNIT_ASSERT(x.size() == 0);
		CPPUNIT_ASSERT(y.size() == 0);
		CPPUNIT_ASSERT(z.size() == 2);
		CPPUNIT_ASSERT(z.size() == t.size());
	}

    // ----------
    // test_index
    // ----------

    void test_index () {
        Matrix<int> x(1,1);
        CPPUNIT_ASSERT(x[0][0] == 0);
	}

	void test_index_reference () {
        Matrix<int> x(1,1);
        CPPUNIT_ASSERT(x[0][0] == 0);
		int& r = x[0][0];
		r = 1;
		CPPUNIT_ASSERT(x[0][0] == 1);

		const Matrix<int> y (1,1);
		CPPUNIT_ASSERT(y[0][0] == 0);
		try{
			const_cast<int&>(y[0][0])++;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
	}

	void test_index_edge () {
		Matrix<int> x(100,100,100);
		CPPUNIT_ASSERT(x[0][0] == 100);
		CPPUNIT_ASSERT(x[99][99] == 100);
		x[0][0]++;
		CPPUNIT_ASSERT(x[0][0] == 101);
	}

    // -----------
    // test_equals
    // -----------

    void test_equals_empty () {
        Matrix<int> x;
        Matrix<int> y;
        CPPUNIT_ASSERT(x.eq(y));
	}

	void test_equals_one () {
        Matrix<int> x(1,1);
        Matrix<int> y(1,1);
		Matrix<int> z(1,1,1);
        CPPUNIT_ASSERT(x.eq(y));
		CPPUNIT_ASSERT(!x.eq(z));
	}

	void test_equals_multiple () {
        Matrix<int> x(5,5,5);
        Matrix<int> y(5,5,5);
		Matrix<int> z(4,5,5);
		Matrix<int> b(5,4,5);
        CPPUNIT_ASSERT(x.eq(y));
		CPPUNIT_ASSERT(!x.eq(z));
		CPPUNIT_ASSERT(!x.eq(b));
		y[0][0] = 1;
		CPPUNIT_ASSERT(!x.eq(y));
	}

    // -----------
    // test_equal_equal
    // -----------

    void test_equal_equal_errors () {
        Matrix<int> x;
        Matrix<int> y;
		Matrix<int> w(1,1);
		Matrix<int> z(1,2);
		try{
			x == y;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			w == z;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
	}


	void test_equal_equal_ones () {
        Matrix<int> x(1,1);
        Matrix<int> y(1,1);
		Matrix<int> w(1,1,1);
		Matrix<bool> a(1,1, true);
		Matrix<bool> b;
		b = (x == y);
		CPPUNIT_ASSERT(a.eq(b));
		b = (x == w);
		CPPUNIT_ASSERT(!a.eq(b));
	}

	void test_equal_equal_fives () {
        Matrix<int> x(5,5);
        Matrix<int> y(5,5);
		x[0][0] = 1;
		y[4][4] = 1;
		Matrix<bool> a(5,5, true);
		a[0][0] = false;
		a[4][4] = false;
		Matrix<bool> b;
		b = (x == y);
		CPPUNIT_ASSERT(a.eq(b));
	}

	// -----------
    // test_not_equal
    // -----------

    void test_not_equal_errors () {
        Matrix<int> x;
        Matrix<int> y;
		Matrix<int> w(1,1);
		Matrix<int> z(1,2);
		try{
			x != y;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			w != z;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
	}


	void test_not_equal_ones () {
        Matrix<int> x(1,1);
        Matrix<int> y(1,1);
		Matrix<int> w(1,1,1);
		Matrix<bool> a(1,1, false);
		Matrix<bool> b;
		b = (x != y);
		CPPUNIT_ASSERT(a.eq(b));
		b = (x != w);
		CPPUNIT_ASSERT(!a.eq(b));
	}

	void test_not_equal_fives () {
        Matrix<int> x(5,5);
        Matrix<int> y(5,5);
		x[0][0] = 1;
		y[4][4] = 1;
		Matrix<bool> a(5,5, false);
		a[0][0] = true;
		a[4][4] = true;
		Matrix<bool> b;
		b = (x != y);
		CPPUNIT_ASSERT(a.eq(b));
	}

	
    // --------------
    // test_less_than_and_ltoe
    // --------------

    void test_less_than_errors () {
        Matrix<int> x;
        Matrix<int> y;
		Matrix<int> w(1,1);
		Matrix<int> z(1,2);
		try{
			x < y;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
		try{
			x <= y;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}


		try{
			w < z;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
		try{
			w <= z;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		};
	}

	void test_less_than_ones () {
        Matrix<int> x(1,1);
        Matrix<int> y(1,1);
		Matrix<int> w(1,1,1);
		Matrix<bool> a(1,1,true);
		Matrix<bool> b(1,1,false);
		Matrix<bool> c;
		c = (x < y);
		CPPUNIT_ASSERT(c.eq(b));
		c = (x <= y);
		CPPUNIT_ASSERT(c.eq(a));		
		c = (x < w);
		CPPUNIT_ASSERT(c.eq(a));
		c = (x <= w);
		CPPUNIT_ASSERT(c.eq(a));
	}

	void test_less_than_fives () {
        Matrix<int> x(5,5);
        Matrix<int> y(5,5);
		x[0][0] = 1;
		y[4][4] = 1;
		Matrix<bool> a(5,5,false);
		a[4][4] = true;
		Matrix<bool> b(5,5,true);
		b[0][0] = false;
		Matrix<bool> c;
		c = (x < y);
		CPPUNIT_ASSERT(c.eq(a));
		c = (x <= y);
		CPPUNIT_ASSERT(c.eq(b));
	}

	// --------------
    // test_greater_than_and_gtoe
    // --------------

    void test_greater_than_errors () {
        Matrix<int> x;
        Matrix<int> y;
		Matrix<int> w(1,1);
		Matrix<int> z(1,2);
		try{
			x > y;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
		try{
			x >= y;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}


		try{
			w > z;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
		try{
			w >= z;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		};
	}

	void test_greater_than_ones () {
        Matrix<int> x(1,1);
        Matrix<int> y(1,1);
		Matrix<int> w(1,1,1);
		Matrix<bool> a(1,1,true);
		Matrix<bool> b(1,1,false);
		Matrix<bool> c;
		c = (x > y);
		CPPUNIT_ASSERT(c.eq(b));
		c = (x >= y);
		CPPUNIT_ASSERT(c.eq(a));		
		c = (x > w);
		CPPUNIT_ASSERT(c.eq(b));
		c = (x >= w);
		CPPUNIT_ASSERT(c.eq(b));
	}

	void test_greater_than_fives () {
        Matrix<int> x(5,5);
        Matrix<int> y(5,5);
		x[0][0] = 1;
		y[4][4] = 1;
		Matrix<bool> a(5,5,false);
		a[0][0] = true;
		Matrix<bool> b(5,5,true);
		b[4][4] = false;
		Matrix<bool> c;
		c = (x > y);
		CPPUNIT_ASSERT(c.eq(a));
		c = (x >= y);
		CPPUNIT_ASSERT(c.eq(b));
	}

    // ---------
    // test_plus_and_+=
    // ---------

    void test_plus_defaults () {
        Matrix<int> x;
        Matrix<int> y;
        x + 0;
        CPPUNIT_ASSERT(x.eq(y));
		x += 0;
        CPPUNIT_ASSERT(x.eq(y));
		try{
			x + y;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		};
		try{
			x += y;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		};
    }

	void test_plus_ones () {
        Matrix<int> x(1,1);
        Matrix<int> y(1,1,1);
		Matrix<int> z;
		CPPUNIT_ASSERT(!x.eq(y));
		x + y;
		CPPUNIT_ASSERT(!x.eq(y));
		z = x + 1;
        CPPUNIT_ASSERT(z.eq(y));
		z = x + y;
        CPPUNIT_ASSERT(z.eq(y));
		x += y;
        CPPUNIT_ASSERT(x.eq(y));
    }

	void test_plus_fives () {
        Matrix<int> x(5,5);
        Matrix<int> y(5,5,5);
		Matrix<int> z(5,5,10);
		Matrix<int> a;
		CPPUNIT_ASSERT(!x.eq(y));
		a = x + 5;
        CPPUNIT_ASSERT(a.eq(y));
		x += y;
        CPPUNIT_ASSERT(x.eq(y));
		a = (x += y);
        CPPUNIT_ASSERT(x.eq(z));
		CPPUNIT_ASSERT(a.eq(z));
    }

    // ----------
    // test_minus_and-=
    // ----------

    void test_minus_defaults () {
        Matrix<int> x;
        Matrix<int> y;
        x - 0;
        CPPUNIT_ASSERT(x.eq(y));
		x -= 0;
        CPPUNIT_ASSERT(x.eq(y));
		try{
			x - y;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		};
		try{
			x -= y;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		};
    }

	void test_minus_ones () {
        Matrix<int> x(1,1,2);
        Matrix<int> y(1,1,1);
		Matrix<int> z;
		CPPUNIT_ASSERT(!x.eq(y));
		x - y;
		CPPUNIT_ASSERT(!x.eq(y));
		z = x - 1;
        CPPUNIT_ASSERT(z.eq(y));
		z = x - y;
        CPPUNIT_ASSERT(z.eq(y));
		x -= y;
        CPPUNIT_ASSERT(x.eq(y));
    }

	void test_minus_fives () {
        Matrix<int> x(5,5,10);
        Matrix<int> y(5,5,5);
		Matrix<int> z(5,5);
		Matrix<int> a;
		CPPUNIT_ASSERT(!x.eq(y));
		a = x - 5;
        CPPUNIT_ASSERT(a.eq(y));
		x -= y;
        CPPUNIT_ASSERT(x.eq(y));
		a = (x -= y);
        CPPUNIT_ASSERT(x.eq(z));
		CPPUNIT_ASSERT(a.eq(z));
    }


    // ---------------
    // test_multiplies_and*=
    // ---------------

    void test_multiplies_defaults () {
        Matrix<int> x;
        Matrix<int> y;
        x * 0;
        CPPUNIT_ASSERT(x.eq(y));
		x *= 0;
        CPPUNIT_ASSERT(x.eq(y));
		try{
			x * y;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		};
		try{
			x *= y;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		};
    }

	void test_multiplies_ones () {
        Matrix<int> x(1,1,1);
        Matrix<int> y(1,1,2);
		Matrix<int> z;
		CPPUNIT_ASSERT(!x.eq(y));
		x * y;
		CPPUNIT_ASSERT(!x.eq(y));
		z = x * 2;
        CPPUNIT_ASSERT(z.eq(y));
		z = x * y;
        CPPUNIT_ASSERT(z.eq(y));
		x *= y;
        CPPUNIT_ASSERT(x.eq(y));
    }

	void test_multiplies_sizes () {
        Matrix<int> x(1,3,2);
        Matrix<int> y(3,2,5);
		Matrix<int> z(1,2,30);
		Matrix<int> a;
		a = x * y;	
        CPPUNIT_ASSERT(a.eq(z));
		try{
			y * x;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			x * z;
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

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
        CPPUNIT_ASSERT(b == e);
	}

	void test_iterator_one () {
        Matrix<int> x(1,10);	// iterator goes through row size
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b != e);
		++b;
		CPPUNIT_ASSERT(b == e);
	}

	void test_iterator_five () {
        Matrix<int> x(5,10);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b != e);
		++b; ++b; ++b; ++b; ++b;
		CPPUNIT_ASSERT(b == e);
	}

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);
	}
   
	void test_const_iterator_one () {
        const Matrix<int> x(1,10);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b != e);
		++b;
		CPPUNIT_ASSERT(b == e);
	}

	void test_const_iterator_five () {
        Matrix<int> x(5,10);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b != e);
		++b; ++b; ++b; ++b; ++b;
		CPPUNIT_ASSERT(b == e);
	}
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor);
	CPPUNIT_TEST(test_constructor_defaults);	
	CPPUNIT_TEST(test_constructor_types);	
    CPPUNIT_TEST(test_index);
	CPPUNIT_TEST(test_index_reference);
	CPPUNIT_TEST(test_index_edge);
    CPPUNIT_TEST(test_equals_empty);
    CPPUNIT_TEST(test_equals_one);
    CPPUNIT_TEST(test_equals_multiple);
    CPPUNIT_TEST(test_equal_equal_errors);
    CPPUNIT_TEST(test_equal_equal_ones);
    CPPUNIT_TEST(test_equal_equal_fives);
    CPPUNIT_TEST(test_not_equal_errors);
    CPPUNIT_TEST(test_not_equal_ones);
    CPPUNIT_TEST(test_not_equal_fives);
	CPPUNIT_TEST(test_less_than_errors);
	CPPUNIT_TEST(test_less_than_ones);
	CPPUNIT_TEST(test_less_than_fives);
	CPPUNIT_TEST(test_greater_than_errors);
	CPPUNIT_TEST(test_greater_than_ones);
	CPPUNIT_TEST(test_greater_than_fives);
    CPPUNIT_TEST(test_plus_defaults);
	CPPUNIT_TEST(test_plus_ones);
	CPPUNIT_TEST(test_plus_fives);
    CPPUNIT_TEST(test_minus_defaults);
	CPPUNIT_TEST(test_minus_ones);
	CPPUNIT_TEST(test_minus_fives);
    CPPUNIT_TEST(test_multiplies_defaults);
    CPPUNIT_TEST(test_multiplies_ones);
    CPPUNIT_TEST(test_multiplies_sizes);
    CPPUNIT_TEST(test_iterator);
    CPPUNIT_TEST(test_iterator_one);
    CPPUNIT_TEST(test_iterator_five);
    CPPUNIT_TEST(test_const_iterator);
    CPPUNIT_TEST(test_const_iterator_one);
    CPPUNIT_TEST(test_const_iterator_five);
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
