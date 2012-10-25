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

#define private public
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
        Matrix<int> x(3,5);
        Matrix<int> y(3,3);
        Matrix<int> z(3,8);
        int values_x[] = {17, 24, 1, 8, 15,
            23, 5, 7, 14, 16,
            4, 6, 13, 20, 22};
        int values_y[] = {800, 100, 600,
            300, 500, 700,
            400, 900, 200};
        int values_z[] = {17, 24, 1, 8, 15, 800, 100, 600,
            23, 5, 7, 14, 16, 300, 500, 700,
            4, 6, 13, 20, 22, 400, 900, 200};
        int k = 0;
        for (int i=0; i<3; i++){
            for (int j=0 ; j<5; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<8; j++) {
                z[i][j] = values_z[k];
                k++;
            }
        }
        
        x = horzcat(x, y);
                
        CPPUNIT_ASSERT(x.eq(z));}
    
    void test_horzcat_2 () {
        Matrix<int> x(3,3);
        Matrix<int> y(3,3);
        Matrix<int> z(3,6);
        
        int values_x[] = {2, 3, 4,
            1, 2, 5,
            4, 6, 3};
        int values_y[] = {9, 6, 8,
            5, 6, 2,
            3, 2, 1};
        int values_z[] = {2, 3, 4, 9, 6, 8,
            1, 2, 5, 5, 6, 2,
            4, 6, 3, 3, 2, 1};
        int k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<6; j++) {
                z[i][j] = values_z[k];
                k++;
            }
        }
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
    
    void test_horzcat_3 () {
        Matrix<int> x(3,3);
        Matrix<int> y(3,3);
        Matrix<int> z(3,6);
        
        int values_x[] = {1, 2, 3,
            7, 8, 9,
            13, 14, 15};
        int values_y[] = {4, 5, 6,
            10, 11, 12,
            16, 17, 18};
        int values_z[] = {1, 2, 3, 4, 5, 6,
            7, 8, 9, 10, 11, 12,
            13, 14, 15, 16, 17, 18};
        int k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<6; j++) {
                z[i][j] = values_z[k];
                k++;
            }
        }
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
        
        
    void test_horzcat_4() {
        Matrix<int> x(3,3);
        Matrix<int> y(4,3);
        Matrix<int> z(3,6);
        
        try {
            x = horzcat(x,y);
            CPPUNIT_ASSERT(false);
        }
        
        catch (std::invalid_argument) {
            CPPUNIT_ASSERT(true);
        }
    }
    
    void test_vertcat_1 () {
        Matrix<int> x(5,3);
        Matrix<int> y(3,3);
        Matrix<int> z(8,3);
        
        
        int values_x[] = {17, 24, 1,
            23, 5, 7,
            4, 6, 13,
            10, 12, 19,
            11, 18, 25};
        int values_y[] = {800, 100, 600,
            300, 500, 700,
            400, 900, 200};
        int values_z[] = {17, 24, 1,
            23, 5, 7,
            4, 6, 13,
            10, 12, 19,
            11, 18, 25,
            800, 100, 600,
            300, 500, 700,
            400, 900, 200};
        int k = 0;
        for (int i=0; i<5; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<8; i++){
            for (int j=0; j<3; j++) {
                z[i][j] = values_z[k];
                k++;
            }
        }
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
    
    void test_vertcat_2 () {
        Matrix<int> x(3,3);
        Matrix<int> y(3,3);
        Matrix<int> z(6,3);
        
        int values_x[] = {1, 2, 3,
            7, 8, 9,
            13, 14, 15};
        int values_y[] = {4, 5, 6,
            10, 11, 12,
            16, 17, 18};
        int values_z[] = {1, 2, 3,
            7, 8, 9,
            13, 14, 15,
            4, 5, 6,
            10, 11, 12,
            16, 17, 18};
        int k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<6; i++){
            for (int j=0; j<3; j++) {
                z[i][j] = values_z[k];
                k++;
            }
        }
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
    
    void test_vertcat_3 () {
        Matrix<int> x(3,3);
        Matrix<int> y(3,3);
        Matrix<int> z(6,3);
        
        int values_x[] = {2, 3, 4,
            1, 2, 5,
            4, 6, 13};
        int values_y[] = {9, 6, 8,
            5, 6, 2,
            3, 2, 1};
        int values_z[] = {2, 3, 4,
            1, 2, 5,
            4, 6, 13,
            9, 6, 8,
            5, 6, 2,
            3, 2, 1};
        int k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<6; i++){
            for (int j=0; j<3; j++) {
                z[i][j] = values_z[k];
                k++;
            }
        }
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
        
    void test_vertcat_4() {
        Matrix<int> x(3,3);
        Matrix<int> y(4,4);
        Matrix<int> z(3,6);
        
        try {
            x = vertcat(x,y);
            CPPUNIT_ASSERT(false);
        }
        
        catch (std::invalid_argument) {
            CPPUNIT_ASSERT(true);
        }
    }        
    
    // ---------
    // test_diag
    // ---------
    
    void test_diag_1 () {
        Matrix<int> x(3,3);
        Matrix<int> y(3,1);
        
        int values_x[] = {2, 3, 4,
            1, 2, 5,
            4, 6, 2};
        int values_y[] = {2,
            2,
            2};
        
        int k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<1; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_diag_2 () {
        Matrix<int> x(4,3);
        Matrix<int> y(3,1);
        
        int values_x[] = {100, 0, 0,
            0, -221, 0,
            0, 0, 1212,
            0, 0, 0};
        int values_y[] = {100,
            -221,
            1212};
        
        int k = 0;
        for (int i=0; i<4; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<1; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        CPPUNIT_ASSERT(y.eq(diag(x)));}
    
    void test_diag_3 () {
        Matrix<int> x(3,4);
        Matrix<int> y(3,1);
        
        int values_x[] = {1, 2, 3, 4,
            5, 6, 7, 8,
            9, 10, 11, 12};
        int values_y[] = {1,
            6,
            11};
        
        int k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<4; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<1; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        CPPUNIT_ASSERT(y.eq(diag(x)));}
        
        
    void test_diag_4 () {
        Matrix<int> x(3,1);
        Matrix<int> y(3,3);
        int values_x[] = {1,
                          2,
                          3
        };
        
        int values_y[] = {1, 0, 0,
                          0, 2, 0,
                          0, 0, 3
        };
        
        int k = 0;
          for (int i=0; i<3; i++){
              for (int j=0; j<1; j++) {
                  x[i][j] = values_x[k];
                 k++;
            }
        }

        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
        
    }
    
    void test_diag_5() {
        Matrix<int> x(1,3);
        Matrix<int> y(3,3);
        
        int values_x[] = {1,
                          2,
                          3
        };
        
        int values_y[] = {1, 0, 0,
                          0, 2, 0,
                          0, 0, 3
        };
        
        int k = 0;
          for (int i=0; i<1; i++){
              for (int j=0; j<3; j++) {
                  x[i][j] = values_x[k];
                 k++;
            }
        }
        k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }
    
    // --------
    // test_dot
    // --------
    
    void test_dot_1 () {
        Matrix<int> x(1,3);
        Matrix<int> y(1,3);
        Matrix<int> z(1,1);
        
        int values_x[] = {1, 2, 3,};
        int values_y[] = {4, 5, 6};
        int k = 0;
        for (int i=0; i<1; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<1; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        
        z[0][0] = 32;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
    
    void test_dot_2 () {
        Matrix<int> x(1,3);
        Matrix<int> y(1,3);
        Matrix<int> z(1,1);
        
        int values_x[] = {1, 3, -5,};
        int values_y[] = {4, -2, -1};
        int k = 0;
        for (int i=0; i<1; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<1; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        
        z[0][0] = 3;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
    
    void test_dot_3 () {
        Matrix<int> x(1,2);
        Matrix<int> y(1,2);
        Matrix<int> z(1,1);
        
        int values_x[] = {-2, 3};
        int values_y[] = {4, 6};
        int k = 0;
        for (int i=0; i<1; i++){
            for (int j=0; j<2; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k = 0;
        for (int i=0; i<1; i++){
            for (int j=0; j<2; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        
        z[0][0] = 10;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
        
    void test_dot_4() {
        Matrix<int> x(50,50);
        Matrix<int> y(100,100);
        Matrix<int> z(1,1);
        
        try {
            x = dot(x,y);
            CPPUNIT_ASSERT(false);
        }
        
        catch (std::invalid_argument) {
            CPPUNIT_ASSERT(true);
        }        
      
    }
    
    // --------
    // test_eye
    // --------
    
    void test_eye_1 () {
        Matrix<int> x(2,3);
        Matrix<int> y(2,3);
        
        int values_y[] = {1, 0, 0,
            0, 1, 0};
        
        int k = 0;
        for (int i=0; i<2; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        
        x = eye< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_eye_2 () {
        Matrix<int> x(5,5);
        Matrix<int> y(5,5);
        
        int values_y[] = {1, 0, 0, 0, 0,
            0, 1, 0, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 0, 1, 0,
            0, 0, 0, 0, 1};
        
        int k = 0;
        for (int i=0; i<5; i++){
            for (int j=0; j<5; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        x = eye< Matrix<int> >(5, 5);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_eye_3 () {
        Matrix<int> x(4,3);
        Matrix<int> y(4,3);
        
        int values_y[] = {1, 0, 0,
            0, 1, 0,
            0, 0, 1,
            0, 0, 0};
        
        int k = 0;
        for (int i=0; i<4; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        x = eye< Matrix<int> >(4, 3);
        CPPUNIT_ASSERT(x.eq(y));}
        
        
    void test_eye_4 () {
      Matrix<int> empty;
      Matrix<int> answer;
      
      empty = eye< Matrix<int> >(0, 0);
      CPPUNIT_ASSERT(empty.eq(answer));
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
        Matrix<int> x;
        Matrix<int> y(2,3,1);
        x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_ones_3 () {
        Matrix<int> x;
        Matrix<int> y(4,3,0);
        x = ones< Matrix<int> >(4, 3);
        CPPUNIT_ASSERT(y.eq(x-1));}
    
    // ---------
    // test_rand
    // ---------
    
    void test_rand_1 () {
        Matrix<double> x;
        x = rand< Matrix<double> >(2, 3);
        CPPUNIT_ASSERT(x.size() == 2);}
    
    void test_rand_2 () {
        Matrix<double> x(4,3);
        Matrix<double> y(4,3);
        int values_x[] = {1, 0, 0,
            0, 1, 0,
            0, 0, 1,
            0, 0, 0};
        int values_y[] = {1, 0, 0,
            0, 1, 0,
            0, 0, 1,
            0, 0, 0};
        int k = 0;
        for (int i=0; i<4; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k=0;
        for (int i=0; i<4; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        x = rand< Matrix<double> >(4, 3);
        CPPUNIT_ASSERT(!x.eq(y));}
    
    void test_rand_3 () {
        Matrix<double> x;
        x = rand< Matrix<double> >(1000, 1000);
        Matrix<double> y;
        y = rand< Matrix<double> >(1000, 1000);
        CPPUNIT_ASSERT(!x.eq(y));}
    
    // --------------
    // test_transpose
    // --------------
    
    void test_transpose_1 () {
        Matrix<int> x(1,2);
        Matrix<int> y(2,1);
        
        int values_x[] = {1, 2};
        int values_y[] = {1, 2};
        int k = 0;
        for (int i=0; i<1; i++){
            for (int j=0; j<2; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k=0;
        for (int i=0; i<2; i++){
            for (int j=0; j<1; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_transpose_2 () {
        Matrix<int> x(2,2);
        Matrix<int> y(2,2);
        
        int values_x[] = {1, 2,
                          3, 4};
        int values_y[] = {1, 3,
                          2, 4};
        int k = 0;
        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k=0;
        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        CPPUNIT_ASSERT(x.eq(transpose(y)));}
    
    void test_transpose_3 () {
        Matrix<int> x(3,2);
        Matrix<int> y(2,3);
        
        int values_x[] = {1, 2,
                          3, 4,
                          5, 6,};
        int values_y[] = {1, 3, 5,
                          2, 4, 6};
        int k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<2; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k=0;
        for (int i=0; i<2; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        CPPUNIT_ASSERT(x.eq(transpose(y)));}
    
    // ---------
    // test_tril
    // ---------
    
    void test_tril_1 () {
        Matrix<int> x(4,3);
        Matrix<int> y(4,3);
        
        int values_x[] = {1, 1, 1,
            1, 1, 1,
            1, 1, 1,
            1, 1, 1};
        int values_y[] = {1, 0, 0,
            1, 1, 0,
            1, 1, 1,
            1, 1, 1};
        int k = 0;
        for (int i=0; i<4; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k=0;
        for (int i=0; i<4; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_tril_2 () {
        Matrix<int> x(3,3);
        Matrix<int> y(3,3);
        
        int values_x[] = {1, 2, 8,
                          3, 4, 3,
                          5, 6, 1};
        int values_y[] = {1, 0, 0,
                          3, 4, 0,
                          5, 6, 1};
        int k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k=0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_tril_3 () {
        Matrix<int> x(3,4);
        Matrix<int> y(3,4);
        
        int values_x[] = {1, 2, 3, 4,
                        0, 5, 6, 7,
                        0, 0, 8, 9};
        int values_y[] = {1, 0, 0, 0,
                        0, 5, 0, 0,
                        0, 0, 8, 0};
        int k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<4; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k=0;
        for (int i=0; i<3; i++){
            for (int j=0; j<4; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}
    
    // ---------
    // test_triu
    // ---------
    
    void test_triu_1 () {
        Matrix<int> x(4,3);
        Matrix<int> y(4,3);
        
        int values_x[] = {1, 1, 1,
                          1, 1, 1,
                          1, 1, 1,
                          1, 1, 1};
        int values_y[] = {1, 1, 1,
                          0, 1, 1,
                          0, 0, 1,
                          0, 0, 0};
        int k = 0;
        for (int i=0; i<4; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k=0;
        for (int i=0; i<4; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_triu_2 () {
        Matrix<int> x(3,3);
        Matrix<int> y(3,3);
        
        int values_x[] = {1, 2, 8,
                          3, 4, 3,
                          5, 6, 1};
        int values_y[] = {1, 2, 8,
                          0, 4, 3,
                          0, 0, 1};
        int k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k=0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_triu_3 () {
        Matrix<int> x(3,4);
        Matrix<int> y(3,4);
        
        int values_x[] = {1, 0, 0, 0,
                          2, 5, 0, 0,
                          3, 4, 8, 0};
        int values_y[] = {1, 0, 0, 0,
                          0, 5, 0, 0,
                          0, 0, 8, 0};
        int k = 0;
        for (int i=0; i<3; i++){
            for (int j=0; j<4; j++) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        
        k=0;
        for (int i=0; i<3; i++){
            for (int j=0; j<4; j++) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}
    
    
    // ---------
    // test_zeros
    // ---------
    
    void test_zeros_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_zeros_2 () {
        Matrix<int> x;
        Matrix<int> y(2,3,0);
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_zeros_3 () {
        Matrix<int> x;
        Matrix<int> y(4,3,-1);
        x = zeros< Matrix<int> >(4, 3);
        CPPUNIT_ASSERT(y.eq(x-1));}
    
    // -----
    // suite
    // -----
    
    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat_1);
    CPPUNIT_TEST(test_horzcat_2);
    CPPUNIT_TEST(test_horzcat_3);
    CPPUNIT_TEST(test_horzcat_4);
    CPPUNIT_TEST(test_vertcat_1);
    CPPUNIT_TEST(test_vertcat_2);
    CPPUNIT_TEST(test_vertcat_3);
    CPPUNIT_TEST(test_vertcat_4);
    CPPUNIT_TEST(test_diag_1);
    CPPUNIT_TEST(test_diag_2);
    CPPUNIT_TEST(test_diag_3);
    CPPUNIT_TEST(test_diag_4);
    CPPUNIT_TEST(test_diag_5);
    CPPUNIT_TEST(test_dot_1);
    CPPUNIT_TEST(test_dot_2);
    CPPUNIT_TEST(test_dot_3);
    CPPUNIT_TEST(test_dot_4);    
    CPPUNIT_TEST(test_eye_1);
    CPPUNIT_TEST(test_eye_2);
    CPPUNIT_TEST(test_eye_3);
    CPPUNIT_TEST(test_eye_4);    
    //    CPPUNIT_TEST(test_linsolve);
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