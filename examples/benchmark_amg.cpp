// Copyright (c) 2015-2017, RAPtor Developer Team
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <ctime>

#include "clear_cache.hpp"

#include "raptor.hpp"

double wtime()
{
    return (double) clock() / (double) CLOCKS_PER_SEC;
}

int main(int argc, char* argv[])
{

    int n = 10;
    int iter = 0;
    int system = 0;
    double strong_threshold = 0.25;

    coarsen_t coarsen_type = HMIS;
    interp_t interp_type = Extended;

    Multilevel* ml = nullptr;
    CSRMatrix* A = nullptr;
    Vector x;
    Vector b;

    double t0 = 0.0;

    if (argc > 1)
    {
        system = atoi(argv[1]);
    }
    if (system < 2)
    {
        int dim = 3;
        double* stencil = nullptr;
        std::vector<int> grid;
        if (argc > 2)
        {
            n = atoi(argv[2]);
        }

        if (system == 0)
        {
            dim = 3;
            grid.resize(dim, n);
            stencil = laplace_stencil_27pt();
        }
        else if (system == 1)
        {
            coarsen_type = Falgout;
            interp_type = ModClassical;

            dim = 2;
            grid.resize(dim, n);
            double eps = 0.001;
            double theta = M_PI/4.0;
            if (argc > 3)
            {
                eps = atof(argv[3]);
                if (argc > 4)
                {
                    theta = atof(argv[4]);
                }
            }
            stencil = diffusion_stencil_2d(eps, theta);
        }
        A = stencil_grid(stencil, grid.data(), dim);
        delete[] stencil;
    }
    else if (system == 3)
    {
        const char* file = "../../examples/LFAT5.pm";
        A = readMatrix(file);
    }

    if (system != 2)
    {
        x = Vector(A->n_rows);
        b = Vector(A->n_rows);
        x.set_rand_values();
        A->mult(x, b);
        x.set_const_value(0.0);
    }


    // Ruge-Stuben AMG
    printf("Ruge Stuben Solver: \n");
    t0 = wtime();
    ml = new RugeStubenSolver(strong_threshold, coarsen_type, interp_type, Classical, SSOR);
    ml->setup(A);
    ml->max_iterations = 30;
    ml->solve_tol = 1.0e-05;
    ml->store_residuals = true;
    t0 = (wtime() - t0);
    printf("Total Setup Time: %e\n", t0);
    ml->print_hierarchy();
    //ml->print_setup_times();

    Vector rss_sol = Vector(x);
    t0 = wtime();
    iter = ml->solve(rss_sol, b);
    t0 = (wtime() - t0);
    printf("Total Solve Time: %e\n", t0);
    ml->print_residuals(iter);
    //ml->print_solve_times();
    delete ml;

    // Smoothed Aggregation AMG
    printf("\n\nSmoothed Aggregation Solver:\n");
    t0 = wtime();
    ml = new SmoothedAggregationSolver(strong_threshold, MIS, JacobiProlongation, 
            Symmetric, raptor::SSOR);
    ml->setup(A);
    ml->max_iterations = 30;
    ml->solve_tol = 1.0e-05;
    ml->store_residuals = true;
    t0 = (wtime() - t0);
    printf("Total Setup Time: %e\n", t0);
    ml->print_hierarchy();
    //ml->print_setup_times();

    Vector sas_sol = Vector(x);
    t0 = wtime();
    iter = ml->solve(sas_sol, b);
    t0 = (wtime() - t0);
    printf("Total Solve Time: %e\n", t0);
    ml->print_residuals(iter);
    //ml->print_solve_times();
    delete ml;

    delete A;

    return 0;
}

