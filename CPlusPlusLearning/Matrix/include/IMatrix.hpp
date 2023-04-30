#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace Matrixes{
    template<class T>
    class IMatrix{
        public:
            virtual void add(const IMatrix& right) = 0;
            virtual void sub(const IMatrix& right) = 0;
            virtual void mult(const IMatrix& right) = 0;
            virtual void transpose() = 0;
            virtual void inverse() = 0;
            virtual std::pair<size_t, size_t> getSize() const = 0;
            virtual T& operator()(size_t i, size_t j) = 0;
            virtual const T& operator()(size_t i, size_t j) const = 0;
            virtual ~IMatrix() = default; 
    };
}
#endif