// Copyright (c) 2015-2017, RAPtor Developer Team
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#pragma once

#include <vector>

namespace raptor {

    class CSRMatrix;

    CSRMatrix *direct_interpolation(CSRMatrix * A,
                                    CSRMatrix * S,
    const std::vector<int> &states
    );

    CSRMatrix *mod_classical_interpolation(CSRMatrix * A,
                                           CSRMatrix * S,
    const std::vector<int> &states,
    int num_variables = 1,
    const int *variables = nullptr
    );

    CSRMatrix *extended_interpolation(CSRMatrix * A,
                                      CSRMatrix * S,
    const std::vector<int> &states,
    int num_variables = 1,
    int *variables = nullptr
    );

}

