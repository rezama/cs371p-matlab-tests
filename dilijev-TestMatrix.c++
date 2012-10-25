// ------------------------------
// projects/matlab/TestMatrix.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
 * To test the program:
 *     g++ -ansi -pedantic -lcppunit -ldl -Wall TestMatrix.c++ -o TestMatrix.app
 *     valgrind TestMatrix.app >& TestMatrix.out
 */

// --------
// includes
// --------
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner
#include "Matrix.h"

// ----------
// TestMatrix
// ----------

struct TestMatrix : CppUnit::TestFixture {
    // ----------------
    // test_constructor
    // ----------------

    void test_constructor_1() {
        Matrix<int> x;
        CPPUNIT_ASSERT(x.size() == 0);
    }

    void test_constructor_2() {
        Matrix<int> y(2);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(y[0].size() == 0);
    }

    void test_constructor_3() {
        Matrix<int> z(2, 3);
        CPPUNIT_ASSERT(z.size() == 2);
        CPPUNIT_ASSERT(z[0].size() == 3);
    }

    void test_constructor_4() {
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(t.size() == 2);
        CPPUNIT_ASSERT(t[0].size() == 3);
        CPPUNIT_ASSERT(t[0][0] == 4);
    }

    //
    // test_makeMatrix
    //

    void test_makeMatrix_1() {
        int arr[] = { 1, 2, 3 };
        Matrix<int> x = Matrix<int>::makeMatrix(arr, 1, 3);

        CPPUNIT_ASSERT(x.size() == 1);
        CPPUNIT_ASSERT(x[0][0] == 1);
        CPPUNIT_ASSERT(x[0][1] == 2);
        CPPUNIT_ASSERT(x[0][2] == 3);
    }

    void test_makeMatrix_2() {
        int arr[] = { 1, 2, 3 };
        Matrix<int> y = Matrix<int>::makeMatrix(arr, 3, 1);

        CPPUNIT_ASSERT(y.size() == 3);
        CPPUNIT_ASSERT(y[0][0] == 1);
        CPPUNIT_ASSERT(y[1][0] == 2);
        CPPUNIT_ASSERT(y[2][0] == 3);
    }

    void test_makeMatrix_3() {
        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
        Matrix<int> x = Matrix<int>::makeMatrix(arr, 2, 4);
        Matrix<int> y = Matrix<int>::makeMatrix(arr, 4, 2);

        CPPUNIT_ASSERT(x.size() == 2);
        CPPUNIT_ASSERT(x[0][3] == 4);
        CPPUNIT_ASSERT(x[1][0] == 5);
        CPPUNIT_ASSERT(x[1][2] == 7);

        CPPUNIT_ASSERT(y.size() == 4);
        CPPUNIT_ASSERT(y[0][1] == 2);
        CPPUNIT_ASSERT(y[1][1] == 4);
        CPPUNIT_ASSERT(y[3][0] == 7);
    }

    // ----------
    // test_index
    // ----------

    void test_index_1() {
        Matrix<int> x(1, 2, 42);
        std::vector<int> v(2, 42);
        CPPUNIT_ASSERT(x[0][0] == 42);
        CPPUNIT_ASSERT(x[0][1] == 42);
        CPPUNIT_ASSERT(x[0] == v);
    }

    void test_index_2() {
        Matrix<int> x(2, 2, 42);
        std::vector<int> v(2, 42);
        CPPUNIT_ASSERT(x[1] == v);
    }

    void test_index_3() {
        Matrix<int> x(2, 3, 42);
        x[0][0] = 3;
        x[0][1] = 6;
        x[0][2] = 9;

        std::vector<int> v(3);
        v[0] = 3;
        v[1] = 6;
        v[2] = 9;

        CPPUNIT_ASSERT(x[0] == v);
    }

    void test_index_4() {
        int arr[2][3] = { { 0, 0, 0 }, { 3, 6, 9 } };
        Matrix<int> x = Matrix<int>::makeMatrix(&arr[0][0], 2, 3);
        x[0][0] = 3;
        x[0][1] = 6;
        x[0][2] = 9;

        std::vector<int> v(3);
        v[0] = 3;
        v[1] = 6;
        v[2] = 9;

        CPPUNIT_ASSERT(x[0] == v);
    }

    // -----------
    // test_equals
    // -----------

    void test_equals_1() {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_equals_2() {
        Matrix<int> x(1, 1, 42);
        Matrix<int> y(1, 1, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        z = (x == y);
        CPPUNIT_ASSERT(x.eq(y));
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_equals_3() {
        Matrix<int> x(1, 2, 42);
        Matrix<int> y(1, 1, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);

        try {
            z = (x == y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_equals_4() {
        Matrix<int> x(34, 2, 42);
        Matrix<int> y(345, 2, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);

        try {
            z = (x == y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_equals_5() {
        Matrix<int> x(34, 2, 42);
        Matrix<int> y(345, 1, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        try {
            z = (x == y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_equals_6() {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        Matrix<bool> z;
        Matrix<bool> t(2, 2, 1);

        x[0][0] = 12;
        y[0][0] = 12;
        x[1][1] = 42;
        y[1][1] = 42;

        z = (x == y);

        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_equals_7() {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        Matrix<bool> z;
        Matrix<bool> t(2, 2, 1);

        x[0][0] = 12;
        y[0][0] = 12;
        x[1][1] = 23;
        y[1][1] = 42;

        z = (x == y);

        t[1][1] = 0;

        CPPUNIT_ASSERT(z.eq(t));
    }

    // -----------
    // test_not_equals
    // -----------

    void test_not_equals_1() {
        Matrix<int> x(1, 1, 2);
        Matrix<int> y(1, 1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);  // all elems are not equal (1's)
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_not_equals_2() {
        Matrix<int> x(1, 1, 42);
        Matrix<int> y(1, 1, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 0);  // all elems are equal (0's)
        z = (x != y);
        CPPUNIT_ASSERT(x.eq(y));
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_not_equals_3() {
        Matrix<int> x(1, 2, 42);
        Matrix<int> y(1, 1, 42);
        Matrix<bool> z;

        try {
            z = (x != y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_not_equals_4() {
        Matrix<int> x(34, 2, 42);
        Matrix<int> y(345, 2, 42);
        Matrix<bool> z;

        try {
            z = (x != y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_not_equals_5() {
        Matrix<int> x(34, 2, 42);
        Matrix<int> y(345, 1, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        try {
            z = (x != y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_not_equals_6() {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        Matrix<bool> z;
        Matrix<bool> t(2, 2, 0);

        x[1][1] = 43;
        y[1][1] = 45;

        t[1][1] = 1;

        z = (x != y);

        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_not_equals_7() {
        Matrix<int> x(2, 2, 3);
        Matrix<int> y(2, 2, 346);
        Matrix<bool> z;
        Matrix<bool> t(2, 2, 1);

        x[0][0] = 12;
        y[0][0] = 12;

        z = (x != y);

        t[0][0] = 0;

        CPPUNIT_ASSERT(z.eq(t));
    }

    // -----------
    // test_less_than
    // -----------

    void test_less_than_1() {
        Matrix<int> x(1, 1, 2);
        Matrix<int> y(1, 1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 0);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_less_than_2() {
        Matrix<int> x(1, 1, 42);
        Matrix<int> y(1, 1, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 0);
        z = (x < y);
        CPPUNIT_ASSERT(x.eq(y));
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_less_than_3() {
        Matrix<int> x(1, 2, 42);
        Matrix<int> y(1, 1, 42);
        Matrix<bool> z;

        try {
            z = (x < y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_less_than_4() {
        Matrix<int> x(34, 2, 42);
        Matrix<int> y(345, 2, 42);
        Matrix<bool> z;

        try {
            z = (x < y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_less_than_5() {
        Matrix<int> x(34, 2, 42);
        Matrix<int> y(345, 1, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);

        try {
            z = (x < y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_less_than_6() {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        Matrix<bool> z;
        Matrix<bool> t(2, 2, 0);

        x[1][1] = 43;
        y[1][1] = 45;

        t[1][1] = 1;

        z = (x < y);

        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_less_than_7() {
        Matrix<int> x(12, 15, 2);
        Matrix<int> y(12, 15, 3);
        Matrix<bool> z;
        Matrix<bool> t(12, 15, 1);

        x[0][0] = 124;
        y[0][0] = 14;

        z = (x < y);

        t[0][0] = 0;

        CPPUNIT_ASSERT(z.eq(t));
    }

    // -----------
    // test_less_than_or_equal
    // -----------

    void test_less_than_or_equal_1() {
        Matrix<int> x(1, 1, 2);
        Matrix<int> y(1, 1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 0);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_less_than_or_equal_2() {
        Matrix<int> x(1, 1, 42);
        Matrix<int> y(1, 1, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        z = (x <= y);
        CPPUNIT_ASSERT(x.eq(y));
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_less_than_or_equal_3() {
        Matrix<int> x(1, 2, 42);
        Matrix<int> y(1, 1, 42);
        Matrix<bool> z;

        try {
            z = (x <= y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_less_than_or_equal_4() {
        Matrix<int> x(34, 2, 42);
        Matrix<int> y(345, 2, 42);
        Matrix<bool> z;

        try {
            z = (x <= y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_less_than_or_equal_5() {
        Matrix<int> x(34, 2, 42);
        Matrix<int> y(345, 1, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);

        try {
            z = (x <= y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_less_than_or_equal_6() {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        Matrix<bool> z;
        Matrix<bool> t(2, 2, 1);

        x[1][1] = 546;
        y[1][1] = 45;

        t[1][1] = 0;

        z = (x <= y);

        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_less_than_or_equal_7() {
        Matrix<int> x(12, 15, 3);
        Matrix<int> y(12, 15, 2);
        Matrix<bool> z;
        Matrix<bool> t(12, 15, 0);

        x[0][0] = 12;
        y[0][0] = 14;

        z = (x <= y);

        t[0][0] = 1;

        CPPUNIT_ASSERT(z.eq(t));
    }

    // -----------
    // test_greater_than
    // -----------

    void test_greater_than_1() {
        Matrix<int> x(1, 1, 2);
        Matrix<int> y(1, 1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_greater_than_2() {
        Matrix<int> x(1, 1, 42);
        Matrix<int> y(1, 1, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 0);
        z = (x > y);
        CPPUNIT_ASSERT(x.eq(y));
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_greater_than_3() {
        Matrix<int> x(1, 2, 42);
        Matrix<int> y(1, 1, 42);
        Matrix<bool> z;

        try {
            z = (x > y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_greater_than_4() {
        Matrix<int> x(34, 2, 42);
        Matrix<int> y(345, 2, 42);
        Matrix<bool> z;

        try {
            z = (x > y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_greater_than_5() {
        Matrix<int> x(34, 2, 42);
        Matrix<int> y(345, 1, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);

        try {
            z = (x > y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_greater_than_6() {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        Matrix<bool> z;
        Matrix<bool> t(2, 2, 0);

        x[1][1] = 546;
        y[1][1] = 45;

        t[1][1] = 1;

        z = (x > y);

        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_greater_than_7() {
        Matrix<int> x(12, 15, 3);
        Matrix<int> y(12, 15, 2);
        Matrix<bool> z;
        Matrix<bool> t(12, 15, 1);

        x[0][0] = 12;
        y[0][0] = 134;

        z = (x > y);

        t[0][0] = 0;

        CPPUNIT_ASSERT(z.eq(t));
    }

    // -----------
    // test_greater_than_or_equal
    // -----------

    void test_greater_than_or_equal_1() {
        Matrix<int> x(1, 1, 2);
        Matrix<int> y(1, 1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_greater_than_or_equal_2() {
        Matrix<int> x(1, 1, 42);
        Matrix<int> y(1, 1, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        z = (x >= y);
        CPPUNIT_ASSERT(x.eq(y));
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_greater_than_or_equal_3() {
        Matrix<int> x(1, 2, 42);
        Matrix<int> y(1, 1, 42);
        Matrix<bool> z;

        try {
            z = (x >= y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_greater_than_or_equal_4() {
        Matrix<int> x(34, 2, 42);
        Matrix<int> y(345, 2, 42);
        Matrix<bool> z;

        try {
            z = (x >= y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_greater_than_or_equal_5() {
        Matrix<int> x(34, 2, 42);
        Matrix<int> y(345, 1, 42);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);

        try {
            z = (x >= y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_greater_than_or_equal_6() {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        Matrix<bool> z;
        Matrix<bool> t(2, 2, 1);

        x[1][1] = 3;
        y[1][1] = 45;

        t[1][1] = 0;

        z = (x >= y);

        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_greater_than_or_equal_7() {
        Matrix<int> x(12, 15, 2);
        Matrix<int> y(12, 15, 3);
        Matrix<bool> z;
        Matrix<bool> t(12, 15, 0);

        x[0][0] = 1424;
        y[0][0] = 14;

        z = (x >= y);

        t[0][0] = 1;

        CPPUNIT_ASSERT(z.eq(t));
    }

    // ---------
    // test_plus
    // ---------

    void test_plus_1() {
        int a[] = { 1, 2, 3, 4 };
        int b[] = { 2, 3, 4, 5 };
        int c[] = { 3, 5, 7, 9 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 2, 2);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 2, 2);
        Matrix<int> z(x);

        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        z = Matrix<int>::makeMatrix(c, 2, 2);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_plus_2() {
        int a[] = { 0 };
        int b[] = { 123 };
        int c[] = { 32 };
        int d[] = { 155 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 1, 1);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 1, 1);
        Matrix<int> z = Matrix<int>::makeMatrix(c, 1, 1);

        x += 32;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        z = Matrix<int>::makeMatrix(d, 1, 1);
        CPPUNIT_ASSERT(x.eq(z));
        CPPUNIT_ASSERT(x[0][0] == 155);
    }

    void test_plus_3() {
        Matrix<int> x(2, 3);
        Matrix<int> y(2, 34);
        Matrix<int> z;
        try {
            z = (x + y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_plus_4() {
        Matrix<int> x(2, 3);
        Matrix<int> y(23, 3);
        Matrix<int> z;
        try {
            z = (x + y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_plus_5() {
        Matrix<int> x(32, 3);
        Matrix<int> y(2, 546);
        Matrix<int> z;
        try {
            z = (x + y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_plus_6() {
        int a[] = { 0 };
        int b[] = { 123 };
        int c[] = { 32 };
        int d[] = { 155 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 1, 1);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 1, 1);
        Matrix<int> z = Matrix<int>::makeMatrix(c, 1, 1);
        x += 32;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        z = Matrix<int>::makeMatrix(d, 1, 1);
        CPPUNIT_ASSERT(x.eq(z));
        CPPUNIT_ASSERT(x[0][0] == 155);
    }

    // ----------
    // test_minus
    // ----------

    void test_minus() {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_minus_1() {
        int a[] = { 1, 2, 3, 4 };
        int b[] = { 2, 3, 4, 5 };
        int c[] = { 3, 5, 7, 9 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 2, 2);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 2, 2);
        Matrix<int> z(x);
        Matrix<int> t = Matrix<int>::makeMatrix(c, 2, 2);

        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));

        t -= y;
        CPPUNIT_ASSERT(t.eq(x));
    }

    void test_minus_2() {
        int a[] = { 32 };
        int b[] = { 155 };
        int c[] = { 0 };
        int d[] = { 123 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 1, 1);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 1, 1);
        Matrix<int> z = Matrix<int>::makeMatrix(c, 1, 1);
        Matrix<int> t = Matrix<int>::makeMatrix(d, 1, 1);

        x -= 32;
        CPPUNIT_ASSERT(x.eq(z));
        x += 32;

        y -= x;
        CPPUNIT_ASSERT(y.eq(t));
        CPPUNIT_ASSERT(y[0][0] == 123);
    }

    void test_minus_3() {
        Matrix<int> x(2, 3);
        Matrix<int> y(2, 34);
        Matrix<int> z;

        try {
            z = (x - y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_minus_4() {
        Matrix<int> x(2, 3);
        Matrix<int> y(23, 3);
        Matrix<int> z;
        try {
            z = (x - y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_minus_5() {
        Matrix<int> x(32, 3);
        Matrix<int> y(2, 546);
        Matrix<int> z;
        try {
            z = (x - y);
            CPPUNIT_ASSERT(false);
        } catch (Matrix<int>::DimensionException& e) {
            CPPUNIT_ASSERT(true);
        }
    }

    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies() {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_multiplies_1() {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, 42);
        x *= 42;
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_multiplies_2() {
        Matrix<int> x(2, 2, 2);
        Matrix<int> y(2, 2, 4);
        x *= 2;
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_multiplies_3() {
        Matrix<float> x(2, 2, 1);
        Matrix<float> y(2, 2, 1. / 6);
        x *= 1. / 6;
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_multiplies_4() {
        int a[] = { 2 };
        int b[] = { 4 };
        int c[] = { 8 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 1, 1);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 1, 1);
        Matrix<int> z = Matrix<int>::makeMatrix(c, 1, 1);

        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_multiplies_5() {
        int a[] = { 2, 1 };
        int b[] = { 3, 6 };
        int c[] = { 12 };
        Matrix<int> x = Matrix<int>::makeMatrix(a, 1, 2);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 2, 1);
        Matrix<int> z = Matrix<int>::makeMatrix(c, 1, 1);

        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_multiplies_6() {
        int a[] = { 1, 2, 3, 4, 5, 6 };
        int b[] = { 3, 4, 5 };
        int c[] = { 26, 62 };

        Matrix<int> x = Matrix<int>::makeMatrix(a, 2, 3);
        Matrix<int> y = Matrix<int>::makeMatrix(b, 3, 1);
        Matrix<int> z = Matrix<int>::makeMatrix(c, 2, 1);

        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    // -------------
    // test_iterator
    // -------------

    void test_iterator() {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);
    }

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator() {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);
    }

    // -----
    // suite
    // -----

CPPUNIT_TEST_SUITE(TestMatrix);
        CPPUNIT_TEST(test_constructor_1);
        CPPUNIT_TEST(test_constructor_2);
        CPPUNIT_TEST(test_constructor_3);
        CPPUNIT_TEST(test_constructor_4);
        CPPUNIT_TEST(test_makeMatrix_1);
        CPPUNIT_TEST(test_makeMatrix_2);
        CPPUNIT_TEST(test_makeMatrix_3);
        CPPUNIT_TEST(test_index_1);
        CPPUNIT_TEST(test_index_2);
        CPPUNIT_TEST(test_index_3);
        CPPUNIT_TEST(test_index_4);
        CPPUNIT_TEST(test_equals_1);
        CPPUNIT_TEST(test_equals_2);
        CPPUNIT_TEST(test_equals_3);
        CPPUNIT_TEST(test_equals_4);
        CPPUNIT_TEST(test_equals_5);
        CPPUNIT_TEST(test_equals_6);
        CPPUNIT_TEST(test_equals_7);
        CPPUNIT_TEST(test_not_equals_1);
        CPPUNIT_TEST(test_not_equals_2);
        CPPUNIT_TEST(test_not_equals_3);
        CPPUNIT_TEST(test_not_equals_4);
        CPPUNIT_TEST(test_not_equals_5);
        CPPUNIT_TEST(test_not_equals_6);
        CPPUNIT_TEST(test_not_equals_7);
        CPPUNIT_TEST(test_less_than_1);
        CPPUNIT_TEST(test_less_than_2);
        CPPUNIT_TEST(test_less_than_3);
        CPPUNIT_TEST(test_less_than_4);
        CPPUNIT_TEST(test_less_than_5);
        CPPUNIT_TEST(test_less_than_6);
        CPPUNIT_TEST(test_less_than_7);
        CPPUNIT_TEST(test_less_than_or_equal_1);
        CPPUNIT_TEST(test_less_than_or_equal_2);
        CPPUNIT_TEST(test_less_than_or_equal_3);
        CPPUNIT_TEST(test_less_than_or_equal_4);
        CPPUNIT_TEST(test_less_than_or_equal_5);
        CPPUNIT_TEST(test_less_than_or_equal_6);
        CPPUNIT_TEST(test_less_than_or_equal_7);
        CPPUNIT_TEST(test_greater_than_1);
        CPPUNIT_TEST(test_greater_than_2);
        CPPUNIT_TEST(test_greater_than_3);
        CPPUNIT_TEST(test_greater_than_4);
        CPPUNIT_TEST(test_greater_than_5);
        CPPUNIT_TEST(test_greater_than_6);
        CPPUNIT_TEST(test_greater_than_7);
        CPPUNIT_TEST(test_greater_than_or_equal_1);
        CPPUNIT_TEST(test_greater_than_or_equal_2);
        CPPUNIT_TEST(test_greater_than_or_equal_3);
        CPPUNIT_TEST(test_greater_than_or_equal_4);
        CPPUNIT_TEST(test_greater_than_or_equal_5);
        CPPUNIT_TEST(test_greater_than_or_equal_6);
        CPPUNIT_TEST(test_greater_than_or_equal_7);
        CPPUNIT_TEST(test_plus_1);
        CPPUNIT_TEST(test_plus_2);
        CPPUNIT_TEST(test_plus_3);
        CPPUNIT_TEST(test_plus_4);
        CPPUNIT_TEST(test_plus_5);
        CPPUNIT_TEST(test_plus_6);
        CPPUNIT_TEST(test_minus);
        CPPUNIT_TEST(test_minus_1);
        CPPUNIT_TEST(test_minus_2);
        CPPUNIT_TEST(test_minus_3);
        CPPUNIT_TEST(test_minus_4);
        CPPUNIT_TEST(test_minus_5);
        CPPUNIT_TEST(test_multiplies);
        CPPUNIT_TEST(test_multiplies_1);
        CPPUNIT_TEST(test_multiplies_2);
        CPPUNIT_TEST(test_multiplies_3);
        CPPUNIT_TEST(test_multiplies_4);
        CPPUNIT_TEST(test_multiplies_5);
        CPPUNIT_TEST(test_multiplies_6);
        CPPUNIT_TEST(test_iterator);
        CPPUNIT_TEST(test_const_iterator);
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
        tr.addTest(TestMatrix::suite());
        tr.run();
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    cout << "Done." << endl;
    return 0;
}
