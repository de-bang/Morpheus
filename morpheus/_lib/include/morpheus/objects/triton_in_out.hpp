/*
 * SPDX-FileCopyrightText: Copyright (c) 2022 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "morpheus/utilities/type_util.hpp"

#include <string>
#include <vector>

namespace morpheus {
/****** Component public implementations *******************/
/****** TritonInOut****************************************/
/**
 * TODO(Documentation)
 */
struct TritonInOut
{
    std::string name;
    size_t bytes;
    DType datatype;
    std::vector<int> shape;
    std::string mapped_name;
    size_t offset;
};
}  // namespace morpheus
