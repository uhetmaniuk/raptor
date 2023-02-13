// Copyright (c) 2015, Raptor Developer Team, University of Illinois at Urbana-Champaign
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#pragma once

#include <vector>

namespace raptor {

    class CSRMatrix;

    int aggregate(CSRMatrix* A, CSRMatrix* S, std::vector<int>& states,
                  std::vector<int>& aggregates, const double* rand_vals = nullptr);

}


