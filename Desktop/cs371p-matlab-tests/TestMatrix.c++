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
    // ----------------
    // test_constructor
    // ----------------

    void test_constructor_1 () {
        Matrix<int> x;
        CPPUNIT_ASSERT(x._m.size() == 0);
    }
    
    void test_constructor_2 () {
        Matrix<int> y(5);
        CPPUNIT_ASSERT(y._m.size() == 5);
    }
        
    void test_constructor_3 () {
        Matrix<int> y(2, 5);
        CPPUNIT_ASSERT(y._m.size() == 2);
        CPPUNIT_ASSERT(y._m[0].size() == 5);
        CPPUNIT_ASSERT(y._m[1].size() == 5);
    }
    
    void test_constructor_4 () {
        Matrix<int> y(2, 5, 8);
        CPPUNIT_ASSERT(y._m.size() == 2);
        CPPUNIT_ASSERT((y._m)[0].size() == 5);
        CPPUNIT_ASSERT((y._m)[1].size() == 5);
     }
       

    // ----------
    // test_index
    // ----------

    void test_index_1 () {
        const Matrix<int> x(1, 1);
        CPPUNIT_ASSERT(x[0][0] == 0);
    }
    
    void test_index_2 () {
        const Matrix<int> x(3, 4);
        for(int i=0; i<3; ++i){
            for(int j=0; j<4; ++j){
                CPPUNIT_ASSERT(x[i][j] == 0);
            }
        }
    }
    
    void test_index_3 () {
        const Matrix<int> x(5, 6, 7);
        for(int i=0; i<5; ++i){
            for(int j=0; j<6; ++j){
                CPPUNIT_ASSERT(x[i][j] == 7);
            }
        }
    }
        

    // -----------
    // test_equals
    // -----------

    void test_equals_1 () {
        Matrix<int>  z;
        Matrix<int>  t;
        CPPUNIT_ASSERT(z.eq(t));
    }
        
    void test_equals_2 () {
        Matrix<int>  z(2, 2);
        Matrix<int>  t(3, 3);
        CPPUNIT_ASSERT(!z.eq(t));
    }
        
    void test_equals_3 () {
        Matrix<int>  z(3, 3, 4);
        Matrix<int>  t(3, 3, 4);
        CPPUNIT_ASSERT(z.eq(t));
    }

    // --------------
    // test_equal_equal
    // --------------

    void test_equal_equal_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_equal_equal_2 () {
        Matrix<int>  x(1, 1);
        Matrix<int>  y(1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
    }
        
    void test_equal_equal_3 () {
        Matrix<int>  x(2, 3);
        Matrix<int>  y(2, 3);
        Matrix<bool> z;
        Matrix<bool> t(2, 3, 1);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_equal_equal_4 () {
        Matrix<int>  x(1, 1);
        Matrix<int>  y(2, 1);
        try{
            x == y;
            CPPUNIT_ASSERT(false);
        } catch(std::invalid_argument& A){
            CPPUNIT_ASSERT(true);
        }
    }
        
    // --------------
    // test_not_equal
    // --------------

    void test_not_equal_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_not_equal_2 () {
        Matrix<int>  x(1, 1);
        Matrix<int>  y(1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 0);
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));
    }
        
    void test_not_equal_3 () {
        Matrix<int>  x(2, 3);
        Matrix<int>  y(2, 3);
        Matrix<bool> z;
        Matrix<bool> t(2, 3, 0);
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));
    }
        
    // --------------
    // test_less_than
    // --------------

    void test_less_than_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_less_than_2 () {
        Matrix<int>  x(1, 1);
        Matrix<int>  y(1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 0);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
    }
        
    void test_less_than_3 () {
        Matrix<int>  x(2, 3);
        Matrix<int>  y(2, 3);
        Matrix<bool> z;
        Matrix<bool> t(2, 3, 0);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
     }
     
    // --------------
    // test_less_equal_than
    // --------------

    void test_less_equal_than_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_less_equal_than_2 () {
        Matrix<int>  x(1, 1);
        Matrix<int>  y(1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));
    }
        
    void test_less_equal_than_3 () {
        Matrix<int>  x(2, 3);
        Matrix<int>  y(2, 3);
        Matrix<bool> z;
        Matrix<bool> t(2, 3, 1);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));
     }

    // --------------
    // test_greater_than
    // --------------

    void test_greater_than_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x > y);
        
        CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_greater_than_2 () {
        Matrix<int>  x(1, 1);
        Matrix<int>  y(1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 0);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));
    }
        
    void test_greater_than_3 () {
        Matrix<int>  x(2, 3);
        Matrix<int>  y(2, 3);
        Matrix<bool> z;
        Matrix<bool> t(2, 3, 0);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));
     }

    // --------------
    // test_greater_equal_than
    // --------------

    void test_greater_equal_than_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));
    }
    
    void test_greater_equal_than_2 () {
        Matrix<int>  x(1, 1);
        Matrix<int>  y(1, 1);
        Matrix<bool> z;
        Matrix<bool> t(1, 1, 1);
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));
    }
        
    void test_greater_equal_than_3 () {
        Matrix<int>  x(2, 3);
        Matrix<int>  y(2, 3);
        Matrix<bool> z;
        Matrix<bool> t(2, 3, 1);
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));
     }
          
    // ---------
    // test_plus
    // ---------

    void test_plus_1 () {
        Matrix<int> x(1, 1);
        Matrix<int> y(1, 1);
        Matrix<int> z(1, 1, 0);
        x += 0;

        CPPUNIT_ASSERT(x.eq(z));

        x += y;

        CPPUNIT_ASSERT(x.eq(z));
    }
        
    void test_plus_2 () {
        Matrix<int> x(4, 4);
        Matrix<int> y(4, 4);
        Matrix<int> z(4, 4, 0);
        x += 0;
        x += y;

        CPPUNIT_ASSERT(x.eq(z));
    }
        
    void test_plus_3 () {
        Matrix<int> x(6, 6, 5);
        Matrix<int> y(6, 6, 5);
        Matrix<int> z(6, 6, 10);
        x += 0;
        x += y;

        CPPUNIT_ASSERT(x.eq(z));
    }
    

    // ----------
    // test_minus
    // ----------

    void test_minus_1 () {
        Matrix<int> x(1, 1);
        Matrix<int> y(1, 1);
        Matrix<int> z(1, 1, 0);
        x -= 0;

        CPPUNIT_ASSERT(x.eq(z));

        x -= y;

        CPPUNIT_ASSERT(x.eq(z));
    }
        
    void test_minus_2 () {
        Matrix<int> x(4, 4);
        Matrix<int> y(4, 4);
        Matrix<int> z(4, 4, 0);
        x -= 0;
        x -= y;

        CPPUNIT_ASSERT(x.eq(z));
    }
        
    void test_minus_3 () {
        Matrix<int> x(6, 6, 5);
        Matrix<int> y(6, 6, 5);
        Matrix<int> z(6, 6, 0);
        x -= 0;
        x -= y;

        CPPUNIT_ASSERT(x.eq(z));
    }


    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies_1 () {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, 1);
        Matrix<int> z(1, 1, 1);
        x *= 1;

        CPPUNIT_ASSERT(x.eq(z));

        x *= y;

        CPPUNIT_ASSERT(x.eq(z));
    }
        
    void test_multiplies_2 () {
        Matrix<int> x(4, 4, 2);
        Matrix<int> y(4, 4, 3);
        Matrix<int> z(4, 4, 12);
        x *= 2;
	x *= y;

        CPPUNIT_ASSERT(x.eq(z));
    }
        
    void test_multiplies_3 () {
        Matrix<int> x(6, 6, 5);
        Matrix<int> y(6, 6, 5);
        Matrix<int> z(6, 6, 10);
        x *= 2;

        CPPUNIT_ASSERT(x.eq(z));
    }
    

    // -------------
    // test_iterator
    // -------------

    void test_iterator () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);
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

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_constructor_4);
    CPPUNIT_TEST(test_index_1);
    CPPUNIT_TEST(test_index_2);
    CPPUNIT_TEST(test_index_3);

    // -------
    // compare
    // -------   

    CPPUNIT_TEST(test_equals_1);
    CPPUNIT_TEST(test_equals_2);
    CPPUNIT_TEST(test_equals_3);
    CPPUNIT_TEST(test_equal_equal_1);
    CPPUNIT_TEST(test_equal_equal_2);
    CPPUNIT_TEST(test_equal_equal_3);
    CPPUNIT_TEST(test_equal_equal_4);
    CPPUNIT_TEST(test_not_equal_1);
    CPPUNIT_TEST(test_not_equal_2);
    CPPUNIT_TEST(test_not_equal_3);
    CPPUNIT_TEST(test_less_than_1);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
    CPPUNIT_TEST(test_less_equal_than_1);
    CPPUNIT_TEST(test_less_equal_than_2);
    CPPUNIT_TEST(test_less_equal_than_3);
    CPPUNIT_TEST(test_greater_than_1);
    CPPUNIT_TEST(test_greater_than_2);
    CPPUNIT_TEST(test_greater_than_3);
    CPPUNIT_TEST(test_greater_equal_than_1);
    CPPUNIT_TEST(test_greater_equal_than_2);
    CPPUNIT_TEST(test_greater_equal_than_3);

    // ----
    // Math
    // ----

    CPPUNIT_TEST(test_plus_1);
    CPPUNIT_TEST(test_plus_2);
    CPPUNIT_TEST(test_plus_3);
    CPPUNIT_TEST(test_minus_1);
    CPPUNIT_TEST(test_minus_2);
    CPPUNIT_TEST(test_minus_3);
    CPPUNIT_TEST(test_multiplies_1);
    CPPUNIT_TEST(test_multiplies_2);
    CPPUNIT_TEST(test_multiplies_3);

    // ----

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
    return 0;
}
