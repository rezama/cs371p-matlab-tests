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

#undef private
#define private public

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
        Matrix<int> t(2, 3);
        z[0][0] = 1;
        t += z;
        t *= z;
        CPPUNIT_ASSERT(t[0][0] == 1);
        CPPUNIT_ASSERT(x.size() == 0);}

    // ----------------
    // test_constructor1
    // ----------------
    
    void test_constructor1 () {
        Matrix<int> x;
        Matrix<int> y(0);
        CPPUNIT_ASSERT(y.size() == 0);}

    // ----------------
    // test_constructor2
    // ----------------
    
    void test_constructor2 () {
        Matrix<int> x;
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(10, 3, 4);
        CPPUNIT_ASSERT(z[0].size() == 3);}
    
    // ----------------
    // test_constructor3
    // ----------------
    
    void test_constructor3 () {
        Matrix<int> x;
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(t[0][0] == 4);}
    
    // ----------
    // test_index
    // ----------

    void test_index () {
        const Matrix<int> x(100, 100);
        try {
            if (x[0][0] == 0); 
        } catch (...) {
            // We pass
        }}

    // ----------
    // test_index1
    // ----------
    
    void test_index1 () {
        const Matrix<int> x(2, 2);
        CPPUNIT_ASSERT(x[1][1] == 0);}

    // ----------
    // test_index2
    // ----------
    
    void test_index2 () {
        const Matrix<int> x(2, 1);
        CPPUNIT_ASSERT(x[0][0] == 0);}
    
    // ----------
    // test_index3
    // ----------
    
    void test_index3 () {
        const Matrix<int> x(3, 2);
        CPPUNIT_ASSERT(x[2][0] == 0);}

    // -----------
    // test_equals
    // -----------

    void test_equals () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    // -----------
    // test_equals1
    // -----------
    
    void test_equals1 () {
        Matrix<int>  x(1, 4);
        Matrix<int>  y(1, 4);
        Matrix<bool> z;
        Matrix<bool> t(1, 4);
        x[0][0] = 1;
        y[0][0] = 0;
        t[0][0] = 0;
        t[0][1] = t[0][2] = t[0][3] = 1;
        z = (x == y);
        //std::cout << "z[0][0]=" << z[0][0] << std::endl;
        //std::cout << "z[0][1]=" << z[0][1] << std::endl;
        CPPUNIT_ASSERT(z.eq(t));}

    // -----------
    // test_equals2
    // -----------
    
    void test_equals2 () {
        Matrix<int>  x(1, 3);
        Matrix<int>  y(3, 1);
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(!z.eq(t));}

    // -----------
    // test_equals3
    // -----------
    
    void test_equals3 () {
        Matrix<int>  x(3, 3);
        Matrix<int>  y(3, 3);
        Matrix<bool> z;
        z = (x == y);
        for (int j = 0; j < 3; j++)
            for (int i = 0; i < 3; i++)
                CPPUNIT_ASSERT(z[j][i] == true);}

    // -----------
    // test_not_equals1
    // -----------
    
    void test_not_equals1 () {
        Matrix<int>  x(1, 4);
        Matrix<int>  y(1, 4);
        Matrix<bool> z;
        Matrix<bool> t(1, 4);
        t[0][0] = 0;
        t[0][1] = t[0][2] = t[0][3] = 1;
        x[0][0] = 1;
        y[0][0] = 0;
        z = (x != y);
        CPPUNIT_ASSERT(!z.eq(t));}
    
    // -----------
    // test_not_equals2
    // -----------
    
    void test_not_equals2 () {
        Matrix<int>  x(1, 3);
        Matrix<int>  y(3, 1);
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x != y);
        CPPUNIT_ASSERT(!z.eq(t));}
    
    // -----------
    // test_not_equals3
    // -----------
    
    void test_not_equals3 () {
        Matrix<int>  x(3, 3);
        Matrix<int>  y(3, 3);
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x != y);
        for (int j = 0; j < 3; j++)
            for (int i = 0; i < 3; i++)
                CPPUNIT_ASSERT(z[j][i] == false);}
    
    // --------------
    // test_less_than
    // --------------

    void test_less_than () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_less_than1
    // --------------
    
    void test_less_than1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    // --------------
    // test_less_than2
    // --------------
    
    void test_less_than2 () {
        Matrix<int>  x(2, 2);
        Matrix<int>  y(2, 2);
        Matrix<bool> z;
        Matrix<bool> t(2, 2);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    // --------------
    // test_less_than3
    // --------------
    
    void test_less_than3 () {
        Matrix<int>  x(1, 4);
        Matrix<int>  y(1, 4);
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x < y);
        CPPUNIT_ASSERT(!z.eq(t));}
    
    
    // --------------
    // test_less_than_equalsto1
    // --------------
    
    void test_less_than_equalsto1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    // --------------
    // test_less_than_equalsto2
    // --------------
    
    void test_less_than_equalsto2 () {
        Matrix<int>  x(2, 2);
        Matrix<int>  y(2, 2);
        Matrix<bool> z;
        Matrix<bool> t(2, 2);
        z = (x <= y);
        t[0][0] = t[0][1] = t[1][0] = t[1][1] = true;
        CPPUNIT_ASSERT(z.eq(t));}
    
    // --------------
    // test_less_than_equalsto3
    // --------------
    
    void test_less_than_equalsto3 () {
        Matrix<int>  x(1, 4);
        Matrix<int>  y(1, 4);
        Matrix<bool> z;
        Matrix<bool> t(1, 4);
        z = (x <= y);
        t[0][0] = t[0][1] = t[0][2] = t[0][3] = true;
        CPPUNIT_ASSERT(z.eq(t));}
    
    // --------------
    // test_greater_than1
    // --------------
    
    void test_greater_than1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    // --------------
    // test_greater_than2
    // --------------
    
    void test_greater_than2 () {
        Matrix<int>  x(2, 2);
        Matrix<int>  y(2, 2);
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x > y);
        CPPUNIT_ASSERT(!z.eq(t));}
    
    // --------------
    // test_greater_than3
    // --------------
    
    void test_greater_than3 () {
        Matrix<int>  x(1, 4);
        Matrix<int>  y(1, 4);
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x > y);
        CPPUNIT_ASSERT(!z.eq(t));}
    
    
    // --------------
    // test_greater_than_equalsto1
    // --------------
    
    void test_greater_than_equalsto1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    // --------------
    // test_greater_than_equalsto2
    // --------------
    
    void test_greater_than_equalsto2 () {
        Matrix<int>  x(2, 2);
        Matrix<int>  y(2, 2);
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x >= y);
        CPPUNIT_ASSERT(!z.eq(t));}
    
    // --------------
    // test_greater_than_equalsto3
    // --------------
    
    void test_greater_than_equalsto3 () {
        Matrix<int>  x(1, 4);
        Matrix<int>  y(1, 4);
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x >= y);
        CPPUNIT_ASSERT(!z.eq(t));}
    
    // ---------
    // test_plus
    // ---------

    void test_plus () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------
    // test_plus1
    // ---------
    
    void test_plus1 () {
        Matrix<int> x(1, 4);
        Matrix<int> y(1, 4);
        Matrix<int> z(1, 4);
        x = x + 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------
    // test_plus2
    // ---------
    
    void test_plus2 () {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        Matrix<int> z(2, 2);
        x = x + 0;
        y = y + 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}
    
    // ---------
    // test_plus3
    // ---------
    
    void test_plus3 () {
        Matrix<int> x(1,1);
        Matrix<int> y(1,1);
        Matrix<int> z(1,1);
        x = x + 1;
        y = y + x;
        z = 1;
        //std::cout << "x[0][0]=" << x[0][0] << std::endl;
        //std::cout << "y[0][0]=" << y[0][0] << std::endl;
        //std::cout << "z[0][0]=" << z[0][0] << std::endl;
        CPPUNIT_ASSERT(!y.eq(z));}

    // ---------
    // test_plus_equals1
    // ---------
    
    void test_plus_equals1 () {
        Matrix<int> x(1, 4);
        Matrix<int> y(1, 4);
        Matrix<int> z(1, 4);
        x = x + 0;
        y += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}
    
    // ---------
    // test_plus_equals2
    // ---------
    
    void test_plus_equals2 () {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        Matrix<int> z(2, 2);
        x = x + 0;
        y = y + 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}
    
    // ---------
    // test_plus_equals3
    // ---------
    
    void test_plus_equals3 () {
        Matrix<int> x(1,1);
        Matrix<int> y(1,1);
        Matrix<int> z(1,1);
        x = x + 1;
        y += x;
        z += 1;
        CPPUNIT_ASSERT(y.eq(z));}
    
    // ----------
    // test_minus
    // ----------

    void test_minus () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}

    
    // ----------
    // test_minus1
    // ----------
    
    void test_minus1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = x - 0;
        CPPUNIT_ASSERT(x.eq(z));
        x = x - y;
        CPPUNIT_ASSERT(x.eq(z));}
    
    
    // ----------
    // test_minus2
    // ----------
    
    void test_minus2 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = x - z;
        CPPUNIT_ASSERT(x.eq(z));
        x = x - y;
        CPPUNIT_ASSERT(x.eq(z));}
    
    
    // ----------
    // test_minus3
    // ----------
    
    void test_minus3 () {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        Matrix<int> z(2, 2);
        x = x - y;
        CPPUNIT_ASSERT(x.eq(z));}
    
    // ----------
    // test_minus_equals1
    // ----------
    
    void test_minus_equals1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}
    
    
    // ----------
    // test_minus_equals2
    // ----------
    
    void test_minus_equals2 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= z;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}
    
    
    // ----------
    // test_minus_equals3
    // ----------
    
    void test_minus_equals3 () {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 2);
        Matrix<int> z(2, 2);
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------------
    // test_multiplies1
    // ---------------
    
    void test_multiplies1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------------
    // test_multiplies2
    // ---------------
    
    void test_multiplies2 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------------
    // test_multiplies3
    // ---------------
    
    void test_multiplies3 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------------
    // test_multiplies_equals1
    // ---------------
    
    void test_multiplies_equals1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x *= 1;
        CPPUNIT_ASSERT(x.eq(z));}
    
    // ---------------
    // test_multiplies_equals2
    // ---------------
    
    void test_multiplies_equals2 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= x;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}
    
    // ---------------
    // test_multiplies_equals3
    // ---------------
    
    void test_multiplies_equals3 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= z;
        CPPUNIT_ASSERT(x.eq(z));
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}
    

    // -------------
    // test_iterator
    // -------------

    void test_iterator () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    // -------------
    // test_iterator1
    // -------------
    
    void test_iterator1 () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    // -------------
    // test_iterator2
    // -------------
    
    void test_iterator2 () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}
    
    // -------------
    // test_iterator3
    // -------------
    
    void test_iterator3 () {
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

    // -------------------
    // test_const_iterator1
    // -------------------
    
    void test_const_iterator1 () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}
    
    // -------------------
    // test_const_iterator2
    // -------------------
    
    void test_const_iterator2 () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}
    
    // -------------------
    // test_const_iterator3
    // -------------------
    
    void test_const_iterator3 () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}
    
    // -------------------
    // test_size1
    // -------------------
    
    void test_size1 () {
        const Matrix<int> x;
        CPPUNIT_ASSERT(x.size() == 0);}
    
    // -------------------
    // test_size2
    // -------------------
    
    void test_size2 () {
        const Matrix<int> x(2, 2);
        CPPUNIT_ASSERT(x.size() == 2);}
    
    // -------------------
    // test_size3
    // -------------------
    
    void test_size3 () {
        const Matrix<int> x(2, 3);
        CPPUNIT_ASSERT(x[0].size() == 3);}
    
    // -------------------
    // test_valid1
    // -------------------
    
    void test_valid1 () {
        const Matrix<int> x;
        CPPUNIT_ASSERT(!x.valid());}
    
    // -------------------
    // test_valid2
    // -------------------
    
    void test_valid2 () {
        const Matrix<int> x(2, 2);
        CPPUNIT_ASSERT(x.valid());}
    
    // -------------------
    // test_valid3
    // -------------------
    
    void test_valid3 () {
        const Matrix<int> x(2, 3);
        CPPUNIT_ASSERT(x.valid());}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_constructor1);
    CPPUNIT_TEST(test_constructor2);
    CPPUNIT_TEST(test_constructor3);

    CPPUNIT_TEST(test_index);
    CPPUNIT_TEST(test_index1);
    CPPUNIT_TEST(test_index2);
    CPPUNIT_TEST(test_index3);

    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_equals1);
    CPPUNIT_TEST(test_equals2);
    CPPUNIT_TEST(test_equals3);
    
    CPPUNIT_TEST(test_not_equals1);
    CPPUNIT_TEST(test_not_equals2);
    CPPUNIT_TEST(test_not_equals3);
    
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_less_than1);
    CPPUNIT_TEST(test_less_than2);
    CPPUNIT_TEST(test_less_than3);

    CPPUNIT_TEST(test_less_than_equalsto1);
    CPPUNIT_TEST(test_less_than_equalsto2);
    CPPUNIT_TEST(test_less_than_equalsto3);
    
    CPPUNIT_TEST(test_greater_than1);
    CPPUNIT_TEST(test_greater_than2);
    CPPUNIT_TEST(test_greater_than3);

    CPPUNIT_TEST(test_greater_than_equalsto1);
    CPPUNIT_TEST(test_greater_than_equalsto2);
    CPPUNIT_TEST(test_greater_than_equalsto3);
    
    CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(test_plus1);
    CPPUNIT_TEST(test_plus2);
    CPPUNIT_TEST(test_plus3);
    
    CPPUNIT_TEST(test_plus_equals1);
    CPPUNIT_TEST(test_plus_equals2);
    CPPUNIT_TEST(test_plus_equals3);
    
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_minus1);
    CPPUNIT_TEST(test_minus2);
    CPPUNIT_TEST(test_minus3);    

    CPPUNIT_TEST(test_minus_equals1);
    CPPUNIT_TEST(test_minus_equals2);
    CPPUNIT_TEST(test_minus_equals3);    
    
    CPPUNIT_TEST(test_multiplies);
    CPPUNIT_TEST(test_multiplies1);
    CPPUNIT_TEST(test_multiplies2);
    CPPUNIT_TEST(test_multiplies3);

    CPPUNIT_TEST(test_multiplies_equals1);
    CPPUNIT_TEST(test_multiplies_equals2);
    CPPUNIT_TEST(test_multiplies_equals3);
    
    CPPUNIT_TEST(test_iterator);
    CPPUNIT_TEST(test_iterator1);
    CPPUNIT_TEST(test_iterator2);
    CPPUNIT_TEST(test_iterator3);
    
    CPPUNIT_TEST(test_const_iterator);
    CPPUNIT_TEST(test_const_iterator1);
    CPPUNIT_TEST(test_const_iterator2);
    CPPUNIT_TEST(test_const_iterator3);
    
    CPPUNIT_TEST(test_size1);
    CPPUNIT_TEST(test_size2);
    CPPUNIT_TEST(test_size3);

    CPPUNIT_TEST(test_valid1);
    CPPUNIT_TEST(test_valid2);
    CPPUNIT_TEST(test_valid3);
    
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
