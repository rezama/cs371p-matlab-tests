// ------------------------
// projects/matLab/MatLab.h
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------

#ifndef MatLab_h
#define MatLab_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t

// ------
// concat
// ------

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/horzcat.html
 */
template <typename T>
T horzcat (const T& x, const T& y) 
{
    // <your code>
    T result(x);
    if (x.size() == y.size() && x.size() > 0)
    {
        int newsize = (x[0].size() + y[0].size());
        
        T result(x.size(), newsize, 0);
        result += x;
        for (unsigned int i = 0; i < y.size(); i++)
        {
            for (unsigned int j = 0; j < y[0].size(); j++)
            {
                result[i][j+x[0].size()] = y[i][j];
            }
        }
    }
    return result;
}

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/vertcat.html
 */
template <typename T>
T vertcat (const T& x, const T& y) 
{
    // <your code>
    T result(x);
    if (x.size() > 0 && x[0].size() == y[0].size())
    {
        int newsize = (x.size() + y.size());
        
        T result(newsize, x.size(), 0);
        result += x;
        for (unsigned int i = 0; i < y.size(); i++)
        {
            for (unsigned int j = 0; j < y[0].size(); j++)
            {
                result[i + x[0].size()][j] = y[i][j];
            }
        }
    }
    return result;
}

// ----
// diag
// ----

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/diag.html
 */
template <typename T>
T diag (const T& x) 
{
    // <your code>
    return x;
}

// ---
// dot
// ---

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/dot.html
 */
template <typename T>
T dot (const T& x, const T& y) 
{
    // <your code>
    return x;
}

// ---
// eye
// ---

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/eye.html
 */
template <typename T>
T eye (std::size_t r, std::size_t c) 
{
    // <your code>
    T x;
    return x;
}

// ----------------
// linsolve (bonus)
// ----------------

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/linsolve.html
 */
template <typename T>
T linsolve (const T& x, const T& y) 
{
    // <your code>
    return x;
}

// ----
// ones
// ----

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/ones.html
 */
template <typename T>
T ones (std::size_t r, std::size_t c) 
{
    // <your code>
    T x;
    return x;
}

// ----
// rand
// ----

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/rand.html
 */
template <typename T>
T rand (std::size_t r, std::size_t c) 
{
    // <your code>
    T x;
    return x;
}

// ---------
// transpose
// ---------

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/transpose.html
 */
template <typename T>
T transpose (const T& x) 
{
    // <your code>
    return x;
}

// ----
// tril
// ----

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/tril.html
 */
template <typename T>
T tril (const T& x) 
{
    // <your code>
    return x;
}

// ----
// triu
// ----

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/triu.html
 */
template <typename T>
T triu (const T& x) 
{
    // <your code>
    return x;
}

// -----
// zeros
// -----

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/zeros.html
 */
template <typename T>
T zeros (std::size_t r, std::size_t c) 
{
    // <your code>
    T x;
    return x;
}

#endif // MatLab_h
