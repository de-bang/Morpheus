/**
 * SPDX-FileCopyrightText: Copyright (c) 2021-2022, NVIDIA CORPORATION & AFFILIATES. All rights reserved.
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

#include "morpheus/objects/python_data_table.hpp"

#include "morpheus/objects/table_info.hpp"
#include "morpheus/utilities/cudf_util.hpp"

#include <cudf/types.hpp>
#include <pybind11/cast.h>  // for object::cast
#include <pybind11/gil.h>
#include <pybind11/pybind11.h>

#include <utility>

namespace morpheus {
/****** Component public implementations *******************/
/****** PyDataTable****************************************/
PyDataTable::PyDataTable(pybind11::object &&py_table) : m_py_table(std::move(py_table)) {}

PyDataTable::~PyDataTable()
{
    if (m_py_table)
    {
        pybind11::gil_scoped_acquire gil;

        // Clear out the python object
        m_py_table = pybind11::object();
    }
}

cudf::size_type PyDataTable::count() const
{
    pybind11::gil_scoped_acquire gil;
    return m_py_table.attr("_num_rows").cast<cudf::size_type>();
}

TableInfo PyDataTable::get_info() const
{
    pybind11::gil_scoped_acquire gil;

    // auto info = proxy_table_info_from_table((PyTable *) m_py_table.ptr(), this->shared_from_this());
    auto info = proxy_table_info_from_table(m_py_table, this->shared_from_this());

    return info;
}

const pybind11::object &PyDataTable::get_py_object() const
{
    return m_py_table;
}
}  // namespace morpheus
