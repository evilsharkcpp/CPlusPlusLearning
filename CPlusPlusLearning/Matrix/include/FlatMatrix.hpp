#ifndef FLATMATRIX_HPP
#define FLATMATRIXHPP

#include "IMatrix.hpp"

#include <memory>
#include <vector>

namespace Matrixes{
    template<class T>
    class FlatMatrix final : IMatrix<T>{
        std::unique_ptr<std::vector<std::vector<T>>> m_matrix;
        public:
            FlatMatrix() = default;
            void add(const IMatrix<T>& right) override{
                std::pair<size_t, size_t> size { this->getSize() };
                if(size != right.getSize()){
                    throw std::exception("Different sizes");
                }
                for(size_t i{}; i < size.first; ++i){
                    for(size_t j{}; j < size.second; ++j){
                        this->operator()(i, j) += right(i, j);
                    }
                }
            }
            void sub(const IMatrix& right) override{
                std::pair<size_t, size_t> size { this->getSize() };
                if(size != right.getSize()){
                    throw std::exception("Different sizes");
                }
                for(size_t i{}; i < size.first; ++i){
                    for(size_t j{}; j < size.second; ++j){
                       this->operator()(i, j) -= right(i, j);
                    }
                }
            }
            void mult(const IMatrix& right) override{

            }
            void transpose() override{

            }
            void inverse() override{

            }
            std::pair<size_t, size_t> getSize() const override{
                return std::pair<size_t, size_t>((*m_matrix).size(), (*m_matrix).front().size());
            }
            T& operator()(size_t i, size_t j) override{
                return (*m_matrix)[i][j];
            };
            const T& operator()(size_t i, size_t j) const override{
                return (*m_matrix)[i][j];
            }
            ~FlatMatrix() = default;
    };
}
#endif