// Copyright (c) 2015, Raptor Developer Team, University of Illinois at Urbana-Champaign
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#pragma once

#include <vector>

namespace raptor {

    class CSRMatrix;

    void mis2(CSRMatrix* A, std::vector<int>& states,
              const double* rand_vals = nullptr);

}