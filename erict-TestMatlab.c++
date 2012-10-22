
//
// projects/matlab/TestMatlab.c++
// Copyright (C) 2012
// Glenn P. Downing
//

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
        CPPUNIT_ASSERT(x.eq(z));
    }

  void test_horzcat_1 () {
    Matrix<int> x(1, 1, 1);
    Matrix<int> r;
    Matrix<int> e(1, 2, 1);
    r = horzcat(x, x);
    CPPUNIT_ASSERT(e.eq(r));
  }

  void test_horzcat_a () {
    Matrix<int> x(4, 0);
    Matrix<int> y(4, 1, 1);
    Matrix<int> r(4, 1);
    Matrix<int> e(4, 1, 1);
    r = horzcat(x, y);
    CPPUNIT_ASSERT(e.eq(r));
  }

  void test_horzcat_b () {
    Matrix<int> x(0, 4);
    Matrix<int> r(0, 8);
    Matrix<int> e(0, 8);
    r = horzcat(x, x);
    CPPUNIT_ASSERT(e.eq(r));
  }

  void test_horzcat_Xby1 () {
    Matrix<int> x(4, 1);
    Matrix<int> r;
    Matrix<int> e(4, 2);
    x[0][0] = e[0][0] = e[0][1] = 1;
    x[1][0] = e[1][0] = e[1][1] = 2;
    x[2][0] = e[2][0] = e[2][1] = 3;
    x[3][0] = e[3][0] = e[3][1] = 4;
    r = horzcat(x, x);
    CPPUNIT_ASSERT(e.eq(r));
  }

  void test_horzcat_1byX () {
    Matrix<int> x(1, 4);
    Matrix<int> r;
    Matrix<int> e(1, 8);
    x[0][0] = e[0][0] = e[0][4] = 1;
    x[0][1] = e[0][1] = e[0][5] = 2;
    x[0][2] = e[0][2] = e[0][6] = 3;
    x[0][3] = e[0][3] = e[0][7] = 4;
    r = horzcat(x, x);
    CPPUNIT_ASSERT(e.eq(r));
  }

  void test_horzcat_2 () {
    Matrix<int> e(5, 3, 0);
    Matrix<int> x(5, 1, 1);
    x[0][0] = e[0][0] = 1;
    x[1][0] = e[1][0] = 2;
    x[2][0] = e[2][0] = 3;
    x[3][0] = e[3][0] = 4;
    x[4][0] = e[4][0] = 5;
    Matrix<int> y(5, 2, 1);
    y[0][0] = e[0][1] = 6;
    y[1][0] = e[1][1] = 7;
    y[2][0] = e[2][1] = 8;
    y[3][0] = e[3][1] = 9;
    y[4][0] = e[4][1] = 1;
    y[0][1] = e[0][2] = 2;
    y[1][1] = e[1][2] = 3;
    y[2][1] = e[2][2] = 4;
    y[3][1] = e[3][2] = 5;
    y[4][1] = e[4][2] = 6;
    Matrix<int> r;
    r = horzcat(x, y);
    CPPUNIT_ASSERT(e.eq(r));
  }

  void test_horzcat_3 () {
    Matrix<int> x(5, 1, 1);
    Matrix<int> y(4, 1, 0);
    Matrix<int> r;
    try {
      r = horzcat(x, y);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

  // -------
  // vertcat
  // -------

    void test_vertcat () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

  void test_vertcat_1 () {
    Matrix<int> x(1, 1, 1);
    Matrix<int> r;
    Matrix<int> e(2, 1, 1);
    r = vertcat(x, x);
    CPPUNIT_ASSERT(e.eq(r));
  }

  void test_vertcat_Xby0 () {
    Matrix<int> x(3, 0);
    Matrix<int> r;
    Matrix<int> e(6, 0);
    r = vertcat(x, x);
    CPPUNIT_ASSERT(e.eq(r));
  }

  void test_vertcat_0byX () {
    Matrix<int> x(0, 3);
    Matrix<int> r;
    Matrix<int> e(0, 3);
    r = vertcat(x, x);
    CPPUNIT_ASSERT(e.eq(r));
  }

  void test_vertcat_Xby1 () {
    Matrix<int> x(3, 1, 1);
    Matrix<int> r;
    Matrix<int> e(6, 1, 1);
    r = vertcat(x, x);
    CPPUNIT_ASSERT(e.eq(r));
  }

  void test_vertcat_1byX () {
    Matrix<int> x(1, 3, 1);
    Matrix<int> r;
    Matrix<int> e(2, 3, 1);
    r = vertcat(x, x);
    CPPUNIT_ASSERT(e.eq(r));
  }
  void test_vertcat_2 () {
    Matrix<int> e(3, 5, 0);
    Matrix<int> x(1, 5, 1);
    x[0][0] = e[0][0] = 1;
    x[0][1] = e[0][1] = 2;
    x[0][2] = e[0][2] = 3;
    x[0][3] = e[0][3] = 4;
    x[0][4] = e[0][4] = 5;
    Matrix<int> y(2, 5, 1);
    y[0][0] = e[1][0] = 6;
    y[0][1] = e[1][1] = 7;
    y[0][2] = e[1][2] = 8;
    y[0][3] = e[1][3] = 9;
    y[0][4] = e[1][4] = 1;
    y[1][0] = e[2][0] = 2;
    y[1][1] = e[2][1] = 3;
    y[1][2] = e[2][2] = 4;
    y[1][3] = e[2][3] = 5;
    y[1][4] = e[2][4] = 6;
    Matrix<int> r;
    r = vertcat(x, y);
    CPPUNIT_ASSERT(e.eq(r));
  }

  void test_vertcat_3 () {
    Matrix<int> x(1, 5, 1);
    Matrix<int> y(1, 4, 0);
    Matrix<int> r;
    try {
      r = horzcat(x, y);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

    // ---------
    // test_diag
    // ---------

    void test_diag () {
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_diag_1
    // ---------

    void test_diag_1 () {
        Matrix<int> x(2, 2, 3);
        Matrix<int> y(2, 1);
        y[0][0] = 3;
        y[1][0] = 3;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_diag_2
    // ---------

    void test_diag_2 () {
        Matrix<int> x(2, 3, 3);
        Matrix<int> y(2, 1);
        y[0][0] = 3;
        y[1][0] = 3;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_diag_3
    // ---------

    void test_diag_3 () {
        Matrix<int> x(3, 2, 3);
        Matrix<int> y(2, 1);
        y[0][0] = 3;
        y[1][0] = 3;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_diag_Xby0 () {
        Matrix<int> x(3, 0);
        Matrix<int> y(0, 0);
        x = diag(x);
        //std::cout << "x is now:" << std::endl;
        //x.print();
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_diag_0byX () {
        Matrix<int> x(0, 3);
        Matrix<int> y(0, 0);
        x = diag(x);
        //std::cout << "x is now:" << std::endl;
        //x.print();
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_diag_vector () {
        Matrix<int> x(1, 3, 3);
        Matrix<int> y(3, 3, 0);
        y[0][0] = 3;
        y[1][1] = 3;
        y[2][2] = 3;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_diag_col_vector () {
        Matrix<int> x(3, 1, 3);
        Matrix<int> y(3, 3, 0);
        y[0][0] = 3;
        y[1][1] = 3;
        y[2][2] = 3;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------
    // test_dot
    // --------

    void test_dot () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

  void test_dot_1 () {
    Matrix<int> x(1, 1, 2);
    Matrix<int> y(1, 1, 2);
    Matrix<int> e(1, 1, 4);
    Matrix<int> r;
    r = dot(x, y);
    CPPUNIT_ASSERT(r.eq(e));
  }

  void test_dot_2 () {
    Matrix<int> x(2, 2);
    x[0][0] = 1;
    x[0][1] = 2;
    x[1][0] = 3;
    x[1][1] = 4;
    Matrix<int>y(2, 2);
    y[0][0] = 5;
    y[0][1] = 6;
    y[1][0] = 7;
    y[1][1] = 8;
    Matrix<int>e(1, 2);
    e[0][0] = 26;
    e[0][1] = 44;
    Matrix<int> r;
    r = dot(x, y);
    CPPUNIT_ASSERT(r.eq(e));
  }

  void test_dot_3 () {
    Matrix<int> x(1, 5, 2);
    Matrix<int>y(5, 1, 2);
    Matrix<int>e(1, 1, 20);
    Matrix<int> r;
    r = dot(x, y);
    CPPUNIT_ASSERT(r.eq(e));
  }
//TODO: implement these methods
  void test_dot_0byXP () {
    Matrix<int> x(0, 5);
    Matrix<int>e(1, 5, 0);
    Matrix<int> r;
    r = dot(x, x);
    CPPUNIT_ASSERT(r.eq(e));
  }

  void test_dot_0byXP2 () {
    Matrix<int> x(0, 1);
    Matrix<int>e(1, 1, 0);
    Matrix<int> r;
    r = dot(x, x);
    CPPUNIT_ASSERT(r.eq(e));
  }

  void test_dot_0byXF () {
    Matrix<int> x(0, 5);
    Matrix<int> y(0, 4);
    Matrix<int> r;
    try {
      r = dot(x, y);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

  void test_dot_Xby0P () {
    Matrix<int> x(5, 0);
    Matrix<int>e(1, 0);
    Matrix<int> r;
    r = dot(x, x);
    CPPUNIT_ASSERT(r.eq(e));
  }

  void test_dot_Xby0P2 () {
    Matrix<int> x(1, 0);
    Matrix<int>e(1, 1, 0);
    Matrix<int> r;
    r = dot(x, x);
    CPPUNIT_ASSERT(r.eq(e));
  }

  void test_dot_Xby0F () {
    Matrix<int> x(5, 0);
    Matrix<int> y(4, 0);
    Matrix<int> r;
    try {
      r = dot(x, y);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

  void test_dot_vector_1 () {
    Matrix<int> x(1, 5,2);
    Matrix<int>y(1, 5, 2);
    Matrix<int>e(1, 1,20);
    Matrix<int> r;
    r = dot(x, y);
    CPPUNIT_ASSERT(r.eq(e));
  }

  void test_dot_vector_2 () {
    Matrix<int> x(5, 1, 2);
    Matrix<int>y(5, 1, 2);
    Matrix<int>e(1, 1,20);
    Matrix<int> r;
    r = dot(x, y);
    CPPUNIT_ASSERT(r.eq(e));
  }

  void test_dot_vector_3 () {
    Matrix<int> x(1, 5,2);
    Matrix<int>y(5, 1, 2);
    Matrix<int>e(1, 1,20);
    Matrix<int> r;
    r = dot(x, y);
    CPPUNIT_ASSERT(r.eq(e));
  }

  void test_dot_vector_4 () {
    Matrix<int> x(5, 1,2);
    Matrix<int>y(1, 5, 2);
    Matrix<int>e(1, 1,20);
    Matrix<int> r;
    r = dot(x, y);
    CPPUNIT_ASSERT(r.eq(e));
  }

  void test_dot_vector_5 () {
    Matrix<int> x(1, 3,2);
    Matrix<int>y(1, 5, 2);
    Matrix<int> r;
    try {
      r = dot(x, y);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

  void test_dot_vector_6 () {
    Matrix<int> x(3, 1,2);
    Matrix<int>y(5, 1, 2);
    Matrix<int> r;
    try{
      r = dot(x, y);
      CPPUNIT_ASSERT(false);
	} catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

  void test_dot_vector_7 () {
    Matrix<int> x(1, 3,2);
    Matrix<int>y(5, 1, 2);
    Matrix<int> r;
    try{
      r = dot(x, y);
      CPPUNIT_ASSERT(false);
	} catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

  void test_dot_vector_8 () {
    Matrix<int> x(3, 1,2);
    Matrix<int>y(1, 5, 2);
    Matrix<int> r;
    try{
      r = dot(x, y);
      CPPUNIT_ASSERT(false);
	} catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

    // --------
    // test_eye
    // --------

    void test_eye () {
        Matrix<int> x;
        Matrix<int> y(2, 3);
        for (unsigned int i = 0; i < y.rows(); i++)
          for (unsigned int j = 0; j < y.columns(); j++)
            if (i == j)
              y[i][j] = 1;

        x = eye< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    // ----------
    // test_eye_1
    // ----------

    void test_eye_1 () {
        Matrix<int> x(4, 4);
        Matrix<int> y(4, 4, 0);
        for (unsigned int i = 0; i < y.rows(); i++)
          for (unsigned int j = 0; j < y.columns(); j++)
            if (i == j)
              y[i][j] = 1;

        x = eye<Matrix<int> > (4, 4);
        CPPUNIT_ASSERT(x.eq(y));}

    // ----------
    // test_eye_2
    // ----------

    void test_eye_2 () {
        Matrix<int> x(6, 4);
        Matrix<int> y(6, 4, 0);
        for (unsigned int i = 0; i < y.rows(); i++)
          for (unsigned int j = 0; j < y.columns(); j++)
            if (i == j)
              y[i][j] = 1;

        x = eye<Matrix<int> > (6, 4);
        CPPUNIT_ASSERT(x.eq(y));}

    // ----------
    // test_eye_3
    // ----------

    void test_eye_3 () {
        Matrix<int> x;
        Matrix<int> y;

        x = eye<Matrix<int> > (0, 0);
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

  void test_ones_1 () {
    Matrix<int> x;
    Matrix<int> y(100, 1, 1);
    x = ones< Matrix<int> >(100, 1);
    CPPUNIT_ASSERT(x.eq(y));}

  void test_ones_2 () {
    Matrix<int> x;
    Matrix<int> y(1, 1, 1);
    x = ones< Matrix<int> >(1, 1);
    CPPUNIT_ASSERT(x.eq(y));}

  void test_ones_3 () {
    Matrix<int> x;
    Matrix<int> y(0, 0, 1);
    x = ones< Matrix<int> >(0, 0);
    CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_rand
    // ---------

    void test_rand () {
        Matrix<int> x;
        Matrix<int> y;
        x = rand< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(!x.eq(y));}

    // ---------
    // test_rand_1
    // ---------

    void test_rand_1 () {
        Matrix<int> x(2, 3, 0);
        Matrix<int> y(2, 3, 0);
        x = rand< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(!x.eq(y));}

    // ---------
    // test_rand_2
    // ---------

    void test_rand_2 () {
        Matrix<int> x(4, 3, 0);
        Matrix<int> y(4, 3, 0);
        x = rand< Matrix<int> >(4, 3);
        CPPUNIT_ASSERT(!x.eq(y));}

    // ---------
    // test_rand_3
    // ---------

    void test_rand_3 () {
        Matrix<int> x(3, 3, 0);
        Matrix<int> y(3, 3, 0);
        x = rand< Matrix<int> >(3, 3);
        CPPUNIT_ASSERT(!x.eq(y));}

    // ---------
    // test_rand_4
    // ---------

    void test_rand_4 () {
        Matrix<double> x(3, 3, 3.1);
        Matrix<double> y(3, 3, 3.1);
        x = rand< Matrix<double> >(3, 3);
        CPPUNIT_ASSERT(!x.eq(y));}

    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

  void test_transpose_1 () {
    Matrix<int> x(1, 5, 1);
    Matrix<int> y(5, 1, 1);
    x = transpose(x);
    CPPUNIT_ASSERT(x.eq(y));
  }

  void test_transpose_2 () {
    Matrix<int> x(2, 2, 1);
    Matrix<int> y(2, 2, 1);
    x[0][0] = y[0][0] = 1;
    x[0][1] = y[1][0] = 2;
    x[1][0] = y[0][1] = 3;
    x[1][1] = y[1][1] = 4;
    x = transpose(x);
    CPPUNIT_ASSERT(x.eq(y));
  }

  void test_transpose_3 () {
    Matrix<int> x(3, 2, 1);
    Matrix<int> y(2, 3, 1);
    x[0][0] = y[0][0] = 1;
    x[0][1] = y[1][0] = 2;
    x[1][0] = y[0][1] = 3;
    x[1][1] = y[1][1] = 4;
    x[2][0] = y[0][2] = 5;
    x[2][1] = y[1][2] = 6;
    x = transpose(x);
    CPPUNIT_ASSERT(x.eq(y));
  }

    // ---------
    // test_tril
    // ---------

    void test_tril () {
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

  void test_tril_1 () {
    Matrix<int> x(2, 2, 1);
    Matrix<int> y(2, 2, 1);
    y[0][1] = 0;
    x = tril(x);
    CPPUNIT_ASSERT(x.eq(y));
  }

  void test_tril_2 () {
    Matrix<int> x(4, 4, 1);
    Matrix<int> y(4, 4, 1);
    y[0][1] = 0;
    y[0][2] = 0;
    y[0][3] = 0;
    y[1][2] = 0;
    y[1][3] = 0;
    y[2][3] = 0;
    x = tril(x);
    CPPUNIT_ASSERT(x.eq(y));
  }

  void test_tril_3 () {
    Matrix<int> x(4, 6, 1);
    Matrix<int> y(4, 6, 1);
    y[0][1] = 0;
    y[0][2] = 0;
    y[0][3] = 0;
    y[0][4] = 0;
    y[0][5] = 0;
    y[1][2] = 0;
    y[1][3] = 0;
    y[1][4] = 0;
    y[1][5] = 0;
    y[2][3] = 0;
    y[2][4] = 0;
    y[2][5] = 0;
    y[3][4] = 0;
    y[3][5] = 0;
    x = tril(x);
    CPPUNIT_ASSERT(x.eq(y));
  }

    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

  void test_triu_1 () {
    Matrix<int> x(2, 2, 1);
    Matrix<int> y(2, 2, 1);
    y[1][0] = 0;
    x = triu(x);
    CPPUNIT_ASSERT(x.eq(y));
  }

  void test_triu_2 () {
    Matrix<int> x(4, 4, 1);
    Matrix<int> y(4, 4, 1);
    y[1][0] = 0;
    y[2][0] = 0;
    y[3][0] = 0;
    y[2][1] = 0;
    y[3][1] = 0;
    y[3][2] = 0;
    x = triu(x);
    CPPUNIT_ASSERT(x.eq(y));
  }

  void test_triu_3 () {
    Matrix<int> x(4, 6, 1);
    Matrix<int> y(4, 6, 1);
    y[1][0] = 0;
    y[2][0] = 0;
    y[3][0] = 0;
    y[2][1] = 0;
    y[3][1] = 0;
    y[3][2] = 0;
    x = triu(x);
    CPPUNIT_ASSERT(x.eq(y));
  }

    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x;
        Matrix<int> y(2, 3, 0);
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    // ------------
    // test_zeros_1
    // ------------

    void test_zeros_1 () {
        Matrix<int> x;
        Matrix<int> y(3, 3, 0);
        x = zeros< Matrix<int> >(3, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    // ------------
    // test_zeros_2
    // ------------

    void test_zeros_2 () {
        Matrix<int> x;
        Matrix<int> y(1, 1, 0);
        x = zeros< Matrix<int> >(1, 1);
        CPPUNIT_ASSERT(x.eq(y));}

    // ------------
    // test_zeros_3
    // ------------

    void test_zeros_3 () {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(test_horzcat_1);
    CPPUNIT_TEST(test_horzcat_2);
    CPPUNIT_TEST(test_horzcat_3);
    CPPUNIT_TEST(test_horzcat_Xby1);
    CPPUNIT_TEST(test_horzcat_1byX);
    CPPUNIT_TEST(test_horzcat_a);
    CPPUNIT_TEST(test_horzcat_b);
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(test_vertcat_1);
    CPPUNIT_TEST(test_vertcat_2);
    CPPUNIT_TEST(test_vertcat_3);
    CPPUNIT_TEST(test_vertcat_Xby0);
    CPPUNIT_TEST(test_vertcat_0byX);
    CPPUNIT_TEST(test_vertcat_Xby1);
    CPPUNIT_TEST(test_vertcat_1byX);
    CPPUNIT_TEST(test_diag);
    CPPUNIT_TEST(test_diag_1);
    CPPUNIT_TEST(test_diag_2);
    CPPUNIT_TEST(test_diag_3);
    CPPUNIT_TEST(test_diag_vector);
    CPPUNIT_TEST(test_diag_col_vector);
    CPPUNIT_TEST(test_diag_Xby0);
    CPPUNIT_TEST(test_diag_0byX);
    CPPUNIT_TEST(test_dot_1);
    CPPUNIT_TEST(test_dot_2);
    CPPUNIT_TEST(test_dot_3);
    CPPUNIT_TEST(test_dot_vector_1);
  CPPUNIT_TEST(test_dot_vector_2);
  CPPUNIT_TEST(test_dot_vector_3);
  CPPUNIT_TEST(test_dot_vector_4);
  CPPUNIT_TEST(test_dot_vector_5);
  CPPUNIT_TEST(test_dot_vector_6);
  CPPUNIT_TEST(test_dot_vector_7);
  CPPUNIT_TEST(test_dot_vector_8);
  CPPUNIT_TEST(test_dot_0byXP);
  CPPUNIT_TEST(test_dot_0byXP2);
  CPPUNIT_TEST(test_dot_0byXF);
  CPPUNIT_TEST(test_dot_Xby0P);
  CPPUNIT_TEST(test_dot_Xby0P2);
  CPPUNIT_TEST(test_dot_Xby0F);
    CPPUNIT_TEST(test_eye);
    CPPUNIT_TEST(test_eye_1);
    CPPUNIT_TEST(test_eye_2);
    CPPUNIT_TEST(test_eye_3);
    CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_ones);
    CPPUNIT_TEST(test_ones_1);
    CPPUNIT_TEST(test_ones_2);
    CPPUNIT_TEST(test_ones_3);
    CPPUNIT_TEST(test_rand);
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
    CPPUNIT_TEST(test_triu);
    CPPUNIT_TEST(test_triu_1);
    CPPUNIT_TEST(test_triu_2);
    CPPUNIT_TEST(test_triu_3);
    CPPUNIT_TEST(test_zeros);
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
