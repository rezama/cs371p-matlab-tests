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
#include <stdexcept>

// ----------
// TestMatlab
// ----------

struct TestMatlab : CppUnit::TestFixture {
    // --------
    // test_cat
    // --------

    void test_horzcat () {
        Matrix<int> x(1, 1, 2);
        Matrix<int> y(1, 1, 4);
        Matrix<int> z(1, 2, 4);
        z[0][0] = 2;
        //std::cout << "It's gonna blow! \n";
        x = horzcat(x, y);

        CPPUNIT_ASSERT(x.eq(z));}

    void test_horzcat2 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> y(1, 3, 4);
        bool caught = false;
        try {
        x = horzcat(x, y);
        }//should fail
        catch (std::length_error& e) {
        	caught = true;
        }

        CPPUNIT_ASSERT(caught);}

    void test_horzcat3 () {
        Matrix<double> x(2, 10, 1);
        Matrix<double> y(2, 1, 0);
        Matrix<double> z(2, 11, 1);
        z[0][10] = 0;
        z[1][10] = 0;

        x = horzcat(x, y);

        CPPUNIT_ASSERT(x.eq(z));}

    void test_horzcat4 () {
        Matrix<double> x(2, 10, 1);
        Matrix<double> z;
        Matrix<double> expected(2, 10, 1);

        x = horzcat(x, z);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_horzcat5 () {
        Matrix<double> x;
        Matrix<double> z(2, 10, 1);
        Matrix<double> expected(2, 10, 1);


        x = horzcat(x, z);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_vertcat () {
        Matrix<int> x(1, 1, 2);
        Matrix<int> y(1, 1, 4);
        Matrix<int> z(2, 1, 4);
        z[0][0] = 2;
        //std::cout << "It's gonna blow! \n";
        x = vertcat(x, y);
 //       x.print();
 //       z.print();
        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat2 () {
        Matrix<int> x(2, 3, 4);
        Matrix<int> y(2, 2, 4);
        bool caught = false;
        try {
        x = vertcat(x, y);
        }//should fail; diff column #
        catch (std::length_error& e) {
        	caught = true;
        }

        CPPUNIT_ASSERT(caught);}

    void test_vertcat3 () {
        Matrix<double> x(2, 10, 1);
        Matrix<double> y(1, 10, 0);
        Matrix<double> z(3, 10, 1);
        for(int i = 0; i < 10; i++)
        	z[2][i] = 0;

        x = vertcat(x, y);


        CPPUNIT_ASSERT(x.eq(z));}

    void test_vertcat4 () {
         Matrix<double> x(2, 10, 11);
         Matrix<double> expected(2, 10, 11);
         Matrix<double> z;


         x = vertcat(x, z);


         CPPUNIT_ASSERT(x.eq(expected));}

    void test_vertcat5 () {
        Matrix<double> x;
        Matrix<double> expected(2, 10, 11);
        Matrix<double> z(2, 10, 11);


        x = vertcat(x, z);


        CPPUNIT_ASSERT(x.eq(expected));}

    // ---------
    // test_diag
    // ---------

    void test_diag () {
    	Matrix<int> x(3, 0, 1);
    	bool caught = false;
    	try{
    		x = diag(x);
    	}
    	catch(std::length_error& e)
    	{
    		caught = true;
    	}
    	CPPUNIT_ASSERT(caught);}

    void test_diag2 () {
        Matrix<short> x(2, 2, 0);
        Matrix<short> expected(2, 1, 50);
        x[0][0] = 50;
        x[1][1] = 50;
        x = diag(x);

        CPPUNIT_ASSERT(x.eq(expected));}

    void test_diag3 () {
        Matrix<double> x(6, 2, 1);
        x[0][0] = 1;
        x[0][1] = 10;
        x[1][0] = 2;
        x[1][1] = 20;
        x[2][0] = 3;
        x[2][1] = 30;
        x[3][0] = 4;
        x[3][1] = 40;
        x[4][0] = 5;
        x[4][1] = 50;
        x[5][0] = 6;
        x[5][1] = 60;


        Matrix<double> y(2, 1, 1);
        y[1][0] = 20;
        x = diag(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_diag4 () {
    	Matrix<int> x(0, 3, 1);
    	bool caught = false;
    	try{
    		x = diag(x);
    	}
    	catch(std::length_error& e)
    	{
    		caught = true;
    	}
    	CPPUNIT_ASSERT(caught);}

    // --------
    // test_dot // only allows 1 x N matrices (vectors)
    // --------

    void test_dot () {
        Matrix<int> x(1, 3, 1);
        Matrix<int> y(1, 3, 4);

        x[0][1] = 2;
        x[0][2] = 3;
        y[0][1] = 5;
        y[0][2] = 6;

        double z = (dot(x, y))[0][0];
        CPPUNIT_ASSERT(z == 32);}

    void test_dot2 () {
        Matrix<int> x(3, 3, -1);
        Matrix<int> y(3, 3, -1);
        bool caught = false;


        x[0][0] = 1;
        x[0][1] = 2;
        x[0][2] = 0;
        x[0][0] = 2;
        x[0][1] = 5;
        x[0][2] = -1;
        x[0][0] = 4;
        x[0][1] = 10;
        x[0][2] = -1;

        y[0][0] = 1;
        y[0][1] = 2;
        y[0][2] = 4;
        y[0][0] = 2;
        y[0][1] = 5;
        y[0][2] = 10;
        y[0][0] = 0;
        y[0][1] = -1;
        y[0][2] = -1;


        try{
        	x = (dot(x, y));
        }
        catch(std::length_error& e) {
        	caught = true;
        }
        CPPUNIT_ASSERT(caught);}

    void test_dot3 () {
        Matrix<int> x(1, 1, 2);
        Matrix<int> y(1, 1, 10);

        double z = (dot(x, y))[0][0];
        CPPUNIT_ASSERT(z == 20);}

    void test_dot4 () {
        Matrix<int> x(1, 3, -1);
        Matrix<int> y(1, 0, -1);
        bool caught = false;

        try{
        	x = (dot(x, y));
        }
        catch(std::length_error& e) {
        	caught = true;
        }
        CPPUNIT_ASSERT(caught);}

    void test_dot5 () {
        Matrix<int> x(1, 2, -1);
        Matrix<int> y(1, 3, -1);
        bool caught = false;

        try{
        	x = (dot(x, y));
        }
        catch(std::length_error& e) {
        	caught = true;
        }
        CPPUNIT_ASSERT(caught);}

    void test_dot6 () {
        Matrix<int> x(2, 3, -1);
        Matrix<int> y(2, 3, -1);
        bool caught = false;

        try{
        	x = (dot(x, y));
        }
        catch(std::length_error& e) {
        	caught = true;
        }
        CPPUNIT_ASSERT(caught);}


    // --------
    // test_eye
    // --------

    void test_eye () {
        Matrix<int> x;
        Matrix<int> y(2, 2, 0);
        x = eye< Matrix<int> >(2, 2);
        y[0][0] = 1;
        y[1][1] = 1;
        CPPUNIT_ASSERT(x.eq(y));}

    void test_eye2 () {
        Matrix<int> x;
        Matrix<int> y(1, 10, 0);
        y[0][0] = 1;
        x = eye< Matrix<int> >(1, 10);


        CPPUNIT_ASSERT(x.eq(y));}

    void test_eye3 () {
        Matrix<double> x;
        Matrix<double> y(10, 1, 0);
        y[0][0] = 1;
        x = eye< Matrix<double> >(10, 1);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_eye4 () {
        Matrix<double> x;
        Matrix<double> y(5, 5, 0);
        y[0][0] = 1;
        y[1][1] = 1;
        y[2][2] = 1;
        y[3][3] = 1;
        y[4][4] = 1;
        x = eye< Matrix<double> >(5, 5);
        CPPUNIT_ASSERT(x.eq(y));}

    // -------------
    // test_linsolve
    // -------------

    void test_linsolve () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x = linsolve(x, y);
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------
    // test_ones
    // ---------

    void test_ones () {
        Matrix<int> x;
        x = ones< Matrix<int> >(5, 5);

        CPPUNIT_ASSERT(x[4][4] == 1);}

    void test_ones2 () {
        Matrix<short> x(100, 100, 0);
        x = ones< Matrix<short> >(1, 1);
        Matrix<short> y(1, 1, 1);

        CPPUNIT_ASSERT(x.eq(y));}

    void test_ones3 () {
        Matrix<double> x(3, 3, 4.245);
        bool caught = false;
        try {
        x = ones< Matrix<double> >(0, 1);
        }
        catch(std::length_error& e) {
        	caught = true;
        }

        CPPUNIT_ASSERT(caught);}

    // ---------
    // test_rand
    // ---------

    void test_rand () {
        Matrix<double> x;
        Matrix<double> y;

        x = rand(3, 3);
        //x.print();
        CPPUNIT_ASSERT(!x.eq(y));}

    void test_rand2 () {
        Matrix<double> x(10, 10, 10);
        Matrix<double> y(10, 10, 10);
        x = rand(1, 1);
        //x.print();
        CPPUNIT_ASSERT(!x.eq(y));}

    void test_rand3 () {
        Matrix<double> x;
        bool caught = false;
        try {
        	x = rand(0, 2);
        }
        catch(std::length_error& e) {
        	caught = true;
        }
        //x.print();
        CPPUNIT_ASSERT(caught);}

    // --------------
    // test_transpose
    // --------------

    void test_transpose () {
        Matrix<int> x(1, 3, 1);
        x[0][1] = 2;
        x[0][2] = 3;
        x = transpose(x);

        Matrix<int> expected(3, 1, 1);
        expected[1][0] = 2;
        expected[2][0] = 3;
        CPPUNIT_ASSERT(x.eq(expected));}


    void test_transpose2 () {
    	Matrix<int> x(3, 3, -1);
    	Matrix<int> y(3, 3, -1);
    	x[0][0] = 1;
    	x[0][1] = 2;
    	x[0][2] = 0;
    	x[1][0] = 2;
    	x[1][1] = 5;
    	x[1][2] = -1;
    	x[2][0] = 4;
    	x[2][1] = 10;
    	x[2][2] = -1;
//x.print();
    	x = transpose(x);
//x.print();
    	y[0][0] = 1;
    	y[0][1] = 2;
    	y[0][2] = 4;
    	y[1][0] = 2;
    	y[1][1] = 5;
    	y[1][2] = 10;
    	y[2][0] = 0;
    	y[2][1] = -1;
    	y[2][2] = -1;
//y.print();
    	CPPUNIT_ASSERT(x.eq(y));
    }

    void test_transpose3() {
    	Matrix<int> x;
    	bool caught = false;

    	try {
    	x = transpose(x);
    	}
    	catch(std::length_error& e) {
    	caught = true;
    	}
    	CPPUNIT_ASSERT(caught);
    }

    void test_transpose4() {
    	Matrix<int> x(1, 0, 1);
    	bool caught = false;

    	try {
    	x = transpose(x);
    	}
    	catch(std::length_error& e) {
    	caught = true;
    	}
    	CPPUNIT_ASSERT(caught);
    }

    void test_transpose5() {
    	Matrix<int> x(0, 1, 0);
    	bool caught = false;

    	try {
    	x = transpose(x);
    	}
    	catch(std::length_error& e) {
    	caught = true;
    	}
    	CPPUNIT_ASSERT(caught);
    }


    // ---------
    // test_tril
    // ---------

    void test_tril () {
        Matrix<int> x(1, 3, 1);
        Matrix<int> y(1, 3, 1);
        y[0][1] = 0;
        y[0][2] = 0;
        x = tril(x);
    //    x.print();

        CPPUNIT_ASSERT(x.eq(y));}

    void test_tril2 () {
        Matrix<float> x(3, 3, 1.1);
        Matrix<float> y(3, 3, 1.1);
        y[0][1] = 0;
        y[0][2] = 0;
        y[1][2] = 0;


        x = tril(x);
    //    x.print();

        CPPUNIT_ASSERT(x.eq(y));}

    void test_tril3 () {
        Matrix<double> x(5, 1, 12);
        Matrix<double> y(5, 1, 12);
        x = tril(x);

        CPPUNIT_ASSERT(x.eq(y));}

    // ---------
    // test_triu
    // ---------

    void test_triu () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        y[1][0] = 0;
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_triu2() {
        Matrix<float> x(1, 3, 3.14);
        Matrix<float> y(1, 3, 3.14);
        x = triu(x);
        CPPUNIT_ASSERT(x.eq(y));}

    void test_triu3 () {
        Matrix<short> x(5, 1, 1);
        Matrix<short> y(5, 1, 0);
        y[0][0] = 1;
        x = triu(x);

        CPPUNIT_ASSERT(x.eq(y));}

    // ----------
    // test_zeros
    // ----------

    void test_zeros () {
        Matrix<int> x;
        x = zeros< Matrix<int> >(5, 5);

        CPPUNIT_ASSERT(x[4][4] == 0);}

    void test_zeros2 () {
        Matrix<int> x;
        x = zeros< Matrix<int> >(1, 1);

        CPPUNIT_ASSERT(x[0][0] == 0);}

    void test_zeros3 () {
        Matrix<int> z;
        z = zeros< Matrix<int> >(10, 10);
        bool allzeros = true;
        for(unsigned y = 0; y < z.size(); y++)
        	for(unsigned x = 0; x < z[0].size(); x++)
        		if(z[y][x] != 0)
        			allzeros = false;


        CPPUNIT_ASSERT(allzeros);}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatlab);
    CPPUNIT_TEST(test_horzcat);
    CPPUNIT_TEST(test_horzcat2);
    CPPUNIT_TEST(test_horzcat3);
    CPPUNIT_TEST(test_horzcat4);
    CPPUNIT_TEST(test_horzcat5);
    CPPUNIT_TEST(test_vertcat);
    CPPUNIT_TEST(test_vertcat2);
    CPPUNIT_TEST(test_vertcat3);
    CPPUNIT_TEST(test_vertcat4);
    CPPUNIT_TEST(test_vertcat5);

    CPPUNIT_TEST(test_dot);
    CPPUNIT_TEST(test_dot2);
    CPPUNIT_TEST(test_dot3);
    CPPUNIT_TEST(test_dot4);
    CPPUNIT_TEST(test_dot5);
    CPPUNIT_TEST(test_dot6);

    CPPUNIT_TEST(test_transpose);
    CPPUNIT_TEST(test_transpose2);
    CPPUNIT_TEST(test_transpose3);
    CPPUNIT_TEST(test_transpose4);
    CPPUNIT_TEST(test_transpose5);

    CPPUNIT_TEST(test_diag);
 	CPPUNIT_TEST(test_diag2);
 	CPPUNIT_TEST(test_diag3);
 	CPPUNIT_TEST(test_diag4);

     CPPUNIT_TEST(test_eye);
     CPPUNIT_TEST(test_eye2);
     CPPUNIT_TEST(test_eye3);
     CPPUNIT_TEST(test_eye4);
    //CPPUNIT_TEST(test_linsolve);

    CPPUNIT_TEST(test_rand);
    CPPUNIT_TEST(test_rand2);
    CPPUNIT_TEST(test_rand3);



    CPPUNIT_TEST(test_tril);
    CPPUNIT_TEST(test_tril2);
    CPPUNIT_TEST(test_tril3);
    CPPUNIT_TEST(test_triu);
    CPPUNIT_TEST(test_triu2);
    CPPUNIT_TEST(test_triu3);
    CPPUNIT_TEST(test_ones);
    CPPUNIT_TEST(test_ones2);
    CPPUNIT_TEST(test_ones3);
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
