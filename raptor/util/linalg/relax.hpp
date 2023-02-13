// Copyright (c) 2015-2017, RAPtor Developer Team, University of Illinois at Urbana-Champaign
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#pragma once

namespace raptor {

    class CSRMatrix;
    class Vector;

    void jacobi(CSRMatrix *A, Vector &b, Vector &x, Vector &tmp,
                int num_sweeps = 1, double omega = 1.0);

    void sor(CSRMatrix *A, Vector &b, Vector &x, Vector &tmp,
             int num_sweeps = 1, double omega = 1.0);

    void ssor(CSRMatrix *A, Vector &b, Vector &x, Vector &tmp,
              int num_sweeps = 1, double omega = 1.0);

}