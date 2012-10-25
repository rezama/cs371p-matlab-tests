// ------------------------------
// projects/matlab/TestMatlab.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
 * To test the program:
 *     g++ -ansi -pedantic -Wl,--no-as-needed -lcppunit -ldl -Wall TestMatlab.c++ -o TestMatlab.app
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
#include <cstdlib>
#include <stdexcept>

// ----------
// TestMatlab
// ----------

struct TestMatlab : CppUnit::TestFixture {
    // --------
    // test_cat
    // --------

    void test_horzcat_1 () 
    {
        Matrix<int> x(5,5,10);
        Matrix<int> y(5,8,10);
        y[4][3] = 4;
        Matrix<int> z(5,13,10);
        z[4][8] = 4;
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

     void test_horzcat_2 () {
        Matrix<int> x(3, 1, 0);
        Matrix<int> y(3, 4, 1);
        Matrix<int> z(3, 5, 1);
        z[0][0] = z[1][0] = z[2][0] = 0;
        x = horzcat<Matrix<int> >(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_horzcat_3 () 
    {
        Matrix<int> x(1, 3, 0);
        Matrix<int> y(2, 2, 1);
        try 
        {
          x = horzcat<Matrix<int> >(x, y);
        }
        catch (std::invalid_argument& e) 
        {
          CPPUNIT_ASSERT(true);
        }
    }


    void test_vertcat_1 () 
    {
        Matrix<int> x(6,5,20);
        Matrix<int> y(3,5,20);
        y[2][3] = 4;
        Matrix<int> z(9,5,20);
        z[8][3] = 4;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_vertcat_2 () {
        Matrix<int> x(0, 3, 0);
        Matrix<int> y(1, 3, 1);
        Matrix<int> z(1, 3, 1);
        x = vertcat<Matrix<int> >(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_vertcat_3 () {
        Matrix<int> x(2, 3, 0);
        Matrix<int> y(1, 2, 1);
        try {
          x = vertcat<Matrix<int> >(x, y);
        }
        catch (std::invalid_argument& e) {
          CPPUNIT_ASSERT(true);
        }
    }

    // ---------
    // test_diag
    // ---------

    void test_diag_1 () 
    {
        Matrix<int> x(3,3);
        x[0][0] = 1;
        x[0][1] = 2;
        x[0][2] = 3;

        x[1][0] = 4;
        x[1][1] = 5;
        x[1][2] = 6;

        x[2][0] = 7;
        x[2][1] = 8;
        x[2][2] = 9;
        Matrix<int> y(3,1);
        y[0][0]=1;
        y[1][0]=5;
        y[2][0]=9;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_diag_2 () 
    {
        Matrix<int> x(3, 3, 0);
        Matrix<int> y(3, 1, 0);
        Matrix<int> z;
        y[0][0] = 1;
        y[1][0] = 5;
        y[2][0] = 9;
        int count = 1;
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                x[i][j] = count++;

        try {
            z = diag(x);
            CPPUNIT_ASSERT(z.eq(y));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_diag_3 () 
    {
        Matrix<int> x(2, 5, 0);
        Matrix<int> y(2, 1, 0);
        Matrix<int> z;
        y[0][0] = 1;
        y[1][0] = 7;
        int count = 1;
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                x[i][j] = count++;

        try {
            z = diag(x);
            CPPUNIT_ASSERT(z.eq(y));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // --------
    // test_dot
    // --------

    void test_dot_1 () 
    {
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

    void test_dot_2 () 
    {
        Matrix<int> x(3, 3, 0);
        Matrix<int> y(1, 3, 0);
        Matrix<int> z;

        int count = 1;
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                x[i][j] = count++;

        y[0][0] = 66;
        y[0][1] = 93;
        y[0][2] = 126;

        try {
            z = dot(x, x);
            CPPUNIT_ASSERT(z.eq(y));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
        
    }

    void test_dot_3 () 
    {
        Matrix<int> x(2, 4, 0);
        Matrix<int> y(2, 4, 0);
        Matrix<int> z(1, 4, 0);
        Matrix<int> w;

        int count = 1;
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                x[i][j] = count++;

        count = 10;
        for(unsigned int i = 0; i < y.size(); i++)
            for(unsigned int j = 0; j < (y[i]).size(); j++)
                y[i][j] = count++;

        z[0][0] = 80;
        z[0][1] = 112;
        z[0][2] = 148;
        z[0][3] = 188;

        try {
            w = dot(x, y);
            CPPUNIT_ASSERT(w.eq(z));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // --------
    // test_eye
    // --------

    void test_eye_1 () 
    {
        Matrix<int> x;
        Matrix<int> y(5,4);
        y[0][0] = 1;
        y[1][1] = 1;
        y[2][2] = 1;
        y[3][3] = 1;
        x = eye< Matrix<int> >(5, 4);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_eye_2 () 
    {
        Matrix<int> x;
        Matrix<int> y(2,3,0);
        y[0][0] = 1;
        y[1][1] = 1;
        x = eye< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_eye_3 () 
    {
        Matrix<int> x;
        Matrix<int> y(3, 2);
        y[0][0] = 1;
        y[1][1] = 1;
        x = eye< Matrix<int> >(3, 2);
        CPPUNIT_ASSERT(x.eq(y));
    }

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

    void test_ones_1() 
    {
        Matrix<int> x;
        Matrix<int> y(2,3,1);
        x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

     void test_ones_2 () {
        Matrix<int> x;
        Matrix<int> y;
        x = ones< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}
 
     void test_ones_3() {
        Matrix<int> x;
        Matrix<int> y(1, 1, 1);
        x = ones<Matrix<int> >(1, 1);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_rand
    // ---------

    void test_rand_1 () 
    {
        Matrix<double> x;
        x = rand< Matrix<double> >(4,2);
        for(unsigned int i = 0; i < x.size(); i++)
        {
            for(unsigned int j = 0; j < x[0].size(); j++)
            {
                CPPUNIT_ASSERT(x[i][j] >= 0 && x[i][j] <= 1);
            }
        }
    }

    void test_rand_2() 
    {
        Matrix<double> x;
        x = rand<Matrix<double> >(10, 10);
        CPPUNIT_ASSERT(x.size() == 10);
        CPPUNIT_ASSERT(x[0].size() == 10);
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                CPPUNIT_ASSERT(x[i][j] >= 0 && x[i][j] <= 1);
    }
    
    void test_rand_3 () 
    {
        Matrix<int> x;
        Matrix<int> y;
        x = rand< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------------
    // test_transpose
    // --------------

    void test_transpose_1 () 
    {
        Matrix<int> x (3,2);
        x[0][0] = 1;
        x[0][1] = 2;
        x[1][0] = 3;
        x[1][1] = 4;
        x[2][0] = 5;
        x[2][1] = 6;
        Matrix<int> y (2,3);
        y[0][0] = 1;
        y[0][1] = 3;
        y[0][2] = 5;
        y[1][0] = 2;
        y[1][1] = 4;
        y[1][2] = 6;     
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_transpose_2()
    {
        Matrix<int> x(2, 69, 69);
        Matrix<int> y(69, 2, 69);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_transpose_3 () 
    {
        Matrix<int> x(96, 69);
        Matrix<int> y(69, 96);
        for (int i = 0; i < 96; i++) {
          for (int k = 0; k < 69; k++) {
            x[i][k] = y[k][i] = std::rand();
          }
        }
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_tril
    // ---------

    void test_tril_1 () 
    {
        Matrix<int> x(4, 5, 0);
        int count = 0;
        for(unsigned int i=0;i<x.size();i++)
            for(unsigned int j=0;j<x[0].size();j++)
                x[i][j] = ++count;  
        Matrix<int> y = tril(x);
        Matrix<int> z(4,5,0);
        z[0][0] = 1;
        z[1][0] = 6;
        z[1][1] = 7;
        z[2][0] = 11;
        z[2][1] = 12;
        z[2][2] = 13;
        z[3][0] = 16;
        z[3][1] = 17;
        z[3][2] = 18;
        z[3][3] = 19;
        CPPUNIT_ASSERT(y.eq(z));
    }

    void test_tril_2 () 
    {
        Matrix<int> x(3,3,2);
        Matrix<int> y(3,3,2);
        y[0][1] = 0;
        y[0][2] = 0;
        y[1][2] = 0;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_tril_3() 
    {
        Matrix<int> x(4, 5, 1);
        Matrix<int> y(4,5,0);
        y[0][0] = 1;
        y[1][0] = 1;  
        y[1][1] = 1;
        y[2][0] = 1;
        y[2][1] = 1;
        y[2][2] = 1;
        y[3][0] = 1;
        y[3][1] = 1;
        y[3][2] = 1;
        y[3][3] = 1;           
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_triu
    // ---------

    void test_triu_1() 
    {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y = triu(x);
        Matrix<int> z(2,2,1);
        z[1][0] = 0;
        CPPUNIT_ASSERT(y.eq(z));
    }

    void test_triu_2 () 
    {
        Matrix<int> x(3,3,2);
        Matrix<int> y(3,3,2);
        y[1][0] = 0;
        y[2][0] = 0;
        y[2][1] = 0;

        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_triu_3 ()
    {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        y[1][0] = 0;
        x = triu(x);

        CPPUNIT_ASSERT(x.eq(y));
    }

    // ----------
    // test_zeros
    // ----------

    void test_zeros_1 () 
    {
        Matrix<int> x(2, 3, -24);
        Matrix<int> y(2, 3, -1);
        y[0][0] = 0;
        y[0][1] = 0;
        y[0][2] = 0;
        y[1][0] = 0;
        y[1][1] = 0;
        y[1][2] = 0;
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_zeros_2 () 
    {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_zeros_3 () 
    {
        Matrix<int> x;
        Matrix<int> y(2, 3, 0);
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

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
    // CPPUNIT_TEST(test_linsolve);
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