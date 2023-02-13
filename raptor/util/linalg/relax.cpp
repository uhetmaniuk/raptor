// Copyright (c) 2015-2017, RAPtor Developer Team
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#include "core/types.hpp"
#include "core/matrix.hpp"
#include "core/vector.hpp"
#include "util/linalg/relax.hpp"

namespace raptor {

    void jacobi(CSRMatrix *A, Vector &x, Vector &b, Vector &tmp, int num_sweeps,
                double omega) {
        int row_start, row_end;
        double diag, row_sum;

        for (int iter = 0; iter < num_sweeps; iter++) {
            for (int i = 0; i < A->n_rows; i++) {
                tmp[i] = x[i];
            }

            for (int i = 0; i < A->n_rows; i++) {
                row_start = A->idx1[i];
                row_end = A->idx1[i + 1];
                if (row_start == row_end) continue;
                row_sum = 0;
                diag = 0;

                for (int j = row_start; j < row_end; j++) {
                    int col = A->idx2[j];
                    if (i == col)
                        diag = A->vals[j];
                    else
                        row_sum += A->vals[j] * tmp[col];
                }
                if (fabs(diag) > zero_tol)
                    x[i] = ((1.0 - omega) * tmp[i]) + (omega * ((b[i] - row_sum) / diag));
            }
        }
    }

    void sor(CSRMatrix *A, Vector &x, Vector &b, Vector &tmp, int num_sweeps,
             double omega) {
        int row_start, row_end;
        double diag_inv, omega_diag_inv, orig_x;
        double one_m_omega = 1.0 - omega;

        for (int iter = 0; iter < num_sweeps; iter++) {
            for (int i = 0; i < A->n_rows; i++) {
                orig_x = x[i];
                x[i] = b[i];
                row_start = A->idx1[i];
                row_end = A->idx1[i + 1];
                if (row_start == row_end) continue;

                diag_inv = 1.0 / A->vals[row_start];
                omega_diag_inv = omega * diag_inv;
                for (int j = row_start + 1; j < row_end; j++) {
                    x[i] -= A->vals[j] * x[A->idx2[j]];
                }
                x[i] = omega_diag_inv * x[i] + one_m_omega * orig_x * diag_inv;
            }
        }
    }

    void ssor(CSRMatrix *A, Vector &x, Vector &b, Vector &tmp, int num_sweeps,
              double omega) {
        int row_start, row_end;
        double diag_inv = 0.0, omega_diag_inv = 0.0, orig_x = 0.0;

        for (int iter = 0; iter < num_sweeps; iter++) {
            for (int i = 0; i < A->n_rows; i++) {
                orig_x = x[i];
                x[i] = b[i];
                row_start = A->idx1[i];
                row_end = A->idx1[i + 1];
                if (row_start == row_end) continue;

                diag_inv = omega / A->vals[row_start];
                omega_diag_inv = omega * diag_inv;
                for (int j = row_start + 1; j < row_end; j++) {
                    x[i] -= A->vals[j] * x[A->idx2[j]];
                }
                x[i] = omega_diag_inv * x[i] + (1 - omega) * orig_x;
            }

            for (int i = A->n_rows - 1; i >= 0; i--) {
                orig_x = x[i];
                x[i] = b[i];
                row_start = A->idx1[i];
                row_end = A->idx1[i + 1];
                if (row_start == row_end) continue;

                diag_inv = omega / A->vals[row_start];
                omega_diag_inv = omega * diag_inv;
                for (int j = row_start + 1; j < row_end; j++) {
                    x[i] -= A->vals[j] * x[A->idx2[j]];
                }
                x[i] = omega_diag_inv * x[i] + (1 - omega) * orig_x;
            }
        }
    }

}



