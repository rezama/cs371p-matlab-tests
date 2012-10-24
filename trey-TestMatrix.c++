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
        CPPUNIT_ASSERT(x.size() == 0);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(z.size() == 2);
        CPPUNIT_ASSERT(t.size() == 2);}
    
    void test_constructor_2 () {
        Matrix<int> x(0, 0);
        CPPUNIT_ASSERT(x.size() == 0);
    }
    
    void test_constructor_3 () {
        Matrix<int> x(8, 10, 0);
        CPPUNIT_ASSERT(x.size() == 8);
        CPPUNIT_ASSERT((x[0]).size() == 10);
        CPPUNIT_ASSERT(x[0][0] == 0);
    }

    // ----------
    // test_index
    // ----------

    void test_index () {
        const Matrix<int> x(2, 3, 4);
        CPPUNIT_ASSERT(x[0][0] == 4);}
    
    void test_index_2 () {
        const Matrix<int> x(2,2);
        CPPUNIT_ASSERT(x[0][0] == 0);
        CPPUNIT_ASSERT(x[1][0] == 0);
        CPPUNIT_ASSERT(x[0][1] == 0);
        CPPUNIT_ASSERT(x[1][1] == 0);
    }
    
    void test_index_3 () { 
        const Matrix<int> x(2,2,4);
        CPPUNIT_ASSERT(x[0][0] == 4);
        CPPUNIT_ASSERT(x[1][0] == 4);
        CPPUNIT_ASSERT(x[0][1] == 4);
        CPPUNIT_ASSERT(x[1][1] == 4);
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
        CPPUNIT_ASSERT(z.eq(t));}

    void test_equals_2 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> y(2, 3, 4);
        Matrix<bool> z = (x == y);
        for (unsigned i = 0; i < 2; i++) {
          for (unsigned j = 0; j < 3; j++) {
            CPPUNIT_ASSERT(z[i][j]);
          }
        }
    }

    void test_equals_3 () {
      Matrix<int> x(2, 3, 3);
      Matrix<int> y(2, 3, 4);
      Matrix<bool> z = (x == y);
      for (unsigned i = 0; i < 2; i++) {
        for (unsigned j = 0; j < 3; j++) {
          CPPUNIT_ASSERT(!z[i][j]);
        }
      }
        CPPUNIT_ASSERT(!x.eq(y));
    }

    void test_equals_4 () {
      Matrix<int> x(2, 2, 3);
      Matrix<int> y(2, 3, 3);
      try {
        Matrix<bool> z = (x == y);
        CPPUNIT_ASSERT(false);
      }

      catch (...) {
        CPPUNIT_ASSERT(true);
      }
    }
    
    // -----------
    // test_not_equals
    // -----------
    
    void test_not_equals () {
        Matrix<int>  x(1,1,2);
        Matrix<int>  y(1,1,2);
        Matrix<bool> z;
        Matrix<bool> t(1,1,false);
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    void test_not_equals_2 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    void test_not_equals_3 () {
        Matrix<int>  x(2);
        Matrix<int>  y(2);
        Matrix<bool> z;
        Matrix<bool> t(2);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    
    // --------------
    // test_less_than
    // --------------

    void test_less_than () {
        Matrix<int>  x(2, 3, 4);
        Matrix<int>  y(2, 3, 3);
        Matrix<bool> z = (x < y);
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 3; j++) {
            CPPUNIT_ASSERT(!z[i][j]);
          }
        }
    }

    void test_less_than_2 () {
        Matrix<int> x(2, 3, 3);
        Matrix<int> y(2, 3, 4);
        Matrix<bool> z = (x < y);
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 3; j++) {
            CPPUNIT_ASSERT(z[i][j]);
          }
        }
    }

    void test_less_than_3 () {
      Matrix<int> x(2, 3);
      Matrix<int> y(2, 4);
      Matrix<bool> z;
      try {
        z = (x < y);
        CPPUNIT_ASSERT(false);
      }

      catch (...) {
        CPPUNIT_ASSERT(true);
      }
    }

    void test_less_than_4 () {
      Matrix<int> x(2, 3);
      Matrix<int> y(2, 3);
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
          if ( (i + j) == 2 ) {
            x[i][j] = 2;
            y[i][j] = 2;
          }

          else {
            x[i][j] = 4;
            y[i][j] = 5;
          }
        }
      }

      Matrix<bool> z = (x < y);
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
          if ( (i + j) == 2 ) 
            CPPUNIT_ASSERT(!z[i][j]); 
          else
            CPPUNIT_ASSERT(z[i][j]);
        }
      }
    }
    
    // -----------------------
    // test_less_than_or_equal
    // -----------------------
    
    void test_less_than_or_equal() {
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
        } catch (...) {
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
        } catch (...) {
            CPPUNIT_ASSERT(true);
        }
    }
    
    // -----------------
    // test_greater_than
    // -----------------
    
    void test_greater_than() {
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
        } catch (...) {
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
        } catch (...) {
            CPPUNIT_ASSERT(true);
        }
    }
    
    // --------------------------
    // test_greater_than_or_equal
    // --------------------------
    
    void test_greater_than_or_equal() {
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
        } catch (...) {
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
        } catch (...) {
            CPPUNIT_ASSERT(true);
        }
    }

    
    // ---------
    // test_plus
    // ---------

    void test_plus () {
        Matrix<int> x(2, 3, 4);
        x += 10;
        Matrix<int> y(2, 3, 14);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_plus_2 () {
        Matrix<int> x(3, 4, 10);
        Matrix<int> y(3, 4, 13);
        Matrix<int> z = x + y;
        Matrix<int> expected(3, 4, 23);
        CPPUNIT_ASSERT(z.eq(expected));}

     void test_plus_3 () {
        Matrix<int> x(3, 4, 5);
        Matrix<int> y(3, 3, 5);
        Matrix<int> z;
        try {
          z = x + y;
          CPPUNIT_ASSERT(false);
        }
        catch (...) {
          CPPUNIT_ASSERT(true);
        }
     }
    
    void test_plus_4 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> z = x + 2;
        x += 2;
        Matrix<int> expected(2, 3, 6);
        CPPUNIT_ASSERT(z.eq(expected) && x.eq(expected));} 
    
    void test_plus_5 () {
        Matrix<int> x(2, 10, 4);
        Matrix<int> y(3, 3, 5);
        try {
            Matrix<int> z = x + y;
            CPPUNIT_ASSERT(false);
        }
        
        catch (...) {
            CPPUNIT_ASSERT(true);
        }
    } 
    
    void test_plus_6 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> y(3, 3, 5);
        try {
            x +=  y;
            CPPUNIT_ASSERT(false);
        }
        
        catch (...) {
            CPPUNIT_ASSERT(true);
        }
    }
    
    void test_plus_7 () {
        Matrix<int> x(2, 10, 4);
        Matrix<int> y(3, 3, 5);
        try {
            x += y;
            CPPUNIT_ASSERT(false);
        }
        
        catch (...) {
            CPPUNIT_ASSERT(true);
        }
    }
    // ----------
    // test_minus
    // ----------

    void test_minus () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> y(2, 3, 1);
        Matrix<int> expected(2, 3, 3);
        Matrix<int> z = x - y;
        CPPUNIT_ASSERT(z.eq(expected));}

    void test_minus_1 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> y(2, 3, 3);
        Matrix<int> expected(2, 3, 1);
        Matrix<int> z = x - y;
        CPPUNIT_ASSERT(z.eq(expected));}

    void test_minus_2 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> z = x - 1;
        Matrix<int> expected(2, 3, 3);
        CPPUNIT_ASSERT(z.eq(expected));} 

    void test_minus_3 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> y(3, 3, 5);
        try {
          Matrix<int> z = x - y;
          CPPUNIT_ASSERT(false);
        }
    
        catch (...) {
          CPPUNIT_ASSERT(true);
        }
    }
    
    void test_minus_4 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> z = x - 2;
        x -= 2;
        Matrix<int> expected(2, 3, 2);
        CPPUNIT_ASSERT(z.eq(expected) && x.eq(expected));} 
    
    void test_minus_5 () {
        Matrix<int> x(2, 10, 4);
        Matrix<int> y(3, 3, 5);
        try {
            Matrix<int> z = x - y;
            CPPUNIT_ASSERT(false);
        }
        
        catch (...) {
            CPPUNIT_ASSERT(true);
        }
    } 
    
    void test_minus_6 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> y(3, 3, 5);
        try {
            x -=  y;
            CPPUNIT_ASSERT(false);
        }
        
        catch (...) {
            CPPUNIT_ASSERT(true);
        }
    }
    
    void test_minus_7 () {
        Matrix<int> x(2, 10, 4);
        Matrix<int> y(3, 3, 5);
        try {
            x -= y;
            CPPUNIT_ASSERT(false);
        }
        
        catch (...) {
            CPPUNIT_ASSERT(true);
        }
    }
            

    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> z(2, 3, 0);
        Matrix<int> y = x * 0;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z) && y.eq(z));}

    void test_multiplies_2 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> z(2, 3, 8);
        Matrix<int> y = x * 2;
        x *= 2;
        CPPUNIT_ASSERT(y.eq(z) && x.eq(z));}

    void test_multiplies_3 () {
        Matrix<int> x(2, 2, 4);
        Matrix<int> y(2, 2, 3);
        Matrix<int> z = x * y;
        x *= y;
        Matrix<int> expected(2, 2, 24);
        CPPUNIT_ASSERT(x.eq(expected));
        CPPUNIT_ASSERT(z.eq(expected));}

    void test_multiplies_4 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> y(4, 3, 4);
        Matrix<int> z;
        try {
          z = x * y;
          CPPUNIT_ASSERT(false);
        }
        catch(...) {
          CPPUNIT_ASSERT(true);
        }
    }

    void test_multiplies_5 () { 
        Matrix<int> x(2, 3, 4);
        Matrix<int> y(3, 1, 5);
        Matrix<int> z = x * y;
        x *= y;
        Matrix<int> expected(2, 1, 60);
        CPPUNIT_ASSERT(x.eq(expected));
        CPPUNIT_ASSERT(z.eq(expected));} 
    
    void test_multiplies_6 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> y(4, 3, 4);
        Matrix<int> z;
        try {
            x *= y;
            CPPUNIT_ASSERT(false);
        }
        catch(...) {
            CPPUNIT_ASSERT(true);
        }
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

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_index);
    CPPUNIT_TEST(test_index_2);
    CPPUNIT_TEST(test_index_3);
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_equals_2);
    CPPUNIT_TEST(test_equals_3);
    CPPUNIT_TEST(test_equals_4);
    CPPUNIT_TEST(test_not_equals);
    CPPUNIT_TEST(test_not_equals_2);
    CPPUNIT_TEST(test_not_equals_3);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
    CPPUNIT_TEST(test_less_than_4);
    CPPUNIT_TEST(test_less_than_or_equal);
    CPPUNIT_TEST(test_less_than_or_equal_2);
    CPPUNIT_TEST(test_less_than_or_equal_3);
    CPPUNIT_TEST(test_less_than_or_equal_4);
    CPPUNIT_TEST(test_greater_than);
    CPPUNIT_TEST(test_greater_than_2);
    CPPUNIT_TEST(test_greater_than_3);
    CPPUNIT_TEST(test_greater_than_4);
    CPPUNIT_TEST(test_greater_than_or_equal);
    CPPUNIT_TEST(test_greater_than_or_equal_2);
    CPPUNIT_TEST(test_greater_than_or_equal_3);
    CPPUNIT_TEST(test_greater_than_or_equal_4);
    CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(test_plus_2);
    CPPUNIT_TEST(test_plus_3);
    CPPUNIT_TEST(test_plus_4);
    CPPUNIT_TEST(test_plus_5);
    CPPUNIT_TEST(test_plus_6);
    CPPUNIT_TEST(test_plus_7);
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_minus_2);
    CPPUNIT_TEST(test_minus_3);
    CPPUNIT_TEST(test_minus_1);
    CPPUNIT_TEST(test_minus_4);
    CPPUNIT_TEST(test_minus_5);
    CPPUNIT_TEST(test_minus_6);
    CPPUNIT_TEST(test_minus_7);        
    CPPUNIT_TEST(test_multiplies);
    CPPUNIT_TEST(test_multiplies_2);
    CPPUNIT_TEST(test_multiplies_3);
    CPPUNIT_TEST(test_multiplies_4);
    CPPUNIT_TEST(test_multiplies_5);
    CPPUNIT_TEST(test_multiplies_6);
    CPPUNIT_TEST(test_iterator);
    CPPUNIT_TEST(test_const_iterator);
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
