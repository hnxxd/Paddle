// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
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

#pragma once

// See Note [ Why still include the fluid headers? ]
#ifndef PADDLE_WITH_CUSTOM_KERNEL
#include "paddle/fluid/framework/mixed_vector.h"
#endif

namespace phi {
#ifndef PADDLE_WITH_CUSTOM_KERNEL
using LoD = std::vector<paddle::framework::Vector<size_t>>;
#else
using LoD = std::vector<std::vector<size_t>>;
#endif

void AppendLoD(LoD* lod, const LoD& lod_length);

/*
 * Convert between length-based LoD and offset-based LoD.
 * The implementation of LoDTensor class use offset-based LoD.
 * However, we want to expose the more user-friendly length-based
 * LoD to the Python side instead.
 *
 * Example:
 * If offset_lod = [[0, 2, 3],[0, 3, 5, 9]]
 * then length_lod = [[2, 1], [3, 2, 4]]
 */
LoD ConvertToLengthBasedLoD(const LoD& offset_lod);

}  // namespace  pten
