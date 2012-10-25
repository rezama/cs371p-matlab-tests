// ------------------------------
// projects/matlab/TestMatrix.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
 * To test the program:
 *     g++ TestMatrix.c++ -ansi -pedantic -lcppunit -ldl -Wall  -o TestMatrix.app
 *     valgrind TestMatrix.app >& TestMatrix.out
 */

// --------
// includes
// --------

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Matrix.h" // Matrix class
#include <stdexcept>  // for STL exceptions

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
        CPPUNIT_ASSERT(x.size() == 0);;
    }

    // ----------
    // test_index
    // ----------

    void test_index () {
        const Matrix<int> x(1, 1, 0);
        CPPUNIT_ASSERT(x[0][0] == 0);}

    void test_index2 () {
        Matrix<int> x(10, 10, 0);
        x[5][5] = 5;
        CPPUNIT_ASSERT(x[5][5] == 5);}

    void test_index3 () {
        const Matrix<double> x(1, 1, .99);
        CPPUNIT_ASSERT(x[0][0] == .99);}

    void test_index4 () {
    	//throw exception when accessing non existant index
        Matrix<double> x(1, 1, .99);
        bool excpthrown = false;
        try {
        	x[2][2];
        }
        catch (std::out_of_range& e) {
        	excpthrown = true;
        }
        CPPUNIT_ASSERT(excpthrown == true);}

    void test_index5 () {
    	//no row/column constructing
        const Matrix<double> x(5, 1, .99);
        CPPUNIT_ASSERT(x[0][0] == .99);}

    // -----------
    // test_equals
    // -----------

    void test_equals () {
        Matrix<int>  x(5, 5, 0);
        Matrix<int>  y(5, 5, 0);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_equals2 () {
        Matrix<bool> z(5, 5, true);
        Matrix<bool> t(5, 5, true);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_equals3 () {//different size
        Matrix<bool> z(5, 5, true);
        Matrix<bool> t(5, 6, true);
        CPPUNIT_ASSERT(!z.eq(t));}

    void test_equals4 () {
        Matrix<bool> z(6, 5, true);
        Matrix<bool> t(5, 5, true);
        CPPUNIT_ASSERT(!z.eq(t));}

    void test_equals5 () {//different elements
        Matrix<unsigned> z(5, 5, -1);
        Matrix<unsigned> t(5, 5, 1);
        CPPUNIT_ASSERT(!z.eq(t));}

    void test_equals6 () {
        Matrix<int>  x(5, 5, 0);
        Matrix<int>  y(5, 5, 0);
        x[0][0] = y[0][0] = 1;
        x[4][4] = y[4][4] = -1;
        CPPUNIT_ASSERT(x.eq(y));}

    void test_equals7 () {
        Matrix<int>  x(5, 5, 0);

        CPPUNIT_ASSERT(x.eq(x));}

    void test_equals8 () {
        Matrix<int>  x;
        Matrix<int>  y;
        CPPUNIT_ASSERT(x.eq(y));}

    void test_equals9 () {
        Matrix<int>  x(1, 0, 1);
        Matrix<int>  y(1, 0, 1);
        CPPUNIT_ASSERT(x.eq(y));}
    // -----------
    // test_eqeq (==)
    // -----------
    void test_eqeq () {
        Matrix<int>  x(1, 1, 0);
        Matrix<int>  y(1, 1, 0);
        //x.print();
        Matrix<bool> equivalence = x == y;
        Matrix<bool> expected(1, 1, true);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    void test_eqeq2 () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);

        Matrix<bool> equivalence = x == y;
        Matrix<bool> expected(1, 1, false);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    void test_eqeq3 () {
        Matrix<int>  x(5, 5, 200);
        Matrix<int>  y(5, 5, 200);

        Matrix<bool> equivalence = x == y;
        Matrix<bool> expected(5, 5, true);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    // -----------
    // test_diff (!=)
    // -----------
    void test_diff () {
        Matrix<int>  x(1, 1, 0);
        Matrix<int>  y(1, 1, 0);
        //x.print();
        Matrix<bool> equivalence = x != y;
        Matrix<bool> expected(1, 1, false);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    void test_diff2 () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);

        Matrix<bool> equivalence = x != y;
        Matrix<bool> expected(1, 1, true);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    void test_diff3 () {
        Matrix<int>  x(5, 5, 200);
        Matrix<int>  y(5, 5, 200);

        Matrix<bool> equivalence = x != y;
        Matrix<bool> expected(5, 5, false);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    // --------------
    // test_less_than (<)
    // --------------

    void test_less_than () {
        Matrix<int>  x(1, 1, 0);
        Matrix<int>  y(1, 1, 1);
        //x.print();
        Matrix<bool> equivalence = x < y;
        Matrix<bool> expected(1, 1, true);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    void test_less_than2  () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);

        Matrix<bool> equivalence = x < y;
        Matrix<bool> expected(1, 1, false);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    void test_less_than3  () {
        Matrix<int>  x(5, 5, 200);
        Matrix<int>  y(5, 5, 200);

        Matrix<bool> equivalence = x < y;
        Matrix<bool> expected(5, 5, false);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    // --------------
    // test_lesseq (<)
    // --------------

    void test_lesseq () {
        Matrix<int>  x(1, 1, 0);
        Matrix<int>  y(1, 1, 1);
        //x.print();
        Matrix<bool> equivalence = x <= y;
        Matrix<bool> expected(1, 1, true);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    void test_lesseq2  () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);

        Matrix<bool> equivalence = x <= y;
        Matrix<bool> expected(1, 1, false);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    void test_lesseq3  () {
        Matrix<int>  x(5, 5, 200);
        Matrix<int>  y(5, 5, 200);

        Matrix<bool> equivalence = x <= y;
        Matrix<bool> expected(5, 5, true);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    // --------------
    // test_greater_than (>)
    // --------------

    void test_greater_than () {
        Matrix<int>  x(1, 1, 0);
        Matrix<int>  y(1, 1, 1);
        //x.print();
        Matrix<bool> equivalence = x > y;
        Matrix<bool> expected(1, 1, false);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    void test_greater_than2  () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);

        Matrix<bool> equivalence = x > y;
        Matrix<bool> expected(1, 1, true);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    void test_greater_than3  () {
        Matrix<int>  x(5, 5, 200);
        Matrix<int>  y(5, 5, 200);

        Matrix<bool> equivalence = x > y;
        Matrix<bool> expected(5, 5, false);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    // --------------
    // test_greateq (>=)
    // --------------

    void test_greateq () {
        Matrix<int>  x(1, 1, 0);
        Matrix<int>  y(1, 1, 1);
        //x.print();
        Matrix<bool> equivalence = x >= y;
        Matrix<bool> expected(1, 1, false);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    void test_greateq2  () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 0);

        Matrix<bool> equivalence = x >= y;
        Matrix<bool> expected(1, 1, true);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    void test_greateq3  () {
        Matrix<int>  x(5, 5, 200);
        Matrix<int>  y(5, 5, 200);

        Matrix<bool> equivalence = x >= y;
        Matrix<bool> expected(5, 5, true);

        CPPUNIT_ASSERT(equivalence.eq(expected));}

    // --------------
    // test_pluseqc (+=) constants
    // --------------

    void test_pluseqc () {
        Matrix<int>  x(1, 1, 0);

        x+=1;
        Matrix<int> expected(1, 1, 1);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_pluseqc2  () {
        Matrix<int>  x(1, 1, 0);

        x+=6;
        Matrix<int> expected(1, 1, 6);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_pluseqc3  () {
        Matrix<int>  x(10, 10, 0);

        x[5][5] = 4;
        x+=6;
        Matrix<int> expected(10, 10, 6);
        expected[5][5] += 4;

        CPPUNIT_ASSERT(x.eq(expected));}

    // --------------
    // test_pluseq (+=)
    // --------------

    void test_pluseq () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 1);

        x+=y;
        Matrix<int> expected(1, 1, 2);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_pluseq2  () {
        Matrix<int>  x(1, 1, 13);
        Matrix<int>  y(1, 1, 31);

        x+=y;
        Matrix<int> expected(1, 1, 44);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_pluseq3  () {
        Matrix<int>  x(10, 10, 0);
        Matrix<int>  y(10, 10, 10);

        x[5][5] = 4;
        x+=y;
        Matrix<int> expected(10, 10, 10);
        expected[5][5] = 14;

        CPPUNIT_ASSERT(x[0][0] == 10 && x.eq(expected));}

    // --------------
    // test_minuseqc (-=) constants
    // --------------

    void test_minuseqc () {
        Matrix<int>  x(1, 1, 1);

        x-=1;
        Matrix<int> expected(1, 1, 0);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_minuseqc2  () {
        Matrix<int>  x(1, 1, 10);

        x-=6;
        Matrix<int> expected(1, 1, 4);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_minuseqc3  () {
        Matrix<int>  x(10, 10, 6);

        x[5][5] = 10;
        x-=6;
        Matrix<int> expected(10, 10, 0);
        expected[5][5] = 4;

        CPPUNIT_ASSERT(x.eq(expected));}

    // --------------
    // test_minuseq (*=)
    // --------------

    void test_minuseq () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 1);

        x-=y;
        Matrix<int> expected(1, 1, 0);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_minuseq2  () {
        Matrix<int>  x(1, 1, 22);
        Matrix<int>  y(1, 1, 11);

        x-=y;
        CPPUNIT_ASSERT(x.eq(y));}

    void test_minuseq3  () {
        Matrix<int>  x(10, 10, 10);
        Matrix<int>  y(10, 10, 5);

        x[5][5] = 8;
        x-=y;
        Matrix<int> expected(10, 10, 5);
        expected[5][5] = 3;

        CPPUNIT_ASSERT(x[0][0] == 5 && x.eq(expected));}

    // --------------
    // test_timeseqc (+=) constants
    // --------------

    void test_timeseqc () {
        Matrix<int>  x(1, 1, 10);

        x*=2;
        Matrix<int> expected(1, 1, 20);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_timeseqc2  () {
        Matrix<int>  x(1, 1, 5);

        x*=10;
        Matrix<int> expected(1, 1, 50);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_timeseqc3  () {
        Matrix<int>  x(10, 10, 1);

        x[5][5] = 4;
        x*=11;
        Matrix<int> expected(10, 10, 11);
        expected[5][5] += 44;

        CPPUNIT_ASSERT(x.eq(expected));}

    // --------------
    // test_timeseq (+=)
    // --------------

    void test_timeseq () {
        Matrix<int>  x(1, 1, 1);
        Matrix<int>  y(1, 1, 1);

        x*=y;
        Matrix<int> expected(1, 1, 1);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_timeseq2  () {
        Matrix<int>  x(1, 1, 10);
        Matrix<int>  y(1, 1, 5);

        x*=y;
        Matrix<int> expected(1, 1, 50);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_timeseq3  () {
        Matrix<double> x(2, 3, 0);
        Matrix<double> y(3, 2, 0);

        x[0][0] = 1;

        x[0][2] = -2;

        x[1][1] = 3;
        x[1][2] = -1;

        y[0][1] = 3;
        y[1][0] = -2;
        y[1][1] = -1;
        y[2][1] = 4;

        y *= x;

        Matrix<double> expected(3, 3, 0);
        expected[0][0] = 0;
        expected[0][1] = 9;
        expected[0][2] = -3;

        expected[1][0] = -2;
        expected[1][1] = -3;
        expected[1][2] = 5;

        expected[2][0] = 0;
        expected[2][1] = 12;
        expected[2][2] = -4;

        CPPUNIT_ASSERT(y.eq(expected));}





    // ---------
    // test_plus
    // ---------

    void test_plus () {
        Matrix<int> x(1, 1, 4);
        Matrix<int> y(1, 1, 3);

        Matrix<int> result = x + y;

        CPPUNIT_ASSERT(result[0][0] == 7);}

    void test_plus2 () {
        Matrix<int> x(1, 1, 0);

        Matrix<int> result = x + 100;

        CPPUNIT_ASSERT(result[0][0] == 100);}


    void test_plus3 () {
        Matrix<int> x(1, 5, 11);
        Matrix<int> y(1, 5, 11);

        Matrix<int> result = x + y;
        Matrix<int> expected(1, 5, 22);

        CPPUNIT_ASSERT(result.eq(expected));}

    // ----------
    // test_minus
    // ----------

    void test_minus () {
        Matrix<int> x(1, 1, 4);
        Matrix<int> y(1, 1, 3);

        Matrix<int> result = x - y;

        CPPUNIT_ASSERT(result[0][0] == 1);}

    void test_minus2 () {
        Matrix<int> x(1, 1, 100);

        Matrix<int> result = x - 0;

        CPPUNIT_ASSERT(result[0][0] == 100);}


    void test_minus3 () {
        Matrix<int> x(1, 5, 11);
        Matrix<int> y(1, 5, 10);

        Matrix<int> result = x - y;
        Matrix<int> expected(1, 5, 1);

        CPPUNIT_ASSERT(result.eq(expected));}

    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies () {
        Matrix<int> x(1, 3, 0);
        Matrix<int> y(3, 2, 0);

        x[0][0] = 1;
        x[0][1] = 4;
        x[0][2] = 6;

        y[0][0] = 2;
        y[0][1] = 3;
        y[1][0] = 5;
        y[1][1] = 8;
        y[2][0] = 7;
        y[2][1] = 9;


        Matrix<int> result = x * y;
        Matrix<int> expected(1, 2, 0);

        expected[0][0] = 64;
        expected[0][1] = 89;

        CPPUNIT_ASSERT(result.eq(expected));}

    void test_multiplies2 () {
        Matrix<double> x(2, 3, 0);
        Matrix<double> y(3, 2, 0);

        x[0][0] = 1;
        x[0][2] = -2;
        x[1][0] = 0;
        x[1][1] = 3;
        x[1][2] = -1;

        y[0][1] = 3;
        y[1][0] = -2;
        y[1][1] = -1;
        y[2][1] = 4;

        Matrix<double> result = x * y;

        Matrix<double> expected(2, 2, 0);
        expected[0][1] = -5;
        expected[1][0] = -6;
        expected[1][1] = -7;


        CPPUNIT_ASSERT(result.eq(expected));}


    void test_multiplies3 () {
        Matrix<int> x(3, 3, 0);
        Matrix<int> y(3, 2, 0);

        x[0][0] = 6;
        x[0][1] = 3;
        x[0][2] = 0;

        x[1][0] = 2;
        x[1][1] = 5;
        x[1][2] = 1;

        x[2][0] = 9;
        x[2][1] = 8;
        x[2][2] = 6;


        y[0][0] = 7;
        y[0][1] = 4;

        y[1][0] = 6;
        y[1][1] = 7;

        y[2][0] = 5;
        y[2][1] = 0;

        Matrix<int> result = x * y;
        Matrix<int> expected(3, 2, 0);

        expected[0][0] = 60;
        expected[0][1] = 45;

        expected[1][0] = 49;
        expected[1][1] = 43;

        expected[2][0] = 141;
        expected[2][1] = 92;

        CPPUNIT_ASSERT(result.eq(expected));}

    // ----------
       // test_minus
       // ----------

       void test_nonzero () {
           Matrix<int> x(1, 1, 4);
           x.nonzero();

           CPPUNIT_ASSERT(true);}

       void test_nonzero2 () {
           Matrix<int> x;
           bool caught = false;
           try {
           x.nonzero();
           }
           catch (std::length_error& e){
        	 caught = true;
           }
           CPPUNIT_ASSERT(caught);}


       void test_nonzero3 () {
           Matrix<int> x(0, 5, 11);
           bool caught = false;
           try {
           x.nonzero();
           }
           catch (std::length_error& e){
        	 caught = true;
           }

           CPPUNIT_ASSERT(caught);}

       void test_nonzero4 () {
            Matrix<int> x(5, 0, 11);
            bool caught = false;
            try {
            x.nonzero();
            }
            catch (std::length_error& e){
         	 caught = true;
            }

            CPPUNIT_ASSERT(caught);}



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
    CPPUNIT_TEST(test_index);
    CPPUNIT_TEST(test_index2);
    CPPUNIT_TEST(test_index3);
    CPPUNIT_TEST(test_index4);
    CPPUNIT_TEST(test_index5);
    //CPPUNIT_TEST(test_index6);
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_equals2); //8 tests so far
    CPPUNIT_TEST(test_equals3);
    CPPUNIT_TEST(test_equals4);
    CPPUNIT_TEST(test_equals5);
    CPPUNIT_TEST(test_equals6);
    CPPUNIT_TEST(test_equals7);
    CPPUNIT_TEST(test_equals8);
    CPPUNIT_TEST(test_equals9);

    CPPUNIT_TEST(test_eqeq);
    CPPUNIT_TEST(test_eqeq2);
    CPPUNIT_TEST(test_eqeq3);//15 so far; number no longer complete
    CPPUNIT_TEST(test_diff);
    CPPUNIT_TEST(test_diff2);
    CPPUNIT_TEST(test_diff3);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less_than2);
    CPPUNIT_TEST(test_less_than3);
    CPPUNIT_TEST(test_lesseq);
    CPPUNIT_TEST(test_lesseq2);
    CPPUNIT_TEST(test_lesseq3);
    CPPUNIT_TEST(test_greater_than);
    CPPUNIT_TEST(test_greater_than2);
    CPPUNIT_TEST(test_greater_than3);
    CPPUNIT_TEST(test_greateq);
    CPPUNIT_TEST(test_greateq2);
    CPPUNIT_TEST(test_greateq3);//30 done so far

    CPPUNIT_TEST(test_pluseqc);
    CPPUNIT_TEST(test_pluseqc2);
    CPPUNIT_TEST(test_pluseqc3);
    CPPUNIT_TEST(test_pluseq);
    CPPUNIT_TEST(test_pluseq2);
    CPPUNIT_TEST(test_pluseq3);
    CPPUNIT_TEST(test_minuseqc);
    CPPUNIT_TEST(test_minuseqc2);
    CPPUNIT_TEST(test_minuseqc3);
    CPPUNIT_TEST(test_minuseq);
    CPPUNIT_TEST(test_minuseq2);
    CPPUNIT_TEST(test_minuseq3);
    CPPUNIT_TEST(test_timeseqc);
    CPPUNIT_TEST(test_timeseqc2);
    CPPUNIT_TEST(test_timeseqc3);
    CPPUNIT_TEST(test_timeseq);
    CPPUNIT_TEST(test_timeseq2);
    CPPUNIT_TEST(test_timeseq3);//48 tests so far
    CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(test_plus2);
    CPPUNIT_TEST(test_plus3);
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_minus2);
    CPPUNIT_TEST(test_minus3);
    CPPUNIT_TEST(test_multiplies);
    CPPUNIT_TEST(test_multiplies2);
    CPPUNIT_TEST(test_multiplies3);
    CPPUNIT_TEST(test_nonzero);
    CPPUNIT_TEST(test_nonzero2);
    CPPUNIT_TEST(test_nonzero3);
    CPPUNIT_TEST(test_nonzero4);
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
