#ifndef LIMBO_INIT_RANDOM_SAMPLING_HPP
#define LIMBO_INIT_RANDOM_SAMPLING_HPP

#include <Eigen/Core>

#include <limbo/tools/macros.hpp>
#include <limbo/tools/rand.hpp>

namespace limbo {
    namespace defaults {
        struct init_randomsampling {
            BO_PARAM(int, samples, 10);
        };
    }
    namespace init {
        template <typename Params>
        struct RandomSampling {
            template <typename StateFunction, typename AggregatorFunction, typename Opt>
            void operator()(const StateFunction& seval, const AggregatorFunction&, Opt& opt) const
            {
                for (int i = 0; i < Params::init_randomsampling::samples(); i++) {
                    Eigen::VectorXd new_sample(StateFunction::dim_in);
                    for (int i = 0; i < StateFunction::dim_in; i++)
                        new_sample[i] = tools::rand<double>(0, 1);                 
                    opt.add_new_sample(new_sample, seval(new_sample));
                }
            }
        };
    }
}

#endif
