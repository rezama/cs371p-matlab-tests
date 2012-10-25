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
	try{
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
        Matrix<int> x1(2, 2, 4);
        Matrix<int> y1(2, 3, 4);
        Matrix<int> z1(2, 5, 4);
        x1 = horzcat(x1, y1);
        CPPUNIT_ASSERT(x1.eq(z1));
        Matrix<int> x2(5, 3, 1);
        Matrix<int> y2(5, 2, 1);
        Matrix<int> z2(5, 5, 1);
        x2 = horzcat(x2, y2);
        CPPUNIT_ASSERT(x2.eq(z2));}
	catch(std::invalid_argument& a){
		std::cout << "Caught exception" << std::endl;}
     }



    void test_vertcat () {
	try{
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
        Matrix<int> x1(2, 2, 4);
        Matrix<int> y1(2, 2, 4);
        Matrix<int> z1(4, 2, 4);
        x1 = vertcat(x1, y1);
        CPPUNIT_ASSERT(x1.eq(z1));
        Matrix<int> x2(2, 3, 1);
        Matrix<int> y2(5, 3, 1);
        Matrix<int> z2(7, 3, 1);
        x2 = vertcat(x2, y2);
        CPPUNIT_ASSERT(x2.eq(z2));}
	  catch(std::invalid_argument& a){
		std::cout << "Caught exception" << std::endl;}
     }



    // ---------
    // test_diag
    // ---------

    void test_diag () {
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
        Matrix<int> x1(1, 1, 5);
        Matrix<int> y1(1, 1, 5);
        x1 = diag(x1);
        CPPUNIT_ASSERT(x1.eq(y1));
        Matrix<int> x2(4, 1, 1);
        Matrix<int> y2(4, 4, 0);
		y2 = diag(x2);
        x2 = diag(x2);
        CPPUNIT_ASSERT(x2.eq(y2));}



    // --------
    // test_dot
    // --------

    void test_dot () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
        Matrix<int> x1(1, 1, 1);
        Matrix<int> y1(1, 1, 2);
        Matrix<int> z1(1, 1, 2);
        x1 = dot(x1, y1);
        CPPUNIT_ASSERT(x1.eq(z1));
        Matrix<int> x2(2, 2, 2);
        Matrix<int> y2(2, 2, 2);
        Matrix<int> z2(2, 2, 4);
        x2 = dot(x2, y2);
        CPPUNIT_ASSERT(x2.eq(z2));}

    // --------
    // test_eye
    // --------

    void test_eye () {
        Matrix<int> x;
        Matrix<int> y;
        x = eye< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
        Matrix<int> x1;
        Matrix<int> y1(3,1,1);
		y1 = diag(y1);
        x1 = eye< Matrix<int> >(3, 3);
        CPPUNIT_ASSERT(x1.eq(y1));
        Matrix<int> x2;
        Matrix<int> y2(100,1,1);
		y2 = diag(y2);
        x2 = eye< Matrix<int> >(100, 100);
        CPPUNIT_ASSERT(x2.eq(y2));}

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
        CPPUNIT_ASSERT(x.eq(y));
        Matrix<int> x1;
        Matrix<int> y1(10,10,1);
        x1 = ones< Matrix<int> >(10, 10);
        CPPUNIT_ASSERT(x1.eq(y1));
        Matrix<int> x2;
        Matrix<int> y2(100,50,1);
        x2 = ones< Matrix<int> >(100, 50);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_rand
    // ---------

    void test_rand () {
        Matrix<int> x(2, 3, 0);
        Matrix<int> y(2, 3, 0);
        x = rand< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(!x.eq(y));
        Matrix<int> x1(10, 15, 1);
        Matrix<int> y1(10, 15, 1);
        x1 = rand< Matrix<int> >(10, 15);
        CPPUNIT_ASSERT(!x1.eq(y1));
        Matrix<int> x2(100, 100, 0);
        Matrix<int> y2(100, 100, 0);
        x2 = rand< Matrix<int> >(100, 100);
        CPPUNIT_ASSERT(!x2.eq(y2));}

    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
        Matrix<int> x1(2, 3, 1);
        Matrix<int> y1(3, 2, 1);
        x1 = transpose(x1);
        CPPUNIT_ASSERT(x1.eq(y1));
        Matrix<int> x2(5, 5, 5);
        Matrix<int> y2(5, 5, 5);
        x2 = transpose(x2);
        CPPUNIT_ASSERT(x2.eq(y2));}

    // ---------
    // test_tril
    // ---------

    void test_tril () {
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
        Matrix<int> x1(1, 1, 2);
        Matrix<int> y1(1, 1, 2);
        x1 = tril(x1);
        CPPUNIT_ASSERT(x1.eq(y1));
        Matrix<int> x2(2, 2, 3);
        Matrix<int> y2(2, 2, 3);
        y2[0][1] = 0;
        x2 = tril(x2);
        CPPUNIT_ASSERT(x2.eq(y2));}

    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
        Matrix<int> x1(1, 1, 4);
        Matrix<int> y1(1, 1, 4);
        x1 = triu(x1);
        CPPUNIT_ASSERT(x1.eq(y1));
        Matrix<int> x2(3, 3, 1);
        Matrix<int> y2(3, 3, 1);
        y2[1][0] = 0;
 		y2[2][0] = 0;
		y2[2][1] = 0;
        x2 = triu(x2);
        CPPUNIT_ASSERT(x2.eq(y2));}

    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x;
        Matrix<int> y(2,3,0);
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
        Matrix<int> x1;
        Matrix<int> y1(10,10,0);
        x1 = zeros< Matrix<int> >(10, 10);
        CPPUNIT_ASSERT(x1.eq(y1));
        Matrix<int> x2;
        Matrix<int> y2(100,50,0);
        x2 = zeros< Matrix<int> >(100, 50);
        CPPUNIT_ASSERT(x.eq(y));}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(test_diag);
    CPPUNIT_TEST(test_eye);
    CPPUNIT_TEST(test_linsolve);
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
    tr.addTest(TestMatlab::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
