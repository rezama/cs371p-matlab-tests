// ------------------------------
// projects/matlab/TestMatrix.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
 * To test the program:
 *      make test
 *      g++ -std=c++0x -ansi -pedantic -lcppunit -ldl -Wall TestMatrix.c++ -o TestMatrix.app
 *      valgrind TestMatrix.app >& TestMatrix.out
 */

// --------
// includes
#include "cppunit/extensions/HelperMacros.h"    // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"                // TestFixture
#include "cppunit/TextTestRunner.h"             // TestRunner

#define private public
#define protected public
#define class struct

#include "Matrix.h"

// ----------
// TestMatrix
struct TestMatrix : CppUnit::TestFixture {

    // ----------------
    // test_constructor1
    // ----------------
    void test_constructor1 () {
        Matrix<int> x(0, 0);
        CPPUNIT_ASSERT(x.size() == 0);
    }

    // ----------------
    // test_constructor2
    // ----------------
    void test_constructor2 () {
        Matrix<int> x(10, 8, 1);
        CPPUNIT_ASSERT(x.size() == 10);
        CPPUNIT_ASSERT((x[0]).size() == 8);
        CPPUNIT_ASSERT(x[0][0] = 1);
    }

    // ----------------
    // test_constructor3
    // ----------------
    void test_constructor3 () {
        Matrix<int> x(8, 10, 0);
        CPPUNIT_ASSERT(x.size() == 8);
        CPPUNIT_ASSERT((x[0]).size() == 10);
        CPPUNIT_ASSERT(x[0][0] == 0);
    }

    // ----------
    // test_index
    // ----------

    void test_index1 () {
        const Matrix<int> x(2, 2, 1);
        
        CPPUNIT_ASSERT(x[0][0] == 1);
        CPPUNIT_ASSERT(x[1][1] == 1);
    }

    void test_index2 () {
        Matrix<int> x(10, 8, 19);

        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++) 
                CPPUNIT_ASSERT(x[i][j] == 19);

        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                CPPUNIT_ASSERT(x[i][j] = 1);
            
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                CPPUNIT_ASSERT(x[i][j] == 1);
    }

    void test_index3 () {
        Matrix<int> x(8, 10, 91);

        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                CPPUNIT_ASSERT(x[i][j] == 91);

        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                CPPUNIT_ASSERT(x[i][j] = -1);

        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                CPPUNIT_ASSERT(x[i][j] == -1);
    }

    // -----------
    // test_equals1
    // -----------
    void test_equals1 () {
        Matrix<bool> z;
        Matrix<bool> w;
        
        CPPUNIT_ASSERT(z.eq(z));
        CPPUNIT_ASSERT(z.eq(w));
    }
    // -----------
    // test_equals2
    // -----------
    void test_equals2 () {
        Matrix<int> x(10, 10, 10);
        Matrix<int> y(10, 10, 10);
        
        CPPUNIT_ASSERT(x.eq(y));
    }

    // -----------
    // test_equals3
    // -----------
    void test_equals3 () {
        Matrix<int> x(10, 10, 10);
        Matrix<int> y(10, 10, -10);
        
        CPPUNIT_ASSERT(!x.eq(y));
    }
    
    // -----------
    // test_equals4
    // -----------
    void test_equals4 () {
        Matrix<int> x(10, 8, 10);
        Matrix<int> y(8, 10, 10);
        CPPUNIT_ASSERT(!x.eq(y));
    }

    // -----------
    // test_eq_op1
    // -----------
    void test_eq_op1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> w;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(w));
    }
    
    // -----------
    // test_eq_op2
    // -----------
    void test_eq_op2 () {
        Matrix<int>  x(10, 8, 1);
        Matrix<int>  y(10, 8, 0);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, false);
        z = (x == y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }
    // -----------
    // test_eq_op3
    // -----------
    void test_eq_op3 () {
        Matrix<int>  x(8, 10, 1);
        Matrix<int>  y(8, 10, 1);
        Matrix<bool> z;
        Matrix<bool> w(8, 10, true);
        z = (x == y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }

    // -----------
    // test_eq_op4
    // -----------
    
    void test_eq_op4 () {
        Matrix<int>  x(10, 8, 1);
        Matrix<int>  y(8, 10, 1);
        try {
            x == y;
            CPPUNIT_ASSERT(false);
        }
        catch(...) {
            CPPUNIT_ASSERT(true);
        }
    }

    // ---------
    // test_less_than1
    // ---------

    void test_less_than1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> w;
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(w));
    }

    // ---------
    // test_less_than2
    // ---------

    void test_less_than2 () {
        Matrix<int>  x(10, 8, 10);
        Matrix<int>  y(10, 8, 10);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, false);
        z = (x < y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }
    
    // ---------
    // test_less_than3
    // ---------
    
    void test_less_than3 () {
        Matrix<int>  x(10, 8, 8);
        Matrix<int>  y(10, 8, 10);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, true);
        z = (x < y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }

    // ---------
    // test_less_than4
    // ---------
    
    void test_less_than4 () {
        Matrix<int>  x(10, 8, 10);
        Matrix<int>  y(10, 8, 8);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, false);
        z = (x < y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }
    
    // ---------
    // test_less_than_or1
    // ---------

    void test_less_than_or1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> w;
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(w));
    }

    // ---------
    // test_less_than_or2
    // ---------

    void test_less_than_or2 () {
        Matrix<int>  x(10, 8, 10);
        Matrix<int>  y(10, 8, 10);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, true);
        z = (x <= y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }
    
    // ---------
    // test_less_than_or3
    // ---------
    
    void test_less_than_or3 () {
        Matrix<int>  x(10, 8, 8);
        Matrix<int>  y(10, 8, 10);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, true);
        z = (x <= y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }

    // ---------
    // test_less_than_or4
    // ---------
    
    void test_less_than_or4 () {
        Matrix<int>  x(10, 8, 10);
        Matrix<int>  y(10, 8, 8);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, false);
        z = (x <= y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }

    // --------------
    // test_ne1
    // --------------
    void test_ne1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> w;
        z = (x != y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }

    // --------------
    // test_ne2
    // --------------
    void test_ne2 () {
        Matrix<int>  x(10, 8, 10);
        Matrix<int>  y(10, 8, 10);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, false);
        z = (x != y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }
    
    // --------------
    // test_ne3
    // --------------
    void test_ne3 () {
        Matrix<int>  x(10, 8, 10);
        Matrix<int>  y(10, 8, -10);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, true);
        z = (x != y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }

    // --------------
    // test_greater_than1
    // --------------

    void test_greater_than1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> w;
        z = (x > y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }
    
    // --------------
    // test_greater_than2
    // --------------

    void test_greater_than2 () {
        Matrix<int>  x(10, 8, 10);
        Matrix<int>  y(10, 8, 10);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, false);
        z = (x > y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }
    
    // --------------
    // test_greater_than3
    // --------------

    void test_greater_than3 () {
        Matrix<int>  x(10, 8, 0);
        Matrix<int>  y(10, 8, 1);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, false);
        z = (x > y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }

    // --------------
    // test_greater_than4
    // --------------

    void test_greater_than4 () {
        Matrix<int>  x(10, 8, 1);
        Matrix<int>  y(10, 8, 0);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, true);
        z = (x > y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }



    // --------------
    // test_greater_than_or1
    // --------------
    void test_greater_than_or1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> w;
        z = (x >= y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }
    
    // --------------
    // test_greater_than_or2
    // --------------
    void test_greater_than_or2 () {
        Matrix<int>  x(10, 8, 10);
        Matrix<int>  y(10, 8, 10);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, true);
        z = (x >= y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }

    // --------------
    // test_greater_than_or3
    // --------------
    void test_greater_than_or3 () {
        Matrix<int>  x(10, 8, 8);
        Matrix<int>  y(10, 8, 10);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, false);
        z = (x >= y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }

    // --------------
    // test_greater_than_or4
    // --------------
    void test_greater_than_or4 () {
        Matrix<int>  x(10, 8, 10);
        Matrix<int>  y(10, 8, 8);
        Matrix<bool> z;
        Matrix<bool> w(10, 8, true);
        z = (x >= y);
        
        CPPUNIT_ASSERT(z.eq(w));
    }
    
    // --------------------
    // test_scalar_add1
    // ---------------------
    void test_scalar_add1() {
        Matrix<int> x(10, 8, 10);
        Matrix<int> y(10, 8, 20);
        x += 10;
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------------------
    // test_scalar_add2
    // ---------------------
    void test_scalar_add2() {
        Matrix<int> x(10, 8, 10);
        Matrix<int> y(10, 8, 10);
        x += 0;
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------------------
    // test_scalar_add3
    // ---------------------
    void test_scalar_add3() {
        Matrix<int> x(10, 8, 10);
        Matrix<int> y(10, 8, 0);
        x += (-10);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------------------
    // test_scalar_sub1
    // ---------------------
    void test_scalar_sub1() {
        Matrix<int> x(10, 8, 10);
        Matrix<int> y(10, 8, 0);
        x -= 10;
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------------------
    // test_scalar_sub2
    // ---------------------
    void test_scalar_sub2() {
        Matrix<int> x(10, 8, 10);
        Matrix<int> y(10, 8, 10);
        x -= 0;
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------------------
    // test_scalar_sub3
    // ---------------------
    void test_scalar_sub3() {
        Matrix<int> x(10, 8, 10);
        Matrix<int> y(10, 8, 20);
        x -= (-10);
        CPPUNIT_ASSERT(x.eq(y));
    }
    
    // --------------------
    // test_scalar_mult1
    // ---------------------
    void test_scalar_mult1() {
        Matrix<int> x(10, 8, 10);
        Matrix<int> y(10, 8, 0);
        x *= 0;
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------------------
    // test_scalar_mult2
    // ---------------------
    void test_scalar_mult2() {
        Matrix<int> x(10, 8, 10);
        Matrix<int> y(10, 8, 10);
        x *= 1;
        CPPUNIT_ASSERT(x.eq(y));
    }

    // --------------------
    // test_scalar_mult3
    // ---------------------
    void test_scalar_mult3() {
        Matrix<int> x(10, 8, 10);
        Matrix<int> y(10, 8, 20);
        x *= 2;
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_matrix_add1
    // ---------
    void test_matrix_add1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    // ---------
    // test_matrix_add2
    // ---------
    void test_matrix_add2 () {
        Matrix<int> x(10,8,1);
        Matrix<int> y(10,8,-1);
        Matrix<int> z(10,8,0);
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    // ---------
    // test_matrix_add3
    // ---------
    void test_matrix_add3 () {
        Matrix<int> x(10,8,1);
        Matrix<int> y(10,8,1);
        Matrix<int> z(10,8,2);
        x += y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    // ---------
    // test_matrix_add4
    // ---------
    void test_matrix_add4 () {
        Matrix<int> x(10,8,1);
        Matrix<int> y(8,10,1);
        Matrix<int> z(10,8,2);
        try{
            x += y;
            CPPUNIT_ASSERT(false);
        }
        catch(...){
            CPPUNIT_ASSERT(true);
        }
    }

    // ---------
    // test_matrix_sub1
    // ---------
    void test_matrix_sub1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    // ---------
    // test_matrix_sub2
    // ---------
    void test_matrix_sub2 () {
        Matrix<int> x(10,8,1);
        Matrix<int> y(10,8,-1);
        Matrix<int> z(10,8,2);
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    // ---------
    // test_matrix_sub3
    // ---------
    void test_matrix_sub3 () {
        Matrix<int> x(10,8,1);
        Matrix<int> y(10,8,1);
        Matrix<int> z(10,8,0);
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    // ---------
    // test_matrix_sub4
    // ---------
    void test_matrix_sub4 () {
        Matrix<int> x(10,8,1);
        Matrix<int> y(8,10,1);
        Matrix<int> z(10,8,2);
        try{
            x -= y;
            CPPUNIT_ASSERT(false);
        }
        catch(...){
            CPPUNIT_ASSERT(true);
        }
    }

    // ---------
    // test_matrix_mult1
    // ---------
    void test_matrix_mult1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
    }

    // ---------
    // test_matrix_mult2
    // ---------
    void test_matrix_mult2 () {
        Matrix<int> x(2,2,0);
        Matrix<int> y(2,2,0);
        int count = 1;
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                x[i][j] = count++;

        y[0][0] = 7;
        y[0][1] = 10;
        y[1][0] = 15;
        y[1][1] = 22;
        
        x = (x * x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_matrix_mult3
    // ---------
    void test_matrix_mult3 () {
        Matrix<int> x(1,3,0);
        Matrix<int> y(3,1,0);
        Matrix<int> z(1,1,0);
        int count = 10;
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                x[i][j] = count++;

        count = 5;
        for(unsigned int i = 0; i < y.size(); i++)
            for(unsigned int j = 0; j < (y[i]).size(); j++)
                y[i][j] = count++;

        x = (x * y);
        z[0][0] = 200;
        CPPUNIT_ASSERT(x.eq(z));
    }

    // ---------
    // test_matrix_mult4
    // ---------
    void test_matrix_mult4 () {
        Matrix<int> x(1,3,0);
        Matrix<int> y(3,1,0);
        Matrix<int> z(3,3,0);
        int count = 10;
        for(unsigned int i = 0; i < x.size(); i++)
            for(unsigned int j = 0; j < (x[i]).size(); j++)
                x[i][j] = count++;

        count = 5;
        for(unsigned int i = 0; i < y.size(); i++)
            for(unsigned int j = 0; j < (y[i]).size(); j++)
                y[i][j] = count++;

        x = (y * x);
        z[0][0] = 50;
        z[0][1] = 55;
        z[0][2] = 60;
        z[1][0] = 60;
        z[1][1] = 66;
        z[1][2] = 72;
        z[2][0] = 70;
        z[2][1] = 77;
        z[2][2] = 84;

        CPPUNIT_ASSERT(x.eq(z));
    }

    // ---------
    // test_matrix_mult5
    // ---------
    void test_matrix_mult5 () {
        Matrix<int> x(10, 8,1);
        Matrix<int> y(10, 8,1);
        try{
            x *= y;
            CPPUNIT_ASSERT(false);
        }
        catch(...){
            CPPUNIT_ASSERT(true);
        }
    }

    // -------------
    // test_iterator1
    // -------------
    void test_iterator1 () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);
    }

    // -------------
    // test_iterator2
    // -------------
    void test_iterator2 () {
        Matrix<int> x(1,1,0);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b != e);
        b++;
        CPPUNIT_ASSERT(b == e);
    }

    // -------------
    // test_iterator3
    // -------------
    void test_iterator3 () {
        Matrix<int> x(1,1,0);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b != e);
        e--;
        CPPUNIT_ASSERT(b == e);
    }

    // -------------------
    // test_const_iterator1
    // -------------------
    void test_const_iterator1 () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);
    }

    // -------------------
    // test_const_iterator2
    // -------------------
    void test_const_iterator2 () {
        const Matrix<int> x(1,1,0);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b != e);
    }

    // -------------------
    // test_const_iterator3
    // -------------------
    void test_const_iterator3 () {
        const Matrix<int> x(1,1,0);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b != e);
        try{
            b++;
            CPPUNIT_ASSERT(false);
        }
        catch (...) {
            CPPUNIT_ASSERT(true);
        }
    }


    // -------------------
    // test_empty1
    // -------------------
    void test_empty1 () {
        const Matrix<int> x;
        CPPUNIT_ASSERT(x.empty());
    }

    // -------------------
    // test_empty2
    // -------------------
    void test_empty2 () {
        const Matrix<int> x(1,1,1);
        CPPUNIT_ASSERT(!x.empty());
    }

    // -------------------
    // test_empty3
    // -------------------
    void test_empty3 () {
        const Matrix<int> x(0,0,0);
        CPPUNIT_ASSERT(x.empty());
    }

    // -------------------
    // test_push_back1
    // -------------------
    void test_push_back1 () {
        Matrix<int> x;
        CPPUNIT_ASSERT(x.empty());
        std::vector<int> y;
        y.push_back(1);
        x.push_back(y);
        CPPUNIT_ASSERT(!x.empty());
        CPPUNIT_ASSERT(x[0][0] == 1);
    }

    // -------------------
    // test_push_back2
    // -------------------
    void test_push_back2 () {
        Matrix<int> x;
        CPPUNIT_ASSERT(x.empty());
        std::vector<int> y;
        y.push_back(10);
        y.push_back(1);
        x.push_back(y);
        x.push_back(y);
        CPPUNIT_ASSERT(!x.empty());
        CPPUNIT_ASSERT(x[0][0] == 10);
        CPPUNIT_ASSERT(x[0][1] == 1);
        CPPUNIT_ASSERT(x[1][0] == 10);
        CPPUNIT_ASSERT(x[1][1] == 1);
    }

    // -------------------
    // test_push_back3
    // -------------------
    void test_push_back3 () {
        Matrix<int> x;
        CPPUNIT_ASSERT(x.empty());
        std::vector<int> y;
        x.push_back(y);
        CPPUNIT_ASSERT(!x.empty());
        CPPUNIT_ASSERT((x[0]).empty());
    }

    // -------------------
    // test_size1
    // -------------------
    void test_size1 () {
        Matrix<int> x;
        CPPUNIT_ASSERT(x.size() == 0);
    }

    // -------------------
    // test_size2
    // -------------------
    void test_size2 () {
        Matrix<int> x(10, 8, 1);
        CPPUNIT_ASSERT(x.size() == 10);
        CPPUNIT_ASSERT((x[0]).size() == 8);
    }

    // -------------------
    // test_size3
    // -------------------
    void test_size3 () {
        Matrix<int> x(8, 10, 1);
        CPPUNIT_ASSERT(x.size() == 8);
        CPPUNIT_ASSERT((x[0]).size() == 10);
    }

    // -------------------
    // test_valid1
    // -------------------
    void test_valid1 () {
        Matrix<int> x;
        std::vector<int> y;
        x.push_back(y);
        CPPUNIT_ASSERT(x.valid());
    }

    // -------------------
    // test_valid2
    // -------------------
    void test_valid2 () {
        Matrix<int> x(3, 3, 1);
        std::vector<int> y;
        y.push_back(1);
        y.push_back(2);
        y.push_back(3);
        x.push_back(y);
        CPPUNIT_ASSERT(x.valid());
    }

    // -------------------
    // test_valid3
    // -------------------
    void test_valid3 () {
        Matrix<int> x(3, 3, 1);
        std::vector<int>& y = x[2];
        y.pop_back();

        CPPUNIT_ASSERT(!x.valid());
    }

    // -------------------
    // test_eq_dim1
    // -------------------
    void test_eq_dim1 () {
        Matrix<int> x;
        Matrix<int> y;
        CPPUNIT_ASSERT(x.eq_dim(x,y));
    }

    // -------------------
    // test_eq_dim2
    // -------------------
    void test_eq_dim2 () {
        Matrix<int> x(10, 8, 1);
        Matrix<int> y(10, 8, -100);
        CPPUNIT_ASSERT(x.eq_dim(x,y));
    }

    // -------------------
    // test_eq_dim3
    // -------------------
    void test_eq_dim3 () {
        Matrix<int> x(8, 10, 1);
        Matrix<int> y(10, 8, 1);
        CPPUNIT_ASSERT(!x.eq_dim(x,y));
    }



    // -----
    // suite
    CPPUNIT_TEST_SUITE(TestMatrix);

    CPPUNIT_TEST(test_constructor1);
    CPPUNIT_TEST(test_constructor2);
    CPPUNIT_TEST(test_constructor3);
    CPPUNIT_TEST(test_index1);
    CPPUNIT_TEST(test_index2);
    CPPUNIT_TEST(test_index3);

    CPPUNIT_TEST(test_equals1);
    CPPUNIT_TEST(test_equals2);
    CPPUNIT_TEST(test_equals3);
    CPPUNIT_TEST(test_equals4);

    CPPUNIT_TEST(test_eq_op1);
    CPPUNIT_TEST(test_eq_op2);
    CPPUNIT_TEST(test_eq_op3);
    CPPUNIT_TEST(test_eq_op4);

    CPPUNIT_TEST(test_less_than1);
    CPPUNIT_TEST(test_less_than2);
    CPPUNIT_TEST(test_less_than3);
    CPPUNIT_TEST(test_less_than4);

    CPPUNIT_TEST(test_less_than_or1);
    CPPUNIT_TEST(test_less_than_or2);
    CPPUNIT_TEST(test_less_than_or3);
    CPPUNIT_TEST(test_less_than_or4);

    CPPUNIT_TEST(test_ne1);
    CPPUNIT_TEST(test_ne2);
    CPPUNIT_TEST(test_ne3);

    CPPUNIT_TEST(test_greater_than1);
    CPPUNIT_TEST(test_greater_than2);
    CPPUNIT_TEST(test_greater_than3);
    CPPUNIT_TEST(test_greater_than4);

    CPPUNIT_TEST(test_greater_than_or1);
    CPPUNIT_TEST(test_greater_than_or2);
    CPPUNIT_TEST(test_greater_than_or3);
    CPPUNIT_TEST(test_greater_than_or4);

    CPPUNIT_TEST(test_scalar_add1);
    CPPUNIT_TEST(test_scalar_add2);
    CPPUNIT_TEST(test_scalar_add3);

    CPPUNIT_TEST(test_scalar_sub1);
    CPPUNIT_TEST(test_scalar_sub2);
    CPPUNIT_TEST(test_scalar_sub3);

    CPPUNIT_TEST(test_scalar_mult1);
    CPPUNIT_TEST(test_scalar_mult2);
    CPPUNIT_TEST(test_scalar_mult3);

    CPPUNIT_TEST(test_matrix_add1);
    CPPUNIT_TEST(test_matrix_add2);
    CPPUNIT_TEST(test_matrix_add3);
    CPPUNIT_TEST(test_matrix_add4);

    CPPUNIT_TEST(test_matrix_sub1);
    CPPUNIT_TEST(test_matrix_sub2);
    CPPUNIT_TEST(test_matrix_sub3);
    CPPUNIT_TEST(test_matrix_sub4);

    CPPUNIT_TEST(test_matrix_mult1);
    CPPUNIT_TEST(test_matrix_mult2);
    CPPUNIT_TEST(test_matrix_mult3);
    CPPUNIT_TEST(test_matrix_mult4);

    CPPUNIT_TEST(test_iterator1);
    CPPUNIT_TEST(test_iterator2);
    CPPUNIT_TEST(test_iterator3);

    CPPUNIT_TEST(test_const_iterator1);
    CPPUNIT_TEST(test_const_iterator2);
    CPPUNIT_TEST(test_const_iterator3);

    CPPUNIT_TEST(test_push_back1);
    CPPUNIT_TEST(test_push_back2);
    CPPUNIT_TEST(test_push_back3);

    CPPUNIT_TEST(test_size1);
    CPPUNIT_TEST(test_size2);
    CPPUNIT_TEST(test_size3);

    CPPUNIT_TEST(test_valid1);
    CPPUNIT_TEST(test_valid2);
    CPPUNIT_TEST(test_valid3);

    CPPUNIT_TEST(test_eq_dim1);
    CPPUNIT_TEST(test_eq_dim2);
    CPPUNIT_TEST(test_eq_dim3);

    CPPUNIT_TEST_SUITE_END();
};

// ----
// main
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);   // turn off synchronization with C I/O
    cout << "TestMatrix.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestMatrix::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}