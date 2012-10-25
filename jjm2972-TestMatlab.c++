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
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
    void test_horzcat_1(){

        Matrix<int> x(10, 8, 0);
        Matrix<int> y(10, 2, 0);
        Matrix<int> z(10, 10, 0);
        Matrix<int> w;
            w = horzcat(x, y);
            CPPUNIT_ASSERT(w.eq(z));
        }
    void test_horzcat_2(){
        Matrix<int> x(1, 1, 0);
        Matrix<int> y(1, 1, 0);
        Matrix<int> z(1, 2, 0);
        Matrix<int> w;
            w = horzcat(x, y);
            CPPUNIT_ASSERT(w.eq(z));
        }

    void test_horzcat_3(){
        Matrix<bool> x(1, 4, true);
        Matrix<bool> y(1, 1, false);
        Matrix<bool> z(1, 5, true);
        z[0][4]=false;
        Matrix<bool> w;
            w = horzcat(x, y);
            CPPUNIT_ASSERT(w.eq(z));
        }
    void test_vertcat () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
    void test_vertcat_1(){

        Matrix<int> x(8, 10, 0);
        Matrix<int> y(2, 10, 0);
        Matrix<int> z(10, 10, 0);
        Matrix<int> w;
            w = vertcat(x, y);
            CPPUNIT_ASSERT(w.eq(z));
        }
    void test_vertcat_2(){
        Matrix<int> x(1, 1, 0);
        Matrix<int> y(1, 1, 0);
        Matrix<int> z(2, 1, 0);
        Matrix<int> w;
            w = vertcat(x, y);
            CPPUNIT_ASSERT(w.eq(z));
        }

    void test_vertcat_3(){
        Matrix<bool> x(4, 1, true);
        Matrix<bool> y(1, 1, false);
        Matrix<bool> z(5, 1, true);
        z[4][0]=false;
        Matrix<bool> w;
            w = vertcat(x, y);
            CPPUNIT_ASSERT(w.eq(z));
        }

    // ---------
    // test_diag
    // ---------
    void test_diag_1(){
    std::vector<int> x(3,2);
    Matrix<int> y = diag(x);
    CPPUNIT_ASSERT(y.size()==3);
    CPPUNIT_ASSERT(y.front().size()==3);

    }
    void test_diag_2(){
    std::vector<int> x(3,2);
    Matrix<int> y = diag(x);
    CPPUNIT_ASSERT(y[0][0] = 2);
    }
    void test_diag_3(){
    std::vector<int> x(3,2);
    Matrix<int> y = diag(x);
    CPPUNIT_ASSERT(y[1][2] == 0);
    }
    void test_diag_4(){
    std::vector<int> x(3,2);
    Matrix<int> y = diag(x,1);
    CPPUNIT_ASSERT(y.size()==4);
    CPPUNIT_ASSERT(y.front().size()==4);
    }
    void test_diag_5(){
    std::vector<int> x(3,2);
    Matrix<int> y = diag(x,-1);
    CPPUNIT_ASSERT(y.size()==4);
    CPPUNIT_ASSERT(y.front().size()==4);
    }
    void test_diag_6(){
    std::vector<int> x(3,2);
    Matrix<int> y = diag(x,1);
    CPPUNIT_ASSERT(y[0][1]==2);
    CPPUNIT_ASSERT(y[2][2]==0);
    }
    void test_diag_7(){
	 Matrix<int> y (3,3,2);
    std::vector<int> x = diag(y);
    CPPUNIT_ASSERT(x.size()==3);
    }
    void test_diag_8(){
	 Matrix<int> y (3,3,2);
    std::vector<int> x = diag(y);
    CPPUNIT_ASSERT(x[1] == 2);
    }
    void test_diag_9(){
	 Matrix<int> y (3,3,2);
    y[1][1] = 5;
    std::vector<int> x = diag(y);
    CPPUNIT_ASSERT(x[1] ==5);
    }
    void test_diag_10(){
	 Matrix<int> y(3,3,2);
    y[1][1] = 5;
    std::vector<int> x = diag(y,1);
    CPPUNIT_ASSERT(x.size()==2);
    }
    void test_diag_11(){
	 Matrix<int> y(3,3,2);
    y[1][1] = 5;
    std::vector<int> x = diag(y, 1);
    CPPUNIT_ASSERT(x[1] ==2);
    }
    void test_diag_12(){
	 Matrix<int> y(3,3,2);
    y[1][0] = 5;
    std::vector<int> x = diag(y,-1);
    CPPUNIT_ASSERT(x[0] ==5);
    }
    // --------
    // test_dot
    // --------
    void test_dot_1(){
    std::vector<int> x(3,3);
    std::vector<int> y(3,3);
    CPPUNIT_ASSERT(dot(x,y)==27);

    }
    void test_dot_2(){
    std::vector<int> x(3,1);
    std::vector<int> y(3,3);
    CPPUNIT_ASSERT(dot(x,y)==9);

    }
    void test_dot_3(){
    std::vector<int> x(2,3);
    std::vector<int> y(2,9);
    CPPUNIT_ASSERT(dot(x,y)==54);

    }

    // --------
    // test_eye
    // --------
    void test_eye_1(){
    Matrix<int> x = eye(3,3);
    CPPUNIT_ASSERT(x[1][1] == 1);

    }
    void test_eye_2(){
    Matrix<int> x = eye(3,3);
    CPPUNIT_ASSERT(x[0][1] == 0);

    }
    void test_eye_3(){
    Matrix<int> x = eye(3,4);
    CPPUNIT_ASSERT(x[1][1] == 1);
    CPPUNIT_ASSERT(x[2][3] == 0);

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
    void test_ones_1(){
    Matrix<int> x = ones(2,2);
    CPPUNIT_ASSERT(x[0][0] == 1);
 
    }
    void test_ones_2(){
    Matrix<int> x = ones(2,2);
    CPPUNIT_ASSERT(x[0][1] == 1);
 
    }
    void test_ones_3(){
    Matrix<int> x = ones(2,2);
    CPPUNIT_ASSERT(x[1][1] == 1);
 
    }
    // ---------
    // test_rand
    // ---------
    void test_rand_1(){
    Matrix<double> x = rand(4,4);
    CPPUNIT_ASSERT(x[1][1]<1);
    }
    void test_rand_2(){
    Matrix<double> x = rand(4,4);
    CPPUNIT_ASSERT(x[1][1]!=x[2][2]);
    }
    void test_rand_3(){
    Matrix<double> x = rand(4,4);
    CPPUNIT_ASSERT(x[1][1] > 0);
    }
    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}
    void test_transpose_1 () {
        Matrix<int> x(2,2,2);
        Matrix<int> y(2,2,2);
        x[0][1]=1;
        y[1][0]=1;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}
    void test_transpose_2 () {
        Matrix<int> x(2,3,2);
        x = transpose(x);
        CPPUNIT_ASSERT(x.size()==3);
        CPPUNIT_ASSERT(x.front().size()==2);}
    void test_transpose_3 () {
        Matrix<int> x(1,3,2);
        x = transpose(x);
        CPPUNIT_ASSERT(x.size()==3);}

    // ---------
    // test_tril
    // ---------

    void test_tril () {
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}
    void test_tril_1 () {
        Matrix<int> x(2,2,2);
        Matrix<int> y(2,2,2);
        y[0][1]=0;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}
    void test_tril_2 () {
        Matrix<int> x(3,3,3);
        x = tril(x);
        CPPUNIT_ASSERT(x[2][2] == 3);
        CPPUNIT_ASSERT(x[1][2] == 0);}
    void test_tril_3 () {
        Matrix<int> x(4,4,4);
        x = tril(x);
        CPPUNIT_ASSERT(x[1][1] == 4);
        CPPUNIT_ASSERT(x[2][1] == 4);
        CPPUNIT_ASSERT(x[2][3] == 0);}
    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}
    void test_triu_1 () {
        Matrix<int> x(2,2,2);
        Matrix<int> y(2,2,2);
        y[1][0]=0;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}
    void test_triu_2 () {
        Matrix<int> x(3,3,3);
        x = triu(x);
        CPPUNIT_ASSERT(x[2][2] == 3);
        CPPUNIT_ASSERT(x[2][1] == 0);}
    void test_triu_3 () {
        Matrix<int> x(4,4,4);
        x = triu(x);
        CPPUNIT_ASSERT(x[1][1] == 4);
        CPPUNIT_ASSERT(x[1][2] == 4);
        CPPUNIT_ASSERT(x[3][2] == 0);}
    // ----------
    // test_zeros
    // ----------
    void test_zeros_1(){
	 Matrix<int> x = zeros(2,3);
        CPPUNIT_ASSERT(x[1][1] == 0);
        CPPUNIT_ASSERT(x[1][2] == 0);
        CPPUNIT_ASSERT(x[1][0] == 0);
    
    }
    void test_zeros_2(){
	 Matrix<int> x = zeros(4,3);
        CPPUNIT_ASSERT(x[2][1] == 0);
        CPPUNIT_ASSERT(x[3][2] == 0);
        CPPUNIT_ASSERT(x[0][0] == 0);
    
    }
    void test_zeros_3(){
	 Matrix<int> x = zeros(15,33);
        CPPUNIT_ASSERT(x[12][30] == 0);
        CPPUNIT_ASSERT(x[6][15] == 0);
        CPPUNIT_ASSERT(x[2][27] == 0);
    
    }


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(test_horzcat_1);
    CPPUNIT_TEST(test_horzcat_2);
    CPPUNIT_TEST(test_horzcat_3);
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(test_vertcat_1);
    CPPUNIT_TEST(test_vertcat_2);
    CPPUNIT_TEST(test_vertcat_3);
    CPPUNIT_TEST(test_diag_1);
    CPPUNIT_TEST(test_diag_2);
    CPPUNIT_TEST(test_diag_3);
    CPPUNIT_TEST(test_diag_4);
    CPPUNIT_TEST(test_diag_5);
    CPPUNIT_TEST(test_diag_6);
    CPPUNIT_TEST(test_diag_7);
    CPPUNIT_TEST(test_diag_8);
    CPPUNIT_TEST(test_diag_9);
    CPPUNIT_TEST(test_diag_10);
    CPPUNIT_TEST(test_diag_11);
    CPPUNIT_TEST(test_diag_12);
    CPPUNIT_TEST(test_dot_1);
    CPPUNIT_TEST(test_dot_2);
    CPPUNIT_TEST(test_dot_3);
    CPPUNIT_TEST(test_eye_1);
    CPPUNIT_TEST(test_eye_2);
    CPPUNIT_TEST(test_eye_3);
    CPPUNIT_TEST(test_ones_1);
    CPPUNIT_TEST(test_ones_2);
    CPPUNIT_TEST(test_ones_3);
    CPPUNIT_TEST(test_rand_1);
    CPPUNIT_TEST(test_rand_2);
    CPPUNIT_TEST(test_rand_3);
    CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_transpose);
    CPPUNIT_TEST(test_transpose_1);
    CPPUNIT_TEST(test_transpose_2);
    CPPUNIT_TEST(test_transpose_3);
    CPPUNIT_TEST(test_tril);
    CPPUNIT_TEST(test_tril_1);
    CPPUNIT_TEST(test_tril_2);
    CPPUNIT_TEST(test_tril_3);
    CPPUNIT_TEST(test_triu);
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