#pragma once

#include <vector>

namespace raptor {

    class Vector;
    class CSRMatrix;

    void CG(CSRMatrix* A, Vector& x, Vector& b, std::vector<double>& res, double tol = 1e-05, int max_iter = -1);

}
