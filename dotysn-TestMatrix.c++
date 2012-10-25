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
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(z.size() == 2);
        CPPUNIT_ASSERT(t.size() == 2);        
    }
    
    void test_constructor2 () {
    	Matrix<int> x(0, 0);
    	CPPUNIT_ASSERT(x.size() == 0);    	    	
    }
    
    void test_constructor3() {
    	Matrix<double> dm (5, 10, 3.14159);
    	CPPUNIT_ASSERT(dm.size() == 5);
    	CPPUNIT_ASSERT(dm.width() == 10); 
    	for(size_t i = 0; i < dm.size(); i++)
    		for(size_t j = 0; j < dm.width(); j++)
    			CPPUNIT_ASSERT(dm[i][j] == 3.14159);   	   
    }
    
    void test_constructor4 () {
    	Matrix<int> x(0, 5);
    	CPPUNIT_ASSERT(x.size() == 0); 
    	CPPUNIT_ASSERT(x.width() == 0);   	    	
    }
    
    // ----------
    // test_size
    // ----------
    
    void test_size () {
        const Matrix<int> x(1, 1, 0);
        CPPUNIT_ASSERT(x.size() == 1);
    }
    
    void test_size2 () {
        const Matrix<int> x(5,2, 0);
        CPPUNIT_ASSERT(x.size() == 5);
    }
    
    void test_size3 () {
        const Matrix<int> x(100, 100, 0);
        CPPUNIT_ASSERT(x.size() == 100);
    }
    
    // ----------
    // test_width
    // ----------
    
    void test_width () {
        const Matrix<int> x(1, 1, 0);
        CPPUNIT_ASSERT(x.width() == 1);
    }
    
    void test_width2 () {
        const Matrix<int> x(5,2, 0);
        CPPUNIT_ASSERT(x.width() == 2);
    }
    
    void test_width3 () {
        const Matrix<int> x(100, 100, 0);
        CPPUNIT_ASSERT(x.width() == 100);
    }
   

    // ----------
    // test_index_const
    // ----------

    void test_index_const () {
        const Matrix<int> x(1, 1, 0);
        CPPUNIT_ASSERT(x[0][0] == 0);
    }
    
    void test_index_const2 () {
        const Matrix<int> x;
        int y;
        try 
        {
        	y = x[0][0]; // should fail since matrix is of size zero
        }
        catch (std::exception& e)
        {
        	CPPUNIT_ASSERT(true);
        }
    }
    
    void test_index_const3 () {
    	const Matrix<double> x(5, 2, 4.5);
    	CPPUNIT_ASSERT(x[2][1] == 4.5);
    }
        
    // ----------
    // test_index
    // ----------
    
    void test_index2 () {
    	Matrix<int> x(2, 3, 8);    	
    	int test = x[0][0];    	
    	CPPUNIT_ASSERT(test == 8);    
    }
    
    void test_index3 () {
    	Matrix<int> x(2, 3, 8);    	
    	int test = x[1][2];    	
    	CPPUNIT_ASSERT(test == 8);    
    }
    
    void test_index4 () {
    	Matrix<int> x(2, 3, 8);    	
    	x[1][2] = 10;    	
    	CPPUNIT_ASSERT(x[1][2] == 10);    
    }
    
    void test_index5 () {
    	std::vector<int> temp(3, -3);
    	Matrix<int> x(2, 3, 8);    	
    	x[1] =  temp;    	
    	CPPUNIT_ASSERT(x[1][0] == -3);
    	CPPUNIT_ASSERT(x[1][1] == -3);
    	CPPUNIT_ASSERT(x[1][2] == -3);    	    
    }

    // -----------
    // test_equals
    // -----------

    void test_equals () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_equals2() {
    	Matrix<int> x(2, 2, 4);
    	Matrix<int> y(2, 2, 4);
    	Matrix<bool> z;
    	try {
    		z = (x == y);
    	}
    	catch (std::exception& e)
    	{}
    	Matrix<bool> t(2, 2, true);
    	CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_equals3() {
    	Matrix<int> x(25, 15, 4);
    	Matrix<int> y(25, 15, 3);
    	Matrix<bool> z;
    	try {
    		z = (x == y);
    	}
    	catch (std::exception& e)
    	{}
    	Matrix<bool> t(25, 15, true);
    	CPPUNIT_ASSERT(!z.eq(t));
    }
    
    void test_equals4() {
    	Matrix<int> x(2, 2);
    	Matrix<int> y(2, 2);
    	Matrix<bool> t(2, 2, true);
    	
    	x[0][0] = 1;
    	x[0][1] = 2;
    	x[1][0] = 3;
    	x[1][1] = 4;
    	y[0][0] = 1;
    	y[0][1] = 4;
    	y[1][0] = 3;
    	y[1][1] = 5;
    	
    	//initialize bool Matrix
    	t[0][1] = false;
    	t[1][1] = false;
    	
    	Matrix<bool> z;
    	try {
    		z = (x == y);
    	}
    	catch (std::exception& e)
    	{}
    	
    	CPPUNIT_ASSERT(z.eq(t));
    }

    // --------------
    // test_less_than
    // --------------

    void test_less_than () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    
    void test_less() {
    	Matrix<int> x(2, 2, 4);
    	Matrix<int> y(2, 2, 4);
    	Matrix<bool> z;
    	try {
    		z = (x < y);
    	}
    	catch (std::exception& e)
    	{}
    	Matrix<bool> t(2, 2, false);
    	CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_less2() {
    	Matrix<int> x(25, 15, 3);
    	Matrix<int> y(25, 15, 4);
    	Matrix<bool> z;
    	try {
    		z = (x < y);
    	}
    	catch (std::exception& e)
    	{}
    	Matrix<bool> t(25, 15, true);
    	CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_less3() {
    	Matrix<int> x(2, 2);
    	Matrix<int> y(2, 2);
    	Matrix<bool> t(2, 2, true);
    	
    	x[0][0] = 1;
    	x[0][1] = 2;
    	x[1][0] = 3;
    	x[1][1] = 4;
    	y[0][0] = 1;
    	y[0][1] = 4;
    	y[1][0] = 3;
    	y[1][1] = 5;
    	
    	//initialize bool Matrix
    	t[0][0] = false;
    	t[1][0] = false;
    	
    	Matrix<bool> z;
    	try {
    		z = (x < y);
    	}
    	catch (std::exception& e)
    	{}
    	
    	CPPUNIT_ASSERT(z.eq(t));
    }
    
    
    // ---------
    // less_than_equal
    // ---------
    
    void test_less_E() {
    	Matrix<int> x(2, 2, 4);
    	Matrix<int> y(2, 2, 4);
    	Matrix<bool> z;
    	try {
    		z = (x <= y);
    	}
    	catch (std::exception& e)
    	{}
    	Matrix<bool> t(2, 2, true);
    	CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_less_E2() {
    	Matrix<int> x(25, 15, 3);
    	Matrix<int> y(25, 15, 4);
    	Matrix<bool> z;
    	try {
    		z = (x <= y);
    	}
    	catch (std::exception& e)
    	{}
    	Matrix<bool> t(25, 15, true);
    	CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_less_E3() {
    	Matrix<int> x(2, 2);
    	Matrix<int> y(2, 2);
    	Matrix<bool> t(2, 2, true);
    	
    	x[0][0] = 1;
    	x[0][1] = 2;
    	x[1][0] = 3;
    	x[1][1] = 6;
    	y[0][0] = 1;
    	y[0][1] = 4;
    	y[1][0] = 3;
    	y[1][1] = 5;
    		
    	Matrix<bool> z;
    	t[1][1] = false;
    	try {
    		z = (x <= y);
    	}
    	catch (std::exception& e)
    	{}    	
    	CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_less_E4() {
    	Matrix<int> x(20, 15, 3);
    	Matrix<int> y(25, 15, 4);
    	Matrix<bool> z;
    	try {
    		z = (x <= y);
    	}
    	catch (std::exception& e)
    	{
    		CPPUNIT_ASSERT(true);
    	}    	
    }

    // ---------
    // greater_than
    // ---------
    
    void test_greater() {
    	Matrix<int> x(10, 5, 4);
    	Matrix<int> y(10, 5, 4);
    	Matrix<bool> z;
    	try {
    		z = (x > y);
    	}
    	catch (std::exception& e)
    	{}
    	Matrix<bool> t(10, 5, false);
    	CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_greater2() {
    	Matrix<int> x(25, 15, 3);
    	Matrix<int> y(25, 15, 4);
    	Matrix<bool> z;
    	try {
    		z = (x > y);
    	}
    	catch (std::exception& e)
    	{}
    	Matrix<bool> t(25, 15, false);
    	CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_greater3() {
    	Matrix<int> x(2, 2);
    	Matrix<int> y(2, 2);
    	Matrix<bool> t(2, 2, false);
    	
    	x[0][0] = 1;
    	x[0][1] = 2;
    	x[1][0] = 3;
    	x[1][1] = 4;
    	y[0][0] = 1;
    	y[0][1] = 4;
    	y[1][0] = 3;
    	y[1][1] = 5;

    	Matrix<bool> z;
    	try {
    		z = (x > y);
    	}
    	catch (std::exception& e)
    	{}
    	
    	CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_greater4() {
    	Matrix<int> x(1, 1, 4);
    	Matrix<int> y(1, 1, 3);
    	Matrix<bool> z;
    	try {
    		z = (x > y);
    	}
    	catch (std::exception& e)
    	{}
    	Matrix<bool> t(1, 1, true);
    	CPPUNIT_ASSERT(z.eq(t));
    }

	// ---------
	// greater_than_equal
	// -----------
	
	void test_greater_E() {
    	Matrix<int> x(10, 5, 4);
    	Matrix<int> y(10, 5, 4);
    	Matrix<bool> z;
    	try {
    		z = (x >= y);
    	}
    	catch (std::exception& e)
    	{}
    	Matrix<bool> t(10, 5, true);
    	CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_greater_E2() {
    	Matrix<int> x(25, 15, 3);
    	Matrix<int> y(25, 15, 4);
    	Matrix<bool> z;
    	try {
    		z = (x >= y);
    	}
    	catch (std::exception& e)
    	{}
    	Matrix<bool> t(25, 15, false);
    	CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_greater_E3() {
    	Matrix<int> x(2, 2);
    	Matrix<int> y(2, 2);
    	Matrix<bool> t(2, 2, true);
    	
    	x[0][0] = 3;
    	x[0][1] = 2;
    	x[1][0] = 3;
    	x[1][1] = 4;
    	y[0][0] = 1;
    	y[0][1] = 4;
    	y[1][0] = 3;
    	y[1][1] = 9;

    	Matrix<bool> z;
    	t[0][1] = false;
    	t[1][1] = false;
    	
    	try {
    		z = (x >= y);
    	}
    	catch (std::exception& e)
    	{}    	
    	CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_greater_E4() {
    	Matrix<int> x(1, 1, -4);
    	Matrix<int> y(1, 1, -3);
    	Matrix<bool> z;
    	try {
    		z = (x >= y);
    	}
    	catch (std::exception& e)
    	{}
    	Matrix<bool> t(1, 1, false);
    	CPPUNIT_ASSERT(z.eq(t));
    }

	void test_greater_E5() {
    	Matrix<int> x(1, 5, -4);
    	Matrix<int> y(1, 1, -3);
    	Matrix<bool> z;
    	try {
    		z = (x >= y);
    	}
    	catch (std::exception& e)
    	{
			CPPUNIT_ASSERT(true);    	
    	}    	
    }
    
    // ---------
    // test_plus
    // ---------

    void test_plus () {
        Matrix<int> x(1, 1, -100);
        x = x + 0;
		Matrix<int> z(1 , 1, -100);
        CPPUNIT_ASSERT(x.eq(z));
    }
    
    void test_plus2() {
    	Matrix<double> x(3, 3, 1.5);
    	Matrix<double> y(3, 3);
		y = x + 4.0;
    	Matrix<double> z(3, 3, 5.5);
    	CPPUNIT_ASSERT(y.eq(z));
    }
    
    void test_plus3() {
    	Matrix<int> x(3, 3, 4);
    	Matrix<int> y(3, 3);
		y = x + (-2);
    	Matrix<int> z(3, 3, 2);
    	CPPUNIT_ASSERT(y.eq(z));
    }

	void test_plus4() {
		Matrix<int> x(5, 5, 2);
		Matrix<int> const y(5, 5, 3);
		x = x + y;
		Matrix<int> z(5, 5, 5);
		CPPUNIT_ASSERT(x.eq(z));
	}

	//different sizes can't be added
	void test_plus5() {
		Matrix<int> x(4, 4, 5);
		Matrix<int> y(5, 5, 5);
		try {
			y = y + x;
		}
		catch(std::exception& e) {
			CPPUNIT_ASSERT(true);
		}
	}
	
	void test_plus6() {
		Matrix<int> x(5, 5, 2);
		Matrix<int> const y(5, 5, -3);
		x = x + y;
		Matrix<int> z(5, 5, -1);
		CPPUNIT_ASSERT(x.eq(z));
	}

	// ---------------
	// test_plusEquals
	// ---------------
	
	void test_plusEquals () {
        Matrix<int> x(1, 1, -100);
        x += 5;
		Matrix<int> z(1 , 1, -95);
        CPPUNIT_ASSERT(x.eq(z));
    }
    
    void test_plusEquals1 () {
        Matrix<int> x(1, 1, 0);
        x += 0;
		Matrix<int> z(1 , 1, 0);
        CPPUNIT_ASSERT(x.eq(z));
    }
    
    void test_plusEquals2 () {
        Matrix<int> x(1, 1, 0);
        x += 21;
		Matrix<int> z(1 , 1, 21);
        CPPUNIT_ASSERT(x.eq(z));
    }
    
    void test_plusEquals3 () {
        Matrix<int> x(3, 3, -100);
        Matrix<int> y(3, 3, 100);
        x += y;
		Matrix<int> z(3 , 3, 0);
        CPPUNIT_ASSERT(x.eq(z));
    }
    
    void test_plusEquals4 () {
    	Matrix<int> x(4, 5, 10);
    	Matrix<int> y(4, 5, 5);
    	x += y;
    	Matrix<int> z(4, 5, 15);
    	CPPUNIT_ASSERT(x.eq(z));
    }
    
    void test_plusEquals5 () {
    	Matrix<int> x(4, 5, 10);
    	Matrix<int> y(4, 6, 5);
    	try{
    		x += y;
    	}
    	
    	catch(std::invalid_argument& e)
    	{
    		CPPUNIT_ASSERT(true);
    	}
    }
    
    // ----------
    // test_minus
    // ----------

    void test_minus() {
    	Matrix<double> x(3, 3, 1.5);
    	Matrix<double> y(3, 3);
		y = x - 4.0;
    	Matrix<double> z(3, 3, -2.5);
    	CPPUNIT_ASSERT(y.eq(z));
	}
	
	void test_minus2 () {
    	Matrix<int> x(3, 3, -5);
    	Matrix<int> y;
		y = x - 4.0;
    	Matrix<int> z(3, 3, -9);
    	CPPUNIT_ASSERT(y.eq(z));
	}
	
	void test_minus3 () {
    	Matrix<int> x;
    	Matrix<int> y;
		y = x - 4.0;
    	Matrix<int> z;
    	CPPUNIT_ASSERT(y.eq(z));
	}
    
	void test_minus4 () {
        Matrix<int> x(3, 3, 8);
        Matrix<int> y(3, 3, 5);
        x = x - y;
		Matrix<int> z(3, 3, 3);
        CPPUNIT_ASSERT(x.eq(z));
    }
    
	//different sizes, can't compare
	void test_minus5 () {
        Matrix<int> x(4, 4, 8);
        Matrix<int> y(3, 3, 5);
        try {
			x = x - y;
		}
		catch (std::exception& e)
		{
			CPPUNIT_ASSERT(true);
		}
	}
	
	void test_minus6 () {		
        Matrix<int> x(3, 3, 1000000);
        Matrix<int> y(3, 3, 5);
        Matrix<int> a;
        a = x - y;
		Matrix<int> z(3, 3, 999995);
        CPPUNIT_ASSERT(a.eq(z));
    }
    
    // ----------------
    // test_minusEquals
    // ----------------
    void test_minusEquals() {
    	Matrix<double> x(3, 3, 1.5);
		x -= 4.0;
    	Matrix<double> z(3, 3, -2.5);
    	CPPUNIT_ASSERT(x.eq(z));
	}
	
	void test_minusEquals2 () {
    	Matrix<int> x(3, 3, -5);
		x -= 4.0;
    	Matrix<int> z(3, 3, -9);
    	CPPUNIT_ASSERT(x.eq(z));
	}
	
	void test_minusEquals3 () {
    	Matrix<int> x;
    	x -= 4.0;
    	Matrix<int> z;
    	CPPUNIT_ASSERT(x.eq(z));
	}
    
	void test_minusEquals4 () {
        Matrix<int> x(3, 3, 8);
        Matrix<int> y(3, 3, 5);
        x -= y;
		Matrix<int> z(3, 3, 3);
        CPPUNIT_ASSERT(x.eq(z));
    }
    
	//different sizes, can't compare
	void test_minusEquals5 () {
        Matrix<int> x(4, 4, 8);
        Matrix<int> y(3, 3, 5);
        try {
			x -= y;
		}
		catch (std::invalid_argument& e)
		{
			CPPUNIT_ASSERT(true);
		}
	}
	
	void test_minusEquals6 () {		
        Matrix<int> x(3, 3, 1000000);
        Matrix<int> y(3, 3, 5);
        x -= y;
		Matrix<int> z(3, 3, 999995);
        CPPUNIT_ASSERT(x.eq(z));
    }
    
    
    // ---------------
    // test_multiplies
    // ---------------
    
    void test_multiplies () {
        Matrix<int> x(2, 2, 3);
		Matrix<int> a;
		Matrix<int> z(2, 2, 12);
		a = x * 4;
        
        CPPUNIT_ASSERT(a.eq(z));
	}
	
	void test_multiplies2 () {
        Matrix<int> x(2, 2, 3);
		Matrix<int> a;
		Matrix<int> z(2, 2, 0);
		a = x * 0;
        
        CPPUNIT_ASSERT(a.eq(z));
	}
	
	void test_multiplies3 () {
        Matrix<int> x(2, 2, 5);
		Matrix<int> a;
		Matrix<int> z(2, 2, -5);
		a = x * -1;
        
        CPPUNIT_ASSERT(a.eq(z));
	}

    void test_multiplies4 () {
        Matrix<int> x(2, 2, 3);
		Matrix<int> y(2, 2, 2);
		Matrix<int> a;
		Matrix<int> z(2, 2, 12);
		a = x * y;
        
        CPPUNIT_ASSERT(a.eq(z));
	}

    void test_multiplies5 () {
        Matrix<int> x(2, 3, 3);
		Matrix<int> y(3, 2, 2);
		Matrix<int> z(2, 2, 18);
		x = x * y;
        
        CPPUNIT_ASSERT(x.eq(z));
	}
	
	void test_multiplies6 () {
        Matrix<int> x(2, 3);
        x[0][0] = 1;
        x[0][1] = 3;
        x[0][2] = 5;
        x[1][0] = 2;
        x[1][1] = 4;
        x[1][2] = 7;
		Matrix<int> y(3, 3);
		y[0][0] = -5;
		y[0][1] = 8;
		y[0][2] = 11;
		y[1][0] = 3;
		y[1][1] = 9;
		y[1][2] = 21;
		y[2][0] = 4;
		y[2][1] = 0;
		y[2][2] = 8;
		Matrix<int> z(2, 3);
		z[0][0] = 24;
        z[0][1] = 35;
        z[0][2] = 114;
        z[1][0] = 30;
        z[1][1] = 52;
        z[1][2] = 162;
       	Matrix<int> a;
		a = x * y;
        
        CPPUNIT_ASSERT(a.eq(z));
	}
	
	// -------------------
	// test_multiplyEquals
	// -------------------
   
    void test_multiplyEquals () {
        Matrix<int> x(2, 2, 3);
		Matrix<int> z(2, 2, 12);
		x *= 4;
        
        CPPUNIT_ASSERT(x.eq(z));
	}
	
	void test_multiplyEquals2 () {
        Matrix<int> x(2, 2, 3);
		Matrix<int> z(2, 2, 0);
		x *= 0;
        
        CPPUNIT_ASSERT(x.eq(z));
	}
	
	void test_multiplyEquals3 () {
        Matrix<int> x(2, 2, 5);
		Matrix<int> z(2, 2, -5);
		x *= -1;
        
        CPPUNIT_ASSERT(x.eq(z));
	}

    void test_multiplyEquals4 () {
        Matrix<int> x(2, 2, 3);
		Matrix<int> y(2, 2, 2);
		Matrix<int> z(2, 2, 12);
		x *= y;
        
        CPPUNIT_ASSERT(x.eq(z));
	}

    void test_multiplyEquals5 () {
        Matrix<int> x(2, 3, 3);
		Matrix<int> y(3, 2, 2);
		Matrix<int> z(2, 2, 18);
		x *= y;
        
        CPPUNIT_ASSERT(x.eq(z));
	}
	
	void test_multiplyEquals6 () {
        Matrix<int> x(2, 3);
        x[0][0] = 1;
        x[0][1] = 3;
        x[0][2] = 5;
        x[1][0] = 2;
        x[1][1] = 4;
        x[1][2] = 7;
		Matrix<int> y(3, 3);
		y[0][0] = -5;
		y[0][1] = 8;
		y[0][2] = 11;
		y[1][0] = 3;
		y[1][1] = 9;
		y[1][2] = 21;
		y[2][0] = 4;
		y[2][1] = 0;
		y[2][2] = 8;
		Matrix<int> z(2, 3);
		z[0][0] = 24;
        z[0][1] = 35;
        z[0][2] = 114;
        z[1][0] = 30;
        z[1][1] = 52;
        z[1][2] = 162;
       
		x *= y;
        
        CPPUNIT_ASSERT(x.eq(z));
	}
   
   
   
    /*void test_multiplies3 () {
        Matrix<int> x(4, 3, 3);
		Matrix<int> y(3, 2, 2);
		try {
			x = x * y;
        }
		catch (std::exception& e)
		{
        	CPPUNIT_ASSERT(true);
		}
	}*/

	// ------------
    // test_iterator
    // -------------

    void test_iterator () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}
        
    void test_iterator2 () {
        Matrix<int> x(2, 2, 1);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        b++;
        b++;
        CPPUNIT_ASSERT(b == e);}
        
   	void test_iterator3 () {
        Matrix<int> x(2, 2, 1);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT((*b)[0] == 1);}
       
    void test_iterator4 () {
        Matrix<int> x(2, 2, 1);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        (*b)[0] = 10;
        CPPUNIT_ASSERT(x[0][0] == 10);}

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}
        
    void test_const_iterator2 () {
        const Matrix<int> x(2, 1, 5);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        b++;
        CPPUNIT_ASSERT((*b)[0] == 5);}
        
    void test_const_iterator3 () {
        const Matrix<int> x(5, 1);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        b++;
        b++;
        b++;
        b++;
        b++;
        CPPUNIT_ASSERT(b == e);}

    // -----
    // suite
    // -----
    
    CPPUNIT_TEST_SUITE(TestMatrix);
    
	CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_constructor2);
    CPPUNIT_TEST(test_constructor3);
    CPPUNIT_TEST(test_constructor4);
    CPPUNIT_TEST(test_size);
    CPPUNIT_TEST(test_size2);
    CPPUNIT_TEST(test_size3);
    CPPUNIT_TEST(test_width);
    CPPUNIT_TEST(test_width2);
    CPPUNIT_TEST(test_width3);
    CPPUNIT_TEST(test_index_const);
    CPPUNIT_TEST(test_index_const2);
    CPPUNIT_TEST(test_index_const3);
    CPPUNIT_TEST(test_index2);
    CPPUNIT_TEST(test_index3);
    CPPUNIT_TEST(test_index4);
    CPPUNIT_TEST(test_index5);
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_equals2);
    CPPUNIT_TEST(test_equals3);
    CPPUNIT_TEST(test_equals4);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less);
    CPPUNIT_TEST(test_less2);
    CPPUNIT_TEST(test_less3);
    CPPUNIT_TEST(test_less_E);
    CPPUNIT_TEST(test_less_E2);
    CPPUNIT_TEST(test_less_E3);
    CPPUNIT_TEST(test_less_E4);
    CPPUNIT_TEST(test_greater);
    CPPUNIT_TEST(test_greater2);
    CPPUNIT_TEST(test_greater3);
    CPPUNIT_TEST(test_greater4);
    CPPUNIT_TEST(test_greater_E);
    CPPUNIT_TEST(test_greater_E2);
    CPPUNIT_TEST(test_greater_E3);
    CPPUNIT_TEST(test_greater_E4);
    CPPUNIT_TEST(test_greater_E5);   
    CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(test_plus2);
	CPPUNIT_TEST(test_plus3);
	CPPUNIT_TEST(test_plus4);
	CPPUNIT_TEST(test_plus5);
	CPPUNIT_TEST(test_plus6);
	CPPUNIT_TEST(test_plusEquals);
	CPPUNIT_TEST(test_plusEquals1);
	CPPUNIT_TEST(test_plusEquals2);
	CPPUNIT_TEST(test_plusEquals3);		
	CPPUNIT_TEST(test_plusEquals4);
	CPPUNIT_TEST(test_plusEquals5);
	CPPUNIT_TEST(test_minus);
	CPPUNIT_TEST(test_minus2);			
 	CPPUNIT_TEST(test_minus3);
 	CPPUNIT_TEST(test_minus4);
 	CPPUNIT_TEST(test_minus5);
 	CPPUNIT_TEST(test_minus6);
 	CPPUNIT_TEST(test_minusEquals);
	CPPUNIT_TEST(test_minusEquals2);			
 	CPPUNIT_TEST(test_minusEquals3);
 	CPPUNIT_TEST(test_minusEquals4);
 	CPPUNIT_TEST(test_minusEquals5);
 	CPPUNIT_TEST(test_minusEquals6);
 	CPPUNIT_TEST(test_multiplies);
	CPPUNIT_TEST(test_multiplies2);
	CPPUNIT_TEST(test_multiplies3);
	CPPUNIT_TEST(test_multiplies4);
	CPPUNIT_TEST(test_multiplies5);
	CPPUNIT_TEST(test_multiplies6);
 	CPPUNIT_TEST(test_multiplyEquals);		
	CPPUNIT_TEST(test_multiplyEquals2);
	CPPUNIT_TEST(test_multiplyEquals3);
	CPPUNIT_TEST(test_multiplyEquals4);
	CPPUNIT_TEST(test_multiplyEquals5);
	CPPUNIT_TEST(test_multiplyEquals6);
	CPPUNIT_TEST(test_iterator);
	CPPUNIT_TEST(test_iterator2);
	CPPUNIT_TEST(test_iterator3);
	CPPUNIT_TEST(test_iterator4);
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

