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
    // test_horzcat1
    // --------

    void test_horzcat1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        try {
            z = horzcat(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(z.eq(x));
    }

    // --------
    // test_horzcat2
    // --------

    void test_horzcat2 () {
        Matrix<int> x(3, 4, 1);
        Matrix<int> y(3, 6, 1);
        Matrix<int> z;
        Matrix<int> w(3, 10, 1);
        try {
            z = horzcat(x, y);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(z.eq(w));
    }

    // --------
    // test_horzcat3
    // --------

    void test_horzcat3 () {
        Matrix<int> x(2, 6, 1);
        Matrix<int> y(3, 6, 1);
        Matrix<int> z;
        Matrix<int> w;
        try {
            z = horzcat(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(z.eq(w));
    }

    // ------------
    // test_vertcat1
    // ------------

    void test_vertcat1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        try {
            z = vertcat(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(z.eq(x));
    }

    // ------------
    // test_vertcat2
    // ------------

    void test_vertcat2 () {
        Matrix<int> x(5, 3, 1);
        Matrix<int> y(2, 3, 1);
        Matrix<int> z;
        Matrix<int> w(7, 3, 1);
        try {
            z = vertcat(x, y);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(z.eq(w));
    }

    // ------------
    // test_vertcat3
    // ------------

    void test_vertcat3 () {
        Matrix<int> x(5, 3, 1);
        Matrix<int> y(5, 2, 1);
        Matrix<int> z;
        Matrix<int> w;
        try {
            z = vertcat(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(z.eq(w));
    }

    // ---------
    // test_diag1
    // ---------

    void test_diag1 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            y = diag(x);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_diag2
    // ---------

    void test_diag2 () {
        Matrix<int> x(5, 2, 100);
        Matrix<int> y;
        Matrix<int> w;
        try {
            y = diag(x);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(y.eq(w));
    }

    // ---------
    // test_diag3
    // ---------

    void test_diag3 () {
        Matrix<int> x(4, 1, 5);
        Matrix<int> y(4, 4, 0);
        y[0][0] = 5;
        y[1][1] = 5;
        y[2][2] = 5;
        y[3][3] = 5;
        Matrix<int> w;
        try {
            w = diag(x);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(w.eq(y));
    }

    // --------
    // test_eye1
    // --------

    void test_eye1 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            x = eye<Matrix<int> >(0, 0);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------
    // test_eye2
    // --------

    void test_eye2 () {
        Matrix<int> x(4,4,0);
        x[0][0] = 1;
        x[1][1] = 1;
        x[2][2] = 1;
        x[3][3] = 1;
        Matrix<int> y;
        try {
            y = eye<Matrix<int> >(4, 4);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------
    // test_eye3
    // --------

    void test_eye3 () {
        Matrix<int> x(6,4,0);
        x[0][0] = 1;
        x[1][1] = 1;
        x[2][2] = 1;
        x[3][3] = 1;
        Matrix<int> y;
        try {
            y = eye<Matrix<int> >(6, 4);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------
    // test_eye4
    // --------

    void test_eye4 () {
        Matrix<int> x(4,8,0);
        x[0][0] = 1;
        x[1][1] = 1;
        x[2][2] = 1;
        x[3][3] = 1;
        Matrix<int> y;
        try {
            y = eye<Matrix<int> >(4, 8);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
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
    // test_dot1
    // ---------

    void test_dot1 () {
        Matrix<int> x(6,1,2);
        Matrix<int> y(4,1,5);
        Matrix<int> z;
        Matrix<int> w;
        try {
            z = dot(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(z.eq(w));
    }

    // ---------
    // test_dot2
    // ---------

    void test_dot2 () {
        Matrix<int> x(6,1,4);
        Matrix<int> y(6,2,5);
        Matrix<int> z;
        Matrix<int> w;
        try {
            z = dot(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(z.eq(w));
    }

    // ---------
    // test_dot3
    // ---------

    void test_dot3 () {
        Matrix<int> x(4,1,2);
        Matrix<int> y(4,1,3);
        Matrix<int> z;
        Matrix<int> w(1,1,24);
        try {
            z = dot(x, y);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(z.eq(w));
    }

    // ---------
    // test_ones1
    // ---------

    void test_ones1 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            x = ones<Matrix <int> >(0, 5);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_ones2
    // ---------

    void test_ones2 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            x = ones<Matrix <int> >(5, 0);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_ones3
    // ---------

    void test_ones3 () {
        Matrix<int> x;
        Matrix<int> y(3, 5, 1);
        try {
            x = ones<Matrix <int> >(3, 5);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_rand1
    // ---------

    void test_rand1 () {
        Matrix<double> x;
        Matrix<double> y;
        try {
            x = rand< Matrix<double> >(0, 0);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_rand2
    // ---------

    void test_rand2 () {
        Matrix<double> x;
        try {
            x = rand< Matrix<double> >(2, 3);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        for (int r = 0; r < 2; r++)
            for (int c = 0; c < 3; c++)
                if (x[r][c] < 0 || x[r][c] > 1) CPPUNIT_ASSERT(false);
        CPPUNIT_ASSERT(true);
    }

    // ---------
    // test_rand3
    // ---------

    void test_rand3 () {
        Matrix<double> x;
        try {
            x = rand< Matrix<double> >(5, 1);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        Matrix<double> y = diag(x);
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (r == c) CPPUNIT_ASSERT(y[r][c] >= 0 || y[r][c] <= 1);
                else CPPUNIT_ASSERT(y[r][c] == 0);
            }
        }
        CPPUNIT_ASSERT(true);
    }
    // --------------
    // test_transpose1
    // --------------

    void test_transpose1 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            y = transpose(x);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(x.eq(y));}

    // --------------
    // test_transpose2
    // --------------

    void test_transpose2 () {
        Matrix<int> x(4, 2, 3);
        Matrix<int> y;
        Matrix<int> w(2, 4, 3);
        try {
            y = transpose(x);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(w.eq(y));}

    // --------------
    // test_transpose3
    // --------------

    void test_transpose3 () {
        Matrix<int> x(10, 10, 30);
        Matrix<int> y;
        try {
            y = transpose(x);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_tril1
    // ---------

    void test_tril1 () {
        Matrix<int> x(5, 4, 10);
        Matrix<int> y;
        Matrix<int> w;
        try {
            y = tril(x);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(y.eq(w));
    }

    // ---------
    // test_tril2
    // ---------

    void test_tril2 () {
        Matrix<int> x(3, 3, 10);
        Matrix<int> y;
        Matrix<int> w(3, 3, 10);
        w[0][1] = 0;
        w[0][2] = 0;
        w[1][2] = 0;
        try {
            y = tril(x);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(y.eq(w));
    }

    // ---------
    // test_tril3
    // ---------

    void test_tril3 () {
        Matrix<int> x(2, 2, 10);
        Matrix<int> y;
        Matrix<int> w(2, 2, 10);
        w[0][1] = 0;
        try {
            y = tril(x);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(y.eq(w));
    }

    // ---------
    // test_tril4
    // ---------

    void test_tril4 () {
        Matrix<int> x(1, 1, 10);
        Matrix<int> y;
        Matrix<int> w(1, 1, 10);
        try {
            y = tril(x);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(y.eq(w));
    }

    // ---------
    // test_triu1
    // ---------

    void test_triu1 () {
        Matrix<int> x(5, 4, 10);
        Matrix<int> y;
        Matrix<int> w;
        try {
            y = triu(x);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(y.eq(w));
    }

    // ---------
    // test_triu2
    // ---------

    void test_triu2 () {
        Matrix<int> x(3, 3, 10);
        Matrix<int> y;
        Matrix<int> w(3, 3, 10);
        w[1][0] = 0;
        w[2][0] = 0;
        w[2][1] = 0;
        try {
            y = triu(x);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(y.eq(w));
    }

    // ---------
    // test_triu3
    // ---------

    void test_triu3 () {
        Matrix<int> x(2, 2, 10);
        Matrix<int> y;
        Matrix<int> w(2, 2, 10);
        w[1][0] = 0;
        try {
            y = triu(x);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(y.eq(w));
    }

    // ---------
    // test_triu4
    // ---------

    void test_triu4 () {
        Matrix<int> x(1, 1, 10);
        Matrix<int> y;
        Matrix<int> w(1, 1, 10);
        try {
            y = triu(x);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(y.eq(w));
    }

    // ---------
    // test_zeros1
    // ---------

    void test_zeros1 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            x = zeros<Matrix <int> >(0, 5);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_zeros2
    // ---------

    void test_zeros2 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            x = zeros<Matrix <int> >(5, 0);
            CPPUNIT_ASSERT(false);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_zeros3
    // ---------

    void test_zeros3 () {
        Matrix<int> x;
        Matrix<int> y(5, 3, 0);
        try {
            x = zeros<Matrix <int> >(5, 3);
            CPPUNIT_ASSERT(true);
        }
        catch (DimensionException& e) {
            CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(x.eq(y));
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat1);
    CPPUNIT_TEST(test_horzcat2);
    CPPUNIT_TEST(test_horzcat3);
    CPPUNIT_TEST(test_vertcat1);
    CPPUNIT_TEST(test_vertcat2);
    CPPUNIT_TEST(test_vertcat3);
    CPPUNIT_TEST(test_diag1);
    CPPUNIT_TEST(test_diag2);
    CPPUNIT_TEST(test_diag3);
    CPPUNIT_TEST(test_dot1);
    CPPUNIT_TEST(test_dot2);
    CPPUNIT_TEST(test_dot3);
    CPPUNIT_TEST(test_eye1);
    CPPUNIT_TEST(test_eye2);
    CPPUNIT_TEST(test_eye3);
    CPPUNIT_TEST(test_eye4);
    CPPUNIT_TEST(test_ones1);
    CPPUNIT_TEST(test_ones2);
    CPPUNIT_TEST(test_ones3);
    CPPUNIT_TEST(test_rand1);
    CPPUNIT_TEST(test_rand2);
    CPPUNIT_TEST(test_rand3);
    CPPUNIT_TEST(test_transpose1);
    CPPUNIT_TEST(test_transpose2);
    CPPUNIT_TEST(test_transpose3);
    CPPUNIT_TEST(test_tril1);
    CPPUNIT_TEST(test_tril2);
    CPPUNIT_TEST(test_tril3);
    CPPUNIT_TEST(test_tril4);
    CPPUNIT_TEST(test_triu1);
    CPPUNIT_TEST(test_triu2);
    CPPUNIT_TEST(test_triu3);
    CPPUNIT_TEST(test_triu4);
    CPPUNIT_TEST(test_zeros1);
    CPPUNIT_TEST(test_zeros2);
    CPPUNIT_TEST(test_zeros3);
    //CPPUNIT_TEST(test_linsolve1);
    //CPPUNIT_TEST(test_linsolve2);
    //CPPUNIT_TEST(test_linsolve3);
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
