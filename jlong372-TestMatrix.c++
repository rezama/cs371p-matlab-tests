// ------------------------------
// projects/matlab/TestMatrix.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
 * To test the program:
 *     g++ -ansi -pedantic -lcppunit -ldl -Wall TestMatrix.c++ -o TestMatrix.app
 *     valgrind TestMatrix.app >& TestMatrix.out
 */

// --------
// includes
// --------

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Matrix.h"

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
        CPPUNIT_ASSERT(y.size() == 2);
    }

    void testConstructorBool()
    {
        Matrix<bool>x(5, 5, true);
        CPPUNIT_ASSERT(x.size() == 5);
        CPPUNIT_ASSERT(x[0][0]);
    }

    void testConstructorNoSpecifiedValue()
    {
        Matrix<int>t(12,12);
        CPPUNIT_ASSERT(t.size() == 12);
        CPPUNIT_ASSERT(t[0][0] == 0);
    }

    void testDefaultConstructor()
    {
        Matrix<int>x;
        Matrix<long>l;
        Matrix<bool>b;
        Matrix<double>d;

        CPPUNIT_ASSERT(x.size() == 0);
        CPPUNIT_ASSERT(l.size() == 0);
        CPPUNIT_ASSERT(b.size() == 0);
        CPPUNIT_ASSERT(d.size() == 0);
    }
    // ----------
    // test_index
    // ----------

    void test_index () {
        const Matrix<int> x(1,1);
        CPPUNIT_ASSERT(x[0][0] == 0);
    }

    void testSingleIndex ()
    {
        Matrix<int>x(5,5,5);

        std::vector<int> t = x[0];

        CPPUNIT_ASSERT(t.size() == 5);
        CPPUNIT_ASSERT(t[0] == 5);
    }

    void testIndexDefault ()
    {
        Matrix<int> x(12, 12);

        CPPUNIT_ASSERT(x[0][0] == 0);
    }

    void testSingleIndexDefault()
    {
        Matrix<int>x(12,12);
        std::vector<int> v = x[0];

        CPPUNIT_ASSERT(v.size() == 12);
        CPPUNIT_ASSERT(v[0] == 0);
    }

    // -----------
    // test_equals
    // -----------

    void test_equals () {
        Matrix<int>  x(1,1);
        Matrix<int>  y(1,1);
        Matrix<bool> z;
        Matrix<bool> t(1,1,true);
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void testEqualsWithDefaults ()
    {
        Matrix<int> x(5, 5);
        Matrix<int> y(5, 5);
        Matrix<bool> truth(5, 5, true);
        Matrix<bool>z;

        z = (x == y);

        CPPUNIT_ASSERT(z.eq(truth));
    }

    void testNotEquals ()
    {
        Matrix<int> x(5, 5, 5);
        Matrix<int> y(5, 5, 4);
        Matrix<bool> truth(5, 5, false);
        Matrix<bool>z;

        z = (x == y);

        CPPUNIT_ASSERT(z.eq(truth));
    }

    void testEqualVectors ()
    {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1, 1);
        Matrix<bool> t(1, 1, true);
        Matrix<bool> z = (x == y);

        CPPUNIT_ASSERT(z.eq(t));
    }

    // --------------
    // NotEquals test
    // --------------
    void testNotEqualsWithDefaults ()
    {
        Matrix<int> x(5, 5);
        Matrix<int> y(5, 5);
        Matrix<bool> truth(5, 5, false);
        Matrix<bool>z;

        z = (x != y);

        CPPUNIT_ASSERT(z.eq(truth));
    }

    void testNotEqualsTrue ()
    {
        Matrix<int> x(5, 5, 5);
        Matrix<int> y(5, 5, 4);
        Matrix<bool> truth(5, 5, true);
        Matrix<bool>z;

        z = (x != y);

        CPPUNIT_ASSERT(z.eq(truth));
    }

    void testNotEqualVector ()
    {
        Matrix<int> x(1, 1, 1);
        Matrix<int> y(1, 1);
        Matrix<bool> t(1, 1, true);
        Matrix<bool> z = (x != y);

        CPPUNIT_ASSERT(z.eq(t));
    }

    // --------------
    // test_less_than
    // --------------

    void test_less_than ()
     {
        Matrix<int>  x(1,1,100);
        Matrix<int>  y(1,1,1000);
        Matrix<bool> z;
        Matrix<bool> t(1,1,true);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void testLessThanTrue ()
    {
        Matrix<int> x(4,4,4);
        Matrix<int> y(4,4,5);
        Matrix<bool>z;
        Matrix<bool>truth(4,4,true);

        z = (x < y);

        CPPUNIT_ASSERT(z.eq(truth));

    }

    void testLessThanFalse()
    {
        Matrix<int> x(4,4,5);
        Matrix<int> y(4,4,4);
        Matrix<bool>z;
        Matrix<bool>truth(4,4,false);

        z = (x < y);

        CPPUNIT_ASSERT(z.eq(truth));

    }

    void testLessThanDefault()
    {
        Matrix<int> x(4,4);
        Matrix<int> y(4,4);
        Matrix<bool>z;
        Matrix<bool>truth(4,4,false);

        z = (x < y);

        CPPUNIT_ASSERT(z.eq(truth));
    }

    // --------------
    // lessThanEquals Tests
    // --------------

    void testLessEqualsThanTrue ()
    {
        Matrix<int> x(4,4,4);
        Matrix<int> y(4,4,5);
        Matrix<bool>z;
        Matrix<bool>truth(4,4,true);

        z = (x <= y);

        CPPUNIT_ASSERT(z.eq(truth));

    }

    void testLessEqualsThanFalse()
    {
        Matrix<int> x(4,4,5);
        Matrix<int> y(4,4,4);
        Matrix<bool>z;
        Matrix<bool>truth(4,4,false);

        z = (x <= y);

        CPPUNIT_ASSERT(z.eq(truth));

    }

    void testLessEqualsThanDefault()
    {
        Matrix<int> x(4,4);
        Matrix<int> y(4,4);
        Matrix<bool>z;
        Matrix<bool>truth(4,4,true);

        z = (x <= y);

        CPPUNIT_ASSERT(z.eq(truth));
    }

    //--------------------
    // greater than tests
    //--------------------
        void testGreaterThanTrue ()
    {
        Matrix<int> x(4,4,4);
        Matrix<int> y(4,4,5);
        Matrix<bool>z;
        Matrix<bool>truth(4,4, false);

        z = (x > y);

        CPPUNIT_ASSERT(z.eq(truth));

    }

    void testGreaterThanFalse()
    {
        Matrix<int> x(4,4,5);
        Matrix<int> y(4,4,4);
        Matrix<bool>z;
        Matrix<bool>truth(4,4,true);

        z = (x > y);

        CPPUNIT_ASSERT(z.eq(truth));

    }

    void testGreaterThanDefault()
    {
        Matrix<int> x(4,4);
        Matrix<int> y(4,4);
        Matrix<bool>z;
        Matrix<bool>truth(4,4,false);

        z = (x > y);

        CPPUNIT_ASSERT(z.eq(truth));
    }

    // --------------
    // greaterThanEquals Tests
    // --------------

    void testGreaterEqualsThanTrue ()
    {
        Matrix<int> x(4,4,4);
        Matrix<int> y(4,4,5);
        Matrix<bool>z;
        Matrix<bool>truth(4,4,false);

        z = (x >= y);

        CPPUNIT_ASSERT(z.eq(truth));

    }

    void testGreaterEqualsThanFalse()
    {
        Matrix<int> x(4,4,5);
        Matrix<int> y(4,4,4);
        Matrix<bool>z;
        Matrix<bool>truth(4,4,true);

        z = (x >= y);

        CPPUNIT_ASSERT(z.eq(truth));

    }

    void testGreaterEqualsThanDefault()
    {
        Matrix<int> x(4,4);
        Matrix<int> y(4,4);
        Matrix<bool>z;
        Matrix<bool>truth(4,4,true);

        z = (x >= y);

        CPPUNIT_ASSERT(z.eq(truth));
    }
    // ---------
    // test_plus
    // ---------

    void test_plus () {
        Matrix<int> x(1,1);
        Matrix<int> y(1,1);
        Matrix<int> z(1,1,0);
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void testPlusTrivial ()
    {
        Matrix<int> x(4,4);
        Matrix<int> y(4,4);
        Matrix<int>answer(4,4, 0);
        x += 0;
        x += y;

        CPPUNIT_ASSERT(x.eq(answer));

    }

    void testplusLarge()
    {
        Matrix<int> x(400,400,400);
        Matrix<int> y(400,400,200);
        Matrix<int>answer(400,400, 800);
        x += 200;

        x += y;

        CPPUNIT_ASSERT(x.eq(answer));

    }

    void testPlusNegative()
    {
        Matrix<int> x(4,4, 6);
        Matrix<int> y(4,4, -2);
        Matrix<int>answer(4,4, 2);
        x += -2;

        x += y;

        CPPUNIT_ASSERT(x.eq(answer));
    }

    // ----------
    // test_minus
    // ----------

    void test_minus ()
    {
        Matrix<int> x(1,1);
        Matrix<int> y(1,1);
        Matrix<int> z(1,1,0);
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void testMinusTrivial()
    {
        Matrix<int> x(4,4);
        Matrix<int> y(4,4);
        Matrix<int>answer(4,4, 0);
        x -= 0;

        x -= y;

        CPPUNIT_ASSERT(x.eq(answer));
    }

    void testMinusLarge()
    {
        Matrix<int> x(400,400, 1000);
        Matrix<int> y(400,400, 500);
        Matrix<int>answer(400,400, 0);
        x -= 500;

        x -= y;

        CPPUNIT_ASSERT(x.eq(answer));
    }

    void testMinusNegative()
    {
        Matrix<int> x(400,400, 1000);
        Matrix<int> y(400,400, -500);
        Matrix<int>answer(400,400, 1000);
        x -= 500;

        x -= y;

        CPPUNIT_ASSERT(x.eq(answer));
    }

    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies () {
        Matrix<int> x(1,1);
        Matrix<int> y(1,1);
        Matrix<int> z(1,1,0);
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void testMultipliesTrivial()
    {
        Matrix<int> x(4,4, 1);
        Matrix<int> y(4,4, 1);
        Matrix<int>answer(4,4, 0);
        x *= 0;

        x *= y;

        CPPUNIT_ASSERT(x.eq(answer));
    }

    void testMultipliesLarge()
    {
        Matrix<int> x(400,400, 9);
        Matrix<int> y(400,400, 10);
        Matrix<int>answer(400,400, 900);
        x *= 10;

        x *= y;

        CPPUNIT_ASSERT(x.eq(answer));
    }

    void testMultipliesNegative()
    {
        Matrix<int> x(400,400, -9);
        Matrix<int> y(400,400, 10);
        Matrix<int>answer(400,400, 900);
        x *= -10;

        x *= y;

        CPPUNIT_ASSERT(x.eq(answer));
    }

    // -------------
    // test_iterator
    // -------------

    void test_iterator ()
     {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);
    }

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);

    /////////////////////
    //Constructor Tests//
    /////////////////////
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(testConstructorBool);
    CPPUNIT_TEST(testConstructorNoSpecifiedValue);
    CPPUNIT_TEST(testDefaultConstructor);
    
    ///////////////
    //Index Tests//
    ///////////////
    CPPUNIT_TEST(test_index);
    CPPUNIT_TEST(testSingleIndex);
    CPPUNIT_TEST(testIndexDefault);
    CPPUNIT_TEST(testSingleIndexDefault);

    ////////////////
    //Equals Tests//
    ///////////////
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(testEqualsWithDefaults);
    CPPUNIT_TEST(testNotEquals);
    CPPUNIT_TEST(testEqualVectors);

    ///////////////////
    //NotEquals Tests//
    ///////////////////
    CPPUNIT_TEST(testNotEqualsWithDefaults);
    CPPUNIT_TEST(testNotEqualsTrue);
    CPPUNIT_TEST(testNotEqualVector);


    /////////////////
    //Less Than Tests//
    /////////////////
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(testLessThanTrue);
    CPPUNIT_TEST(testLessThanFalse);
    CPPUNIT_TEST(testLessThanDefault);

    /////////////////////////
    //Less Than Equal Tests//
    /////////////////////////
    CPPUNIT_TEST(testLessEqualsThanTrue);
    CPPUNIT_TEST(testLessEqualsThanFalse);
    CPPUNIT_TEST(testLessEqualsThanDefault);

    //////////////////////
    //Greater Than Tests//
    //////////////////////
    CPPUNIT_TEST(testGreaterThanTrue);
    CPPUNIT_TEST(testGreaterThanFalse);
    CPPUNIT_TEST(testGreaterThanDefault);

    ////////////////////////////
    //Greater Than Equal Tests//
    ////////////////////////////
    CPPUNIT_TEST(testGreaterEqualsThanTrue);
    CPPUNIT_TEST(testGreaterEqualsThanFalse);
    CPPUNIT_TEST(testGreaterEqualsThanDefault);

    
    //////////////
    //plus Tests//
    //////////////
    CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(testPlusTrivial);
    CPPUNIT_TEST(testplusLarge);
    CPPUNIT_TEST(testPlusNegative);

    //////////////
    //minus Tests//
    //////////////
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(testMinusTrivial);
    CPPUNIT_TEST(testMinusLarge);
    CPPUNIT_TEST(testMinusNegative);

    ////////////////////
    //multiplies Tests//
    ///////////////////
    CPPUNIT_TEST(test_multiplies);
    CPPUNIT_TEST(testMultipliesTrivial);
    CPPUNIT_TEST(testMultipliesLarge);
    CPPUNIT_TEST(testMultipliesNegative);

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