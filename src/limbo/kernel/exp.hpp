#ifndef LIMBO_KERNEL_EXP_HPP
#define LIMBO_KERNEL_EXP_HPP

#include <Eigen/Core>

#include <limbo/tools/macros.hpp>

namespace limbo {
    namespace defaults {
        struct kernel_exp {
            /// @ingroup kernel_defaults
            BO_PARAM(double, sigma, 1);
        };
    }
    namespace kernel {
        /// @ingroup kernel
        /// Exponential kernel (TODO: formula)
        template <typename Params>
        struct Exp {
            Exp(size_t dim = 1) {}
            double operator()(const Eigen::VectorXd& v1, const Eigen::VectorXd& v2) const
            {
                double _sigma = Params::kernel_exp::sigma();
                return (std::exp(-(1 / (2 * std::pow(_sigma, 2))) * std::pow((v1 - v2).norm(), 2)));
            }
        };
    }
}

#endif
