// ------------------------------
// projects/matlab/TestMatlab.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
* To test the program:
* g++ -ansi -pedantic -lcppunit -ldl -Wall TestMatlab.c++ -o TestMatlab.app
* valgrind TestMatlab.app >& TestMatlab.out
*/

// --------
// includes
// --------

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TestRunner

#include <stdexcept>
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
        CPPUNIT_ASSERT(x.eq(z));
	}

	void test_horzcat_2 () {
        Matrix<int> x(1, 1);
        Matrix<int> y(1, 1);
        Matrix<int> z(1, 2);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
	}

	void test_horzcat_3 () {
        Matrix<int> x(2, 2, 5);
        Matrix<int> y(2, 2, 5);
        Matrix<int> z(2, 4, 5);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
	}

	void test_horzcat_4 () {
        Matrix<int> x(5, 1);
        Matrix<int> y(1, 1);

		try{
        	x = horzcat(x, y);
			CPPUNIT_ASSERT(false);
		}catch(...)	{
			CPPUNIT_ASSERT(true);
		}
	}

    void test_vertcat_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
	}

    void test_vertcat_2 () {
        Matrix<int> x(2, 3);
        Matrix<int> y(3, 3);
        Matrix<int> z(5, 3);
        x = vertcat(x, y);

        CPPUNIT_ASSERT(x.eq(z));
	}

    void test_vertcat_3 () {
        Matrix<int> x(4, 5, 7);
        Matrix<int> y(8, 5, 7);
        Matrix<int> z(12, 5, 7);
        x = vertcat(x, y);

        CPPUNIT_ASSERT(x.eq(z));
	}

	void test_vertcat_4 () {
        Matrix<int> x(1, 3);
        Matrix<int> y(1, 1);

		try{
        	x = vertcat(x, y);
			CPPUNIT_ASSERT(false);
		}catch(...)	{
			CPPUNIT_ASSERT(true);
		}
	}

    // ---------
    // test_diag
    // ---------

    void test_diag_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
	}

	void test_diag_2 () {
        Matrix<int> x(3, 3);
        Matrix<int> y(1, 3);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
	}

	void test_diag_3 () {
        Matrix<int> x(3, 3, 3);
        Matrix<int> y(1, 3, 3);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
	}

	void test_diag_4 () {
        Matrix<int> x(3, 4, 3);
        try{
        	x = diag(x);
			CPPUNIT_ASSERT(false);
		}catch(...){
			CPPUNIT_ASSERT(true);
		}
	}

    // --------
    // test_dot
    // --------

    void test_dot_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
	}

	void test_dot_2 () {
        Matrix<int> x(3, 1);
        Matrix<int> y(3, 1);
        Matrix<int> z(1, 1, 0);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
	}

	void test_dot_3 () {
        Matrix<int> x(2, 1, 5);
        Matrix<int> y(2, 1, 2);
        Matrix<int> z(1, 1, 20);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
	}

	void test_dot_4 () {
        Matrix<int> x(2, 1, 5);
        Matrix<int> y(2, 1, 2);

        try{
            x = dot(x, y);;
			CPPUNIT_ASSERT(false);
		}catch(...){
			CPPUNIT_ASSERT(true);
		}
	}


    // --------
    // test_eye
    // --------

    void test_eye_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = eye< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(!x.eq(y));
	}

	void test_eye_2 () {
        Matrix<int> x;
        Matrix<int> y(3, 3, 0);
		y[0][0] = 1;
		y[1][1] = 1;
		y[2][2] = 1;
        x = eye< Matrix<int> >(3, 3);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_eye_3 () {
        Matrix<int> x;
        Matrix<int> y(1, 20, 1);
        x = eye< Matrix<int> >(20, 20);
		x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_eye_4 () {
        Matrix<int> x;
        try{
            x = eye< Matrix<int> >(-1, 0);
			CPPUNIT_ASSERT(false);
		}catch(...){
			CPPUNIT_ASSERT(true);
		}
	}

    // -------------
    // test_linsolve
    // -------------

    void test_linsolve () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = linsolve(x, y);
        CPPUNIT_ASSERT(x.eq(z));
	}

    // ---------
    // test_ones
    // ---------

    void test_ones_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(!x.eq(y));
	}

    void test_ones_2 () {
        Matrix<int> x;
        Matrix<int> y(5, 5, 2);
        x = ones< Matrix<int> >(5, 5);
        CPPUNIT_ASSERT(!x.eq(y));
	}

    void test_ones_3 () {
        Matrix<int> x;
        Matrix<int> y(16, 18, 1);
        x = ones< Matrix<int> >(16, 18);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_ones_4 () {
        Matrix<int> x;
        try{
            x = ones< Matrix<int> >(-1, 0);
			CPPUNIT_ASSERT(false);
		}catch(...){
			CPPUNIT_ASSERT(true);
		}
	}

    // ---------
    // test_rand
    // ---------

    void test_rand_1 () {
        Matrix<int> x;
        Matrix<int> y(3, 3);
        x = rand< Matrix<int> >(3, 3);
        CPPUNIT_ASSERT(!x.eq(y));
	}

    void test_rand_2 () {
        Matrix<int> x;
        Matrix<int> y(5, 5);
        x = rand< Matrix<int> >(5, 5);
        CPPUNIT_ASSERT(!x.eq(y));
	}

    void test_rand_3 () {
        Matrix<int> x;
        Matrix<int> y;
        x = rand< Matrix<int> >(10, 10);
        CPPUNIT_ASSERT(!x.eq(y));
	}

    void test_rand_4 () {
        Matrix<int> x;
        try{
            x = rand< Matrix<int> >(-1, 0);
			CPPUNIT_ASSERT(false);
		}catch(...){
			CPPUNIT_ASSERT(true);
		}
	}

    // --------------
    // test_transpose
    // --------------

    void test_transpose_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_transpose_2 () {
        Matrix<int> x(1, 2);
        Matrix<int> y(2, 1);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_transpose_3 () {
        Matrix<int> x(4, 6, 1);
        Matrix<int> y(6, 4, 1);
		x[2][3] = 7;
		y[3][2] = 7;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
	}

    // ---------
    // test_tril
    // ---------

    void test_tril_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_tril_2 () {
        Matrix<int> x(2,2,1);
        Matrix<int> y(2,2,0);
		y[1][0] = 1;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_tril_3 () {
        Matrix<int> x(2,3);
		try{
        	x = tril(x);
			CPPUNIT_ASSERT(false);
		}catch(...){
			CPPUNIT_ASSERT(true);
		}
	}

    // ---------
    // test_triu
    // ---------

    void test_triu_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_triu_2 () {
        Matrix<int> x(2,2,1);
        Matrix<int> y(2,2,0);
		y[0][1] = 1;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_triu_3 () {
        Matrix<int> x(2,3);
		try{
        	x = triu(x);
			CPPUNIT_ASSERT(false);
		}catch(...){
			CPPUNIT_ASSERT(true);
		}
	}

    // ----------
    // test_zeros
    // ----------

    void test_zeros_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(!x.eq(y));}

    void test_zeros_2 () {
        Matrix<int> x;
        Matrix<int> y(5, 5, 2);
        x = zeros< Matrix<int> >(5, 5);
        CPPUNIT_ASSERT(!x.eq(y));
	}

    void test_zeros_3 () {
        Matrix<int> x;
        Matrix<int> y(16, 18, 0);
        x = zeros< Matrix<int> >(16, 18);
        CPPUNIT_ASSERT(x.eq(y));
	}

    void test_zeros_4 () {
        Matrix<int> x;
        try{
            x = zeros< Matrix<int> >(-1, 0);
			CPPUNIT_ASSERT(false);
		}catch(...){
			CPPUNIT_ASSERT(true);
		}
	}


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat_1);
    CPPUNIT_TEST(test_horzcat_2);
    CPPUNIT_TEST(test_horzcat_3);
    CPPUNIT_TEST(test_horzcat_4);
    CPPUNIT_TEST(test_vertcat_1);
    CPPUNIT_TEST(test_vertcat_2);
    CPPUNIT_TEST(test_vertcat_3);
    CPPUNIT_TEST(test_vertcat_4);
    CPPUNIT_TEST(test_diag_1);
    CPPUNIT_TEST(test_diag_2);
    CPPUNIT_TEST(test_diag_3);
	CPPUNIT_TEST(test_diag_4);
	CPPUNIT_TEST(test_dot_1);
	CPPUNIT_TEST(test_dot_2);
	CPPUNIT_TEST(test_dot_3);
	CPPUNIT_TEST(test_dot_4);
    CPPUNIT_TEST(test_eye_1);
    CPPUNIT_TEST(test_eye_2);
    CPPUNIT_TEST(test_eye_3);
    //CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_ones_1);
    CPPUNIT_TEST(test_ones_2);
    CPPUNIT_TEST(test_ones_3);
    CPPUNIT_TEST(test_rand_1);
    CPPUNIT_TEST(test_rand_2);
    CPPUNIT_TEST(test_rand_3);
    CPPUNIT_TEST(test_rand_4);
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
    CPPUNIT_TEST(test_zeros_4);
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
