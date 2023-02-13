// Copyright (c) 2015-2017, RAPtor Developer Team
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
//
#pragma once

#include <vector>

namespace raptor {

    class ParCSRMatrix;

ParCSRMatrix* repartition_matrix(ParCSRMatrix* A, int* partition, std::vector<int>& new_local_rows);
void make_contiguous(ParCSRMatrix* A);
}

