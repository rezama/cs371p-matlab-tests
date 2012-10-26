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
        Matrix<int> x(1, 1);
        Matrix<int> y(1, 1);
        Matrix<int> z(1, 2);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_horzcat_zero () {
        Matrix<int> x(1, 1);
        Matrix<int> y(0, 0);
        Matrix<int> z(1, 1);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_horzcat_values () {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, 2);
        Matrix<int> z(1, 2);
        z[0][0] = 1;
        z[0][1] = 2;
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat () {
        Matrix<int> x(1, 1);
        Matrix<int> y(1, 1);
        Matrix<int> z(2, 1);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat_zero () {
        Matrix<int> x(0, 0);
        Matrix<int> y(1, 1);
        Matrix<int> z(1, 1);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat_values () {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, 2);
        Matrix<int> z(2, 1);
        z[0][0] = 1;
        z[1][0] = 2;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------
    // test_diag
    // ---------

    void test_diag () {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 1);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag_wide () {
        Matrix<int> x(2, 3);
        Matrix<int> y(2, 1);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag_tall () {
        Matrix<int> x(3, 2);
        Matrix<int> y(2, 1);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag_values () {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 1);
        x[0][0] = 1;
        x[1][1] = 2;
        y[0][0] = 1;
        y[1][0] = 2;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    // --------
    // test_dot
    // --------

    void test_dot_zero () {
        Matrix<int> x(1, 1, 0);
        Matrix<int> y(1, 1, 0);
        Matrix<int> z(1, 1, 0);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_one () {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, 1);
        Matrix<int> z(1, 1, 1);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_values () {
        Matrix<int> x(3, 1);
        Matrix<int> y(3, 1);
        Matrix<int> z(1, 1, 32);
        x[0][0] = 1;
        x[1][0] = 2;
        x[2][0] = 3;
        y[0][0] = 4;
        y[1][0] = 5;
        y[2][0] = 6;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    // --------
    // test_eye
    // --------

    void test_eye_negative () {
        Matrix<int> x;
        Matrix<int> y;
        x = eye< Matrix<int> >(-1, -1);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_eye_square () {
        Matrix<int> x;
        Matrix<int> y(2, 2);
        y[0][0] = 1;
        y[1][1] = 1;
        x = eye< Matrix<int> >(2, 2);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_eye_wide () {
        Matrix<int> x;
        Matrix<int> y(2, 3);
        y[0][0] = 1;
        y[1][1] = 1;
        x = eye< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_eye_tall () {
        Matrix<int> x;
        Matrix<int> y(3, 2);
        y[0][0] = 1;
        y[1][1] = 1;
        x = eye< Matrix<int> >(3, 2);
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
        Matrix<int> y(2, 3, 1);
        x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_ones_double () {
        Matrix<double> x;
        Matrix<double> y(2, 3, 1);
        x = ones< Matrix<double> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_ones_negative () {
        Matrix<int> x;
        Matrix<int> y(0, 0, 1);
        x = ones< Matrix<int> >(-1, -1);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_rand
    // ---------

    void test_rand_seed () {
        Matrix<double> x;
        Matrix<double> y;
        srand(0);
        x = rand< Matrix<double> >(3, 3);
        srand(0);
        y = rand< Matrix<double> >(3, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_rand_negative () {
        Matrix<double> x;
        Matrix<double> y;
        x = rand< Matrix<double> >(-1, -1);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_rand_range () {
        Matrix<double> x;
        Matrix<double> y(3, 3, 0.0);
        Matrix<double> z(3, 3, 1.0);
        Matrix<bool>   t(3, 3, true);
        x = rand< Matrix<double> >(3, 3);
        CPPUNIT_ASSERT(t.eq(x >= y));
        CPPUNIT_ASSERT(t.eq(x <= z));}

    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x(1, 2);
        Matrix<int> y(2, 1);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_transpose_zero () {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_transpose_values () {
        Matrix<int> x(2, 3);
        Matrix<int> y(3, 2);
        x[0][0] = 1;
        x[0][1] = 2;
        x[0][2] = 3;
        y[0][0] = 1;
        y[1][0] = 2;
        y[2][0] = 3;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_tril
    // ---------

    void test_tril_zero () {
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_tril_one () {
        Matrix<int> x(1, 1);
        Matrix<int> y(1, 1);
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_tril_two () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        y[0][1] = 0;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_triu
    // ---------

    void test_triu_zero () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_triu_one () {
        Matrix<int> x(1, 1);
        Matrix<int> y(1, 1);
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_triu_two () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        y[1][0] = 0;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x;
        Matrix<int> y(2, 3, 0);
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_zeros_double () {
        Matrix<double> x;
        Matrix<double> y(2, 3, 0);
        x = zeros< Matrix<double> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_zeros_negative () {
        Matrix<int> x;
        Matrix<int> y(0, 0, 0);
        x = zeros< Matrix<int> >(-1, -1);
        CPPUNIT_ASSERT(x.eq(y));}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(test_horzcat_zero);
    CPPUNIT_TEST(test_horzcat_values);
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(test_vertcat_zero);
    CPPUNIT_TEST(test_vertcat_values);
    CPPUNIT_TEST(test_diag);
    CPPUNIT_TEST(test_diag_wide);
    CPPUNIT_TEST(test_diag_tall);
    CPPUNIT_TEST(test_diag_values);
    CPPUNIT_TEST(test_dot_zero);
    CPPUNIT_TEST(test_dot_one);
    CPPUNIT_TEST(test_dot_values);
    CPPUNIT_TEST(test_eye_negative);
    CPPUNIT_TEST(test_eye_square);
    CPPUNIT_TEST(test_eye_wide);
    CPPUNIT_TEST(test_eye_tall);
    //CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_ones);
    CPPUNIT_TEST(test_ones_double);
    CPPUNIT_TEST(test_ones_negative);
    CPPUNIT_TEST(test_rand_seed);
    CPPUNIT_TEST(test_rand_negative);
    CPPUNIT_TEST(test_rand_range);
    CPPUNIT_TEST(test_transpose);
    CPPUNIT_TEST(test_transpose_zero);
    CPPUNIT_TEST(test_transpose_values);
    CPPUNIT_TEST(test_tril_zero);
    CPPUNIT_TEST(test_tril_one);
    CPPUNIT_TEST(test_tril_two);
    CPPUNIT_TEST(test_triu_zero);
    CPPUNIT_TEST(test_triu_one);
    CPPUNIT_TEST(test_triu_two);
    CPPUNIT_TEST(test_zeros);
    CPPUNIT_TEST(test_zeros_double);
    CPPUNIT_TEST(test_zeros_negative);
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
