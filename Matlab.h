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
 * Combine two matrices by "sticking" one on the left of the first
 * http://www.mathworks.com/help/matlab/ref/horzcat.html
 * @param x Base Matrix
 * @param y Matrix to be concatonated on to A
 * @return Matrix with y horizontally concatonated to x
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
 * Combine two matrices by "sticking" one below the first
 * http://www.mathworks.com/help/matlab/ref/vertcat.html
 * @param x Base Matrix
 * @param y Matrix to be concatonated on to A
 * @return Matrix with y vertically concatonated to x
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
 * Returns an array of the diagonal elements in a matrix.
 * http://www.mathworks.com/help/matlab/ref/diag.html
 * @param x Matrix
 * @return Vector of the diagonal elements of x
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
 * http://www.mathworks.com/help/matlab/ref/dot.html
 * @param x Vector
 * @param y Vector
 * @return Dot product of both vectors as an element in a 1x1 matrix
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
 * http://www.mathworks.com/help/matlab/ref/eye.html
 * @param m row length
 * @param n column length
 * @return M x N matrix with 1s along the diagonal and 0s elsewhere
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
 * http://www.mathworks.com/help/matlab/ref/ones.html
 * @param m row length
 * @param n column length
 * @return M x N matrix filled with ones
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
 * http://www.mathworks.com/help/matlab/ref/rand.html
 * @param m row length
 * @param n column length
 * @return M x N matrix filled with random numbers spanning from 0 to 1
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
    {
        for (unsigned int j = 0; j < c; j++)
        {
            /*
            unsigned int p1 = i + j + 14;
            unsigned int p2 = i + j + 23;
            p1 = 36969 * (p1 & 65535) + (p1 >> 16);
            p2 = 18000 * (p2 & 65535) + (p2 >> 16);
            x[i][j] = ((p1 << 16) + p2);// / 4074996553.0;
            printf("%f\n", (double)x[i][j]);
            */
            x[i][j] = rand() % 1;
        }
    }

    return x;
}

// ---------
// transpose
// ---------

/**
 * http://www.mathworks.com/help/matlab/ref/transpose.html
 * @param x Matrix
 * @return the transpose of matrix x
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
 * http://www.mathworks.com/help/matlab/ref/tril.html
 * @param x Matrix
 * @return lower triangle of matrix x, with zeroes in the upper
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
 * http://www.mathworks.com/help/matlab/ref/triu.html
 * @param x Matrix
 * @return upper triangle of matrix x, with zeroes in the upper
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
 * http://www.mathworks.com/help/matlab/ref/zeros.html
 * @param m row length
 * @param n column length
 * @return M x N matrix filled with zeros
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
