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
         * <your documentation>
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
         * <your documentation>
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
         * <your documentation>
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
         * <your documentation>
         */
        friend Matrix<bool> operator <= (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            return true;}

        // ----------
        // operator >
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix<bool> operator > (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            return true;}

        // -----------
        // operator >=
        // -----------

        /**
         * <your documentation>
         */
        friend Matrix<bool> operator >= (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            return true;}

        // ----------
        // operator +
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix operator + (Matrix lhs, const T& rhs) 
        {
            return lhs += rhs;
        }

        /**
         * <your documentation>
         */
        friend Matrix operator + (Matrix lhs, const Matrix& rhs) {
            return lhs += rhs;}

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix operator - (Matrix lhs, const T& rhs) {
            return lhs -= rhs;}

        /**
         * <your documentation>
         */
        friend Matrix operator - (Matrix lhs, const Matrix& rhs) {
            return lhs -= rhs;}

        // ----------
        // operator *
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix operator * (Matrix lhs, const T& rhs) {
            return lhs *= rhs;}

        /**
         * <your documentation>
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
        bool valid () const {
            // <your code>
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
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
         * <your documentation>
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
         * <your documentation>
         */
        const_reference operator [] (size_type i) const 
        {
            return (*const_cast<Matrix*>(this))[i];
        }

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
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
         * <your documentation>
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
         * <your documentation>
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
         * <your documentation>
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
         * <your documentation>
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
         * <your documentation>
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
         * <your documentation>
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
         * <your documentation>
         */
        iterator begin () {
            return _m.begin();}

        /**
         * <your documentation>
         */
        const_iterator begin () const {
            return const_cast<Matrix*>(this)->begin();}

        // ---
        // end
        // ---

        /**
         * <your documentation>
         */
        iterator end () {
            return _m.end();}

        /**
         * <your documentation>
         */
        const_iterator end () const {
            return const_cast<Matrix*>(this)->end();}

        // ----
        // size
        // ----

        /**
         * <your documentation>
         */
        size_type size () const 
        {
            return _m.size();
        }

};

#endif // Matrix_h
