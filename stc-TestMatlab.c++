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

#define private public
#include "Matrix.h"
#include "Matlab.h"

// ----------
// TestMatlab
// ----------

struct TestMatlab : CppUnit::TestFixture {
    // --------
    // test_cat
    // --------

    void test_horzcat () {
        std::cout << std::endl << "test_horzcat: " << std::endl;
		Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        z = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
	}

    void test_horzcat2 () {
        std::cout << std::endl << "test_horzcat2: " << std::endl;
		Matrix<int> x(2,2,3);
        Matrix<int> y(2,2,4);
        Matrix<int> z(2,4);
		Matrix<int> test(2,4,3);
		test[0][2] = 4;
		test[0][3] = 4;
		test[1][2] = 4;
		test[1][3] = 4;
        z = horzcat(x, y);
		CPPUNIT_ASSERT(z.valid());
        CPPUNIT_ASSERT(z.eq(test));
	}

    void test_horzcat3 () {
        std::cout << std::endl << "test_horzcat3: " << std::endl;
		Matrix<int> x(2,0,0);
        Matrix<int> y(2,1,100);
        Matrix<int> z(2,1,0);
        Matrix<int> test(2,1,100);
        z = horzcat(x, y);
        CPPUNIT_ASSERT(z.eq(test));
	}

    void test_horzcat4 () {
        std::cout << std::endl << "test_horzcat4: " << std::endl;
		Matrix<int> x(1,3);
        Matrix<int> y(2,3);
        Matrix<int> z(2,6);
		try{
        	z = horzcat(x, y);
			CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
        	CPPUNIT_ASSERT(x.eq(x));
		}
	}

    void test_vertcat () {
        std::cout << std::endl << "test_vertcat: " << std::endl;
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat2 () {
        std::cout << std::endl << "test_vertcat2: " << std::endl;
		Matrix<int> x(2,2,3);
        Matrix<int> y(2,2,4);
        Matrix<int> z(4,2);
		Matrix<int> test(4,2,3);
		test[2][0] = 4;
		test[2][1] = 4;
		test[3][0] = 4;
		test[3][1] = 4;
        z = vertcat(x, y);
		CPPUNIT_ASSERT(z.valid());
        CPPUNIT_ASSERT(z.eq(test));
	}
    
	void test_vertcat3 () {
        std::cout << std::endl << "test_vertcat3: " << std::endl;
		Matrix<int> x(3,1);
        Matrix<int> y(3,2);
        Matrix<int> z(3,3);
		try{
        	z = vertcat(x, y);
			CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
        	CPPUNIT_ASSERT(x.eq(x));
		}
	}


    // ---------
    // test_diag
    // ---------

    void test_diag () {
        std::cout << std::endl << "test_diag: " << std::endl;
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_diag2 () {
        std::cout << std::endl << "test_diag2: " << std::endl;
        Matrix<int> x(3,3,1);
        Matrix<int> y(3,1,1);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
        CPPUNIT_ASSERT(x.valid());
	}

    void test_diag3 () {
        std::cout << std::endl << "test_diag3: " << std::endl;
        Matrix<int> x(2,3,999);
		x[0][0] = 1;
		x[1][1] = 2;
        Matrix<int> y(2,1,1);
		y[1][0] = 2;
        x = diag(x);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));

		x = Matrix<int>(3, 2, 999);
		x[0][0] = 0;
		x[1][1] = 1;
		y = Matrix<int>(2, 1, 0);
		y[1][0] = 1;
        x = diag(x);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));
	}

    // --------
    // test_dot
    // --------

    void test_dot () {
        std::cout << std::endl << "test_dot: " << std::endl;
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
	}

    void test_dot2 () {
        std::cout << std::endl << "test_dot2: " << std::endl;
        Matrix<int> x(2,2);
		x[0][0] = 1;
		x[0][1] = 3;
		x[1][0] = 4;
		x[1][1] = 2;
        Matrix<int> y(2,2);
		y[0][0] = 5;
		y[0][1] = 1;
		y[1][0] = 1;
		y[1][1] = 8;
		
        Matrix<int> z(1,2);
		z[0][0] = 9;
		z[0][1] = 19;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(z));
        
		x= Matrix<int>(1,2);
		x[0][0] = 1;
		x[0][1] = 3;
        y= Matrix<int>(1,2);
		y[0][0] = 5;
		y[0][1] = 1;
		
        z= Matrix<int>(1,2);
		z[0][0] = 5;
		z[0][1] = 3;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(z));
	}

    void test_dot3 () {
        std::cout << std::endl << "test_dot3: " << std::endl;
        Matrix<int> x(2,3);
        Matrix<int> y(2,4);
        Matrix<int> z;
		try{
        	z = dot(x, y);
			CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
        	CPPUNIT_ASSERT(x.eq(x));
		}

		x = Matrix<int>(3,4);
		try{
        	z = dot(x, y);
			CPPUNIT_ASSERT(false);
		}
		catch(invalid_argument& e)
		{
        	CPPUNIT_ASSERT(x.eq(x));
		}
	}

    // --------
    // test_eye
    // --------

    void test_eye () {
        std::cout << std::endl << "test_eye: " << std::endl;
        Matrix<int> x;
        Matrix<int> y(0,0);
        x = eye< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));
        
        x = eye< Matrix<int> >(1, 0);
		y = Matrix<int>(1,0);
        CPPUNIT_ASSERT(x.eq(y));
        
		x = eye< Matrix<int> >(0, 1);
		y = Matrix<int>(0,1);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_eye2 () {
        std::cout << std::endl << "test_eye2: " << std::endl;
        Matrix<int> x;
        Matrix<int> y(2,2,0);
		y[0][0] = 1;
		y[1][1] = 1;
        x = eye< Matrix<int> >(2, 2);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_eye3 () {
        std::cout << std::endl << "test_eye3: " << std::endl;
        Matrix<int> x;
        Matrix<int> y(2,3,0);
		y[0][0] = 1;
		y[1][1] = 1;
        x = eye< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));
        
        y = Matrix<int>(3,2,0);
		y[0][0] = 1;
		y[1][1] = 1;
        x = eye< Matrix<int> >(3, 2);
        CPPUNIT_ASSERT(x.valid());
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
        std::cout << std::endl << "test_ones: " << std::endl;
        Matrix<int> x;
        Matrix<int> y;
        x = ones< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_ones2 () {
        std::cout << std::endl << "test_ones2: " << std::endl;
        Matrix<int> x;
        Matrix<int> y(3,3,1);
        x = ones< Matrix<int> >(3, 3);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_ones3 () {
        std::cout << std::endl << "test_ones3: " << std::endl;
        Matrix<int> x;
        Matrix<int> y(4,5,1);
        x = ones< Matrix<int> >(4, 5);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_rand
    // ---------

    void test_rand () {
        std::cout << std::endl << "test_rand: " << std::endl;
        Matrix<int> x;
        Matrix<int> y;
        x = rand< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_rand2 () {
        std::cout << std::endl << "test_rand2: " << std::endl;
        Matrix<int> x;
        Matrix<int> y(1,0);
        x = rand< Matrix<int> >(1, 0);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_rand3 () {
        std::cout << std::endl << "test_rand3: " << std::endl;
        Matrix<double> x;
        Matrix<double> y(2,2,999);
        x = rand< Matrix<double> >(2, 3);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(!x.eq(y));
	}

    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        std::cout << std::endl << "test_transpose: " << std::endl;
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_transpose2 () {
        std::cout << std::endl << "test_transpose2: " << std::endl;
        Matrix<int> x(2,3,99);
		x[1][2] = 200;
        Matrix<int> y(3,2,99);
		y[2][1] = 200;
        x = transpose(x);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_transpose3 () {
        std::cout << std::endl << "test_transpose3: " << std::endl;
        Matrix<int> x(2,2,1);
        Matrix<int> y(2,2,1);
        x = transpose(x);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));
	}

    // ---------
    // test_tril
    // ---------

    void test_tril () {
        std::cout << std::endl << "test_tril: " << std::endl;
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_tril2 () {
        std::cout << std::endl << "test_tril2: " << std::endl;
        Matrix<int> x(1,1,1);
        Matrix<int> y(1,1,1);
        x = tril(x);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_tril3 () {
        std::cout << std::endl << "test_tril3: " << std::endl;
        Matrix<int> x(3,3,99);
        Matrix<int> y(3,3,99);
		y[0][1] = 0;
		y[0][2] = 0;
		y[1][2] = 0;
        x = tril(x);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));
	}

    // ---------
    // test_triu
    // ---------

    void test_triu () {
        std::cout << std::endl << "test_triu: " << std::endl;
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_triu2 () {
        std::cout << std::endl << "test_triu2: " << std::endl;
        Matrix<int> x(1,1,1);
        Matrix<int> y(1,1,1);
        x = triu(x);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_triu3 () {
        std::cout << std::endl << "test_triu3: " << std::endl;
        Matrix<int> x(3,3,99);
        Matrix<int> y(3,3,99);
		y[1][0] = 0;
		y[2][0] = 0;
		y[2][1] = 0;
        x = triu(x);
        CPPUNIT_ASSERT(x.valid());
        CPPUNIT_ASSERT(x.eq(y));
	}

    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x;
        Matrix<int> y(0,0,0);
        x = zeros< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_zeros2 () {
        Matrix<int> x;
        Matrix<int> y(1,1,0);
        x = zeros< Matrix<int> >(1, 1);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_zeros3 () {
        Matrix<int> x;
        Matrix<int> y(4,5,0);
        x = zeros< Matrix<int> >(4, 5);
        CPPUNIT_ASSERT(x.eq(y));
	}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(test_horzcat2);
    CPPUNIT_TEST(test_horzcat3);
    CPPUNIT_TEST(test_horzcat4);
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(test_vertcat2);
    CPPUNIT_TEST(test_vertcat3);
    CPPUNIT_TEST(test_diag);
    CPPUNIT_TEST(test_diag2);
    CPPUNIT_TEST(test_diag3);
    CPPUNIT_TEST(test_dot);
    CPPUNIT_TEST(test_dot2);
    CPPUNIT_TEST(test_dot3);
    CPPUNIT_TEST(test_eye);
    CPPUNIT_TEST(test_eye2);
    CPPUNIT_TEST(test_eye3);
    CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_ones);
    CPPUNIT_TEST(test_ones2);
    CPPUNIT_TEST(test_ones3);
    CPPUNIT_TEST(test_rand);
    CPPUNIT_TEST(test_rand2);
    CPPUNIT_TEST(test_rand3);
    CPPUNIT_TEST(test_transpose);
    CPPUNIT_TEST(test_transpose2);
    CPPUNIT_TEST(test_transpose3);
    CPPUNIT_TEST(test_tril);
    CPPUNIT_TEST(test_tril2);
    CPPUNIT_TEST(test_tril3);
    CPPUNIT_TEST(test_triu);
    CPPUNIT_TEST(test_triu2);
    CPPUNIT_TEST(test_triu3);
    CPPUNIT_TEST(test_zeros);
    CPPUNIT_TEST(test_zeros2);
    CPPUNIT_TEST(test_zeros3);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestMatlab.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestMatlab::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
