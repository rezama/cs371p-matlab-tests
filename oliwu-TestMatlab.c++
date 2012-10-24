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
        Matrix<int> x(2, 3, 0);
        Matrix<int> y(2, 2, 1);
        Matrix<int> z(2, 5, 0);
        z[0][3] = z[0][4] = 1;
        z[1][3] = z[1][4] = 1;
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_horzcat_2 () {
        Matrix<int> x(3, 1, 0);
        Matrix<int> y(3, 4, 1);
        Matrix<int> z(3, 5, 1);
        z[0][0] = z[1][0] = z[2][0] = 0;
        x = horzcat<Matrix<int> >(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_horzcat_3 () {
        Matrix<int> x(1, 3, 0);
        Matrix<int> y(2, 2, 1);
        try {
          x = horzcat<Matrix<int> >(x, y);
        }
        catch (DimensionException& e) {
          CPPUNIT_ASSERT(true);
        }
    }

    void test_vertcat_1 () {
        Matrix<int> x(2, 3, 0);
        Matrix<int> y(1, 3, 1);
        Matrix<int> z(3, 3, 0);
        z[2][0] = z[2][1] = z[2][2] = 1;
        x = vertcat<Matrix<int> >(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_vertcat_2 () {
        Matrix<int> x(0, 3, 0);
        Matrix<int> y(1, 3, 1);
        Matrix<int> z(1, 3, 1);
        x = vertcat<Matrix<int> >(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_vertcat_3 () {
        Matrix<int> x(2, 3, 0);
        Matrix<int> y(1, 2, 1);
        try {
          x = vertcat<Matrix<int> >(x, y);
        }
        catch (DimensionException& e) {
          CPPUNIT_ASSERT(true);
        }
    }

    // ---------
    // test_diag
    // ---------

    void test_diag_1 () {
        Matrix<int> x(3, 3, 5);
        Matrix<int> y(3, 1, 5);
        x = diag<Matrix<int> >(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_diag_2 () {
        Matrix<int> x(1, 3, 5);
        Matrix<int> y(3, 3, 0);
        y[0][0] = y[1][1] = y[2][2] = 5;
        x = diag<Matrix<int> >(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_diag_3 () {
        Matrix<int> x(3, 1, 5);
        Matrix<int> y(3, 3, 0);
        y[0][0] = y[1][1] = y[2][2] = 5;
        x = diag<Matrix<int> >(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_diag_4 () {
        Matrix<int> x(4, 3, 5);
        Matrix<int> y(3, 1, 5);
        x = diag<Matrix<int> >(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_diag_5 () {
        Matrix<int> x;
        Matrix<int> y;
        x = diag<Matrix<int> >(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------
    // test_dot
    // --------

    void test_dot_zero () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z(1, 1, 0);
        x = dot<Matrix<int> >(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_row () {
        Matrix<int> x(1, 3);
        Matrix<int> y(1, 3);
        Matrix<int> z(1, 1, 32);
        for (size_t i = 0; i < 6; i++) {
          if (i < 3) { x[0][i] = i+1; }
          else { y[0][i-3] = i+1; }
        }
        x = dot<Matrix<int> >(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_column () {
        Matrix<int> x(3, 1);
        Matrix<int> y(3, 1);
        Matrix<int> z(1, 1, 32);
        for (size_t i = 0; i < 6; i++) {
          if (i < 3) { x[i][0] = i+1; }
          else { y[i-3][0] = i+1; }
        }
        x = dot<Matrix<int> >(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_2d () {
        Matrix<int> x(2, 3);
        for (size_t i = 0; i < 6; i++) {
          if (i < 3) { x[0][i] = i+1; }
          else { x[1][i-3] = i+1; }
        }
        Matrix<int> y = x; 
        Matrix<int> z(1, 3);
        z[0][0] = 17; z[0][1] = 29; z[0][2] = 45;
        x = dot<Matrix<int> >(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_fail () {
        Matrix<int> x(2, 2);
        Matrix<int> y(4, 1);
        try {
          x = dot< Matrix<int> >(x, y);
          CPPUNIT_ASSERT(false);
        } catch (DimensionException& e) { CPPUNIT_ASSERT(true); }
    }

    // --------
    // test_eye
    // --------

    void test_eye_1 () {
        Matrix<int> x = eye<Matrix<int> >(5, 5);
        Matrix<int> y(5, 5, 0);
        for (size_t i = 0; i < 5; ++i) {
          y[i][i] = 1;
        }
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_eye_2 () {
        Matrix<int> x;
        Matrix<int> y(1, 1, 1);
        x = eye<Matrix<int> >(1, 1);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // NOTE: When using eye() with one or more of the dimenions being 0 just
    // let Matrix do it's thing here. We decided not to throw an exception here
    // because Matlab just prints a message like "Empty matrix: 0-by-n" or
    // "Empty matrix: n-by-0" as the result. Further, when both dimensions are
    // 0, it returns a normal empty matrix, [], which our method will do as
    // well.
    void test_eye_3 () {
        Matrix<int> x;
        Matrix<int> y(0, 3, 0);
        x = eye<Matrix<int> >(0, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_eye_4 () {
        Matrix<int> x;
        Matrix<int> y(4, 2, 0);
        y[0][0] = y[1][1] = 1;
        x = eye<Matrix<int> >(4, 2);
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
    // test_ones
    // ---------

    void test_ones_1 () {
        Matrix<int> x;
        Matrix<int> y(2, 3, 1);
        x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_ones_2 () {
        Matrix<int> x;
        Matrix<int> y;
        x = ones< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_ones_3 () {
        Matrix<int> x;
        Matrix<int> y(3, 0, 1);
        x = ones< Matrix<int> >(3, 0);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_rand
    // ---------

    void test_rand_1 () {
      Matrix<double> x(4, 4, 2);
      x = rand< Matrix<double> >(4, 4);
      for (size_t i = 0; i < x.rows(); ++i) {
        for (size_t j = 0; j < x.columns(); ++j) {
          CPPUNIT_ASSERT(x[i][j] != 2);
        }
      }
    }

    void test_rand_2 () {
      Matrix<double> x(4, 4, 2);
      Matrix<double> y(0, 4);
      x = rand< Matrix<double> >(0, 4);
      CPPUNIT_ASSERT(x.eq(y));
    }

    void test_rand_3 () {
      Matrix<double> x(4, 4, 2);
      x = rand< Matrix<double> >(4, 4);
      for (size_t i = 0; i < x.rows(); ++i) {
        for (size_t j = 0; j < x.columns(); ++j) {
          CPPUNIT_ASSERT(x[i][j] >= 0 && x[i][j] <= 1);
        }
      }
    }

    // --------------
    // test_transpose
    // --------------
    
    void test_transpose_empty () {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_transpose_fat () {
        Matrix<int> x(4, 1, 8);
        Matrix<int> y(1, 4, 8);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_transpose_tall () {
        Matrix<int> x(2, 69, 69);
        Matrix<int> y(69, 2, 69);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_transpose_2dizzle () {
        Matrix<int> x(96, 69);
        Matrix<int> y(69, 96);
        for (int i = 0; i < 96; i++) {
          for (int k = 0; k < 69; k++) {
            x[i][k] = y[k][i] = std::rand();
          }
        }
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_tril
    // ---------

    void test_tril_2x2 () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        y[0][0] = y[0][1] = y[1][1] = 0;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}

   void test_tril_69x69 () {
        Matrix<int> x(69, 69, 1);
        Matrix<int> y(69, 69, 1);
        for (int i = 0; i < 69; i++) {
          for (int j = i; j < 69; j++) {
            y[i][j] = 0;
          }
        }
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_tril_one_pt () {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, 0);
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_tril_fail () {
        Matrix<int> x(4, 5, 1);
        try {
          x = tril(x);
          CPPUNIT_ASSERT(false);
        } catch (DimensionException& e) { CPPUNIT_ASSERT(true); }}

    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_triu_2x2 () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        y[1][0] = 0;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

   void test_triu_88x88 () {
        Matrix<int> x(88, 88, 8);
        Matrix<int> y(88, 88);
        for (int i = 0; i < 88; i++) {
          for (int j = i; j < 88; j++) {
            y[i][j] = 8;
          }
        }
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_triu_one_pt () {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, 1);
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_triu_fail () {
        Matrix<int> x(1, 0);
        try {
          x = triu(x);
          CPPUNIT_ASSERT(false);
        } catch (DimensionException& e) { CPPUNIT_ASSERT(true); }}


    // ----------
    // test_zeros
    // ----------

    void test_zeros_1 () {
        Matrix<int> x;
        Matrix<int> y(2, 3, 0);
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_zeros_2 () {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_zeros_3 () {
        Matrix<int> x;
        Matrix<int> y(2, 3, 0);
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat_1);
    CPPUNIT_TEST(test_horzcat_2);
    CPPUNIT_TEST(test_horzcat_3);

    CPPUNIT_TEST(test_vertcat_1);
    CPPUNIT_TEST(test_vertcat_2);
    CPPUNIT_TEST(test_vertcat_3);

    CPPUNIT_TEST(test_diag_1);
    CPPUNIT_TEST(test_diag_2);
    CPPUNIT_TEST(test_diag_3);
    CPPUNIT_TEST(test_diag_4);
    CPPUNIT_TEST(test_diag_5);

    CPPUNIT_TEST(test_dot_zero);
    CPPUNIT_TEST(test_dot_row);
    CPPUNIT_TEST(test_dot_column);
    CPPUNIT_TEST(test_dot_2d);
    CPPUNIT_TEST(test_dot_fail);

    CPPUNIT_TEST(test_eye_1);
    CPPUNIT_TEST(test_eye_2);
    CPPUNIT_TEST(test_eye_3);
    CPPUNIT_TEST(test_eye_4);

    CPPUNIT_TEST(test_linsolve);

    CPPUNIT_TEST(test_ones_1);
    CPPUNIT_TEST(test_ones_2);
    CPPUNIT_TEST(test_ones_3);

    CPPUNIT_TEST(test_rand_1);
    CPPUNIT_TEST(test_rand_2);
    CPPUNIT_TEST(test_rand_3);

    CPPUNIT_TEST(test_transpose_empty);
    CPPUNIT_TEST(test_transpose_fat);
    CPPUNIT_TEST(test_transpose_tall);
    CPPUNIT_TEST(test_transpose_2dizzle);

    CPPUNIT_TEST(test_tril_2x2);
    CPPUNIT_TEST(test_tril_69x69);
    CPPUNIT_TEST(test_tril_one_pt);
    CPPUNIT_TEST(test_tril_fail);

    CPPUNIT_TEST(test_triu);
    CPPUNIT_TEST(test_triu_2x2);
    CPPUNIT_TEST(test_triu_88x88);
    CPPUNIT_TEST(test_triu_one_pt);
    CPPUNIT_TEST(test_triu_fail);

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
