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
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_horzcat2 () {
        Matrix<int> x(1,1,1);
        Matrix<int> y(1,1,2);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x[0][0] = 1);
        CPPUNIT_ASSERT(x[0][1] = 2);}


    void test_vertcat () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat2 () {
        Matrix<int> x(1,1,1);
        Matrix<int> y(1,1,2);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x[0][0] = 1);
        CPPUNIT_ASSERT(x[1][0] = 2);
    }

    // ---------
    // test_diag
    // ---------

    void test_diag () {
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}


    void test_diag2 () {
        Matrix<int> x(1,1,1);
        Matrix<int> y(1,1,1);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag3 () {
        Matrix<int> x(2,2,2);
        Matrix<int> y(2,1);
        y[0][0] = 2;
        y[1][0] = 2;
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

    void test_dot2 () {
        Matrix<int> x(1,2,2);
        Matrix<int> y(1,2,2);
        x = dot(x, y);
        CPPUNIT_ASSERT(x[0][0] == 8);}

    // --------
    // test_eye
    // --------

    void test_eye () {
        Matrix<int> x;
        Matrix<int> y;
        x = eye< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_eye2 () {
        Matrix<int> x(2,3);
        Matrix<int> y;
        x[0][0] = 1;
        x[1][1] = 1;
        y = eye< Matrix<int> >(2, 3);
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
        Matrix<int> y;
        x = ones< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_ones2 () {
        Matrix<int> x;
        Matrix<int> y(2,3,1);
        x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}



    // ---------
    // test_rand
    // ---------

    void test_rand () {
        Matrix<int> x;
        Matrix<int> y;
        x = rand< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_rand2 () {
        Matrix<double> x(5, 5);
        Matrix<double> y(5, 5, 1.1);
        x = rand< Matrix<double> >(5, 5);
        CPPUNIT_ASSERT(x[0][0] < y[0][0]);
        CPPUNIT_ASSERT(x[4][4] < y[4][4]);
    }


    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

void test_transpose2 () {
        Matrix<int> x(2,2);
        x[0][0] = 1;
        x[0][1] = 2;
        x[1][0] = 3;
        x[1][1] = 4;
        Matrix<int> y(2,2);
        y[0][0] = 1;
        y[0][1] = 3;
        y[1][0] = 2;
        y[1][1] = 4;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}


    // ---------
    // test_tril
    // ---------

    void test_tril () {
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_tril2 () {
        Matrix<int> x(3,2,1);
        Matrix<int> y(3,2,1);
        y[0][1] = 0;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_triu2 () {
        Matrix<int> x(3,2,1);
        Matrix<int> y(3,2,1);
        y[1][0] = 0;
        y[2][0] = 0;
        y[2][1] = 0;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}


    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}


void test_zeros2 () {
        Matrix<int> x;
        Matrix<int> y(2,2,0);
        x = zeros< Matrix<int> >(2, 2);
        CPPUNIT_ASSERT(x.eq(y));}


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);

    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(test_horzcat2);
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(test_vertcat2);
    CPPUNIT_TEST(test_diag);
    CPPUNIT_TEST(test_diag2);
    CPPUNIT_TEST(test_diag3);
    CPPUNIT_TEST(test_dot);
    CPPUNIT_TEST(test_dot2);
    CPPUNIT_TEST(test_eye);
    CPPUNIT_TEST(test_eye2);
    //CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_ones);
    CPPUNIT_TEST(test_ones2);
    CPPUNIT_TEST(test_rand);
    CPPUNIT_TEST(test_rand2);
    CPPUNIT_TEST(test_transpose);
    CPPUNIT_TEST(test_transpose2);
    CPPUNIT_TEST(test_tril);
    CPPUNIT_TEST(test_tril2);
    CPPUNIT_TEST(test_triu);
    CPPUNIT_TEST(test_triu2);
    CPPUNIT_TEST(test_zeros);
    CPPUNIT_TEST(test_zeros2);

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
