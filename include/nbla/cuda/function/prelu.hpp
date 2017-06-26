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

// -*- coding:utf-8 -*-
/*
 * Copyright (C) 2016 Sony Corporation
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Sony Corporation;
 * the contents of this file is not to be disclosed to third parties, copied
 * or duplicated in any form, in whole or in part, without the prior written
 * permission of Sony Corporation.
 */

/** PReLU
 */
#ifndef __NBLA_CUDA_FUNCTION_PRELU_HPP__
#define __NBLA_CUDA_FUNCTION_PRELU_HPP__

#include <nbla/cuda/cuda.hpp>
#include <nbla/function/prelu.hpp>
namespace nbla {
/** @copydoc PReLU
*/

template <typename T> class PReLUCuda : public PReLU<T> {
public:
  explicit PReLUCuda(const Context &ctx, int base_axis)
      : PReLU<T>(ctx, base_axis), device_(std::stoi(ctx.device_id)) {}
  virtual ~PReLUCuda() {}
  virtual string name() { return "PReLUCuda"; }
  virtual vector<string> allowed_array_classes() {
    return SingletonManager::get<Cuda>()->array_classes();
  }

protected:
  int device_;
  virtual void setup_impl(const Variables &inputs, const Variables &outputs);
  virtual void forward_impl(const Variables &inputs, const Variables &outputs);
  virtual void backward_impl(const Variables &inputs, const Variables &outputs,
                             const vector<bool> &propagate_down,
                             const vector<bool> &accum);
};
}

#endif
