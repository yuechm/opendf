#pragma once 
#include "df_base.hpp"

namespace open_df { 

template <typename LatticeT> 
class df_hubbard : public df_base<LatticeT>
{
public:
    typedef df_base<LatticeT> base;
    using typename base::lattice_t;
    using typename base::vertex_type;
    using typename base::fvertex_type;
    using typename base::gw_type;
    using typename base::gk_type;
    using typename base::disp_type;
    using base::NDim;

    // constructor
    df_hubbard(gw_type gw, gw_type Delta, lattice_t lattice, kmesh kgrid, vertex_type d_vertex, vertex_type m_vertex):
        base(gw,Delta,lattice,kgrid),
        density_vertex_(d_vertex),
        magnetic_vertex_(m_vertex)
        {}
    // run the df calculation and return the updated hybridization function
    virtual gw_type operator()(alps::params p);
    // get spin susceptibility at fixed frequency
    disp_type spin_susc(bmatsubara_grid::point W);

protected:
    using base::fgrid_;
    using base::kgrid_;
    using base::gd_;
    using base::gd0_;
    using base::sigma_d_;
    using base::disp_;
    using base::gw_;
    using base::delta_;
    using base::glat_;
    vertex_type density_vertex_;
    vertex_type magnetic_vertex_;
};

} // end of namespace open_df