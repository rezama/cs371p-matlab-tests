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

    void test_horzcat ()
    {
        Matrix<int> x(1,1,0);
        Matrix<int> y(1,1,0);
        Matrix<int> z(1,2,0);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void testHorzCatTrivial ()
    {
        Matrix<int> x(1,1,4);
        Matrix<int> y(1,1,4);
        Matrix<int> z(1,2,4);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void testHorzCatEmpty ()
    {
        Matrix<int> x(0,0,0);
        Matrix<int> y(0,0,0);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.size() == 0);
    }

    void testHorzCatException ()
    {
        try{
            Matrix<int> x(2,1,4);
            Matrix<int> y(1,1,4);
        
            x = horzcat(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch(IllegalMatrixDimensionException){
            CPPUNIT_ASSERT(true);
        }
    }

    void test_vertcat () {
        Matrix<int> x(1,1,0);
        Matrix<int> y(1,1,0);
        Matrix<int> z(2,1,0);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void testVertCatTrivial ()
    {
        Matrix<int> x(2,2,4);
        Matrix<int> y(2,2,4);
        Matrix<int> z(4,2,4);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void testVertCatEmpty ()
    {
        Matrix<int> x(0,0);
        Matrix<int> y(0,0);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.size() == 0);
    }

    void testVertCatException ()
    {
        try{
            Matrix<int> x(2,2,4);
            Matrix<int> y(1,1,4);
        
            x = vertcat(x, y);
            CPPUNIT_ASSERT(false);
        }
        catch(IllegalMatrixDimensionException){
            CPPUNIT_ASSERT(true);
        }
    }

    // ---------
    // test_diag
    // ---------

    void test_diag () {
        Matrix<int> x(1,1,1);
        Matrix<int> y(1,1,1);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void testDiagTrivial () {
        Matrix<int> x(1,1,0);
        Matrix<int> y(1,1,0);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void testDiagSquare () {
        Matrix<int> x(3,3,3);
        x = diag(x);
        CPPUNIT_ASSERT(x.size() == 3);
        CPPUNIT_ASSERT(x[0][0] == 3);
        CPPUNIT_ASSERT(x[1][0] == 3);
        CPPUNIT_ASSERT(x[2][0] == 3);
    }

    void testDiagRectangle () {
        Matrix<int> x(4,5,1);
        x = diag(x);
        CPPUNIT_ASSERT(x.size() == 4);
        CPPUNIT_ASSERT(x[0][0] == 1);
        CPPUNIT_ASSERT(x[1][0] == 1);
        CPPUNIT_ASSERT(x[2][0] == 1);
        CPPUNIT_ASSERT(x[3][0] == 1);
    }

    void testDiagRectangleMoreRows () {
        Matrix<int> x(5,4,1);
        x = diag(x);
        CPPUNIT_ASSERT(x.size() == 5);
        CPPUNIT_ASSERT(x[0][0] == 1);
        CPPUNIT_ASSERT(x[1][0] == 1);
        CPPUNIT_ASSERT(x[2][0] == 1);
        CPPUNIT_ASSERT(x[3][0] == 1);
        CPPUNIT_ASSERT(x[4][0] == 0);
    }

    // --------
    // test_dot
    // --------

    void test_dot () {
        Matrix<int> x(1,1,2);
        Matrix<int> y(1,1,2);
        Matrix<int> z(1,1,4);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void testDotTrivial () {
        Matrix<int> x(3,3);
        x[0][0] = 8;
        x[0][1] = 1;
        x[0][2] = 6;
        x[1][0] = 3;
        x[1][1] = 5;
        x[1][2] = 7;
        x[2][0] = 4;
        x[2][1] = 9;
        x[2][2] = 2;
        Matrix<int> x1(3,3);
        x1[0][0] = 8;
        x1[0][1] = 1;
        x1[0][2] = 6;
        x1[1][0] = 3;
        x1[1][1] = 5;
        x1[1][2] = 7;
        x1[2][0] = 4;
        x1[2][1] = 9;
        x1[2][2] = 2;

        Matrix<int> x2(1,3);
        x2[0][0] = 89;
        x2[0][1] = 107;
        x2[0][2] = 89;

        x = dot(x, x1);

        CPPUNIT_ASSERT(x.eq(x2));
    }

    void testDotException () {
        Matrix<int> x(2,3);
        x[0][0] = 8;
        x[0][1] = 1;
        x[0][2] = 6;
        x[1][0] = 3;
        x[1][1] = 5;
        x[1][2] = 7;
        Matrix<int> x1(3,3);
        x1[0][0] = 8;
        x1[0][1] = 1;
        x1[0][2] = 6;
        x1[1][0] = 3;
        x1[1][1] = 5;
        x1[1][2] = 7;
        x1[2][0] = 4;
        x1[2][1] = 9;
        x1[2][2] = 2;

        Matrix<int> x2(1,3);
        x2[0][0] = 89;
        x2[0][1] = 107;
        x2[0][2] = 89;
        try{
            x = dot(x, x1);
            CPPUNIT_ASSERT(false);
        }
        catch(IllegalMatrixDimensionException)
        {
            CPPUNIT_ASSERT(true);
        }
        
    }

    void testDotSizeException () {
        Matrix<int> x;
        Matrix<int> x1(3,3);
        x1[0][0] = 8;
        x1[0][1] = 1;
        x1[0][2] = 6;
        x1[1][0] = 3;
        x1[1][1] = 5;
        x1[1][2] = 7;
        x1[2][0] = 4;
        x1[2][1] = 9;
        x1[2][2] = 2;

        Matrix<int> x2(1,3);
        x2[0][0] = 89;
        x2[0][1] = 107;
        x2[0][2] = 89;
        try{
            x = dot(x, x1);
            CPPUNIT_ASSERT(false);
        }
        catch(IllegalMatrixDimensionException)
        {
            CPPUNIT_ASSERT(true);
        }
        
    }

    // --------
    // test_eye
    // --------

    void test_eye () {

        Matrix<int> x = eye< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.size() == 0);
    }

    void testEyeTrivial () {
        Matrix<int> x = eye< Matrix<int> >(1, 1);
        Matrix<int> z(1,1,1);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void testEyeSquare () {
        Matrix<int> x = eye< Matrix<int> >(3, 3);
        Matrix<int> x1(3,3);
        x1[0][0] = 1;
        x1[0][1] = 0;
        x1[0][2] = 0;
        x1[1][0] = 0;
        x1[1][1] = 1;
        x1[1][2] = 0;
        x1[2][0] = 0;
        x1[2][1] = 0;
        x1[2][2] = 1;
        CPPUNIT_ASSERT(x.eq(x1));
    }

    void testEyeRectangle () {
        Matrix<int> x = eye< Matrix<int> >(3, 2);
        Matrix<int> x1(3,2);
        x1[0][0] = 1;
        x1[0][1] = 0;
        x1[1][0] = 0;
        x1[1][1] = 1;
        x1[2][0] = 0;
        x1[2][1] = 0;
        CPPUNIT_ASSERT(x.eq(x1));
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

    void test_ones () {
        Matrix<int> y(2,3,1);
        Matrix<int> x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void testOnesTrivial () {
        Matrix<int> x = ones< Matrix<int> >(1,1);
        Matrix<int> y(1,1,1);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void testOnesSquare () {
        Matrix<int> x = ones< Matrix<int> >(3,3);
        Matrix<int> y(3,3,1);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void testOnesRectangle () {
        Matrix<int> x = ones< Matrix<int> >(40,30);
        Matrix<int> y(40,30,1);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_rand
    // ---------

    void test_rand () {
        Matrix<int> x;
        x = rand< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.size()==0);
    }

    void testRandTrivial () {
        Matrix<double> x = rand< Matrix<double> >(1,1);
        CPPUNIT_ASSERT(x[0][0] > 0 && x[0][0] < 1);
    }

    void testRandSquare () {
        Matrix<double> x = rand< Matrix<double> >(2,2);
        CPPUNIT_ASSERT(x[0][0] > 0 && x[0][0] < 1);
        CPPUNIT_ASSERT(x[0][1] > 0 && x[0][1] < 1);
        CPPUNIT_ASSERT(x[1][0] > 0 && x[1][0] < 1);
        CPPUNIT_ASSERT(x[1][1] > 0 && x[1][1] < 1);
    }

    void testRandRectangle () {
        Matrix<double> x = rand< Matrix<double> >(3,2);
        CPPUNIT_ASSERT(x[0][0] > 0 && x[0][0] < 1);
        CPPUNIT_ASSERT(x[0][1] > 0 && x[0][1] < 1);
        CPPUNIT_ASSERT(x[1][0] > 0 && x[1][0] < 1);
        CPPUNIT_ASSERT(x[1][1] > 0 && x[1][1] < 1);
        CPPUNIT_ASSERT(x[2][0] > 0 && x[2][0] < 1);
        CPPUNIT_ASSERT(x[2][1] > 0 && x[2][1] < 1);
    }

    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.size() == 0);
    }

    void testTransposeTrivial()
    {
        Matrix<int> x(2,2);
        x[0][0] = 12;
        x[0][1] = 4;
        x[1][0] = 3;
        x[1][1] = 12;
        Matrix<int> x1(2,2);
        x1[0][0] = 12;
        x1[0][1] = 3;
        x1[1][0] = 4;
        x1[1][1] = 12;
        x1 = transpose(x1);
        CPPUNIT_ASSERT(x.eq(x1));
    }

    void testTransposeSquare()
    {
        Matrix<int> x(3,3);
        x[0][0] = 12;
        x[0][1] = 1;
        x[0][2] = 2;
        x[1][0] = 3;
        x[1][1] = 12;
        x[1][2] = 1;
        x[2][0] = 2;
        x[2][1] = 3;
        x[2][2] = 12;
        Matrix<int> x1(3,3);
        x1[0][0] = 12;
        x1[0][1] = 3;
        x1[0][2] = 2;
        x1[1][0] = 1;
        x1[1][1] = 12;
        x1[1][2] = 3;
        x1[2][0] = 2;
        x1[2][1] = 1;
        x1[2][2] = 12;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(x1));
    }

    void testTransposeRectangle()
    {
        Matrix<int> x(3,2);
        x[0][0] = 12;
        x[0][1] = 2;
        x[1][0] = 3;
        x[1][1] = 12;
        x[2][0] = 2;
        x[2][1] = 3;
        Matrix<int> x1(2,3);
        x1[0][0] = 12;
        x1[0][1] = 3;
        x1[0][2] = 2;
        x1[1][0] = 2;
        x1[1][1] = 12;
        x1[1][2] = 3;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(x1));
    }

    // ---------
    // test_tril
    // ---------

    void test_tril () {
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.size() == 0);
    }

    void testTrilTrivial()
    {
        Matrix<int> x = eye<Matrix<int> >(2,2);
        Matrix<int> y = eye<Matrix<int> >(2,2);
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void testTrilSquare()
    {
        Matrix<int> x(3,3);
        x[0][0] = 12;
        x[0][1] = 1;
        x[0][2] = 2;
        x[1][0] = 3;
        x[1][1] = 12;
        x[1][2] = 1;
        x[2][0] = 2;
        x[2][1] = 3;
        x[2][2] = 12;
        Matrix<int> x1(3,3);
        x1[0][0] = 12;
        x1[0][1] = 0;
        x1[0][2] = 0;
        x1[1][0] = 3;
        x1[1][1] = 12;
        x1[1][2] = 0;
        x1[2][0] = 2;
        x1[2][1] = 3;
        x1[2][2] = 12;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(x1));
    }

    void testTrilRectangle()
    {
        Matrix<int> x(3,2);
        x[0][0] = 12;
        x[0][1] = 1;
        x[1][0] = 3;
        x[1][1] = 12;
        x[2][0] = 2;
        x[2][1] = 3;
        Matrix<int> x1(3,2);
        x1[0][0] = 12;
        x1[0][1] = 0;
        x1[1][0] = 3;
        x1[1][1] = 12;
        x1[2][0] = 2;
        x1[2][1] = 3;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(x1));
    }

    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.size() == 0);
    }

    void testTriuTrivial()
    {
        Matrix<int> x = eye<Matrix<int> >(2,2);
        Matrix<int> y = eye<Matrix<int> >(2,2);
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void testTriuSquare()
    {
        Matrix<int> x(3,3);
        x[0][0] = 12;
        x[0][1] = 1;
        x[0][2] = 2;
        x[1][0] = 3;
        x[1][1] = 12;
        x[1][2] = 1;
        x[2][0] = 2;
        x[2][1] = 3;
        x[2][2] = 12;
        Matrix<int> x1(3,3);
        x1[0][0] = 12;
        x1[0][1] = 1;
        x1[0][2] = 2;
        x1[1][0] = 0;
        x1[1][1] = 12;
        x1[1][2] = 1;
        x1[2][0] = 0;
        x1[2][1] = 0;
        x1[2][2] = 12;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(x1));
    }

    void testTriuRectangle()
    {
        Matrix<int> x(3,2);
        x[0][0] = 12;
        x[0][1] = 1;
        x[1][0] = 3;
        x[1][1] = 12;
        x[2][0] = 2;
        x[2][1] = 3;
        Matrix<int> x1(3,2);
        x1[0][0] = 12;
        x1[0][1] = 1;
        x1[1][0] = 0;
        x1[1][1] = 12;
        x1[2][0] = 0;
        x1[2][1] = 0;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(x1));
    }

    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x;
        Matrix<int> y(2,3,0);
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void testZerosTrivial () {
        Matrix<int> x = zeros< Matrix<int> >(1,1);
        Matrix<int> y(1,1,0);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void testZerosSquare () {
        Matrix<int> x = zeros< Matrix<int> >(3,3);
        Matrix<int> y(3,3,0);
        CPPUNIT_ASSERT(x.eq(y));
    }

    void testZerosRectangle () {
        Matrix<int> x = zeros< Matrix<int> >(40,30);
        Matrix<int> y(40,30,0);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);

    // ----------
    // testHorzcat
    // ----------
    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(testHorzCatTrivial);
    CPPUNIT_TEST(testHorzCatEmpty);
    CPPUNIT_TEST(testHorzCatException);
    // ----------
    // testVertcat
    // ----------
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(testVertCatTrivial);
    CPPUNIT_TEST(testVertCatEmpty);
    CPPUNIT_TEST(testVertCatException);

    // ----------
    // testDiag
    // ----------
    CPPUNIT_TEST(test_diag);
    CPPUNIT_TEST(testDiagTrivial);
    CPPUNIT_TEST(testDiagSquare);
    CPPUNIT_TEST(testDiagRectangle);
    CPPUNIT_TEST(testDiagRectangleMoreRows);

    // --------
    // test_dot
    // --------

    CPPUNIT_TEST(test_dot);
    CPPUNIT_TEST(testDotTrivial);
    CPPUNIT_TEST(testDotException);
    CPPUNIT_TEST(testDotSizeException);


    // ----------
    // testEye
    // ----------
    CPPUNIT_TEST(test_eye);
    CPPUNIT_TEST(testEyeTrivial);
    CPPUNIT_TEST(testEyeSquare);
    CPPUNIT_TEST(testEyeRectangle);

    // CPPUNIT_TEST(test_linsolve);

    // ----------
    // testOnes
    // ----------
    CPPUNIT_TEST(test_ones);
    CPPUNIT_TEST(testOnesTrivial);
    CPPUNIT_TEST(testOnesSquare);
    CPPUNIT_TEST(testOnesRectangle);
    // ----------
    // testRand
    // ----------
    CPPUNIT_TEST(test_rand);
    CPPUNIT_TEST(testRandTrivial);
    CPPUNIT_TEST(testRandSquare);
    CPPUNIT_TEST(testRandRectangle);
    // ----------
    // testTranspose
    // ----------
    CPPUNIT_TEST(test_transpose);
    CPPUNIT_TEST(testTransposeTrivial);
    CPPUNIT_TEST(testTransposeSquare);
    CPPUNIT_TEST(testTransposeRectangle);
    // ----------
    // testTril
    // ----------
    CPPUNIT_TEST(test_tril);
    CPPUNIT_TEST(testTrilTrivial);
    CPPUNIT_TEST(testTrilSquare);
    CPPUNIT_TEST(testTrilRectangle);
    // ----------
    // testtriu
    // ----------
    CPPUNIT_TEST(test_triu);
    CPPUNIT_TEST(testTriuTrivial);
    CPPUNIT_TEST(testTriuSquare);
    CPPUNIT_TEST(testTriuRectangle);
    // ----------
    // testZeros
    // ----------
    CPPUNIT_TEST(test_zeros);
    CPPUNIT_TEST(testZerosTrivial);
    CPPUNIT_TEST(testZerosSquare);
    CPPUNIT_TEST(testZerosRectangle);
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