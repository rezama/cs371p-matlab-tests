//
// projects/matlab/TestMatrix.c++
// Copyright (C) 2012
// Glenn P. Downing
//

/** 
 * To test the program:
 *     g++ -ansi -pedantic -lcppunit -ldl -Wall TestMatrix.c++ -o TestMatrix.app
 *     valgrind TestMatrix.app >& TestMatrix.out
 */

// --------
// includes
// --------

#include <string>
#include <iostream>
#include <stdio.h>

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
        CPPUNIT_ASSERT(x.size() == 0);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(z.size() == 2);
        CPPUNIT_ASSERT(t.size() == 2);
    }
    
    void test_constructor_1 () {
        Matrix<int> x(2, 3, 4);
        CPPUNIT_ASSERT(x.size() == 2);
	CPPUNIT_ASSERT(x.rows() == 2);
	CPPUNIT_ASSERT(x.columns() == 3);
	for(unsigned int i = 0; i < x.rows(); i++) {
	  for(unsigned int j = 0; j < x.columns(); j++) {
	    CPPUNIT_ASSERT(x[i][j] == 4);
	  }
	}
    }

  void test_constructor_2 () {
    Matrix<double> x(5, 1, 9.0);
    CPPUNIT_ASSERT(x.size() == 5);
    CPPUNIT_ASSERT(x.rows() == 5);
    CPPUNIT_ASSERT(x.columns() == 1);
    for(unsigned int i = 0; i < x.rows(); i++) {
      for(unsigned int j = 0; j < x.columns(); j++) {
	CPPUNIT_ASSERT(x[i][j] == 9.0);
      }
    }
  }

  void test_constructor_3 () {
    Matrix<std::string> x(9,11, "def");
    CPPUNIT_ASSERT(x.size() == 9);
    CPPUNIT_ASSERT(x.rows() == 9);
    CPPUNIT_ASSERT(x.columns() == 11);
    for(unsigned int i = 0; i < x.rows(); i++) {
      for(unsigned int j = 0; j< x.columns(); j++) {
	CPPUNIT_ASSERT(x[i][j] == "def");
      } 
    }
  }

  void test_constructor_4 () {
    Matrix<double> x(5, 0, 9.0);
    CPPUNIT_ASSERT(x.size() == 5);
    CPPUNIT_ASSERT(x.rows() == 5);
    CPPUNIT_ASSERT(x.columns() == 0);
  }

  void test_constructor_5 () {
    Matrix<int> x(0, 0);
    Matrix<int> e(0, 0);
    CPPUNIT_ASSERT(x.eq(e));
  }

    // ----------
    // test_index
    // ----------

    void test_index () {
      const Matrix<int> x(1,1);
        CPPUNIT_ASSERT(x[0][0] == 0);}

    void test_index_1 () {
        const Matrix<int> x(2, 3, 0);
        CPPUNIT_ASSERT(x[0][0] == 0);}

    void test_index_2 () {
        Matrix<int> x(2, 3, 0);
        x[1][1] = -1;
        CPPUNIT_ASSERT(x[0][0] == 0);
        CPPUNIT_ASSERT(x[1][1] == -1);}

  void test_index_3 () {
    Matrix<int> x(10, 10, 0);
    x[9][9] = -1;
    CPPUNIT_ASSERT(x[0][0] == 0);
    CPPUNIT_ASSERT(x[9][9] == -1);}

    // -----------
    // test_equals
    // -----------

    void test_equals () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
    }

  void test_equals_1 () {
    Matrix<int>  x(1,1,1);
    Matrix<int>  y(1,1,1);
    Matrix<bool> z;
    Matrix<bool> t(1,1,true);
    z = (x == y);
    CPPUNIT_ASSERT(z.eq(t));
    x[0][0] = 2;
    t[0][0] = false;
    z = (x == y);
    CPPUNIT_ASSERT(z.eq(t));
  }

  void test_equals_2 () {
    Matrix<int>  x(5,6,1);
    Matrix<int>  y(5,6,1);
    Matrix<bool> z;
    Matrix<bool> t(5,6,true);
    z = (x == y);
    CPPUNIT_ASSERT(z.eq(t));
    x[3][3] = 2;
    t[3][3] = false;
    z = (x == y);
    CPPUNIT_ASSERT(z.eq(t));
  }

  void test_equals_3 () {
    Matrix<int>  x(1,1,1);
    Matrix<int>  y(1,2,1);
    Matrix<bool> z;
    Matrix<bool> t(1,2,true);
    z = (x == y);
    CPPUNIT_ASSERT(z.eq(t));
    z = (y == x);
    CPPUNIT_ASSERT(z.eq(t));
    x[0][0] = 2;
    t[0][0] = false;
    t[0][1] = false;
    z = (x == y);
    CPPUNIT_ASSERT(z.eq(t));
    z = (y == x);
    CPPUNIT_ASSERT(z.eq(t));
  }

  void test_equals_4 () {
    Matrix<int>  x1(2, 1, 0);
    Matrix<int>  y1(1, 2, 2);
    Matrix<bool> z;
    try {
      z = (x1 == y1);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }

    Matrix<int>  x2(2, 1, 0);
    Matrix<int>  y2(3, 1, 2);
    try {
      z = (x2 == y2);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

  // ----------
  // not equals
  // ----------

  void test_not_equals_1 () {
    Matrix<int>  x(1,1,1);
    Matrix<int>  y(1,1,1);
    Matrix<bool> z;
    Matrix<bool> t(1,1,false);
    z = (x != y);
    CPPUNIT_ASSERT(z.eq(t));
    x[0][0] = 2;
    t[0][0] = true;
    z = (x != y);
    CPPUNIT_ASSERT(z.eq(t));
  }

  void test_not_equals_2 () {
    Matrix<int>  x(5,6,1);
    Matrix<int>  y(5,6,1);
    Matrix<bool> z;
    Matrix<bool> t(5,6,false);
    z = (x != y);
    CPPUNIT_ASSERT(z.eq(t));
    x[3][3] = 2;
    t[3][3] = true;
    z = (x != y);
    CPPUNIT_ASSERT(z.eq(t));
  }

  template <typename T>
  void printMatrix (Matrix<T> x) {
    std::cout << std::endl;
    for (unsigned int i = 0; i < x.size(); i++) {
      std::cout << "[ ";
      for (unsigned int j = 0; j < x.columns(); j++) {
	std::cout << x[i][j] << " ";
      }
      std::cout << "]" << std:: endl;
    }
    std::cout << std::endl;
  }

  void test_not_equals_3 () {
    Matrix<int>  x(1,1,1);
    Matrix<int>  y(1,2,1);
    Matrix<bool> z;
    Matrix<bool> t(1,2,false);
    z = (x != y);
    CPPUNIT_ASSERT(z.eq(t));
    z = (y != x);
    CPPUNIT_ASSERT(z.eq(t));
    x[0][0] = 2;
    t[0][0] = true;
    t[0][1] = true;
    z = (x != y);
    CPPUNIT_ASSERT(z.eq(t));
    z = (y != x);
    CPPUNIT_ASSERT(z.eq(t));
  }

  void test_not_equals_4 () {
    Matrix<int>  x1(2, 1, 0);
    Matrix<int>  y1(1, 2, 2);
    Matrix<bool> z;
    try {
      z = (x1 != y1);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }

    Matrix<int>  x2(2, 1, 0);
    Matrix<int>  y2(3, 1, 2);
    try {
      z = (x2 != y2);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

    // --------------
    // test_less_than
    // --------------

    void test_less_than () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
    }

  void test_less_than_1 () {
    Matrix<int>  x(1, 1, 1);
    Matrix<int>  y(1, 1, 2);
    Matrix<bool> z;
    Matrix<bool> t(1, 1, true);
    Matrix<bool> f(1, 1, false);
    z = (x < y);
    //printMatrix(z);
    //printMatrix(t);
    CPPUNIT_ASSERT(z.eq(t));
    z = (y < x);
    CPPUNIT_ASSERT(z.eq(f));
    z = (x < x);
    CPPUNIT_ASSERT(z.eq(f));
  }

  void test_less_than_2 () {
    Matrix<int>  x(1, 1, 0);
    Matrix<int>  y(1, 2, 2);
    Matrix<bool> z;
    Matrix<bool> t(1, 2, true);
    Matrix<bool> f(1, 2, false);
    z = (x < y);
    //printMatrix(z);
    //printMatrix(t);
    CPPUNIT_ASSERT(z.eq(t));
    z = (y < x);
    CPPUNIT_ASSERT(z.eq(f));
  }

  void test_less_than_3 () {
    Matrix<int>  x1(2, 1, 0);
    Matrix<int>  y1(1, 2, 2);
    Matrix<bool> z;
    try {
      z = (x1 < y1);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }

    Matrix<int>  x2(2, 1, 0);
    Matrix<int>  y2(3, 1, 2);
    try {
      z = (x2 < y2);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

  void test_less_than_4 () {
    Matrix<int> x(3, 3);
    x[0][0] = 5;
    x[0][1] = 2;
    x[0][2] = 6;
    x[1][0] = 7;
    x[1][1] = 1;
    x[1][2] = 1;
    x[2][0] = 0;
    x[2][1] = 4;
    x[2][2] = 10;
    Matrix<int> y(3, 3);
    y[0][0] = 2;
    y[0][1] = 2;
    y[0][2] = 9;
    y[1][0] = 8;
    y[1][1] = 9;
    y[1][2] = 10;
    y[2][0] = 1;
    y[2][1] = 1;
    y[2][2] = 2;
    Matrix<bool> z;
    Matrix<bool> e(3, 3);
    e[0][0] = false;
    e[0][1] = false;
    e[0][2] = true;
    e[1][0] = true;
    e[1][1] = true;
    e[1][2] = true;
    e[2][0] = true;
    e[2][1] = false;
    e[2][2] = false;
    z = (x < y);
    CPPUNIT_ASSERT(z.eq(e));
    e[0][0] = true;
    e[0][1] = false;
    e[0][2] = false;
    e[1][0] = false;
    e[1][1] = false;
    e[1][2] = false;
    e[2][0] = false;
    e[2][1] = true;
    e[2][2] = true;
    z = (y < x);
    CPPUNIT_ASSERT(z.eq(e));
  }

  // ----------------
  // less than equals
  // ----------------

  void test_less_than_equals_1 () {
    Matrix<int>  x(1, 1, 1);
    Matrix<int>  y(1, 1, 2);
    Matrix<bool> z;
    Matrix<bool> t(1, 1, true);
    Matrix<bool> f(1, 1, false);
    z = (x <= y);
    CPPUNIT_ASSERT(z.eq(t));
    z = (y <= x);
    CPPUNIT_ASSERT(z.eq(f));
    z = (x <= x);
    CPPUNIT_ASSERT(z.eq(t));
  }

  void test_less_than_equals_2 () {
    Matrix<int>  x(1, 1, 0);
    Matrix<int>  y(1, 2, 2);
    Matrix<bool> z;
    Matrix<bool> t(1, 2, true);
    Matrix<bool> f(1, 2, false);
    z = (x <= y);
    CPPUNIT_ASSERT(z.eq(t));
    z = (y <= x);
    CPPUNIT_ASSERT(z.eq(f));
  }

  void test_less_than_equals_3 () {
    Matrix<int>  x1(2, 1, 0);
    Matrix<int>  y1(1, 2, 2);
    Matrix<bool> z;
    try {
      z = (x1 <= y1);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }

    Matrix<int>  x2(2, 1, 0);
    Matrix<int>  y2(3, 1, 2);
    try {
      z = (x2 <= y2);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

  void test_less_than_equals_4 () {
    Matrix<int> x(3, 3);
    x[0][0] = 5;
    x[0][1] = 2;
    x[0][2] = 6;
    x[1][0] = 7;
    x[1][1] = 1;
    x[1][2] = 1;
    x[2][0] = 0;
    x[2][1] = 4;
    x[2][2] = 10;
    Matrix<int> y(3, 3);
    y[0][0] = 2;
    y[0][1] = 2;
    y[0][2] = 9;
    y[1][0] = 8;
    y[1][1] = 9;
    y[1][2] = 10;
    y[2][0] = 1;
    y[2][1] = 1;
    y[2][2] = 2;
    Matrix<bool> z;
    Matrix<bool> e(3, 3);
    e[0][0] = false;
    e[0][1] = true;
    e[0][2] = true;
    e[1][0] = true;
    e[1][1] = true;
    e[1][2] = true;
    e[2][0] = true;
    e[2][1] = false;
    e[2][2] = false;
    z = (x <= y);
    CPPUNIT_ASSERT(z.eq(e));
    e[0][0] = true;
    e[0][1] = true;
    e[0][2] = false;
    e[1][0] = false;
    e[1][1] = false;
    e[1][2] = false;
    e[2][0] = false;
    e[2][1] = true;
    e[2][2] = true;
    z = (y <= x);
    CPPUNIT_ASSERT(z.eq(e));
  }

  // ------------
  // greater then
  // ------------

  void test_greater_than_1 () {
    Matrix<int>  x(1, 1, 1);
    Matrix<int>  y(1, 1, 2);
    Matrix<bool> z;
    Matrix<bool> t(1, 1, true);
    Matrix<bool> f(1, 1, false);
    z = (x > y);
    CPPUNIT_ASSERT(z.eq(f));
    z = (y > x);
    CPPUNIT_ASSERT(z.eq(t));
    z = (x > x);
    CPPUNIT_ASSERT(z.eq(f));
  }

  void test_greater_than_2 () {
    Matrix<int>  x(1, 1, 0);
    Matrix<int>  y(1, 2, 2);
    Matrix<bool> z;
    Matrix<bool> t(1, 2, true);
    Matrix<bool> f(1, 2, false);
    z = (x > y);
    CPPUNIT_ASSERT(z.eq(f));
    z = (y > x);
    CPPUNIT_ASSERT(z.eq(t));
  }

  void test_greater_than_3 () {
    Matrix<int>  x1(2, 1, 0);
    Matrix<int>  y1(1, 2, 2);
    Matrix<bool> z;
    try {
      z = (x1 > y1);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }

    Matrix<int>  x2(2, 1, 0);
    Matrix<int>  y2(3, 1, 2);
    try {
      z = (x2 > y2);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

  void test_greater_than_4 () {
    Matrix<int> x(3, 3);
    x[0][0] = 5;
    x[0][1] = 2;
    x[0][2] = 6;
    x[1][0] = 7;
    x[1][1] = 1;
    x[1][2] = 1;
    x[2][0] = 0;
    x[2][1] = 4;
    x[2][2] = 10;
    Matrix<int> y(3, 3);
    y[0][0] = 2;
    y[0][1] = 2;
    y[0][2] = 9;
    y[1][0] = 8;
    y[1][1] = 9;
    y[1][2] = 10;
    y[2][0] = 1;
    y[2][1] = 1;
    y[2][2] = 2;
    Matrix<bool> z;
    Matrix<bool> e(3, 3);
    e[0][0] = true;
    e[0][1] = false;
    e[0][2] = false;
    e[1][0] = false;
    e[1][1] = false;
    e[1][2] = false;
    e[2][0] = false;
    e[2][1] = true;
    e[2][2] = true;
    z = (x > y);
    CPPUNIT_ASSERT(z.eq(e));
    e[0][0] = false;
    e[0][1] = false;
    e[0][2] = true;
    e[1][0] = true;
    e[1][1] = true;
    e[1][2] = true;
    e[2][0] = true;
    e[2][1] = false;
    e[2][2] = false;
    z = (y > x);
    CPPUNIT_ASSERT(z.eq(e));
  }

  // ------------
  // greater then 
  // ------------

  void test_greater_than_equals_1 () {
    Matrix<int>  x(1, 1, 1);
    Matrix<int>  y(1, 1, 2);
    Matrix<bool> z;
    Matrix<bool> t(1, 1, true);
    Matrix<bool> f(1, 1, false);
    z = (x >= y);
    CPPUNIT_ASSERT(z.eq(f));
    z = (y >= x);
    CPPUNIT_ASSERT(z.eq(t));
    z = (x >= x);
    CPPUNIT_ASSERT(z.eq(t));
  }

  void test_greater_than_equals_2 () {
    Matrix<int>  x(1, 1, 0);
    Matrix<int>  y(1, 2, 2);
    Matrix<bool> z;
    Matrix<bool> t(1, 2, true);
    Matrix<bool> f(1, 2, false);
    z = (x >= y);
    CPPUNIT_ASSERT(z.eq(f));
    z = (y >= x);
    CPPUNIT_ASSERT(z.eq(t));
  }

  void test_greater_than_equals_3 () {
    Matrix<int>  x1(2, 1, 0);
    Matrix<int>  y1(1, 2, 2);
    Matrix<bool> z;
    try {
      z = (x1 >= y1);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }

    Matrix<int>  x2(2, 1, 0);
    Matrix<int>  y2(3, 1, 2);
    try {
      z = (x2 >= y2);
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

  void test_greater_than_equals_4 () {
    Matrix<int> x(3, 3);
    x[0][0] = 5;
    x[0][1] = 2;
    x[0][2] = 6;
    x[1][0] = 7;
    x[1][1] = 1;
    x[1][2] = 1;
    x[2][0] = 0;
    x[2][1] = 4;
    x[2][2] = 10;
    Matrix<int> y(3, 3);
    y[0][0] = 2;
    y[0][1] = 2;
    y[0][2] = 9;
    y[1][0] = 8;
    y[1][1] = 9;
    y[1][2] = 10;
    y[2][0] = 1;
    y[2][1] = 1;
    y[2][2] = 2;
    Matrix<bool> z;
    Matrix<bool> e(3, 3);
    e[0][0] = true;
    e[0][1] = true;
    e[0][2] = false;
    e[1][0] = false;
    e[1][1] = false;
    e[1][2] = false;
    e[2][0] = false;
    e[2][1] = true;
    e[2][2] = true;
    z = (x >= y);
    CPPUNIT_ASSERT(z.eq(e));
    e[0][0] = false;
    e[0][1] = true;
    e[0][2] = true;
    e[1][0] = true;
    e[1][1] = true;
    e[1][2] = true;
    e[2][0] = true;
    e[2][1] = false;
    e[2][2] = false;
    z = (y >= x);
    CPPUNIT_ASSERT(z.eq(e));
  }

    // ---------
    // test_plus
    // ---------

    void test_plus_equals () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}

    // -----------
    // test_plus_1
    // -----------

    void test_plus_equals_1 () {
        Matrix<int> x(2, 2);
        x[0][0] = 1;
        x[0][1] = 1;
        x[1][0] = 1;
        x[1][1] = 1;
        Matrix<int> y(2, 2);
        y[0][0] = 2;
        y[0][1] = 2;
        y[1][0] = 2;
        y[1][1] = 2;
        x += x;
        CPPUNIT_ASSERT(x.eq(y));}

    // -----------
    // test_plus_2
    // -----------

    void test_plus_equals_2 () {
        Matrix<int> x(2, 2);
        x[0][0] = 1;
        x[0][1] = 1;
        x[1][0] = 1;
        x[1][1] = 1;
        Matrix<int> y(2, 3);
        try {
          x += y;
          CPPUNIT_ASSERT(false);
        }
        catch (std::exception& e) {
          CPPUNIT_ASSERT(true);
        }}

    // -----------
    // test_plus_3
    // -----------

    void test_plus_equals_3 () {
        Matrix<int> x(2, 2);
        x[0][0] = 1;
        x[0][1] = 1;
        x[1][0] = 1;
        x[1][1] = 1;
        Matrix<int> y(2, 2);
        y[0][0] = 2;
        y[0][1] = 2;
        y[1][0] = 2;
        y[1][1] = 2;
        Matrix<int> z(2, 2);
        z[0][0] = 3;
        z[0][1] = 3;
        z[1][0] = 3;
        z[1][1] = 3;
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
    }

  void test_plus_equals_4 () {
    Matrix<int> x(1, 1, 1);
    Matrix<int> y(1, 3);
    y[0][0] = 1;
    y[0][1] = 2;
    y[0][2] = 3;
    Matrix<int> e(1, 3);
    e[0][0] = 2;
    e[0][1] = 3;
    e[0][2] = 4;
    y += x;
    CPPUNIT_ASSERT(y.eq(e));
  }

  void test_plus_equals_5 () {
    Matrix<int> x(1, 1,1);
    Matrix<int> y(1, 3);
    y[0][0] = 1;
    y[0][1] = 2;
    y[0][2] = 3;
    Matrix<int> e(1, 3);
    e[0][0] = 2;
    e[0][1] = 3;
    e[0][2] = 4;
    x += y;
    CPPUNIT_ASSERT(x.eq(e));
  }

  // -----------                                                                                                                                                              
  // test_plus_1                                                                                                                                                              
  // -----------                                                                                                                                                              

  void test_plus_1 () {
    Matrix<int> x(2, 2);
    x[0][0] = 1;
    x[0][1] = 1;
    x[1][0] = 1;
    x[1][1] = 1;
    Matrix<int> x2 = x;
    Matrix<int> e(2, 2);
    e[0][0] = 2;
    e[0][1] = 2;
    e[1][0] = 2;
    e[1][1] = 2;
    Matrix<int> r;
    r = x + x;
    CPPUNIT_ASSERT(r.eq(e));
    CPPUNIT_ASSERT(x.eq(x2));
  }

  // -----------                                                                                                                                                                                                                
  // test_plus_2                                                                                                                                                                                                                
  // -----------                                                                                                                                                                                                                

  void test_plus_2 () {
    Matrix<int> x(2, 2);
    x[0][0] = 1;
    x[0][1] = 1;
    x[1][0] = 1;
    x[1][1] = 1;
    Matrix<int> y(2, 3);
    try {
      x = x + y;
      CPPUNIT_ASSERT(false);
    }
    catch (std::exception& e) {
      CPPUNIT_ASSERT(true);
    }
  }

  // -----------                                                                                                                                                                                                                
  // test_plus_3                                                                                                                                                                                                                
  // -----------                                                                                                                                                                                                                

  void test_plus_3 () {
    Matrix<int> x(2, 2);
    x[0][0] = 1;
    x[0][1] = 1;
    x[1][0] = 1;
    x[1][1] = 1;
    Matrix<int> y(2, 2);
    y[0][0] = 2;
    y[0][1] = 2;
    y[1][0] = 2;
    y[1][1] = 2;
    Matrix<int> z(2, 2);
    z[0][0] = 3;
    z[0][1] = 3;
    z[1][0] = 3;
    z[1][1] = 3;
    x = x + y;
    CPPUNIT_ASSERT(x.eq(z));
  }

    // ----------
    // test_minus
    // ----------

    void test_minus_equals () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}

    // -----------
    // test_minus_1
    // -----------

    void test_minus_equals_1 () {
        Matrix<int> x(2, 2);
        x[0][0] = 1;
        x[0][1] = 1;
        x[1][0] = 1;
        x[1][1] = 1;
        Matrix<int> y(2, 2);
        y[0][0] = 0;
        y[0][1] = 0;
        y[1][0] = 0;
        y[1][1] = 0;
        x -= x;
        CPPUNIT_ASSERT(x.eq(y));
    }

    // -----------
    // test_minus_2
    // -----------

    void test_minus_equals_2 () {
        Matrix<int> x(2, 2);
        x[0][0] = 1;
        x[0][1] = 1;
        x[1][0] = 1;
        x[1][1] = 1;
        Matrix<int> y(2, 3);
        try {
          x -= y;
          CPPUNIT_ASSERT(false);
        }
        catch (std::exception& e) {
          CPPUNIT_ASSERT(true);
        }}

    // -----------
    // test_minus_3
    // -----------

    void test_minus_equals_3 () {
        Matrix<int> x(2, 2);
        x[0][0] = 1;
        x[0][1] = 1;
        x[1][0] = 1;
        x[1][1] = 1;
        Matrix<int> y(2, 2);
        y[0][0] = 2;
        y[0][1] = 2;
        y[1][0] = 2;
        y[1][1] = 2;
        Matrix<int> z(2, 2);
        z[0][0] = -1;
        z[0][1] = -1;
        z[1][0] = -1;
        z[1][1] = -1;
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
    }
  
  void test_minus_equals_4 () {
    Matrix<int> x(1, 1, 1);
    Matrix<int> y(1, 3);
    y[0][0] = 1;
    y[0][1] = 2;
    y[0][2] = 3;
    Matrix<int> e(1, 3);
    e[0][0] = 0;
    e[0][1] = 1;
    e[0][2] = 2;
    y -= x;
    CPPUNIT_ASSERT(y.eq(e));
  }

  void test_minus_equals_5 () {
    Matrix<int> x(1, 1,1);
    Matrix<int> y(1, 3);
    y[0][0] = 1;
    y[0][1] = 2;
    y[0][2] = 3;
    Matrix<int> e(1, 3);
    e[0][0] = 0;
    e[0][1] = -1;
    e[0][2] = -2;
    x -= y;
    CPPUNIT_ASSERT(x.eq(e));
  }

  void test_minus_1 () {
    Matrix<int> x(2, 2);
    x[0][0] = 1;
    x[0][1] = 1;
    x[1][0] = 1;
    x[1][1] = 1;
    Matrix<int> y(2, 2);
    y[0][0] = 0;
    y[0][1] = 0;
    y[1][0] = 0;
    y[1][1] = 0;
    Matrix<int> z;
    z = x - x;
    CPPUNIT_ASSERT(z.eq(y));
  }

  void test_minus_2 () {
    Matrix<int> x(2, 2);
    x[0][0] = 1;
    x[0][1] = 1;
    x[1][0] = 1;
    x[1][1] = 1;
    Matrix<int> y(2, 3);
    try {
      x = x - y;
      CPPUNIT_ASSERT(false);
    }
    catch (std::exception& e) {
      CPPUNIT_ASSERT(true);
    }
  }

  void test_minus_3 () {
    Matrix<int> x(2, 2);
    x[0][0] = 1;
    x[0][1] = 1;
    x[1][0] = 1;
    x[1][1] = 1;
    Matrix<int> y(2, 2);
    y[0][0] = 2;
    y[0][1] = 2;
    y[1][0] = 2;
    y[1][1] = 2;
    Matrix<int> z(2, 2);
    z[0][0] = -1;
    z[0][1] = -1;
    z[1][0] = -1;
    z[1][1] = -1;
    x = x - y;
    CPPUNIT_ASSERT(x.eq(z));
  }

    // ------------------------------
    // test_multiplies (matrix * int)
    // ------------------------------

    void test_multiplies () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}

  void test_multiplies_MI_1 () {
    Matrix<int> x(1, 1, 1);
    int y = 2;
    Matrix<int> z(1, 1, 2);
    x *= y;
    CPPUNIT_ASSERT(x.eq(z));
  }

  void test_multiplies_MI_2 () {
    Matrix<int> x(5, 2, 10);
    int y = 55;
    Matrix<int>z(5, 2, 550);
    x *= y;
    CPPUNIT_ASSERT(x.eq(z));
  }

  void test_multiplies_MI_3 () {
    Matrix<int> x(0, 1,1);
    int y = 2;
    Matrix<int> z(0, 1);
    x *= y;
    CPPUNIT_ASSERT(x.eq(z));
  }

  void test_multiplies_MM_1 () {
    Matrix<int> x(1, 1, 1);
    Matrix<int> y(1, 1, 2);
    Matrix<int> z(1, 1, 2);
    x *= y;
    CPPUNIT_ASSERT(x.eq(z));
  }

  void test_multiplies_MM_2 () {
    Matrix<int> x1(3, 1, 1);
    Matrix<int> y1(1, 4, 1);
    Matrix<int> z1(3, 4, 1);
    x1 *= y1;
    CPPUNIT_ASSERT(x1.eq(z1));
    Matrix<int> x2(3, 1, 1);
    Matrix<int> y2(1, 4, 1);
    Matrix<int> z2(3, 4, 1);
    try {
      y1 *= x1;
      CPPUNIT_ASSERT(false);
    } catch (...) {
      CPPUNIT_ASSERT(true);
    }
  }

  void test_multiplies_MM_3 () {
    Matrix<int> x(3, 2);
    x[0][0] = 4;
    x[0][1] = 5;
    x[1][0] = 9;
    x[1][1] = 0;
    x[2][0] = 1;
    x[2][1] = 1;
    Matrix<int> y(2, 4);
    y[0][0] = 4;
    y[0][1] = 5;
    y[0][2] = 6;
    y[0][3] = 10;
    y[1][0] = 5;
    y[1][1] = 7;
    y[1][2] = 2;
    y[1][3] = 1;
    Matrix<int> z(3, 4);
    z[0][0] = 41;
    z[0][1] = 55;
    z[0][2] = 34;
    z[0][3] = 45;
    z[1][0] = 36;
    z[1][1] = 45;
    z[1][2] = 54;
    z[1][3] = 90;
    z[2][0] = 9;
    z[2][1] = 12;
    z[2][2] = 8;
    z[2][3] = 11;
    x *= y;
    CPPUNIT_ASSERT(x.eq(z));
 }

  void test_mult_equals_4 () {
    Matrix<int> x(1, 1, 2);
    Matrix<int> y(1, 3);
    y[0][0] = 1;
    y[0][1] = 2;
    y[0][2] = 3;
    Matrix<int> e(1, 3);
    e[0][0] = 2;
    e[0][1] = 4;
    e[0][2] = 6;
    y *= x;
    CPPUNIT_ASSERT(y.eq(e));
  }

  void test_mult_equals_5 () {
    Matrix<int> x(1, 1, 2);
    Matrix<int> y(1, 3);
    y[0][0] = 1;
    y[0][1] = 2;
    y[0][2] = 3;
    Matrix<int> e(1, 3);
    e[0][0] = 2;
    e[0][1] = 4;
    e[0][2] = 6;
    x *= y;
    CPPUNIT_ASSERT(x.eq(e));
  }

  // --
  // eq
  // --

  void test_eq_1 () {
    Matrix<int> x;
    Matrix<int> y;
    CPPUNIT_ASSERT(x.eq(y));
    CPPUNIT_ASSERT(y.eq(x));
  }

  void test_eq_2 () {
    Matrix<int> x(1, 2, 3);
    Matrix<int> y(1, 2, 3);
    CPPUNIT_ASSERT(x.eq(y));
    CPPUNIT_ASSERT(y.eq(x));
    y[0][0] = -3;
    CPPUNIT_ASSERT(!x.eq(y));
    CPPUNIT_ASSERT(!y.eq(x));
  }

  void test_eq_3 () {
    Matrix<int> x(1, 2, 3);
    Matrix<int> y(2, 1, 3);
    CPPUNIT_ASSERT(!x.eq(y));
    CPPUNIT_ASSERT(!y.eq(x));
  }


    // -------------
    // test_iterator
    // -------------

    void test_iterator () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

  void test_iterator_1 () {
   Matrix<int> x (2, 3);
    Matrix<int>::iterator b = x.begin();
    Matrix<int>::iterator e = x.end();
    int count = 0;
    while (b != e) {
      ++count;
      ++b;
    }
    CPPUNIT_ASSERT(count == 2);
  }

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);
    }

  // ----
  // size
  // ----

  void test_size_1 () {
    Matrix<int> x;
    CPPUNIT_ASSERT(x.size() == 0);
  }

  void test_size_2 () {
    Matrix<int> x(5, 5, 1);
    CPPUNIT_ASSERT(x.size() == 5);
  }

  void test_size_3 () {
    Matrix<int> x(0, 2);
    CPPUNIT_ASSERT(x.size() == 0);
  }

  // ----
  // rows
  // ----

  void test_rows_1 () {
    Matrix<int> x (1, 2);
    CPPUNIT_ASSERT(x.rows() == 1);
  }

  void test_rows_2 () {
    Matrix<int> x (189, 2);
    CPPUNIT_ASSERT(x.rows() == 189);
  }

  void test_rows_3 () {
    Matrix<int> x (0, 2);
    CPPUNIT_ASSERT(x.rows() == 0);
  }

  // -------
  // columns
  // -------

  void test_columns_1 () {
    Matrix<int> x (1, 2);
    CPPUNIT_ASSERT(x.columns() == 2);
  }

  void test_columns_2 () {
    Matrix<int>x (0, 2);
    CPPUNIT_ASSERT(x.columns() == 2);
  }

  void test_columns_3 () {
    Matrix<int>x (1, 0);
    CPPUNIT_ASSERT(x.columns() == 0);
  }

    // -----
    // suite
    // -----

  CPPUNIT_TEST_SUITE(TestMatrix);
  CPPUNIT_TEST(test_constructor);
  CPPUNIT_TEST(test_constructor_1);
  CPPUNIT_TEST(test_constructor_2);
  CPPUNIT_TEST(test_constructor_3);
  CPPUNIT_TEST(test_constructor_4);
  CPPUNIT_TEST(test_constructor_5);
  CPPUNIT_TEST(test_index);
  CPPUNIT_TEST(test_index_1);
  CPPUNIT_TEST(test_index_2);
  CPPUNIT_TEST(test_index_3);
  CPPUNIT_TEST(test_equals);
  CPPUNIT_TEST(test_equals_1);
  CPPUNIT_TEST(test_equals_2);
  CPPUNIT_TEST(test_equals_3);
  CPPUNIT_TEST(test_equals_4);
  CPPUNIT_TEST(test_not_equals_1);
  CPPUNIT_TEST(test_not_equals_2);
  CPPUNIT_TEST(test_not_equals_3);
  CPPUNIT_TEST(test_not_equals_4);
  CPPUNIT_TEST(test_less_than);
  CPPUNIT_TEST(test_less_than_1);
  CPPUNIT_TEST(test_less_than_2);
  CPPUNIT_TEST(test_less_than_3);
  CPPUNIT_TEST(test_less_than_4);
  CPPUNIT_TEST(test_less_than_equals_1);
  CPPUNIT_TEST(test_less_than_equals_2);
  CPPUNIT_TEST(test_less_than_equals_3);
  CPPUNIT_TEST(test_less_than_equals_4);
  CPPUNIT_TEST(test_greater_than_1);
  CPPUNIT_TEST(test_greater_than_2);
  CPPUNIT_TEST(test_greater_than_3);
  CPPUNIT_TEST(test_greater_than_4);
  CPPUNIT_TEST(test_greater_than_equals_1);
  CPPUNIT_TEST(test_greater_than_equals_2);
  CPPUNIT_TEST(test_greater_than_equals_3);
  CPPUNIT_TEST(test_greater_than_equals_4);
  CPPUNIT_TEST(test_plus_equals);
  CPPUNIT_TEST(test_plus_equals_1);
  CPPUNIT_TEST(test_plus_equals_2);
  CPPUNIT_TEST(test_plus_equals_3);
  CPPUNIT_TEST(test_plus_equals_4);
  CPPUNIT_TEST(test_plus_equals_5);  
  CPPUNIT_TEST(test_plus_1);
  CPPUNIT_TEST(test_plus_2);
  CPPUNIT_TEST(test_plus_3);
  CPPUNIT_TEST(test_minus_equals);
  CPPUNIT_TEST(test_minus_equals_1);
  CPPUNIT_TEST(test_minus_equals_2);
  CPPUNIT_TEST(test_minus_equals_3);
  CPPUNIT_TEST(test_minus_equals_4);
  CPPUNIT_TEST(test_minus_equals_5);
  CPPUNIT_TEST(test_multiplies);
  CPPUNIT_TEST(test_multiplies_MI_1);
  CPPUNIT_TEST(test_multiplies_MI_2);
  CPPUNIT_TEST(test_multiplies_MI_3);
  CPPUNIT_TEST(test_multiplies_MM_1);
  CPPUNIT_TEST(test_multiplies_MM_2);
  CPPUNIT_TEST(test_multiplies_MM_3);
  CPPUNIT_TEST(test_mult_equals_4);
  CPPUNIT_TEST(test_mult_equals_5);
  CPPUNIT_TEST(test_eq_1);
  CPPUNIT_TEST(test_eq_2);
  CPPUNIT_TEST(test_eq_3);
  CPPUNIT_TEST(test_iterator);
  CPPUNIT_TEST(test_iterator_1);
  CPPUNIT_TEST(test_const_iterator);
  CPPUNIT_TEST(test_size_1);
  CPPUNIT_TEST(test_size_2);
  CPPUNIT_TEST(test_size_3);
  CPPUNIT_TEST(test_rows_1);
  CPPUNIT_TEST(test_rows_2);
  CPPUNIT_TEST(test_rows_3);
  CPPUNIT_TEST(test_columns_1);
  CPPUNIT_TEST(test_columns_2);
  CPPUNIT_TEST(test_columns_3);
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
    tr.run();

    cout << "Done." << endl;
    return 0;}
