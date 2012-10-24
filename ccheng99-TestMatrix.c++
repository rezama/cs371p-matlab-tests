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

    void test_constructor2 () {
        Matrix<int> y(2);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(y[0].size() == 0);
        CPPUNIT_ASSERT(y[1].size() == 0);
    }

    void test_constructor3 () {
        Matrix<int> z(2, 3);

        CPPUNIT_ASSERT(z.size() == 2);
        CPPUNIT_ASSERT(z[0].size() == 3);
        
        CPPUNIT_ASSERT(z[0][0] == 0);
        CPPUNIT_ASSERT(z[0][1] == 0);
        CPPUNIT_ASSERT(z[0][2] == 0);
        CPPUNIT_ASSERT(z[1][0] == 0);
        CPPUNIT_ASSERT(z[1][1] == 0);
        CPPUNIT_ASSERT(z[1][2] == 0);
    }

    // ----------
    // test_index
    // ----------

    void test_index () {
        const Matrix<int> x(2,2,2);
        CPPUNIT_ASSERT(x[0][0] == 2);
        CPPUNIT_ASSERT(x[1][0] == 2);
        CPPUNIT_ASSERT(x[0][1] == 2);
        CPPUNIT_ASSERT(x[1][1] == 2);
    }

    void test_index2 () {
        const Matrix<int> x(2,2);
        CPPUNIT_ASSERT(x[0][0] == 0);
        CPPUNIT_ASSERT(x[1][0] == 0);
        CPPUNIT_ASSERT(x[0][1] == 0);
        CPPUNIT_ASSERT(x[1][1] == 0);
    }

    void test_index3 () {
        const Matrix<int> x(5,5,5);
        CPPUNIT_ASSERT(x[0][0] == 5);
        CPPUNIT_ASSERT(x[1][0] == 5);
        CPPUNIT_ASSERT(x[0][1] == 5);
        CPPUNIT_ASSERT(x[1][1] == 5);
    }

    // -----------
    // test_equals
    // -----------

    void test_equals () {
        Matrix<int>  x(1,1,2);
        Matrix<int>  y(1,1,2);
        Matrix<bool> z;
        Matrix<bool> t(1,1,true);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_equals_empty () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_equals_emptyrow () {
        Matrix<int>  x(2);
        Matrix<int>  y(2);
        Matrix<bool> z;
        Matrix<bool> t(2);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

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

    void test_not_equals_empty () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_not_equals_emptyrow () {
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
        Matrix<int>  x(1,1,3);
        Matrix<int>  y(1,1,4);
        Matrix<bool> z;
        Matrix<bool> t(1,1,true);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_empty () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_emptyrow () {
        Matrix<int>  x(2);
        Matrix<int>  y(2);
        Matrix<bool> z;
        Matrix<bool> t(2);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_less_than_equals
    // --------------

    void test_less_than_equals () {
        Matrix<int>  x(1,1,3);
        Matrix<int>  y(1,1,4);
        Matrix<bool> z;
        Matrix<bool> t(1,1,true);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_equals_empty () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_equals_emptyrow () {
        Matrix<int>  x(2);
        Matrix<int>  y(2);
        Matrix<bool> z;
        Matrix<bool> t(2);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_greater_than
    // --------------

    void test_greater_than () {
        Matrix<int>  x(1,1,3);
        Matrix<int>  y(1,1,4);
        Matrix<bool> z;
        Matrix<bool> t(1,1,false);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_empty () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_emptyrow () {
        Matrix<int>  x(2);
        Matrix<int>  y(2);
        Matrix<bool> z;
        Matrix<bool> t(2);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_greater_than_equals
    // --------------

    void test_greater_than_equals () {
        Matrix<int>  x(1,1,3);
        Matrix<int>  y(1,1,4);
        Matrix<bool> z;
        Matrix<bool> t(1,1,false);
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_equals_empty () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_equals_emptyrow () {
        Matrix<int>  x(2);
        Matrix<int>  y(2);
        Matrix<bool> z;
        Matrix<bool> t(2);
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    // ---------
    // test_operators
    // ---------

    void test_operators() {
        Matrix<int> x (2,2,2);
        Matrix<int> y (2,2,3);
        Matrix<int> z (2,2,2);
        Matrix<int> res(2,2,5);

        CPPUNIT_ASSERT((x+y).eq(res));
        CPPUNIT_ASSERT(x.eq(z));
    }

    // ---------
    // test_plus
    // ---------

    void test_plus () {
        Matrix<int> x(1,1,3);
        Matrix<int> y(1,1,0);
        Matrix<int> z(1,1,3);
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_plus_empty () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_plus_emptyrow () {
        Matrix<int> x(1);
        Matrix<int> y(1);
        Matrix<int> z(1);
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}

    // ----------
    // test_minus
    // ----------

    void test_minus () {
        Matrix<int> x(1,1,3);
        Matrix<int> y(1,1,0);
        Matrix<int> z(1,1,3);
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}
        			//addl tests
        
 	void test_minus_Matrix_2 () {
        Matrix<int> x(2, 3, 1);
        Matrix<int> y(2, 3, 4);
        x -= y;
        for(int i=0; i<2; ++i){
            for(int j=0; j<3; ++j){
         	   CPPUNIT_ASSERT(y[i][j] == 4);
               CPPUNIT_ASSERT(x[i][j] == -3);             
            }
        }
     }
     
    void test_minus_3 () {
        Matrix<int> x(2,3,9);
        Matrix<int> y(2,3,6);
        Matrix<int> z(2,3,3);
        x -= 3;
        CPPUNIT_ASSERT(x.eq(y));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
    }
        
				// end addl tests
    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies () {
        Matrix<int> x(1,1,3);
        Matrix<int> y(1,1,1);
        Matrix<int> z(1,1,3);
        x *= 1;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_multiplies_matrices() {
        Matrix<int> x(2,3,3);
        Matrix<int> y(3,2,5);
        Matrix<int> z(2,2,45);
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_multiplies_matrices_empty() {
        Matrix<int> x(2,0,2);
        Matrix<int> y(0,2,2);
        Matrix<int> z(2,2,0);
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_multiplies_matrices_emptyresult() {
        Matrix<int> x(0,2,0);
        Matrix<int> y(2,0,0);
        Matrix<int> z(0,0,0);
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_multiplies_matrices_emptycombo() {
        Matrix<int> x(2,2,0);
        Matrix<int> y(2,0,0);
        Matrix<int> z(2,0,0);
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

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_constructor2);
    CPPUNIT_TEST(test_constructor3);
    CPPUNIT_TEST(test_index);
    CPPUNIT_TEST(test_index2);
    CPPUNIT_TEST(test_index3);
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_equals_empty);
    CPPUNIT_TEST(test_equals_emptyrow);
    CPPUNIT_TEST(test_not_equals);
    CPPUNIT_TEST(test_not_equals_empty);
    CPPUNIT_TEST(test_not_equals_emptyrow);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less_than_empty);
    CPPUNIT_TEST(test_less_than_emptyrow);
    CPPUNIT_TEST(test_less_than_equals);
    CPPUNIT_TEST(test_less_than_equals_empty);
    CPPUNIT_TEST(test_less_than_equals_emptyrow);
    CPPUNIT_TEST(test_greater_than);
    CPPUNIT_TEST(test_greater_than_empty);
    CPPUNIT_TEST(test_greater_than_emptyrow);
    CPPUNIT_TEST(test_greater_than_equals);
    CPPUNIT_TEST(test_greater_than_equals_empty);
    CPPUNIT_TEST(test_greater_than_equals_emptyrow);
    CPPUNIT_TEST(test_operators);
    CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(test_plus_empty);
    CPPUNIT_TEST(test_plus_emptyrow);
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_multiplies);
    CPPUNIT_TEST(test_multiplies_matrices);
    CPPUNIT_TEST(test_multiplies_matrices_empty);
    CPPUNIT_TEST(test_multiplies_matrices_emptyresult);
    CPPUNIT_TEST(test_multiplies_matrices_emptycombo);
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
