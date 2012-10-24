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

// ----------
// TestMatlab
// ----------

struct TestMatlab : CppUnit::TestFixture {
    // --------
    // test_cat
    // --------

    void test_horzcat_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_horzcat_2 () {
	Matrix<int> x(3,4,3);
	Matrix<int> y(3,7,3);
	Matrix<int> z(3,11,3);
	x = horzcat(x,y);
	CPPUNIT_ASSERT(x.eq(z));}

    void test_horzcat_3 () {
	Matrix<int> x1(3,3,4);
	Matrix<int> x2(3,3,4);
	Matrix<int> x3(3,3,5);

	x1 = horzcat(x1,x2);
	x1 = horzcat(x1,x3);

	Matrix<int> y1(3,6,4);
	Matrix<int> y2(3,3,5);

	y1 = horzcat(y1,y2);

	CPPUNIT_ASSERT(x1.eq(y1)); }

    void test_vertcat_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat_2 () {
	Matrix<int> x(3,4,3);
	Matrix<int> y(3,4,3);
	Matrix<int> z(6,4,3);
	x = vertcat(x,y);
	CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat_3 () {
	Matrix<int> x1(3,3,4);
	Matrix<int> x2(3,3,4);
	Matrix<int> x3(3,3,5);

	x1 = vertcat(x1,x2);
	x1 = vertcat(x1,x3);

	Matrix<int> y1(6,3,4);
	Matrix<int> y2(3,3,5);

	y1 = vertcat(y1,y2);

	CPPUNIT_ASSERT(x1.eq(y1)); }

    // ---------
    // test_diag
    // ---------

    void test_diag_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag_2 () {
        Matrix<int> x(3, 3, 3);
        Matrix<int> y(3, 1, 3);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag_3 () {
        Matrix<int> x(4, 2, 1);
        Matrix<int> y(2, 1, 1);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag_4 () {
        Matrix<int> x(4, 1, 1);
        Matrix<int> y(4, 4, 0);
        x = diag(x);
	for(int i = 0; i < 4; i++)
	   y[i][i] = 1;

        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag_5 () {
        Matrix<int> x(1, 4, 1);
        Matrix<int> y(4, 4, 0);
        x = diag(x);
	for(int i = 0; i < 4; i++)
	   y[i][i] = 1;
        CPPUNIT_ASSERT(x.eq(y));}

    // --------
    // test_dot
    // --------

    void test_dot_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_2 () {
        Matrix<int> x(1,3,3);
        Matrix<int> y(1,3,4);
        Matrix<int> z(1,1,36);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_3 () {
        Matrix<int> x(3,1,3);
        Matrix<int> y(3,1,4);
        Matrix<int> z(1,1,36);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_4 () {
        Matrix<int> x(1,3,3);
        Matrix<int> y(3,1,4);
        Matrix<int> z(1,1,36);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_5 () {
        Matrix<int> x(3,1,3);
        Matrix<int> y(1,3,4);
        Matrix<int> z(1,1,36);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_6 () {
        Matrix<int> x(2,3,3);
        Matrix<int> y(2,3,3);
        Matrix<int> z(1,3,18);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    // --------
    // test_eye
    // --------

    void test_eye_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = eye< Matrix<int> >(3, 3);
	y = Matrix<int>(3,3,0);
	y[0][0] = 1;
	y[1][1] = 1;
	y[2][2] = 1;
        CPPUNIT_ASSERT(x.eq(y));}

    void test_eye_2 () {
	Matrix<int> x = eye< Matrix<int> >(5,7);
	Matrix<int> y(5,7,0);
	for(int i = 0; i < 5; i++)
	   y[i][i] = 1;
	CPPUNIT_ASSERT(x.eq(y));}

    void test_eye_3 () {
	Matrix<int> x = eye< Matrix<int> >(7,5);
	Matrix<int> y(7,5,0);
	for(int i = 0; i < 5; i++)
	   y[i][i] = 1;
        CPPUNIT_ASSERT(x.eq(y));}


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

    void test_ones_1 () {
        Matrix<int> x;
        Matrix<int> y(2,3,1);
        x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_ones_2 () {
        Matrix<int> x;
        Matrix<int> y(5,5,1);
        x = ones< Matrix<int> >(5, 5);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_ones_3 () {
        Matrix<int> x;
        Matrix<int> y(7,9,1);
        x = ones< Matrix<int> >(7, 9);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_rand
    // ---------

    void test_rand_1 () {
        Matrix<double> x;
        Matrix<double> y(2,3);
        x = rand< Matrix<double> >(2, 3);
        CPPUNIT_ASSERT(!(x.eq(y)));}

    void test_rand_2 () {
        Matrix<double> x;
        Matrix<double> y(5,5);
        x = rand< Matrix<double> >(5, 5);
        CPPUNIT_ASSERT(!(x.eq(y)));}

    void test_rand_3 () {
        Matrix<double> x;
        Matrix<double> y(7,9);
        x = rand< Matrix<double> >(7, 9);
        CPPUNIT_ASSERT(!(x.eq(y)));}

    // --------------
    // test_transpose
    // --------------

    void test_transpose_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_transpose_2 () {
	Matrix<int> x(3,5,1);
	Matrix<int> y(5,3,1);
	x = transpose(x);
	CPPUNIT_ASSERT(x.eq(y));}
    
    void test_transpose_3 () {
	Matrix<int> x(8,2,7);
	Matrix<int> y(2,8,7);
	x = transpose(x);
	CPPUNIT_ASSERT(x.eq(y));}
    
    // ---------
    // test_tril
    // ---------

    void test_tril_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_tril_2 () {
	Matrix<int> x(5,5,5);
	Matrix<int> y(5,5,5);
	x = tril(x);

	for(int i = 0; i < 5; i++)
	  for(int j = i+1; j < 5; j++)
	    y[i][j] = 0;

	CPPUNIT_ASSERT(x.eq(y));
    }

    void test_tril_3 () {
	Matrix<int> x(7,5,5);
	Matrix<int> y(7,5,5);
	x = tril(x);

	for(int i = 0; i < 7; i++)
	  for(int j = i+1; j < 5; j++)
	    y[i][j] = 0;

	CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_triu
    // ---------

    void test_triu_1 () {
        Matrix<int> x(5,5,5);
        Matrix<int> y(5,5,5);
        x = triu(x);
	for(int i = 0; i < 5; i++)
	 for(int j = 0; j < i; j++)
	    y[i][j] = 0;

        CPPUNIT_ASSERT(x.eq(y));}

    void test_triu_2 () {
        Matrix<int> x(7,3,5);
        Matrix<int> y(7,3,5);
        x = triu(x);
	for(int i = 0; i < 3; i++)
	 for(int j = 0; j < i; j++)
	    y[i][j] = 0;
	for(int i = 3; i < 7; i++)
	 for(int j = 0; j < 3; j++)
	    y[i][j] = 0; 

        CPPUNIT_ASSERT(x.eq(y));}

    void test_triu_3 () {
        Matrix<int> x(3,7,5);
        Matrix<int> y(3,7,5);
        x = triu(x);
	for(int i = 0; i < 3; i++)
	 for(int j = 0; j < i; j++)
	    y[i][j] = 0;

        CPPUNIT_ASSERT(x.eq(y));}

    // ----------
    // test_zeros
    // ----------

    void test_zeros_1 () {
        Matrix<int> x;
        Matrix<int> y(2,3,0);
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_zeros_2 () {
        Matrix<int> x;
        Matrix<int> y(5,5,0);
        x = zeros< Matrix<int> >(5, 5);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_zeros_3 () {
        Matrix<int> x;
        Matrix<int> y(7,9,0);
        x = zeros< Matrix<int> >(7, 9);
        CPPUNIT_ASSERT(x.eq(y));}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat_1);
    CPPUNIT_TEST(test_horzcat_2);
    CPPUNIT_TEST(test_horzcat_3);
    CPPUNIT_TEST(test_vertcat_1);
    CPPUNIT_TEST(test_vertcat_2);
    CPPUNIT_TEST(test_vertcat_3);
    CPPUNIT_TEST(test_diag_1);
    CPPUNIT_TEST(test_diag_2);
    CPPUNIT_TEST(test_diag_3);
    CPPUNIT_TEST(test_diag_4);
    CPPUNIT_TEST(test_diag_5);
    CPPUNIT_TEST(test_dot_1);
    CPPUNIT_TEST(test_dot_2);
    CPPUNIT_TEST(test_dot_3);
    CPPUNIT_TEST(test_dot_4);
    CPPUNIT_TEST(test_dot_5);
    CPPUNIT_TEST(test_dot_6);
    CPPUNIT_TEST(test_eye_1);
    CPPUNIT_TEST(test_eye_2);
    CPPUNIT_TEST(test_eye_3);
    CPPUNIT_TEST(test_ones_1);
    CPPUNIT_TEST(test_ones_2);
    CPPUNIT_TEST(test_ones_3);
    CPPUNIT_TEST(test_rand_1);
    CPPUNIT_TEST(test_rand_2);
    CPPUNIT_TEST(test_rand_3);
    CPPUNIT_TEST(test_transpose_1);
    CPPUNIT_TEST(test_transpose_2);
    CPPUNIT_TEST(test_transpose_3);
    CPPUNIT_TEST(test_tril_1);
    CPPUNIT_TEST(test_tril_2);
    CPPUNIT_TEST(test_tril_3);
    CPPUNIT_TEST(test_triu_1);
    CPPUNIT_TEST(test_triu_2);
    CPPUNIT_TEST(test_triu_3);
    CPPUNIT_TEST(test_zeros_1);
    CPPUNIT_TEST(test_zeros_2);
    CPPUNIT_TEST(test_zeros_3);
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
