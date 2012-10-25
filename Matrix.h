// ------------------------
// projects/matlab/Matrix.h
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------

#ifndef Matrix_h
#define Matrix_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // ptrdiff_t, size_t
#include <vector>  // vector

// ------
// Matrix
// ------

template <typename T>
class Matrix {
    public:
        // --------
        // typedefs
        // --------

        typedef typename std::vector< std::vector<T> >    container_type;
        typedef typename container_type::value_type       value_type;

        typedef typename container_type::size_type        size_type;
        typedef typename container_type::difference_type  difference_type;

        typedef typename container_type::pointer          pointer;
        typedef typename container_type::const_pointer    const_pointer;

        typedef typename container_type::reference        reference;
        typedef typename container_type::const_reference  const_reference;

        typedef typename container_type::iterator         iterator;
        typedef typename container_type::const_iterator   const_iterator;

    public:
        // -----------
        // operator ==
        // -----------

        /**
          * Returns a matrix with a 0 or 1 for each element if it is not equal or is repectively
          * @param x matrix lhs
          * @param y matrix rhs
          * @return Matrix with 1 or 0 for whether each element was equal or not
         */
        friend Matrix<bool> operator == (const Matrix& lhs, const Matrix& rhs) 
        {
            // <your code>
            Matrix<bool> dummy;
            if (lhs.size() == 0 && rhs.size() == 0)
                return dummy;
            Matrix<bool> result(lhs.size(), lhs[0].size(), true);
            for (size_type i = 0; i < lhs.size(); i++)
                for (size_type j = 0; j < lhs[0].size(); j++)
                {
                    if (lhs[i][j] != rhs[i][j])
                        result[i][j] = false;
                }

            return result;
        }

        // -----------
        // operator !=
        // -----------

        /**
          * Returns a matrix with a 1 or 0 for each element if it is not equal or is repectively
          * @param x matrix lhs
          * @param y matrix rhs
          * @return Matrix with 0 or 1 for whether each element was equal or not
         */
        friend Matrix<bool> operator != (const Matrix& lhs, const Matrix& rhs) 
        {

            // <your code>
            Matrix<bool> dummy;
            if (lhs.size() == 0 && rhs.size() == 0)
                return dummy;
            Matrix<bool> result(lhs.size(), lhs[0].size(), true);
            for (size_type i = 0; i < lhs.size(); i++)
                for (size_type j = 0; j < lhs[0].size(); j++)
                {
                    if (lhs[i][j] == rhs[i][j])
                        result[i][j] = false;
                }

            return result;
        }

        // ----------
        // operator <
        // ----------

        /**
          * Returns a matrix with a 1 if less than, 0 otherwise, for each spot in the matrix
          * @param x matrix lhs
          * @param y matrix rhs
          * @return Matrix with 1 or 0 for whether each element was less than or not
         */
        friend Matrix<bool> operator < (const Matrix& lhs, const Matrix& rhs) 
        {
            // <your code>
            Matrix<bool> dummy;
            if (lhs.size() == 0 && rhs.size() == 0)
                return dummy;
            Matrix<bool> result(lhs.size(), lhs[0].size(), false);
            for (size_type i = 0; i < lhs.size(); i++)
                for (size_type j = 0; j < lhs[0].size(); j++)
                {
                    if (lhs[i][j] < rhs[i][j])
                        result[i][j] = true;
                }

            return result;
        }

        // -----------
        // operator <=
        // -----------

        /**
          * Returns a matrix with a 1 if less or equal to, 0 otherwise, for each spot in the matrix
          * @param x matrix lhs
          * @param y matrix rhs
          * @return Matrix with 1 or 0 for whether each element was less or equal to or not
         */
        friend Matrix<bool> operator <= (const Matrix& lhs, const Matrix& rhs) 
        {
            // <your code>
            Matrix<bool> dummy;
            if (lhs.size() == 0 && rhs.size() == 0)
                return dummy;
            Matrix<bool> result(lhs.size(), lhs[0].size(), false);
            for (size_type i = 0; i < lhs.size(); i++)
                for (size_type j = 0; j < lhs[0].size(); j++)
                {
                    if (lhs[i][j] <= rhs[i][j])
                        result[i][j] = true;
                }

            return result;
        }

        // ----------
        // operator >
        // ----------

        /**
          * Returns a matrix with a 1 if greater than, 0 otherwise, for each spot in the matrix
          * @param x matrix lhs
          * @param y matrix rhs
          * @return Matrix with 1 or 0 for whether each element was greater than or not
         */
        friend Matrix<bool> operator > (const Matrix& lhs, const Matrix& rhs) 
        {
            // <your code>
            Matrix<bool> dummy;
            if (lhs.size() == 0 && rhs.size() == 0)
                return dummy;
            Matrix<bool> result(lhs.size(), lhs[0].size(), false);
            for (size_type i = 0; i < lhs.size(); i++)
                for (size_type j = 0; j < lhs[0].size(); j++)
                {
                    if (lhs[i][j] > rhs[i][j])
                        result[i][j] = true;
                }

            return result;
        }

        // -----------
        // operator >=
        // -----------

        /**
          * Returns a matrix with a 1 if greater than or equal to, 0 otherwise, for each spot in the matrix
          * @param x matrix lhs
          * @param y matrix rhs
          * @return Matrix with 1 or 0 for whether each element was greater or equal to or not
         */
        friend Matrix<bool> operator >= (const Matrix& lhs, const Matrix& rhs) 
        {
            // <your code>
            Matrix<bool> dummy;
            if (lhs.size() == 0 && rhs.size() == 0)
                return dummy;
            Matrix<bool> result(lhs.size(), lhs[0].size(), false);
            for (size_type i = 0; i < lhs.size(); i++)
                for (size_type j = 0; j < lhs[0].size(); j++)
                {
                    if (lhs[i][j] >= rhs[i][j])
                        result[i][j] = true;
                }

            return result;
        }

        // ----------
        // operator +
        // ----------

        /**
          * Adds a scalar to every element in the matrix
          * @param x matrix lhs
          * @param y T rhs
          * @return Matrix with each element added to rhs
         */
        friend Matrix operator + (Matrix lhs, const T& rhs) 
        {
            return lhs += rhs;
        }

        /**
          * Adds each element in matrix rhs to every corresponding element in the matrix lhs
          * @param x matrix lhs
          * @param y matrix rhs
          * @return Matrix with each element of rhs added to the corresponding element in lhs
         */
        friend Matrix operator + (Matrix lhs, const Matrix& rhs) {
            return lhs += rhs;}

        // ----------
        // operator -
        // ----------

        /**
          * Subtracts a scalar from every element in the matrix
          * @param x matrix lhs
          * @param y T rhs
          * @return Matrix with rhs subtracted from each element
         */
        friend Matrix operator - (Matrix lhs, const T& rhs) {
            return lhs -= rhs;}

        /**
          * Subtracts each element in matrix rhs from every corresponding element in the matrix lhs
          * @param x matrix lhs
          * @param y matrix rhs
          * @return Matrix with each element of rhs subtracted from the corresponding element in lhs
         */
        friend Matrix operator - (Matrix lhs, const Matrix& rhs) {
            return lhs -= rhs;}

        // ----------
        // operator *
        // ----------

        /**
          * Multiplies each element in a matrix with a scalar
          * @param x matrix lhs
          * @param y T rhs
          * @return Matrix with rhs multiplied with each element
         */
        friend Matrix operator * (Matrix lhs, const T& rhs) {
            return lhs *= rhs;}

        /**
          * Multiplies each element in matrix rhs with every corresponding element in the matrix lhs
          * @param x matrix lhs
          * @param y matrix rhs
          * @return Matrix with each element of rhs multiplied with the corresponding element in lhs
         */
        friend Matrix operator * (Matrix lhs, const Matrix& rhs) {
            return lhs *= rhs;}

    private:
        // ----
        // data
        // ----

        std::vector< std::vector<T> > _m;

        // -----
        // valid
        // -----

        /**
         * <your documentation>
         */
        bool valid () const 
        {
            // <your code>
            return true;
        }

    public:
        // ------------
        // constructors
        // ------------

        /**
         * Constructor for Matrix takes m, n, and v to make an MxN matrix filled with v.
          * @param r row size
          * @param c column size
          * @param v element
         */
        Matrix (size_type r = 0, size_type c = 0, const T& v = T())
        {
            // <your code>
            _m.resize(r);

            for (size_type i = 0; i < r; i++)
            {
                _m[i].resize(c);
                for (size_type j = 0; j < c; j++)
                {
                    _m[i][j] = v;
                }

            }
            assert(valid());
        }

        // Default copy, destructor, and copy assignment
        //Matrix  (const Matrix<T>&);
        //~Matrix ();
        //Matrix& operator = (const Matrix&);

        // -----------
        // operator []
        // -----------

        /**
         * Gets the element at i
         * @param i index
         * @return element at i
         */
        reference operator [] (size_type i) 
        {
            // <your code>
            return _m[i];



            // dummy is just to be able to compile the skeleton, remove it
            //static value_type dummy(1);
            //return dummy;
        }

        /**
         * Gets the element at i
         * @param i index
         * @return element at i
         */
        const_reference operator [] (size_type i) const 
        {
            return (*const_cast<Matrix*>(this))[i];
        }

        // -----------
        // operator +=
        // -----------

        /**
         * Takes scalar rhs and adds it to the current matrix
         * @param rhs scalar
         * @return Current matrix with rhs added to each element
         */
        Matrix& operator += (const T& rhs) 
        {
            // <your code>
            if (size() == 0)
                return *this;

            for (size_type i = 0; i < _m.size(); i++)
                for (size_type j = 0; j < _m[0].size(); j++)
                {
                        _m[i][j] += rhs;
                }
            return *this;
        }

        /**
         * Takes Matrix rhs and adds it to the current matrix
         * @param rhs matrix
         * @return Current matrix with each corresponding rhs element added to each element
         */
        Matrix& operator += (const Matrix& rhs) 
        {
            // <your code>
            if (size() == 0 && rhs.size() == 0)
                return *this;

            for (size_type i = 0; i < rhs.size(); i++)
                for (size_type j = 0; j < rhs[0].size(); j++)
                {
                        _m[i][j] += rhs[i][j];
                }
            return *this;
        }

        // -----------
        // operator -=
        // -----------

        /**
         * Takes scalar rhs and subtracts it from the current matrix
         * @param rhs scalar
         * @return Current matrix with rhs subtracted from each element
         */
        Matrix& operator -= (const T& rhs) 
        {
            // <your code>
            if (size() == 0)
                return *this;

            for (size_type i = 0; i < _m.size(); i++)
                for (size_type j = 0; j < _m[0].size(); j++)
                {
                        _m[i][j] -= rhs;
                }
            return *this;
        }

        /**
         * Takes Matrix rhs and subtracts it from the current matrix
         * @param rhs matrix
         * @return Current matrix with each corresponding rhs element subtracted from each element
         */
        Matrix& operator -= (const Matrix& rhs) 
        {
            // <your code>
            if (size() == 0 && rhs.size() == 0)
                return *this;

            for (size_type i = 0; i < rhs.size(); i++)
                for (size_type j = 0; j < rhs[0].size(); j++)
                {
                        _m[i][j] -= rhs[i][j];
                }
            return *this;
        }

        // -----------
        // operator *=
        // -----------

        /**
         * Takes scalar rhs and multiplies it with the current matrix
         * @param rhs scalar
         * @return Current matrix with rhs multiplied with each element
         */
        Matrix& operator *= (const T& rhs) 
        {
            // <your code>
            if (size() == 0)
                return *this;

            for (size_type i = 0; i < _m.size(); i++)
                for (size_type j = 0; j < _m[0].size(); j++)
                {
                        _m[i][j] *= rhs;
                }
            return *this;
        }

        /**
         * Takes Matrix rhs and multiplies it with the current matrix
         * @param rhs matrix
         * @return Current matrix with each corresponding rhs element multiplied with each element
         */
        Matrix& operator *= (const Matrix& rhs) 
        {
            // <your code>
            if (size() == 0 && rhs.size() == 0)
                return *this;

            Matrix<T> result(_m.size(), rhs[0].size());
            for (size_type i = 0; i < _m.size(); i++)
            {
                //_m[i].resize(rhs[0].size());
                for (size_type j = 0; j < rhs[0].size(); j++)
                {
                    T temp;
                    temp = 0;
                    for(size_type k = 0; k < _m[0].size(); k++)
                    {
                        temp += _m[i][k]*rhs[k][j];
                    }
                    result[i][j] = temp;
                    
                }
            }

            *this = result;
            return *this;
        }

        // --
        // eq
        // --

        /**
         * Checks to see if each element of the current matrix equals each corresponding element of mat
         * @param mat Matrix
         * @return Boolean for whether or not the elements of the matrices are the same
         */
        bool eq (const Matrix& mat) const 
        {
            // <your code>
            if(size() == 0 && mat.size() == 0)
                return true;
            else if(size() != mat.size() || _m[0].size() != mat[0].size())
                return false;
            else
            {
                for (size_type i = 0; i < mat.size(); i++)
                    for(size_type j = 0; j < mat[0].size(); j++)
                        if (_m[i][j] != mat[i][j])
                            return false;
            }
            
            return true;
        }

        // -----
        // begin
        // -----

        /**
          * Returns an iterator at the beginning of the matrix.
          * @return Iterator pointing to the first element of the matrix
         */
        iterator begin () {
            return _m.begin();}

        /**
          * Returns a constant iterator at the beginning of the matrix.
          * @return Iterator pointing to the first element of the matrix
         */
        const_iterator begin () const {
            return const_cast<Matrix*>(this)->begin();}

        // ---
        // end
        // ---

        /**
          * Returns an iterator at the end of the matrix.
          * @return Iterator pointing to the last element of the matrix
         */
        iterator end () {
            return _m.end();}

        /**
          * Returns a constant iterator at the end of the matrix.
          * @return Iterator pointing to the last element of the matrix
         */
        const_iterator end () const {
            return const_cast<Matrix*>(this)->end();}

        // ----
        // size
        // ----

        /**
         * Returns the number of rows in the matrix
         * @return size_type of the number of rows in the matrix
         */
        size_type size () const 
        {
            return _m.size();
        }

};

#endif // Matrix_h
