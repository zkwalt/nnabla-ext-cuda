// Copyright (c) 2017 Sony Corporation. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef __NBLA_CUBLAS_HPP__
#define __NBLA_CUBLAS_HPP__
namespace nbla {

template <typename T>
void cublas_gemm(cublasHandle_t handle, cublasOperation_t op_x,
                 cublasOperation_t op_y, int m, int n, int k, const T *alpha,
                 const T *x, int lda, const T *y, int ldb, const T *beta, T *z,
                 int ldc);

template <typename T>
void cublas_gemv(cublasHandle_t handle, cublasOperation_t trans, int m, int n,
                 const T *alpha, const T *A, int lda, const T *x, int incx,
                 const T *beta, T *y, int incy);

template <typename T>
void cublas_dot(cublasHandle_t handle, int n, const T *x, int incx, const T *y,
                int incy, T *out);
}
#endif
