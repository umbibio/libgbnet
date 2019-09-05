#ifndef GBNET_GRAPHBASE
#define GBNET_GRAPHBASE


#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stdio.h>


#include <gsl/gsl_rng.h>


#include "RVNode.h"
#include "XNode.h"
#include "HNodeORNOR.h"
#include "YDataNode.h"
#include "SNode.h"
#include "NodeDictionary.h"


namespace gbn
{
    // used accross module. might want to find a better place for these typedefs
    typedef std::vector<RVNode *> node_vector_t;
    typedef std::pair<std::string, int> trg_de_pair_t;
    typedef std::map<std::string, int> evidence_dict_t;

    typedef std::set<std::string> prior_active_tf_set_t;

    typedef std::pair<std::string, std::string> src_trg_pair_t;
    typedef std::pair<src_trg_pair_t, int> network_edge_t;
    typedef std::vector<network_edge_t> network_t;
    
    class GraphBase
    {
        private:
        protected:
            gsl_rng * rng;

        public:
            node_vector_t random_nodes;
            node_vector_t norand_nodes; /* Used to keep track of node pointers for later destruction */

            GraphBase (unsigned int);
            virtual ~GraphBase ();

            virtual void build_structure (network_t, evidence_dict_t, prior_active_tf_set_t);

            void sample (unsigned int);
            void burn_stats();
            void print_stats();
    };
}

#endif