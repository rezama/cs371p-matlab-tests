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
#include <stdexcept>

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

    void test_horzcat() {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_horzcat_1() {
        Matrix<int> x(2, 3, 42);
        Matrix<int> y(2, 5, 123);

        int a[] = { 42, 42, 42, 123, 123, 123, 123, 123, 42, 42, 42, 123, 123,
                123, 123, 123 };
        Matrix<int> z = Matrix<int>::makeMatrix(a, 2, 8);

        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_horzcat_2() {
        Matrix<int> x(1, 1, 42);
        Matrix<int> y(1, 1, 123);

        int a[] = { 42, 123 };
        Matrix<int> z = Matrix<int>::makeMatrix(a, 1, 2);

        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_horzcat_3() {
        Matrix<int> x(3, 1, 42);
        Matrix<int> y(3, 1, 123);

        int a[] = { 42, 123, 42, 123, 42, 123 };
        Matrix<int> z = Matrix<int>::makeMatrix(a, 3, 2);

        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_horzcat_4() {
        Matrix<int> x(3, 1, 42);
        Matrix<int> y(0, 1, 123);  // effectively 0x0

        try {
            x = horzcat(x, y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException &e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_horzcat_5() {
        Matrix<int> x(3, 1, 42);
        Matrix<int> y(2, 1, 123);  // wrong num rows

        try {
            x = horzcat(x, y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException &e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_vertcat() {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_vertcat_1() {
        Matrix<int> x(3, 1, 42);
        Matrix<int> y(5, 1, 123);

        int a[] = { 42, 42, 42, 123, 123, 123, 123, 123 };
        Matrix<int> z = Matrix<int>::makeMatrix(a, 8, 1);

        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_vertcat_2() {
        Matrix<int> x(1, 1, 42);
        Matrix<int> y(1, 1, 123);

        int a[] = { 42, 123 };
        Matrix<int> z = Matrix<int>::makeMatrix(a, 2, 1);

        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_vertcat_3() {
        Matrix<int> x(1, 3, 42);
        Matrix<int> y(1, 3, 123);

        int a[] = { 42, 42, 42, 123, 123, 123 };
        Matrix<int> z = Matrix<int>::makeMatrix(a, 2, 3);

        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_vertcat_4() {
        Matrix<int> x(3, 1, 42);
        Matrix<int> y(0, 1, 123);  // effectively 0x0

        try {
            x = vertcat(x, y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException &e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_vertcat_5() {
        Matrix<int> x(3, 1, 42);
        Matrix<int> y(2, 2, 123);  // wrong num columns

        try {
            x = vertcat(x, y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException &e) {
            CPPUNIT_ASSERT(true);
        }
    }

    // ---------
    // test_diag
    // ---------

    /**
     * Zero length vector.
     */
    void test_diag() {
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    /**
     * 1x1 Matrix
     */
    void test_diag_1() {
        Matrix<int> x(1, 1, 42);
        Matrix<int> y(1, 1, 42);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    /**
     * 1x3 row vector
     */
    void test_diag_2() {
        int a[] = { 1, 2, 3 };
        int b[] = { 1, 0, 0, 0, 2, 0, 0, 0, 3 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 1, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 3, 3);

        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    /**
     * 3x1 column vector
     */
    void test_diag_3() {
        int a[] = { 1, 2, 3 };
        int b[] = { 1, 0, 0, 0, 2, 0, 0, 0, 3 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 3, 1);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 3, 3);

        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    /**
     * 2x2 matrix
     */
    void test_diag_4() {
        int a[] = { 1, 2, 3, 4 };
        int b[] = { 1, 4 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 2, 2);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 2, 1);

        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    /**
     * 3x3 matrix
     */
    void test_diag_5() {
        int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int b[] = { 1, 5, 9 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 3, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 3, 1);

        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    /**
     * 2x3 matrix
     */
    void test_diag_6() {
        int a[] = { 1, 2, 3, 4, 5, 6 };
        int b[] = { 1, 5 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 2, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 2, 1);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    /**
     * 4x2 matrix
     */
    void test_diag_7() {
        int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
        int b[] = { 1, 4 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 4, 2);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 2, 1);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    /**
     * 2x4 matrix
     */
    void test_diag_8() {
        int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
        int b[] = { 1, 6 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 2, 4);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 2, 1);

        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------
    // test_dot
    // --------

    void test_dot() {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    /**
     * Both row vectors
     */
    void test_dot_1() {
        int a[] = { 1, 2, 3 };
        int b[] = { 4, 5, 6 };
        int c[] = { 32 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 3, 1);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 3, 1);
        Matrix<int> z(1, 1, c[0]);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    /**
     * Both column vectors
     */
    void test_dot_2() {
        int a[] = { 1, 2, 3 };
        int b[] = { 4, 5, 6 };
        int c[] = { 32 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 1, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 1, 3);
        Matrix<int> z(1, 1, c[0]);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    /**
     * Row vector X Column vector
     */
    void test_dot_3() {
        int a[] = { 1, 2, 3 };
        int b[] = { 4, 5, 6 };
        int c[] = { 32 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 3, 1);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 1, 3);
        Matrix<int> z(1, 1, c[0]);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    /**
     * Column vector X Row vector
     */
    void test_dot_4() {
        int a[] = { 1, 2, 3 };
        int b[] = { 4, 5, 6 };
        int c[] = { 32 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 1, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 3, 1);
        Matrix<int> z(1, 1, c[0]);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    /**
     * Nonconformant vector sizes.
     * Both row vectors
     */
    void test_dot_5() {
        int a[] = { 1, 2, 3 };
        int b[] = { 4, 5, 6 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 1, 2);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 1, 3);

        try {
            x = dot(x, y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException &e) {
            CPPUNIT_ASSERT(true);
        }
    }

    /**
     * Nonconformant vector sizes.
     * Both column vectors
     */
    void test_dot_6() {
        int a[] = { 1, 2, 3 };
        int b[] = { 4, 5, 6 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 3, 1);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 2, 1);

        try {
            x = dot(x, y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException &e) {
            CPPUNIT_ASSERT(true);
        }
    }

    /**
     * Nonconformant vector sizes.
     * Row by column vector
     */
    void test_dot_7() {
        int a[] = { 1, 2, 3 };
        int b[] = { 4, 5, 6 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 3, 1);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 1, 2);

        try {
            x = dot(x, y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException &e) {
            CPPUNIT_ASSERT(true);
        }
    }

    /**
     * Nonconformant vector sizes.
     * Column by row vector
     */
    void test_dot_8() {
        int a[] = { 1, 2, 3 };
        int b[] = { 4, 5, 6 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 1, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 2, 1);

        try {
            x = dot(x, y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException &e) {
            CPPUNIT_ASSERT(true);
        }
    }

    // TODO test dot product for non-vectors
    // TODO test exceptions for non-vectors

    // --------
    // test_eye
    // --------

    void test_eye_1() {
        Matrix<int> x = eye<Matrix<int> >(0, 0);
        Matrix<int> y;
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_eye_2() {
        Matrix<int> x = eye<Matrix<int> >(1, 1);
        Matrix<int> y(1, 1, 1);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_eye_3() {
        int a[] = { 1, 0, 0, 0, 1, 0 };
        Matrix<int> x = eye<Matrix<int> >(2, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(a, 2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_eye_4() {
        int a[] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
        Matrix<int> x = eye<Matrix<int> >(3, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(a, 3, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_eye_5() {
        int a[] = { 1, 0, 0, 1, 0, 0 };
        Matrix<int> x = eye<Matrix<int> >(3, 2);
        Matrix<int> y = Matrix<int>::makeMatrix(a, 3, 2);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // -------------
    // test_linsolve
    // -------------

    void test_linsolve() {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;

        try {
            x = linsolve(x, y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException &e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_linsolve_1() {
        float a[] = { 1., 2., 4., 3. };
        float b[] = { 3., 2. };
        float x[] = { -1., 2. };

        Matrix<float> aa = Matrix<float>::makeMatrix(a, 2, 2);
        Matrix<float> bb = Matrix<float>::makeMatrix(b, 2, 1);
        Matrix<float> xx = Matrix<float>::makeMatrix(x, 2, 1);

        aa = linsolve(aa, bb);
        CPPUNIT_ASSERT(aa.eq(xx));
    }

    void test_linsolve_2() {
        float a[] = { 5, 2, 3, 4, 5, 6, 7, 8, 9 };
        float b[] = { 4, 7, 14 };
        float x[] = { 1, 5, -3 - (2. / 3) };

        Matrix<float> aa = Matrix<float>::makeMatrix(a, 3, 3);
        Matrix<float> bb = Matrix<float>::makeMatrix(b, 3, 1);
        Matrix<float> xx = Matrix<float>::makeMatrix(x, 3, 1);

        aa = linsolve(aa, bb);

        typedef Matrix<float>::size_type size_type;

        for (size_type i = 0; i < aa.size(); ++i) {
            for (size_type j = 0; j < aa[0].size(); ++j) {
                CPPUNIT_ASSERT(aa[i][j]-xx[i][j] < 1e-5);
            }
        }
    }

    void test_linsolve_3() {
        float a[] = { 5, 2, 3, 4, 5, 6, 7, 8, 9 };
        float b[] = { 4, 7, 14, 4, 7, 14, 4, 7, 14, };
        float x[] = { 1, 5, -3 - (2. / 3), 1, 5, -3 - (2. / 3), 1, 5, -3
                - (2. / 3) };

        Matrix<float> aa = Matrix<float>::makeMatrix(a, 3, 3);
        Matrix<float> bb = transpose(Matrix<float>::makeMatrix(b, 3, 3));
        Matrix<float> xx = transpose(Matrix<float>::makeMatrix(x, 3, 3));

        aa = linsolve(aa, bb);

        typedef Matrix<float>::size_type size_type;

        for (size_type i = 0; i < aa.size(); ++i) {
            for (size_type j = 0; j < aa[0].size(); ++j) {
                CPPUNIT_ASSERT(aa[i][j]-xx[i][j] < 1e-5);
            }
        }
    }

    /**
     * What if the matrix is singular?
     */
    void test_linsolve_4() {
        float a[] = { 0, 2, 3, 0, 1, 2, 0, 3, 4 };
        float b[] = { 1, 2, 3 };
        float x[] = { 0, 0, 0 };  // TODO what?

        Matrix<float> aa = Matrix<float>::makeMatrix(a, 3, 3);
        Matrix<float> bb = transpose(Matrix<float>::makeMatrix(b, 3, 3));
        Matrix<float> xx = transpose(Matrix<float>::makeMatrix(x, 3, 3));

        try {
            aa = linsolve(aa, bb);
            CPPUNIT_ASSERT(false);
        } catch (std::invalid_argument &e) {
            CPPUNIT_ASSERT(true);
        }
    }

    /**
     * What if the number of equations is smaller than the number of variables?
     */
    void test_linsolve_5() {
        float a[] = { 1, 2, 3, 4, 5, 6 };
        float b[] = { 8, 9 };

        Matrix<float> aa = Matrix<float>::makeMatrix(a, 2, 3);
        Matrix<float> bb = transpose(Matrix<float>::makeMatrix(b, 1, 2));

        Matrix<float> tt = linsolve(aa, bb);

        Matrix<float> variance = (ones<Matrix<float> >(2, 1) * 1e-5);
        Matrix<float> xx = aa * tt;
        Matrix<bool> results = (bb - xx) < variance;
        Matrix<bool> expected = ones<Matrix<bool> >(2, 1);

        CPPUNIT_ASSERT(results.eq(expected));
    }

    /**
     * What if there are more equations than variables?
     * In this test, the last equation is redundant and we have found a solution.
     */
    void test_linsolve_6() {
        float a[] = { 1, 2, 2, 3, 3, 4 };
        float b[] = { 3, 4, 5 };
        float z[] = { -1, 2 };

        Matrix<float> aa = Matrix<float>::makeMatrix(a, 3, 2);
        Matrix<float> bb = Matrix<float>::makeMatrix(b, 3, 1);
        Matrix<float> zz = Matrix<float>::makeMatrix(z, 2, 1);

        aa = linsolve(aa, bb);

        CPPUNIT_ASSERT(aa.eq(zz));
    }

    /**
     * What if there are more equations than variables?
     * In this test, the last equation conflicts and is false, yielding no solutions.
     */
    void test_linsolve_7() {
        float a[] = { 1, 2, 2, 3, 3, 4 };
        float b[] = { 3, 4, 21434 };

        Matrix<float> aa = Matrix<float>::makeMatrix(a, 3, 2);
        Matrix<float> bb = Matrix<float>::makeMatrix(b, 3, 1);

        try {
            aa = linsolve(aa, bb);
            CPPUNIT_ASSERT(false);
        } catch (std::invalid_argument &e) {
            CPPUNIT_ASSERT(true);
        }
    }

    /**
     * What if there are more equations than variables?
     * In this test, the last equation conflicts and is false, yielding no solutions.
     */
    void test_linsolve_8() {
        float a[] = { 1, 2, 2, 3, 3, 4, 1, 2 };
        float b[] = { 3, 4, 21434, 3 };

        Matrix<float> aa = Matrix<float>::makeMatrix(a, 4, 2);
        Matrix<float> bb = Matrix<float>::makeMatrix(b, 4, 1);

        try {
            aa = linsolve(aa, bb);
            CPPUNIT_ASSERT(false);
        } catch (std::invalid_argument &e) {
            CPPUNIT_ASSERT(true);
        }
    }

    // ---------
    // test_ones
    // ---------

    void test_ones_1() {
        Matrix<int> x;
        Matrix<int> y;

        x = ones<Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_ones_2() {
        int a[] = { 1, 1, 1 };

        Matrix<int> x;
        Matrix<int> y = Matrix<int>::makeMatrix(a, 1, 3);

        x = ones<Matrix<int> >(1, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_ones_3() {
        int a[] = { 1, 1, 1 };

        Matrix<int> x;
        Matrix<int> y = Matrix<int>::makeMatrix(a, 3, 1);

        x = ones<Matrix<int> >(3, 1);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_ones_4() {
        int a[] = { 1, 1, 1, 1, 1, 1 };

        Matrix<int> x;
        Matrix<int> y = Matrix<int>::makeMatrix(a, 2, 3);

        x = ones<Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_rand
    // ---------

    void test_rand_1() {
        Matrix<float> x = rand<Matrix<float> >(0, 0);
        Matrix<float> y;

        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_rand_2() {
        Matrix<float> x = rand<Matrix<float> >(1, 1);

        CPPUNIT_ASSERT((x[0][0] > 0.0f) && (x[0][0] < 1.0f));
    }

    void test_rand_3() {
        Matrix<float> x = rand<Matrix<float> >(2, 2);

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                CPPUNIT_ASSERT((x[i][j] > 0.0f) && (x[i][j] < 1.0f));
            }
        }
    }

    void test_rand_4() {
        Matrix<float> x = rand<Matrix<float> >(4, 3);

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                CPPUNIT_ASSERT((x[i][j] > 0.0f) && (x[i][j] < 1.0f));
            }
        }
    }

    // --------------
    // test_transpose
    // --------------

    void test_transpose() {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_transpose_1() {
        Matrix<int> x = eye<Matrix<int> >(2, 3);
        Matrix<int> y = eye<Matrix<int> >(3, 2);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_transpose_2() {
        int a[] = { 1, 2, 3, 4 };
        int b[] = { 1, 3, 2, 4 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 2, 2);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 2, 2);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_transpose_3() {
        int a[] = { 1, 2, 3, 4, 5, 6 };
        int b[] = { 1, 4, 2, 5, 3, 6 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 2, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 3, 2);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_tril
    // ---------

    void test_tril() {
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_tril_1() {
        int a[] = { 1, 2, 3, 4, 5, 6 };
        int b[] = { 1, 0, 0, 4, 5, 0 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 2, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 2, 3);

        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_tril_2() {
        int a[] = { 1, 2, 3, 4, 5, 6 };
        int b[] = { 1, 0, 3, 4, 5, 6 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 3, 2);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 3, 2);

        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_tril_3() {
        int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int b[] = { 1, 0, 0, 4, 5, 0, 7, 8, 9 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 3, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 3, 3);

        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_tril_4() {
        int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
        int b[] = { 1, 0, 0, 0, 5, 6, 0, 0, 9, 10, 11, 0 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 3, 4);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 3, 4);

        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_triu
    // ---------

    void test_triu() {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_triu_1() {
        int a[] = { 1, 2, 3, 4, 5, 6 };
        int b[] = { 1, 2, 3, 0, 5, 6 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 2, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 2, 3);

        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_triu_2() {
        int a[] = { 1, 2, 3, 4, 5, 6 };
        int b[] = { 1, 2, 0, 4, 0, 0 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 3, 2);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 3, 2);

        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_triu_3() {
        int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int b[] = { 1, 2, 3, 0, 5, 6, 0, 0, 9 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 3, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 3, 3);

        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_triu_4() {
        int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
        int b[] = { 1, 2, 3, 4, 0, 6, 7, 8, 0, 0, 11, 12 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 3, 4);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 3, 4);

        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ----------
    // test_zeros
    // ----------

    void test_zeros_1() {
        Matrix<int> x;
        Matrix<int> y;

        x = zeros<Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_zeros_2() {
        int a[] = { 0, 0, 0 };

        Matrix<int> x;
        Matrix<int> y = Matrix<int>::makeMatrix(a, 1, 3);

        x = zeros<Matrix<int> >(1, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_zeros_3() {
        int a[] = { 0, 0, 0 };

        Matrix<int> x;
        Matrix<int> y = Matrix<int>::makeMatrix(a, 3, 1);

        x = zeros<Matrix<int> >(3, 1);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_zeros_4() {
        int a[] = { 0, 0, 0, 0, 0, 0 };

        Matrix<int> x;
        Matrix<int> y = Matrix<int>::makeMatrix(a, 2, 3);

        x = zeros<Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // -----
    // suite
    // -----

CPPUNIT_TEST_SUITE(TestMatlab);
        CPPUNIT_TEST(test_horzcat);
        CPPUNIT_TEST(test_horzcat_1);
        CPPUNIT_TEST(test_horzcat_2);
        CPPUNIT_TEST(test_horzcat_3);
        CPPUNIT_TEST(test_horzcat_4);
        CPPUNIT_TEST(test_horzcat_5);
        CPPUNIT_TEST(test_vertcat);
        CPPUNIT_TEST(test_vertcat_1);
        CPPUNIT_TEST(test_vertcat_2);
        CPPUNIT_TEST(test_vertcat_3);
        CPPUNIT_TEST(test_vertcat_4);
        CPPUNIT_TEST(test_vertcat_5);
        CPPUNIT_TEST(test_diag);
        CPPUNIT_TEST(test_diag_1);
        CPPUNIT_TEST(test_diag_2);
        CPPUNIT_TEST(test_diag_3);
        CPPUNIT_TEST(test_diag_4);
        CPPUNIT_TEST(test_diag_5);
        CPPUNIT_TEST(test_diag_6);
        CPPUNIT_TEST(test_diag_7);
        CPPUNIT_TEST(test_diag_8);
        CPPUNIT_TEST(test_dot);
        CPPUNIT_TEST(test_dot_1);
        CPPUNIT_TEST(test_dot_2);
        CPPUNIT_TEST(test_dot_3);
        CPPUNIT_TEST(test_dot_4);
        CPPUNIT_TEST(test_dot_5);
        CPPUNIT_TEST(test_dot_6);
        CPPUNIT_TEST(test_dot_7);
        CPPUNIT_TEST(test_dot_8);
        CPPUNIT_TEST(test_eye_1);
        CPPUNIT_TEST(test_eye_2);
        CPPUNIT_TEST(test_eye_3);
        CPPUNIT_TEST(test_eye_4);
        CPPUNIT_TEST(test_eye_5);
        CPPUNIT_TEST(test_linsolve);
        CPPUNIT_TEST(test_linsolve_1);
        CPPUNIT_TEST(test_linsolve_2);
        CPPUNIT_TEST(test_linsolve_3);
        CPPUNIT_TEST(test_linsolve_4);
        CPPUNIT_TEST(test_linsolve_5);
        CPPUNIT_TEST(test_linsolve_6);
        CPPUNIT_TEST(test_linsolve_7);
        CPPUNIT_TEST(test_linsolve_8);
        CPPUNIT_TEST(test_ones_1);
        CPPUNIT_TEST(test_ones_2);
        CPPUNIT_TEST(test_ones_3);
        CPPUNIT_TEST(test_ones_4);
        CPPUNIT_TEST(test_rand_1);
        CPPUNIT_TEST(test_rand_2);
        CPPUNIT_TEST(test_rand_3);
        CPPUNIT_TEST(test_rand_4);
        CPPUNIT_TEST(test_transpose);
        CPPUNIT_TEST(test_transpose_1);
        CPPUNIT_TEST(test_transpose_2);
        CPPUNIT_TEST(test_transpose_3);
        CPPUNIT_TEST(test_tril);
        CPPUNIT_TEST(test_tril_1);
        CPPUNIT_TEST(test_tril_2);
        CPPUNIT_TEST(test_tril_3);
        CPPUNIT_TEST(test_tril_4);
        CPPUNIT_TEST(test_triu);
        CPPUNIT_TEST(test_triu_1);
        CPPUNIT_TEST(test_triu_2);
        CPPUNIT_TEST(test_triu_3);
        CPPUNIT_TEST(test_triu_4);
        CPPUNIT_TEST(test_zeros_1);
        CPPUNIT_TEST(test_zeros_2);
        CPPUNIT_TEST(test_zeros_3);
        CPPUNIT_TEST(test_zeros_4);
    CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main() {
    using namespace std;

    try {
        ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
        cout << "TestMatlab.c++" << endl;

        CppUnit::TextTestRunner tr;
        tr.addTest(TestMatlab::suite());
        tr.run();
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    cout << "Done." << endl;
    return 0;
}
