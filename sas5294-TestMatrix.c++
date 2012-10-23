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

struct TestMatrix : CppUnit::TestFixture 
{
  // ----------------
  // test_constructor
  // ----------------

  void test_constructor ()
  {
    Matrix<int> x;
    CPPUNIT_ASSERT(x.size() == 0);
  }

  void test_constructor_two ()
  {
    Matrix<int> y(2);
    CPPUNIT_ASSERT(y.size() == 2);
  }

  void test_constructor_three ()
  {
    Matrix<int> z(2, 3);
    Matrix<int> t(2, 3, 4);
    CPPUNIT_ASSERT(z.size() == t.size());
  }

  // ----------
  // test_index
  // ----------

  void test_index ()
  {
    const Matrix<int> x(1, 1, 0);
    CPPUNIT_ASSERT(x[0][0] == 0);
  }

  void test_index_two ()
  {
    const Matrix<int> x(2, 2, 0);
    for (int r = 0; r < (int) x.size(); r++)
      for (int c = 0; c < (int) x[r].size(); c++)
        CPPUNIT_ASSERT(x[r][c] == 0);
  }

  void test_index_three ()
  {
    const Matrix<int> x(4, 3, 1);
    for (int r = 0; r < (int) x.size(); r++)
      for (int c = 0; c < (int) x[r].size(); c++)
        CPPUNIT_ASSERT(x[r][c] == 1);
  }

  // -----------
  // test_equals
  // -----------

  void test_equals ()
  {
    Matrix<int>  x;
    Matrix<int>  y;
    Matrix<bool> z;
    Matrix<bool> t;
    z = (x == y);
    CPPUNIT_ASSERT(z.eq(t));
  }

  void test_equals_two ()
  {
    Matrix<int>  x(2, 2, 0);
    Matrix<int>  y(2, 2, 0);
    Matrix<bool> z;
    Matrix<bool> t(2, 2, true);
    z = (x == y);
    CPPUNIT_ASSERT(z.eq(t));
  }

  void test_equals_three ()
  {
    Matrix<int>  x(2, 2, 0);
    Matrix<int>  y(2, 2, 3);
    Matrix<bool> z;
    Matrix<bool> t(2, 2, false);
    z = (x == y);
    CPPUNIT_ASSERT(z.eq(t));
  }

  // --------------
  // test_less_than
  // --------------

  void test_less_than ()
  {
    Matrix<int>  x;
    Matrix<int>  y;
    Matrix<bool> z;
    Matrix<bool> t;
    z = (x < y);
    CPPUNIT_ASSERT(z.eq(t));
  }

  void test_less_than_two ()
  {
    Matrix<int>  x(2, 2, 0);
    Matrix<int>  y(2, 2, 1);
    Matrix<bool> z;
    Matrix<bool> t(2, 2, true);
    z = (x < y);
    CPPUNIT_ASSERT(z.eq(t));
  }

  void test_less_than_three ()
  {
    Matrix<int>  x(2, 2, 5);
    Matrix<int>  y(2, 2, 3);
    Matrix<bool> z;
    Matrix<bool> t(2, 2, false);
    z = (x < y);
    CPPUNIT_ASSERT(z.eq(t));
  }

  // ---------
  // test_plus
  // ---------

  void test_plus ()
  {
    Matrix<int> x;
    Matrix<int> y;
    Matrix<int> z;
    x += 0;
    CPPUNIT_ASSERT(x.eq(z));
    x += y;
    CPPUNIT_ASSERT(x.eq(z));
  }

  void test_plus_two ()
  {
    Matrix<int> x(1, 1, 1);
    Matrix<int> y(1, 1, 0);
    Matrix<int> z(1, 1, 2);
    x += 1;
    CPPUNIT_ASSERT(x.eq(z));
    x += y;
    CPPUNIT_ASSERT(x.eq(z));
  }

  void test_plus_three ()
  {
    Matrix<int> x(1, 1, 1);
    Matrix<int> y(1, 1, 3);
    Matrix<int> z(1, 1, 4);
    Matrix<int> zz(1, 1, 7);
    x += 3;
    CPPUNIT_ASSERT(x.eq(z));
    x += y;
    CPPUNIT_ASSERT(x.eq(zz));
  }

  // ----------
  // test_minus
  // ----------

  void test_minus ()
  {
    Matrix<int> x;
    Matrix<int> y;
    Matrix<int> z;
    x -= 0;
    CPPUNIT_ASSERT(x.eq(z));
    x -= y;
    CPPUNIT_ASSERT(x.eq(z));
  }

  void test_minus_two ()
  {
    Matrix<int> x(1, 1, 1);
    Matrix<int> y(1, 1, 0);
    Matrix<int> z(1, 1, 0);
    x -= 1;
    CPPUNIT_ASSERT(x.eq(z));
    x -= y;
    CPPUNIT_ASSERT(x.eq(z));
  }

  void test_minus_three ()
  {
    Matrix<int> x(1, 1, 1);
    Matrix<int> y(1, 1, -3);
    Matrix<int> z(1, 1, -2);
    Matrix<int> zz(1, 1, 1);
    x -= 3;
    CPPUNIT_ASSERT(x.eq(z));
    x -= y;
    CPPUNIT_ASSERT(x.eq(zz));
  }

  // ---------------
  // test_multiplies
  // ---------------

  void test_multiplies ()
  {
    Matrix<int> x;
    Matrix<int> y;
    Matrix<int> z;
    x *= 0;
    CPPUNIT_ASSERT(x.eq(z));
    x *= y;
    CPPUNIT_ASSERT(x.eq(z));
  }

  void test_multiplies_two ()
  {
    Matrix<int> x(2, 2, 1);
    Matrix<int> y(2, 2, 1);
    Matrix<int> z(2, 2, 0);
    x *= 0;
    CPPUNIT_ASSERT(x.eq(z));
    x *= y;
    CPPUNIT_ASSERT(x.eq(z));
  }

  void test_multiplies_three ()
  {
    Matrix<int> x(2, 1, 1);
    Matrix<int> y(1, 2, 1);
    Matrix<int> z(2, 1, 3);
    Matrix<int> zz(2, 2, 3);
    x *= 3;
    CPPUNIT_ASSERT(x.eq(z));
    x *= y;
    CPPUNIT_ASSERT(x.eq(zz));
  }

  // -------------
  // test_iterator
  // -------------

  void test_iterator ()
  {
    Matrix<int> x;
    Matrix<int>::iterator b = x.begin();
    Matrix<int>::iterator e = x.end();
    CPPUNIT_ASSERT(b == e);
  }

  void test_iterator_two ()
  {
    Matrix<int> x(1, 1, 1);
    Matrix<int>::iterator b = x.begin();
    Matrix<int>::iterator e = x.end();
    CPPUNIT_ASSERT(b != e);
  }

  void test_iterator_three ()
  {
    Matrix<int> x(2, 1, 0);
    Matrix<int> y(2, 1, 0);
    Matrix<int>::iterator b = x.begin();
    Matrix<int>::iterator b2 = y.begin();    
    Matrix<int>::iterator e = x.end();
    Matrix<int>::iterator e2 = y.end();
    CPPUNIT_ASSERT(b != b2);
    CPPUNIT_ASSERT(e != e2);
  }

  // -------------------
  // test_const_iterator
  // -------------------

  void test_const_iterator ()
  {
    const Matrix<int> x;
    Matrix<int>::const_iterator b = x.begin();
    Matrix<int>::const_iterator e = x.end();
    CPPUNIT_ASSERT(b == e);
  }

  void test_const_iterator_two ()
  {
    const Matrix<int> x(1, 1, 1);
    Matrix<int>::const_iterator b = x.begin();
    Matrix<int>::const_iterator e = x.end();
    CPPUNIT_ASSERT(b != e);
  }

  void test_const_iterator_three ()
  {
    const Matrix<int> x(2, 1, 0);
    const Matrix<int> y(2, 1, 0);
    Matrix<int>::const_iterator b = x.begin();
    Matrix<int>::const_iterator b2 = y.begin();
    Matrix<int>::const_iterator e = x.end();
    Matrix<int>::const_iterator e2 = y.end();
    CPPUNIT_ASSERT(b != b2);
    CPPUNIT_ASSERT(e != e2);
  }

  // -----
  // suite
  // -----

  CPPUNIT_TEST_SUITE(TestMatrix);
  CPPUNIT_TEST(test_constructor);
  CPPUNIT_TEST(test_constructor_two);
  CPPUNIT_TEST(test_constructor_three);
  CPPUNIT_TEST(test_index);
  CPPUNIT_TEST(test_index_two);
  CPPUNIT_TEST(test_index_three);
  CPPUNIT_TEST(test_equals);
  CPPUNIT_TEST(test_equals_two);
  CPPUNIT_TEST(test_equals_three);
  CPPUNIT_TEST(test_less_than);
  CPPUNIT_TEST(test_less_than_two);
  CPPUNIT_TEST(test_less_than_three);
  CPPUNIT_TEST(test_plus);
  CPPUNIT_TEST(test_plus_two);
  CPPUNIT_TEST(test_plus_three);
  CPPUNIT_TEST(test_minus);
  CPPUNIT_TEST(test_minus_two);
  CPPUNIT_TEST(test_minus_three);
  CPPUNIT_TEST(test_multiplies);
  CPPUNIT_TEST(test_multiplies_two);
  CPPUNIT_TEST(test_multiplies_three);
  CPPUNIT_TEST(test_iterator);
  CPPUNIT_TEST(test_iterator_two);
  CPPUNIT_TEST(test_iterator_three);
  CPPUNIT_TEST(test_const_iterator);
  CPPUNIT_TEST(test_const_iterator_two);
  CPPUNIT_TEST(test_const_iterator_three);
  CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main () 
{
  using namespace std;
  ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
  cout << "TestMatrix.c++" << endl;

  CppUnit::TextTestRunner tr;
  tr.addTest(TestMatrix::suite());
  tr.run();

  cout << "Done." << endl;
  return 0;
}
