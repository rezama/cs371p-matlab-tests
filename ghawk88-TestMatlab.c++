// ------------------------------
// projects/matlab/TestMatlab.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
 * To test the program:
 *     g++ -g -ansi -pedantic -lcppunit -ldl -Wall ghawk88-TestMatlab.c++ -o TestMatlab.app
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

// ----------
// TestMatlab
// ----------

struct TestMatlab : CppUnit::TestFixture {
    // --------
    // test_cat
    // --------

    void test_horzcat_One() {
        Matrix<int> x(1, 2, 3);
        Matrix<int> y(1, 3, 3);
        Matrix<int> z(1, 5, 3);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_horzcat_Two() {
        Matrix<int> x(2, 1, 0);
        Matrix<int> y(2, 1, 3);
        Matrix<int> z(2, 2);
        z[0][1] = 3;
        z[1][1] = 3;
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_horzcat_Three() {
        Matrix<int> x(1, 1, -1);
        Matrix<int> y(1, 1, 3);
        Matrix<int> z(1, 2, 3);
        z[0][0] = -1;
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_vertcat_One() {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_vertcat_Two() {
        Matrix<int> x(2, 1, 1);
        Matrix<int> y(3, 1, 1);
        Matrix<int> z(5, 1, 1);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_vertcat_Three() {
        Matrix<int> x(2, 4);
        Matrix<int> y(1, 4);
        Matrix<int> z(3, 4);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }
// ---------
    // test_diag
    // ---------

    void test_diag_One() {
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_diag_Two() {
        Matrix<int> x(1, 1, 2);
        Matrix<int> y(1, 1, 2);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_diag_Three() {
        Matrix<int> x(2, 2, 5);
        Matrix<int> y(1, 2, 5);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------
    // test_dot
    // --------

    void test_dot_One() {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, 1);
        Matrix<int> z(1, 1, 1);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_dot_Two() {
        Matrix<int> x(3, 3);
      
        Matrix<int> z(1, 3);
	x[0][0] = 1;
	x[0][1] = 2;
	x[0][2] = 3;
	x[1][0] = 1;
	x[1][1] = 2;
	x[1][2] = 3;
	x[2][0] = 1;
	x[2][1] = 2;
	x[2][2] = 3;	        
	x = dot(x, x);
	z[0][0] = 3;
	z[0][1] = 12;
	z[0][2] = 27;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_dot_Three() {
        Matrix<int> x(2, 1, 2);
        Matrix<int> y(2, 1, 1);
        Matrix<int> z(1, 1, 4);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_dot_4() {
        Matrix<int> x(2, 2, 2);
        Matrix<int> y(2, 2);
        Matrix<int> z(1, 2, 2);

        y = eye<Matrix<int> >(2, 2);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    // --------
    // test_eye
    // --------

    void test_eye_One() {
        Matrix<int> x;
        Matrix<int> y(2, 3);
        y[0][0] = 1;
        y[1][1] = 1;
        x = eye<Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_eye_Two() {
        Matrix<int> x;
        Matrix<int> y(1, 1, 1);
        x = eye<Matrix<int> >(1, 1);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_eye_Three() {
        Matrix<int> x;
        Matrix<int> y(3, 2);
        y[0][0] = 1;
        y[1][1] = 1;
        x = eye<Matrix<int> >(3, 2);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_ones
    // ---------

    void test_ones_One() {
        Matrix<int> x;
        Matrix<int> y;
        x = ones<Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_ones_Two() {
        Matrix<int> x;
        Matrix<int> y(2, 3, 1);
        x = ones<Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_ones_Three() {
        Matrix<int> x;
        Matrix<int> y(1, 1, 1);
        x = ones<Matrix<int> >(1, 1);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_rand
    // ---------

    void test_rand_One() {
        Matrix<double> x;
        x = rand<Matrix<double> >(2, 3);

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                CPPUNIT_ASSERT(x[i][j] != 0 && x[i][j] < 1);
    }

    void test_rand_Two() {
        Matrix<int> x;
        x = rand<Matrix<int> >(0, 0);

    }

    void test_rand_Three() {
        Matrix<double> x;
        x = rand<Matrix<double> >(10, 10);
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                CPPUNIT_ASSERT(x[i][j] != 0 && x[i][j] < 1);
    }

    // --------------
    // test_transpose
    // --------------

    void test_transpose_One() {
        Matrix<int> x(1, 1, 2);
        Matrix<int> y(1,1, 2);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_transpose_Two() {
        Matrix<int> x(1, 2, 1);
        Matrix<int> y(2, 1, 1);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_transpose_Three() {
        Matrix<int> x(2, 2);
        x = eye<Matrix<int> >(2, 2);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(x));
    }

    void test_transpose_4() {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        x[0][1] = 1;
        y[1][0] = 1;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_tril
    // ---------

    void test_tril_One() {
        Matrix<int> y(1, 1, 1);
        Matrix<int> x(1, 1, 1);
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_tril_Two() {
 	Matrix<int> y(2, 2, 1); 	
	Matrix<int> x(2, 2, 1);
       
        x = tril(x);
	y[0][1] = 0;       
	CPPUNIT_ASSERT(x.eq(y));        
    }

    void test_tril_Three() {

	Matrix<int> t(1, 2, 1);
        Matrix<int> e(1, 2, 0);
        e[0][0] = 1;
        t = tril(t);
        CPPUNIT_ASSERT(t.eq(e));
       
    }

    // ---------
    // test_triu
    // ---------

    void test_triu_One() {
        Matrix<int> a(1, 1, 1);
        Matrix<int> b(1, 1, 1);
        a = triu(a);
        CPPUNIT_ASSERT(a.eq(b));
    }

    void test_triu_Two() {
        Matrix<int> x(1, 2, 1);
        Matrix<int> y(1, 2, 1);
        x = triu(x);
        CPPUNIT_ASSERT(!x.eq(y));
    }

    void test_triu_Three() {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        y[1][0] = 0;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ----------
    // test_zeros
    // ----------

    void test_zeros_One() {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros<Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_zeros_Two() {
        Matrix<int> x(1, 1);
        Matrix<int> y(1, 1);
        x = zeros<Matrix<int> >(1, 1);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_zeros_Three() {
        Matrix<int> x(5, 5);
        Matrix<int> y(5, 5, 0);
        x = zeros<Matrix<int> >(5, 5);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // -----
    // suite
    // -----

CPPUNIT_TEST_SUITE(TestMatlab);

        CPPUNIT_TEST(test_horzcat_One);   
	CPPUNIT_TEST(test_horzcat_Two);
        CPPUNIT_TEST(test_horzcat_Three);

        CPPUNIT_TEST(test_vertcat_One);
        CPPUNIT_TEST(test_vertcat_Two);
        CPPUNIT_TEST(test_vertcat_Three);
 
        CPPUNIT_TEST(test_diag_One);
        CPPUNIT_TEST(test_diag_Two);
        CPPUNIT_TEST(test_diag_Three);
        
	CPPUNIT_TEST(test_eye_One);
        CPPUNIT_TEST(test_eye_Two);
        CPPUNIT_TEST(test_eye_Three);
     
	CPPUNIT_TEST(test_dot_One);
        CPPUNIT_TEST(test_dot_Two);
        CPPUNIT_TEST(test_dot_Three);
        CPPUNIT_TEST(test_dot_4);



        CPPUNIT_TEST(test_ones_One);
        CPPUNIT_TEST(test_ones_Two);
        CPPUNIT_TEST(test_ones_Three);

        CPPUNIT_TEST(test_rand_One);
        CPPUNIT_TEST(test_rand_Two);
        CPPUNIT_TEST(test_rand_Three);

        CPPUNIT_TEST(test_transpose_One);
        CPPUNIT_TEST(test_transpose_Two);
        CPPUNIT_TEST(test_transpose_Three);
        CPPUNIT_TEST(test_transpose_4);

        CPPUNIT_TEST(test_tril_One);
        CPPUNIT_TEST(test_tril_Two);
        CPPUNIT_TEST(test_tril_Three);

        CPPUNIT_TEST(test_triu_One);
        CPPUNIT_TEST(test_triu_Two);
        CPPUNIT_TEST(test_triu_Three);

        CPPUNIT_TEST(test_zeros_One);
        CPPUNIT_TEST(test_zeros_Two);
        CPPUNIT_TEST(test_zeros_Three);

    CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestMatlab.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestMatlab::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}

