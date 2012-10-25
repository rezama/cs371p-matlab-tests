// ------------------------------
// projects/matlab/TestMatrix.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
 * To test the program:
 *     g++ -ansi -Wl,--no-as-needed -pedantic -lcppunit -ldl -Wall TestMatrix.c++ -o TestMatrix.app
 *     valgrind TestMatrix.app >& TestMatrix.out
 */

// --------
// includes
// --------

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Matrix.h"
 #include <stdexcept>
 #include <iostream>
using namespace std;

// ----------
// TestMatrix
// ----------

struct TestMatrix : CppUnit::TestFixture {
    // ----------------
    // test_constructor
    // ----------------

    void test_constructor_1 () 
    {
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(y.rows == 2);
        CPPUNIT_ASSERT(z.rows == 2);
        CPPUNIT_ASSERT(z.cols == 3);
        CPPUNIT_ASSERT(t.rows == 2);
        CPPUNIT_ASSERT(t.cols == 3);
    }

    void test_constructor_2 () 
    {
      Matrix<int> x(2, 0);
      CPPUNIT_ASSERT(x.size() == 2);
      CPPUNIT_ASSERT(x[0].size() == 0);
      CPPUNIT_ASSERT(x[1].size() == 0);
    }

    void test_constructor_3 () 
    {
        Matrix<double> pi(2, 3, 3.14);
        CPPUNIT_ASSERT(pi.size() == 2);
        for (int i = 0; i < 2; i++) 
        {
            CPPUNIT_ASSERT(pi[i].size() == 3);         
            for (int j = 0; j < 3; j++) 
            {
                CPPUNIT_ASSERT(pi[i][j] == 3.14);
            }
        }
    }

    // ----------
    // test_index
    // ----------

    void test_index_1 () 
    {
        Matrix<int> x(5,5,10);
        CPPUNIT_ASSERT(x[0][0] == 10);
        x[3][4] = 56;
        CPPUNIT_ASSERT(x[3][4] == 56);
    }

    void test_index_2 () 
    {
      Matrix<double> pi(2, 3, 3.14);
      CPPUNIT_ASSERT(pi.size() == 2);
      for (int i = 0; i < 2; i++) {
        CPPUNIT_ASSERT(pi[i].size() == 3);         
        for (int j = 0; j < 3; j++) {
          CPPUNIT_ASSERT(pi[i][j] == 3.14);
        }
      }
    }
    void test_index_3 () 
    {
      Matrix<double> pi(5, 1, 3.14);
      CPPUNIT_ASSERT(pi.size() == 5);
      CPPUNIT_ASSERT(pi[0].size() == 1);
      for (int i = 0; i < 5; i++) {
        CPPUNIT_ASSERT(pi[i][0] == 3.14);
      }
    }


    // -----------
    // test_equals
    // -----------

    void test_equals_1 () 
    {
        Matrix<int>  x(3,3,5);
        Matrix<int>  y(3,3,5);
        Matrix<bool> z(3,3,true);
        
        Matrix<int>  a(2,2);
        a[0][0] = 4;
        a[0][1] = 2;
        a[1][0] = 2;
        a[1][1] = 4;
        Matrix<int>  b(2,2);
        b[0][0] = 4;
        b[0][1] = 1;
        b[1][0] = 1;
        b[1][1] = 4;
        Matrix<bool> c(2,2);
        b[0][0] = 1;
        b[0][1] = 0;
        b[1][0] = 0;
        b[1][1] = 1;

        Matrix<bool> test1 = x==y;
        Matrix<bool> test2 = a==b;
        CPPUNIT_ASSERT(test1.eq(z));
        CPPUNIT_ASSERT(test2.eq(c));
    }

    void test_equals_2 () 
    {
        Matrix<int>  x(2,2,4);
        Matrix<int>  y(2,2,4);
        Matrix<bool> z(2,2,4);
        Matrix<bool> t(2,2);
        t[0][0] = true;
        t[0][1] = true;
        t[1][0] = true;
        t[1][1] = true;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
        Matrix<int> w(9,9,0);
        try{
            z= x==w;
            CPPUNIT_ASSERT(false);
        }
        catch(invalid_argument& e)
        {
            CPPUNIT_ASSERT(x.eq(x));
        }
    }

    void test_equals_3 () 
    {
        Matrix<int>  x(2,2,4);
        x[1][1] = 999;
        Matrix<int>  y(2,2,4);
        Matrix<bool> z(2,2,4);
        Matrix<bool> t(2,2);
        t[0][0] = true;
        t[0][1] = true;
        t[1][0] = true;
        t[1][1] = false;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    // --------------
    // test_less_than
    // --------------

    void test_less_than_1 () 
    {
        Matrix<int>  x(3,3,5);
        Matrix<int>  y(3,3,5);
        Matrix<bool> z(3,3,false);
        
        Matrix<int>  a(2,2);
        a[0][0] = 4;
        a[0][1] = 1;
        a[1][0] = 1;
        a[1][1] = 4;
        Matrix<int>  b(2,2);
        b[0][0] = 4;
        b[0][1] = 2;
        b[1][0] = 2;
        b[1][1] = 4;
        Matrix<bool> c(2,2);
        b[0][0] = 0;
        b[0][1] = 1;
        b[1][0] = 1;
        b[1][1] = 0;

        Matrix<bool> test1 = x<y;
        Matrix<bool> test2 = a<b;
        CPPUNIT_ASSERT(test1.eq(z));
        CPPUNIT_ASSERT(test2.eq(c));
    }

    void test_less_than_2 () 
    {
        Matrix<int>  x(1,1);
        Matrix<int>  y(1,1,999);
        Matrix<bool> z(1,1);
        Matrix<bool> t(1,1, true);
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
        Matrix<int> w(9,9,0);
        try{
            z= x<w;
            CPPUNIT_ASSERT(false);
        }
        catch(std::invalid_argument& e)
        {
            CPPUNIT_ASSERT(x.eq(x));
        }
    }

    void test_less_than_3 () {
        Matrix<int>  x(1,2);
        x[0][0] = 100;
        x[0][1] = 0;
        Matrix<int>  y(1,2);
        y[0][0] = 0;
        y[0][1] = 999;
        Matrix<bool> z(1,2);
        Matrix<bool> t(1,2);
        t[0][0] = false;
        t[0][1] = true;
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_less_than_equals_1 () 
    {
        Matrix<int>  x(3,3,5);
        Matrix<int>  y(3,3,5);
        Matrix<bool> z(3,3,true);
        
        Matrix<int>  a(2,2);
        a[0][0] = 4;
        a[0][1] = 2;
        a[1][0] = 5;
        a[1][1] = 4;
        Matrix<int>  b(2,2);
        b[0][0] = 4;
        b[0][1] = 2;
        b[1][0] = 1;
        b[1][1] = 4;
        Matrix<bool> c(2,2);
        b[0][0] = 1;
        b[0][1] = 1;
        b[1][0] = 0;
        b[1][1] = 1;

        Matrix<bool> test1 = x<=y;
        Matrix<bool> test2 = a<=b;
        CPPUNIT_ASSERT(test1.eq(z));
        CPPUNIT_ASSERT(test2.eq(c));
    }
    void test_less_than_equals_2 () 
    {
        Matrix<int>  x(1,1);
        Matrix<int>  y(1,1,999);
        Matrix<bool> z(1,1);
        Matrix<bool> t(1,1, true);
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));
        Matrix<int> w(9,9,0);
        try{
            z= x<=w;
            CPPUNIT_ASSERT(false);
        }
        catch(invalid_argument& e)
        {
            CPPUNIT_ASSERT(x.eq(x));
        }
    }

    void test_less_than_equals_3 () 
    {
        Matrix<int>  x(1,2);
        x[0][0] = 100;
        x[0][1] = 0;
        Matrix<int>  y(1,2);
        y[0][0] = 1000;
        y[0][1] = 999;
        Matrix<bool> z(1,2);
        Matrix<bool> t(1,2);
        t[0][0] = true;
        t[0][1] = true;
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_greater_than_1 () 
    {
        Matrix<int>  x(3,3,5);
        Matrix<int>  y(3,3,5);
        Matrix<bool> z(3,3,false);
        
        Matrix<int>  a(2,2);
        a[0][0] = 5;
        a[0][1] = 1;
        a[1][0] = 1;
        a[1][1] = 5;
        Matrix<int>  b(2,2);
        b[0][0] = 4;
        b[0][1] = 2;
        b[1][0] = 2;
        b[1][1] = 4;
        Matrix<bool> c(2,2);
        c[0][0] = 1;
        c[0][1] = 0;
        c[1][0] = 0;
        c[1][1] = 1;

        Matrix<bool> test1 = x>y;
        Matrix<bool> test2 = a>b;

        CPPUNIT_ASSERT(test1.eq(z));
        CPPUNIT_ASSERT(test2.eq(c));
    }

    void test_greater_than_2 () 
    {
        Matrix<int>  x(1,1);
        Matrix<int>  y(1,1,999);
        Matrix<bool> z(1,1);
        Matrix<bool> t(1,1, false);
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));
        Matrix<int> w(9,9,0);
        try{
            z= x<w;
            CPPUNIT_ASSERT(false);
        }
        catch(invalid_argument& e)
        {
            CPPUNIT_ASSERT(x.eq(x));
        }
    }

    void test_greater_than_3 () 
    {
        Matrix<int>  x(1,2);
        x[0][0] = 100;
        x[0][1] = 0;
        Matrix<int>  y(1,2);
        y[0][0] = 0;
        y[0][1] = 999;
        Matrix<bool> z(1,2);
        Matrix<bool> t(1,2);
        t[0][0] = true;
        t[0][1] = false;
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    void test_greater_than_equals_1() 
    {
        Matrix<int>  x(3,3,5);
        Matrix<int>  y(3,3,5);
        Matrix<bool> z(3,3,true);
        
        Matrix<int>  a(2,2);
        a[0][0] = 5;
        a[0][1] = 1;
        a[1][0] = 1;
        a[1][1] = 5;
        Matrix<int>  b(2,2);
        b[0][0] = 4;
        b[0][1] = 2;
        b[1][0] = 1;
        b[1][1] = 5;
        Matrix<bool> c(2,2);
        c[0][0] = 1;
        c[0][1] = 0;
        c[1][0] = 1;
        c[1][1] = 1;

        Matrix<bool> test1 = x>=y;
        Matrix<bool> test2 = a>=b;
        CPPUNIT_ASSERT(test1.eq(z));
        CPPUNIT_ASSERT(test2.eq(c));
    }

    void test_greater_than_equals_2 () 
    {
        Matrix<int>  x(1,1);
        Matrix<int>  y(1,1,999);
        Matrix<bool> z(1,1);
        Matrix<bool> t(1,1, false);
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));
        Matrix<int> w(9,9,0);
        try{
            z= x<=w;
            CPPUNIT_ASSERT(false);
        }
        catch(invalid_argument& e)
        {
            CPPUNIT_ASSERT(x.eq(x));
        }
    }

    void test_greater_than_equals_3 () 
    {
        Matrix<int>  x(1,2);
        x[0][0] = 100;
        x[0][1] = 0;
        Matrix<int>  y(1,2);
        y[0][0] = 100;
        y[0][1] = 999;
        Matrix<bool> z(1,2);
        Matrix<bool> t(1,2);
        t[0][0] = true;
        t[0][1] = false;
        z = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));
    }

    // ---------
    // test_plus
    // ---------

    void test_plus_1 ()
    {
        Matrix<int> a(4,4,20);
        Matrix<int> b(4,4,30);
        Matrix<int> z(4,4,50);
        Matrix<int> temp = a + b;
        
        CPPUNIT_ASSERT(temp.eq(z));
    }

    void test_plus_scalar_1 ()
    {
        Matrix<int> a(4,4,20);
        Matrix<int> z(4,4,50);
        Matrix<int> temp = a + 30;
        
        CPPUNIT_ASSERT(temp.eq(z));
    }

    void test_plus_scalar_2 () 
    {
        Matrix<int> x(2, 3, 0);
        Matrix<int> y(2, 3, 2);
        int two = 2;
        CPPUNIT_ASSERT(!x.eq(y));
        x += two;
        CPPUNIT_ASSERT(x.eq(y));
    }
    void test_plus_scalar_3 () 
    {
        Matrix<int> x(69, 96, 27);
        Matrix<int> y(69, 96, 96);
        int n = 69;
        CPPUNIT_ASSERT(!x.eq(y));
        x += n;
        CPPUNIT_ASSERT(x.eq(y));
    }

    void test_plus_equal () 
    {
        Matrix<int> x(4,4,20);
        Matrix<int> y(4,4,30);
        Matrix<int> z(4,4,50);
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_plus_equal_scalar () 
    {
        Matrix<int> x(4,4,20);
        Matrix<int> z(4,4,50);
        x += 30;
        CPPUNIT_ASSERT(x.eq(z));
    }

    // ----------
    // test_minus
    // ----------

    void test_minus () 
    {
        Matrix<int> x(5,5,500);
        Matrix<int> y(5,5,250);
        Matrix<int> z(5,5,250);
        Matrix<int> temp = x-y;
        CPPUNIT_ASSERT(temp.eq(z));
    }

    void test_minus_scalar () 
    {
        Matrix<int> x(5,5,500);
        Matrix<int> z(5,5,250);
        Matrix<int> temp = x-250;
        CPPUNIT_ASSERT(temp.eq(z));
    }

    void test_minus_equal () 
    {
        Matrix<int> x(5,5,500);
        Matrix<int> y(5,5,250);
        Matrix<int> z(5,5,250);
        x-=y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_minus_equal_scalar () 
    {
        Matrix<int> x(5,5,500);
        Matrix<int> z(5,5,250);
        x-=250;
        CPPUNIT_ASSERT(x.eq(z));
    }

    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies () 
    {
        Matrix<int> a(2,3);
        a[0][0]=1;
        a[0][1]=2;
        a[0][2]=3;
        a[1][0]=4;
        a[1][1]=5;
        a[1][2]=6;
        Matrix<int> b(3,2);
        b[0][0]=1;
        b[0][1]=2;
        b[1][0]=3;
        b[1][1]=4;
        b[2][0]=5;
        b[2][1]=6;
        Matrix<int> z(2,2);
        z[0][0]=22;
        z[0][1]=28;
        z[1][0]=49;
        z[1][1]=64;
        Matrix<int> temp = a*b;
        CPPUNIT_ASSERT(temp.eq(z));
    }
    void test_multiplies_scalar () 
    {
        Matrix<int> a(2,3);
        a[0][0]=1;
        a[0][1]=2;
        a[0][2]=3;
        a[1][0]=4;
        a[1][1]=5;
        a[1][2]=6;
        Matrix<int> z(2,3);
        z[0][0]=2;
        z[0][1]=4;
        z[0][2]=6;
        z[1][0]=8;
        z[1][1]=10;
        z[1][2]=12;
        Matrix<int> temp = a*2;
        CPPUNIT_ASSERT(temp.eq(z));
    }

    void test_multiplies_equals () 
    {
        Matrix<int> a(2,3);
        a[0][0]=1;
        a[0][1]=2;
        a[0][2]=3;
        a[1][0]=4;
        a[1][1]=5;
        a[1][2]=6;
        Matrix<int> b(3,2);
        b[0][0]=1;
        b[0][1]=2;
        b[1][0]=3;
        b[1][1]=4;
        b[2][0]=5;
        b[2][1]=6;
        Matrix<int> z(2,2);
        z[0][0]=22;
        z[0][1]=28;
        z[1][0]=49;
        z[1][1]=64;
        a*=b;
        CPPUNIT_ASSERT(a.eq(z));
    }

    void test_multiplies_equals_scalar () 
    {
        Matrix<int> a(2,3);
        a[0][0]=1;
        a[0][1]=2;
        a[0][2]=3;
        a[1][0]=4;
        a[1][1]=5;
        a[1][2]=6;
        Matrix<int> z(2,3);
        z[0][0]=2;
        z[0][1]=4;
        z[0][2]=6;
        z[1][0]=8;
        z[1][1]=10;
        z[1][2]=12;
        a*=2;
        CPPUNIT_ASSERT(a.eq(z));
    }

    // -------------
    // test_iterator
    // -------------

    void test_iterator () {
        Matrix<int> x(2,3,6);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT((b+2) == e);}

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator () {
        const Matrix<int> x(2,3,6);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT((b+2) == e);}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_index_1);
    CPPUNIT_TEST(test_index_2);
    CPPUNIT_TEST(test_index_3);
    CPPUNIT_TEST(test_equals_1);
    CPPUNIT_TEST(test_equals_2);
    CPPUNIT_TEST(test_equals_3);
    CPPUNIT_TEST(test_less_than_1);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
    CPPUNIT_TEST(test_greater_than_1);
    CPPUNIT_TEST(test_greater_than_2);
    CPPUNIT_TEST(test_greater_than_3);
    CPPUNIT_TEST(test_greater_than_equals_1);
    CPPUNIT_TEST(test_greater_than_equals_2);
    CPPUNIT_TEST(test_greater_than_equals_3);
    CPPUNIT_TEST(test_less_than_equals_1);
    CPPUNIT_TEST(test_less_than_equals_2);
    CPPUNIT_TEST(test_less_than_equals_3);
    CPPUNIT_TEST(test_plus_1);
    CPPUNIT_TEST(test_plus_scalar_1);
    CPPUNIT_TEST(test_plus_scalar_2);
    CPPUNIT_TEST(test_plus_scalar_3);
    CPPUNIT_TEST(test_plus_equal);
    CPPUNIT_TEST(test_plus_equal_scalar);
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_minus_scalar);
    CPPUNIT_TEST(test_minus_equal);
    CPPUNIT_TEST(test_minus_equal_scalar);
    CPPUNIT_TEST(test_multiplies);
    CPPUNIT_TEST(test_multiplies_scalar);
    CPPUNIT_TEST(test_multiplies_equals);
    CPPUNIT_TEST(test_multiplies_equals_scalar);
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