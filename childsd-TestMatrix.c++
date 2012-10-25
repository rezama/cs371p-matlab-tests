// ------------------------------
// projects/matlab/TestMatrix.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
 * To test the program:
 *     g++ -ansi -pedantic -lcppunit -ldl -Wall TestMatrix.c++ -o TestMatrix.app
 *     valgrind ./TestMatrix.app >& TestMatrix.out
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

	void test_constructor_1 () {
		Matrix<int> x;
		Matrix<int> y(2);
		Matrix<int> z(2, 3);
		Matrix<int> t(2, 3, 4);
		CPPUNIT_ASSERT(x.size() == 0);
	}

	void test_constructor_2 () {
		Matrix<int> y(2);
		CPPUNIT_ASSERT(y.size() == 2);
	}

	void test_constructor_3 () {
		Matrix<int> z(2, 3);
		CPPUNIT_ASSERT(z.size() == 2);
		CPPUNIT_ASSERT(z[0].size() == 3);
	}

	void test_constructor_4 () {
		Matrix<int> t(2, 3, 4);
		CPPUNIT_ASSERT(t.size() == 2);
		CPPUNIT_ASSERT(t.begin()->size() == 3);
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 3; j++) {
				CPPUNIT_ASSERT(t[i][j] == 4);
			}
		}
	}

	// ----------
	// test_index
	// ----------

	void test_index_1 () {
		const Matrix<int> x(1,1);
		CPPUNIT_ASSERT(x[0][0] == 0);
	}

	void test_index_2 () {
		const Matrix<int> x(1,1,1);
		CPPUNIT_ASSERT(x[0][0] == 1);
	}

	void test_index_3 () {
		const Matrix<int> x(2,2,2);
		CPPUNIT_ASSERT(x[0][0] == 2);
		CPPUNIT_ASSERT(x[0][1] == 2);
		CPPUNIT_ASSERT(x[1][0] == 2);
		CPPUNIT_ASSERT(x[1][1] == 2);
	}

	void test_index_4 () {
		const Matrix<int> x(2,3,2);
		CPPUNIT_ASSERT(x[0][0] == 2);
		CPPUNIT_ASSERT(x[0][1] == 2);
		CPPUNIT_ASSERT(x[0][2] == 2);
		CPPUNIT_ASSERT(x[1][0] == 2);
		CPPUNIT_ASSERT(x[1][1] == 2);
		CPPUNIT_ASSERT(x[0][2] == 2);
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

	void test_equals_1 () {
		Matrix<int>  x(2, 1, 5);
		Matrix<int>  y(2, 1, 4);
		Matrix<bool> z;
		Matrix<bool> t(2, 1, 1);
		z = (x != y);
		CPPUNIT_ASSERT(z.eq(t));}

	void test_equals_2 () {
		Matrix<int>  x(1, 0, 0);
		Matrix<int>  y(1, 0, 0);
		Matrix<bool> z;
		Matrix<bool> t(1, 0, 1);
		z = (x != y);
		CPPUNIT_ASSERT(z.eq(t));}

	void test_equals_3 () {
		Matrix<int>  x(100, 100, 99);
		Matrix<int>  y(100, 100, 99);
		Matrix<bool> z;
		Matrix<bool> t(100, 100, 1);
		z = (x == y);
		CPPUNIT_ASSERT(z.eq(t));}

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

	void test_less_than_1 () {
		Matrix<int>  x1(1, 1, 1);
		Matrix<int>  y1(1, 1, 1);

		Matrix<int>  x2(1, 1, 1);
		Matrix<int>  y2(1, 1, 2);

		Matrix<bool> z1;
		Matrix<bool> t1(1, 1, 0);
		z1 = (x1 < y1);

		Matrix<bool> z2;
		Matrix<bool> t2(1, 1, 1);
		z2 = (x2 < y2);

		Matrix<bool> z3;
		Matrix<bool> t3(1, 1, 1);
		z3 = (x1 <= y1);

		Matrix<bool> z4;
		Matrix<bool> t4(1, 1, 1);
		z4 = (x1 >= y1);

		Matrix<bool> z5;
		Matrix<bool> t5(1, 1, 1);
		z5 = (y2 > x2);

		CPPUNIT_ASSERT(z1.eq(t1));
		CPPUNIT_ASSERT(z2.eq(t2));
		CPPUNIT_ASSERT(z3.eq(t3));
		CPPUNIT_ASSERT(z4.eq(t4));
		CPPUNIT_ASSERT(z5.eq(t5));
	}

	void test_less_than_2 () {
		Matrix<int>  x(3, 5, 25);
		Matrix<int>  y(3, 5, 24);
		Matrix<bool> z;
		Matrix<bool> t;
		z = (x < y);
		CPPUNIT_ASSERT(z.size() == x.size() && z.size() == y.size());
		CPPUNIT_ASSERT(z[0][0] == 0);
		CPPUNIT_ASSERT(z[2][4] == 0);
	}

	void test_less_than_3 () {
		Matrix<int>  x(3, 5, 24);
		Matrix<int>  y(3, 5, 25);
		Matrix<bool> z;
		Matrix<bool> t;
		z = (x < y);
		CPPUNIT_ASSERT(z.size() == x.size() && z.size() == y.size());
		CPPUNIT_ASSERT(z[0][0] == 1);
		CPPUNIT_ASSERT(z[2][4] == 1);
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

	void test_plus_1 () {
		Matrix<int> x(1, 1, 10);
		Matrix<int> y(24, 30, 5);
		Matrix<int> z;
		x += 0;
		CPPUNIT_ASSERT(x.eq(x));
		try {
			y += x;
			CPPUNIT_ASSERT(false);
		}
		catch (exception e){
			CPPUNIT_ASSERT(true);
		}
	}

	void test_plus_2 () {
		Matrix<int> x(24, 30, 10);
		Matrix<int> y(24, 30, 5);
		Matrix<int> z(24, 30, 15);
		x += 0;
		CPPUNIT_ASSERT(!(x.eq(z)));
		x += y;
		CPPUNIT_ASSERT(x[0][0] == 15);
		CPPUNIT_ASSERT(x[5][5] == 15);
		CPPUNIT_ASSERT(x[23][29] == 15);
		CPPUNIT_ASSERT(x.eq(z));
	}

	void test_plus_3 () {
		Matrix<int> x(1, 1, 0);
		Matrix<int> y(1, 1, 0);
		Matrix<int> z(1, 1, 0);
		x += y;
		CPPUNIT_ASSERT(x.eq(z));
		CPPUNIT_ASSERT(x.eq(y));
	}

	void test_plus_4 () {
		Matrix<int> x(1, 1, 5);
		Matrix<int> dup_x(1, 1, 5);
		Matrix<int> y(1, 1, 6);
		Matrix<int> dup_y(1, 1, 6);
		Matrix<int> a(1, 1, 11);
		Matrix<int> z;
		z = x + y;
		CPPUNIT_ASSERT(z.eq(a));
		CPPUNIT_ASSERT(x.eq(dup_x));
		CPPUNIT_ASSERT(y.eq(dup_y));
	}

	// ----------
	// test_minus
	// ----------

	void test_minus_1 () {
		Matrix<int> x;
		Matrix<int> y;
		Matrix<int> z;
		x -= 0;
		CPPUNIT_ASSERT(x.eq(z));
		x -= y;
		CPPUNIT_ASSERT(x.eq(z));}

	void test_minus_2 () {
		Matrix<int> x(1,1,1);
		x -= 0;
		CPPUNIT_ASSERT(x[0][0] == 1);}

	void test_minus_3 () {
		Matrix<int> x(1,1,1);
		Matrix<int> y(1,1,1);
		x -= y;
		CPPUNIT_ASSERT(x[0][0] == 0);}

	void test_minus_4 () {
		Matrix<int> x(2,2,3);
		Matrix<int> y(2,2,1);
		x -= y;
		CPPUNIT_ASSERT(x[0][0] == 2);
		CPPUNIT_ASSERT(x[0][1] == 2);
		CPPUNIT_ASSERT(x[1][0] == 2);
		CPPUNIT_ASSERT(x[1][1] == 2);}

	void test_minus_5 () {
		Matrix<int> x(1, 1, 5);
		Matrix<int> dup_x(1, 1, 5);
		Matrix<int> y(1, 1, 6);
		Matrix<int> dup_y(1, 1, 6);
		Matrix<int> a(1, 1, -1);
		Matrix<int> z;
		z = x - y;
		CPPUNIT_ASSERT(z.eq(a));
		CPPUNIT_ASSERT(x.eq(dup_x));
		CPPUNIT_ASSERT(y.eq(dup_y));
	}

	// ---------------
	// test_multiplies
	// ---------------

	void test_multiplies_1 () {
		Matrix<int> x(2,2,3);
		x *= 2;
		CPPUNIT_ASSERT(x[0][0] = 6);
		CPPUNIT_ASSERT(x[0][1] = 6);
		CPPUNIT_ASSERT(x[0][0] = 6);
		CPPUNIT_ASSERT(x[1][1] = 6);}

	void test_multiplies_2 () {
		Matrix<int> x(2,2,2);
		Matrix<int> y(2,2,3);
		x *= y;
		CPPUNIT_ASSERT(x[0][0] = 6);
		CPPUNIT_ASSERT(x[0][1] = 6);
		CPPUNIT_ASSERT(x[0][0] = 6);
		CPPUNIT_ASSERT(x[1][1] = 6);}

	void test_multiplies_3 () {
		Matrix<int> x(2,3);
		int x_vals[6] = {1,0,-2,0,3,-1};
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 3; j++) {
				x[i][j] = x_vals[j+3*i];
			}
		}

		Matrix<int> y(3,2);
		int y_vals[6] = {0,3,-2,-1,0,4};
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 2; j++) {
				y[i][j] = y_vals[j+2*i];
			}
		}

		Matrix<int> prod(2,2);
		prod[0][0] = 0;
		prod[0][1] = -5;
		prod[1][0] = -6;
		prod[1][1] = -7;

		x *= y;
		CPPUNIT_ASSERT(x.eq(prod));}

	void test_multiplies_4 () {
		Matrix<int> x(2,2);
		x[0][0] = 8;
		x[0][1] = 9;
		x[1][0] = 5;
		x[1][1] = -1;

		Matrix<int> y(2,2);
		x[0][0] = -2;
		x[0][1] = 3;
		x[1][0] = 4;
		x[1][1] = 0;

		Matrix<int> prod(2,2);
		x[0][0] = 20;
		x[0][1] = 24;
		x[1][0] = -14;
		x[1][1] = 15;

		x *= y;
		CPPUNIT_ASSERT(x.eq(prod));}

	void test_multiplies_5 () {
		Matrix<int> x(2,2,2);
		Matrix<int> dup_x(2,2,2);
		Matrix<int> y(2,2,3);
		Matrix<int> dup_y(2,2,3);
		Matrix<int> z;
		z = x * y;
		CPPUNIT_ASSERT(z[0][0] = 6);
		CPPUNIT_ASSERT(z[0][1] = 6);
		CPPUNIT_ASSERT(z[0][0] = 6);
		CPPUNIT_ASSERT(z[1][1] = 6);
		CPPUNIT_ASSERT(x.eq(dup_x));
		CPPUNIT_ASSERT(y.eq(dup_y));}

	// -------------
	// test_iterator
	// -------------

	void test_iterator_1 () {
		Matrix<int> x;
		Matrix<int>::iterator b = x.begin();
		Matrix<int>::iterator e = x.end();
		CPPUNIT_ASSERT(b == e);}

	void test_iterator_2 () {
		Matrix<int> x(1,1);
		Matrix<int>::iterator b = x.begin();
		Matrix<int>::iterator e = x.end();
		CPPUNIT_ASSERT(b+1 == e);}

	void test_iterator_3 () {
		Matrix<int> x(2,2);
		Matrix<int>::iterator b = x.begin();
		Matrix<int>::iterator e = x.end();
		CPPUNIT_ASSERT(b+2 == e);}

	// -------------------
	// test_const_iterator
	// -------------------

	void test_const_iterator_1 () {
		const Matrix<int> x;
		Matrix<int>::const_iterator b = x.begin();
		Matrix<int>::const_iterator e = x.end();
		CPPUNIT_ASSERT(b == e);}

	void test_const_iterator_2 () {
		Matrix<int> x(1,1);
		Matrix<int>::const_iterator b = x.begin();
		Matrix<int>::const_iterator e = x.end();
		CPPUNIT_ASSERT(b+1 == e);}

	void test_const_iterator_3 () {
		Matrix<int> x(2,2);
		Matrix<int>::iterator b = x.begin();
		Matrix<int>::iterator e = x.end();
		CPPUNIT_ASSERT(b+2 == e);}

	// -----
	// suite
	// -----

	CPPUNIT_TEST_SUITE(TestMatrix);
	CPPUNIT_TEST(test_constructor_1);
	CPPUNIT_TEST(test_constructor_2);
	CPPUNIT_TEST(test_constructor_3);
	CPPUNIT_TEST(test_constructor_4);
	CPPUNIT_TEST(test_index_1);
	CPPUNIT_TEST(test_index_2);
	CPPUNIT_TEST(test_index_3);
	CPPUNIT_TEST(test_index_4);
	CPPUNIT_TEST(test_equals);
	CPPUNIT_TEST(test_equals_1);
	CPPUNIT_TEST(test_equals_2);
	CPPUNIT_TEST(test_equals_3);
	CPPUNIT_TEST(test_less_than);
	CPPUNIT_TEST(test_less_than_1);
	CPPUNIT_TEST(test_less_than_2);
	CPPUNIT_TEST(test_less_than_3);
	CPPUNIT_TEST(test_plus);
	CPPUNIT_TEST(test_plus_1);
	CPPUNIT_TEST(test_plus_2);
	CPPUNIT_TEST(test_plus_3);
	CPPUNIT_TEST(test_plus_4);
	CPPUNIT_TEST(test_minus_1);
	CPPUNIT_TEST(test_minus_2);
	CPPUNIT_TEST(test_minus_3);
	CPPUNIT_TEST(test_minus_4);
	CPPUNIT_TEST(test_minus_5);
	CPPUNIT_TEST(test_multiplies_1);
	CPPUNIT_TEST(test_multiplies_2);
	CPPUNIT_TEST(test_multiplies_3);
	CPPUNIT_TEST(test_multiplies_4);
	CPPUNIT_TEST(test_multiplies_5);
	CPPUNIT_TEST(test_iterator_1);
	CPPUNIT_TEST(test_iterator_2);
	CPPUNIT_TEST(test_iterator_3);
	CPPUNIT_TEST(test_const_iterator_1);
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
