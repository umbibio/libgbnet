#include "GraphBase.h"


namespace gbn
{
    GraphBase::GraphBase(unsigned int seed)
    {
        this->rng = gsl_rng_alloc(gsl_rng_ranlxs2);
        gsl_rng_set(this->rng, seed);
    }

    GraphBase::~GraphBase()
    {
        for (auto node: this->random_nodes)
            delete node;
        for (auto node: this->norand_nodes)
            delete node;
        gsl_rng_free(this->rng);
        // std::cout << "Object at " << this << " destroyed, instance of  GraphBase\t" << std::endl;
    }

    void GraphBase::build_structure(
        network_t interaction_network, 
        evidence_dict_t evidence,
        prior_active_tf_set_t active_tf_set) {}

    void GraphBase::sample(unsigned int N)
    {
        for (unsigned int i = 0; i < N; i++) {
            for (auto node: this->random_nodes) node->sample(this->rng, true);
        }
    }

    void GraphBase::burn_stats()
    {
        for (auto node: this->random_nodes) node->burn_stats();
    }

    void GraphBase::print_stats()
    {
        printf("NodeID");
        for (auto node: this->random_nodes) {
            printf("\n%s", node->id.c_str());
            for (unsigned int i = 0;  i < node->n_stats; i++)
                printf("\t%6.2f", gsl_rstat_mean(node->stats[i]));
        }
        printf("\n\n");
    }
}
