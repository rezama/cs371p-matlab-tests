// ------------------------------
// projects/matlab/TestMatlab.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
 * To test the program:
 *     g++ -ansi -pedantic -lcppunit -ldl -Wall TestMatlab.c++ -o TestMatlab.app
 *     valgrind ./TestMatlab.app >& TestMatlab.out
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
        Matrix<int> x(2,1);
        Matrix<int> y(1,2);
        try {
        	x = horzcat(x, y);
        	CPPUNIT_ASSERT(false);
        }
        catch (std::invalid_argument &e) {
        	CPPUNIT_ASSERT(true);
        }
    }

    void test_horzcat_3 () {
        Matrix<int> x(1,1,1);
        Matrix<int> y(1,1,2);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x[0][0] = 1);
        CPPUNIT_ASSERT(x[0][1] = 2);}

    void test_horzcat_4 () {
        Matrix<int> x(2,1,2);
        Matrix<int> y(2,1,3);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x[0][0] = 2);
        CPPUNIT_ASSERT(x[0][1] = 3);
        CPPUNIT_ASSERT(x[1][0] = 2);
        CPPUNIT_ASSERT(x[1][1] = 3);}

    void test_horzcat_5 () {
        Matrix<int> x(2,1,2);
        Matrix<int> y(2,0);
        y = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_vertcat_1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat_2 () {
        Matrix<int> x(2,1);
        Matrix<int> y(1,2);
        try {
        	x = vertcat(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch (std::invalid_argument &e) {
        	CPPUNIT_ASSERT(true);
        }
    }

    void test_vertcat_3 () {
        Matrix<int> x(1,1,1);
        Matrix<int> y(1,1,2);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x[0][0] = 1);
        CPPUNIT_ASSERT(x[1][0] = 2);}

    void test_vertcat_4 () {
        Matrix<int> x(1,2,2);
        Matrix<int> y(1,2,3);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x[0][0] = 2);
        CPPUNIT_ASSERT(x[0][1] = 2);
        CPPUNIT_ASSERT(x[1][0] = 3);
        CPPUNIT_ASSERT(x[1][1] = 3);}

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
        Matrix<int> x(1,1);
        Matrix<int> y(1,1);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_dot_3 () {
        Matrix<int> x(1,2,2);
        Matrix<int> y(1,2,2);
        x = dot(x, y);
        CPPUNIT_ASSERT(x[0][0] == 8);}


    void test_diag_1 () {
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

    void test_diag_2 () {
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

    void test_diag_4 () {
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

    void test_diag_3 () {
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

    void test_eye_1 () {
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

    void test_eye_2 () {
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

    void test_eye_3 () {
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

    void test_eye_4 () {
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

    void test_ones_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = ones< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_ones_2 () {
        Matrix<int> x(5, 6, 1);
        Matrix<int> y;
        y = ones< Matrix<int> >(5, 6);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_ones_3 () {
        Matrix<int> x;
        Matrix<int> y(2,2,1);
        x = ones< Matrix<int> >(2, 2);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_ones_4 () {
        Matrix<int> x;
        Matrix<int> y(2,3,1);
        x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_rand
    // ---------

    void test_rand_4 () {
        Matrix<double> x(500, 500);
        Matrix<double> y(500, 500);
        x = rand< Matrix<double> >(500, 500);
        y = rand< Matrix<double> >(500, 500);
        CPPUNIT_ASSERT(x[499] != y[499] || x[0] != y[0] || x[250] != y[250]);
        CPPUNIT_ASSERT(x.eq(y) == false);
    }

    void test_rand_1 () {
        Matrix<double> x;
        int ROW = 100;
        int COL = 100;        
        x = rand< Matrix<double> >(ROW, COL);        
        for(int rows = 0; rows < ROW; rows++)
        {
            for(int cols = 0; cols < COL; cols++)
            {
                CPPUNIT_ASSERT(x[rows][cols] < 1.0 && x[rows][cols] > 0.0);
            }
        }
     }
          
     void test_rand_2 () {
        Matrix<int> x;
        Matrix<int> y;
        x = rand< Matrix<int> >(2, 3);
        
        CPPUNIT_ASSERT(x.size() == 2);
        CPPUNIT_ASSERT(x[0].size() == 3);
    }
    
    void test_rand_3 () {
        Matrix<double> x;
        x = rand<Matrix<double> >(10, 10);        
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                CPPUNIT_ASSERT(x[i][j] != 0 && x[i][j] < 1);
    }

    // --------------
    // test_transpose
    // --------------

    void test_transpose_1 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> y(3, 2, 4);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_transpose_2 () {
        Matrix<int> x(1,1,1);
        Matrix<int> y(1,1,1);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_transpose_3 () {
        Matrix<int> x(2,2);
        x[0][0] = 1;
        x[0][1] = 2;
        x[1][0] = 3;
        x[1][1] = 4;
        Matrix<int> y(2,2);
        y[0][0] = 1;
        y[0][1] = 3;
        y[1][0] = 2;
        y[1][1] = 4;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_transpose_4 () {
    	Matrix<int> z(3,2);
        Matrix<int> x(2,3);
        x[0][0] = 1;
        x[0][1] = 2;
        x[0][2] = 3;
        x[1][0] = 4;
        x[1][1] = 5;
        x[1][2] = 6;
        Matrix<int> y(3,2);
        y[0][0] = 1;
        y[0][1] = 4;
        y[1][0] = 2;
        y[1][1] = 5;
        y[2][0] = 3;
        y[2][1] = 6;
        z = transpose(x);
        CPPUNIT_ASSERT(z.eq(y));}

    // ---------
    // test_tril
    // ---------

    void test_tril_1 () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        y[0][1] = 0;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_tril_2 () {
        Matrix<int> x(2,3,1);
        Matrix<int> y(2,3,1);

        y[0][1] = 0;
        y[0][2] = 0;
        y[1][2] = 0;

        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_tril_3 () {
        Matrix<int> x(4, 6, 1);
        Matrix<int> y(4, 6, 1);
        y[0][1] = 0;
        y[0][2] = 0;
        y[0][3] = 0;
        y[0][4] = 0;
        y[0][5] = 0;
        y[1][2] = 0;
        y[1][3] = 0;
        y[1][4] = 0;
        y[1][5] = 0;
        y[2][3] = 0;
        y[2][4] = 0;
        y[2][5] = 0;
        y[3][4] = 0;
        y[3][5] = 0;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_tril_4 () {
        Matrix<int> x(3,3,1);
        Matrix<int> y(3,3,1);
        y[0][1] = 0;
        y[0][2] = 0;
        y[1][2] = 0;
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
        Matrix<int> x(4, 4, 1);
        Matrix<int> y(4, 4, 1);
        y[1][0] = 0;
        y[2][0] = 0;
        y[3][0] = 0;
        y[2][1] = 0;
        y[3][1] = 0;
        y[3][2] = 0;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_triu_3 () {
        Matrix<int> x(4, 6, 1);
        Matrix<int> y(4, 6, 1);
        y[1][0] = 0;
        y[2][0] = 0;
        y[3][0] = 0;
        y[2][1] = 0;
        y[3][1] = 0;
        y[3][2] = 0;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_triu_4 () {
        Matrix<int> x(3,3,1);
        Matrix<int> y(3,3,1);
        y[1][0] = 0;
        y[2][0] = 0;
        y[2][1] = 0;
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
        Matrix<int> y(1,1,0);
        x = zeros< Matrix<int> >(1, 1);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_zeros_3 () {
        Matrix<int> x;
        Matrix<int> y(2,2,0);
        x = zeros< Matrix<int> >(2, 2);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_zeros_4 () {
        Matrix<int> x;
        Matrix<int> y(2,3,0);
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat_1);
    CPPUNIT_TEST(test_horzcat_2);
    CPPUNIT_TEST(test_horzcat_3);
    CPPUNIT_TEST(test_horzcat_4);
    CPPUNIT_TEST(test_horzcat_5);
    CPPUNIT_TEST(test_vertcat_1);
    CPPUNIT_TEST(test_vertcat_2);
    CPPUNIT_TEST(test_vertcat_3);
    CPPUNIT_TEST(test_vertcat_4);
    CPPUNIT_TEST(test_diag_1);
    CPPUNIT_TEST(test_diag_2);
    CPPUNIT_TEST(test_diag_3);
    CPPUNIT_TEST(test_diag_4);
    CPPUNIT_TEST(test_dot_1);
    CPPUNIT_TEST(test_dot_2);
    CPPUNIT_TEST(test_dot_3);
    CPPUNIT_TEST(test_eye_1);
    CPPUNIT_TEST(test_eye_2);
    CPPUNIT_TEST(test_eye_3);
    CPPUNIT_TEST(test_eye_4);
    CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_ones_1);
    CPPUNIT_TEST(test_ones_2);
    CPPUNIT_TEST(test_ones_3);
    CPPUNIT_TEST(test_ones_4);
    CPPUNIT_TEST(test_rand_1);
    CPPUNIT_TEST(test_rand_2);
    CPPUNIT_TEST(test_rand_3);
    CPPUNIT_TEST(test_rand_4);
    CPPUNIT_TEST(test_transpose_1);
    CPPUNIT_TEST(test_transpose_2);
    CPPUNIT_TEST(test_transpose_3);
    CPPUNIT_TEST(test_transpose_4);
    CPPUNIT_TEST(test_tril_1);
    CPPUNIT_TEST(test_tril_2);
    CPPUNIT_TEST(test_tril_3);
    CPPUNIT_TEST(test_tril_4);
    CPPUNIT_TEST(test_triu_1);
    CPPUNIT_TEST(test_triu_2);
    CPPUNIT_TEST(test_triu_3);
    CPPUNIT_TEST(test_triu_4);
    CPPUNIT_TEST(test_zeros_1);
    CPPUNIT_TEST(test_zeros_2);
    CPPUNIT_TEST(test_zeros_3);
    CPPUNIT_TEST(test_zeros_4);
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
