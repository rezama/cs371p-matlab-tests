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
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        Matrix<int> z = horzcat(x, y);

        CPPUNIT_ASSERT(z.size() == 2);
        CPPUNIT_ASSERT(z[0].size() == 4);
        for (int i=0; i < (int)z.size(); i++){
            for (int j=0; j < (int)z[0].size(); j++){
                CPPUNIT_ASSERT(z[i][j] == 1);
            }

        }

    }

    void test_horzcat_2 () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 2);
        Matrix<int> z = horzcat(x, y);

        CPPUNIT_ASSERT(z.size() == 2);
        CPPUNIT_ASSERT(z[0].size() == 4);
        for (int i=0; i < (int)z.size(); i++){
            for (int j=0; j < (int)z[0].size(); j++){
                if (j < 2)
                    CPPUNIT_ASSERT(z[i][j] == 1);
                else
                    CPPUNIT_ASSERT(z[i][j] == 2);
            }

        }

    }

    void test_vertcat_1 () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        Matrix<int> z = vertcat(x, y);

        CPPUNIT_ASSERT(z.size() == 4);
        CPPUNIT_ASSERT(z[0].size() == 2);
        for (int i=0; i < (int)z.size(); i++){
            for (int j=0; j < (int)z[0].size(); j++){
                CPPUNIT_ASSERT(z[i][j] == 1);
            }

        }
    }

    void test_vertcat_2 () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 2);
        Matrix<int> z = vertcat(x, y);

        CPPUNIT_ASSERT(z.size() == 4);
        CPPUNIT_ASSERT(z[0].size() == 2);
        for (int i=0; i < (int)z.size(); i++){
            for (int j=0; j < (int)z[0].size(); j++){
                if (i < 2)
                    CPPUNIT_ASSERT(z[i][j] == 1);
                else
                    CPPUNIT_ASSERT(z[i][j] == 2);
            }

        }

    }

    // ---------
    // test_diag
    // ---------

    void test_diag_1 () {
        Matrix<int> x(2, 2, 2);
        Matrix<int> z = diag(x);

        for (int i=0; i < (int)z.size(); i++){
            for (int j=0; j < (int)z[0].size(); j++){
                if (i == j)
                    CPPUNIT_ASSERT(z[i][j] == 2);
                else
                    CPPUNIT_ASSERT(z[i][j] == 0);
            }
        }
    }

    void test_diag_2 () {
        Matrix<int> x(2, 3, 3);
        Matrix<int> z = diag(x);

        for (int i=0; i < (int)z.size(); i++){
            for (int j=0; j < (int)z[0].size(); j++){
                if (i == j)
                    CPPUNIT_ASSERT(z[i][j] == 3);
                else
                    CPPUNIT_ASSERT(z[i][j] == 0);
            }

        }

        
    }

    // --------
    // test_dot
    // --------

    void test_dot_1 () {
        Matrix<int> x(3, 3, 1);
        Matrix<int> y(3, 3, 1);
        //int z = dot(x, y);
        //assert(z == 9);

    }

    void test_dot_2 () {
        Matrix<int> x(3, 3, 2);
        Matrix<int> y(3, 3, 2);
        //int z = dot(x, y);
        //assert(z == 36);

    }


    // --------
    // test_eye
    // --------

    void test_eye_1 () {
        Matrix<int> x;
        x = eye< Matrix<int> >(2, 3);

        for (int i=0; i < (int)x.size(); i++){
            for (int j=0; j < (int)x[0].size(); j++){
                if (i == j)
                    CPPUNIT_ASSERT(x[i][j] == 1);
                else
                    CPPUNIT_ASSERT(x[i][j] == 0);
            }

        }
    }

    void test_eye_2 () {
        Matrix<int> x;
        x = eye< Matrix<int> >(2, 2);

        for (int i=0; i < (int)x.size(); i++){
            for (int j=0; j < (int)x[0].size(); j++){
                if (i == j)
                    CPPUNIT_ASSERT(x[i][j] == 1);
                else
                    CPPUNIT_ASSERT(x[i][j] == 0);
            }

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
    }
    //    CPPUNIT_ASSERT(x == z);}

    // ---------
    // test_ones
    // ---------

    void test_ones () {
        Matrix<int> x;
        Matrix<int> y;
        x = ones< Matrix<int> >(2, 3);
    }
    //    CPPUNIT_ASSERT(x == y);}

    // ---------
    // test_rand
    // ---------

    void test_rand () {
        Matrix<int> x;
        Matrix<int> y;
        x = rand< Matrix<int> >(2, 3);
    }
    //    CPPUNIT_ASSERT(x == y);}

    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
    }
    //    CPPUNIT_ASSERT(x == y);}

    // ---------
    // test_tril
    // ---------

    void test_tril () {
        Matrix<int> x(2, 2, 2);
        x = tril(x);
    }
    //    CPPUNIT_ASSERT(x == y);}

    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x(2, 2, 2);
        x = triu(x);
    }
    //    CPPUNIT_ASSERT(x == y);}

    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros< Matrix<int> >(2, 3);
    }
    //    CPPUNIT_ASSERT(x == y);}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);

    CPPUNIT_TEST(test_horzcat_1);
    CPPUNIT_TEST(test_horzcat_2);

    CPPUNIT_TEST(test_vertcat_1);
    CPPUNIT_TEST(test_vertcat_2);

    CPPUNIT_TEST(test_diag_1);
    CPPUNIT_TEST(test_diag_2);

    CPPUNIT_TEST(test_eye_1);
    CPPUNIT_TEST(test_eye_2);

    CPPUNIT_TEST(test_linsolve);
    CPPUNIT_TEST(test_ones);
    CPPUNIT_TEST(test_rand);
    CPPUNIT_TEST(test_transpose);
    CPPUNIT_TEST(test_tril);
    CPPUNIT_TEST(test_triu);
    CPPUNIT_TEST(test_zeros);
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
