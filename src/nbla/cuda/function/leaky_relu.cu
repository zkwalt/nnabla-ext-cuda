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

// leaky_relu.cpp

#include <nbla/cuda/function/leaky_relu.hpp>
#include <nbla/cuda/function/utils/base_transform_unary.cuh>

namespace nbla {

NBLA_DEFINE_TRANSFORM_UNARY_CUDA_1(LeakyReLU, x >= (T)0 ? x : (T)a0 * x,
                                   x >= (T)0 ? dy : (T)a0 * dy, float);
// Template instantiation
template class LeakyReLUCuda<float>;
}