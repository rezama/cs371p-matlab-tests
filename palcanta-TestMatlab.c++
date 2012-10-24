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

    void test_horzcat () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
	x = horzcat(x,y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_horzcat_2 () {
        Matrix<int> x(1,1,1);
        Matrix<int> y(1,1,1);
        Matrix<int> z(1,2,1);
	x = horzcat(x,y);
        CPPUNIT_ASSERT(x.eq(z));}
    void test_horzcat_3 () {
        Matrix<int> x(3,2,0);
	x[0][0] = 1;
	x[1][0] = 2;
	x[2][0] = 3;
        Matrix<int> y(3,2,0);
	y[0][0] = 4;
	y[1][0] = 5;
	y[2][0] = 6;
        Matrix<int> z(3,4,0);
	x = horzcat(x,y);
	z[0][0] = 1;
	z[1][0] = 2;
	z[2][0] = 3;
	z[0][2] = 4;
	z[1][2] = 5;
	z[2][2] = 6;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
 
   void test_vertcat_2 () {
        Matrix<int> x(1,2,0);
	x[0][0] = 42;
	x[0][1] = 24;
        Matrix<int> y(1,2,0);
	y[0][0] = 1337;
	y[0][1] = 7331;
        Matrix<int> z(2,2,0);
	z[0][0] = 42;
	z[0][1] = 24;
	z[1][0] = 1337;
	z[1][1] = 7331;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat_3 () {
        Matrix<int> x(2,2,0);
	x[0][0] = 1;
	x[0][1] = 2;
	x[1][0] = 3;
	x[1][1] = 4;
        Matrix<int> y(2,2,0);
	y[0][0] = 5;
	y[0][1] = 6;
	y[1][0] = 7;
	y[1][1] = 8;
        Matrix<int> z(4,2,0);
	z[0][0] = 1;
	z[0][1] = 2;
	z[1][0] = 3;
	z[1][1] = 4;
	z[2][0] = 5;
	z[2][1] = 6;
	z[3][0] = 7;
	z[3][1] = 8;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
    // ---------
    // test_diag
    // ---------

    void test_diag () {
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}
        
	void test_diag_2() {
		Matrix<int> x(1,3,2);
		Matrix<int> y;
		Matrix<int> result(3,3,0);
		result[0][0] = 2;
		result[1][1] = 2;
		result[2][2] = 2;
		y = diag(x);
		CPPUNIT_ASSERT(result.eq(y));
	}
	
    void test_diag_3 () {
        Matrix<int> x(3,2,0);
	x[0][0] = 1;
	x[0][1] = 2;
	x[1][0] = 3;
	x[1][1] = 4;
	x[2][0] = 5;
	x[2][1] = 6;
        Matrix<int> y(2,1,0);
	y[0][0] = 1;
	y[1][0] = 4;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}


    // --------
    // test_dot
    // --------

    void test_dot () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_2 () {
        Matrix<int> x(3,2,0);
	x[0][0] = 1;
	x[0][1] = 2;
	x[1][0] = 3;
	x[1][1] = 4;
	x[2][0] = 5;
	x[2][1] = 6;
        Matrix<int> y(3,2,0);
	y[0][0] = 7;
	y[0][1] = 8;
	y[1][0] = 9;
	y[1][1] = 10;
	y[2][0] = 11;
	y[2][1] = 12;
        Matrix<int> z(1,2,0);
	z[0][0] = 89;
	z[0][1] = 128;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}


    void test_dot_3 () {
        Matrix<int> x(2,2,0);
        Matrix<int> y(4,4,0);
        Matrix<int> z;
	try{	
        	x = dot(x, y);
		CPPUNIT_ASSERT(false);
	}
	catch(std::invalid_argument& e){
		CPPUNIT_ASSERT(true);
	}
    }
    // --------
    // test_eye
    // --------

    void test_eye () {
        Matrix<int> x;
        Matrix<int> y(2,3,0);
        y[0][0] = 1;
        y[1][1] = 1;
        x = eye< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}
        
	void test_eye_2 (){
		Matrix<int> x;
		try{
	        x = eye< Matrix<int> >(-2, -3);
	        CPPUNIT_ASSERT(false);
		}
		catch(std::invalid_argument& e){
			CPPUNIT_ASSERT(true);
		}
	}

    void test_eye_3 () {
        Matrix<int> x;
        Matrix<int> y(5,4,0);
	y[0][0] = 1;
	y[1][1] = 1;
	y[2][2] = 1;
	y[3][3] = 1;
        x = eye< Matrix<int> >(5, 4);
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

    void test_ones () {
        Matrix<int> x;
        Matrix<int> y(2,3,1);
        x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_ones_2 () {
        Matrix<int> x;
        Matrix<int> y(3,3,0);
	y[0][0] = 1;
	y[0][1] = 1;
	y[0][2] = 1;
	y[1][0] = 1;
	y[1][1] = 1;
	y[1][2] = 1;
	y[2][0] = 1;
	y[2][1] = 1;
	y[2][2] = 1;
        x = ones< Matrix<int> >(3, 3);
        CPPUNIT_ASSERT(x.eq(y));}
    void test_ones_3 () {
        Matrix<int> x;
       	try{ 
		x = ones< Matrix<int> >(-2, -3);
		CPPUNIT_ASSERT(false);
	}
	catch(std::invalid_argument& e){
		CPPUNIT_ASSERT(true);
	}
    }
    // ---------
    // test_rand
    // ---------

    void test_rand () {
        Matrix<double> x;
        x = rand< Matrix<double> >(2, 3);
        for(unsigned int i = 0; i < x.size(); i++){
        	for(unsigned int j = 0; j < x[0].size(); j++){
        		CPPUNIT_ASSERT(x[i][j] >= 0 && x[i][j] <= 1);
        	}
        }
    }
    void test_rand_2(){
	Matrix<double> x;
	x = rand< Matrix<double> >(4,2);
        for(unsigned int i = 0; i < x.size(); i++){
        	for(unsigned int j = 0; j < x[0].size(); j++){
        		CPPUNIT_ASSERT(x[i][j] >= 0 && x[i][j] <= 1);
        	}
        }
    }
    void test_rand_3(){
       	try{ 
		Matrix<double> x;
		x = rand< Matrix<double> >(-2, -2);
		CPPUNIT_ASSERT(false);
	}
	catch(std::invalid_argument& e){
		CPPUNIT_ASSERT(true);
	}
    }

    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x = eye< Matrix<int> >(2,3);
        Matrix<int> y = eye< Matrix<int> >(3,2);
        
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_transpose_2 () {
        Matrix<int> x (3,2);
	x[0][0] = 1;
	x[0][1] = 2;
	x[1][0] = 3;
	x[1][1] = 4;
	x[2][0] = 5;
	x[2][1] = 6;
        Matrix<int> y (2,3);
	y[0][0] = 1;
	y[0][1] = 3;
	y[0][2] = 5;
	y[1][0] = 2;
	y[1][1] = 4;
	y[1][2] = 6;	 
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}
   void test_transpose_3(){
	Matrix<int> x (2,3);
	x[0][0] = 1;
	x[0][1] = 2;
	x[0][2] = 3;
	x[1][0] = 4;
	x[1][1] = 5;
	x[1][2] = 6;
	Matrix<int> y(3,2);
	y[0][0] = 1;
	y[0][1] = 4;
	y[1][0] = 2;
	y[1][1] = 5;
	y[2][0] = 3;
	y[2][1] = 6;	
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}
    // ---------
    // test_tril
    // ---------

    void test_tril () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y = tril(x);
		Matrix<int> z(2,2,1);
		z[0][1] = 0;
        CPPUNIT_ASSERT(y.eq(z));}

    void test_tril_2 () {
        Matrix<int> x(4, 5, 0);
	int count = 0;
	for(unsigned int i=0;i<x.size();i++)
		for(unsigned int j=0;j<x[0].size();j++)
			x[i][j] = ++count;	
        Matrix<int> y = tril(x);
	Matrix<int> z(4,5,0);
       	z[0][0] = 1;
	z[1][0] = 6;
	z[1][1] = 7;
	z[2][0] = 11;
	z[2][1] = 12;
	z[2][2] = 13;
	z[3][0] = 16;
	z[3][1] = 17;
	z[3][2] = 18;
	z[3][3] = 19;
	CPPUNIT_ASSERT(y.eq(z));}
    void test_tril_3 () {
        Matrix<int> x(4, 3, 0);
	int count = 0;
	for(unsigned int i=0;i<x.size();i++)
		for(unsigned int j=0;j<x[0].size();j++)
			x[i][j] = ++count;	
        Matrix<int> y = tril(x);
	Matrix<int> z(4,3,0);
	z[0][0] = 1;
	z[1][0] = 4;
	z[1][1] = 5;
	z[2][0] = 7;
	z[2][1] = 8;
	z[2][2] = 9;
	z[3][0] = 10;
	z[3][1] = 11;
	z[3][2] = 12;
        CPPUNIT_ASSERT(y.eq(z));}
    // ---------
    // test_triu
    // ---------

    void test_triu () {
       Matrix<int> x(2, 2, 1);
        Matrix<int> y = triu(x);
		Matrix<int> z(2,2,1);
		z[1][0] = 0;
        CPPUNIT_ASSERT(y.eq(z));}
    void test_triu_2 () {
       Matrix<int> x(3, 4, 0);
	int count = 0;
	for(unsigned int i=0;i<x.size();i++)
		for(unsigned int j=0;j<x[0].size();j++)
			x[i][j] = ++count;	
        Matrix<int> y = triu(x);
	Matrix<int> z(3,4,0);
	z[0][0] = 1;
	z[0][1] = 2;
	z[0][2] = 3;
	z[0][3] = 4;
	z[1][1] = 6;
	z[1][2] = 7;
	z[1][3] = 8;
	z[2][2] = 11;
	z[2][3] = 12;
        CPPUNIT_ASSERT(y.eq(z));}
    void test_triu_3 () {
       Matrix<int> x(4, 3, 0);
	int count = 0;
	for(unsigned int i=0;i<x.size();i++)
		for(unsigned int j=0;j<x[0].size();j++)
			x[i][j] = ++count;	
        Matrix<int> y = triu(x);
	Matrix<int> z(4,3,0);
	z[0][0] = 1;
	z[0][1] = 2;
	z[0][2] = 3;
	z[1][1] = 5;
	z[1][2] = 6;
	z[2][2] = 9;
        CPPUNIT_ASSERT(y.eq(z));}

    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x(5, 5, 5);
        Matrix<int> y(5, 5, 0);
        x = zeros< Matrix<int> >(5, 5);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_zeros_2 () {
        Matrix<int> x(2, 3, -24);
        Matrix<int> y(2, 3, -1);
	y[0][0] = 0;
	y[0][1] = 0;
	y[0][2] = 0;
	y[1][0] = 0;
	y[1][1] = 0;
	y[1][2] = 0;
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}
    void test_zeros_3 () {
        Matrix<int> x(5, 5, 5);
        Matrix<int> y(5, 5, 0);
	try{
        	x = zeros< Matrix<int> >(-5, -5);
		CPPUNIT_ASSERT(false);
	}
	catch(std::invalid_argument& e){
		CPPUNIT_ASSERT(true);
	}
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(test_horzcat_2);
    CPPUNIT_TEST(test_horzcat_3);
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(test_vertcat_2);
    CPPUNIT_TEST(test_vertcat_3);
    CPPUNIT_TEST(test_diag);
    CPPUNIT_TEST(test_diag_2);
    CPPUNIT_TEST(test_diag_3);
    CPPUNIT_TEST(test_dot);
    CPPUNIT_TEST(test_dot_2);
    CPPUNIT_TEST(test_dot_3);
    CPPUNIT_TEST(test_eye);
    CPPUNIT_TEST(test_eye_2);
    CPPUNIT_TEST(test_eye_3);
//    CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_ones);
    CPPUNIT_TEST(test_ones_2);
    CPPUNIT_TEST(test_ones_3);
    CPPUNIT_TEST(test_rand);
    CPPUNIT_TEST(test_rand_2);
    CPPUNIT_TEST(test_rand_3);
    CPPUNIT_TEST(test_transpose);
    CPPUNIT_TEST(test_transpose_2);
    CPPUNIT_TEST(test_transpose_3);
    CPPUNIT_TEST(test_tril);
    CPPUNIT_TEST(test_tril_2);
    CPPUNIT_TEST(test_tril_3);
    CPPUNIT_TEST(test_triu);
    CPPUNIT_TEST(test_triu_2);
    CPPUNIT_TEST(test_triu_3);
    CPPUNIT_TEST(test_zeros);
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
