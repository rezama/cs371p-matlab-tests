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

#include <cstdlib>
#include <time.h>
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
        return result;
    }
    return x;
}

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/vertcat.html
 */
template <typename T>
T vertcat (const T& x, const T& y) 
{
    // <your code>
    if (x.size() > 0 && x[0].size() == y[0].size())
    {
        int newsize = (x.size() + y.size());
        T result(newsize, x[0].size(), 0);
        result += x;
        for (unsigned int i = 0; i < y.size(); i++)
        {
            for (unsigned int j = 0; j < y[0].size(); j++)
            {
                result[i + x.size()][j] = y[i][j];
            }
        }
        return result;
    }
    return x;
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
    int r = x.size();
    int c = 0;
    if (r > 0)
        c = x[0].size();
    int min = r;
    if (c < min)
        min = c;

    T result(min, 1);
    
    for (int i = 0; i < min; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j)
                result[i][0] = x[i][j];
        }
    }


    return result;
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
    T result(1, 1);
    if (x.size() < 1)
        return x;
    if (x.size() > 1 && y.size() > 0)
    {
        if (x[0].size() == 1 && y[0].size() == 1)
        {
            for (unsigned int i = 0; i < x.size(); i++)
                result[0][0] += x[i][0] * y[i][0];
        }

        else if (y[0].size() > 1)
        {
            for (unsigned int i = 0; i < x.size(); i++)
                result[0][0] += x[i][0] * y[0][i];
        }
    }

    else if (x[0].size() > 1 && y.size() == 1)
    {
        if (x.size() == 1 && y[0].size() == 1)
        {
            for (unsigned int i = 0; i < x[0].size(); i++)
                result[0][0] += x[0][i] * y[i][0];
        }

        else if (y[0].size() > 1)
            for (unsigned int i = 0; i < x[0].size(); i++)
                result[0][0] += x[0][i] * y[0][i];
    }

    return result;
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
    T x(r, c, 0);
    for (unsigned int i = 0; i < r; i++)
    {
        for (unsigned int j = 0; j < c; j++)
        {
            if (i == j)
                x[i][j] = 1;
        }
    }
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
    T dummy;
    if (r == 0 || c == 0)
        return dummy;
    T x(r, c, 1);
   
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
    T dummy;
    if (r == 0 || c == 0)
        return dummy;

    srand ( time(NULL) );
    
    T x(r, c, 0);
    for (unsigned int i = 0; i < r; i++)
        for (unsigned int j = 0; j < c; j++)
            x[i][j] = rand() % 1;
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
    T dummy;
    if (x.size() == 0)
        return dummy;

    T result(x[0].size(), x.size());
    for (unsigned int i = 0; i < x.size(); i++)
        for(unsigned int j = 0; j < x[0].size(); j++)
            result[j][i] = x[i][j];
    return result;
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
    T dummy;
    if (x.size() == 0)
        return dummy;

    T result(x.size(), x[0].size(), 0);
    
    for (unsigned int i = 0; i < x.size(); i++)
    {
        for (unsigned int j = 0; j < x[0].size(); j++)
        {
            if (j <= i)
                result[i][j] = x[i][j];
        }
    }

    return result;
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
    T dummy;
    if (x.size() == 0)
        return dummy;

    T result(x.size(), x[0].size(), 0);
    
    for (unsigned int i = 0; i < x.size(); i++)
    {
        for (unsigned int j = 0; j < x[0].size(); j++)
        {
            if (j >= i)
                result[i][j] = x[i][j];
        }
    }

    return result;
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
    T dummy;
    if (r == 0 || c == 0)
        return dummy;
    T x(r, c, 0);
   
    return x;
}

#endif // MatLab_h
