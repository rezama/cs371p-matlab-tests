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
        CPPUNIT_ASSERT(x.get_cols() == 0);
    }
        
    void test_constructor2 () {
        Matrix<int> x;
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(y.get_cols() == 0);
    }
    
    void test_constructor3 () {
        Matrix<int> x;
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(z.size() == 2);
        CPPUNIT_ASSERT(z.get_cols() == 3);
        CPPUNIT_ASSERT(z[0][0] == 0);
    }
    
    void test_constructor4 () {
        Matrix<int> x;
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(t.size() == 2);
        CPPUNIT_ASSERT(t.get_cols() == 3);
        CPPUNIT_ASSERT(t[0][0] == 4);
    }

    // ----------
    // test_index
    // ----------

    void test_index () {
        const Matrix<int> x(1, 1);
        CPPUNIT_ASSERT(x[0][0] == 0);
    }
    
    void test_index2 () {
        const Matrix<int> x(1, 1, 1);
        CPPUNIT_ASSERT(x[0][0] == 1);
    }
    
    void test_index3 () {
        const Matrix<int> x(2, 2, 4);
        CPPUNIT_ASSERT(x[1][1] == 4);
    }
    
    void test_index4 () {
        const Matrix<int> x(100, 100, 100);
        CPPUNIT_ASSERT(x[99][98] == 100);
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
        CPPUNIT_ASSERT(t.eq(z));
    }
    
    void test_equals2 () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 1);
        Matrix<bool> z = (x == y);
        CPPUNIT_ASSERT(z.size() == 1);
        CPPUNIT_ASSERT(z.get_cols() == 1);
        CPPUNIT_ASSERT(z[0][0] == 1);
    }
    
    void test_equals3 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        t = (y == x);
        CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_equals4 () {
        Matrix<double>  x(5, 5, 2.5);
        Matrix<double>  y(5, 5, 2.5);
        Matrix<bool> z;
        Matrix<bool> t(5, 5, true);
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
    
    void test_less_than2 () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 2);
        Matrix<bool> z;
        z = (x < y);
        CPPUNIT_ASSERT(z.get_rows() == 1);
        CPPUNIT_ASSERT(z.get_cols() == 1);
        CPPUNIT_ASSERT(z[0][0] == true);
    }
    
    void test_less_than3 () {
        Matrix<int>  x(1, 1, 2);
        Matrix<int>  y(1, 1, 2);
        Matrix<bool> z;
        z = (x < y);
        CPPUNIT_ASSERT(z.get_rows() == 1);
        CPPUNIT_ASSERT(z.get_cols() == 1);
        CPPUNIT_ASSERT(z[0][0] == false);
    }
    
    void test_less_than4 () {
        Matrix<int>  x(2, 2, 2);
        Matrix<int>  y(2, 2, 1);
        Matrix<bool> z;
        z = (x < y);
        CPPUNIT_ASSERT(z.get_rows() == 2);
        CPPUNIT_ASSERT(z.get_cols() == 2);
        CPPUNIT_ASSERT(z[1][1] == false);
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
        CPPUNIT_ASSERT(x.eq(z));
     }
     
     void test_plus2 () {
        Matrix<int> x(1, 1, 0);
        Matrix<int> y(1, 1, 1);
        Matrix<int> z(1, 1, 0);
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        z += 1;
        CPPUNIT_ASSERT(x.eq(z));
     }
     
     void test_plus3 () {
        Matrix<double> x;
        Matrix<double> y;
        Matrix<double> z;
        x += 0.0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
     }
     
     void test_plus4 () {
        Matrix<double> x(2, 2, 3.0);
        Matrix<double> y(2, 2, 1.4);
        Matrix<double> z(2, 2, 3.0);
        x += 0.0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        z += 1.4;
        CPPUNIT_ASSERT(x.eq(z));
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
        CPPUNIT_ASSERT(x.eq(z));
     }
     
     void test_minus2 () {
        Matrix<int> x(1, 1, 0);
        Matrix<int> y(1, 1, 1);
        Matrix<int> z(1, 1, 0);
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        y -= y;
        CPPUNIT_ASSERT(y.eq(z));
     }
     
     void test_minus3 () {
        Matrix<double> x(1, 1, 0.0);
        Matrix<double> y(1, 1, 0.0);
        Matrix<double> z(1, 1, 0.0);
        x -= 0.0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
     }
     
     void test_minus4 () {
        Matrix<double> x(2, 2, 3.0);
        Matrix<double> y(2, 2, 1.4);
        Matrix<double> z(2, 2, 3.0);
        x -= 0.0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        z -= 1.4;
        CPPUNIT_ASSERT(x.eq(z));
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
        CPPUNIT_ASSERT(x.eq(z));
    }
    
    void test_multiplies2 () {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, 2);
        Matrix<int> z(1, 1, 1);
        x *= 1;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        z *= 2;
        CPPUNIT_ASSERT(x.eq(z));
    }
    
    void test_multiplies3 () {
        Matrix<double> x(3, 3, 1.5);
        Matrix<double> y(3, 3, 2);
        Matrix<double> z(3, 3, 9);
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }
    
    void test_multiplies4 () {
        Matrix<int> x(2, 2, 2);
        Matrix<int> y(2, 2, 2);
        Matrix<int> z(2, 2, 8);
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
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
        
    /// ---------------
    /// test_not_equals
    /// ---------------
    
    void test_not_equals () {
    		Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));
        CPPUNIT_ASSERT(t.eq(z));
    }
    
    void test_not_equals2 () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);
        Matrix<bool> z = (x != y);
        CPPUNIT_ASSERT(z.size() == 1);
        CPPUNIT_ASSERT(z.get_cols() == 1);
        CPPUNIT_ASSERT(z[0][0] == 1);
    }
    
    void test_not_equals3 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x != y);
        t = (y != x);
        CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_not_equals4 () {
        Matrix<double>  x(5, 5, 2.5);
        Matrix<double>  y(5, 5, 2.5);
        Matrix<bool> z;
        Matrix<bool> t(5, 5, false);
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));
    }
    
    
    /// -----------------
    /// test_greater_than
    /// -----------------
    
    void test_greater_than () {
    		Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));
        CPPUNIT_ASSERT(t.eq(z));
    }
    
    void test_greater_than2 () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 2);
        Matrix<bool> z;
        z = (x > y);
        CPPUNIT_ASSERT(z.get_rows() == 1);
        CPPUNIT_ASSERT(z.get_cols() == 1);
        CPPUNIT_ASSERT(z[0][0] == false);
    }
    
    void test_greater_than3 () {
        Matrix<int>  x(1, 1, 2);
        Matrix<int>  y(1, 1, 2);
        Matrix<bool> z;
        z = (x > y);
        CPPUNIT_ASSERT(z.get_rows() == 1);
        CPPUNIT_ASSERT(z.get_cols() == 1);
        CPPUNIT_ASSERT(z[0][0] == false);
    }
    
    void test_greater_than4 () {
        Matrix<int>  x(2, 2, 2);
        Matrix<int>  y(2, 2, 1);
        Matrix<bool> z;
        z = (x > y);
        CPPUNIT_ASSERT(z.get_rows() == 2);
        CPPUNIT_ASSERT(z.get_cols() == 2);
        CPPUNIT_ASSERT(z[1][1] == true);
    }
    
    /// --------------------
    /// test_greater_than_eq
    /// --------------------
    
    void test_greater_than_eq () {
    		Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));
        CPPUNIT_ASSERT(t.eq(z));
    }
    
    void test_greater_than_eq2 () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 2);
        Matrix<bool> z;
        z = (x >= y);
        CPPUNIT_ASSERT(z.get_rows() == 1);
        CPPUNIT_ASSERT(z.get_cols() == 1);
        CPPUNIT_ASSERT(z[0][0] == false);
    }
    
    void test_greater_than_eq3 () {
        Matrix<int>  x(1, 1, 2);
        Matrix<int>  y(1, 1, 2);
        Matrix<bool> z;
        z = (x >= y);
        CPPUNIT_ASSERT(z.get_rows() == 1);
        CPPUNIT_ASSERT(z.get_cols() == 1);
        CPPUNIT_ASSERT(z[0][0] == true);
    }
    
    void test_greater_than_eq4 () {
        Matrix<int>  x(2, 2, 2);
        Matrix<int>  y(2, 2, 1);
        Matrix<bool> z;
        z = (x >= y);
        CPPUNIT_ASSERT(z.get_rows() == 2);
        CPPUNIT_ASSERT(z.get_cols() == 2);
        CPPUNIT_ASSERT(z[1][1] == true);
    }
    
    /// -----------------
    /// test_less_than_eq
    /// -----------------
    
    void test_less_than_eq () {
    		Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));
        CPPUNIT_ASSERT(t.eq(z));
    }
    
    
    
    void test_less_than_eq2 () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 2);
        Matrix<bool> z;
        z = (x <= y);
        CPPUNIT_ASSERT(z.get_rows() == 1);
        CPPUNIT_ASSERT(z.get_cols() == 1);
        CPPUNIT_ASSERT(z[0][0] == true);
    }
    
    void test_less_than_eq3 () {
        Matrix<int>  x(1, 1, 2);
        Matrix<int>  y(1, 1, 2);
        Matrix<bool> z;
        z = (x <= y);
        CPPUNIT_ASSERT(z.get_rows() == 1);
        CPPUNIT_ASSERT(z.get_cols() == 1);
        CPPUNIT_ASSERT(z[0][0] == true);
    }
    
    void test_less_than_eq4 () {
        Matrix<int>  x(2, 2, 2);
        Matrix<int>  y(2, 2, 1);
        Matrix<bool> z;
        z = (x <= y);
        CPPUNIT_ASSERT(z.get_rows() == 2);
        CPPUNIT_ASSERT(z.get_cols() == 2);
        CPPUNIT_ASSERT(z[1][1] == false);
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_constructor2);
    CPPUNIT_TEST(test_constructor3);
    CPPUNIT_TEST(test_constructor4);
    CPPUNIT_TEST(test_index);
    CPPUNIT_TEST(test_index2);
    CPPUNIT_TEST(test_index3);
    CPPUNIT_TEST(test_index4);
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_equals2);
    CPPUNIT_TEST(test_equals3);
    CPPUNIT_TEST(test_equals4);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less_than2);
    CPPUNIT_TEST(test_less_than3);
    CPPUNIT_TEST(test_less_than4);
    CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(test_plus2);
    CPPUNIT_TEST(test_plus3);
    CPPUNIT_TEST(test_plus4);
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_minus2);
    CPPUNIT_TEST(test_minus3);
    CPPUNIT_TEST(test_minus4);
    CPPUNIT_TEST(test_multiplies);
    CPPUNIT_TEST(test_multiplies2);
    CPPUNIT_TEST(test_multiplies3);
    CPPUNIT_TEST(test_multiplies4);
    CPPUNIT_TEST(test_iterator);
    CPPUNIT_TEST(test_const_iterator);
    CPPUNIT_TEST(test_not_equals);
    CPPUNIT_TEST(test_not_equals2);
    CPPUNIT_TEST(test_not_equals3);
    CPPUNIT_TEST(test_not_equals4);
    CPPUNIT_TEST(test_greater_than);
    CPPUNIT_TEST(test_greater_than2);
    CPPUNIT_TEST(test_greater_than3);
    CPPUNIT_TEST(test_greater_than4);
    CPPUNIT_TEST(test_greater_than_eq);
    CPPUNIT_TEST(test_greater_than_eq2);
    CPPUNIT_TEST(test_greater_than_eq3);
    CPPUNIT_TEST(test_greater_than_eq4);
    CPPUNIT_TEST(test_less_than_eq);
    CPPUNIT_TEST(test_less_than_eq2);
    CPPUNIT_TEST(test_less_than_eq3);
    CPPUNIT_TEST(test_less_than_eq4);
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

