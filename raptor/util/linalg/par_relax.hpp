// Copyright (c) 2015-2017, RAPtor Developer Team
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#pragma once

namespace raptor {

    class ParCSRMatrix;
    class ParVector;

    void jacobi(ParCSRMatrix* A, ParVector& x, ParVector& b, ParVector& tmp,
                int num_sweeps = 1, double omega = 1.0, bool tap = false);
    void sor(ParCSRMatrix* A, ParVector& x, ParVector& b, ParVector& tmp,
             int num_sweeps = 1, double omega = 1.0, bool tap = false);
    void ssor(ParCSRMatrix* A, ParVector& x, ParVector& b, ParVector& tmp,
              int num_sweeps = 1, double omega = 1.0, bool tap = false);

}
