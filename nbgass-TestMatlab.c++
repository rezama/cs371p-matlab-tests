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

#define private public
#define protected public
#define class struct

#include "Matrix.h"
#include "Matlab.h"

using namespace std;

// ----------
// TestMatlab
// ----------

struct TestMatlab : CppUnit::TestFixture {
    // --------
    // test_cat
    // --------

    void test_horzcat () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = horzcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_horzcat_one () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;

        vector< vector<int> > xMatrix(2, vector <int>(3, 0));
        vector< vector<int> > yMatrix(2, vector <int>(2, 0));
        vector< vector<int> > zMatrix(2, vector <int>(5, 0));        
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 1;
        xMatrix[0][2] = 1;
        xMatrix[1][0] = 5;
        xMatrix[1][1] = 1;
        xMatrix[1][2] = 1;

        yMatrix[0][0] = 1;
        yMatrix[0][1] = 2;
        yMatrix[1][0] = 1;
        yMatrix[1][1] = 1;

        zMatrix[0][0] = 1;
        zMatrix[0][1] = 1;
        zMatrix[0][2] = 1;
        zMatrix[0][3] = 1;
        zMatrix[0][4] = 2;
        zMatrix[1][0] = 5;
        zMatrix[1][1] = 1;
        zMatrix[1][2] = 1;
        zMatrix[1][3] = 1;
        zMatrix[1][4] = 1;
        
        x._m = xMatrix;
        y._m = yMatrix;
        z._m = zMatrix;

        Matrix<int> result = horzcat(x, y);
        CPPUNIT_ASSERT(result.eq(z));}

    void test_horzcat_two () {
        Matrix<int> x;
        Matrix<int> y;

        vector< vector<int> > xMatrix(3, vector <int>(2, 0));
        vector< vector<int> > yMatrix(2, vector <int>(2, 0));       

        xMatrix[0][0] = 1;
        xMatrix[0][1] = 1;
        xMatrix[1][0] = 1;
        xMatrix[1][1] = 5;
        xMatrix[2][0] = 1;
        xMatrix[2][1] = 1;

        yMatrix[0][0] = 1;
        yMatrix[0][1] = 2;
        yMatrix[1][0] = 1;
        yMatrix[1][1] = 1;

        x._m = xMatrix;
        y._m = yMatrix;

		try {
			Matrix<int> result = horzcat(x, y);
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
    }        

    void test_horzcat_three () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;

        vector< vector<int> > xMatrix(2, vector <int>(3, 0));
        vector< vector<int> > yMatrix(0, vector <int>(0, 0));
        vector< vector<int> > zMatrix(2, vector <int>(3, 0));        
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 1;
        xMatrix[0][2] = 1;
        xMatrix[1][0] = 5;
        xMatrix[1][1] = 1;
        xMatrix[1][2] = 1;

        zMatrix[0][0] = 1;
        zMatrix[0][1] = 1;
        zMatrix[0][2] = 1;
        zMatrix[1][0] = 5;
        zMatrix[1][1] = 1;
        zMatrix[1][2] = 1;
        
        x._m = xMatrix;
        y._m = yMatrix;
        z._m = zMatrix;

        Matrix<int> result = horzcat(x, y);
        CPPUNIT_ASSERT(result.eq(z));}
        
    void test_vertcat () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = vertcat(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
        
    void test_vertcat_one () {
       Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;

        vector< vector<int> > xMatrix(3, vector <int>(2, 0));
        vector< vector<int> > yMatrix(2, vector <int>(2, 0));
        vector< vector<int> > zMatrix(5, vector <int>(2, 0));        
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 1;
        xMatrix[1][0] = 1;
        xMatrix[1][1] = 5;
        xMatrix[2][0] = 1;
        xMatrix[2][1] = 1;

        yMatrix[0][0] = 1;
        yMatrix[0][1] = 2;
        yMatrix[1][0] = 1;
        yMatrix[1][1] = 1;

        zMatrix[0][0] = 1;
        zMatrix[0][1] = 1;
        zMatrix[1][0] = 1;
        zMatrix[1][1] = 5;
        zMatrix[2][0] = 1;
        zMatrix[2][1] = 1;
        zMatrix[3][0] = 1;
        zMatrix[3][1] = 2;
        zMatrix[4][0] = 1;
        zMatrix[4][1] = 1;
        
        x._m = xMatrix;
        y._m = yMatrix;
        z._m = zMatrix;

        Matrix<int> result = vertcat(x, y);
        CPPUNIT_ASSERT(result.eq(z));}
        
    void test_vertcat_two () {
        Matrix<int> x;
        Matrix<int> y;

        vector< vector<int> > xMatrix(2, vector <int>(3, 0));
        vector< vector<int> > yMatrix(2, vector <int>(2, 0));       

        xMatrix[0][0] = 1;
        xMatrix[0][1] = 1;
        xMatrix[0][2] = 1;
        xMatrix[1][0] = 5;
        xMatrix[1][1] = 1;
        xMatrix[1][2] = 1;

        yMatrix[0][0] = 1;
        yMatrix[0][1] = 2;
        yMatrix[1][0] = 1;
        yMatrix[1][1] = 1;

        x._m = xMatrix;
        y._m = yMatrix;
        
		try {
			Matrix<int> result = vertcat(x, y);
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
    } 
        
    void test_vertcat_three () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;

        vector< vector<int> > xMatrix(2, vector <int>(3, 0));
        vector< vector<int> > yMatrix(0, vector <int>(0, 0));
        vector< vector<int> > zMatrix(2, vector <int>(3, 0));        
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 1;
        xMatrix[0][2] = 1;
        xMatrix[1][0] = 5;
        xMatrix[1][1] = 1;
        xMatrix[1][2] = 1;

        zMatrix[0][0] = 1;
        zMatrix[0][1] = 1;
        zMatrix[0][2] = 1;
        zMatrix[1][0] = 5;
        zMatrix[1][1] = 1;
        zMatrix[1][2] = 1;
        
        x._m = xMatrix;
        y._m = yMatrix;
        z._m = zMatrix;

        Matrix<int> result = vertcat(x, y);
        CPPUNIT_ASSERT(result.eq(z));}
        
    // ---------
    // test_diag
    // ---------

    void test_diag () {
        Matrix<int> x;
        Matrix<int> y;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_diag_one () {
        Matrix<int> x;
        Matrix<int> z;

        vector< vector<int> > xMatrix(3, vector <int>(3, 0));
        vector< vector<int> > zMatrix(3, vector <int>(1, 0));        
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 15;
        xMatrix[0][2] = 16;
        xMatrix[1][0] = 2;
        xMatrix[1][1] = 17;
        xMatrix[1][2] = 18;
        xMatrix[2][0] = 3;
        xMatrix[2][1] = 19;
        xMatrix[2][2] = 20;

        zMatrix[0][0] = 1;
        zMatrix[1][0] = 17;
        zMatrix[2][0] = 20;
        
        x._m = xMatrix;
        z._m = zMatrix;
        Matrix<int> result = diag(x);
        
        CPPUNIT_ASSERT(result.eq(z));}
    
    void test_diag_two () {
        Matrix<int> x;
        Matrix<int> z;

        vector< vector<int> > xMatrix(2, vector <int>(3, 0));
        vector< vector<int> > zMatrix(2, vector <int>(1, 0));        
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 15;
        xMatrix[0][2] = 16;
        xMatrix[1][0] = 2;
        xMatrix[1][1] = 17;
        xMatrix[1][2] = 18;

        zMatrix[0][0] = 1;
        zMatrix[1][0] = 17;
        
        x._m = xMatrix;
        z._m = zMatrix;

		try {
			Matrix<int> result = diag(x);
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
    }

    void test_diag_three () {
        Matrix<int> x;
        Matrix<int> z;

        vector< vector<int> > xMatrix(0, vector <int>(0, 0));
        vector< vector<int> > zMatrix(0, vector <int>(0, 0));
        
        x._m = xMatrix;
        z._m = zMatrix;

        Matrix<int> result = diag(x);
        CPPUNIT_ASSERT(result.eq(x));}

    // --------
    // test_dot
    // --------

    void test_dot () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = dot(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    void test_dot_one () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;

        vector< vector<int> > xMatrix(3, vector <int>(1, 0));
        vector< vector<int> > yMatrix(3, vector <int>(1, 0));
        vector< vector<int> > zMatrix(1, vector <int>(1, 0));        
        
        xMatrix[0][0] = 1;
        xMatrix[1][0] = 2;
        xMatrix[2][0] = 5;
        
        yMatrix[0][0] = 19;
        yMatrix[1][0] = 5;
        yMatrix[2][0] = 6;

        zMatrix[0][0] = 59;
        
        x._m = xMatrix;
        y._m = yMatrix;
        z._m = zMatrix;
        
        Matrix<int> result = dot(x, y);        
        CPPUNIT_ASSERT(result.eq(z));}
        
    void test_dot_two () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;

        vector< vector<int> > xMatrix(1, vector <int>(3, 0));
        vector< vector<int> > yMatrix(1, vector <int>(3, 0));
        vector< vector<int> > zMatrix(1, vector <int>(1, 0));        
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 2;
        xMatrix[0][2] = 5;
        
        yMatrix[0][0] = 19;
        yMatrix[0][1] = 5;
        yMatrix[0][2] = 6;

        zMatrix[0][0] = 59;
        
        x._m = xMatrix;
        y._m = yMatrix;
        z._m = zMatrix;
        
        Matrix<int> result = dot(x, y);        
        CPPUNIT_ASSERT(result.eq(z));}
        
    void test_dot_three () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;

        vector< vector<int> > xMatrix(1, vector <int>(3, 0));
        vector< vector<int> > yMatrix(3, vector <int>(1, 0));
        vector< vector<int> > zMatrix(1, vector <int>(1, 0));        
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 2;
        xMatrix[0][2] = 5;
        
        yMatrix[0][0] = 19;
        yMatrix[1][0] = 5;
        yMatrix[2][0] = 6;

        zMatrix[0][0] = 59;
        
        x._m = xMatrix;
        y._m = yMatrix;
        z._m = zMatrix;
        
        Matrix<int> result = dot(x, y);
        CPPUNIT_ASSERT(result.eq(z));}  

    void test_dot_four () {
        Matrix<int> x;
        Matrix<int> y;

        vector< vector<int> > xMatrix(1, vector <int>(4, 0));
        vector< vector<int> > yMatrix(1, vector <int>(3, 0));     
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 2;
        xMatrix[0][2] = 5;
        xMatrix[0][3] = 17;
        
        yMatrix[0][0] = 19;
        yMatrix[0][1] = 5;
        yMatrix[0][2] = 6;
        
        x._m = xMatrix;
        y._m = yMatrix;
        
		try {
			Matrix<int> result = dot(x, y);
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
        
    }
        
    void test_dot_five () {
        Matrix<int> x;
        Matrix<int> y;

        vector< vector<int> > xMatrix(2, vector <int>(2, 0));
        vector< vector<int> > yMatrix(2, vector <int>(2, 0));     
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 2;
        xMatrix[1][0] = 5;
        xMatrix[1][1] = 17;
        
        yMatrix[0][0] = 19;
        yMatrix[0][1] = 5;
        yMatrix[1][0] = 6;
        yMatrix[1][1] = 16;
        
        x._m = xMatrix;
        y._m = yMatrix;
        
		try {
			Matrix<int> result = dot(x, y);
			CPPUNIT_ASSERT(false);
		}
		
		catch (std::invalid_argument e){
			//nothing to do here
		}
        
    }
              
    // --------
    // test_eye
    // --------

    void test_eye () {
        Matrix<int> x;
        Matrix<int> y;
        x = eye< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(!x.eq(y));}
        
    void test_eye_one () {
        Matrix<int> z;
        
        vector< vector<int> > zMatrix(3, vector <int>(3, 0));

        zMatrix[0][0] = 1;
        zMatrix[0][1] = 0;
        zMatrix[0][2] = 0;
        zMatrix[1][0] = 0;
        zMatrix[1][1] = 1;
        zMatrix[1][2] = 0;
        zMatrix[2][0] = 0;
        zMatrix[2][1] = 0;
        zMatrix[2][2] = 1;
        
        z._m = zMatrix;
        
        Matrix<int> result = eye< Matrix<int> >(3, 3);
        CPPUNIT_ASSERT(result.eq(z));}
    
    void test_eye_two () {
        Matrix<int> z;
        
        vector< vector<int> > zMatrix(0, vector <int>(0, 0));
        
        z._m = zMatrix;
        
        Matrix<int> result = eye< Matrix<int> >(0, 0);        
        CPPUNIT_ASSERT(result.eq(z));}
    
    void test_eye_three () {
        Matrix<int> z;
        
        vector< vector<int> > zMatrix(2, vector <int>(3, 0));

        zMatrix[0][0] = 1;
        zMatrix[0][1] = 0;
        zMatrix[0][2] = 0;
        zMatrix[1][0] = 0;
        zMatrix[1][1] = 1;
        zMatrix[1][2] = 0;
        
        z._m = zMatrix;
        
        Matrix<int> result = eye< Matrix<int> >(2, 3);        
        CPPUNIT_ASSERT(result.eq(z));}
        

    // -------------
    // test_linsolve
    // -------------

    void test_linsolve () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = linsolve(x, y);
        CPPUNIT_ASSERT(x.eq(z));}
        
    void test_linsolve_one () {      
        CPPUNIT_ASSERT(true && "extra credit");}
        
    void test_linsolve_two () {
        CPPUNIT_ASSERT(true && "extra credit");}
        
    void test_linsolve_three () {
        CPPUNIT_ASSERT(true && "extra credit");}

    // ---------
    // test_ones
    // ---------

    void test_ones () {
        Matrix<int> x;
        Matrix<int> y;
        x = ones< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(!x.eq(y));}
        
    void test_ones_one () {
        Matrix<int> z;

        vector< vector<int> > zMatrix(3, vector <int>(1, 0));        

        zMatrix[0][0] = 1;
        zMatrix[1][0] = 1;
        zMatrix[2][0] = 1;
        z._m = zMatrix;
        
        Matrix<int> result = ones< Matrix<int> >(3, 1);        
        CPPUNIT_ASSERT(result.eq(z));}
        
    void test_ones_two () {
        Matrix<int> z;

        vector< vector<int> > zMatrix(3, vector <int>(3, 0));        

        zMatrix[0][0] = 1;
        zMatrix[0][1] = 1;
        zMatrix[0][2] = 1;
        zMatrix[1][0] = 1;
        zMatrix[1][1] = 1;
        zMatrix[1][2] = 1;
        zMatrix[2][0] = 1;
        zMatrix[2][1] = 1;
        zMatrix[2][2] = 1;
        
        z._m = zMatrix;
        
        Matrix<int> result = ones< Matrix<int> >(3, 3);        
        CPPUNIT_ASSERT(result.eq(z));}
        
    void test_ones_three () {
        Matrix<int> z;

        vector< vector<int> > zMatrix(0, vector <int>(0, 0));
        
        z._m = zMatrix;
        
        Matrix<int> result = ones< Matrix<int> >(0, 0);        
        CPPUNIT_ASSERT(result.eq(z));}

    // ---------
    // test_rand
    // ---------

    void test_rand () {
        Matrix<int> x;
        Matrix<int> y;
        x = rand< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(!x.eq(y));}
        
    void test_rand_one () {
        Matrix<double> x = rand< Matrix<double> >(2, 3);
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 3; j++){
                CPPUNIT_ASSERT (x[i][j] > 0 && x[i][j] < 1);
            }
        }
    }

    void test_rand_two () {
        Matrix<double> x = rand< Matrix<double> >(0, 0);
        CPPUNIT_ASSERT (x.size() == 0);}


    void test_rand_three () {
        Matrix<double> x = rand< Matrix<double> >(3, 2);
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 2; j++){
                CPPUNIT_ASSERT (x[i][j] > 0 && x[i][j] < 1);
            }
        }
    }
    
    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x;
        Matrix<int> y;
        x = transpose(x);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_transpose_one () {
        Matrix<int> x;
        Matrix<int> y;

        vector< vector<int> > xMatrix(2, vector <int>(2, 0));
        vector< vector<int> > yMatrix(2, vector <int>(2, 0));     
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 2;
        xMatrix[1][0] = 5;
        xMatrix[1][1] = 17;
        
        yMatrix[0][0] = 1;
        yMatrix[0][1] = 5;
        yMatrix[1][0] = 2;
        yMatrix[1][1] = 17;
        
        x._m = xMatrix;
        y._m = yMatrix;
        
        Matrix<int> result = transpose(x);        
        CPPUNIT_ASSERT(result.eq(y));}
    
    void test_transpose_two () {
        Matrix<int> x;

        vector< vector<int> > xMatrix(0, vector <int>(0, 0));
        
        x._m = xMatrix;
        
        Matrix<int> result = transpose(x);        
        CPPUNIT_ASSERT(result.eq(x));}
    
    void test_transpose_three () {
        Matrix<int> x;
        Matrix<int> y;

        vector< vector<int> > xMatrix(1, vector <int>(4, 0));
        vector< vector<int> > yMatrix(4, vector <int>(1, 0));     
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 2;
        xMatrix[0][2] = 5;
        xMatrix[0][3] = 17;
        
        yMatrix[0][0] = 1;
        yMatrix[1][0] = 2;
        yMatrix[2][0] = 5;
        yMatrix[3][0] = 17;
        
        x._m = xMatrix;
        y._m = yMatrix;

        Matrix<int> result = transpose(x); 
        CPPUNIT_ASSERT(result.eq(y));}
        
    // ---------
    // test_tril
    // ---------

    void test_tril () {
        Matrix<int> x;
        Matrix<int> y;
        x = tril(x);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_tril_one () {
        Matrix<int> x;
        Matrix<int> y;

        vector< vector<int> > xMatrix(3, vector <int>(3, 0));
        vector< vector<int> > yMatrix(3, vector <int>(3, 0));     
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 2;
        xMatrix[0][2] = 3;
        xMatrix[1][0] = 4;
        xMatrix[1][1] = 5;
        xMatrix[1][2] = 6;
        xMatrix[2][0] = 7;
        xMatrix[2][1] = 8;
        xMatrix[2][2] = 9;        
        
        yMatrix[0][0] = 1;
        yMatrix[0][1] = 0;
        yMatrix[0][2] = 0;
        yMatrix[1][0] = 4;
        yMatrix[1][1] = 5;
        yMatrix[1][2] = 0;
        yMatrix[2][0] = 7;
        yMatrix[2][1] = 8;
        yMatrix[2][2] = 9;
        
        x._m = xMatrix;
        y._m = yMatrix;
        
        Matrix<int> result = tril(x);        
        CPPUNIT_ASSERT(result.eq(y));}
        
    void test_tril_two () {
        Matrix<int> x;
        Matrix<int> y;

        vector< vector<int> > xMatrix(0, vector <int>(0, 0));
        
        x._m = xMatrix;
        
        Matrix<int> result = tril(x);        
        CPPUNIT_ASSERT(result.eq(x));}
        
    void test_tril_three () {
        Matrix<int> x;
        Matrix<int> y;

        vector< vector<int> > xMatrix(2, vector <int>(4, 0));
        vector< vector<int> > yMatrix(2, vector <int>(4, 0));     
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 2;
        xMatrix[0][2] = 3;
        xMatrix[0][3] = 4;
        xMatrix[1][0] = 5;
        xMatrix[1][1] = 6;
        xMatrix[1][2] = 7;
        xMatrix[1][3] = 8;      
        
        yMatrix[0][0] = 1;
        yMatrix[0][1] = 0;
        yMatrix[0][2] = 0;
        yMatrix[0][3] = 0;
        yMatrix[1][0] = 5;
        yMatrix[1][1] = 6;
        yMatrix[1][2] = 0;
        yMatrix[1][3] = 0;      
        
        x._m = xMatrix;
        y._m = yMatrix;
        
        Matrix<int> result = tril(x);
        CPPUNIT_ASSERT(result.eq(y));}
        
    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x;
        Matrix<int> y;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}
        
    void test_triu_one () {
        Matrix<int> x;
        Matrix<int> y;

        vector< vector<int> > xMatrix(3, vector <int>(3, 0));
        vector< vector<int> > yMatrix(3, vector <int>(3, 0));     
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 2;
        xMatrix[0][2] = 3;
        xMatrix[1][0] = 4;
        xMatrix[1][1] = 5;
        xMatrix[1][2] = 6;
        xMatrix[2][0] = 7;
        xMatrix[2][1] = 8;
        xMatrix[2][2] = 9;        
        
        yMatrix[0][0] = 1;
        yMatrix[0][1] = 2;
        yMatrix[0][2] = 3;
        yMatrix[1][0] = 0;
        yMatrix[1][1] = 5;
        yMatrix[1][2] = 6;
        yMatrix[2][0] = 0;
        yMatrix[2][1] = 0;
        yMatrix[2][2] = 9;
        
        x._m = xMatrix;
        y._m = yMatrix;
        
        Matrix<int> result = triu(x);        
        CPPUNIT_ASSERT(result.eq(y));}
        
    void test_triu_two () {
        Matrix<int> x;
        Matrix<int> y;

        vector< vector<int> > xMatrix(0, vector <int>(0, 0));
        
        x._m = xMatrix;
        
        Matrix<int> result = triu(x);        
        CPPUNIT_ASSERT(result.eq(x));}
        
    void test_triu_three () {
        Matrix<int> x;
        Matrix<int> y;

        vector< vector<int> > xMatrix(2, vector <int>(4, 0));
        vector< vector<int> > yMatrix(2, vector <int>(4, 0));     
        
        xMatrix[0][0] = 1;
        xMatrix[0][1] = 2;
        xMatrix[0][2] = 3;
        xMatrix[0][3] = 4;
        xMatrix[1][0] = 5;
        xMatrix[1][1] = 6;
        xMatrix[1][2] = 7;
        xMatrix[1][3] = 8;      
        
        yMatrix[0][0] = 1;
        yMatrix[0][1] = 2;
        yMatrix[0][2] = 3;
        yMatrix[0][3] = 4;
        yMatrix[1][0] = 0;
        yMatrix[1][1] = 6;
        yMatrix[1][2] = 7;
        yMatrix[1][3] = 8;   
        
        x._m = xMatrix;
        y._m = yMatrix;
        
        Matrix<int> result = triu(x);
        CPPUNIT_ASSERT(result.eq(y));}

    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x;
        Matrix<int> y;
        x = zeros< Matrix<int> >(2, 3);
        CPPUNIT_ASSERT(!x.eq(y));}
        
    void test_zeros_one () {
        Matrix<int> y;
        
        vector< vector<int> > yMatrix(2, vector <int>(2, 0));     
        
        yMatrix[0][0] = 0;
        yMatrix[0][1] = 0;
        yMatrix[1][0] = 0;
        yMatrix[1][1] = 0;
        
        y._m = yMatrix;
        
        Matrix<int> result = zeros< Matrix<int> >(2, 2);       
        CPPUNIT_ASSERT(result.eq(y));}
        
    void test_zeros_two () {
        Matrix<int> y;
        
        vector< vector<int> > yMatrix(0, vector <int>(0, 0));
        
        y._m = yMatrix;
        
        Matrix<int> result = zeros< Matrix<int> >(0, 0);       
        CPPUNIT_ASSERT(result.eq(y));}
        
    void test_zeros_three () {
        Matrix<int> y;
        
        vector< vector<int> > yMatrix(2, vector <int>(3, 0));     
        
        yMatrix[0][0] = 0;
        yMatrix[0][1] = 0;
        yMatrix[0][2] = 0;
        yMatrix[1][0] = 0;
        yMatrix[1][1] = 0;
        yMatrix[1][2] = 0;
        
        y._m = yMatrix;
        
        Matrix<int> result = zeros< Matrix<int> >(2, 3);       
        CPPUNIT_ASSERT(result.eq(y));}

    // -----
    // suite
    // -----
    
    CPPUNIT_TEST_SUITE(TestMatlab);
    
    // my added tests
    CPPUNIT_TEST(test_horzcat_one);
    CPPUNIT_TEST(test_horzcat_two);
    CPPUNIT_TEST(test_horzcat_three);
    
    CPPUNIT_TEST(test_vertcat_one);
    CPPUNIT_TEST(test_vertcat_two);
    CPPUNIT_TEST(test_vertcat_three);
    
    CPPUNIT_TEST(test_diag_one);
    CPPUNIT_TEST(test_diag_two);
    CPPUNIT_TEST(test_diag_three);
    
    CPPUNIT_TEST(test_dot_one);
    CPPUNIT_TEST(test_dot_two);
    CPPUNIT_TEST(test_dot_three);
    CPPUNIT_TEST(test_dot_four);
    CPPUNIT_TEST(test_dot_five); 

    CPPUNIT_TEST(test_eye_one);
    CPPUNIT_TEST(test_eye_two);
    CPPUNIT_TEST(test_eye_three);

    CPPUNIT_TEST(test_linsolve_one);
    CPPUNIT_TEST(test_linsolve_two);
    CPPUNIT_TEST(test_linsolve_three); 

    CPPUNIT_TEST(test_ones_one);
    CPPUNIT_TEST(test_ones_two);
    CPPUNIT_TEST(test_ones_three);     

    CPPUNIT_TEST(test_rand_one);
    CPPUNIT_TEST(test_rand_two);
    CPPUNIT_TEST(test_rand_three);

    CPPUNIT_TEST(test_transpose_one);
    CPPUNIT_TEST(test_transpose_two);
    CPPUNIT_TEST(test_transpose_three);    

    CPPUNIT_TEST(test_tril_one);
    CPPUNIT_TEST(test_tril_two);
    CPPUNIT_TEST(test_tril_three);        
    
    CPPUNIT_TEST(test_triu_one);
    CPPUNIT_TEST(test_triu_two);
    CPPUNIT_TEST(test_triu_three);
    
    CPPUNIT_TEST(test_zeros_one);
    CPPUNIT_TEST(test_zeros_two);
    CPPUNIT_TEST(test_zeros_three);
    
    // skeleton tests
    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(test_diag);
    CPPUNIT_TEST(test_eye);
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
