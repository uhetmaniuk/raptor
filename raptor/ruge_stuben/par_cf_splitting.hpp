// Copyright (c) 2015-2017, RAPtor Developer Team
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#pragma once

#include <vector>

namespace raptor {

    class ParCSRMatrix;

    void set_initial_states(ParCSRMatrix *S, std::vector<int> &states);

    void reset_boundaries(ParCSRMatrix *S, std::vector<int> &states);

    void cljp_main_loop(ParCSRMatrix *S, std::vector<int> &states,
                        std::vector<int> &off_proc_states, bool tap_comm = false,
                        const double *rand_vals = nullptr);

    void pmis_main_loop(ParCSRMatrix *S, std::vector<int> &states,
                        std::vector<int> &off_proc_states, bool tap_comm = false,
                        const double *rand_vals = nullptr);

    void split_rs(ParCSRMatrix *S, std::vector<int> &states,
                  std::vector<int> &off_proc_states, bool tap_cf = false);

    void split_cljp(ParCSRMatrix *S, std::vector<int> &states,
                    std::vector<int> &off_proc_states, bool tap_cf = false,
                    const double *rand_vals = nullptr);

    void split_falgout(ParCSRMatrix *S, std::vector<int> &states,
                       std::vector<int> &off_proc_states, bool tap_cf = false,
                       const double *rand_vals = nullptr);

    void split_pmis(ParCSRMatrix *S, std::vector<int> &states,
                    std::vector<int> &off_proc_states, bool tap_cf = false,
                    const double *rand_vals = nullptr);

    void split_hmis(ParCSRMatrix *S, std::vector<int> &states,
                    std::vector<int> &off_proc_states, bool tap_cf = false,
                    const double *rand_vals = nullptr);

}