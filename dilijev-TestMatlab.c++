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

    // ---------
    // test_diag
    // ---------

    void test_diag() {
        Matrix<int> x;
        Matrix<int> y;
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
        x = linsolve(x, y);
        CPPUNIT_ASSERT(x.eq(z));
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

    void test_rand() {
        Matrix<int> x;
        Matrix<int> y;
        x = rand<Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
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

    // ---------
    // test_triu
    // ---------

    void test_triu() {
        Matrix<int> x;
        Matrix<int> y;
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
        CPPUNIT_TEST(test_horzcat);  // TODO
        CPPUNIT_TEST(test_horzcat_1);  // TODO
        CPPUNIT_TEST(test_vertcat);  // TODO
        CPPUNIT_TEST(test_vertcat_1);  // TODO
        CPPUNIT_TEST(test_diag);  // TODO
        CPPUNIT_TEST(test_eye_1);
        CPPUNIT_TEST(test_eye_2);
        CPPUNIT_TEST(test_eye_3);
        CPPUNIT_TEST(test_eye_4);
        CPPUNIT_TEST(test_eye_5);
        CPPUNIT_TEST(test_linsolve);  // TODO
        CPPUNIT_TEST(test_ones_1);
        CPPUNIT_TEST(test_ones_2);
        CPPUNIT_TEST(test_ones_3);
        CPPUNIT_TEST(test_ones_4);
        CPPUNIT_TEST(test_rand);  // TODO
        CPPUNIT_TEST(test_transpose);
        CPPUNIT_TEST(test_transpose_1);
        CPPUNIT_TEST(test_transpose_2);
        CPPUNIT_TEST(test_transpose_3);
        CPPUNIT_TEST(test_tril);  // TODO
        CPPUNIT_TEST(test_triu);  // TODO
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
        cout << "TestMatrix.c++" << endl;

        CppUnit::TextTestRunner tr;
        tr.addTest(TestMatlab::suite());
        tr.run();
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    cout << "Done." << endl;
    return 0;
}
