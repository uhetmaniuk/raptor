// Copyright (c) 2015, Raptor Developer Team, University of Illinois at Urbana-Champaign
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#pragma once

#include <vector>

namespace raptor {

    class ParCSRMatrix;

// TODO -- currently only accepts constant vector
ParCSRMatrix* fit_candidates(ParCSRMatrix* A, int n_aggs,
        const std::vector<int>& aggregates, 
        const std::vector<double>& B, std::vector<double>& R,
        int num_candidates, bool tag_comm = false, double tol = 1e-10);

}

