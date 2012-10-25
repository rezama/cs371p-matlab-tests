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
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
        
    void test_horzcat_2 () {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 4);
        Matrix<int> z(2, 6);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
        
    void test_horzcat_3 () {
        Matrix<int> x(2, 3);
        Matrix<int> y(3, 2);
        try{
            x = horzcat(x, y);
            CPPUNIT_ASSERT(false);
        } catch(...){
            CPPUNIT_ASSERT(true);
        }
    }

    void test_vertcat_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
        
    void test_vertcat_2 () {
        Matrix<int> x(2, 3, 5);
        Matrix<int> y(1, 3, 5);
        Matrix<int> z(3, 3, 5);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
    
    void test_vertcat_3 () {
        Matrix<int> x(2, 3);
        Matrix<int> y(3, 2);
        try{
            x = horzcat(x, y);
            CPPUNIT_ASSERT(false);
        } catch(...){
            CPPUNIT_ASSERT(true);
        }
    }

    // ---------
    // test_diag
    // ---------

    void test_diag_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_diag_2 () {
        Matrix<int> x(1, 2);
        Matrix<int> y(1, 1);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_diag_3 () {
        Matrix<int> x(3, 4);
        Matrix<int> y(3, 1);
        for(int i=0; i<3; ++i){
            x[i][i] = i;
            y[i][0] = i;
        }
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    // --------
    // test_dot
    // --------

    void test_dot_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
    
    void test_dot_2 () {
        Matrix<int> x(2, 1, 2);
        Matrix<int> y(2, 1, 3);
        Matrix<int> z(1, 1, 12);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
        
    void test_dot_3 () {
        Matrix<int> x(3, 1, 2);
        Matrix<int> y(3, 1, 2);
        Matrix<int> z(1, 1, 12);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
        

    // --------
    // test_eye
    // --------

    void test_eye_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = eye< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_eye_2 () {
        Matrix<int> x;
        Matrix<int> y(2, 3);
        y[0][0] = 1;
        y[1][1] = 1;
        x = eye< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_eye_3 () {
        Matrix<int> x;
        Matrix<int> y(3, 2);
        y[0][0] = 1;
        y[1][1] = 1;
        x = eye< Matrix<int> >(3, 2);
        CPPUNIT_ASSERT(x.eq(y));}

  /*  // -------------
    // test_linsolve
    // -------------

    void test_linsolve () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = linsolve(x, y);
        CPPUNIT_ASSERT(x.eq(z));} */

    // ---------
    // test_ones
    // ---------

    void test_ones_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = ones< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_ones_2 () {
        Matrix<int> x;
        Matrix<int> y(2, 3, 1);
        x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_ones_3 () {
        Matrix<int> x;
        Matrix<int> y(3, 1, 5);
        x = ones< Matrix<int> >(3, 1);
        CPPUNIT_ASSERT(!x.eq(y));}

    // ---------
    // test_rand
    // ---------

    void test_rand_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = rand< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_rand_2 () {
        Matrix<int> x;
        Matrix<int> y(2, 2, 2);
        x = rand< Matrix<int> >(2, 2);
        CPPUNIT_ASSERT(!x.eq(y));}
        
    void test_rand_3 () {
        Matrix<double> x;
        Matrix<double> y(2, 2, 2.0);
        x = rand< Matrix<double> >(2, 2);
        CPPUNIT_ASSERT(!x.eq(y));}

    // --------------
    // test_transpose
    // --------------

    void test_transpose_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_transpose_2 () {
        Matrix<int> x(1, 2);
        Matrix<int> y(2, 1);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_transpose_3 () {
        Matrix<int> x(3, 2);
        Matrix<int> y(2, 3);
        for(int i=0; i<(int)x.size(); ++i){
            for(int j=0; j<(int)x[i].size(); ++j){
                x[i][j] = i;
                y[j][i] = i;
            }
        }
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}
        
    // ---------
    // test_tril
    // ---------

    void test_tril_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_tril_2 () {
        Matrix<int> x(3, 3, 5);
        Matrix<int> y(3, 3);
        y[1][0] = 5;
        y[2][0] = 5;
        y[2][1] = 5;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_tril_3 () {
        Matrix<int> x(3, 1, 5);
        Matrix<int> y(3, 1, 5);
        y[0][0] = 0;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_triu
    // ---------

    void test_triu_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_triu_2 () {
        Matrix<int> x(3, 3, 5);
        Matrix<int> y(3, 3);
        y[0][1] = 5;
        y[0][2] = 5;
        y[1][2] = 5;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_triu_3 () {
        Matrix<int> x(3, 1, 5);
        Matrix<int> y(3, 1, 0);
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

    // ----------
    // test_zeros
    // ----------

    void test_zeros_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_zeros_2 () {
        Matrix<int> x;
        Matrix<int> y(2, 3);
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_zeros_3 () {
        Matrix<int> x;
        Matrix<int> y(3, 5, 1);
        x = zeros< Matrix<int> >(3, 5);
        CPPUNIT_ASSERT(!x.eq(y));}

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
    CPPUNIT_TEST(test_dot_1);
    CPPUNIT_TEST(test_dot_2);
    CPPUNIT_TEST(test_dot_3);
    CPPUNIT_TEST(test_eye_1);
    CPPUNIT_TEST(test_eye_2);
    CPPUNIT_TEST(test_eye_3);
    //CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_ones_1);
    CPPUNIT_TEST(test_ones_2);
    CPPUNIT_TEST(test_ones_3);
    CPPUNIT_TEST(test_rand_1);
    CPPUNIT_TEST(test_rand_2);
    CPPUNIT_TEST(test_rand_3);
    CPPUNIT_TEST(test_transpose_1);
    CPPUNIT_TEST(test_transpose_2);
    CPPUNIT_TEST(test_transpose_3);
    CPPUNIT_TEST(test_tril_1);
    CPPUNIT_TEST(test_tril_2);
    CPPUNIT_TEST(test_tril_3);
    CPPUNIT_TEST(test_triu_1);
    CPPUNIT_TEST(test_triu_2);
    CPPUNIT_TEST(test_triu_3);
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

