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
#include <vector>  // vector

#define private public
#define protected public
#define class struct

#include "Matrix.h"

using namespace std;

// ----------
// TestMatrix
// ----------

struct TestMatrix : CppUnit::TestFixture {

	// ----------------
    // test_op_equals
    // ----------------
	
	void test_op_equals_one () {
		Matrix<int> x;
		Matrix<int> y;
		Matrix<bool> result = (x == y);
		CPPUNIT_ASSERT(x._m.size() == 0);
		CPPUNIT_ASSERT(y._m.size() == 0);
		CPPUNIT_ASSERT(result._m.size() == 0);
	}
		
	void test_op_equals_two () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(2, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		Matrix<bool> result = (x == y);
		
		CPPUNIT_ASSERT(result._m.size() == 2);
		CPPUNIT_ASSERT(result._m[0].size() == 2);
		CPPUNIT_ASSERT(result._m[1].size() == 2);
		CPPUNIT_ASSERT(result._m[0][0] == true);
		CPPUNIT_ASSERT(result._m[0][1] == false);
		CPPUNIT_ASSERT(result._m[1][0] == true);
		CPPUNIT_ASSERT(result._m[1][1] == false);
	}

	void test_op_equals_three () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;
		try {
			Matrix<bool> result = (x == y);
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
		
	}
	
	// ----------------
    // test_op_notequal
    // ----------------
	
	void test_op_notequal_one () {
		Matrix<int> x;
		Matrix<int> y;
		Matrix<bool> result = (x != y);
		CPPUNIT_ASSERT(x._m.size() == 0);
		CPPUNIT_ASSERT(y._m.size() == 0);
		CPPUNIT_ASSERT(result._m.size() == 0);
	}
		
	void test_op_notequal_two () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(2, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		Matrix<bool> result = (x != y);
		
		CPPUNIT_ASSERT(result._m.size() == 2);
		CPPUNIT_ASSERT(result._m[0].size() == 2);
		CPPUNIT_ASSERT(result._m[1].size() == 2);
		CPPUNIT_ASSERT(result._m[0][0] == false);
		CPPUNIT_ASSERT(result._m[0][1] == true);
		CPPUNIT_ASSERT(result._m[1][0] == false);
		CPPUNIT_ASSERT(result._m[1][1] == true);
	}

	void test_op_notequal_three () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;
		
		try {
			Matrix<bool> result = (x != y);
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
		
	}
	
	// ----------------
    // test_op_lessthan
    // ----------------
	
	void test_op_lessthan_one () {
		Matrix<int> x;
		Matrix<int> y;
		Matrix<bool> result = (x < y);
		CPPUNIT_ASSERT(x._m.size() == 0);
		CPPUNIT_ASSERT(y._m.size() == 0);
		CPPUNIT_ASSERT(result._m.size() == 0);
	}
		
	void test_op_lessthan_two () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(2, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		Matrix<bool> result = (x < y);
		
		CPPUNIT_ASSERT(result._m.size() == 2);
		CPPUNIT_ASSERT(result._m[0].size() == 2);
		CPPUNIT_ASSERT(result._m[1].size() == 2);
		CPPUNIT_ASSERT(result._m[0][0] == false);
		CPPUNIT_ASSERT(result._m[0][1] == true);
		CPPUNIT_ASSERT(result._m[1][0] == false);
		CPPUNIT_ASSERT(result._m[1][1] == false);
	}

	void test_op_lessthan_three () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		
		try {
			Matrix<bool> result = (x < y);
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
	}
	
	// ----------------
    // test_op_lessthanequal
    // ----------------
	
	void test_op_lessthanequal_one () {
		Matrix<int> x;
		Matrix<int> y;
		Matrix<bool> result = (x <= y);
		CPPUNIT_ASSERT(x._m.size() == 0);
		CPPUNIT_ASSERT(y._m.size() == 0);
		CPPUNIT_ASSERT(result._m.size() == 0);
	}
		
	void test_op_lessthanequal_two () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(2, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		Matrix<bool> result = (x <= y);
		
		CPPUNIT_ASSERT(result._m.size() == 2);
		CPPUNIT_ASSERT(result._m[0].size() == 2);
		CPPUNIT_ASSERT(result._m[1].size() == 2);
		CPPUNIT_ASSERT(result._m[0][0] == true);
		CPPUNIT_ASSERT(result._m[0][1] == true);
		CPPUNIT_ASSERT(result._m[1][0] == true);
		CPPUNIT_ASSERT(result._m[1][1] == false);
	}

	void test_op_lessthanequal_three () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;	
		
		try {
			Matrix<bool> result = (x <= y);
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
	}
	
	// ----------------
    //  test_op_greaterthan
    // ----------------
	
	void test_op_greaterthan_one () {
		Matrix<int> x;
		Matrix<int> y;
		Matrix<bool> result = (x > y);
		CPPUNIT_ASSERT(x._m.size() == 0);
		CPPUNIT_ASSERT(y._m.size() == 0);
		CPPUNIT_ASSERT(result._m.size() == 0);
	}
		
	void test_op_greaterthan_two () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(2, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		Matrix<bool> result = (x > y);
		
		CPPUNIT_ASSERT(result._m.size() == 2);
		CPPUNIT_ASSERT(result._m[0].size() == 2);
		CPPUNIT_ASSERT(result._m[1].size() == 2);
		CPPUNIT_ASSERT(result._m[0][0] == false);
		CPPUNIT_ASSERT(result._m[0][1] == false);
		CPPUNIT_ASSERT(result._m[1][0] == false);
		CPPUNIT_ASSERT(result._m[1][1] == true);
	}

	void test_op_greaterthan_three () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		try {
			Matrix<bool> result = (x > y);
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
	}
	
	// ----------------
    //  test_op_greaterthanequal
    // ----------------

	void test_op_greaterthanequal_one () {
		Matrix<int> x;
		Matrix<int> y;
		Matrix<bool> result = (x >= y);
		CPPUNIT_ASSERT(x._m.size() == 0);
		CPPUNIT_ASSERT(y._m.size() == 0);
		CPPUNIT_ASSERT(result._m.size() == 0);
	}
		
	void test_op_greaterthanequal_two () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(2, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		Matrix<bool> result = (x >= y);
		
		CPPUNIT_ASSERT(result._m.size() == 2);
		CPPUNIT_ASSERT(result._m[0].size() == 2);
		CPPUNIT_ASSERT(result._m[1].size() == 2);
		CPPUNIT_ASSERT(result._m[0][0] == true);
		CPPUNIT_ASSERT(result._m[0][1] == false);
		CPPUNIT_ASSERT(result._m[1][0] == true);
		CPPUNIT_ASSERT(result._m[1][1] == true);
	}

	void test_op_greaterthanequal_three () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;	
			
		try {
			Matrix<bool> result = (x >= y);
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
	}



    // ----------------
    // test_constructor
    // ----------------

    void test_constructor () {
        Matrix<int> x;
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(x.size() == 0);}
		
    void test_constructor_one () {
        Matrix<int> x;
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(2, 3, 4);
		
        CPPUNIT_ASSERT(x._m.size() == 0);
		
		CPPUNIT_ASSERT(y._m.size() == 2);
		CPPUNIT_ASSERT(y._m[0].size() == 0);
		CPPUNIT_ASSERT(y._m[1].size() == 0);
		
		CPPUNIT_ASSERT(z._m.size() == 2);
		CPPUNIT_ASSERT(z._m[0].size() == 3);
		CPPUNIT_ASSERT(z._m[1].size() == 3);
		CPPUNIT_ASSERT(z._m[0][0] == 0);
		CPPUNIT_ASSERT(z._m[0][1] == 0);
		CPPUNIT_ASSERT(z._m[1][0] == 0);
		CPPUNIT_ASSERT(z._m[1][1] == 0);
		
		CPPUNIT_ASSERT(t._m.size() == 2);
		CPPUNIT_ASSERT(t._m[0].size() == 3);
		CPPUNIT_ASSERT(t._m[1].size() == 3);
		CPPUNIT_ASSERT(t._m[0][0] == 4);
		CPPUNIT_ASSERT(t._m[0][1] == 4);
		CPPUNIT_ASSERT(t._m[1][0] == 4);
		CPPUNIT_ASSERT(t._m[1][1] == 4);}
		
    void test_constructor_two () {
		Matrix<bool> t(2, 2, true);
		CPPUNIT_ASSERT(t._m.size() == 2);
		CPPUNIT_ASSERT(t._m[0].size() == 2);
		CPPUNIT_ASSERT(t._m[1].size() == 2);
		CPPUNIT_ASSERT(t._m[0][0] == true);
		CPPUNIT_ASSERT(t._m[0][1] == true);
		CPPUNIT_ASSERT(t._m[1][0] == true);
		CPPUNIT_ASSERT(t._m[1][1] == true);}
		
    void test_constructor_three () {
		Matrix<bool> t(13, true);
		CPPUNIT_ASSERT(t._m.size() == 13);
		// for some reason t._m[0].size() == 1 and not default 0
		CPPUNIT_ASSERT(t._m[0].size() == 1);}

    // ----------
    // test_index
    // ----------

    void test_index () {
        const Matrix<int> x(1, 1, 0);
        CPPUNIT_ASSERT(x[0][0] == 0);}
    
	void test_index_one () {
		Matrix<int> y;
		vector< vector<int> > myMatrix(2, vector <int>(2, 0));
		
		myMatrix[0][0] = 1;
		myMatrix[0][1] = 2;
		myMatrix[1][0] = 1;
		myMatrix[1][1] = 1;
		
		y._m = myMatrix;		
		
		CPPUNIT_ASSERT(y[0].size() == 2);
		CPPUNIT_ASSERT(y[1].size() == 2);
		CPPUNIT_ASSERT(y[0][0] == 1);
		CPPUNIT_ASSERT(y[0][1] == 2);
		CPPUNIT_ASSERT(y[1][0] == 1);
		CPPUNIT_ASSERT(y[1][1] == 1);
	}
		
    void test_index_two () {
		Matrix<int> y;
		vector< vector<int> > myMatrix(3, vector <int>(2, 0));
		
		myMatrix[0][0] = 1;
		myMatrix[0][1] = 1;
		myMatrix[1][0] = 1;
		myMatrix[1][1] = 5;
		myMatrix[2][0] = 1;
		myMatrix[2][1] = 1;
		
		y._m = myMatrix;		
				
		CPPUNIT_ASSERT(y[0].size() == 2);
		CPPUNIT_ASSERT(y[1].size() == 2);
		CPPUNIT_ASSERT(y[2].size() == 2);
		CPPUNIT_ASSERT(y[0][0] == 1);
		CPPUNIT_ASSERT(y[0][1] == 1);
		CPPUNIT_ASSERT(y[1][0] == 1);
		CPPUNIT_ASSERT(y[1][1] == 5);
		CPPUNIT_ASSERT(y[2][0] == 1);
		CPPUNIT_ASSERT(y[2][1] == 1);
	}
	
	void test_index_three () {
		Matrix<int> y;
		vector< vector<int> > myMatrix(1, vector <int>(8, 0));
		
		myMatrix[0][0] = 1;
		myMatrix[0][1] = 2;
		myMatrix[0][2] = 3;
		myMatrix[0][3] = 4;
		myMatrix[0][4] = 1;
		myMatrix[0][5] = 2;
		myMatrix[0][6] = 3;
		myMatrix[0][7] = 4;
		
		y._m = myMatrix;		
				
		CPPUNIT_ASSERT(y[0].size() == 8);
		CPPUNIT_ASSERT(y[0][0] == 1);
		CPPUNIT_ASSERT(y[0][1] == 2);
		CPPUNIT_ASSERT(y[0][2] == 3);
		CPPUNIT_ASSERT(y[0][3] == 4);
		CPPUNIT_ASSERT(y[0][4] == 1);
		CPPUNIT_ASSERT(y[0][5] == 2);
		CPPUNIT_ASSERT(y[0][6] == 3);
		CPPUNIT_ASSERT(y[0][7] == 4);
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
        CPPUNIT_ASSERT(z.eq(t));}
		
    void test_equals_one () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(2, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 2;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 5;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		bool result = (x.eq(y));
		
		CPPUNIT_ASSERT(result == true);
	}

    void test_equals_two () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(2, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		bool result = (x.eq(y));
		
		CPPUNIT_ASSERT(result == false);
	}
	
    void test_equals_three () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		bool result = (x.eq(y));
		
		CPPUNIT_ASSERT(result == false);
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

    void test_plus_one () {
		Matrix<int> x;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		x._m = xMatrix;	
		x += 5;
		
		CPPUNIT_ASSERT(x._m[0][0] == 6);
		CPPUNIT_ASSERT(x._m[0][1] == 6);
		CPPUNIT_ASSERT(x._m[1][0] == 6);
		CPPUNIT_ASSERT(x._m[1][1] == 10);
		CPPUNIT_ASSERT(x._m[2][0] == 6);
		CPPUNIT_ASSERT(x._m[2][1] == 6);
	}

    void test_plus_two () {
		Matrix<int> x;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		x._m = xMatrix;	
		x += -6;
		
		CPPUNIT_ASSERT(x._m[0][0] == -5);
		CPPUNIT_ASSERT(x._m[0][1] == -5);
		CPPUNIT_ASSERT(x._m[1][0] == -5);
		CPPUNIT_ASSERT(x._m[1][1] == -1);
		CPPUNIT_ASSERT(x._m[2][0] == -5);
		CPPUNIT_ASSERT(x._m[2][1] == -5);
	}

    void test_plus_three () {
		Matrix<int> x;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		x._m = xMatrix;	
		x += 0;
		
		CPPUNIT_ASSERT(x._m[0][0] == 1);
		CPPUNIT_ASSERT(x._m[0][1] == 1);
		CPPUNIT_ASSERT(x._m[1][0] == 1);
		CPPUNIT_ASSERT(x._m[1][1] == 5);
		CPPUNIT_ASSERT(x._m[2][0] == 1);
		CPPUNIT_ASSERT(x._m[2][1] == 1);
	}
	
	void test_matrixplus_one () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(2, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		x += y;
		
		CPPUNIT_ASSERT(x._m[0][0] == 2);
		CPPUNIT_ASSERT(x._m[0][1] == 3);
		CPPUNIT_ASSERT(x._m[1][0] == 2);
		CPPUNIT_ASSERT(x._m[1][1] == 6);
	}

    void test_matrixplus_two () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		
		try {
			x += y;
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
	}

    void test_matrixplus_three () {
       		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		vector< vector<int> > yMatrix(0, vector <int>(0, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		x += y;
		
		CPPUNIT_ASSERT(x._m[0][0] == 1);
		CPPUNIT_ASSERT(x._m[0][1] == 1);
		CPPUNIT_ASSERT(x._m[1][0] == 1);
		CPPUNIT_ASSERT(x._m[1][1] == 5);
		CPPUNIT_ASSERT(x._m[2][0] == 1);
		CPPUNIT_ASSERT(x._m[2][1] == 1);
	}
	
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

    void test_minus_one () {
		Matrix<int> x;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		x._m = xMatrix;	
		x -= 5;
		
		CPPUNIT_ASSERT(x._m[0][0] == -4);
		CPPUNIT_ASSERT(x._m[0][1] == -4);
		CPPUNIT_ASSERT(x._m[1][0] == -4);
		CPPUNIT_ASSERT(x._m[1][1] == 0);
		CPPUNIT_ASSERT(x._m[2][0] == -4);
		CPPUNIT_ASSERT(x._m[2][1] == -4);
	}

    void test_minus_two () {
		Matrix<int> x;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		x._m = xMatrix;	
		x -= -6;
		
		CPPUNIT_ASSERT(x._m[0][0] == 7);
		CPPUNIT_ASSERT(x._m[0][1] == 7);
		CPPUNIT_ASSERT(x._m[1][0] == 7);
		CPPUNIT_ASSERT(x._m[1][1] == 11);
		CPPUNIT_ASSERT(x._m[2][0] == 7);
		CPPUNIT_ASSERT(x._m[2][1] == 7);
	}

    void test_minus_three () {
		Matrix<int> x;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		x._m = xMatrix;	
		x -= 0;
		
		CPPUNIT_ASSERT(x._m[0][0] == 1);
		CPPUNIT_ASSERT(x._m[0][1] == 1);
		CPPUNIT_ASSERT(x._m[1][0] == 1);
		CPPUNIT_ASSERT(x._m[1][1] == 5);
		CPPUNIT_ASSERT(x._m[2][0] == 1);
		CPPUNIT_ASSERT(x._m[2][1] == 1);
	}
	
	void test_matrixminus_one () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(2, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		x -= y;
		
		CPPUNIT_ASSERT(x._m[0][0] == 0);
		CPPUNIT_ASSERT(x._m[0][1] == -1);
		CPPUNIT_ASSERT(x._m[1][0] == 0);
		CPPUNIT_ASSERT(x._m[1][1] == 4);
	}

    void test_matrixminus_two () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;

		try {
			x -= y;
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
	}

    void test_matrixminus_three () {
       		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		vector< vector<int> > yMatrix(0, vector <int>(0, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		x -= y;
		
		CPPUNIT_ASSERT(x._m[0][0] == 1);
		CPPUNIT_ASSERT(x._m[0][1] == 1);
		CPPUNIT_ASSERT(x._m[1][0] == 1);
		CPPUNIT_ASSERT(x._m[1][1] == 5);
		CPPUNIT_ASSERT(x._m[2][0] == 1);
		CPPUNIT_ASSERT(x._m[2][1] == 1);
	}
    
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

        
    void test_multiplies_one () {
		Matrix<int> x;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		x._m = xMatrix;	
		x *= 5;
		
		CPPUNIT_ASSERT(x._m[0][0] == 5);
		CPPUNIT_ASSERT(x._m[0][1] == 5);
		CPPUNIT_ASSERT(x._m[1][0] == 5);
		CPPUNIT_ASSERT(x._m[1][1] == 25);
		CPPUNIT_ASSERT(x._m[2][0] == 5);
		CPPUNIT_ASSERT(x._m[2][1] == 5);
	}

    void test_multiplies_two () {
		Matrix<int> x;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		x._m = xMatrix;	
		x *= -6;
		
		CPPUNIT_ASSERT(x._m[0][0] == -6);
		CPPUNIT_ASSERT(x._m[0][1] == -6);
		CPPUNIT_ASSERT(x._m[1][0] == -6);
		CPPUNIT_ASSERT(x._m[1][1] == -30);
		CPPUNIT_ASSERT(x._m[2][0] == -6);
		CPPUNIT_ASSERT(x._m[2][1] == -6);
	}

    void test_multiplies_three () {
		Matrix<int> x;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		x._m = xMatrix;	
		x *= 0;
		
		CPPUNIT_ASSERT(x._m[0][0] == 0);
		CPPUNIT_ASSERT(x._m[0][1] == 0);
		CPPUNIT_ASSERT(x._m[1][0] == 0);
		CPPUNIT_ASSERT(x._m[1][1] == 0);
		CPPUNIT_ASSERT(x._m[2][0] == 0);
		CPPUNIT_ASSERT(x._m[2][1] == 0);
	}
	
	void test_matrixmultiplies_one () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(2, vector <int>(2, 0));
		vector< vector<int> > yMatrix(2, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		x *= y;
		
		CPPUNIT_ASSERT(x._m[0][0] == 2);
		CPPUNIT_ASSERT(x._m[0][1] == 3);
		CPPUNIT_ASSERT(x._m[1][0] == 6);
		CPPUNIT_ASSERT(x._m[1][1] == 7);
	}

    void test_matrixmultiplies_two () {
		Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		vector< vector<int> > yMatrix(3, vector <int>(2, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		yMatrix[0][0] = 1;
		yMatrix[0][1] = 2;
		yMatrix[1][0] = 1;
		yMatrix[1][1] = 1;
		yMatrix[2][0] = 1;
		yMatrix[2][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;
		
		try {
			x *= y;
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
	}

    void test_matrixmultiplies_three () {
       	Matrix<int> x;
		Matrix<int> y;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		vector< vector<int> > yMatrix(0, vector <int>(0, 0));
		
		xMatrix[0][0] = 1;
		xMatrix[0][1] = 1;
		xMatrix[1][0] = 1;
		xMatrix[1][1] = 5;
		xMatrix[2][0] = 1;
		xMatrix[2][1] = 1;
		
		x._m = xMatrix;
		y._m = yMatrix;		
		x *= y;
		
		CPPUNIT_ASSERT(x._m[0][0] == 1);
		CPPUNIT_ASSERT(x._m[0][1] == 1);
		CPPUNIT_ASSERT(x._m[1][0] == 1);
		CPPUNIT_ASSERT(x._m[1][1] == 5);
		CPPUNIT_ASSERT(x._m[2][0] == 1);
		CPPUNIT_ASSERT(x._m[2][1] == 1);
	}
    
    // -------------
    // test_valid
    // -------------

    void test_valid_one () {
   		Matrix<int> x;
		vector< vector<int> > xMatrix(3, vector <int>(2, 0));
		x._m = xMatrix;
        CPPUNIT_ASSERT(x.valid());}
  
    void test_valid_two () {
   		Matrix<int> x;
		vector< vector<int> > xMatrix(0, vector <int>(0, 0));
		x._m = xMatrix;
        CPPUNIT_ASSERT(x.valid());}

    void test_valid_three () {
   		Matrix<int> x;
		vector< vector<int> > xMatrix(2, vector <int>(1, 0));
		x._m = xMatrix;
		x[0].resize(15);
        CPPUNIT_ASSERT(x.valid() == false);}
        
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
	
	// my added tests for ops
	CPPUNIT_TEST(test_op_equals_one);
	CPPUNIT_TEST(test_op_equals_two);
	CPPUNIT_TEST(test_op_equals_three);	
	
	CPPUNIT_TEST(test_op_notequal_one);
	CPPUNIT_TEST(test_op_notequal_two);
	CPPUNIT_TEST(test_op_notequal_three);	
	
	CPPUNIT_TEST(test_op_lessthan_one);
	CPPUNIT_TEST(test_op_lessthan_two);
	CPPUNIT_TEST(test_op_lessthan_three);
	
	CPPUNIT_TEST(test_op_lessthanequal_one);
	CPPUNIT_TEST(test_op_lessthanequal_two);
	CPPUNIT_TEST(test_op_lessthanequal_three);	
	
	CPPUNIT_TEST(test_op_greaterthan_one);
	CPPUNIT_TEST(test_op_greaterthan_two);
	CPPUNIT_TEST(test_op_greaterthan_three);
	
	CPPUNIT_TEST(test_op_greaterthanequal_one);
	CPPUNIT_TEST(test_op_greaterthanequal_two);
	CPPUNIT_TEST(test_op_greaterthanequal_three);	
	
	// my added tests for methods	
	CPPUNIT_TEST(test_constructor_one);
	CPPUNIT_TEST(test_constructor_two);
	CPPUNIT_TEST(test_constructor_three);
	
	CPPUNIT_TEST(test_index_one);
	CPPUNIT_TEST(test_index_two);
	CPPUNIT_TEST(test_index_three);
	
	CPPUNIT_TEST(test_equals_one);
	CPPUNIT_TEST(test_equals_two);
	CPPUNIT_TEST(test_equals_three);
	
	CPPUNIT_TEST(test_plus_one);
	CPPUNIT_TEST(test_plus_two);	
	CPPUNIT_TEST(test_plus_three);
	CPPUNIT_TEST(test_matrixplus_one);
	CPPUNIT_TEST(test_matrixplus_two);	
	CPPUNIT_TEST(test_matrixplus_three);
    
    CPPUNIT_TEST(test_minus_one);
	CPPUNIT_TEST(test_minus_two);	
	CPPUNIT_TEST(test_minus_three);
	CPPUNIT_TEST(test_matrixminus_one);
	CPPUNIT_TEST(test_matrixminus_two);	
	CPPUNIT_TEST(test_matrixminus_three);
    
    CPPUNIT_TEST(test_multiplies_one);
	CPPUNIT_TEST(test_multiplies_two);	
	CPPUNIT_TEST(test_multiplies_three);
	CPPUNIT_TEST(test_matrixmultiplies_one);
	CPPUNIT_TEST(test_matrixmultiplies_two);	
	CPPUNIT_TEST(test_matrixmultiplies_three);  

    CPPUNIT_TEST(test_valid_one);
	CPPUNIT_TEST(test_valid_two);	
	CPPUNIT_TEST(test_valid_three);
   
	//original skeleton tests
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
