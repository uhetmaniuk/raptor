#pragma once

#include <vector>

namespace raptor {

    class CSRMatrix;
    class Vector;

    void BiCGStab(CSRMatrix *A, Vector &x, Vector &b, std::vector<double> &res, double tol = 1e-05, int max_iter = -1);

}

