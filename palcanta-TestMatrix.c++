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
        CPPUNIT_ASSERT(x.size() == 0);
	CPPUNIT_ASSERT(y.size() == 2);
	CPPUNIT_ASSERT(z.size() == 2);
	CPPUNIT_ASSERT(z[0].size() == 3);
	CPPUNIT_ASSERT(t[1][2] == 4);}

    void test_constructor_2 () {
        Matrix<int> x;
        Matrix<int> y(24);
        Matrix<int> z(24, 24);
        Matrix<int> t(2, 3, 1);
        CPPUNIT_ASSERT(x.size() == 0);
	CPPUNIT_ASSERT(y.size() == 24);
	CPPUNIT_ASSERT(z.size() == 24);
	CPPUNIT_ASSERT(z[0].size() == 24);
	CPPUNIT_ASSERT(t.size() == 2);
	CPPUNIT_ASSERT(t[0].size() == 3);
	CPPUNIT_ASSERT(t[0][0] == 1);
	CPPUNIT_ASSERT(t[0][1] == 1);
	CPPUNIT_ASSERT(t[0][2] == 1);
    
	CPPUNIT_ASSERT(t[1][0] == 1);
	CPPUNIT_ASSERT(t[1][1] == 1);
	CPPUNIT_ASSERT(t[1][2] == 1);
    }
    void test_constructor_3 () {
        Matrix<int> x;
        Matrix<int> y(5);
        Matrix<int> z(4, 2);
        Matrix<int> t(1, 1, 42);
        CPPUNIT_ASSERT(x.size() == 0);
	CPPUNIT_ASSERT(y.size() == 5);
	CPPUNIT_ASSERT(z.size() == 4);
	CPPUNIT_ASSERT(z[0].size() == 2);
	CPPUNIT_ASSERT(t[0][0] == 42);}
    // ----------
    // test_index
    // ----------

    void test_index () {
        const Matrix<int> x (1,1,1);
        CPPUNIT_ASSERT(x[0][0] == 1);}

    void test_index_2 () {
        const Matrix<int> x (4,2,42);
	CPPUNIT_ASSERT(x[0][0] == 42);

	CPPUNIT_ASSERT(x[0][1] == 42);
	CPPUNIT_ASSERT(x[1][0] == 42);
	CPPUNIT_ASSERT(x[1][1] == 42);
	CPPUNIT_ASSERT(x[2][0] == 42);
	CPPUNIT_ASSERT(x[2][1] == 42);
	CPPUNIT_ASSERT(x[3][0] == 42);
        CPPUNIT_ASSERT(x[3][1] == 42);}
    void test_index_3 () {
        Matrix<int> x (2,2,2);
	x[0][0] = 0;
	x[1][0] = 42;
        CPPUNIT_ASSERT(x[0][0] == 0);
        CPPUNIT_ASSERT(x[0][1] == 2);
        CPPUNIT_ASSERT(x[1][0] == 42);
        CPPUNIT_ASSERT(x[1][1] == 2);
    }
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
        
    void test_equals_2() {
    	Matrix<int> x (2, 2, 5);
    	Matrix<int> y (2, 2, 5);
    	Matrix<bool> t (2, 2, true);
    	Matrix<bool> result = (x==y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}

    void test_equals_3() {
    	Matrix<int> x (2, 2, 5);
    	Matrix<int> y (2, 2, 4);
    	Matrix<bool> t (2, 2, false);
    	Matrix<bool> result = (x==y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}
    void test_equals_4(){
	Matrix<int> x(2, 2,5);
	Matrix<int> y(1,1,1);
	try{
		Matrix<bool> result = (x==y);
		CPPUNIT_ASSERT(false);
	}
	catch(std::invalid_argument& e){
		CPPUNIT_ASSERT(true);
	}
    }	
    void test_notEquals () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}
        
    void test_notEquals_2() {
    	Matrix<int> x (2, 2, 5);
    	Matrix<int> y (2, 2, 5);
    	Matrix<bool> t (2, 2, false);
    	Matrix<bool> result = (x!=y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}

    void test_notEquals_3() {
    	Matrix<int> x (2, 2, 5);
    	Matrix<int> y (2, 2, 4);
    	Matrix<bool> t (2, 2, true);
    	Matrix<bool> result = (x!=y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}

    void test_notEquals_4(){
	Matrix<int> x(2, 2,5);
	Matrix<int> y(1,1,1);
	try{
		Matrix<bool> result = (x!=y);
		CPPUNIT_ASSERT(false);
	}
	catch(std::invalid_argument& e){
		CPPUNIT_ASSERT(true);
	}
    }	
    // --------------
    // test_less_than
    // --------------

    void test_less_than () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x < y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_2() {
    	Matrix<int> x (2, 2, 5);
    	Matrix<int> y (2, 2, 5);
    	Matrix<bool> t (2, 2, false);
    	Matrix<bool> result = (x < y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}

    void test_less_than_3() {
    	Matrix<int> x (2, 2, 5);
    	Matrix<int> y (2, 2, 6);
    	Matrix<bool> t (2, 2, true);
    	Matrix<bool> result = (x < y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}

    void test_less_than_4() {
    	Matrix<int> x (2, 2, 6);
    	Matrix<int> y (2, 2, 5);
    	Matrix<bool> t (2, 2, false);
    	Matrix<bool> result = (x < y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}
	
    void test_less_than_5(){
	Matrix<int> x(2, 2,5);
	Matrix<int> y(1,1,1);
	try{
		Matrix<bool> result = (x < y);
		CPPUNIT_ASSERT(false);
	}
	catch(std::invalid_argument& e){
		CPPUNIT_ASSERT(true);
	}
    }	
    // --------------
    // test_less_than_equals
    // --------------

    void test_less_than_equals () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x <= y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_less_than_equals_2() {
    	Matrix<int> x (2, 2, 5);
    	Matrix<int> y (2, 2, 5);
    	Matrix<bool> t (2, 2, true);
    	Matrix<bool> result = (x <= y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}

    void test_less_than_equals_3() {
    	Matrix<int> x (2, 2, 5);
    	Matrix<int> y (2, 2, 6);
    	Matrix<bool> t (2, 2, true);
    	Matrix<bool> result = (x <= y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}

    void test_less_than_equals_4() {
    	Matrix<int> x (2, 2, 6);
    	Matrix<int> y (2, 2, 5);
    	Matrix<bool> t (2, 2, false);
    	Matrix<bool> result = (x <= y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}
	
    void test_less_than_equals_5(){
	Matrix<int> x(2, 2,5);
	Matrix<int> y(1,1,1);
	try{
		Matrix<bool> result = (x<=y);
		CPPUNIT_ASSERT(false);
	}
	catch(std::invalid_argument& e){
		CPPUNIT_ASSERT(true);
	}
    }	
    // --------------
    // test_greater_than
    // --------------

    void test_greater_than () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_2() {
    	Matrix<int> x (2, 2, 5);
    	Matrix<int> y (2, 2, 5);
    	Matrix<bool> t (2, 2, false);
    	Matrix<bool> result = (x > y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}

    void test_greater_than_3() {
    	Matrix<int> x (2, 2, 5);
    	Matrix<int> y (2, 2, 6);
    	Matrix<bool> t (2, 2, false);
    	Matrix<bool> result = (x > y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}

    void test_greater_than_4() {
    	Matrix<int> x (2, 2, 6);
    	Matrix<int> y (2, 2, 5);
    	Matrix<bool> t (2, 2, true);
    	Matrix<bool> result = (x > y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}

    void test_greater_than_5(){
	Matrix<int> x(2, 2,5);
	Matrix<int> y(1,1,1);
	try{
		Matrix<bool> result = (x>y);
		CPPUNIT_ASSERT(false);
	}
	catch(std::invalid_argument& e){
		CPPUNIT_ASSERT(true);
	}
    }	
    // --------------
    // test_greater_than
    // --------------

    void test_greater_than_equals () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x > y);
        CPPUNIT_ASSERT(z.eq(t));}

    void test_greater_than_equals_2() {
    	Matrix<int> x (2, 2, 5);
    	Matrix<int> y (2, 2, 5);
    	Matrix<bool> t (2, 2, true);
    	Matrix<bool> result = (x >= y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}

    void test_greater_than_equals_3() {
    	Matrix<int> x (2, 2, 5);
    	Matrix<int> y (2, 2, 6);
    	Matrix<bool> t (2, 2, false);
    	Matrix<bool> result = (x >= y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}

    void test_greater_than_equals_4() {
    	Matrix<int> x (2, 2, 6);
    	Matrix<int> y (2, 2, 5);
    	Matrix<bool> t (2, 2, true);
    	Matrix<bool> result = (x >= y);
    	CPPUNIT_ASSERT(result.eq(t));
    	}

    void test_greater_than_equals_5(){
	Matrix<int> x(2, 2,5);
	Matrix<int> y(1,1,1);
	try{
		Matrix<bool> result = (x>=y);
		CPPUNIT_ASSERT(false);
	}
	catch(std::invalid_argument& e){
		CPPUNIT_ASSERT(true);
	}
    }	
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
        
        
    void test_plus_2 () {
        Matrix<int> x(2, 2, 5);
        Matrix<int> y(2, 2, 10);
        Matrix<int> z(2, 2, 20);
        x += 5;
        CPPUNIT_ASSERT(x.eq(y));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_plus_3 () {
	Matrix<int> x(2, 2, 0);
	x[0][0] = 1;
	x[0][1] = 2;
	x[1][0] = 3;
	x[1][1] = 4;
	x += 1;
	Matrix<int> y(2,2,0);
	y[0][0] = 2;
	y[0][1] = 3;
	y[1][0] = 4;
	y[1][1] = 5;
	CPPUNIT_ASSERT(x.eq(y));
	x += y;
	Matrix<int> z(2,2,0);
	z[0][0] = 4;
	z[0][1] = 6;
	z[1][0] = 8;
	z[1][1] = 10;
	CPPUNIT_ASSERT(x.eq(z));	
    }


    void test_plus_4(){
	Matrix<int> x(2, 2,5);
	Matrix<int> y(1,1,1);
	try{
		x+=y;	
		CPPUNIT_ASSERT(false);
	}
	catch(std::invalid_argument& e){
		CPPUNIT_ASSERT(true);
	}
    }	
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
        

	void test_minus_2 () {
        Matrix<int> x(2, 2, 20);
        Matrix<int> y(2, 2, 15);
        Matrix<int> z(2, 2, 0);
        x -= 5;
        CPPUNIT_ASSERT(x.eq(y));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}

    void test_minus_3 () {
	Matrix<int> x(2,2,0);
	Matrix<int> y(2,2,0);
	Matrix<int> z(2,2,0);

	x[0][0] = 1;
	x[0][1] = 2;
	x[1][0] = 3;
	x[1][1] = 4;
	x-=1;

	y[0][0] = 0;
	y[0][1] = 1;
	y[1][0] = 2;
	y[1][1] = 3;

	CPPUNIT_ASSERT(x.eq(y));

	x-=y;

	CPPUNIT_ASSERT(x.eq(z)); 
    }

    void test_minus_4(){
	Matrix<int> x(2, 2,5);
	Matrix<int> y(1,1,1);
	try{
		x-=y;	
		CPPUNIT_ASSERT(false);
	}
	catch(std::invalid_argument& e){
		CPPUNIT_ASSERT(true);
	}
    }	
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
        CPPUNIT_ASSERT(x.eq(z));
	}
	
	void test_multiplies_2 () {
		Matrix<int> x (3,2,0);
		Matrix<int> y (2,3,0);
		Matrix<int> result(3,3,0);
		x[0][0] = 1;
		x[0][1] = 2;
		x[1][0] = 1;
		x[1][1] = 3;
		x[2][0] = 2;
		x[2][1] = 1;
		
		y[0][0] = 1;
		y[0][1] = 2;
		y[0][2] = 3;
		y[1][0] = 1;
		y[1][1] = 1;
		y[1][2] = 4;
		
		result[0][0] = 3;
		result[0][1] = 4;
		result[0][2] = 11;
		result[1][0] = 4;
		result[1][1] = 5;
		result[1][2] = 15;
		result[2][0] = 3;
		result[2][1] = 5;
		result[2][2] = 10;
		
		x *= y;
		CPPUNIT_ASSERT(x.eq(result));
		
		}

    void test_multiplies_3(){
	Matrix<int> x(2, 2,5);
	Matrix<int> y(1,1,1);
	try{
		x*=y;	
		CPPUNIT_ASSERT(false);
	}
	catch(std::invalid_argument& e){
		CPPUNIT_ASSERT(true);
	}
    }
    void test_eq(){
	Matrix<int> x(4,4,2);
	Matrix<int> y(4,4,2);
	CPPUNIT_ASSERT(x.eq(y));
    }
    void test_eq_1(){
	Matrix<int> x(1,1,1);
	Matrix<int> y(2,2,1);
	CPPUNIT_ASSERT(!x.eq(y));
    }
    void test_eq_2(){
	Matrix<int> x;
	Matrix<int> y;
	CPPUNIT_ASSERT(x.eq(y));
    }
    void test_eq_3(){
	Matrix<int> x(2,2,2);
	Matrix<int> y(2,2,1);
	CPPUNIT_ASSERT(!x.eq(y));
   }
    // -------------
    // test_iterator
    // -------------

    void test_iterator () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    void test_iterator_2 () {
        Matrix<int> x(2, 2, 2);
	Matrix<int> y(2, 2, 2);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
	for(unsigned int i=0;i<x.size();i++){
		for(unsigned int j=0;j<x[0].size();j++){
			CPPUNIT_ASSERT((*b)[j] == y[i][j]);
		}
		++b;
	} 
    }

    void test_iterator_3 () {
        Matrix<int> x(4, 5, 15);
	Matrix<int> y(4, 5, 15);
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
	for(unsigned int i=0;i<x.size();i++){
		for(unsigned int j=0;j<x[0].size();j++){
			CPPUNIT_ASSERT((*b)[j] == y[i][j]);
		}
		++b;
	} 
    }
    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    void test_const_iterator_2 () {
        Matrix<int> x(2, 2, 2);
	Matrix<int> y(2, 2, 2);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
	for(unsigned int i=0;i<x.size();i++){
		for(unsigned int j=0;j<x[0].size();j++){
			CPPUNIT_ASSERT((*b)[j] == y[i][j]);
		}
		++b;
	} 
    }

    void test_const_iterator_3 () {
        Matrix<int> x(4, 5, 15);
	Matrix<int> y(4, 5, 15);
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
	for(unsigned int i=0;i<x.size();i++){
		for(unsigned int j=0;j<x[0].size();j++){
			CPPUNIT_ASSERT((*b)[j] == y[i][j]);
		}
		++b;
	} 
    }
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor); 
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_index);

    CPPUNIT_TEST(test_index_2);
    CPPUNIT_TEST(test_index_3);
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_equals_2);
    CPPUNIT_TEST(test_equals_3);
    CPPUNIT_TEST(test_equals_4);
    CPPUNIT_TEST(test_notEquals);
    CPPUNIT_TEST(test_notEquals_2);
    CPPUNIT_TEST(test_notEquals_3);
    CPPUNIT_TEST(test_notEquals_4);
	CPPUNIT_TEST(test_less_than);
	CPPUNIT_TEST(test_less_than_2);
	CPPUNIT_TEST(test_less_than_3);
	CPPUNIT_TEST(test_less_than_4);
	CPPUNIT_TEST(test_less_than_5);
	CPPUNIT_TEST(test_less_than_equals);
	CPPUNIT_TEST(test_less_than_equals_2);
	CPPUNIT_TEST(test_less_than_equals_3);
	CPPUNIT_TEST(test_less_than_equals_4);
	CPPUNIT_TEST(test_less_than_equals_5);
	CPPUNIT_TEST(test_greater_than);
	CPPUNIT_TEST(test_greater_than_2);
	CPPUNIT_TEST(test_greater_than_3);
	CPPUNIT_TEST(test_greater_than_4);
	CPPUNIT_TEST(test_greater_than_5);
	CPPUNIT_TEST(test_greater_than_equals);
	CPPUNIT_TEST(test_greater_than_equals_2);
	CPPUNIT_TEST(test_greater_than_equals_3);
	CPPUNIT_TEST(test_greater_than_equals_4);
	CPPUNIT_TEST(test_greater_than_equals_5);
    CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(test_plus_2);
    CPPUNIT_TEST(test_plus_3);
    CPPUNIT_TEST(test_plus_4);
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_minus_2);
    CPPUNIT_TEST(test_minus_3);
    CPPUNIT_TEST(test_minus_4);
    CPPUNIT_TEST(test_multiplies);
    CPPUNIT_TEST(test_multiplies_2);
    CPPUNIT_TEST(test_multiplies_3);
    CPPUNIT_TEST(test_eq);
    CPPUNIT_TEST(test_eq_2);
    CPPUNIT_TEST(test_eq_3);
    CPPUNIT_TEST(test_iterator);
    CPPUNIT_TEST(test_iterator_2);
    CPPUNIT_TEST(test_iterator_3);
    CPPUNIT_TEST(test_const_iterator);
    CPPUNIT_TEST(test_const_iterator_2);
    CPPUNIT_TEST(test_const_iterator_3);
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
