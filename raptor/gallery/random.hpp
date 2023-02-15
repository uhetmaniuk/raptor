// Copyright (c) 2015-2017, RAPtor Developer Team
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause

#pragma once

namespace raptor {

    class CSRMatrix;

    CSRMatrix* random(int rows, int cols, int nnz_per_row);

}
