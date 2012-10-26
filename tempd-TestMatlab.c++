// ------------------------------
// projects/matlab/TestMatlab.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
 * To test the program:
 *     g++ -ansi -pedantic -lcppunit -ldl -Wall TestMatlab.c++ -o TestMatlab.app
 *     valgrind TestMatlab.app >& TestMatlab.out
 */

// --------
// includes
// --------

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner
#include "Matrix.h"
#include "Matlab.h"
#include "stdio.h"
#include <typeinfo> //type checking for rand

// ----------
// TestMatlab
// ----------

template <typename T>
struct TestMatlab : CppUnit::TestFixture {
	
	// --------
	// typedefs
	// --------
	typedef typename T::iterator       iterator;
	typedef typename T::const_iterator const_iterator;

    // --------
    // test_cat
    // --------

    void test_horzcat () {
        T x;
        T y;
        T z;
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
	y = T(2,2,2);
	z = T(2,3,2);
	T u = horzcat(y, z);
	
	CPPUNIT_ASSERT(u.eq(T(2,5,2)));
    }
    
    void test_vertcat () {
        T x;
	T y;
	T z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
	y = T(2,2,2);
	z = T(3,2,2);
	T u = vertcat(y, z);
	CPPUNIT_ASSERT(u.eq(T(5,2,2)));
    }
    
    // ---------
    // test_diag
    // ---------
    
    void test_diag () {
        T x;
        T y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
	
	T u(2,2,2);
	x = diag(u);
	CPPUNIT_ASSERT(x.eq(T(2,1,2)));
	
	T z(1,2,2);
	x = diag(z);
	
	for(int i = 0; i < (int)u.size(); ++i) {
	    for(int j = 0; j < (int)u[i].size(); ++j) {
		if( i != j)
		    u[i][j] = 0;
		else
		    u[i][j] = 2;
	    }
	}
	
	CPPUNIT_ASSERT(x.eq(u));
	
    }
    
    // --------
    // test_dot
    // --------
	
    void test_dot () {
        T x;
        T y;
        T z;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
	
	x = T(1,2,1);
	y = T(1,2,2);
	
	CPPUNIT_ASSERT(dot(x,y).eq(T(1,1,4)));
	
	x = T(2,2,1);
	y = T(2,2,2);
	
	CPPUNIT_ASSERT(dot(x,y).eq(T(1,2,4)));
    }
	
    // --------
    // test_eye
    // --------
	
    void test_eye () {
        T x;
        T y;
	x = eye< T >(0,5);
        CPPUNIT_ASSERT(x.eq(y));
	
	x = eye< T >(2,3);
	y = T(2,3,0);
	for(int i = 0; i < (int)y.size(); ++i)
	    y[i][i] = 1;
	CPPUNIT_ASSERT(x.eq(y));
    }
    
    // -------------
    // test_linsolve
    // -------------

    void test_linsolve () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = linsolve(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------
    // test_ones
    // ---------

    void test_ones () {
	T x;
        T y;
	x = ones< T >(0,5);
        CPPUNIT_ASSERT(x.eq(y));
	
	x = ones< T >(2,3);
	y = T(2,3,1);
	CPPUNIT_ASSERT(x.eq(y));
    }
    
    // ---------
    // test_rand
    // ---------

    void test_rand () {
	try{
	    Matrix<int> x;
	    Matrix<int> y;
	    x = rand< Matrix<int> >(2, 3);
	    CPPUNIT_ASSERT(x.eq(y));
	}
	catch( bad_typeid& t )
	{
	    CPPUNIT_ASSERT(true);
	}
	
	Matrix<double> z = rand< Matrix<double> >(2,3);
	
	for (unsigned int i = 0; i < z.size(); i++)
        {
            for (unsigned int j = 0; j < z[0].size(); j++)
            {
                CPPUNIT_ASSERT(z[i][j] <= 1 && z[i][j] >= 0);
            }
        }
	
	Matrix<double> x = rand< Matrix<double> >(0,2);
	Matrix<double> k;
	CPPUNIT_ASSERT(x.eq(k));
    }

    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        T x;
        T y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
		
	T z(2,2,0);
	for(int i = 0; i < (int)z.size(); ++i)
	{
	    int count = 1;
	    
	    for(int j = 0; j < (int) z[0].size(); ++j)
	    {
		z[i][j] = count;
	    }
		}
	x = transpose(z);
	T u(2,2,0);
	for(int i = 0; i < (int)u.size(); ++i)
	{
	    int count = 1;
	    
	    for(int j = 0; j < (int)u[0].size(); ++j)
	    {
		u[j][i] = count;
	    }
	}
	CPPUNIT_ASSERT(x.eq(u));
	u = transpose(u);
	CPPUNIT_ASSERT(u.eq(z));
	
	}

    // ---------
    // test_tril
    // ---------

    void test_tril () {
        T x;
        T y;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
		
		T z(2,2,2);
		z = tril(z);
		
		for(int i = 0; i < (int)z.size(); ++i)
		{
			for(int j = 0; j < (int)z[0].size(); ++j)
			{
				if( j <= i )
					CPPUNIT_ASSERT(z[i][j] == 2);
				else
					CPPUNIT_ASSERT(z[i][j] == 0);
			}
		}
		
    }
	
    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
	
		
		T z(2,2,2);
		z = triu(z);

		for(int i = 0; i < (int)z.size(); ++i)
		{
			for(int j = 0; j < (int)z[0].size(); ++j)
			{
				if( j >= i )
					CPPUNIT_ASSERT(z[i][j] == 2);
				else
					CPPUNIT_ASSERT(z[i][j] == 0);
			}
		}
    }
	
    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        T x;
        T y;
        x = zeros< T >(0, 5);
        CPPUNIT_ASSERT(x.eq(y));
	
	x = zeros< T >(2,3);
	T u(2,3,0);
	CPPUNIT_ASSERT(x.eq(u));
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(test_diag);
    CPPUNIT_TEST(test_dot);
    CPPUNIT_TEST(test_eye);
    // CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_ones);
    CPPUNIT_TEST(test_rand);
    CPPUNIT_TEST(test_transpose);
    CPPUNIT_TEST(test_tril);
    CPPUNIT_TEST(test_triu);
    CPPUNIT_TEST(test_zeros);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestMatlab.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestMatlab< Matrix<int> >::suite());
	tr.addTest(TestMatlab< Matrix<double> >::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
