// Copyright (c) 2015-2017, RAPtor Developer Team
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#pragma once

#include <vector>

namespace raptor {

    class ParCSRMatrix;
    class ParVector;

    void row_scale(ParCSRMatrix* A, ParVector& rhs);
    void diagonally_scale(ParCSRMatrix* A, ParVector& rhs, std::vector<double>& row_scales);
    void diagonally_unscale(ParVector& sol, const std::vector<double>& row_scales);

}
