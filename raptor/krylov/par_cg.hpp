#pragma once

#include <vector>

namespace raptor {

    class ParCSRMatrix;
    class ParMultilevel;
    class ParVector;

    void CG(ParCSRMatrix* A, ParVector& x, ParVector& b, std::vector<double>& res,
            double tol = 1e-05, int max_iter = -1, double* comm_t = NULL);
    void PCG(ParCSRMatrix* A, ParMultilevel* ml, ParVector& x, ParVector& b,
             std::vector<double>& res, double tol = 1e-05, int max_iter = -1,
             double* precond_t = NULL, double* comm_t = NULL);

}
