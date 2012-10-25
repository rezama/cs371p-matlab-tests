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

        // verify row sizes
        CPPUNIT_ASSERT(x.size() == 0);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(z.size() == 2);
        CPPUNIT_ASSERT(t.size() == 2);

        // verify column sizes
        CPPUNIT_ASSERT(z[0].size() == 3);
        CPPUNIT_ASSERT(t[0].size() == 3);

    }


    // ----------
    // test_index
    // ----------

    void test_index () {
        const Matrix<int> x(2, 2, 2);
        CPPUNIT_ASSERT(x[0][0] == 2);

    }


    // -----------
    // test_equals
    // -----------

    void test_equals_1 () {
        Matrix<int> x;
        Matrix<int> y;

        Matrix<bool> eq = x == y;
        Matrix<bool> eq_not = x != y;

        CPPUNIT_ASSERT(eq.size() == 0);
        CPPUNIT_ASSERT(eq_not.size() == 0);
    }

    void test_equals_2() {
        Matrix<int> x(2, 2, 2);
        Matrix<int> y(2, 2, 2);

        Matrix<bool> eq = x == y;
        Matrix<bool> eq_not = x != y;

        CPPUNIT_ASSERT(eq.size() == x.size());
        CPPUNIT_ASSERT(eq_not.size() == x.size());
        CPPUNIT_ASSERT(eq[0].size() == x[0].size());
        CPPUNIT_ASSERT(eq_not[0].size() == x[0].size());

        for (int i=0; i < (int)eq.size(); i++){
            for (int j=0; j < (int)eq[0].size(); j++){
                CPPUNIT_ASSERT(eq[i][j] == true);
                CPPUNIT_ASSERT(eq_not[i][j] == false);
            }
        }
    }

    void test_equals_3() {
        Matrix<int> ones(2, 2, 1);
        Matrix<int> twos(2, 2, 2);

        Matrix<bool> eq = ones == twos;
        Matrix<bool> eq_not = ones != twos;
        
        for (int i=0; i < (int)eq.size(); i++){
            for (int j=0; j < (int)eq[0].size(); j++){
                CPPUNIT_ASSERT(eq[i][j] == false);
                CPPUNIT_ASSERT(eq_not[i][j] == true);
            }

        }
    }

    void test_equals_4() {
        Matrix<int> ones(2, 2, 1);
        Matrix<int> twos(2, 2, 2);

        ones[0][0] = 2;
        Matrix<bool> eq = ones == twos; 
        Matrix<bool> eq_not = ones != twos; 

        for (int i=0; i < (int)eq.size(); i++){
            for (int j=0; j < (int)eq[0].size(); j++){
                if(i == 0 && j == 0) {
                    CPPUNIT_ASSERT(eq[i][j] == true);
                    CPPUNIT_ASSERT(eq_not[i][j] == false);
                }
                else {
                    CPPUNIT_ASSERT(eq[i][j] == false);
                    CPPUNIT_ASSERT(eq_not[i][j] == true);
                }
            }

        }
    }

    // --------------
    // test_less_than
    // --------------

    void test_less_than_1 () {
        Matrix<int> x;
        Matrix<int> y;

        Matrix<bool> less = x < y;
        Matrix<bool> less_eq = x <= y;

        CPPUNIT_ASSERT(less.size() == 0);
        CPPUNIT_ASSERT(less_eq.size() == 0);
    }

    void test_less_than_2 () {
        Matrix<int> x(2, 2, 2);
        Matrix<int> y(2, 2, 2);

        Matrix<bool> less = x < y;
        Matrix<bool> less_eq = x <= y;

        CPPUNIT_ASSERT(less.size() == x.size());
        CPPUNIT_ASSERT(less_eq.size() == x.size());
        CPPUNIT_ASSERT(less[0].size() == x[0].size());
        CPPUNIT_ASSERT(less_eq[0].size() == x[0].size());

        for (int i=0; i < (int)less.size(); i++){
            for (int j=0; j < (int)less[0].size(); j++){
                CPPUNIT_ASSERT(less[i][j] == false);
                CPPUNIT_ASSERT(less_eq[i][j] == true);
            }
        }
    }

    void test_less_than_3 () {
        Matrix<int> ones(2, 2, 1);
        Matrix<int> twos(2, 2, 2);

        Matrix<bool> less_true = ones < twos;
        Matrix<bool> less_eq_true = ones <= twos;
        Matrix<bool> less_false = twos < ones;
        Matrix<bool> less_eq_false = twos <= ones;
        
        for (int i=0; i < (int)ones.size(); i++){
            for (int j=0; j < (int)ones[0].size(); j++){
                CPPUNIT_ASSERT(less_true[i][j] == true);
                CPPUNIT_ASSERT(less_eq_true[i][j] == true);
                CPPUNIT_ASSERT(less_false[i][j] == false);
                CPPUNIT_ASSERT(less_eq_false[i][j] == false);
            }

        }
    }

    void test_less_than_4 () {
        Matrix<int> ones(2, 2, 1);
        Matrix<int> twos(2, 2, 2);

        ones[0][0] = 2;
        Matrix<bool> less = ones < twos; 
        Matrix<bool> less_eq = ones <= twos; 

        for (int i=0; i < (int)ones.size(); i++){
            for (int j=0; j < (int)ones[0].size(); j++){
                if(i == 0 && j == 0) {
                    CPPUNIT_ASSERT(less[i][j] == false);
                    CPPUNIT_ASSERT(less_eq[i][j] == true);
                }
                else {
                    CPPUNIT_ASSERT(less[i][j] == true);
                    CPPUNIT_ASSERT(less_eq[i][j] == true);
                }
            }

        }
    }

    // --------------
    // test_greater_than
    // --------------

    void test_greater_than_1 () {
        Matrix<int> x;
        Matrix<int> y;

        Matrix<bool> greater = x > y;
        Matrix<bool> greater_eq = x >= y;

        CPPUNIT_ASSERT(greater.size() == 0);
        CPPUNIT_ASSERT(greater_eq.size() == 0);
    }

    void test_greater_than_2 () {
        Matrix<int> x(2, 2, 2);
        Matrix<int> y(2, 2, 2);

        Matrix<bool> greater = x > y;
        Matrix<bool> greater_eq = x >= y;

        CPPUNIT_ASSERT(greater.size() == x.size());
        CPPUNIT_ASSERT(greater_eq.size() == x.size());
        CPPUNIT_ASSERT(greater[0].size() == x[0].size());
        CPPUNIT_ASSERT(greater_eq[0].size() == x[0].size());

        for (int i=0; i < (int)greater.size(); i++){
            for (int j=0; j < (int)greater[0].size(); j++){
                CPPUNIT_ASSERT(greater[i][j] == false);
                CPPUNIT_ASSERT(greater_eq[i][j] == true);
            }
        }
    }

    void test_greater_than_3 () {
        Matrix<int> ones(2, 2, 1);
        Matrix<int> twos(2, 2, 2);

        Matrix<bool> greater_true = twos > ones;
        Matrix<bool> greater_eq_true = twos >= ones;
        Matrix<bool> greater_false = ones > twos;
        Matrix<bool> greater_eq_false = ones >= twos;
        
        for (int i=0; i < (int)ones.size(); i++){
            for (int j=0; j < (int)ones[0].size(); j++){
                CPPUNIT_ASSERT(greater_true[i][j] == true);
                CPPUNIT_ASSERT(greater_eq_true[i][j] == true);
                CPPUNIT_ASSERT(greater_false[i][j] == false);
                CPPUNIT_ASSERT(greater_eq_false[i][j] == false);
            }

        }
    }

    void test_greater_than_4 () {
        Matrix<int> ones(2, 2, 1);
        Matrix<int> twos(2, 2, 2);

        ones[0][0] = 2;
        Matrix<bool> greater = twos > ones; 
        Matrix<bool> greater_eq = twos >= ones; 

        for (int i=0; i < (int)ones.size(); i++){
            for (int j=0; j < (int)ones[0].size(); j++){
                if(i == 0 && j == 0) {
                    CPPUNIT_ASSERT(greater[i][j] == false);
                    CPPUNIT_ASSERT(greater_eq[i][j] == true);
                }
                else {
                    CPPUNIT_ASSERT(greater[i][j] == true);
                    CPPUNIT_ASSERT(greater_eq[i][j] == true);
                }
            }

        }
    }

    // ---------
    // test_plus
    // ---------

    void test_plus_1 () {
        Matrix<int> x(2, 2, 2);
        Matrix<int> y = x + 1;

        for (int i=0; i < (int)y.size(); i++){
            for (int j=0; j < (int)y[0].size(); j++){
                CPPUNIT_ASSERT(y[i][j] == 3);
            }
        } 
    }

    void test_plus_2 () {
        Matrix<int> x(2, 2, 2);
        Matrix<int> y = x + (-2);

        for (int i=0; i < (int)y.size(); i++){
            for (int j=0; j < (int)y[0].size(); j++){
                CPPUNIT_ASSERT(y[i][j] == 0);
            }
        } 
  
    }

    void test_plus_3 () {
        Matrix<int> twos(2, 2, 2);
        Matrix<int> ones(2, 2, 1);
        twos[0][0] = 0;
        
        Matrix<int> sol = twos + ones;

        for (int i=0; i < (int)sol.size(); i++){
            for (int j=0; j < (int)sol[0].size(); j++){
                if (i==0 && j==0)
                    CPPUNIT_ASSERT(sol[i][j] == 1);
                else
                    CPPUNIT_ASSERT(sol[i][j] == 3);
            }
        } 
  
    }

    void test_plus_4 () {
        Matrix<int> twos(2, 2, 2);
        twos[0][0] = 0;
        twos += 4;

        for (int i=0; i < (int)twos.size(); i++){
            for (int j=0; j < (int)twos[0].size(); j++){
                if (i==0 && j==0)
                    CPPUNIT_ASSERT(twos[i][j] == 4);
                else
                    CPPUNIT_ASSERT(twos[i][j] == 6);
            }
        } 
  
    }

    void test_plus_5 () {
        Matrix<int> twos(2, 2, 2);
        Matrix<int> ones(2, 2, 1);
        twos[0][0] = 0;

        twos += ones;

        for (int i=0; i < (int)twos.size(); i++){
            for (int j=0; j < (int)twos[0].size(); j++){
                if (i==0 && j==0)
                    CPPUNIT_ASSERT(twos[i][j] == 1);
                else
                    CPPUNIT_ASSERT(twos[i][j] == 3);
            }
        } 
  
    }

    // ----------
    // test_minus
    // ----------

    void test_minus_1 () {
        Matrix<int> x(2, 2, 2);
        Matrix<int> y = x - 1;

        for (int i=0; i < (int)y.size(); i++){
            for (int j=0; j < (int)y[0].size(); j++){
                CPPUNIT_ASSERT(y[i][j] == 1);
            }
        } 
    }

    void test_minus_2 () {
        Matrix<int> x(2, 2, 2);
        Matrix<int> y = x - (-2);

        for (int i=0; i < (int)y.size(); i++){
            for (int j=0; j < (int)y[0].size(); j++){
                CPPUNIT_ASSERT(y[i][j] == 4);
            }
        } 
  
    }

    void test_minus_3 () {
        Matrix<int> twos(2, 2, 2);
        Matrix<int> ones(2, 2, 1);
        twos[0][0] = 0;
        
        Matrix<int> sol = twos - ones;

        for (int i=0; i < (int)sol.size(); i++){
            for (int j=0; j < (int)sol[0].size(); j++){
                if (i==0 && j==0)
                    CPPUNIT_ASSERT(sol[i][j] == -1);
                else
                    CPPUNIT_ASSERT(sol[i][j] == 1);
            }
        } 
  
    }

    void test_minus_4 () {
        Matrix<int> twos(2, 2, 2);
        twos[0][0] = 0;
        twos -= 4;

        for (int i=0; i < (int)twos.size(); i++){
            for (int j=0; j < (int)twos[0].size(); j++){
                if (i==0 && j==0)
                    CPPUNIT_ASSERT(twos[i][j] == -4);
                else
                    CPPUNIT_ASSERT(twos[i][j] == -2);
            }
        } 
  
    }

    void test_minus_5 () {
        Matrix<int> twos(2, 2, 2);
        Matrix<int> ones(2, 2, 1);
        twos[0][0] = 0;

        twos -= ones;

        for (int i=0; i < (int)twos.size(); i++){
            for (int j=0; j < (int)twos[0].size(); j++){
                if (i==0 && j==0)
                    CPPUNIT_ASSERT(twos[i][j] == -1);
                else
                    CPPUNIT_ASSERT(twos[i][j] == 1);
            }
        } 
  
    }


    // ---------------
    // test_multiplies
    // ---------------

    void test_multiplies_scalar_1 () {
        Matrix<int> x(2, 2, 1);
        x[0][0] = 4;
        Matrix<int> y = x * 4;

        for (int i=0; i < (int)y.size(); i++){
            for (int j=0; j < (int)y[0].size(); j++){
                if (i==0 && j==0)
                    CPPUNIT_ASSERT(y[i][j] == 16);
                else
                    CPPUNIT_ASSERT(y[i][j] == 4);
            }
        } 
    }

    void test_multiplies_scalar_2 () {
        Matrix<int> x(2, 2, 1);
        x[0][0] = 4;
        x *= 4;

        for (int i=0; i < (int)x.size(); i++){
            for (int j=0; j < (int)x[0].size(); j++){
                if (i==0 && j==0)
                    CPPUNIT_ASSERT(x[i][j] == 16);
                else
                    CPPUNIT_ASSERT(x[i][j] == 4);
            }
        } 
    }

    void test_multiplies_3 () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        Matrix<int> res = x * y;

        for (int i=0; i < (int)res.size(); i++){
            for (int j=0; j < (int)res[0].size(); j++){
                CPPUNIT_ASSERT(res[i][j] == 2);
            }
        } 

    }

    void test_multiplies_4 () {
        Matrix<int> x(2, 3, 2);
        Matrix<int> y(3, 2, 1);
        Matrix<int> res = x * y;

        for (int i=0; i < (int)res.size(); i++){
            for (int j=0; j < (int)res[0].size(); j++){
                CPPUNIT_ASSERT(res[i][j] == 6);
            }
        } 

    }

    void test_multiplies_5 () {
        Matrix<int> x(2, 2, 1);
        Matrix<int> y(2, 2, 1);
        x *= y;

        for (int i=0; i < (int)x.size(); i++){
            for (int j=0; j < (int)x[0].size(); j++){
                CPPUNIT_ASSERT(x[i][j] == 2);
            }
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

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_index);

    CPPUNIT_TEST(test_equals_1);
    CPPUNIT_TEST(test_equals_2);
    CPPUNIT_TEST(test_equals_3);
    CPPUNIT_TEST(test_equals_4);

    CPPUNIT_TEST(test_less_than_1);
    CPPUNIT_TEST(test_less_than_2);
    CPPUNIT_TEST(test_less_than_3);
    CPPUNIT_TEST(test_less_than_4);

    CPPUNIT_TEST(test_greater_than_1);
    CPPUNIT_TEST(test_greater_than_2);
    CPPUNIT_TEST(test_greater_than_3);
    CPPUNIT_TEST(test_greater_than_4);

    CPPUNIT_TEST(test_plus_1);
    CPPUNIT_TEST(test_plus_2);
    CPPUNIT_TEST(test_plus_3);
    CPPUNIT_TEST(test_plus_4);
    CPPUNIT_TEST(test_plus_5);

    CPPUNIT_TEST(test_minus_1);
    CPPUNIT_TEST(test_minus_2);
    CPPUNIT_TEST(test_minus_3);
    CPPUNIT_TEST(test_minus_4);
    CPPUNIT_TEST(test_minus_5);

    CPPUNIT_TEST(test_multiplies_scalar_1);
    CPPUNIT_TEST(test_multiplies_scalar_2);
    CPPUNIT_TEST(test_multiplies_3);
    CPPUNIT_TEST(test_multiplies_4);
    CPPUNIT_TEST(test_multiplies_5);

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
