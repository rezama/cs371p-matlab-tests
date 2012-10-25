//Stephen Cook
//stc493

/**
*@file
* The unit tests for testing functions of the Matrix class.
*/



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

#define private public
#include "Matrix.h"

#include <stdexcept>


// ----------
// TestMatrix
// ----------

using namespace std;

struct TestMatrix : CppUnit::TestFixture {
    // ----------------
    // test_constructor
    // ----------------

    void test_constructor () {
		using namespace std;
		cout << endl << "test_constructor: " << endl;
        Matrix<int> x;
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(2, 3, 4);
		
        CPPUNIT_ASSERT(x.size() == 0);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(z.size() == 2);
        CPPUNIT_ASSERT(t.size() == 2);
	}
    void test_constructor2 () {
		using namespace std;
		cout << endl << "test_constructor2: " << endl;
        Matrix<int> x;
        Matrix<int> t(0);
        Matrix<int> t2(0,0);
        Matrix<int> t3(0,0,0);

        CPPUNIT_ASSERT(x.size() == 0);
        CPPUNIT_ASSERT(t.size() == 0);
        CPPUNIT_ASSERT(t2.size() == 0);
        CPPUNIT_ASSERT(t3.size() == 0);
	}
    void test_constructor3 () {
		using namespace std;
		cout << endl << "test_constructor3: " << endl;
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<double> t(20, 4, 4.0);

        CPPUNIT_ASSERT(y.size() == z.size());
        CPPUNIT_ASSERT(t.size() == 20);
	}
    
	void test_constructor4 () {
		using namespace std;
		cout << endl << "test_constructor4: " << endl;
        Matrix<bool> y(2,2);
        Matrix<bool> y2(2,2, true);
        Matrix<char> z(5, 3);
		double d = double(5.3);
        Matrix<double> t(20, 4, d);

        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(z.size() == 5);
        CPPUNIT_ASSERT(t.size() == 20);
	}


    // ----------
    // test_index
    // ----------

    void test_index () {
		using namespace std;
		cout << endl << "test_index: " << endl;
        const Matrix<int> x(1,1);
        CPPUNIT_ASSERT(x[0][0] == int());
	}
    

    void test_index2 () {
		using namespace std;
		cout << endl << "test_index2: " << endl;
        const Matrix<int> x(2,2);
        CPPUNIT_ASSERT(x[0][0] == x[0][0]);
        CPPUNIT_ASSERT(x[0][1] == double());
        CPPUNIT_ASSERT(x[1][0] == double());
        CPPUNIT_ASSERT(x[0][0] == double());
        CPPUNIT_ASSERT(x[1][1] == double());
	}

	void test_index3 () {
		using namespace std;
		cout << endl << "test_index3: " << endl;
        Matrix<double> x(2,2);
        CPPUNIT_ASSERT(x[0][0] == double());

		x[0][0] = 4.2;
        CPPUNIT_ASSERT(x[0][0] = 4.2);
	}

	void test_index4 () {
		using namespace std;
		cout << endl << "test_index4: " << endl;
        const Matrix<double> x(2,2, 6.66);
        CPPUNIT_ASSERT(x[0][0] == 6.66);
	}

	//------------
	// same_dim
	//------------

	void test_same_dim () {
		using namespace std;
		cout << endl << "test_same_dim: " << endl;
        const Matrix<double> x(2,2);
        const Matrix<double> y(2,2);
        CPPUNIT_ASSERT(x.same_dim(y) == true);
	}

	void test_same_dim2 () {
		using namespace std;
		cout << endl << "test_same_dim2: " << endl;
        const Matrix<double> x(2,2);
        const Matrix<double> y(2,3);
        CPPUNIT_ASSERT(x.same_dim(y) == false);
	}

	void test_same_dim3 () {
		using namespace std;
		cout << endl << "test_same_dim3: " << endl;
        const Matrix<double> x(0,2);
        const Matrix<double> y(0,3);
        CPPUNIT_ASSERT(x.same_dim(y) == true);
	}

    // -----------
    // test_not_equals
    // -----------

    void test_not_equals () {
		using namespace std;
		cout << endl << "test_not_equals: " << endl;
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x != y);
		
        CPPUNIT_ASSERT(z.eq(t));
	}

    void test_not_equals2 () {
		using namespace std;
		cout << endl << "test_not_equals2: " << endl;
        Matrix<int>  x(2,2,4);
        Matrix<int>  y(2,2,4);
        Matrix<bool> z(2,2,4);
        Matrix<bool> t(2,2);
		t[0][0] = false;
		t[0][1] = false;
		t[1][0] = false;
		t[1][1] = false;
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));
		Matrix<int> w(9,9,0);
		try{
			z= x!=w;
        	CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
        	CPPUNIT_ASSERT(x.eq(x));
		}
	}

    void test_not_equals3 () {
		using namespace std;
		cout << endl << "test_not_equals3: " << endl;
        Matrix<int>  x(2,2,4);
		x[1][1] = 999;
        Matrix<int>  y(2,2,4);
        Matrix<bool> z(2,2,4);
        Matrix<bool> t(2,2);
		t[0][0] = false;
		t[0][1] = false;
		t[1][0] = false;
		t[1][1] = true;
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));
	}

    // -----------
    // test_equals
    // -----------

    void test_equals () {
		using namespace std;
		cout << endl << "test_equals: " << endl;
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
		
        CPPUNIT_ASSERT(z.eq(t));
	}

    void test_equals2 () {
		using namespace std;
		cout << endl << "test_equals2: " << endl;
        Matrix<int>  x(2,2,4);
        Matrix<int>  y(2,2,4);
        Matrix<bool> z(2,2,4);
        Matrix<bool> t(2,2);
		t[0][0] = true;
		t[0][1] = true;
		t[1][0] = true;
		t[1][1] = true;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
		Matrix<int> w(9,9,0);
		try{
			z= x==w;
        	CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
        	CPPUNIT_ASSERT(x.eq(x));
		}
	}

    void test_equals3 () {
		using namespace std;
		cout << endl << "test_equals3: " << endl;
        Matrix<int>  x(2,2,4);
		x[1][1] = 999;
        Matrix<int>  y(2,2,4);
        Matrix<bool> z(2,2,4);
        Matrix<bool> t(2,2);
		t[0][0] = true;
		t[0][1] = true;
		t[1][0] = true;
		t[1][1] = false;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
	}

    // --------------
    // test_less_than
    // --------------

    void test_less_than () {
		using namespace std;
		cout << endl << "test_less_than: " << endl;
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
	}

    void test_less_than2 () {
		using namespace std;
		cout << endl << "test_less_than2: " << endl;
        Matrix<int>  x(1,1);
        Matrix<int>  y(1,1,999);
        Matrix<bool> z(1,1);
        Matrix<bool> t(1,1, true);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
		Matrix<int> w(9,9,0);
		try{
			z= x<w;
        	CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
        	CPPUNIT_ASSERT(x.eq(x));
		}
	}

    void test_less_than3 () {
		using namespace std;
		cout << endl << "test_less_than3: " << endl;
        Matrix<int>  x(1,2);
		x[0][0] = 100;
		x[0][1] = 0;
        Matrix<int>  y(1,2);
		y[0][0] = 0;
		y[0][1] = 999;
        Matrix<bool> z(1,2);
        Matrix<bool> t(1,2);
		t[0][0] = false;
		t[0][1] = true;
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
	}

    // --------------
    // test_less_than_eq
    // --------------

    void test_less_than_eq () {
		using namespace std;
		cout << endl << "test_less_than_eq: " << endl;
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));
	}

    void test_less_than_eq2 () {
		using namespace std;
		cout << endl << "test_less_than_eq2: " << endl;
        Matrix<int>  x(1,1);
        Matrix<int>  y(1,1,999);
        Matrix<bool> z(1,1);
        Matrix<bool> t(1,1, true);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));
		Matrix<int> w(9,9,0);
		try{
			z= x<=w;
        	CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
        	CPPUNIT_ASSERT(x.eq(x));
		}
	}

    void test_less_than_eq3 () {
		using namespace std;
		cout << endl << "test_less_than_eq3: " << endl;
        Matrix<int>  x(1,2);
		x[0][0] = 100;
		x[0][1] = 0;
        Matrix<int>  y(1,2);
		y[0][0] = 1000;
		y[0][1] = 999;
        Matrix<bool> z(1,2);
        Matrix<bool> t(1,2);
		t[0][0] = true;
		t[0][1] = true;
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));
	}

    // --------------
    // test_greater_than
    // --------------

    void test_greater_than () {
		using namespace std;
		cout << endl << "test_greater_than: " << endl;
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));
	}

    void test_greater_than2 () {
		using namespace std;
		cout << endl << "test_greater_than2: " << endl;
        Matrix<int>  x(1,1);
        Matrix<int>  y(1,1,999);
        Matrix<bool> z(1,1);
        Matrix<bool> t(1,1, false);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));
		Matrix<int> w(9,9,0);
		try{
			z= x<w;
        	CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
        	CPPUNIT_ASSERT(x.eq(x));
		}
	}

    void test_greater_than3 () {
		using namespace std;
		cout << endl << "test_greater_than3: " << endl;
        Matrix<int>  x(1,2);
		x[0][0] = 100;
		x[0][1] = 0;
        Matrix<int>  y(1,2);
		y[0][0] = 0;
		y[0][1] = 999;
        Matrix<bool> z(1,2);
        Matrix<bool> t(1,2);
		t[0][0] = true;
		t[0][1] = false;
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));
	}

    // --------------
    // test_greater_than_eq
    // --------------

    void test_greater_than_eq () {
		using namespace std;
		cout << endl << "test_greater_than_eq: " << endl;
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));
	}

    void test_greater_than_eq2 () {
		using namespace std;
		cout << endl << "test_greater_than_eq2: " << endl;
        Matrix<int>  x(1,1);
        Matrix<int>  y(1,1,999);
        Matrix<bool> z(1,1);
        Matrix<bool> t(1,1, false);
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));
		Matrix<int> w(9,9,0);
		try{
			z= x<=w;
        	CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
        	CPPUNIT_ASSERT(x.eq(x));
		}
	}

    void test_greater_than_eq3 () {
		using namespace std;
		cout << endl << "test_greater_than_eq3: " << endl;
        Matrix<int>  x(1,2);
		x[0][0] = 100;
		x[0][1] = 0;
        Matrix<int>  y(1,2);
		y[0][0] = 100;
		y[0][1] = 999;
        Matrix<bool> z(1,2);
        Matrix<bool> t(1,2);
		t[0][0] = true;
		t[0][1] = false;
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));
	}

    // ---------
    // test_plus
    // ---------

    void test_plus () {
		using namespace std;
		cout << endl << "test_plus: " << endl;
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x += 0;
        CPPUNIT_ASSERT(x.eq(y));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
	}
    void test_plus2 () {
		using namespace std;
		cout << endl << "test_plus2: " << endl;
        Matrix<int> x(1,1,0);
        Matrix<int> y(1,1,1);
        Matrix<int> z(1,1,2);
        x += 1;
        CPPUNIT_ASSERT(x.eq(y));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
		Matrix<int> w(9,9,0);
		try{
			x+=w;
        	CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
        	CPPUNIT_ASSERT(x.eq(x));
		}
	}
    void test_plus3 () {
		using namespace std;
		cout << endl << "test_plus3: " << endl;
        Matrix<int> x(2,2,1);
        Matrix<int> x2(2,2,1);
        Matrix<int> y(2,2,5);
        Matrix<int> z(2,2,10);
        x += 1;
        CPPUNIT_ASSERT(!x.eq(x2));
        y += y;
        CPPUNIT_ASSERT(y.eq(z));
	}

    // ----------
    // test_minus
    // ----------

    void test_minus () {
		using namespace std;
		cout << endl << "test_minus: " << endl;
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= 0;
        CPPUNIT_ASSERT(x.eq(y));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
	}
    void test_minus2 () {
		using namespace std;
		cout << endl << "test_minus2: " << endl;
        Matrix<int> x(1,1,2);
        Matrix<int> y(1,1,1);
        Matrix<int> y2(1,1,0);
        Matrix<int> z(1,1,2);
        y -= 1;
        CPPUNIT_ASSERT(y2.eq(y));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));

		Matrix<int> w(9,9,0);
		try{
			x-=w;
        	CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
        	CPPUNIT_ASSERT(x.eq(x));
		}

	}
    void test_minus3 () {
		using namespace std;
		cout << endl << "test_minus3: " << endl;
        Matrix<int> x(2,2,1);
        Matrix<int> x2(2,2,1);
        Matrix<int> y(2,2,5);
        Matrix<int> z(2,2,0);
        x -= 1;
        CPPUNIT_ASSERT(!x.eq(x2));
        y -= y;
        CPPUNIT_ASSERT(y.eq(z));
	}

    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies () {
		using namespace std;
		cout << endl << "test_multiplies: " << endl;
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
    	x *= 0;
	    CPPUNIT_ASSERT(x.eq(x));

		try{
    	    x *= y;
	        CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
	        CPPUNIT_ASSERT(x.eq(x));
		}
	}
    void test_multiplies2 () {
		using namespace std;
		cout << endl << "test_multiplies2: " << endl;
        Matrix<int> x(1,1,2);
        Matrix<int> y(1,1,1);
        Matrix<int> y2(1,1,0);
        Matrix<int> z(1,1,0);
        y *= 1;
        CPPUNIT_ASSERT(y.eq(y));
        x *= y2;
        CPPUNIT_ASSERT(x.eq(z));
	}
    void test_multiplies3 () {
		using namespace std;
		cout << endl << "test_multiplies3: " << endl;
        Matrix<int> x(2,2,2);
        Matrix<int> x2(2,2,4);
        Matrix<int> y(1,2,5);
		Matrix<int> y2(2,3,2);	
        Matrix<int> z(1,3, 20);

		try{
			x*=y;
        	CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
     	   CPPUNIT_ASSERT(x.eq(x));
		}

        x *= 2;
        CPPUNIT_ASSERT(x.eq(x2));
        y *= y2;
        CPPUNIT_ASSERT(y.eq(z));
	}
    // -------------
    // test_iterator
    // -------------

    void test_iterator () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    void test_iterator2 () {
        Matrix<int> x(1,1,2);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b + 1 == e);}

    void test_iterator3 () {
        Matrix<int> x(2,2,99);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b+2 == e);}

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    void test_const_iterator2 () {
        const Matrix<int> x(1,1);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b+1 == e);}

    void test_const_iterator3 () {
        const Matrix<int> x(2,2);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b+2 == e);}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_constructor2);
    CPPUNIT_TEST(test_constructor3);
    CPPUNIT_TEST(test_constructor4);
    CPPUNIT_TEST(test_index);
    CPPUNIT_TEST(test_index2);
    CPPUNIT_TEST(test_index3);
    CPPUNIT_TEST(test_index4);
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_equals2);
    CPPUNIT_TEST(test_equals3);
    CPPUNIT_TEST(test_not_equals);
    CPPUNIT_TEST(test_not_equals2);
    CPPUNIT_TEST(test_not_equals3);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less_than2);
    CPPUNIT_TEST(test_less_than3);
    CPPUNIT_TEST(test_less_than_eq);
    CPPUNIT_TEST(test_less_than_eq2);
    CPPUNIT_TEST(test_less_than_eq3);
    CPPUNIT_TEST(test_greater_than);
    CPPUNIT_TEST(test_greater_than2);
    CPPUNIT_TEST(test_greater_than3);
    CPPUNIT_TEST(test_greater_than_eq);
    CPPUNIT_TEST(test_greater_than_eq2);
    CPPUNIT_TEST(test_greater_than_eq3);
  
	  
	CPPUNIT_TEST(test_same_dim);
	CPPUNIT_TEST(test_same_dim2);
	CPPUNIT_TEST(test_same_dim3);
	CPPUNIT_TEST(test_plus);
	CPPUNIT_TEST(test_plus2);
	CPPUNIT_TEST(test_plus3);
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_minus2);
    CPPUNIT_TEST(test_minus3);
    CPPUNIT_TEST(test_multiplies);
    CPPUNIT_TEST(test_multiplies2);
    CPPUNIT_TEST(test_multiplies3);
    CPPUNIT_TEST(test_iterator);
    CPPUNIT_TEST(test_iterator2);
    CPPUNIT_TEST(test_iterator3);
    CPPUNIT_TEST(test_const_iterator);
    CPPUNIT_TEST(test_const_iterator2);
    CPPUNIT_TEST(test_const_iterator3);
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
