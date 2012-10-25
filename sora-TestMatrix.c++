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

#define private public
#include "Matrix.h"

// ----------
// TestMatrix
// ----------

struct TestMatrix : CppUnit::TestFixture {
    // ----------------
    // test_constructor
    // ----------------

    void test_constructor_1 () {
        Matrix<int> x;
        CPPUNIT_ASSERT(x.size() == 0);}
    
    void test_constructor_2 () {
        Matrix<int> y(2);
        Matrix<int> z(3, 3);
        CPPUNIT_ASSERT(y.size() == 2 && z.size() == 3);}
    
    void test_constructor_3 () {
        Matrix<int> t(3, 4, 5);
        Matrix<int> s(3, 4, 5);
        CPPUNIT_ASSERT(t.size() == 3);
        CPPUNIT_ASSERT(t.eq(s));
        for (int i=0; i<3; ++i) {
            for (int j=0; j<4; ++j) {
                CPPUNIT_ASSERT(t[i][j]==5);
            }
        }
    }

    // ----------------
    // test_valid
    // ----------------
    
    void test_valid_1 () {
        Matrix<int> x;
        CPPUNIT_ASSERT(x.valid());}
    
    void test_valid_2 () {
        Matrix<int> x(2);
        Matrix<int> y(3, 3);
        Matrix<int> z(3, 3, 4);
        CPPUNIT_ASSERT(x.valid() && y.valid() && z.valid());}
    
    void test_valid_3 () {
        Matrix<int> x(3, 4, 5);
        x[0].pop_back();
        CPPUNIT_ASSERT(!x.valid());
    }
    
    // ----------
    // test_index
    // ----------

    void test_index_1 () {
        const Matrix<int> x(1,1,1);
        CPPUNIT_ASSERT(x[0][0] == 1);}
    
    void test_index_2 () {
        Matrix<int> x(3,4,5);
        for (int i=0; i<3; ++i) {
            for (int j=0; j<4; ++j) {
                x[i][j] = i+j;
            }
        }
        for (int i=0; i<3; ++i) {
            for (int j=0; j<4; ++j) {
                CPPUNIT_ASSERT(x[i][j] == i+j);}}}
    
    void test_index_3 () {
        Matrix<int> x(3,4,99);
        Matrix<int> y(3,4,5);
        for (int i=0; i<3; ++i) {
            for (int j=0; j<4; ++j) {
                x[i][j] = 5;
            }
        }
        CPPUNIT_ASSERT(x.eq(y));}
    
    // -----------
    // test_eq
    // -----------
    
    void test_eq_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_eq_2 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(10,10,2);
        CPPUNIT_ASSERT(!x.eq(y));}
    
    void test_eq_3 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(10,10,1);
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_eq_4 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(10,5,1);
        CPPUNIT_ASSERT(!x.eq(y));}
    
    // -----------
    // test_equals
    // -----------

    void test_equals_1 () 
    { 
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        try 
        {
            z = (x == y);
            CPPUNIT_ASSERT(z.eq(t));
        }
        
        catch (std::invalid_argument)
        {
           CPPUNIT_ASSERT(false);
        }
    }
    
    void test_equals_2 () 
    {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(10,10,1);
        Matrix<bool> z(10,10,true);
        Matrix<bool> t;
        try 
        {  
            t = (x == y);
            CPPUNIT_ASSERT(z.eq(t));
        }
        
        catch (std::invalid_argument) 
        {
           CPPUNIT_ASSERT(false);
        }
         
     }
    
    void test_equals_3 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,false);
        Matrix<bool> t;
        
        
        try 
        { 
            t = (x == y);
            CPPUNIT_ASSERT(z.eq(t));
        }
        
        catch (std::invalid_argument) {
          
            CPPUNIT_ASSERT(false);
        }
    }
    
    void test_equals_4 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(11,10,2);
        Matrix<bool> z(10,10,false);
        Matrix<bool> t;
        
        
        try 
        { 
            t = (x == y);
            CPPUNIT_ASSERT(false);
        }
        
        catch (std::invalid_argument) {
          
            CPPUNIT_ASSERT(true);
        }
    }   

    
    // -----------
    // test_not_equals
    // -----------
    
    void test_not_equals_1 () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x != y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_not_equals_2 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(10,10,1);
        Matrix<bool> z(10,10,false);
        Matrix<bool> t;
        t = (x != y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_not_equals_3 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,true);
        Matrix<bool> t;
        t = (x != y);
        CPPUNIT_ASSERT(z.eq(t));}
        
    void test_not_equals_4 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(11,12,2);
        Matrix<bool> z(10,10,true);
        Matrix<bool> t;  
        
        try{
            t = (x != y);
            CPPUNIT_ASSERT(false);  
        }
        
        catch (std::invalid_argument){
            CPPUNIT_ASSERT(true);  
        }
        
        }        

    // --------------
    // test_less_than
    // --------------

    void test_less_than_1 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,true);
        Matrix<bool> t;
        t = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_2 () {
        Matrix<int>  x(10,10,2);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,false);
        Matrix<bool> t;
        t = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_3 () {
        Matrix<int>  x(10,10,3);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,false);
        Matrix<bool> t;
        t = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    void test_less_than_4 () {
        Matrix<int> x(2,2);
        Matrix<int> y(2,2);
        Matrix<bool> z(2,2);
        int values_x[] = {1,-2,
            3,-1};
        int values_y[] = {0,3,
            -2,-1};
        bool values_z[] = {false,true,
            false,false};
        int k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                z[i][j] = values_z[k];
                k++;
            }
        }
        CPPUNIT_ASSERT(z.eq(x<y));}
        
     void test_less_than_5 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(11,12,2);
        Matrix<bool> z(10,10,true);
        Matrix<bool> t;       
        
        try{
            t = (x < y);
            CPPUNIT_ASSERT(false);  
        }
        
        catch (std::invalid_argument){
            CPPUNIT_ASSERT(true);  
        }
     }
    
    
    // --------------
    // test_less_than_eq
    // --------------
    
    void test_less_than_eq_1 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,true);
        Matrix<bool> t;
        t = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_eq_2 () {
        Matrix<int>  x(10,10,2);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,true);
        Matrix<bool> t;
        t = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_eq_3 () {
        Matrix<int>  x(10,10,3);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,false);
        Matrix<bool> t;
        t = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    void test_less_than_eq_4 () {
        Matrix<int> x(2,2);
        Matrix<int> y(2,2);
        Matrix<bool> z(2,2);
        int values_x[] = {1,-2,
            3,-1};
        int values_y[] = {0,3,
            -2,-1};
        bool values_z[] = {false,true,
            false,true};
        int k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                z[i][j] = values_z[k];
                k++;
            }
        }
        CPPUNIT_ASSERT(z.eq(x<=y));}
        
    void test_less_than_eq_5 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(11,12,2);
        Matrix<bool> z(10,10,true);
        Matrix<bool> t;       
        
        try{
            t = (x <= y);
            CPPUNIT_ASSERT(false);  
        }
        
        catch (std::invalid_argument){
            CPPUNIT_ASSERT(true);  
        }      
    }
           
    
    // --------------
    // test_larger_than
    // --------------
    
    void test_larger_than_1 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,false);
        Matrix<bool> t;
        t = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    void test_larger_than_2 () {
        Matrix<int>  x(10,10,2);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,false);
        Matrix<bool> t;
        t = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    void test_larger_than_3 () {
        Matrix<int>  x(10,10,3);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,true);
        Matrix<bool> t;
        t = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    void test_larger_than_4 () {
        Matrix<int> x(2,2);
        Matrix<int> y(2,2);
        Matrix<bool> z(2,2);
        int values_x[] = {1,-2,
            3,-1};
        int values_y[] = {0,3,
            -2,-1};
        bool values_z[] = {true,false,
            true,false};
        int k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                z[i][j] = values_z[k];
                k++;
            }
        }
        CPPUNIT_ASSERT(z.eq(x>y));}
        
    void test_larger_than_5 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(99,10,2);
        Matrix<bool> z(10,10,false);
        Matrix<bool> t;
        
        
        try{
            t = (x > y);
            CPPUNIT_ASSERT(false);  
        }
        
        catch (std::invalid_argument){
            CPPUNIT_ASSERT(true);  
        }   
       }        
    
    
    // --------------
    // test_larger_than_eq
    // --------------
    
    void test_larger_than_eq_1 () {
        Matrix<int>  x(10,10,1);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,false);
        Matrix<bool> t;
        t = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    void test_larger_than_eq_2 () {
        Matrix<int>  x(10,10,2);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,true);
        Matrix<bool> t;
        t = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    void test_larger_than_eq_3 () {
        Matrix<int>  x(10,10,3);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,true);
        Matrix<bool> t;
        t = (x >= y);
        CPPUNIT_ASSERT(z.eq(t));}
    
    void test_larger_than_eq_4 () {
        Matrix<int> x(2,2);
        Matrix<int> y(2,2);
        Matrix<bool> z(2,2);
        int values_x[] = {1,-2,
            3,-1};
        int values_y[] = {0,3,
            -2,-1};
        bool values_z[] = {true,false,
            true,true};
        int k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                z[i][j] = values_z[k];
                k++;
            }
        }
        CPPUNIT_ASSERT(z.eq(x>=y));}
        
     void test_larger_than_eq_5 () {
        Matrix<int>  x(999,10,1);
        Matrix<int>  y(10,10,2);
        Matrix<bool> z(10,10,false);
        Matrix<bool> t;
        
        
        try{
            t = (x >= y);
            CPPUNIT_ASSERT(false);  
        }
        
        catch (std::invalid_argument){
            CPPUNIT_ASSERT(true);  
        } 
        }       
    
    // ---------
    // test_plus
    // ---------
    void test_plus_1 () {
        Matrix<int> x(2,2);
        Matrix<int> y(2,2);
        int values_x[] = {1,-2,
            3,-1};
        int k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                x[i][j] = values_x[k];
                y[i][j] = values_x[k];
                k++;
            }
        }
        x += 0;
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_plus_2 () {
        Matrix<int> x(2,3,1);
        Matrix<int> y(2,3,2);
        Matrix<int> z(2,3,3);
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}
    
    void test_plus_3 () {
        Matrix<int> x(2,2);
        Matrix<int> y(2,2);
        Matrix<int> z(2,2);
        int values_x[] = {1,-2,
            3,-1};
        int values_y[] = {0,3,
            -2,-1};
        int values_z[] = {1,1,
            1,-2};
        int k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                z[i][j] = values_z[k];
                k++;
            }
        }
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}
        
    void test_plus_4 () {
        Matrix<int> x(2,3,1);
        Matrix<int> y;
        
        try{
            x += y;
            CPPUNIT_ASSERT(false);  
        }catch (std::invalid_argument){
            CPPUNIT_ASSERT(true);  
        }        
    }        

    // ----------
    // test_minus
    // ----------
    void test_minus_1 () {
        Matrix<int> x(2,2,1);
        x -= 0;
        CPPUNIT_ASSERT(x.eq(x));}
    
    void test_minus_2 () {
        Matrix<int> x(2,3,4);
        Matrix<int> y(2,3,3);
        Matrix<int> z(2,3,1);
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}
    
    void test_minus_3 () {
        Matrix<int> x(2,2);
        Matrix<int> y(2,2);
        Matrix<int> z(2,2);
        int values_x[] = {1,-2,
            3,-1};
        int values_y[] = {0,3,
            -2,-1};
        int values_z[] = {1,-5,
            5,0};
        int k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                z[i][j] = values_z[k];
                k++;
            }
        }
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));
        x -= 1;
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                z[i][j] -= 1;
            }
        }
        CPPUNIT_ASSERT(x.eq(z));}
        
    void test_minus_4 () {
        Matrix<int> x(2,3,4);
        Matrix<int> y;
        
        try{
            x -= y;
            CPPUNIT_ASSERT(false);  
        }catch (std::invalid_argument){
            CPPUNIT_ASSERT(true);  
        }  
}        

    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies_1 () {
        Matrix<int> x;
        Matrix<int> y;
        x *= y;
        CPPUNIT_ASSERT(x.eq(y));}
    
    void test_multiplies_2 () {
        Matrix<int> x(2,2,1);
        Matrix<int> zz(2,2,0);
        x *= 0;
        CPPUNIT_ASSERT(x.eq(zz));}
    
    void test_multiplies_3 () {
        Matrix<int> x(2,3);
        Matrix<int> y(3,2);
        Matrix<int> z(2,2);
        Matrix<int> zz(2,2,0);
        int values_x[] = {1,0,-2,
            0,3,-1};
        int values_y[] = {0,3,
            -2,-1,
            0,4};
        int values_z[] = {0,-5,
            -6,-7};
        int k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<3; ++j) {
                x[i][j] = values_x[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<2; ++j) {
                y[i][j] = values_y[k];
                k++;
            }
        }
        k=0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<2; ++j) {
                z[i][j] = values_z[k];
                k++;
            }
        }
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));
        x *= 0;
        CPPUNIT_ASSERT(x.eq(zz));}
        
    void test_multiplies_4 () {
        Matrix<int> x(2,2,1);
        Matrix<int> zz(3,2,0);
        
        try{
            x *= zz;
            CPPUNIT_ASSERT(false);  
        }
        
        catch (std::invalid_argument){
            CPPUNIT_ASSERT(true);        
        }
        
    }

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
        
    // -------------------
    // test_num_rows
    // -------------------

    void test_num_rows_1 () {
        const Matrix<int> x;
        int rows = x.num_r();
        CPPUNIT_ASSERT(rows == 0);}
        
    void test_num_rows_2 () {
        const Matrix<int> x(30, 49);
        int rows = x.num_r();
        CPPUNIT_ASSERT(rows == 30);}
              
    void test_num_rows_3 () {
        Matrix<int> x(30, 49);
        x *= 0;
        int rows = x.num_r();
        CPPUNIT_ASSERT(rows == 30);}     
    // -------------------
    // test_num_cols
    // -------------------

    void test_num_cols_1 () {
        const Matrix<int> x;
        int columns = x.num_c();
        CPPUNIT_ASSERT(columns == 0);}
        
    void test_num_cols_2 () {
        const Matrix<int> x(30, 49);
        int columns = x.num_c();
        CPPUNIT_ASSERT(columns == 49);}
              
    void test_num_cols_3 () {
        Matrix<int> x(30, 49);
        x *= 0;
        int columns = x.num_c();
        CPPUNIT_ASSERT(columns == 49);}      

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_valid_1);
    CPPUNIT_TEST(test_valid_2);
    CPPUNIT_TEST(test_valid_3);
    CPPUNIT_TEST(test_index_1);
    CPPUNIT_TEST(test_index_2);
    CPPUNIT_TEST(test_index_3);
    CPPUNIT_TEST(test_eq_1);
    CPPUNIT_TEST(test_eq_2);
    CPPUNIT_TEST(test_eq_3);
    CPPUNIT_TEST(test_eq_4);
    CPPUNIT_TEST(test_equals_1);
    CPPUNIT_TEST(test_equals_2);
    CPPUNIT_TEST(test_equals_3);
    CPPUNIT_TEST(test_equals_4);    
    CPPUNIT_TEST(test_not_equals_1);
    CPPUNIT_TEST(test_not_equals_2);
    CPPUNIT_TEST(test_not_equals_3);
    CPPUNIT_TEST(test_not_equals_4);
    CPPUNIT_TEST(test_less_than_1);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
    CPPUNIT_TEST(test_less_than_4);
    CPPUNIT_TEST(test_less_than_5);
    CPPUNIT_TEST(test_less_than_eq_1);
    CPPUNIT_TEST(test_less_than_eq_2);
    CPPUNIT_TEST(test_less_than_eq_3);
    CPPUNIT_TEST(test_less_than_eq_4);
    CPPUNIT_TEST(test_larger_than_1);
    CPPUNIT_TEST(test_larger_than_2);
    CPPUNIT_TEST(test_larger_than_3);
    CPPUNIT_TEST(test_larger_than_4);
    CPPUNIT_TEST(test_larger_than_5);
    CPPUNIT_TEST(test_larger_than_eq_1);
    CPPUNIT_TEST(test_larger_than_eq_2);
    CPPUNIT_TEST(test_larger_than_eq_3);
    CPPUNIT_TEST(test_larger_than_eq_4);
    CPPUNIT_TEST(test_larger_than_eq_5);
    CPPUNIT_TEST(test_plus_1);
    CPPUNIT_TEST(test_plus_2);
    CPPUNIT_TEST(test_plus_3);
    CPPUNIT_TEST(test_plus_4);    
    CPPUNIT_TEST(test_minus_1);
    CPPUNIT_TEST(test_minus_2);
    CPPUNIT_TEST(test_minus_3);
    CPPUNIT_TEST(test_minus_4);    
    CPPUNIT_TEST(test_multiplies_1);
    CPPUNIT_TEST(test_multiplies_2);
    CPPUNIT_TEST(test_multiplies_3);
    CPPUNIT_TEST(test_multiplies_4);
    CPPUNIT_TEST(test_num_rows_1);
    CPPUNIT_TEST(test_num_rows_2);
    CPPUNIT_TEST(test_num_rows_3);
    CPPUNIT_TEST(test_num_cols_1);
    CPPUNIT_TEST(test_num_cols_2);
    CPPUNIT_TEST(test_num_cols_3);    
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
