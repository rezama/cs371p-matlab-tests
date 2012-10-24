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

    void test_constructor () {
        Matrix<int> x;
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(x.size() == 0);}

    void test_constructor_onearg () {
        Matrix<int> x(1);
        CPPUNIT_ASSERT(x.size() == 1);
        Matrix<int> y(16);
        CPPUNIT_ASSERT(y.size() == 16);
    }

    void test_constructor_twoarg_sq () {
        Matrix<int> x(1,1);
        CPPUNIT_ASSERT(x.size() == 1);
        Matrix<int> y(15,15);
        CPPUNIT_ASSERT(y.size() == 15);
    }

    void test_constructor_twoarg_rect () {
        Matrix<int> x(1,16);
        CPPUNIT_ASSERT(x.size() == 1);
        Matrix<int> y(16,1);
        CPPUNIT_ASSERT(y.size() == 16);
    }


    // ----------
    // test_index
    // ----------

    void test_index () {
        const Matrix<int> x(1,1);
        CPPUNIT_ASSERT(x[0][0] == 0);}

    void test_index_sq () {
        const Matrix<int> x(4,4);
        CPPUNIT_ASSERT(x[0][0] == 0);
        CPPUNIT_ASSERT(x[0][1] == 0);
        CPPUNIT_ASSERT(x[0][2] == 0);
        CPPUNIT_ASSERT(x[0][3] == 0);

        CPPUNIT_ASSERT(x[1][0] == 0);
        CPPUNIT_ASSERT(x[1][1] == 0);
        CPPUNIT_ASSERT(x[1][2] == 0);
        CPPUNIT_ASSERT(x[1][3] == 0);

        CPPUNIT_ASSERT(x[2][0] == 0);
        CPPUNIT_ASSERT(x[2][1] == 0);
        CPPUNIT_ASSERT(x[2][2] == 0);
        CPPUNIT_ASSERT(x[2][3] == 0);

        CPPUNIT_ASSERT(x[3][0] == 0);
        CPPUNIT_ASSERT(x[3][1] == 0);
        CPPUNIT_ASSERT(x[3][2] == 0);
        CPPUNIT_ASSERT(x[3][3] == 0);
    }

    void test_index_rect () {
        const Matrix<int> x(3,5);
        CPPUNIT_ASSERT(x[0][0] == 0);
        CPPUNIT_ASSERT(x[0][1] == 0);
        CPPUNIT_ASSERT(x[0][2] == 0);
        CPPUNIT_ASSERT(x[0][3] == 0);
        CPPUNIT_ASSERT(x[0][4] == 0);

        CPPUNIT_ASSERT(x[1][0] == 0);
        CPPUNIT_ASSERT(x[1][1] == 0);
        CPPUNIT_ASSERT(x[1][2] == 0);
        CPPUNIT_ASSERT(x[1][3] == 0);
        CPPUNIT_ASSERT(x[1][4] == 0);

        CPPUNIT_ASSERT(x[2][0] == 0);
        CPPUNIT_ASSERT(x[2][1] == 0);
        CPPUNIT_ASSERT(x[2][2] == 0);
        CPPUNIT_ASSERT(x[2][3] == 0);
        CPPUNIT_ASSERT(x[2][4] == 0);
    }

    // ---------------------
    // test_constructor_deep
    // ---------------------
    void test_constructor_deep_onearg () {
        Matrix<int> x(1);
        CPPUNIT_ASSERT(x.size() == 1);
        CPPUNIT_ASSERT(x[0].size() == 0);
        Matrix<int> y(16);
        CPPUNIT_ASSERT(y.size() == 16);
        CPPUNIT_ASSERT(y[0].size() == 0);
    }

    void test_constructor_deep_twoarg_sq () {
        Matrix<int> x(1,1);
        CPPUNIT_ASSERT(x.size() == 1);
        CPPUNIT_ASSERT(x[0].size() == 1);
        Matrix<int> y(15,15);
        CPPUNIT_ASSERT(y.size() == 15);
        CPPUNIT_ASSERT(y[0].size() == 15);
    }

    void test_constructor_deep_twoarg_rect () {
        Matrix<int> x(1,16);
        CPPUNIT_ASSERT(x.size() == 1);
        CPPUNIT_ASSERT(x[0].size() == 16);
        Matrix<int> y(16,1);
        CPPUNIT_ASSERT(y.size() == 16);
        CPPUNIT_ASSERT(y[0].size() == 1);
    }

    void test_constructor_deep_threearg_sq () {
        Matrix<int> x(1,1,0xFF);
        CPPUNIT_ASSERT(x.size() == 1);
        CPPUNIT_ASSERT(x[0].size() == 1);
        CPPUNIT_ASSERT(x[0][0] == 0xFF);
        Matrix<int> y(15,15,0x80000000);
        CPPUNIT_ASSERT(y.size() == 15);
        CPPUNIT_ASSERT(y[0].size() == 15);
        CPPUNIT_ASSERT(y[0][0] == (int) 0x80000000);
    }

    void test_constructor_deep_threearg_rect () {
        Matrix<int> x(1,16,0x7FFFFFFF);
        CPPUNIT_ASSERT(x.size() == 1);
        CPPUNIT_ASSERT(x[0].size() == 16);
        CPPUNIT_ASSERT(x[0][0] == 0x7FFFFFFF);
        Matrix<int> y(16,1,0xFFFFFFFF);
        CPPUNIT_ASSERT(y.size() == 16);
        CPPUNIT_ASSERT(y[0].size() == 1);
        CPPUNIT_ASSERT(y[0][0] == (int) 0xFFFFFFFF);
    }

    // --------------
    // test_index_val
    // --------------

    void t_index_sq_val (int v, size_t r = 100, size_t c = 100) {
        const Matrix<int> x(r,c,v);
        
        for (size_t i = 0; i < r; ++i) {
            for (size_t j = 0; j < c; ++j) {
                CPPUNIT_ASSERT(x[i][j] == v);
            }
        }
    }

    void test_index_sq_ffffffff () {
        t_index_sq_val(0xFFFFFFFF);
    }

    void test_index_rect_ffffffff () {
        t_index_sq_val(0xFFFFFFFF,1,300);
    }

    void test_index_sq_7fffffff () {
        t_index_sq_val(0x7FFFFFFF);
    }

    void test_index_rect_7fffffff () {
        t_index_sq_val(0x7FFFFFFF,300,1);
    }

    void test_index_sq_80000000 () {
        t_index_sq_val(0x80000000);
    }

    void test_index_rect_80000000 () {
        t_index_sq_val(0x80000000,200,3);
    }

    // -----------
    // test_equals
    // -----------

    // Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
    // Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
    // Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
    // Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");

    void test_equals () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_equals_1 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<bool> r(6,5,false);
        CPPUNIT_ASSERT(r.eq(a == b));
        CPPUNIT_ASSERT(r.eq(b == a));
    }

    void test_equals_2 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<bool> r("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        CPPUNIT_ASSERT(r.eq(a == c));
        CPPUNIT_ASSERT(r.eq(c == a));
    }

    void test_equals_3 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<bool> r("0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;");
        CPPUNIT_ASSERT(r.eq(a == d));
        CPPUNIT_ASSERT(r.eq(d == a));
    }

    void test_equals_4 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<bool> r("0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;");
        CPPUNIT_ASSERT(r.eq(b == c));
        CPPUNIT_ASSERT(r.eq(c == b));
    }

    void test_equals_5 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<bool> r("1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;");
        CPPUNIT_ASSERT(r.eq(b == d));
        CPPUNIT_ASSERT(r.eq(d == b));
    }

    // --------------
    // test_less_than
    // --------------

    void test_less_than_1 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<bool> r("1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;");
        CPPUNIT_ASSERT(r.eq(a < b));
        r = Matrix<bool>("0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;");
        CPPUNIT_ASSERT(r.eq(b < a));
    }

    void test_less_than_2 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<bool> r(6,5,false);
        CPPUNIT_ASSERT(r.eq(a < c));
    }

    void test_less_than_3 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<bool> r("1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;");
        CPPUNIT_ASSERT(r.eq(a < d));
    }

    void test_less_than_4 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<bool> r(6,5,false);
        CPPUNIT_ASSERT(r.eq(b < c));
    }

    void test_less_than_5 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<bool> r("0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;");
        CPPUNIT_ASSERT(r.eq(b < d));
    }

    // -----------------------
    // test_less_than_or_equal
    // -----------------------

    void test_less_than_or_equal_1 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<bool> r("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        CPPUNIT_ASSERT(r.eq(a <= b));
        r = Matrix<bool>("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        CPPUNIT_ASSERT(r.eq(b <= a));
    }

    void test_less_than_or_equal_2 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<bool> r("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        CPPUNIT_ASSERT(r.eq(a <= c));
    }

    void test_less_than_or_equal_3 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<bool> r(6,5,true);
        CPPUNIT_ASSERT(r.eq(a <= d));
    }

    void test_less_than_or_equal_4 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<bool> r("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        CPPUNIT_ASSERT(r.eq(b <= c));
    }

    void test_less_than_or_equal_5 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<bool> r(6,5,true);
        CPPUNIT_ASSERT(r.eq(b <= d));
    }

    // -----------------
    // test_greater_than
    // -----------------

    void test_greater_than_1 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<bool> r("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        CPPUNIT_ASSERT(r.eq(a > b));
        r = Matrix<bool>("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        CPPUNIT_ASSERT(r.eq(b > a));
    }

    void test_greater_than_2 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<bool> r("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        CPPUNIT_ASSERT(r.eq(a > c));
    }

    void test_greater_than_3 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<bool> r(6,5,false);
        CPPUNIT_ASSERT(r.eq(a > d));
    }

    void test_greater_than_4 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<bool> r("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        CPPUNIT_ASSERT(r.eq(b > c));
    }

    void test_greater_than_5 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<bool> r(6,5,false);
        CPPUNIT_ASSERT(r.eq(b > d));
    }

    // --------------------------
    // test_greater_than_or_equal
    // --------------------------

    void test_greater_than_or_equal_1 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<bool> r("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        CPPUNIT_ASSERT(r.eq(a >= b));
        r = Matrix<bool>("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        CPPUNIT_ASSERT(r.eq(b >= a));
    }

    void test_greater_than_or_equal_2 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<bool> r(6,5,true);
        CPPUNIT_ASSERT(r.eq(a >= c));
    }

    void test_greater_than_or_equal_3 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<bool> r("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        CPPUNIT_ASSERT(r.eq(a >= d));
    }

    void test_greater_than_or_equal_4 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<bool> r(6,5,true);
        CPPUNIT_ASSERT(r.eq(b >= c));
    }

    void test_greater_than_or_equal_5 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<bool> r("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        CPPUNIT_ASSERT(r.eq(b >= d));
    }


    // ---------
    // test_plus
    // ---------

    void test_plus () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_plus_1 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> r("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        CPPUNIT_ASSERT(r.eq(a + b));
        CPPUNIT_ASSERT(r.eq(b + a));
    }

    void test_plus_2 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<int> r("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        CPPUNIT_ASSERT(r.eq(a + c));
        CPPUNIT_ASSERT(r.eq(c + a));
    }

    void test_plus_3 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<int> r("[1,2,1,2,1;2,1,2,1,2;1,2,1,2,1;2,1,2,1,2;1,2,1,2,1;2,1,2,1,2]");
        CPPUNIT_ASSERT(r.eq(a + d));
        CPPUNIT_ASSERT(r.eq(d + a));
    }

    void test_plus_4 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<int> r("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        CPPUNIT_ASSERT(r.eq(b + c));
        CPPUNIT_ASSERT(r.eq(c + b));
    }

    void test_plus_5 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<int> r("[2,1,2,1,2;1,2,1,2,1;2,1,2,1,2;1,2,1,2,1;2,1,2,1,2;1,2,1,2,1]");
        CPPUNIT_ASSERT(r.eq(b + d));
        CPPUNIT_ASSERT(r.eq(d + b));
    }

    // ----------
    // test_minus
    // ----------

    void test_minus () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_minus_1 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> r("[-1,1,-1,1,-1;1,-1,1,-1,1;-1,1,-1,1,-1;1,-1,1,-1,1;-1,1,-1,1,-1;1,-1,1,-1,1]");
        CPPUNIT_ASSERT(r.eq(a - b));
        r = Matrix<int>("[1,-1,1,-1,1;-1,1,-1,1,-1;1,-1,1,-1,1;-1,1,-1,1,-1;1,-1,1,-1,1;-1,1,-1,1,-1]");
        CPPUNIT_ASSERT(r.eq(b - a));
    }

    void test_minus_2 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<int> r("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        CPPUNIT_ASSERT(r.eq(a - c));
    }

    void test_minus_3 () {
        Matrix<int> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<int> r("[-1,0,-1,0,-1;0,-1,0,-1,0;-1,0,-1,0,-1;0,-1,0,-1,0;-1,0,-1,0,-1;0,-1,0,-1,0]");
        CPPUNIT_ASSERT(r.eq(a - d));
    }

    void test_minus_4 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<int> r("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        CPPUNIT_ASSERT(r.eq(b - c));
    }

    void test_minus_5 () {
        Matrix<int> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<int> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");
        Matrix<int> r("[0,-1,0,-1,0;-1,0,-1,0,-1;0,-1,0,-1,0;-1,0,-1,0,-1;0,-1,0,-1,0;-1,0,-1,0,-1]");
        CPPUNIT_ASSERT(r.eq(b - d));
    }

    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}

    //A* is 5x5
    void test_multiplies_A () {
        Matrix<int> AL("[122,196,125,143,54;160,239,50,197,131;61,28,229,80,232;46,47,26,46,161;212,26,12,87,26]");
        Matrix<int> AZ("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<int> ans("[71895,82381,58041,77334,85691;97644,102546,50094,94422,86672;78755,34852,66330,56423,79002;50966,27325,17182,34040,26265;40270,52867,33122,42662,32321]");
        CPPUNIT_ASSERT(ans.eq(AL * AL));
        ans = Matrix<int>("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        CPPUNIT_ASSERT(ans.eq(AZ * AL));
        ans = Matrix<int>("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        CPPUNIT_ASSERT(ans.eq(AL * AZ));
        ans = Matrix<int>("[4026,6468,4125,4719,1782;5280,7887,1650,6501,4323;2013,924,7557,2640,7656;1518,1551,858,1518,5313;6996,858,396,2871,858]");
        CPPUNIT_ASSERT(ans.eq(AL * 33));
    }

    void test_multiplies_A_scalar () {
        Matrix<int> AL("[122,196,125,143,54;160,239,50,197,131;61,28,229,80,232;46,47,26,46,161;212,26,12,87,26]");
        Matrix<int> ans("[4026,6468,4125,4719,1782;5280,7887,1650,6501,4323;2013,924,7557,2640,7656;1518,1551,858,1518,5313;6996,858,396,2871,858]");
        CPPUNIT_ASSERT(ans.eq(AL * 33));
    }

    //BL is 6x9
    //BR is 9x6
    void test_multiplies_B () {
        Matrix<int> BL("[391,486,713,646,552,756,837,282,48;55,894,618,833,979,414,739,231,349;501,138,343,398,549,492,954,711,451;432,390,936,750,331,695,32,624,241;997,927,125,835,619,972,357,591,715;811,917,730,323,361,328,662,660,856]");
        Matrix<int> BR("[282,490,586,232,884,686;731,877,675,404,95,893;138,353,361,122,930,55;836,449,620,269,399,304;139,963,811,258,48,47;588,43,20,332,343,196;366,972,84,153,736,720;806,190,974,348,794,722;504,667,651,122,545,877]");        
        Matrix<int> ans("[2183060,2622799,2054105,1173277,2464562,1960283;2462765,3358719,2691756,1299472,2147174,2255386;2137363,2579335,2278649,1074290,2641367,2324761;2253871,1879917,2368994,1141314,2493294,1760804;3299046,3294641,3365328,1675602,2903617,3302870;2718516,3305879,3113046,1371999,3219440,3298696]");
        CPPUNIT_ASSERT(ans.eq(BL * BR));        
        ans = Matrix<int>("[1968716,2194990,1533316,1957288,1828722,1949860,1934332,1729332,1724020;1665697,2296960,2336623,2142181,2147572,1913838,2541909,1786275,1575283;1278753,1392593,710963,1412690,1255859,1434872,1093091,1039188,1034064;1422746,1646813,1609789,1793940,1687187,1797437,1975322,1384596,1086787;711054,1228609,1254212,1463512,1596821,1144160,1658200,1058652,845250;886644,954143,949385,1022340,770618,1100594,805840,729210,545284;1622458,2460618,1651274,2041414,1965883,1778319,1849074,1393116,1574113;2341066,2229820,1978218,2223794,2032964,2417648,2516786,2126622,1813882;1867216,2288084,1817378,1970139,1982934,1879640,2314858,1736109,1720365]");
        CPPUNIT_ASSERT(ans.eq(BR * BL));
    }

    void test_multiplies_B_scalar () {
        Matrix<int> BL("[391,486,713,646,552,756,837,282,48;55,894,618,833,979,414,739,231,349;501,138,343,398,549,492,954,711,451;432,390,936,750,331,695,32,624,241;997,927,125,835,619,972,357,591,715;811,917,730,323,361,328,662,660,856]");
        Matrix<int> BR("[282,490,586,232,884,686;731,877,675,404,95,893;138,353,361,122,930,55;836,449,620,269,399,304;139,963,811,258,48,47;588,43,20,332,343,196;366,972,84,153,736,720;806,190,974,348,794,722;504,667,651,122,545,877]");        
        Matrix<int> ans("[26197,32562,47771,43282,36984,50652,56079,18894,3216;3685,59898,41406,55811,65593,27738,49513,15477,23383;33567,9246,22981,26666,36783,32964,63918,47637,30217;28944,26130,62712,50250,22177,46565,2144,41808,16147;66799,62109,8375,55945,41473,65124,23919,39597,47905;54337,61439,48910,21641,24187,21976,44354,44220,57352]");
        CPPUNIT_ASSERT(ans.eq(BL * 67));
        ans = Matrix<int>("[-26979,-33534,-49197,-44574,-38088,-52164,-57753,-19458,-3312;-3795,-61686,-42642,-57477,-67551,-28566,-50991,-15939,-24081;-34569,-9522,-23667,-27462,-37881,-33948,-65826,-49059,-31119;-29808,-26910,-64584,-51750,-22839,-47955,-2208,-43056,-16629;-68793,-63963,-8625,-57615,-42711,-67068,-24633,-40779,-49335;-55959,-63273,-50370,-22287,-24909,-22632,-45678,-45540,-59064]");
        CPPUNIT_ASSERT(ans.eq(BL * -69));
        ans = Matrix<int>("[-18612,-32340,-38676,-15312,-58344,-45276;-48246,-57882,-44550,-26664,-6270,-58938;-9108,-23298,-23826,-8052,-61380,-3630;-55176,-29634,-40920,-17754,-26334,-20064;-9174,-63558,-53526,-17028,-3168,-3102;-38808,-2838,-1320,-21912,-22638,-12936;-24156,-64152,-5544,-10098,-48576,-47520;-53196,-12540,-64284,-22968,-52404,-47652;-33264,-44022,-42966,-8052,-35970,-57882]");
        CPPUNIT_ASSERT(ans.eq(BR * -66));
    }

    //BL is 6x9
    //BR is 9x7
    void test_multiplies_B_2 () {
        Matrix<int> BL("[391,486,713,646,552,756,837,282,48;55,894,618,833,979,414,739,231,349;501,138,343,398,549,492,954,711,451;432,390,936,750,331,695,32,624,241;997,927,125,835,619,972,357,591,715;811,917,730,323,361,328,662,660,856]");
        Matrix<int> BR("[582,433,476,939,728,849,407;71,471,363,980,577,373,667;922,561,788,287,26,593,933;800,269,780,801,447,872,811;286,749,668,896,646,933,485;544,504,134,597,521,668,756;984,647,22,884,372,207,417;715,308,560,943,937,654,971;839,139,301,549,829,72,987]");
        Matrix<int> ans("[3070900,2401515,2089080,3543616,2238228,2880525,3181917;3022042,2555383,2447541,3959416,2573101,2992141,3535566;3186178,2139500,1856853,3569954,2637138,2563095,3110303;2894699,1942186,2406693,3117750,2271414,2926441,3460562;3508861,2628969,2658642,4949697,3822782,3733185,4281380;3591739,2465766,2473007,4325226,3261280,2931349,4069598]");
        CPPUNIT_ASSERT(ans.eq(BL * BR));
    }

    void test_multiplies_B_scalar_2 () { 
        Matrix<int> BR("[582,433,476,939,728,849,407;71,471,363,980,577,373,667;922,561,788,287,26,593,933;800,269,780,801,447,872,811;286,749,668,896,646,933,485;544,504,134,597,521,668,756;984,647,22,884,372,207,417;715,308,560,943,937,654,971;839,139,301,549,829,72,987]");
        Matrix<int> ans("[244440,181860,199920,394380,305760,356580,170940;29820,197820,152460,411600,242340,156660,280140;387240,235620,330960,120540,10920,249060,391860;336000,112980,327600,336420,187740,366240,340620;120120,314580,280560,376320,271320,391860,203700;228480,211680,56280,250740,218820,280560,317520;413280,271740,9240,371280,156240,86940,175140;300300,129360,235200,396060,393540,274680,407820;352380,58380,126420,230580,348180,30240,414540]");
        CPPUNIT_ASSERT(ans.eq(BR * 420));
    }

    //CL is 1x10
    //CR is 10x1
    void test_multiplies_C () {
        Matrix<int> CL("[864,389,455,247,784,882,913,558,599,149]");
        Matrix<int> CR("[899;450;206;899;762;882;285;673;664;123]");
        Matrix<int> ans("[3694703]");
        CPPUNIT_ASSERT(ans.eq(CL * CR));
        ans = Matrix<int>("[776736,349711,409045,222053,704816,792918,820787,501642,538501,133951;388800,175050,204750,111150,352800,396900,410850,251100,269550,67050;177984,80134,93730,50882,161504,181692,188078,114948,123394,30694;776736,349711,409045,222053,704816,792918,820787,501642,538501,133951;658368,296418,346710,188214,597408,672084,695706,425196,456438,113538;762048,343098,401310,217854,691488,777924,805266,492156,528318,131418;246240,110865,129675,70395,223440,251370,260205,159030,170715,42465;581472,261797,306215,166231,527632,593586,614449,375534,403127,100277;573696,258296,302120,164008,520576,585648,606232,370512,397736,98936;106272,47847,55965,30381,96432,108486,112299,68634,73677,18327]");
        CPPUNIT_ASSERT(ans.eq(CR * CL));
    }

    void test_multiplies_C_scalar () {
        Matrix<int> CL("[864,389,455,247,784,882,913,558,599,149]");
        Matrix<int> CR("[899;450;206;899;762;882;285;673;664;123]");
        Matrix<int> ans("[95904,43179,50505,27417,87024,97902,101343,61938,66489,16539]");
        CPPUNIT_ASSERT(ans.eq(CL * 111));
        ans = Matrix<int>("[-29667;-14850;-6798;-29667;-25146;-29106;-9405;-22209;-21912;-4059]");
        CPPUNIT_ASSERT(ans.eq(CR * -33));

    }

    //CL is 10x1
    //CD is 1x3
    void test_multiplies_C_2 () {
        Matrix<int> CR("[407,276,716]");
        Matrix<int> CL("[899;450;206;899;762;882;285;673;664;123]");
        Matrix<int> ans("[365893,248124,643684;183150,124200,322200;83842,56856,147496;365893,248124,643684;310134,210312,545592;358974,243432,631512;115995,78660,204060;273911,185748,481868;270248,183264,475424;50061,33948,88068]");
        CPPUNIT_ASSERT(ans.eq(CL * CR));
    }

    void test_multiplies_C_scalar_2 () {
        Matrix<int> CR("[407,276,716]");
        Matrix<int> CL("[899;450;206;899;762;882;285;673;664;123]");
        Matrix<int> ans("[-27269,-18492,-47972]");
        CPPUNIT_ASSERT(ans.eq(CR * -67));
        ans = Matrix<int>("[598734;299700;137196;598734;507492;587412;189810;448218;442224;81918]");
        CPPUNIT_ASSERT(ans.eq(CL * 666));
    }



    // -------------
    // test_iterator
    // -------------

    void test_iterator () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    void test_iterator_2 () {
        Matrix<int> x(5,0);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b != e);
        b += 5;
        CPPUNIT_ASSERT(b == e);
    }

    void test_iterator_3 () {
        Matrix<int> x(5,5);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b != e);
        b += 5;
        CPPUNIT_ASSERT(b == e);
    }

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    void test_const_iterator_2 () {
        const Matrix<int> x(5,0);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b != e);
        b += 5;
        CPPUNIT_ASSERT(b == e);
    }

    void test_const_iterator_3 () {
        const Matrix<int> x(5,5);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b != e);
        b += 5;
        CPPUNIT_ASSERT(b == e);
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_constructor_onearg);
    CPPUNIT_TEST(test_constructor_twoarg_sq);

    CPPUNIT_TEST(test_index);
    CPPUNIT_TEST(test_index_sq);
    CPPUNIT_TEST(test_index_rect);

    CPPUNIT_TEST(test_constructor_deep_onearg);
    CPPUNIT_TEST(test_constructor_deep_twoarg_sq);
    CPPUNIT_TEST(test_constructor_deep_twoarg_rect);
    CPPUNIT_TEST(test_constructor_deep_threearg_sq);
    CPPUNIT_TEST(test_constructor_deep_threearg_rect);

    CPPUNIT_TEST(test_index_sq_80000000);
    CPPUNIT_TEST(test_index_rect_80000000);
    CPPUNIT_TEST(test_index_sq_ffffffff);
    CPPUNIT_TEST(test_index_rect_ffffffff);
    CPPUNIT_TEST(test_index_sq_7fffffff);
    CPPUNIT_TEST(test_index_rect_7fffffff);   

    /*
    Everything below here uses a string constructor that was not
    in the original interface.
     */ 

    // CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_equals_1);
    CPPUNIT_TEST(test_equals_2);
    CPPUNIT_TEST(test_equals_3);
    CPPUNIT_TEST(test_equals_4);
    CPPUNIT_TEST(test_equals_5);

    // CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less_than_1);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
    CPPUNIT_TEST(test_less_than_4);
    CPPUNIT_TEST(test_less_than_5);

    CPPUNIT_TEST(test_less_than_or_equal_1);
    CPPUNIT_TEST(test_less_than_or_equal_2);
    CPPUNIT_TEST(test_less_than_or_equal_3);
    CPPUNIT_TEST(test_less_than_or_equal_4);
    CPPUNIT_TEST(test_less_than_or_equal_5);

    CPPUNIT_TEST(test_greater_than_1);
    CPPUNIT_TEST(test_greater_than_2);
    CPPUNIT_TEST(test_greater_than_3);
    CPPUNIT_TEST(test_greater_than_4);
    CPPUNIT_TEST(test_greater_than_5);

    CPPUNIT_TEST(test_greater_than_or_equal_1);
    CPPUNIT_TEST(test_greater_than_or_equal_2);
    CPPUNIT_TEST(test_greater_than_or_equal_3);
    CPPUNIT_TEST(test_greater_than_or_equal_4);
    CPPUNIT_TEST(test_greater_than_or_equal_5);

    // CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(test_plus_1);
    CPPUNIT_TEST(test_plus_2);
    CPPUNIT_TEST(test_plus_3);
    CPPUNIT_TEST(test_plus_4);
    CPPUNIT_TEST(test_plus_5);

    // CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_minus_1);
    CPPUNIT_TEST(test_minus_2);
    CPPUNIT_TEST(test_minus_3);
    CPPUNIT_TEST(test_minus_4);
    CPPUNIT_TEST(test_minus_5);

    // CPPUNIT_TEST(test_multiplies);
    CPPUNIT_TEST(test_multiplies_A);
    CPPUNIT_TEST(test_multiplies_B);
    CPPUNIT_TEST(test_multiplies_B_2);
    CPPUNIT_TEST(test_multiplies_C);
    CPPUNIT_TEST(test_multiplies_C_2);

    CPPUNIT_TEST(test_multiplies_A_scalar);
    CPPUNIT_TEST(test_multiplies_B_scalar);
    CPPUNIT_TEST(test_multiplies_B_scalar_2);
    CPPUNIT_TEST(test_multiplies_C_scalar);
    CPPUNIT_TEST(test_multiplies_C_scalar_2);

    CPPUNIT_TEST(test_iterator);
    CPPUNIT_TEST(test_iterator_2);
    CPPUNIT_TEST(test_iterator_3);

    CPPUNIT_TEST(test_const_iterator);
    CPPUNIT_TEST(test_const_iterator_2);
    CPPUNIT_TEST(test_const_iterator_3);
    CPPUNIT_TEST_SUITE_END();};

// --------------
// SelfTestMatrix
// --------------

/*
This tests basic functionality across a variety of types and values.
Edge cases and anything other than the most basic of input isn't 
tested. To be used primarily to check minimum functionality.
 */
template <typename T>
struct SelfTestMatrix : CppUnit::TestFixture {

    // --------------
    // Test Templates
    // --------------

    private:
    void t_add_zero (T v, size_t a = 20, size_t b = 100) {
        const Matrix<T> za_a(a,a,0);
        const Matrix<T> zb_b(b,b,0);
        const Matrix<T> za_b(a,b,0);
        const Matrix<T> zb_a(b,a,0);
        const Matrix<T> ma_a(a,a,v);
        const Matrix<T> mb_b(b,b,v);
        const Matrix<T> ma_b(a,b,v);
        const Matrix<T> mb_a(b,a,v);

        Matrix<T> r;
        r = za_a + ma_a;
        CPPUNIT_ASSERT(r.eq(ma_a));
        r = zb_b + mb_b;
        CPPUNIT_ASSERT(r.eq(mb_b));
        r = za_b + ma_b;
        CPPUNIT_ASSERT(r.eq(ma_b));
        r = zb_a + mb_a;
        CPPUNIT_ASSERT(r.eq(mb_a));

        r = ma_a + za_a;
        CPPUNIT_ASSERT(r.eq(ma_a));
        r = mb_b + zb_b;
        CPPUNIT_ASSERT(r.eq(mb_b));
        r = ma_b + za_b;
        CPPUNIT_ASSERT(r.eq(ma_b));
        r = mb_a + zb_a;
        CPPUNIT_ASSERT(r.eq(mb_a));
    }

    void t_add_cumulative (T v, size_t a = 20, size_t b = 100) {
        const Matrix<T> za_b(a,b,0);
        const Matrix<T> ma_b(a,b,v);

        T increment = v;
        Matrix<T> r = za_b + ma_b;
        Matrix<T> ans(a,b,v); 
        CPPUNIT_ASSERT(r.eq(ans));
        v += increment;
        r += ma_b;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v += increment;
        r += ma_b;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v += increment;
        r += ma_b;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v += increment;
        r += ma_b;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v += increment;
        r += ma_b;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v += v;
        r += r;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v += v;
        r += r;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
    }

    void t_add_constant (T v, size_t a = 20, size_t b = 100) {
        const Matrix<T> za_b(a,b,0);

        T constant = v;
        Matrix<T> r = za_b + constant;
        Matrix<T> ans(a,b,v); 
        CPPUNIT_ASSERT(r.eq(ans));
        v += constant;
        r += constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v += constant;
        r += constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v += constant;
        r += constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v += constant;
        r += constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v += constant;
        r += constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));   
        v += constant;
        r += constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));   
        v += constant;
        r += constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));   
    }

    void t_subtract_from_zero (T v, size_t a = 20, size_t b = 100) {
        const Matrix<T> za_a(a,a,0);
        const Matrix<T> zb_b(b,b,0);
        const Matrix<T> za_b(a,b,0);
        const Matrix<T> zb_a(b,a,0);
        const Matrix<T> ma_a(a,a,v);
        const Matrix<T> mb_b(b,b,v);
        const Matrix<T> ma_b(a,b,v);
        const Matrix<T> mb_a(b,a,v);
        const Matrix<T> na_a(a,a,-v);
        const Matrix<T> nb_b(b,b,-v);
        const Matrix<T> na_b(a,b,-v);
        const Matrix<T> nb_a(b,a,-v);

        Matrix<T> r;
        r = za_a - ma_a;
        CPPUNIT_ASSERT(r.eq(na_a));
        r = zb_b - mb_b;
        CPPUNIT_ASSERT(r.eq(nb_b));
        r = za_b - ma_b;
        CPPUNIT_ASSERT(r.eq(na_b));
        r = zb_a - mb_a;
        CPPUNIT_ASSERT(r.eq(nb_a));
    }

    void t_subtract_zero (T v, size_t a = 20, size_t b = 100) {
        const Matrix<T> za_a(a,a,0);
        const Matrix<T> zb_b(b,b,0);
        const Matrix<T> za_b(a,b,0);
        const Matrix<T> zb_a(b,a,0);
        const Matrix<T> ma_a(a,a,v);
        const Matrix<T> mb_b(b,b,v);
        const Matrix<T> ma_b(a,b,v);
        const Matrix<T> mb_a(b,a,v);

        Matrix<T> r;
        r = ma_a - za_a;
        CPPUNIT_ASSERT(r.eq(ma_a));
        r = mb_b - zb_b;
        CPPUNIT_ASSERT(r.eq(mb_b));
        r = ma_b - za_b;
        CPPUNIT_ASSERT(r.eq(ma_b));
        r = mb_a - zb_a;
        CPPUNIT_ASSERT(r.eq(mb_a));
    }

    void t_subtract_cumulative (T v, size_t a = 20, size_t b = 100) {
        const Matrix<T> za_b(a,b,0);
        const Matrix<T> ma_b(a,b,v);

        T decrement = v;
        v = -v;
        Matrix<T> r = za_b - ma_b;
        Matrix<T> ans(a,b,v); 
        CPPUNIT_ASSERT(r.eq(ans));
        v -= decrement;
        r -= ma_b;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v -= decrement;
        r -= ma_b;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v -= decrement;
        r -= ma_b;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v -= decrement;
        r -= ma_b;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v -= decrement;
        r -= ma_b;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v -= v;
        r -= r;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v -= v;
        r -= r;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
    }

    void t_subtract_constant (T v, size_t a = 20, size_t b = 100) {
        const Matrix<T> za_b(a,b,0);

        T constant = -v;
        Matrix<T> r = za_b - constant;
        Matrix<T> ans(a,b,v); 
        CPPUNIT_ASSERT(r.eq(ans));
        v -= constant;
        r -= constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v -= constant;
        r -= constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v -= constant;
        r -= constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v -= constant;
        r -= constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v -= constant;
        r -= constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));   
        v -= constant;
        r -= constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));   
        v -= constant;
        r -= constant;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));   
    }

    void t_mult_scalar (T v, size_t a = 20, size_t b = 100) {
        T scalar = v;
        Matrix<T> r(a,b,1);
        r *= scalar;
        Matrix<T> ans(a,b,v); 
        CPPUNIT_ASSERT(r.eq(ans));
        v *= scalar;
        r *= scalar;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v *= scalar;
        r *= scalar;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
        v *= scalar;
        r *= scalar;
        ans = Matrix<T>(a,b,v);
        CPPUNIT_ASSERT(r.eq(ans));
    }

    void t_equals (T v, T x, size_t a = 50, size_t b = 50) {
        bool t = (v == x);
        Matrix<bool> ba_b(a,b,t);
        Matrix<T> V(a,b,v);
        Matrix<T> X(a,b,x);
        Matrix<bool> r;
        r = (V == X);
        CPPUNIT_ASSERT(ba_b.eq(r));
    }

    void t_not_equals (T v, T x, size_t a = 50, size_t b = 50) {
        bool t = (v != x);
        Matrix<bool> ba_b(a,b,t);
        Matrix<T> V(a,b,v);
        Matrix<T> X(a,b,x);
        Matrix<bool> r;
        r = (V != X);
        CPPUNIT_ASSERT(ba_b.eq(r));
    }

    void t_less_than (T v, T x, size_t a = 50, size_t b = 50) {
        bool t = (v < x);
        Matrix<bool> ba_b(a,b,t);
        Matrix<T> V(a,b,v);
        Matrix<T> X(a,b,x);
        Matrix<bool> r;
        r = (V < X);
        CPPUNIT_ASSERT(ba_b.eq(r));
    }

    void t_less_than_or_equal (T v, T x, size_t a = 50, size_t b = 50) {
        bool t = (v <= x);
        Matrix<bool> ba_b(a,b,t);
        Matrix<T> V(a,b,v);
        Matrix<T> X(a,b,x);
        Matrix<bool> r;
        r = (V <= X);
        CPPUNIT_ASSERT(ba_b.eq(r));
    }

    void t_greater_than (T v, T x, size_t a = 50, size_t b = 50) {
        bool t = (v > x);
        Matrix<bool> ba_b(a,b,t);
        Matrix<T> V(a,b,v);
        Matrix<T> X(a,b,x);
        Matrix<bool> r;
        r = (V > X);
        CPPUNIT_ASSERT(ba_b.eq(r));
    }

    void t_greater_than_or_equal (T v, T x, size_t a = 50, size_t b = 50) {
        bool t = (v >= x);
        Matrix<bool> ba_b(a,b,t);
        Matrix<T> V(a,b,v);
        Matrix<T> X(a,b,x);
        Matrix<bool> r;
        r = (V >= X);
        CPPUNIT_ASSERT(ba_b.eq(r));
    }

    public:

    // --
    // eq
    // --
    
    void test_eq_z () {
        const Matrix<T> z1_1(1,1,0);
        const Matrix<T> z3_3(3,3,0);
        const Matrix<T> z1_7(1,7,0);
        const Matrix<T> z7_1(7,1,0);

        CPPUNIT_ASSERT(z1_1.eq(z1_1));
        CPPUNIT_ASSERT(z3_3.eq(z3_3));
        CPPUNIT_ASSERT(z1_7.eq(z1_7));
        CPPUNIT_ASSERT(z7_1.eq(z7_1));
    }

    void test_eq_ff () {
        const Matrix<T> ff1_1(1,1,(T) 0xFF);
        const Matrix<T> ff3_3(3,3,(T) 0xFF);
        const Matrix<T> ff1_7(1,7,(T) 0xFF);
        const Matrix<T> ff7_1(7,1,(T) 0xFF);

        CPPUNIT_ASSERT(ff1_1.eq(ff1_1));
        CPPUNIT_ASSERT(ff3_3.eq(ff3_3));
        CPPUNIT_ASSERT(ff1_7.eq(ff1_7));
        CPPUNIT_ASSERT(ff7_1.eq(ff7_1));
    }

    void test_eq_m () {
        const Matrix<T> m1_1(1,1,10);
        const Matrix<T> m3_3(3,3,10);
        const Matrix<T> m1_7(1,7,10);
        const Matrix<T> m7_1(7,1,10);

        CPPUNIT_ASSERT(m1_1.eq(m1_1));
        CPPUNIT_ASSERT(m3_3.eq(m3_3));
        CPPUNIT_ASSERT(m1_7.eq(m1_7));
        CPPUNIT_ASSERT(m7_1.eq(m7_1));
    }

    void test_neq_diff_size () {
        const Matrix<T> z1_1(1,1,0);
        const Matrix<T> z3_3(3,3,0);
        const Matrix<T> z1_7(1,7,0);
        const Matrix<T> z7_1(7,1,0);
        const Matrix<T> ff1_1(1,1,(T) 0xFF);
        const Matrix<T> ff3_3(3,3,(T) 0xFF);
        const Matrix<T> ff1_7(1,7,(T) 0xFF);
        const Matrix<T> ff7_1(7,1,(T) 0xFF);
        const Matrix<T> m1_1(1,1,10);
        const Matrix<T> m3_3(3,3,10);
        const Matrix<T> m1_7(1,7,10);
        const Matrix<T> m7_1(7,1,10);    

        CPPUNIT_ASSERT(!ff1_1.eq(ff3_3));
        CPPUNIT_ASSERT(!ff3_3.eq(ff1_1));
        CPPUNIT_ASSERT(!ff1_7.eq(ff7_1));
        CPPUNIT_ASSERT(!ff7_1.eq(ff1_7));

        CPPUNIT_ASSERT(!z1_1.eq(z3_3));
        CPPUNIT_ASSERT(!z3_3.eq(z1_1));
        CPPUNIT_ASSERT(!z1_7.eq(z7_1));
        CPPUNIT_ASSERT(!z7_1.eq(z1_7));

        CPPUNIT_ASSERT(!m1_1.eq(m3_3));
        CPPUNIT_ASSERT(!m3_3.eq(m1_1));
        CPPUNIT_ASSERT(!m1_7.eq(m7_1));
        CPPUNIT_ASSERT(!m7_1.eq(m1_7));
    }

    void test_neq_same_size_no_common () {
        const Matrix<T> z1_1(1,1,0);
        const Matrix<T> z3_3(3,3,0);
        const Matrix<T> z1_7(1,7,0);
        const Matrix<T> z7_1(7,1,0);
        const Matrix<T> ff1_1(1,1,(T) 0xFF);
        const Matrix<T> ff3_3(3,3,(T) 0xFF);
        const Matrix<T> ff1_7(1,7,(T) 0xFF);
        const Matrix<T> ff7_1(7,1,(T) 0xFF);
        const Matrix<T> m1_1(1,1,10);
        const Matrix<T> m3_3(3,3,10);
        const Matrix<T> m1_7(1,7,10);
        const Matrix<T> m7_1(7,1,10); 

        CPPUNIT_ASSERT(!ff1_1.eq(z1_1));
        CPPUNIT_ASSERT(!ff3_3.eq(z3_3));
        CPPUNIT_ASSERT(!ff1_7.eq(z1_7));
        CPPUNIT_ASSERT(!ff7_1.eq(z7_1));

        CPPUNIT_ASSERT(!m1_1.eq(ff1_1));
        CPPUNIT_ASSERT(!m3_3.eq(ff3_3));
        CPPUNIT_ASSERT(!m1_7.eq(ff1_7));
        CPPUNIT_ASSERT(!m7_1.eq(ff7_1));

        CPPUNIT_ASSERT(!m1_1.eq(z1_1));
        CPPUNIT_ASSERT(!m3_3.eq(z3_3));
        CPPUNIT_ASSERT(!m1_7.eq(z1_7));
        CPPUNIT_ASSERT(!m7_1.eq(z7_1));

        CPPUNIT_ASSERT(!z1_1.eq(m1_1));
        CPPUNIT_ASSERT(!z3_3.eq(m3_3));
        CPPUNIT_ASSERT(!z1_7.eq(m1_7));
        CPPUNIT_ASSERT(!z7_1.eq(m7_1));

        CPPUNIT_ASSERT(!z1_1.eq(ff1_1));
        CPPUNIT_ASSERT(!z3_3.eq(ff3_3));
        CPPUNIT_ASSERT(!z1_7.eq(ff1_7));
        CPPUNIT_ASSERT(!z7_1.eq(ff7_1));
    }

    void test_neq_same_size_one_diff () {
        const Matrix<T> z1_1(1,1,0);
        const Matrix<T> z1_7(1,7,0);

        Matrix<T> m(1,1,1);
        CPPUNIT_ASSERT(!m.eq(z1_1));

        m = Matrix<T>(1,7,0);
        CPPUNIT_ASSERT(m.eq(z1_7));
        m[0][4] = 1;
        CPPUNIT_ASSERT(!m.eq(z1_7));
        m[0][4] = 0;
        CPPUNIT_ASSERT(m.eq(z1_7));
    }

    void test_neq_first_elements () {
        const Matrix<T> m(5,5,0);
        Matrix<T> p(5,5,0);

        CPPUNIT_ASSERT(p.eq(m));
        p[0][0] = 1;
        CPPUNIT_ASSERT(!p.eq(m));
        p[0][0] = 0;
        CPPUNIT_ASSERT(p.eq(m));
        p[1][0] = 1;
        CPPUNIT_ASSERT(!p.eq(m));
        p[1][0] = 0;
        CPPUNIT_ASSERT(p.eq(m));
        p[2][0] = 1;
        CPPUNIT_ASSERT(!p.eq(m));
        p[2][0] = 0;
        CPPUNIT_ASSERT(p.eq(m));
        p[3][0] = 1;
        CPPUNIT_ASSERT(!p.eq(m));
        p[3][0] = 0;
        CPPUNIT_ASSERT(p.eq(m));
        p[4][0] = 1;
        CPPUNIT_ASSERT(!p.eq(m));
        p[4][0] = 0;
        CPPUNIT_ASSERT(p.eq(m));
    }

    void test_neq_last_elements () {
        const Matrix<T> m(5,5,0);
        Matrix<T> p(5,5,0);

        CPPUNIT_ASSERT(p.eq(m));
        p[0][0] = 1;
        CPPUNIT_ASSERT(!p.eq(m));
        p[0][0] = 0;
        CPPUNIT_ASSERT(p.eq(m));
        p[0][1] = 1;
        CPPUNIT_ASSERT(!p.eq(m));
        p[0][1] = 0;
        CPPUNIT_ASSERT(p.eq(m));
        p[0][2] = 1;
        CPPUNIT_ASSERT(!p.eq(m));
        p[0][2] = 0;
        CPPUNIT_ASSERT(p.eq(m));
        p[0][3] = 1;
        CPPUNIT_ASSERT(!p.eq(m));
        p[0][3] = 0;
        CPPUNIT_ASSERT(p.eq(m));
        p[0][4] = 1;
        CPPUNIT_ASSERT(!p.eq(m));
        p[0][4] = 0;
        CPPUNIT_ASSERT(p.eq(m));
    }

    // ---
    // add
    // ---

    void test_add_zero_ff () {
        t_add_zero((T) 0xFF);
    }

    void test_add_zero_0 () {
        t_add_zero(0);
    }

    void test_add_zero_neg1 () {
        t_add_zero(-1);
    }

    void test_add_cumulative_10 () {
        t_add_cumulative(10);
    }

    void test_add_cumulative_neg1 () {
        t_add_cumulative(-1);
    }

    void test_add_constant_13 () {
        t_add_constant(13);
    }

    void test_add_constant_neg1 () {
        t_add_constant(-1);
    }

    void test_add_constant_0 () {
        t_add_constant(0);
    }

    // --------
    // subtract
    // --------

    void test_subtract_zero_0 () {
        t_subtract_zero(0);
    }

    void test_subtract_zero_ff () {
        t_subtract_zero((T) 0xFF);
    }

    void test_subtract_zero_neg1 () {
        t_subtract_zero(-1);
    }

    void test_subtract_from_zero_0 () {
        t_subtract_from_zero(0);
    }

    void test_subtract_from_zero_ff () {
        t_subtract_from_zero((T) 0xFF);
    }

    void test_subtract_from_zero_neg1 () {
        t_subtract_from_zero(-1);
    }

    void test_subtract_cumulative_10 () {
        t_subtract_cumulative(10);
    }

    void test_subtract_cumulative_neg1 () {
        t_subtract_cumulative(-1);
    }

    void test_subtract_constant_13 () {
        t_subtract_constant(13);
    }

    void test_subtract_constant_neg1 () {
        t_subtract_constant(-1);
    }

    void test_subtract_constant_0 () {
        t_subtract_constant(0);
    }

    // --------
    // multiply
    // --------

    void test_mult_scalar_7f () {
        t_mult_scalar(0x7F);
    }

    void test_mult_scalar_ff () {
        t_mult_scalar((T) 0xFF);
    }

    void test_mult_scalar_neg1 () {
        t_mult_scalar(-1);
    }

    // --
    // ==
    // --

    void test_equals_t_0 () {
        t_equals(0,0);
    }

    void test_equals_t_7f () {
        t_equals(0x7F, 0x7F);
    }

    void test_equals_t_ff () {
        t_equals((T) 0xFF,(T) 0xFF);
    }

    void test_equals_f () {
        t_equals((T) 0xFE,(T) 0xFF);
    }

    void test_equals_f_2 () {
        t_equals(-1,0);
    }

    void test_equals_f_3 () {
        t_equals(0x7F,(T) 0xFF);
    }

    // --
    // !=
    // --

    void test_not_equals_t () {
        t_not_equals((T) 0xFE,(T) 0xFF);
    }

    void test_not_equals_t_2 () {
        t_not_equals(-1,0);
    }

    void test_not_equals_t_3 () {
        t_not_equals(0x7F,(T) 0xFF);
    }

    void test_not_equals_f_0 () {
        t_not_equals(0,0);
    }

    void test_not_equals_f_7f () {
        t_not_equals(0x7F, 0x7F);
    }

    void test_not_equals_f_ff () {
        t_not_equals((T) 0xFF,(T) 0xFF);
    }

    // --
    //  <
    // --

    void test_less_than_f_0 () {
        t_less_than(0,0);
    }

    void test_less_than_f_7f () {
        t_less_than(0x7F, 0x7F);
    }

    void test_less_than_f_ff () {
        t_less_than((T) 0xFF,(T) 0xFF);
    }

    void test_less_than () {
        t_less_than((T) 0xFE,(T) 0xFF);
    }

    void test_less_than_2 () {
        t_less_than(-1,0);
    }

    void test_less_than_3 () {
        t_less_than(0x7F,(T) 0xFF);
    }

    void test_less_than_4 () {
        t_less_than(0x7F, (T) 0x80);
    }

    void test_less_thanb () {
        t_less_than((T) 0xFF,(T) 0xFE);
    }

    void test_less_than_2b () {
        t_less_than(0,-1);
    }

    void test_less_than_3b () {
        t_less_than((T) 0xFF,0x7F);
    }

    void test_less_than_4b () {
        t_less_than((T) 0x80,0x7F);
    }

    // --
    // <=
    // --

    void test_less_than_or_equal_t_0 () {
        t_less_than_or_equal(0,0);
    }

    void test_less_than_or_equal_t_7f () {
        t_less_than_or_equal(0x7F, 0x7F);
    }

    void test_less_than_or_equal_t_ff () {
        t_less_than_or_equal((T) 0xFF,(T) 0xFF);
    }

    void test_less_than_or_equal () {
        t_less_than_or_equal((T) 0xFE,(T) 0xFF);
    }

    void test_less_than_or_equal_2 () {
        t_less_than_or_equal(-1,0);
    }

    void test_less_than_or_equal_3 () {
        t_less_than_or_equal(0x7F,(T) 0xFF);
    }

    void test_less_than_or_equal_4 () {
        t_less_than_or_equal(0x7F, (T) 0x80);
    }

    void test_less_than_or_equalb () {
        t_less_than_or_equal((T) 0xFF,(T) 0xFE);
    }

    void test_less_than_or_equal_2b () {
        t_less_than_or_equal(0,-1);
    }

    void test_less_than_or_equal_3b () {
        t_less_than_or_equal((T) 0xFF,0x7F);
    }

    void test_less_than_or_equal_4b () {
        t_less_than_or_equal((T) 0x80,0x7F);
    }

    // --
    //  >
    // --

    void test_greater_than_f_0 () {
        t_greater_than(0,0);
    }

    void test_greater_than_f_7f () {
        t_greater_than(0x7F, 0x7F);
    }

    void test_greater_than_f_ff () {
        t_greater_than((T) 0xFF,(T) 0xFF);
    }

    void test_greater_than () {
        t_greater_than((T) 0xFE,(T) 0xFF);
    }

    void test_greater_than_2 () {
        t_greater_than(-1,0);
    }

    void test_greater_than_3 () {
        t_greater_than(0x7F,(T) 0xFF);
    }

    void test_greater_than_4 () {
        t_greater_than(0x7F, (T) 0x80);
    }

    void test_greater_thanb () {
        t_greater_than((T) 0xFF,(T) 0xFE);
    }

    void test_greater_than_2b () {
        t_greater_than(0,-1);
    }

    void test_greater_than_3b () {
        t_greater_than((T) 0xFF,0x7F);
    }

    void test_greater_than_4b () {
        t_greater_than((T) 0x80,0x7F);
    }

    // --
    // >=
    // --

    void test_greater_than_or_equal_t_0 () {
        t_greater_than_or_equal(0,0);
    }

    void test_greater_than_or_equal_t_7f () {
        t_greater_than_or_equal(0x7F, 0x7F);
    }

    void test_greater_than_or_equal_t_ff () {
        t_greater_than_or_equal((T) 0xFF,(T) 0xFF);
    }

    void test_greater_than_or_equal () {
        t_greater_than_or_equal((T) 0xFE,(T) 0xFF);
    }

    void test_greater_than_or_equal_2 () {
        t_greater_than_or_equal(-1,0);
    }

    void test_greater_than_or_equal_3 () {
        t_greater_than_or_equal(0x7F,(T) 0xFF);
    }

    void test_greater_than_or_equal_4 () {
        t_greater_than_or_equal(0x7F, (T) 0x80);
    }

    void test_greater_than_or_equalb () {
        t_greater_than_or_equal((T) 0xFF, (T) 0xFE);
    }

    void test_greater_than_or_equal_2b () {
        t_greater_than_or_equal(0,-1);
    }

    void test_greater_than_or_equal_3b () {
        t_greater_than_or_equal((T) 0xFF,0x7F);
    }

    void test_greater_than_or_equal_4b () {
        t_greater_than_or_equal((T) 0x80,0x7F);
    }

    void printm () {
        const Matrix<T> z1_1(1,1,0);
        const Matrix<T> z3_3(3,3,0);
        const Matrix<T> ff1_1(1,1,(T) 0xFF);
        const Matrix<T> ff3_3(3,3,(T) 0xFF);
        const Matrix<T> m1_1(1,1,10);
        const Matrix<T> m3_3(3,3,10);

        std::cout << "\nz1_1" << std::endl;
        z1_1.print();

        std::cout << "\nz3_3" << std::endl;
        z3_3.print();

        std::cout << "\nm1_1" << std::endl;
        m1_1.print();

        std::cout << "\nm3_3" << std::endl;
        m3_3.print();

        std::cout << "\nff1_1" << std::endl;
        ff1_1.print();

        std::cout << "\nff3_3" << std::endl;
        ff3_3.print();
    }

    void test_string_construct () {
        Matrix<T> a("[0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1]");
        Matrix<T> b("[1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0;1,0,1,0,1;0,1,0,1,0]");
        Matrix<T> c("[0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0;0,0,0,0,0]");
        Matrix<T> d("[1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1;1,1,1,1,1]");

        std::cout << "\na:" << std::endl;
        a.print();
        std::cout << "\nb:" << std::endl;
        b.print();
        std::cout << "\nc:" << std::endl;
        c.print();
        std::cout << "\nd:" << std::endl;
        d.print();
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(SelfTestMatrix);

    CPPUNIT_TEST(test_eq_z);
    CPPUNIT_TEST(test_eq_ff);
    CPPUNIT_TEST(test_neq_diff_size);
    CPPUNIT_TEST(test_neq_same_size_no_common);
    CPPUNIT_TEST(test_neq_first_elements);
    CPPUNIT_TEST(test_neq_last_elements);

    CPPUNIT_TEST(test_add_zero_0);
    CPPUNIT_TEST(test_add_zero_ff);
    CPPUNIT_TEST(test_add_zero_neg1);
    CPPUNIT_TEST(test_add_cumulative_10);
    CPPUNIT_TEST(test_add_cumulative_neg1);
    CPPUNIT_TEST(test_add_constant_13);
    CPPUNIT_TEST(test_add_constant_neg1);
    CPPUNIT_TEST(test_add_constant_0);

    CPPUNIT_TEST(test_subtract_zero_0);
    CPPUNIT_TEST(test_subtract_zero_ff);
    CPPUNIT_TEST(test_subtract_zero_neg1);
    CPPUNIT_TEST(test_subtract_from_zero_0);
    CPPUNIT_TEST(test_subtract_from_zero_ff);
    CPPUNIT_TEST(test_subtract_from_zero_neg1);
    CPPUNIT_TEST(test_subtract_cumulative_10);
    CPPUNIT_TEST(test_subtract_cumulative_neg1);
    CPPUNIT_TEST(test_subtract_constant_13);
    CPPUNIT_TEST(test_subtract_constant_neg1);
    CPPUNIT_TEST(test_subtract_constant_0);

    CPPUNIT_TEST(test_mult_scalar_7f);
    CPPUNIT_TEST(test_mult_scalar_ff);
    CPPUNIT_TEST(test_mult_scalar_neg1);

    CPPUNIT_TEST(test_equals_t_0);
    CPPUNIT_TEST(test_equals_t_7f);
    CPPUNIT_TEST(test_equals_t_ff);
    CPPUNIT_TEST(test_equals_f);
    CPPUNIT_TEST(test_equals_f_2);
    CPPUNIT_TEST(test_equals_f_3);

    CPPUNIT_TEST(test_not_equals_t);
    CPPUNIT_TEST(test_not_equals_t_2);
    CPPUNIT_TEST(test_not_equals_t_3);
    CPPUNIT_TEST(test_not_equals_f_0);
    CPPUNIT_TEST(test_not_equals_f_7f);
    CPPUNIT_TEST(test_not_equals_f_ff);

    CPPUNIT_TEST(test_less_than_f_0);
    CPPUNIT_TEST(test_less_than_f_7f);
    CPPUNIT_TEST(test_less_than_f_ff);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
    CPPUNIT_TEST(test_less_than_4);
    CPPUNIT_TEST(test_less_thanb);
    CPPUNIT_TEST(test_less_than_2b);
    CPPUNIT_TEST(test_less_than_3b);
    CPPUNIT_TEST(test_less_than_4b);

    CPPUNIT_TEST(test_less_than_or_equal_t_0);
    CPPUNIT_TEST(test_less_than_or_equal_t_7f);
    CPPUNIT_TEST(test_less_than_or_equal_t_ff);
    CPPUNIT_TEST(test_less_than_or_equal);
    CPPUNIT_TEST(test_less_than_or_equal_2);
    CPPUNIT_TEST(test_less_than_or_equal_3);
    CPPUNIT_TEST(test_less_than_or_equal_4);
    CPPUNIT_TEST(test_less_than_or_equalb);
    CPPUNIT_TEST(test_less_than_or_equal_2b);
    CPPUNIT_TEST(test_less_than_or_equal_3b);
    CPPUNIT_TEST(test_less_than_or_equal_4b);

    CPPUNIT_TEST(test_greater_than_f_0);
    CPPUNIT_TEST(test_greater_than_f_7f);
    CPPUNIT_TEST(test_greater_than_f_ff);
    CPPUNIT_TEST(test_greater_than);
    CPPUNIT_TEST(test_greater_than_2);
    CPPUNIT_TEST(test_greater_than_3);
    CPPUNIT_TEST(test_greater_than_4);
    CPPUNIT_TEST(test_greater_thanb);
    CPPUNIT_TEST(test_greater_than_2b);
    CPPUNIT_TEST(test_greater_than_3b);
    CPPUNIT_TEST(test_greater_than_4b);

    CPPUNIT_TEST(test_greater_than_or_equal_t_0);
    CPPUNIT_TEST(test_greater_than_or_equal_t_7f);
    CPPUNIT_TEST(test_greater_than_or_equal_t_ff);
    CPPUNIT_TEST(test_greater_than_or_equal);
    CPPUNIT_TEST(test_greater_than_or_equal_2);
    CPPUNIT_TEST(test_greater_than_or_equal_3);
    CPPUNIT_TEST(test_greater_than_or_equal_4);
    CPPUNIT_TEST(test_greater_than_or_equalb);
    CPPUNIT_TEST(test_greater_than_or_equal_2b);
    CPPUNIT_TEST(test_greater_than_or_equal_3b);
    CPPUNIT_TEST(test_greater_than_or_equal_4b);

    // CPPUNIT_TEST(printm);
    // CPPUNIT_TEST(test_string_construct);

    CPPUNIT_TEST_SUITE_END();};

// --------------
// TestExceptions
// --------------

/*
Optionally tests exception cases for Matrix objects.
 */
template <typename T>
struct TestExceptions : CppUnit::TestFixture {

    void test_equals_both_empty () {
        Matrix<T> A;
        Matrix<T> B;
        try { 
            Matrix<bool> r = A == B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_equals_both_zero_dim () {
        Matrix<T> A(3,0);
        Matrix<T> B(3,0);
        try { 
            Matrix<bool> r = A == B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_equals_both_zero_dim_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,3);
        try { 
            Matrix<bool> r = A == B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_equals_diff_size () {
        Matrix<T> A(0,3);
        Matrix<T> B(3,0);
        try { 
            Matrix<bool> r = A == B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_equals_diff_size_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,4);
        try { 
            Matrix<bool> r = A == B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_equals_diff_size_3 () {
        Matrix<T> A(3,0);
        Matrix<T> B(4,0);
        try { 
            Matrix<bool> r = A == B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_equals_diff_size_4 () {
        Matrix<T> A(3,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<bool> r = A == B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_equals_diff_size_5 () {
        Matrix<T> A(4,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<bool> r = A == B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_equals_diff_size_6 () {
        Matrix<T> A(3,4);
        Matrix<T> B(3,3);
        try { 
            Matrix<bool> r = A == B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_not_equals_both_empty () {
        Matrix<T> A;
        Matrix<T> B;
        try { 
            Matrix<bool> r = A != B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_not_equals_both_zero_dim () {
        Matrix<T> A(3,0);
        Matrix<T> B(3,0);
        try { 
            Matrix<bool> r = A != B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_not_equals_both_zero_dim_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,3);
        try { 
            Matrix<bool> r = A != B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_not_equals_diff_size () {
        Matrix<T> A(0,3);
        Matrix<T> B(3,0);
        try { 
            Matrix<bool> r = A != B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_not_equals_diff_size_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,4);
        try { 
            Matrix<bool> r = A != B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_not_equals_diff_size_3 () {
        Matrix<T> A(3,0);
        Matrix<T> B(4,0);
        try { 
            Matrix<bool> r = A != B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_not_equals_diff_size_4 () {
        Matrix<T> A(3,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<bool> r = A != B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_not_equals_diff_size_5 () {
        Matrix<T> A(4,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<bool> r = A != B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_not_equals_diff_size_6 () {
        Matrix<T> A(3,4);
        Matrix<T> B(3,3);
        try { 
            Matrix<bool> r = A != B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_less_both_empty () {
        Matrix<T> A;
        Matrix<T> B;
        try { 
            Matrix<bool> r = A < B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_less_both_zero_dim () {
        Matrix<T> A(3,0);
        Matrix<T> B(3,0);
        try { 
            Matrix<bool> r = A < B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_less_both_zero_dim_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,3);
        try { 
            Matrix<bool> r = A < B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_less_diff_size () {
        Matrix<T> A(0,3);
        Matrix<T> B(3,0);
        try { 
            Matrix<bool> r = A < B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_less_diff_size_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,4);
        try { 
            Matrix<bool> r = A < B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_less_diff_size_3 () {
        Matrix<T> A(3,0);
        Matrix<T> B(4,0);
        try { 
            Matrix<bool> r = A < B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_less_diff_size_4 () {
        Matrix<T> A(3,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<bool> r = A < B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_less_diff_size_5 () {
        Matrix<T> A(4,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<bool> r = A < B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_less_diff_size_6 () {
        Matrix<T> A(3,4);
        Matrix<T> B(3,3);
        try { 
            Matrix<bool> r = A < B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_lesseq_both_empty () {
        Matrix<T> A;
        Matrix<T> B;
        try { 
            Matrix<bool> r = A <= B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_lesseq_both_zero_dim () {
        Matrix<T> A(3,0);
        Matrix<T> B(3,0);
        try { 
            Matrix<bool> r = A <= B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_lesseq_both_zero_dim_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,3);
        try { 
            Matrix<bool> r = A <= B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_lesseq_diff_size () {
        Matrix<T> A(0,3);
        Matrix<T> B(3,0);
        try { 
            Matrix<bool> r = A <= B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_lesseq_diff_size_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,4);
        try { 
            Matrix<bool> r = A <= B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_lesseq_diff_size_3 () {
        Matrix<T> A(3,0);
        Matrix<T> B(4,0);
        try { 
            Matrix<bool> r = A <= B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_lesseq_diff_size_4 () {
        Matrix<T> A(3,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<bool> r = A <= B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_lesseq_diff_size_5 () {
        Matrix<T> A(4,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<bool> r = A <= B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_lesseq_diff_size_6 () {
        Matrix<T> A(3,4);
        Matrix<T> B(3,3);
        try { 
            Matrix<bool> r = A <= B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_greater_both_empty () {
        Matrix<T> A;
        Matrix<T> B;
        try { 
            Matrix<bool> r = A > B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_greater_both_zero_dim () {
        Matrix<T> A(3,0);
        Matrix<T> B(3,0);
        try { 
            Matrix<bool> r = A > B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_greater_both_zero_dim_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,3);
        try { 
            Matrix<bool> r = A > B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_greater_diff_size () {
        Matrix<T> A(0,3);
        Matrix<T> B(3,0);
        try { 
            Matrix<bool> r = A > B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_greater_diff_size_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,4);
        try { 
            Matrix<bool> r = A > B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_greater_diff_size_3 () {
        Matrix<T> A(3,0);
        Matrix<T> B(4,0);
        try { 
            Matrix<bool> r = A > B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_greater_diff_size_4 () {
        Matrix<T> A(3,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<bool> r = A > B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_greater_diff_size_5 () {
        Matrix<T> A(4,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<bool> r = A > B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_greater_diff_size_6 () {
        Matrix<T> A(3,4);
        Matrix<T> B(3,3);
        try { 
            Matrix<bool> r = A > B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_greatereq_both_empty () {
        Matrix<T> A;
        Matrix<T> B;
        try { 
            Matrix<bool> r = A >= B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_greatereq_both_zero_dim () {
        Matrix<T> A(3,0);
        Matrix<T> B(3,0);
        try { 
            Matrix<bool> r = A >= B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_greatereq_both_zero_dim_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,3);
        try { 
            Matrix<bool> r = A >= B;
        } catch (...) { CPPUNIT_ASSERT(false); }
    }

    void test_greatereq_diff_size () {
        Matrix<T> A(0,3);
        Matrix<T> B(3,0);
        try { 
            Matrix<bool> r = A >= B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_greatereq_diff_size_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,4);
        try { 
            Matrix<bool> r = A >= B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_greatereq_diff_size_3 () {
        Matrix<T> A(3,0);
        Matrix<T> B(4,0);
        try { 
            Matrix<bool> r = A >= B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_greatereq_diff_size_4 () {
        Matrix<T> A(3,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<bool> r = A >= B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_greatereq_diff_size_5 () {
        Matrix<T> A(4,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<bool> r = A >= B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_greatereq_diff_size_6 () {
        Matrix<T> A(3,4);
        Matrix<T> B(3,3);
        try { 
            Matrix<bool> r = A >= B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

   void test_plus_both_empty () {
        Matrix<T> A;
        Matrix<T> B;
        Matrix<T> r = A + B;
        CPPUNIT_ASSERT(r.eq(A));
    }

    void test_plus_both_zero_dim () {
        Matrix<T> A(3,0);
        Matrix<T> B(3,0);
        Matrix<T> r = A + B;
        CPPUNIT_ASSERT(r.eq(A));
    }

    void test_plus_both_zero_dim_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,3);
        Matrix<T> r = A + B;
        CPPUNIT_ASSERT(r.eq(A));
    }

    void test_plus_diff_size () {
        Matrix<T> A(0,3);
        Matrix<T> B(3,0);
        try { 
            Matrix<T> r = A + B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_plus_diff_size_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,4);
        try { 
            Matrix<T> r = A + B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_plus_diff_size_3 () {
        Matrix<T> A(3,0);
        Matrix<T> B(4,0);
        try { 
            Matrix<T> r = A + B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_plus_diff_size_4 () {
        Matrix<T> A(3,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<T> r = A + B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_plus_diff_size_5 () {
        Matrix<T> A(4,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<T> r = A + B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_plus_diff_size_6 () {
        Matrix<T> A(3,4);
        Matrix<T> B(3,3);
        try { 
            Matrix<T> r = A + B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_minus_both_empty () {
        Matrix<T> A;
        Matrix<T> B;
        Matrix<T> r = A - B;
        CPPUNIT_ASSERT(r.eq(A));
    }

    void test_minus_both_zero_dim () {
        Matrix<T> A(3,0);
        Matrix<T> B(3,0);
        Matrix<T> r = A - B;
        CPPUNIT_ASSERT(r.eq(A));
    }

    void test_minus_both_zero_dim_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,3);
        Matrix<T> r = A - B;
        CPPUNIT_ASSERT(r.eq(A));
    }

    void test_minus_diff_size () {
        Matrix<T> A(0,3);
        Matrix<T> B(3,0);
        try { 
            Matrix<T> r = A - B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_minus_diff_size_2 () {
        Matrix<T> A(0,3);
        Matrix<T> B(0,4);
        try { 
            Matrix<T> r = A - B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_minus_diff_size_3 () {
        Matrix<T> A(3,0);
        Matrix<T> B(4,0);
        try { 
            Matrix<T> r = A - B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_minus_diff_size_4 () {
        Matrix<T> A(3,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<T> r = A - B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_minus_diff_size_5 () {
        Matrix<T> A(4,4);
        Matrix<T> B(4,3);
        try { 
            Matrix<T> r = A - B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_minus_diff_size_6 () {
        Matrix<T> A(3,4);
        Matrix<T> B(3,3);
        try { 
            Matrix<T> r = A - B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_mult_both_empty () {
        Matrix<T> A;
        Matrix<T> B;
        Matrix<T> r = A * B;
        CPPUNIT_ASSERT(r.eq(A));
    }

    void test_mult_zero_dim () {
        Matrix<T> A(3,0);
        Matrix<T> B(0,3);
        Matrix<T> ans(3,3,0);
        Matrix<T> r = A * B;
        CPPUNIT_ASSERT(ans.eq(r));
    }

    void test_mult_zero_dim_2 () {
        Matrix<T> A(3,0);
        Matrix<T> B(0,4);
        Matrix<T> ans(3,4,0);
        Matrix<T> r = A * B;
        CPPUNIT_ASSERT(ans.eq(r));
    }

    void test_mult_zero_dim_3 () {
        Matrix<T> A(0,3);
        Matrix<T> B(3,0);
        Matrix<T> ans;
        Matrix<T> r = A * B;
        CPPUNIT_ASSERT(ans.eq(r));
    }

    void test_mult_bad_size () {
        Matrix<T> A(3,0);
        Matrix<T> B(1,3);
        try {
            Matrix<T> r = A * B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_mult_bad_size_2 () {
        Matrix<T> A(3,2);
        Matrix<T> B(1,3);
        try {
            Matrix<T> r = A * B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_mult_bad_size_3 () {
        Matrix<T> A(3,1);
        Matrix<T> B(2,3);
        try {
            Matrix<T> r = A * B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_mult_bad_size_4 () {
        Matrix<T> A(3,2);
        Matrix<T> B(1,4);
        try {
            Matrix<T> r = A * B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    void test_mult_bad_size_5 () {
        Matrix<T> A(3,1);
        Matrix<T> B(2,4);
        try {
            Matrix<T> r = A * B;
            CPPUNIT_ASSERT(false);
        } catch (...) { /*nothing to be done*/ }
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestExceptions);
    CPPUNIT_TEST(test_equals_both_empty);
    CPPUNIT_TEST(test_equals_both_zero_dim);
    CPPUNIT_TEST(test_equals_both_zero_dim_2);
    CPPUNIT_TEST(test_equals_diff_size);
    CPPUNIT_TEST(test_equals_diff_size_2);
    CPPUNIT_TEST(test_equals_diff_size_3);
    CPPUNIT_TEST(test_equals_diff_size_4);
    CPPUNIT_TEST(test_equals_diff_size_5);
    CPPUNIT_TEST(test_equals_diff_size_6);

    CPPUNIT_TEST(test_not_equals_both_empty);
    CPPUNIT_TEST(test_not_equals_both_zero_dim);
    CPPUNIT_TEST(test_not_equals_both_zero_dim_2);
    CPPUNIT_TEST(test_not_equals_diff_size);
    CPPUNIT_TEST(test_not_equals_diff_size_2);
    CPPUNIT_TEST(test_not_equals_diff_size_3);
    CPPUNIT_TEST(test_not_equals_diff_size_4);
    CPPUNIT_TEST(test_not_equals_diff_size_5);
    CPPUNIT_TEST(test_not_equals_diff_size_6);

    CPPUNIT_TEST(test_less_both_empty);
    CPPUNIT_TEST(test_less_both_zero_dim);
    CPPUNIT_TEST(test_less_both_zero_dim_2);
    CPPUNIT_TEST(test_less_diff_size);
    CPPUNIT_TEST(test_less_diff_size_2);
    CPPUNIT_TEST(test_less_diff_size_3);
    CPPUNIT_TEST(test_less_diff_size_4);
    CPPUNIT_TEST(test_less_diff_size_5);
    CPPUNIT_TEST(test_less_diff_size_6);

    CPPUNIT_TEST(test_lesseq_both_empty);
    CPPUNIT_TEST(test_lesseq_both_zero_dim);
    CPPUNIT_TEST(test_lesseq_both_zero_dim_2);
    CPPUNIT_TEST(test_lesseq_diff_size);
    CPPUNIT_TEST(test_lesseq_diff_size_2);
    CPPUNIT_TEST(test_lesseq_diff_size_3);
    CPPUNIT_TEST(test_lesseq_diff_size_4);
    CPPUNIT_TEST(test_lesseq_diff_size_5);
    CPPUNIT_TEST(test_lesseq_diff_size_6);

    CPPUNIT_TEST(test_greater_both_empty);
    CPPUNIT_TEST(test_greater_both_zero_dim);
    CPPUNIT_TEST(test_greater_both_zero_dim_2);
    CPPUNIT_TEST(test_greater_diff_size);
    CPPUNIT_TEST(test_greater_diff_size_2);
    CPPUNIT_TEST(test_greater_diff_size_3);
    CPPUNIT_TEST(test_greater_diff_size_4);
    CPPUNIT_TEST(test_greater_diff_size_5);
    CPPUNIT_TEST(test_greater_diff_size_6);

    CPPUNIT_TEST(test_greatereq_both_empty);
    CPPUNIT_TEST(test_greatereq_both_zero_dim);
    CPPUNIT_TEST(test_greatereq_both_zero_dim_2);
    CPPUNIT_TEST(test_greatereq_diff_size);
    CPPUNIT_TEST(test_greatereq_diff_size_2);
    CPPUNIT_TEST(test_greatereq_diff_size_3);
    CPPUNIT_TEST(test_greatereq_diff_size_4);
    CPPUNIT_TEST(test_greatereq_diff_size_5);
    CPPUNIT_TEST(test_greatereq_diff_size_6);

    CPPUNIT_TEST(test_plus_both_empty);
    CPPUNIT_TEST(test_plus_both_zero_dim);
    CPPUNIT_TEST(test_plus_both_zero_dim_2);
    CPPUNIT_TEST(test_plus_diff_size);
    CPPUNIT_TEST(test_plus_diff_size_2);
    CPPUNIT_TEST(test_plus_diff_size_3);
    CPPUNIT_TEST(test_plus_diff_size_4);
    CPPUNIT_TEST(test_plus_diff_size_5);
    CPPUNIT_TEST(test_plus_diff_size_6);

    CPPUNIT_TEST(test_minus_both_empty);
    CPPUNIT_TEST(test_minus_both_zero_dim);
    CPPUNIT_TEST(test_minus_both_zero_dim_2);
    CPPUNIT_TEST(test_minus_diff_size);
    CPPUNIT_TEST(test_minus_diff_size_2);
    CPPUNIT_TEST(test_minus_diff_size_3);
    CPPUNIT_TEST(test_minus_diff_size_4);
    CPPUNIT_TEST(test_minus_diff_size_5);
    CPPUNIT_TEST(test_minus_diff_size_6);

    CPPUNIT_TEST(test_mult_both_empty);
    CPPUNIT_TEST(test_mult_zero_dim);
    CPPUNIT_TEST(test_mult_zero_dim_2);
    CPPUNIT_TEST(test_mult_zero_dim_3);
    CPPUNIT_TEST(test_mult_bad_size);
    CPPUNIT_TEST(test_mult_bad_size_2);
    CPPUNIT_TEST(test_mult_bad_size_3);
    CPPUNIT_TEST(test_mult_bad_size_4);
    CPPUNIT_TEST(test_mult_bad_size_5);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestMatrix.c++" << endl;

    CppUnit::TextTestRunner tr;

    tr.addTest(TestMatrix::suite());
    tr.addTest(SelfTestMatrix<int>::suite());
    tr.addTest(SelfTestMatrix<char>::suite());
    tr.addTest(SelfTestMatrix<short>::suite());
    tr.addTest(SelfTestMatrix<float>::suite());
    tr.addTest(SelfTestMatrix<double>::suite());
    tr.addTest(TestExceptions<int>::suite());
    tr.addTest(TestExceptions<char>::suite());
    tr.addTest(TestExceptions<short>::suite());
    tr.addTest(TestExceptions<float>::suite());
    tr.addTest(TestExceptions<double>::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
