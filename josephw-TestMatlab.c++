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
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 1, 1);
        Matrix<int> z(2, 3, 1);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_horzcat_3 () {
        Matrix<int> x(4, 3, 2);
        Matrix<int> y(4, 7, 2);
        Matrix<int> z(4, 10, 2);
        Matrix<int> t(4, 20, 2);
        x = horzcat(x, y);
        x = horzcat(x, z);
        CPPUNIT_ASSERT(x.eq(t));}

    void test_horzcat_4 () {
        Matrix<int> x1(2, 3, 2);
        Matrix<int> y1(2, 2, 1);
        Matrix<int> x2(2, 2, 2);
        Matrix<int> x2a(2, 1, 2);
        Matrix<int> y2(2, 1, 1);
        x1 = horzcat(x1, y1);
        x2 = horzcat(x2, x2a);
        x2 = horzcat(x2, y2);
        x2 = horzcat(x2, y2);
        CPPUNIT_ASSERT(x1.eq(x2));}

    void test_vertcat_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat_2 () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(1, 2, 1);
        Matrix<int> z(3, 2, 1);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat_3 () {
        Matrix<int> x(4, 3, 2);
        Matrix<int> y(7, 3, 2);
        Matrix<int> z(10, 3, 2);
        Matrix<int> t(21, 3, 2);
        x = vertcat(x, y);
        x = vertcat(x, z);
        CPPUNIT_ASSERT(x.eq(t));}

    void test_vertcat_4 () {
        Matrix<int> x1(3, 2, 2);
        Matrix<int> y1(2, 2, 1);
        Matrix<int> x2(2, 2, 2);
        Matrix<int> x2a(1, 2, 2);
        Matrix<int> y2(1, 2, 1);
        x1 = vertcat(x1, y1);
        x2 = vertcat(x2, x2a);
        x2 = vertcat(x2, y2);
        x2 = vertcat(x2, y2);
        CPPUNIT_ASSERT(x1.eq(x2));}

    // ---------
    // test_diag
    // ---------

    void test_diag_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag_2 () {
        Matrix<int> x(4, 4, 4);
        Matrix<int> y(4, 1, 4);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag_3 () {
        Matrix<int> x(4, 5, 4);
        Matrix<int> y(4, 1, 4);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag_4 () {
        Matrix<int> x(4, 3, 4);
        Matrix<int> y(3, 1, 4);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag_5 () {
        Matrix<int> x(4, 1, 4);
        Matrix<int> y(4, 4, 0);
        x = diag(x);
        for (int i=0; i<4; ++i) {
            y[i][i] = 4;
        }
        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag_6 () {
        Matrix<int> x(3, 3, 0);
        Matrix<int> y(3, 1, 0);
        x[0][0] = 4;
        x[1][1] = 5;
        x[2][2] = 6;
        x = diag(x);
        y[0][0] = 4;
        y[1][0] = 5;
        y[2][0] = 6;
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
        Matrix<int> x(4, 1, 1);
        Matrix<int> y(4, 1, 1);
        Matrix<int> z(1, 1, 4);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_3 () {
        Matrix<int> x(4, 1, 2);
        Matrix<int> y(1, 4, 2);
        Matrix<int> z(1, 1, 16);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_4 () {
        Matrix<int> x(1, 3, 3);
        Matrix<int> y(1, 3, 0);
        y[0][0] = 2;
        y[0][1] = 3;
        y[0][2] = 4;
        Matrix<int> z(1, 1, 27);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    // --------
    // test_eye
    // --------

    void test_eye_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = eye< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_eye_2 () {
        Matrix<int> x;
        Matrix<int> y(3, 3, 0);
        for (int i=0; i<3; ++i) {
            y[i][i] = 1;
        }
        x = eye< Matrix<int> >(3, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_eye_3 () {
        Matrix<int> x;
        Matrix<int> y(3, 4, 0);
        for (int i=0; i<3; ++i) {
            y[i][i] = 1;
        }
        x = eye< Matrix<int> >(3, 4);
        CPPUNIT_ASSERT(x.eq(y));}


/*    // -------------
    // test_linsolve
    // -------------

    void test_linsolve () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = linsolve(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
*/
    // ---------
    // test_ones
    // ---------

    void test_ones_1 () {
        Matrix<int> x;
        Matrix<int> y(0, 0, 1);
        x = ones< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_ones_2 () {
        Matrix<int> x;
        Matrix<int> y(3, 2, 1);
        x = ones< Matrix<int> >(3, 2);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_ones_3 () {
        Matrix<int> x;
        Matrix<int> y(5, 5, 1);
        x = ones< Matrix<int> >(5, 5);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_rand
    // ---------

    void test_rand_1 () {
        Matrix<double> x;
        Matrix<double> y(2, 3, 2);
        x = rand< Matrix<double> >(2, 3);
        for (int i=0; i<2; ++i) {
            for (int j=0; j<3; ++j) {
                CPPUNIT_ASSERT(x[i][j] > 0.0);
                CPPUNIT_ASSERT(x[i][j] < 1.0);
            }
        }
        CPPUNIT_ASSERT(!(x.eq(y)));}

    void test_rand_2 () {
        Matrix<double> x;
        Matrix<double> y(5, 5, 2);
        x = rand< Matrix<double> >(5, 5);
        for (int i=0; i<5; ++i) {
            for (int j=0; j<5; ++j) {
                CPPUNIT_ASSERT(x[i][j] > 0.0);
                CPPUNIT_ASSERT(x[i][j] < 1.0);
            }
        }
        CPPUNIT_ASSERT(!(x.eq(y)));}

    void test_rand_3 () {
        Matrix<double> x;
        Matrix<double> y(7, 9, 2);
        x = rand< Matrix<double> >(7, 9);
        for (int i=0; i<7; ++i) {
            for (int j=0; j<9; ++j) {
                CPPUNIT_ASSERT(x[i][j] > 0.0);
                CPPUNIT_ASSERT(x[i][j] < 1.0);
            }
        }
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
        Matrix<int> x(1, 2);
        Matrix<int> y(2, 1);
        x[0][0] = 2;
        x[0][1] = 3;
        x = transpose(x);
        y[0][0] = 2;
        y[1][0] = 3;
        CPPUNIT_ASSERT(x.eq(y));}

    void test_transpose_3 () {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        x[0][0] = 1;
        x[0][1] = 2;
        x[1][0] = 3;
        x[1][1] = 4;
        x = transpose(x);
        y[0][0] = 1;
        y[1][0] = 2;
        y[0][1] = 3;
        y[1][1] = 4;
        CPPUNIT_ASSERT(x.eq(y));}

    void test_transpose_4 () {
        Matrix<int> x(3, 2);
        Matrix<int> y(2, 3);
        x[0][0] = 1;
        x[0][1] = 2;
        x[1][0] = 3;
        x[1][1] = 4;
        x[2][0] = 5;
        x[2][1] = 6;
        x = transpose(x);
        y[0][0] = 1;
        y[1][0] = 2;
        y[0][1] = 3;
        y[1][1] = 4;
        y[0][2] = 5;
        y[1][2] = 6;
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
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        x = tril(x);
        y[0][1] = 0;
        CPPUNIT_ASSERT(x.eq(y));}

    void test_tril_3 () {
        Matrix<int> x(2, 3, 1);
        Matrix<int> y(2, 3, 1);
        x = tril(x);
        y[0][1] = 0;
        y[0][2] = 0;
        y[1][2] = 0;
        CPPUNIT_ASSERT(x.eq(y));}

    void test_tril_4 () {
        Matrix<int> x(9, 9, 9);
        Matrix<int> y(9, 9, 9);
        x = tril(x);
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                if (j > i) {
                    y[i][j] = 0;
                }
            }
        }
        CPPUNIT_ASSERT(x.eq(y));}


    // ---------
    // test_triu
    // ---------

    void test_triu_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_triu_2 () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        x = triu(x);
        y[1][0] = 0;
        CPPUNIT_ASSERT(x.eq(y));}

    void test_triu_3 () {
        Matrix<int> x(3, 2, 1);
        Matrix<int> y(3, 2, 1);
        x = triu(x);
        y[1][0] = 0;
        y[2][0] = 0;
        y[2][1] = 0;
        CPPUNIT_ASSERT(x.eq(y));}

    void test_triu_4 () {
        Matrix<int> x(9, 9, 9);
        Matrix<int> y(9, 9, 9);
        x = triu(x);
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                if (j < i) {
                    y[i][j] = 0;
                }
            }
        }
        CPPUNIT_ASSERT(x.eq(y));}


    // ----------
    // test_zeros
    // ----------

    void test_zeros_1 () {
        Matrix<int> x;
        Matrix<int> y(0, 0, 0);
        x = zeros< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_zeros_2 () {
        Matrix<int> x;
        Matrix<int> y(3, 2, 0);
        x = zeros< Matrix<int> >(3, 2);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_zeros_3 () {
        Matrix<int> x;
        Matrix<int> y(5, 5, 0);
        x = zeros< Matrix<int> >(5, 5);
        CPPUNIT_ASSERT(x.eq(y));}

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
    CPPUNIT_TEST(test_diag_5);
    CPPUNIT_TEST(test_diag_6);
    CPPUNIT_TEST(test_dot_1);
    CPPUNIT_TEST(test_dot_2);
    CPPUNIT_TEST(test_dot_3);
    CPPUNIT_TEST(test_dot_4);
    CPPUNIT_TEST(test_eye_1);
    CPPUNIT_TEST(test_eye_2);
    CPPUNIT_TEST(test_eye_3);
//    CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_ones_1);
    CPPUNIT_TEST(test_ones_2);
    CPPUNIT_TEST(test_ones_3);
    CPPUNIT_TEST(test_rand_1);
    CPPUNIT_TEST(test_rand_2);
    CPPUNIT_TEST(test_rand_3);
    CPPUNIT_TEST(test_transpose_1);
    CPPUNIT_TEST(test_transpose_2);
    CPPUNIT_TEST(test_transpose_3);
    CPPUNIT_TEST(test_transpose_4);
    CPPUNIT_TEST(test_tril_1);
    CPPUNIT_TEST(test_tril_2);
    CPPUNIT_TEST(test_tril_3);
    CPPUNIT_TEST(test_tril_4);
    CPPUNIT_TEST(test_triu_1);
    CPPUNIT_TEST(test_triu_2);
    CPPUNIT_TEST(test_triu_3);
    CPPUNIT_TEST(test_triu_4);
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