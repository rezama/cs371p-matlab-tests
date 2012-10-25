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

    void test_horzcat_errors () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z(1,1);
		Matrix<int> a(2,1);
		try{
			horzcat(x,y);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			horzcat(x,z);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			horzcat(z,a);	// Rows not the same size
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
    }
	
	void test_horzcat_valid () {
        Matrix<int> x(1,1);
        Matrix<int> y(1,1);
        Matrix<int> z(1,2);
		Matrix<int> a = horzcat(x,y);
		CPPUNIT_ASSERT(a.eq(z));
	}

	void test_horzcat () {
        Matrix<int> x(2,2,1);
        Matrix<int> y(2,1,2);
        Matrix<int> z(2,3,1);
		z[0][2] = 2;
		z[1][2] = 2;
		Matrix<int> a = horzcat(x,y);
		CPPUNIT_ASSERT(a.eq(z));
	}

    void test_vertcat_errors () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z(1,1);
		Matrix<int> a(1,2);
		try{
			vertcat(x,y);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			vertcat(x,z);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			vertcat(z,a);	// cols not the same size
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
    }

	void test_vertcat_valid () {
        Matrix<int> x(1,1);
        Matrix<int> y(1,1);
        Matrix<int> z(2,1);
		Matrix<int> a = vertcat(x,y);
		CPPUNIT_ASSERT(a.eq(z));
	}

	void test_vertcat () {
        Matrix<int> x(2,2,1);
        Matrix<int> y(1,2,2);
        Matrix<int> z(3,2,1);
		z[2][0] = 2;
		z[2][1] = 2;
		Matrix<int> a = vertcat(x,y);
		CPPUNIT_ASSERT(a.eq(z));
	}


    // ---------
    // test_diag
    // ---------

  void test_diag_errors () {
        Matrix<int> x;
        Matrix<int> z(1,1);
		try{
			diag(x);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			diag(z);		
		}
		catch(exception& e){
			CPPUNIT_ASSERT(false);
		}
    }

	void test_diag_valid () {
        Matrix<int> x(1,1,1);
        Matrix<int> y(2,1,1);
		Matrix<int> z(2,2,1);
		Matrix<int> a = diag(x);
		CPPUNIT_ASSERT(a.eq(x));
		a = diag(y);
		CPPUNIT_ASSERT(a.eq(x));
		a = diag(z);
		CPPUNIT_ASSERT(a.eq(y));
	}

	void test_diag () {
        Matrix<int> x(1,100,1);
        Matrix<int> y(100,1,1);
		Matrix<int> z(1,1,1);
		Matrix<int> a = diag(x);
		CPPUNIT_ASSERT(a.eq(z));
		a = diag(y);
		CPPUNIT_ASSERT(a.eq(z));
	}

    // --------
    // test_dot
    // --------

    void test_dot_errors () {
        Matrix<int> x;
		Matrix<int> y;
        Matrix<int> z(1,1);
		Matrix<int> a(2,2);
		Matrix<int> w(1,2);
		try{
			dot(x,y);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			dot(x,z);	
			CPPUNIT_ASSERT(false);	
		}
		catch(exception& e){			
		}

		try{
			dot(a,z);	
			CPPUNIT_ASSERT(false);	
		}
		catch(exception& e){
		}
	
		try{
			dot(w,z);	
			CPPUNIT_ASSERT(false);	
		}
		catch(exception& e){			
		}
    }

	void test_dot_valid () {
        Matrix<int> x(1,1,1);
        Matrix<int> y(1,1,2);
		Matrix<int> z(1,2,1);
		Matrix<int> w(2,1,1);
		Matrix<int> a = dot(x,y);
		CPPUNIT_ASSERT(a.eq(y));
		a = dot(z,w);
		CPPUNIT_ASSERT(a.eq(y));
	}

	void test_dot () {
        Matrix<int> x(3,1,5);
        Matrix<int> y(1,3,2);
		Matrix<int> z(1,1,30);
		Matrix<int> a = dot(x,y);
		CPPUNIT_ASSERT(a.eq(z));
	}

    // --------
    // test_eye
    // --------

   void test_eye_errors () {
        Matrix<int> x;
		try{
			x = eye< Matrix<int> >(0,0);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			x = eye< Matrix<int> >(1,0);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			x = eye< Matrix<int> >(0,1);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
    }

	void test_eye_valid () {
        Matrix<int> x;
		Matrix<int> z(1,1,1);
		Matrix<int> w(2,2,0);
		w[0][0] = 1;
		w[1][1] = 1;
		x = eye< Matrix<int> >(1,1);
		CPPUNIT_ASSERT(x.eq(z));
		x = eye< Matrix<int> >(2,2);
		CPPUNIT_ASSERT(x.eq(w));
	}

	void test_eye () {
        Matrix<int> x;
		Matrix<int> z(1,2,0);
		z[0][0] = 1;
		Matrix<int> w(3,2,0);
		w[0][0] = 1;
		w[1][1] = 1;
		x = eye< Matrix<int> >(1,2);
		CPPUNIT_ASSERT(x.eq(z));
		x = eye< Matrix<int> >(3,2);
		CPPUNIT_ASSERT(x.eq(w));
	}

    // -------------
    // test_linsolve
    // -------------

    void test_linsolve () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        //x = linsolve(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------
    // test_ones
    // ---------

    void test_ones_errors () {
        Matrix<int> x;
		try{
			x = ones< Matrix<int> >(0,0);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			x = ones< Matrix<int> >(1,0);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			x = ones< Matrix<int> >(0,1);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
    }

	void test_ones_valid () {
        Matrix<int> x;
		Matrix<int> z(1,1,1);
		Matrix<int> w(2,2,1);
		x = ones< Matrix<int> >(1,1);
		CPPUNIT_ASSERT(x.eq(z));
		x = ones< Matrix<int> >(2,2);
		CPPUNIT_ASSERT(x.eq(w));
	}

	void test_ones () {
        Matrix<int> x;
		Matrix<int> z(1,2,1);
		Matrix<int> w(3,2,1);
		x = ones< Matrix<int> >(1,2);
		CPPUNIT_ASSERT(x.eq(z));
		x = ones< Matrix<int> >(3,2);
		CPPUNIT_ASSERT(x.eq(w));
	}

    // ---------
    // test_rand
    // ---------

    void test_rand_errors () {
        Matrix<double> x;
		try{
			x = rand< Matrix<double> >(0,0);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			x = rand< Matrix<double> >(1,0);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			x = rand< Matrix<double> >(0,1);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
    }

	void test_rand_valid () {
        Matrix<double> x;;
		x = rand< Matrix<double> >(1,1);
		CPPUNIT_ASSERT(x.size() == 1);
		x = rand< Matrix<double> >(2,2);
		CPPUNIT_ASSERT(x.size() == 2 && x[0].size() == 2);
	}

	void test_rand () {
        Matrix<double> x;
		x = rand< Matrix<double> >(1,2);
		CPPUNIT_ASSERT(x.size() == 1 && x[0].size() == 2);
		x = rand< Matrix<double> >(3,2);
		CPPUNIT_ASSERT(x.size() == 3 && x[0].size() == 2);
	}

    // --------------
    // test_transpose
    // --------------

    void test_transpose_errors () {
        Matrix<int> x;
        Matrix<int> y(0,1);
 		Matrix<int> z(1,0);
		try{
			transpose(x);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			transpose(y);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
	
		try{
			transpose(z);	
			CPPUNIT_ASSERT(false);	
		}
		catch(exception& e){			
		}
	}

	void test_transpose_valid () {
	    Matrix<int> x(1,1,1);
		Matrix<int> a = transpose(x);
		CPPUNIT_ASSERT(a.eq(x));
	}

	void test_transpose () {
	    Matrix<int> x(4,1,1);
		Matrix<int> y(1,4,1);
		Matrix<int> a = transpose(x);
		CPPUNIT_ASSERT(a.eq(y));
	}

    // ---------
    // test_tril
    // ---------

    
    void test_tril_errors () {
        Matrix<int> x;
        Matrix<int> y(0,1);
 		Matrix<int> z(1,0);
		try{
			tril(x);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			tril(y);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
	
		try{
			tril(z);	
			CPPUNIT_ASSERT(false);	
		}
		catch(exception& e){			
		}
	}

	void test_tril_valid () {
	    Matrix<int> x(1,1,1);
		Matrix<int> a = tril(x);
		CPPUNIT_ASSERT(a.eq(x));
	}

	void test_tril () {
	    Matrix<int> x(2,2,1);
		Matrix<int> y(2,2,1);
		y[0][1] = 0;
		Matrix<int> a = tril(x);
		CPPUNIT_ASSERT(a.eq(y));
	}

    // ---------
    // test_triu
    // ---------

    void test_triu_errors () {
        Matrix<int> x;
        Matrix<int> y(0,1);
 		Matrix<int> z(1,0);
		try{
			triu(x);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			triu(y);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
	
		try{
			triu(z);	
			CPPUNIT_ASSERT(false);	
		}
		catch(exception& e){			
		}
	}

	void test_triu_valid () {
	    Matrix<int> x(1,1,1);
		Matrix<int> a = triu(x);
		CPPUNIT_ASSERT(a.eq(x));
	}

	void test_triu () {
	    Matrix<int> x(2,2,1);
		Matrix<int> y(2,2,1);
		y[1][0] = 0;
		Matrix<int> a = triu(x);
		CPPUNIT_ASSERT(a.eq(y));
	}


    // ----------
    // test_zeros
    // ----------

    void test_zeros_errors () {
        Matrix<int> x;
		try{
			x = zeros< Matrix<int> >(0,0);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			x = zeros< Matrix<int> >(1,0);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}

		try{
			x = zeros< Matrix<int> >(0,1);
			CPPUNIT_ASSERT(false);
		}
		catch(exception& e){
		}
    }

	void test_zeros_valid () {
        Matrix<int> x;
		Matrix<int> z(1,1,0);
		Matrix<int> w(2,2,0);
		x = zeros< Matrix<int> >(1,1);
		CPPUNIT_ASSERT(x.eq(z));
		x = zeros< Matrix<int> >(2,2);
		CPPUNIT_ASSERT(x.eq(w));
	}

	void test_zeros () {
        Matrix<int> x;
		Matrix<int> z(1,2,0);
		Matrix<int> w(3,2,0);
		x = zeros< Matrix<int> >(1,2);
		CPPUNIT_ASSERT(x.eq(z));
		x = zeros< Matrix<int> >(3,2);
		CPPUNIT_ASSERT(x.eq(w));
	}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat_errors);
	CPPUNIT_TEST(test_horzcat_valid);
	CPPUNIT_TEST(test_horzcat);
	CPPUNIT_TEST(test_vertcat_errors);
	CPPUNIT_TEST(test_vertcat_valid);
    CPPUNIT_TEST(test_vertcat);
	CPPUNIT_TEST(test_diag_errors);
	CPPUNIT_TEST(test_diag_valid);
    CPPUNIT_TEST(test_diag);
	CPPUNIT_TEST(test_dot_errors);
	CPPUNIT_TEST(test_dot_valid);
    CPPUNIT_TEST(test_dot);
    CPPUNIT_TEST(test_eye_errors);
	CPPUNIT_TEST(test_eye_valid);
    CPPUNIT_TEST(test_eye);
    CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_ones_errors);
	CPPUNIT_TEST(test_ones_valid);
    CPPUNIT_TEST(test_ones);
    CPPUNIT_TEST(test_rand_errors);
	CPPUNIT_TEST(test_rand_valid);
    CPPUNIT_TEST(test_rand);
    CPPUNIT_TEST(test_transpose_errors);
	CPPUNIT_TEST(test_transpose_valid);
    CPPUNIT_TEST(test_transpose);
    CPPUNIT_TEST(test_tril_errors);
    CPPUNIT_TEST(test_tril_valid);
    CPPUNIT_TEST(test_tril);
    CPPUNIT_TEST(test_triu_errors);
	CPPUNIT_TEST(test_triu_valid);
    CPPUNIT_TEST(test_triu);
    CPPUNIT_TEST(test_zeros_errors);
	CPPUNIT_TEST(test_zeros_valid);
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
    tr.addTest(TestMatlab::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
