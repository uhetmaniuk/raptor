// Copyright (c) 2015, Raptor Developer Team, University of Illinois at Urbana-Champaign
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#pragma once

#include <vector>

namespace raptor {

    class ParCSRMatrix;

    int aggregate(ParCSRMatrix *A, ParCSRMatrix *S, std::vector<int> &states,
                  std::vector<int> &off_proc_states, std::vector<int> &aggregates,
                  bool tap_comm = false, const double *rand_vals = nullptr);

}



