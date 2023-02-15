// Copyright (c) 2015-2017, RAPtor Developer Team
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#pragma once

#include "core/types.hpp"

namespace raptor {

    class CSRMatrix;

    // Stencils are symmetric, so A could be CSR or CSC
    CSRMatrix* stencil_grid(data_t* stencil, int* grid, int dim);

}
