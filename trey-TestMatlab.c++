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

    void test_horzcat () {
        Matrix<int> x(2, 2, 4);
        Matrix<int> y(2, 3, 4);
        Matrix<int> expected(2, 5, 4);
        Matrix<int> z = horzcat(x, y);
        CPPUNIT_ASSERT(expected.eq(z));}
    
    void test_horzcat_2 () {
        Matrix<int> x(2, 4, 4);
        Matrix<int> y(2, 3, 4);
        Matrix<int> expected(2, 7, 4);
        Matrix<int> z = horzcat(x, y);
        CPPUNIT_ASSERT(expected.eq(z));}
    
    void test_horzcat_3 () {
        Matrix<int> x(1, 2, 4);
        Matrix<int> y(2, 3, 4);
        try {
            Matrix<int> z = horzcat(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch (...) {
            CPPUNIT_ASSERT(true);
        }
    }

    void test_vertcat () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> y(4, 3, 4);
        Matrix<int> expected(6, 3, 4);
        Matrix<int> z = vertcat(x, y);
        CPPUNIT_ASSERT(expected.eq(z));}
    
    void test_vertcat_2 () {
        Matrix<int> x(2, 5, 4);
        Matrix<int> y(4, 5, 4);
        Matrix<int> expected(6, 5, 4);
        Matrix<int> z = vertcat(x, y);
        CPPUNIT_ASSERT(expected.eq(z));}
    
    void test_vertcat_3 () {
        Matrix<int> x(2, 4, 4);
        Matrix<int> y(4, 3, 4);
        try {
            Matrix<int> z = vertcat(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch (...) {
        CPPUNIT_ASSERT(true);
        }
    }

    // ---------
    // test_diag
    // ---------

    void test_diag () {
        Matrix<int> x(2, 2, 4);
        x[0][0] = 1;
        x[1][1] = 1;
        Matrix<int> y(1, 2, 1);
        Matrix<int> z = diag(x);
        CPPUNIT_ASSERT(z.eq(y));}
    
    void test_diag_2 () {
        Matrix<int> x(2, 3, 4);
        x[0][0] = 1;
        x[1][1] = 1;
        Matrix<int> y(1, 2, 1);
        Matrix<int> z = diag(x);
        CPPUNIT_ASSERT(z.eq(y));}
    
    void test_diag_3 () {
        Matrix<int> x(2, 2, 4);
        Matrix<int> y(1, 2, 4);
        Matrix<int> z = diag(x);
        CPPUNIT_ASSERT(z.eq(y));}

    // --------
    // test_dot
    // --------

    void test_dot () {
        Matrix<int> x(1, 3, 2);
        Matrix<int> y(1, 3, 3);
        Matrix<int> expected(1, 1, 18);
        Matrix<int> z = dot(x, y);
        CPPUNIT_ASSERT(expected.eq(z));}
    
    void test_dot_2 () {
        Matrix<int> x(3, 1, 2);
        Matrix<int> y(1, 3, 3);
        Matrix<int> expected(1, 1, 18);
        Matrix<int> z = dot(x, y);
        CPPUNIT_ASSERT(expected.eq(z));}
    
    void test_dot_3 () {
        Matrix<int> x(1, 4, 2);
        Matrix<int> y(1, 3, 3);
        try {
            Matrix<int> z = dot(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch (...) {
            CPPUNIT_ASSERT(true);
        }
    }

    // --------
    // test_eye
    // --------

    void test_eye () {
        Matrix<int> x(2, 2, 0);
        x[0][0] = 1;
        x[1][1] = 1;
        Matrix<int> y = eye< Matrix<int> >(2, 2);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_eye_2 () {
        Matrix<int> x(3, 3, 0);
        x[0][0] = 1;
        x[1][1] = 1;
        x[2][2] = 1;
        Matrix<int> y = eye< Matrix<int> >(3, 3);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_eye_3 () {
        Matrix<int> x;
        Matrix<int> y = eye< Matrix<int> >(0, 0);
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
        Matrix<int> x(3, 4, 1);
        Matrix<int> y = ones< Matrix<int> >(3, 4);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_ones_2 () {
        Matrix<int> x(4, 4, 1);
        Matrix<int> y = ones< Matrix<int> >(4, 4);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_ones_3 () {
        Matrix<int> x;
        Matrix<int> y = ones< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_rand
    // ---------

    void test_rand () {
        Matrix<double> x(2,3);
        x = rand< Matrix<double> >(2,3);
        for (int i = 0; i < 2; i++) {
         for (int j = 0; j < 3; j++) {
           CPPUNIT_ASSERT( x[i][j] >= 0 && x[i][j] <= 1);
         }
        }
    }
    
    void test_rand_2 () {
        Matrix<double> x(3,3);
        x = rand< Matrix<double> >(3,3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                CPPUNIT_ASSERT( x[i][j] >= 0 && x[i][j] <= 1);
            }
        }
    }

    void test_rand_3 () {
        Matrix<double> x;
        Matrix<double> y;
        x = rand< Matrix<double> >(0,0);
        CPPUNIT_ASSERT(x.eq(y));
    }


    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> y = transpose(x);
        Matrix<int> expected(3, 2, 4);
        CPPUNIT_ASSERT(expected.eq(y));}
    
    void test_transpose_2 () {
        Matrix<int> x(2, 2, 4);
        Matrix<int> y = transpose(x);
        Matrix<int> expected(2, 2, 4);
        CPPUNIT_ASSERT(expected.eq(y));}
    
    void test_transpose_3 () {
        Matrix<int> x(1, 3, 4);
        Matrix<int> y = transpose(x);
        Matrix<int> expected(3, 1, 4);
        CPPUNIT_ASSERT(expected.eq(y));}

    // ---------
    // test_tril
    // ---------

    void test_tril () {
        Matrix<int> x(3, 3, 1);
        Matrix<int> y(3, 3, 0);
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            if ( i >= j )
              y[i][j] = 1;
          }
        }

        Matrix<int> expected = tril(x); 
        CPPUNIT_ASSERT(expected.eq(y));}
    
    void test_tril_2 () {
        Matrix<int> x(3, 2, 4);
        Matrix<int> y(3, 2, 0);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                if ( i >= j )
                    y[i][j] = 4;
            }
        }
        
        Matrix<int> expected = tril(x); 
        CPPUNIT_ASSERT(expected.eq(y));}
    
    void test_tril_3 () {
        Matrix<int> x(3, 3, 0);
        Matrix<int> y(3, 3, 0);
        Matrix<int> expected = tril(x); 
        CPPUNIT_ASSERT(expected.eq(y));}

    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x(3, 3, 1);
        Matrix<int> y(3, 3, 0);
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            if ( i <= j )
              y[i][j] = 1;
          }
        }

        Matrix<int> expected = triu(x); 
        CPPUNIT_ASSERT(expected.eq(y));}
    
    void test_triu_2 () {
        Matrix<int> x(4, 3, 1);
        Matrix<int> y(4, 3, 0);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if ( i <= j )
                    y[i][j] = 1;
            }
        }
        
        Matrix<int> expected = triu(x); 
        CPPUNIT_ASSERT(expected.eq(y));}
    
    void test_triu_3 () {
        Matrix<int> x(3, 3, 0);
        Matrix<int> y(3, 3, 0);
        Matrix<int> expected = triu(x); 
        CPPUNIT_ASSERT(expected.eq(y));}

    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x(2, 3, 0);
        Matrix<int> y = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_zeros_2 () {
        Matrix<int> x;
        Matrix<int> y = zeros< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_zeros_3 () {
        Matrix<int> x(3, 3, 0);
        Matrix<int> y = zeros< Matrix<int> >(3, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(test_horzcat_2);
    CPPUNIT_TEST(test_horzcat_3);
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(test_horzcat_2);
    CPPUNIT_TEST(test_horzcat_3);
    CPPUNIT_TEST(test_diag);
    CPPUNIT_TEST(test_diag_2);
    CPPUNIT_TEST(test_diag_3);
    CPPUNIT_TEST(test_dot);
    CPPUNIT_TEST(test_dot_2);
    CPPUNIT_TEST(test_dot_3);
    CPPUNIT_TEST(test_eye);
    CPPUNIT_TEST(test_eye_2);
    CPPUNIT_TEST(test_eye_3);
    CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_ones);
    CPPUNIT_TEST(test_ones_2);
    CPPUNIT_TEST(test_ones_3);
    CPPUNIT_TEST(test_rand);
    CPPUNIT_TEST(test_rand_2);
    CPPUNIT_TEST(test_rand_3);
    CPPUNIT_TEST(test_transpose);
    CPPUNIT_TEST(test_transpose_2);
    CPPUNIT_TEST(test_transpose_3);
    CPPUNIT_TEST(test_tril);
    CPPUNIT_TEST(test_tril_2);
    CPPUNIT_TEST(test_tril_3);
    CPPUNIT_TEST(test_triu);
    CPPUNIT_TEST(test_triu_2);
    CPPUNIT_TEST(test_triu_3);
    CPPUNIT_TEST(test_zeros);
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
