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
        Matrix<int> x(2,2,2);
        Matrix<int> y(2,4,2);
        Matrix<int> z(2,6,2);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
							//addl unit tests
							
	void test_horzcat_empty() {
		Matrix<int> x;
		Matrix<int> y;
		Matrix<int> z;
		x = horzcat(x, y);
		CPPUNIT_ASSERT(x.eq(z));
	}
        
    void test_horzcat_2 () {
        Matrix<int> x(2, 2);
        Matrix<int> y(2, 4);
        Matrix<int> z(2, 6);
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
     }
        				 //end addl horzcat tests      							
							
							
    void test_vertcat () {
        Matrix<int> x(2,2,2);
        Matrix<int> y(4,2,2);
        Matrix<int> z(6,2,2);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
						//addl vertcat tests
						
    void test_vertcat_2() {
        Matrix<int> x(2, 1, 1);
        Matrix<int> y(3, 1, 1);
        Matrix<int> z(5, 1, 1);
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }		
    
    void test_vertcat_empty() {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }		
						//end addl vertcat tests
    // ---------
    // test_diag
    // ---------

    void test_diag () {
        Matrix<int> x(3,3,2);
        Matrix<int> y(3,1,2);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}
        				// addl diag
        				
    void test_diag_empty() {
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
    }
            				
    void test_diag_2 () {
        Matrix<int> x(1, 2);
        Matrix<int> y(1, 1);
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));
 	}       	
        		// end addl diag tests

    // --------
    // test_dot
    // --------

    void test_dot () {
        Matrix<int> x(1,3,2);
        Matrix<int> y(1,3,3);
        Matrix<int> z(1,1,18);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
     
    void test_dot_2 () {
        Matrix<int> x(3, 1, 2);
        Matrix<int> y(3, 1, 2);
        Matrix<int> z(1, 1, 12);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
        
    void test_dot_3() {
        Matrix<int> x(1, 2, 2);
        Matrix<int> y(1, 2, 1);
        Matrix<int> z(1, 1, 4);
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));
    }

    // --------
    // test_eye
    // --------

    void test_eye () {
        Matrix<int> x;
        Matrix<int> y(2,3,0);
        y[0][0] = 1;
        y[1][1] = 1;
        x = eye< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_eye_2 () {
        Matrix<int> x;
        Matrix<int> y(3, 2);
        y[0][0] = 1;
        y[1][1] = 1;
        x = eye< Matrix<int> >(3, 2);
        CPPUNIT_ASSERT(x.eq(y));}
  
    void test_eye_3() {
        Matrix<int> x;
        Matrix<int> y(1, 1, 1);
        x = eye<Matrix<int> >(1, 1);
        CPPUNIT_ASSERT(x.eq(y));
    }      
  
        
    // ---------
    // test_ones
    // ---------

    void test_ones () {
        Matrix<int> x;
        Matrix<int> y(2,3,1);
        x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}


    void test_ones_2 () {
        Matrix<int> x;
        Matrix<int> y;
        x = ones< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}
 
     void test_ones_3() {
        Matrix<int> x;
        Matrix<int> y(1, 1, 1);
        x = ones<Matrix<int> >(1, 1);
        CPPUNIT_ASSERT(x.eq(y));
    }
    
    // ---------
    // test_rand
    // ---------

    void test_rand () {
        Matrix<double> x;
        x = rand< Matrix<double> >(2, 3);

        for (unsigned int i = 0; i < x.size(); i++)
        {
            for (unsigned int j = 0; j < x[0].size(); j++)
            {
                CPPUNIT_ASSERT(x[i][j] <= 1 && x[i][j] >= 0);
            }
        }
    }
    
    void test_rand_2() {
        Matrix<double> x;
        x = rand<Matrix<double> >(10, 10);
        CPPUNIT_ASSERT(x.size() == 10);
        CPPUNIT_ASSERT(x[0].size() == 10);
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                CPPUNIT_ASSERT(x[i][j] >= 0 && x[i][j] <= 1);
    }
    
    void test_rand_3 () {
        Matrix<int> x;
        Matrix<int> y;
        x = rand< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));
    }
    
    
    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x(2,2,2);
        Matrix<int> y(2,2,2);
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}


	void test_transpose_2 () {
		Matrix<int> x(5, 1);
		Matrix<int> y(1, 5);
		x = transpose(x);
		CPPUNIT_ASSERT(x.eq(y));
		}

	void test_transpose_3 () {
		Matrix<int> x;
		Matrix<int> y;
		x = transpose(x);
		CPPUNIT_ASSERT(x.eq(y));
	}
	
    // ---------
    // test_tril
    // ---------

    void test_tril () {
        Matrix<int> x(3,3,2);
        Matrix<int> y(3,3,2);
        y[0][1] = 0;
        y[0][2] = 0;
        y[1][2] = 0;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }
        
    void test_tril_2 () {
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }
    
    void test_tril_3() {
        Matrix<int> x(1, 2, 1);
        Matrix<int> y(1, 2, 0);
        y[0][0] = 1;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));
    }
    
    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x(3,3,2);
        Matrix<int> y(3,3,2);
        y[1][0] = 0;
        y[2][0] = 0;
        y[2][1] = 0;

        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

	void test_triu_2 () {
		Matrix<int> x(2, 2, 1);
		Matrix<int> y(2, 2, 1);
		y[1][0] = 0;
		x = triu(x);

		CPPUNIT_ASSERT(x.eq(y));
	}
	
    void test_triu_3 () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));
    }
        
        
	// ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x;
        Matrix<int> y(2,3,0);
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_zeros_2 () {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros< Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));}
        
 
    void test_zeros_3() {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros<Matrix<int> >(0, 0);
        CPPUNIT_ASSERT(x.eq(y));
    }       
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(test_horzcat_empty);
    CPPUNIT_TEST(test_horzcat_2);
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(test_vertcat_empty);
    CPPUNIT_TEST(test_vertcat_2);
    CPPUNIT_TEST(test_diag);
    CPPUNIT_TEST(test_diag_empty);
    CPPUNIT_TEST(test_diag_2);
    CPPUNIT_TEST(test_eye);
    CPPUNIT_TEST(test_eye_2);
    CPPUNIT_TEST(test_eye_3);
    CPPUNIT_TEST(test_ones);
    CPPUNIT_TEST(test_ones_2);
    CPPUNIT_TEST(test_ones_3);
    CPPUNIT_TEST(test_rand);
    CPPUNIT_TEST(test_rand_2);
    CPPUNIT_TEST(test_rand_3);
    CPPUNIT_TEST(test_transpose);
    CPPUNIT_TEST(test_transpose_2);
    CPPUNIT_TEST(test_transpose_3);
    CPPUNIT_TEST(test_tril);
    CPPUNIT_TEST(test_tril_2);
    CPPUNIT_TEST(test_tril_3);
    CPPUNIT_TEST(test_triu);
    CPPUNIT_TEST(test_triu_2);
    CPPUNIT_TEST(test_triu_3);
    CPPUNIT_TEST(test_zeros);
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
