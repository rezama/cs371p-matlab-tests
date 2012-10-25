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

#define private public
#include "Matrix.h"

// ----------
// TestMatrix
// ----------

struct TestMatrix : CppUnit::TestFixture {
    
    // ----------
    // test_valid
    // ----------

    void test_valid_zero () {
      Matrix<int> x;
      CPPUNIT_ASSERT(x.valid());
      std::vector<int> row;
      row.push_back(1);
      x._m.push_back(row);
      CPPUNIT_ASSERT(!x.valid());
    }
    void test_valid_columns () {
      Matrix<int> x(69, 69, 69);
      CPPUNIT_ASSERT(x.valid());
      x._columns = 68;
      CPPUNIT_ASSERT(!x.valid());
      for (size_t i = 0; i < 69; i++) {
        x._m.at(i).pop_back();
      }
      CPPUNIT_ASSERT(x.valid());
    }
    void test_valid_rows () {
      Matrix<int> x(69, 69, 69);
      CPPUNIT_ASSERT(x.valid());
      x._rows = 68;
      CPPUNIT_ASSERT(!x.valid());
      x._m.pop_back();
      CPPUNIT_ASSERT(x.valid());
    }
    void test_valid_unequal_columns () {
      Matrix<int> x(3, 3, 1);
      x._m.at(2).push_back(1);
      CPPUNIT_ASSERT(!x.valid());
    }
  
    // ----------------
    // test_constructor
    // ----------------

    void test_constructor () {
      Matrix<int> x;
      Matrix<int> y(2);
      Matrix<int> z(2, 3);
      Matrix<int> t(2, 3, 4);
      CPPUNIT_ASSERT(x.size() == 0);}

    void test_constructor_2 () {
      Matrix<int> x(2, 0);
      CPPUNIT_ASSERT(x.size() == 2);
      CPPUNIT_ASSERT(x[0].size() == 0);
      CPPUNIT_ASSERT(x[1].size() == 0);
    }

    void test_constructor_3 () {
      Matrix<double> pi(2, 3, 3.14);
      CPPUNIT_ASSERT(pi.size() == 2);
      for (int i = 0; i < 2; i++) {
        CPPUNIT_ASSERT(pi[i].size() == 3);         
        for (int j = 0; j < 3; j++) {
          CPPUNIT_ASSERT(pi[i][j] == 3.14);
        }
      }
    }

    // ----------
    // test_index
    // ----------

    void test_index_square () {
        const Matrix<int> x(2, 2);
        CPPUNIT_ASSERT(x[0][0] == 0);
        CPPUNIT_ASSERT(x[0][1] == 0);
        CPPUNIT_ASSERT(x[1][0] == 0);
        CPPUNIT_ASSERT(x[1][1] == 0);
    }
    void test_index_fat_rectangle () {
      Matrix<double> pi(2, 3, 3.14);
      CPPUNIT_ASSERT(pi.size() == 2);
      for (int i = 0; i < 2; i++) {
        CPPUNIT_ASSERT(pi[i].size() == 3);         
        for (int j = 0; j < 3; j++) {
          CPPUNIT_ASSERT(pi[i][j] == 3.14);
        }
      }
    }
    void test_index_tall_rectangle () {
      Matrix<double> pi(5, 1, 3.14);
      CPPUNIT_ASSERT(pi.size() == 5);
      CPPUNIT_ASSERT(pi[0].size() == 1);
      for (int i = 0; i < 5; i++) {
        CPPUNIT_ASSERT(pi[i][0] == 3.14);
      }
    }

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
    // --------------
    // test_less_than
    // --------------

    void test_less_than () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_less_than_1 () {
      Matrix<int>  x(2, 2, 4);
      Matrix<int>  y(2, 2, 5);
      Matrix<bool> t(2, 2, true);  // matrix of truthiness
      Matrix<bool> z;
      z = (x < y);
      CPPUNIT_ASSERT(z.eq(t)); // z should be a matrix of truthiness as well
    }

    void test_less_than_2 () {
      Matrix<int>  x(2, 2, 5);
      Matrix<int>  y(2, 2, 5);
      Matrix<bool> f(2, 2, false);  // matrix of untruthitude
      Matrix<bool> z;
      z = (x < y);
      CPPUNIT_ASSERT(z.eq(f)); // z should be a matrix of untruthitude as well
    }

    void test_less_than_3 () {
      Matrix<int>  x(1, 2, 5);
      Matrix<int>  y(2, 1, 5);
      Matrix<bool> z;

      try {
        z = (x == y);
      }
      catch (DimensionException& e) {
        CPPUNIT_ASSERT(true);
      }
    } 

    // -----------------
    // test_less_eq_than
    // -----------------

    void test_less_eq_than () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    // TODO: implement [] so we can customize a matrix to better test these
    void test_less_than_or_equal_1 () {
      Matrix<int>  x(2, 2, 4);
      Matrix<int>  y(2, 2, 5);
      Matrix<bool> t(2, 2, true);  // matrix of truthiness
      Matrix<bool> z;
      z = (x <= y);
      CPPUNIT_ASSERT(z.eq(t)); // z should be a matrix of truthiness as well
    }

    void test_less_than_or_equal_2 () {
      Matrix<int>  x(2, 2, 5);
      Matrix<int>  y(2, 2, 5);
      Matrix<bool> t(2, 2, true);  // matrix of truthiness
      Matrix<bool> z;
      z = (x <= y);
      CPPUNIT_ASSERT(z.eq(t)); // z should be a matrix of truthiness as well
    }

    void test_less_than_or_equal_3 () {
      Matrix<int>  x(2, 2, 6);
      Matrix<int>  y(2, 2, 5);
      Matrix<bool> f(2, 2, false);  // matrix of untruthitude
      Matrix<bool> z;
      z = (x <= y);
      CPPUNIT_ASSERT(z.eq(f)); // z should be a matrix of untruthitude as well
    }

    void test_less_than_or_equal_4 () {
      Matrix<int>  x(1, 2, 6);
      Matrix<int>  y(2, 1, 5);
      Matrix<bool> z;
      try {
        z = (x <= y);
      }
      catch (DimensionException& e) {
        CPPUNIT_ASSERT(true);
      }
    }

    // -----------------
    // test_greater_than
    // -----------------

    void test_greater_than () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_greater_than_1 () {
      Matrix<int>  x(2, 2, 6);
      Matrix<int>  y(2, 2, 5);
      Matrix<bool> t(2, 2, true);  // matrix of truthiness
      Matrix<bool> z;
      z = (x > y);
      CPPUNIT_ASSERT(z.eq(t)); // z should be a matrix of truthiness as well
    }

    void test_greater_than_2 () {
      Matrix<int>  x(2, 2, 5);
      Matrix<int>  y(2, 2, 5);
      Matrix<bool> f(2, 2, false);  // matrix of untruthitude
      Matrix<bool> z;
      z = (x > y);
      CPPUNIT_ASSERT(z.eq(f)); // z should be a matrix of untruthitude as well
    }

    void test_greater_than_3 () {
      Matrix<int>  x(1, 2, 6);
      Matrix<int>  y(2, 1, 5);
      Matrix<bool> z;
      try {
        z = (x <= y);
      }
      catch (DimensionException& e) {
        CPPUNIT_ASSERT(true);
      }
    }

    // --------------------
    // test_greater_eq_than
    // --------------------

    void test_greater_eq_than () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_greater_than_or_equal_1 () {
      Matrix<int>  x(2, 2, 5);
      Matrix<int>  y(2, 2, 4);
      Matrix<bool> t(2, 2, true);  // matrix of truthiness
      Matrix<bool> z;
      z = (x >= y);
      CPPUNIT_ASSERT(z.eq(t)); // z should be a matrix of truthiness as well
    }

    void test_greater_than_or_equal_2 () {
      Matrix<int>  x(2, 2, 5);
      Matrix<int>  y(2, 2, 5);
      Matrix<bool> t(2, 2, true);  // matrix of truthiness
      Matrix<bool> z;
      z = (x >= y);
      CPPUNIT_ASSERT(z.eq(t)); // z should be a matrix of truthiness as well
    }

    void test_greater_than_or_equal_3 () {
      Matrix<int>  x(2, 2, 4);
      Matrix<int>  y(2, 2, 5);
      Matrix<bool> f(2, 2, false);  // matrix of untruthitude
      Matrix<bool> z;
      z = (x >= y);
      CPPUNIT_ASSERT(z.eq(f)); // z should be a matrix of untruthitude as well
    }

    void test_greater_than_or_equal_4 () {
      Matrix<int>  x(1, 2, 6);
      Matrix<int>  y(2, 1, 5);
      Matrix<bool> z;
      try {
        z = (x <= y);
      }
      catch (DimensionException& e) {
        CPPUNIT_ASSERT(true);
      }
    }


    // ---------
    // test_plus
    // ---------

    void test_plus_T1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_plus_T2 () {
        Matrix<int> x(2, 3, 0);
        Matrix<int> y(2, 3, 2);
        int two = 2;
        CPPUNIT_ASSERT(!x.eq(y));
        x += two;
        CPPUNIT_ASSERT(x.eq(y));
    }
    void test_plus_T3 () {
        Matrix<int> x(69, 96, 27);
        Matrix<int> y(69, 96, 96);
        int n = 69;
        CPPUNIT_ASSERT(!x.eq(y));
        x += n;
        CPPUNIT_ASSERT(x.eq(y));
    }
    void test_plus_eq_fat () {
        Matrix<int> x(2, 8, 0);
        Matrix<int> y(2, 8, 2);
        Matrix<int> z(2, 8, 2);
        CPPUNIT_ASSERT(!x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
    }
    void test_plus_eq_tall () {
        Matrix<int> x(69, 8, 0);
        Matrix<int> y(69, 8, 88);
        Matrix<int> z(69, 8, 88);
        CPPUNIT_ASSERT(!x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
    }
    void test_plus_eq_fail () {
        Matrix<int> x(2, 3, 0);
        Matrix<int> y(1, 3, 2);
        CPPUNIT_ASSERT(!x.eq(y));
        try {
          x += y;
        } catch (DimensionException &e) { CPPUNIT_ASSERT(true); }
    }

    // ----------
    // test_minus
    // ----------

    void test_minus_T1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}
 
    void test_minus_T2 () {
        Matrix<int> x(2, 3, 0);
        Matrix<int> y(2, 3, 2);
        int two = 2;
        CPPUNIT_ASSERT(!x.eq(y));
        y -= two;
        CPPUNIT_ASSERT(x.eq(y));
    }
    void test_minus_T3 () {
        Matrix<int> x(69, 96, 27);
        Matrix<int> y(69, 96, 96);
        int n = 69;
        CPPUNIT_ASSERT(!x.eq(y));
        y -= n;
        CPPUNIT_ASSERT(x.eq(y));
    }
    void test_minus_eq_fat () {
        Matrix<int> x(2, 8, 0);
        Matrix<int> y(2, 8, 2);
        Matrix<int> z(2, 8, 2);
        CPPUNIT_ASSERT(!x.eq(z));
        z -= y;
        CPPUNIT_ASSERT(x.eq(z));
    }
    void test_minus_eq_tall () {
        Matrix<int> x(69, 8, 69);
        Matrix<int> y(69, 8, 70);
        Matrix<int> z(69, 8, -1);
        CPPUNIT_ASSERT(!x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
    }
    void test_minus_eq_fail () {
        Matrix<int> x(2, 3, 0);
        Matrix<int> y(3, 2, 2);
        CPPUNIT_ASSERT(!x.eq(y));
        try {
          x -= y;
          CPPUNIT_ASSERT(false);
        } catch (DimensionException &e) { CPPUNIT_ASSERT(true); }
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

    void test_multiplies_T_fat () {
        Matrix<int> x(2, 1, 1);
        Matrix<int> y(2, 1, 2);
        x *= 2;
        CPPUNIT_ASSERT(x.eq(y));
    }
    void test_multiplies_T_tall () {
        Matrix<int> x(1, 3, 1);
        Matrix<int> y(1, 3, 8);
        x *= 8;
        CPPUNIT_ASSERT(x.eq(y));
    }
    void test_mult_eq1 () {
        Matrix<int> x(4, 1, 1);
        Matrix<int> y(1, 3, 8);
        Matrix<int> z(4, 3, 8);
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }
    void test_mult_eq2 () {
        Matrix<int> x(3, 2, 1);
        Matrix<int> y(2, 3, 8);
        Matrix<int> z(3, 3, 16);
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }
    void test_mult_eq3 () {
        Matrix<int> x(4, 3, 1);
        Matrix<int> y(3, 4, 8);
        Matrix<int> z(4, 4, 24);
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }
    void test_mult_eq_fail () {
        Matrix<int> x(1, 3, 1);
        Matrix<int> y(1, 3, 8);
        try {
          x *= y;
          CPPUNIT_ASSERT(false);
        } catch (DimensionException& e) { CPPUNIT_ASSERT(true); }
    }

    // -------------
    // test_iterator
    // -------------

    void test_iterator () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}


    /*
    * OUR TESTS
    */

    void test_rows_1 () {
      Matrix<int>  x(2, 2, 5);
      Matrix<int>  y(2, 2, 5);
      CPPUNIT_ASSERT(x.rows() == y.rows());
    }

    void test_rows_2 () {
      Matrix<int>  x(2, 2, 5);
      Matrix<int>  y(1, 2, 5);
      CPPUNIT_ASSERT(x.rows() != y.rows());
    }

    void test_rows_3 () {
      Matrix<int>  x;
      Matrix<int>  y;
      CPPUNIT_ASSERT(x.rows() == 0 && y.rows() == 0);
    }

    void test_columns_1 () {
      Matrix<int>  x(2, 2, 5);
      Matrix<int>  y(2, 2, 5);
      CPPUNIT_ASSERT(x.columns() == y.columns());
    }

    void test_columns_2 () {
      Matrix<int>  x(2, 1, 5);
      Matrix<int>  y(2, 2, 5);
      CPPUNIT_ASSERT(x.columns() != y.columns());
    }

    void test_columns_3 () {
      Matrix<int>  x(2, 2, 5);
      Matrix<int>  y(2, 2, 5);
      CPPUNIT_ASSERT(x.columns() == 2 && y.columns() == 2);
    }

    void test_dbl_equal_1 () {
      Matrix<int>  x(2, 2, 5);
      Matrix<int>  y(2, 2, 5);
      Matrix<bool> z;
      z = (x == y);
      CPPUNIT_ASSERT(x.eq(y)); // cant assert on ==, only .eq
    }

    void test_dbl_equal_2 () {
      Matrix<int>  x(2, 2, 4);
      Matrix<int>  y(2, 2, 5);
      Matrix<bool> f(2, 2, false);  // matrix of untruthitude
      Matrix<bool> z;
      z = (x == y);
      CPPUNIT_ASSERT(z.eq(f)); // z should be a matrix of untruthitude as well
    }

    void test_dbl_equal_3 () {
      Matrix<int>  x(2, 2, 5);
      Matrix<int>  y(1, 1, 5);
      Matrix<bool> z;
      try {
        z = (x == y);
      }
      catch (DimensionException& e) {
        CPPUNIT_ASSERT(true);
      }
    }

    void test_not_equal_1 () {
      Matrix<int>  x(2, 2, 4);
      Matrix<int>  y(2, 2, 5);
      Matrix<bool> t(2, 2, true);  // matrix of truthiness
      Matrix<bool> z;
      z = (x != y);
      CPPUNIT_ASSERT(z.eq(t)); // z should be a matrix of truthiness as well
    }

    void test_not_equal_2 () {
      Matrix<int>  x(2, 2, 5);
      Matrix<int>  y(2, 2, 5);
      Matrix<bool> f(2, 2, false);  // matrix of untruthitude
      Matrix<bool> z;
      z = (x != y);
      CPPUNIT_ASSERT(z.eq(f)); // z should be a matrix of untruthitude as well
    }

    void test_not_equal_3 () {
      Matrix<int>  x(1, 2, 5);
      Matrix<int>  y(2, 1, 5);
      Matrix<bool> z;

      try {
        z = (x != y);
      }
      catch (DimensionException& e) {
        CPPUNIT_ASSERT(true);
      }
    }


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_valid_zero);
    CPPUNIT_TEST(test_valid_columns);
    CPPUNIT_TEST(test_valid_rows);
    CPPUNIT_TEST(test_valid_unequal_columns);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_index_square);
    CPPUNIT_TEST(test_index_tall_rectangle);
    CPPUNIT_TEST(test_index_fat_rectangle);
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less_eq_than);
    CPPUNIT_TEST(test_greater_than);
    CPPUNIT_TEST(test_greater_eq_than);
    CPPUNIT_TEST(test_plus_T1);
    CPPUNIT_TEST(test_plus_T2);
    CPPUNIT_TEST(test_plus_T3);
    CPPUNIT_TEST(test_plus_eq_tall);
    CPPUNIT_TEST(test_plus_eq_fat);
    CPPUNIT_TEST(test_plus_eq_fail);
    CPPUNIT_TEST(test_minus_T1);
    CPPUNIT_TEST(test_minus_T2);
    CPPUNIT_TEST(test_minus_T3);
    CPPUNIT_TEST(test_minus_eq_tall);
    CPPUNIT_TEST(test_minus_eq_fat);
    CPPUNIT_TEST(test_minus_eq_fail);
    CPPUNIT_TEST(test_multiplies);
    CPPUNIT_TEST(test_multiplies_T_fat);
    CPPUNIT_TEST(test_multiplies_T_tall);
    CPPUNIT_TEST(test_mult_eq1);
    CPPUNIT_TEST(test_mult_eq2);
    CPPUNIT_TEST(test_mult_eq3);
    CPPUNIT_TEST(test_mult_eq_fail);
    CPPUNIT_TEST(test_iterator);
    CPPUNIT_TEST(test_const_iterator);

    CPPUNIT_TEST(test_dbl_equal_1);
    CPPUNIT_TEST(test_dbl_equal_2);
    CPPUNIT_TEST(test_dbl_equal_3);
    CPPUNIT_TEST(test_rows_1);
    CPPUNIT_TEST(test_rows_2);
    CPPUNIT_TEST(test_rows_3);
    CPPUNIT_TEST(test_columns_1);
    CPPUNIT_TEST(test_columns_2);
    CPPUNIT_TEST(test_columns_3);
    CPPUNIT_TEST(test_not_equal_1);
    CPPUNIT_TEST(test_not_equal_2);
    CPPUNIT_TEST(test_not_equal_3);
    CPPUNIT_TEST(test_less_than_1);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
    CPPUNIT_TEST(test_less_than_or_equal_1);
    CPPUNIT_TEST(test_less_than_or_equal_2);
    CPPUNIT_TEST(test_less_than_or_equal_3);
    CPPUNIT_TEST(test_less_than_or_equal_4);
    CPPUNIT_TEST(test_greater_than_1);
    CPPUNIT_TEST(test_greater_than_2);
    CPPUNIT_TEST(test_greater_than_3);
    CPPUNIT_TEST(test_greater_than_or_equal_1);
    CPPUNIT_TEST(test_greater_than_or_equal_2);
    CPPUNIT_TEST(test_greater_than_or_equal_3);
    CPPUNIT_TEST(test_greater_than_or_equal_4);

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
