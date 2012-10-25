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
    // test_horzcat1
    // --------

    void test_horzcat1 () {
        Matrix<int> x(10, 8, 0);
        Matrix<int> y(10, 2, 0);
        Matrix<int> z(10, 10, 0);
        Matrix<int> w;
        
        try {
            w = horzcat(x, y);
            CPPUNIT_ASSERT(w.eq(z));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // --------
    // test_horzcat2
    // --------

    void test_horzcat2 () {
        Matrix<int> x(1, 1, 0);
        Matrix<int> y(1, 1, 0);
        Matrix<int> z(1, 2, 0);
        Matrix<int> w;
        
        try {
            w = horzcat(x, y);
            CPPUNIT_ASSERT(w.eq(z));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
        
    }

    // --------
    // test_horzcat3
    // --------

    void test_horzcat3 () {
        Matrix<int> x(10, 2, 0);
        Matrix<int> y(9, 2, 0);
        try {
            horzcat(x, y);
            /* should fail here */
            CPPUNIT_ASSERT(false);
        }
        catch (...) {
            /* dimensions need to be the same */
            CPPUNIT_ASSERT(true);
        }
    }


    // ------------
    // test_horzcat4
    // ------------

    void test_horzcat4 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            y = horzcat(x, x);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ------------
    // test_vertcat1
    // ------------

    void test_vertcat1 () {
        Matrix<int> x(1, 1, 0);
        Matrix<int> y(1, 1, 0);
        Matrix<int> z(2, 1, 0);
        Matrix<int> w;
        try {
            w = vertcat(x, y);
            CPPUNIT_ASSERT(w.eq(z));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ------------
    // test_vertcat2
    // ------------

    void test_vertcat2 () {
        Matrix<int> x(5, 2, 0);
        Matrix<int> y(4, 2, 0);
        Matrix<int> z(9, 2, 0);
        Matrix<int> w;
        try {
            w = vertcat(x, y);
            CPPUNIT_ASSERT(w.eq(z));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ------------
    // test_vertcat3
    // ------------

    void test_vertcat3 () {
        Matrix<int> x(10, 5, 1);
        Matrix<int> y(2, 4, 1);
        Matrix<int> z;
        Matrix<int> w;
        try {
            z = vertcat(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch (...) {
            CPPUNIT_ASSERT(true);
        }
    }

    // ------------
    // test_vertcat4
    // ------------

    void test_vertcat4 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            y = vertcat(x, x);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ---------
    // test_diag1
    // ---------

    void test_diag1 () {
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

    // ---------
    // test_diag2
    // ---------

    void test_diag2 () {
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

    // ---------
    // test_diag4
    // ---------

    void test_diag4 () {
        Matrix<int> x(10, 4, 0);
        Matrix<int> y(4, 1, 0);
        Matrix<int> z;
        y[0][0] = 1;
        y[1][0] = 6;
        y[2][0] = 11;
        y[3][0] = 16;
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

    // ---------
    // test_diag3
    // ---------

    void test_diag3 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            y = diag(x);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }


    // --------
    // test_eye1
    // --------

    void test_eye1 () {
        Matrix<int> x(3, 3, 0);
        x[0][0] = 1;
        x[1][1] = 1;
        x[2][2] = 1;

        Matrix<int> y;
        try {
            y = eye<Matrix<int> >(3, 3);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // --------
    // test_eye2
    // --------

    void test_eye2 () {
        Matrix<int> x(2,4,0);
        x[0][0] = 1;
        x[1][1] = 1;
        Matrix<int> y;
        try {
            y = eye<Matrix<int> >(2, 4);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }

    }

    // --------
    // test_eye3
    // --------

    void test_eye3 () {
        Matrix<int> x(5,3,0);
        x[0][0] = 1;
        x[1][1] = 1;
        x[2][2] = 1;
        Matrix<int> y;
        try {
            y = eye<Matrix<int> >(5, 3);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // --------
    // test_eye4
    // --------

    void test_eye4 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            y = eye<Matrix<int> >(0, 0);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ---------
    // test_dot1
    // ---------

    void test_dot1 () {
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

    // ---------
    // test_dot2
    // ---------

    void test_dot2 () {
        Matrix<int> x(10,8,2);
        Matrix<int> y(10,4,3);
        try {
            dot(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch (...) {
            CPPUNIT_ASSERT(true);
        }
    }

    // ---------
    // test_dot3
    // ---------

    void test_dot3 () {
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

    // ---------
    // test_ones1
    // ---------

    void test_ones1 () {
        Matrix<int> x(10, 2, 1);
        Matrix<int> y;
        try {
            y = ones<Matrix <int> >(10, 2);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ---------
    // test_ones2
    // ---------

    void test_ones2 () {
        Matrix<int> x(2, 10, 1);
        Matrix<int> y;
        try {
            y = ones<Matrix <int> >(2, 10);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }


    // ---------
    // test_ones3
    // ---------

    void test_ones3 () {
        Matrix<int> x(10, 10, 1);
        Matrix<int> y;
        try {
            y = ones<Matrix <int> >(10, 10);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    void test_ones4 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            y = ones<Matrix <int> >(0,0);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }


    // ---------
    // test_rand1
    // ---------

    void test_rand1 () {
        Matrix<double> x;
        try {
            x = rand< Matrix<double> >(8, 10);
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
        
        for (unsigned int i = 0; i < x.size(); i++)
            for (unsigned int j = 0; j < (x[i]).size(); j++)
                if (x[i][j] < 0 || x[i][j] > 1) 
                    CPPUNIT_ASSERT(false);

        CPPUNIT_ASSERT(true);
    }

    // ---------
    // test_rand2
    // ---------

    void test_rand2 () {
        Matrix<double> x;
        try {
            x = rand< Matrix<double> >(10, 8);
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }

        for (unsigned int i = 0; i < x.size(); i++)
            for (unsigned int j = 0; j < (x[i]).size(); j++)
                if (x[i][j] < 0 || x[i][j] > 1) 
                    CPPUNIT_ASSERT(false);

        CPPUNIT_ASSERT(true);
    }

    // ---------
    // test_rand3
    // ---------

    void test_rand3 () {
        Matrix<double> x;
        try {
            x = rand< Matrix<double> >(10, 10);
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
        
        for (unsigned int i = 0; i < x.size(); i++)
            for (unsigned int j = 0; j < (x[i]).size(); j++)
                if (x[i][j] < 0 || x[i][j] > 1) 
                    CPPUNIT_ASSERT(false);

        CPPUNIT_ASSERT(true);
    }

    // ---------
    // test_rand4
    // ---------

    void test_rand4 () {
        Matrix<double> x;
        Matrix<double> y;
        try {
            y = rand< Matrix<double> >(0, 0);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // --------------
    // test_transpose1
    // --------------

    void test_transpose1 () {
        Matrix<int> x(15, 15, 100);
        Matrix<int> y;
        try {
            y = transpose(x);
            CPPUNIT_ASSERT(x.eq(y));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // --------------
    // test_transpose2
    // --------------

    void test_transpose2 () {
        Matrix<int> x(10, 8, 2);
        Matrix<int> y(8, 10, 2);
        Matrix<int> z;
        try {
            z = transpose(x);
            CPPUNIT_ASSERT(z.eq(y));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // --------------
    // test_transpose3
    // --------------

    void test_transpose3 () {
        Matrix<int> x(8, 10, 2);
        Matrix<int> y(10, 8, 2);
        Matrix<int> z;
        try {
            z = transpose(x);
            CPPUNIT_ASSERT(z.eq(y));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }


    // --------------
    // test_transpose4
    // --------------

    void test_transpose4 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            y = transpose(x);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

        

    // ---------
    // test_tril1
    // ---------

    void test_tril1 () {
        Matrix<int> x(3, 3, 0);
        Matrix<int> y(3, 3, 0);
        Matrix<int> z;

        int count = 1;
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                x[i][j] = count++;

        y[0][0] = 1;
        y[1][0] = 4;
        y[1][1] = 5;
        y[2][0] = 7;
        y[2][1] = 8;
        y[2][2] = 9;

        try {
            z = tril(x);
            CPPUNIT_ASSERT(y.eq(z));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ---------
    // test_tril2
    // ---------

    void test_tril2 () {
        Matrix<int> x(2, 4, 0);
        Matrix<int> y(2, 4, 0);
        Matrix<int> z;

        int count = 1;
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                x[i][j] = count++;

        y[0][0] = 1;
        y[1][0] = 5;
        y[1][1] = 6;

        try {
            z = tril(x);
            CPPUNIT_ASSERT(z.eq(y));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }

    }

    // ---------
    // test_tril3
    // ---------

    void test_tril3 () {
        Matrix<int> x(4, 2, 0);
        Matrix<int> z;

        int count = 1;
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                x[i][j] = count++;

        Matrix<int> y = x;
        y[0][1] = 0;

        try {
            z = tril(x);
            CPPUNIT_ASSERT(z.eq(y));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ---------
    // test_tril4
    // ---------

    void test_tril4 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            y = tril(x);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ---------
    // test_triu1
    // ---------

    void test_triu1 () {
        Matrix<int> x(3, 3, 0);
        Matrix<int> y(3, 3, 0);
        Matrix<int> z;

        int count = 1;
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                x[i][j] = count++;

        y[0][0] = 1;
        y[0][1] = 2;
        y[0][2] = 3;
        y[1][1] = 5;
        y[1][2] = 6;
        y[2][2] = 9;

        try {
            z = triu(x);
            CPPUNIT_ASSERT(y.eq(z));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ---------
    // test_triu2
    // ---------

    void test_triu2 () {
        Matrix<int> x(2, 4, 0);
        Matrix<int> z;

        int count = 1;
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                x[i][j] = count++;

        Matrix<int> y = x;

        y[1][0] = 0;

        try {
            z = triu(x);
            CPPUNIT_ASSERT(z.eq(y));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ---------
    // test_triu3
    // ---------

    void test_triu3 () {
        Matrix<int> x(4, 2, 0);
        Matrix<int> y(4, 2, 0);
        Matrix<int> z;

        int count = 1;
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                x[i][j] = count++;

        
        y[0][0] = 1;
        y[0][1] = 2;
        y[1][1] = 4;

        try {
            z = triu(x);
            CPPUNIT_ASSERT(z.eq(y));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ---------
    // test_triu4
    // ---------

    void test_triu4 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            y = triu(x);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ---------
    // test_zeros1
    // ---------

    void test_zeros1 () {
        Matrix<int> x(3, 3, 0);
        Matrix<int> y;
        try {
            y = zeros<Matrix <int> >(3, 3);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ---------
    // test_zeros2
    // ---------


    void test_zeros2 () {
        Matrix<int> x(10, 8, 0);
        Matrix<int> y;
        try {
            y = zeros<Matrix <int> >(10, 8);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ---------
    // test_zeros3
    // ---------

    void test_zeros3 () {
        Matrix<int> x(8, 10, 0);
        Matrix<int> y;
        try {
            y = zeros<Matrix <int> >(8, 10);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // ---------
    // test_zeros4
    // ---------

    void test_zeros4 () {
        Matrix<int> x;
        Matrix<int> y;
        try {
            y = zeros<Matrix <int> >(0, 0);
            CPPUNIT_ASSERT(y.eq(x));
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat1);
    CPPUNIT_TEST(test_horzcat2);
    CPPUNIT_TEST(test_horzcat3);
    CPPUNIT_TEST(test_horzcat4);
    CPPUNIT_TEST(test_vertcat1);
    CPPUNIT_TEST(test_vertcat2);
    CPPUNIT_TEST(test_vertcat3);
    CPPUNIT_TEST(test_vertcat4);
    CPPUNIT_TEST(test_diag1);
    CPPUNIT_TEST(test_diag2);
    CPPUNIT_TEST(test_diag3);
    CPPUNIT_TEST(test_diag4);
    CPPUNIT_TEST(test_dot1);
    CPPUNIT_TEST(test_dot2);
    CPPUNIT_TEST(test_dot3);
    CPPUNIT_TEST(test_eye1);
    CPPUNIT_TEST(test_eye2);
    CPPUNIT_TEST(test_eye3);
    CPPUNIT_TEST(test_eye4);
    CPPUNIT_TEST(test_ones1);
    CPPUNIT_TEST(test_ones2);
    CPPUNIT_TEST(test_ones3);
    CPPUNIT_TEST(test_ones4);
    CPPUNIT_TEST(test_rand1);
    CPPUNIT_TEST(test_rand2);
    CPPUNIT_TEST(test_rand3);
    CPPUNIT_TEST(test_rand4);
    CPPUNIT_TEST(test_transpose1);
    CPPUNIT_TEST(test_transpose2);
    CPPUNIT_TEST(test_transpose3);
    CPPUNIT_TEST(test_transpose4);
    CPPUNIT_TEST(test_tril1);
    CPPUNIT_TEST(test_tril2);
    CPPUNIT_TEST(test_tril3);
    CPPUNIT_TEST(test_tril4);
    CPPUNIT_TEST(test_triu1);
    CPPUNIT_TEST(test_triu2);
    CPPUNIT_TEST(test_triu3);
    CPPUNIT_TEST(test_triu4);
    CPPUNIT_TEST(test_zeros1);
    CPPUNIT_TEST(test_zeros2);
    CPPUNIT_TEST(test_zeros3);
    CPPUNIT_TEST(test_zeros4);
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