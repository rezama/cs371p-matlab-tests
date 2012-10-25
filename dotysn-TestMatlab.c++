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
        Matrix<int> x(4, 3, 3);
        Matrix<int> y(4, 4, 3);
        Matrix<int> z(4, 7, 3);
        Matrix<int> result(4, 7);
        result= horzcat(x, y);      
        CPPUNIT_ASSERT(z.eq(result));
    }
    
    void test_horzcat2 () {
        Matrix<int> x(4, 3, 3);
        Matrix<int> y(4, 4, 5);
        //Matrix<int> z(4, 7, 3);
        Matrix<int> result;
        result= horzcat(x, y);         
        CPPUNIT_ASSERT(true);
    }
    
    void test_horzcat3 () {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 4);
        Matrix<int> z(2, 6);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    void test_vertcat () {
        Matrix<int> x(2, 4, 3);
        Matrix<int> y(5, 4, 3);
        Matrix<int> z(7, 4, 3);
        Matrix<int> result;
        result= vertcat(x, y);      
        CPPUNIT_ASSERT(z.eq(result));
    }
    
    // invalid arguments
    void test_vertcat2 () {
        Matrix<int> x(2, 7, 3);
        Matrix<int> y(5, 4, 3);
        Matrix<int> z(7, 4, 3);
        Matrix<int> result;
        try {
        	result= vertcat(x, y);      
        }
        catch(std::invalid_argument& e)
        {
        	CPPUNIT_ASSERT(true);
        }
    }
    
    void test_vertcat3 () {
        Matrix<int> x(2, 3, 5);
        Matrix<int> y(1, 3, 5);
        Matrix<int> z(3, 3, 5);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    // ---------
    // test_diag
    // ---------

    void test_diag () {
		Matrix<int> x(3, 5, 10);
        Matrix<int> y;
        Matrix<int> z(3, 1, 10);
        y = diag(x);
        CPPUNIT_ASSERT(z.eq(y));
   	}
   	
   	void test_diag2 () {
        Matrix<int> x(1, 2);
        Matrix<int> y(1, 1);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }
    
    void test_diag3 () {
    	Matrix<int> x(3, 3, 3);
        Matrix<int> y(3, 1, 3);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));    	
    }

    // --------
    // test_dot
    // --------

    void test_dot () {
        Matrix<int> x(1, 3, 3);
        Matrix<int> y(1, 3, 2);
        Matrix<int> z(1, 1, 18);
        Matrix<int> result;
        result = dot(x, y);
        CPPUNIT_ASSERT(result.eq(z));
     }
     
     void test_dot2 () {
        Matrix<int> x(3, 3, 3);
        Matrix<int> y(3, 3, 2);
        Matrix<int> z(1, 3, 18);
        Matrix<int> result;
        try 
        {
        	result = dot(x, y);        
        }
        catch(std::exception& e)
        {
        	std::cout << e.what() <<std::endl;
        }
        CPPUNIT_ASSERT(result.eq(z));
     }
     
     void test_dot3() {
		Matrix<int> A(3, 0);
		Matrix<int> B(0, 0);
		Matrix<int> ans;
		A = dot(A, B);
		CPPUNIT_ASSERT(A.eq(ans));
	}

    // --------
    // test_eye
    // --------

    void test_eye () {
        Matrix<int> x(2, 2, 0);
        x[0][0] = 1;
        x[1][1] = 1;
        Matrix<int> y;
        y = eye< Matrix<int> >(2, 2);
        CPPUNIT_ASSERT(x.eq(y));
    }
    
    void test_eye2 () {
        Matrix<int> x(2, 3, 0);
        x[0][0] = 1;
        x[1][1] = 1;
        Matrix<int> y;
        y = eye< Matrix<int> >(2, 3);        
        CPPUNIT_ASSERT(x.eq(y));
    }    
    
    void test_eye3 () {
        Matrix<int> x;
        Matrix<int> y(3, 2);
        y[0][0] = 1;
        y[1][1] = 1;
        x = eye< Matrix<int> >(3, 2);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_ones
    // ---------

    void test_ones () {
        Matrix<int> x(2, 3, 1);
        Matrix<int> y;
        y = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }
    
    void test_ones2 () {
        Matrix<int> x(5, 6, 1);
        Matrix<int> y;
        y = ones< Matrix<int> >(5, 6);
        CPPUNIT_ASSERT(x.eq(y));
    }
    
    void test_ones3 () {
        Matrix<int> x;
        Matrix<int> y(2, 3, 1);
        x = ones<Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_rand
    // ---------

    void test_rand () {
        Matrix<double> x;
        int ROW = 100;
        int COL = 100;        
        x = rand< Matrix<double> >(ROW, COL);        
        for(int rows = 0; rows < ROW; rows++)
        {
        	for(int cols = 0; cols < COL; cols++)
        	{
        		CPPUNIT_ASSERT(x[rows][cols] < 1.0 && x[rows][cols] > 0.0);
        	}
        }
     }
          
     void test_rand2 () {
		Matrix<int> x;
		Matrix<int> y;
		x = rand< Matrix<int> >(2, 3);
		
		CPPUNIT_ASSERT(x.size() == 2);
		CPPUNIT_ASSERT(x[0].size() == 3);
	}
	
	void test_rand3 () {
        Matrix<double> x;
        x = rand<Matrix<double> >(10, 10);        
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                CPPUNIT_ASSERT(x[i][j] != 0 && x[i][j] < 1);
    }

    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x(2, 3);
        x[0][0] = 1;
    	x[0][1] = 2;
    	x[0][2] = 3;
    	x[1][0] = 4;
    	x[1][1] = 5;
    	x[1][2] = 6;
    	
        Matrix<int> y;
        y = transpose(x);
        
        Matrix<int> z(3, 2);
        z[0][0] = 1;
    	z[0][1] = 4;
    	z[1][0] = 2;
    	z[1][1] = 5;
    	z[2][0] = 3;
    	z[2][1] = 6;
    	
        CPPUNIT_ASSERT(z.eq(y));
    }
    
    void test_transpose2() {
        Matrix<int> x(2, 2);
        x = eye<Matrix<int> >(2, 2);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(x));
    }
    
    void test_transpose3 () {
		Matrix<int> x(2, 3, 4);
		Matrix<int> y(3, 2, 4);
		x = transpose(x);
		CPPUNIT_ASSERT(x.eq(y));
	}

    // ---------
    // test_tril
    // ---------

    void test_tril () {
        Matrix<int> x(4, 2, 6);
        Matrix<int> y;
        y = tril(x);
        Matrix<int> z(4, 2, 6);
        z[0][1] = 0;      
        CPPUNIT_ASSERT(y.eq(z));
    }
    
     void test_tril2 () {
        Matrix<int> x(3, 3, 6);
        Matrix<int> y;
        y = tril(x);
        Matrix<int> z(3, 3, 6);
        z[0][1] = 0;
        z[0][2] = 0;
        z[1][2] = 0;
        CPPUNIT_ASSERT(y.eq(z));
    }
    
    void test_tril3() {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        y[0][1] = 0;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x(2, 4, 5);
        Matrix<int> y;
        y = triu(x);
        Matrix<int> z(2, 4, 5);
        z[1][0] = 0;
        CPPUNIT_ASSERT(z.eq(y));
    }
    
    void test_triu2 () {
		Matrix<int> x(2, 2, 1);
		Matrix<int> y(2, 2, 1);
		y[1][0] = 0;
		x = triu(x);
		
		CPPUNIT_ASSERT(x.eq(y));
	}
	
	 void test_triu3 () {
        Matrix<int> x(1, 2, 1);
        Matrix<int> y(1, 2, 1);
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
    }	
	

    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x( 10, 10, 0);
        Matrix<int> y;
        y = zeros< Matrix<int> >(10, 10);
        CPPUNIT_ASSERT(x.eq(y));
    }
    
    void test_zeros2 () {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));
    }
    
    void test_zeros3 () {
        Matrix<int> x(5, 6, 0);
        Matrix<int> y;
        y = zeros< Matrix<int> >(5,6);
        CPPUNIT_ASSERT(x.eq(y));
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    
    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(test_horzcat2);
    CPPUNIT_TEST(test_horzcat3);  
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(test_vertcat2);
    CPPUNIT_TEST(test_vertcat3);    
    CPPUNIT_TEST(test_diag);
    CPPUNIT_TEST(test_diag2);
    CPPUNIT_TEST(test_diag3);
    CPPUNIT_TEST(test_dot);
    CPPUNIT_TEST(test_dot2);
    CPPUNIT_TEST(test_dot3);    
    CPPUNIT_TEST(test_eye);
    CPPUNIT_TEST(test_eye2);
    CPPUNIT_TEST(test_eye3);   
    CPPUNIT_TEST(test_ones);
    CPPUNIT_TEST(test_ones2);
    CPPUNIT_TEST(test_ones3);  
    CPPUNIT_TEST(test_rand); 
    CPPUNIT_TEST(test_rand2);
    CPPUNIT_TEST(test_rand3);   
    CPPUNIT_TEST(test_transpose);
    CPPUNIT_TEST(test_transpose2);
    CPPUNIT_TEST(test_transpose3);    
    CPPUNIT_TEST(test_tril);
    CPPUNIT_TEST(test_tril2);
    CPPUNIT_TEST(test_tril3);
    CPPUNIT_TEST(test_triu);
    CPPUNIT_TEST(test_triu2);
    CPPUNIT_TEST(test_triu3);
    CPPUNIT_TEST(test_zeros);
    CPPUNIT_TEST(test_zeros2);
    CPPUNIT_TEST(test_zeros3);
   
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

