#include "HParentNode.h"

namespace gbn
{
    HParentNode::HParentNode () {}
    HParentNode::~HParentNode () {
        // std::cout << "Object at " << this << " destroyed, instance of  HParentNode\t" << "\t" << typeid(this).name() << std::endl;
    }

    void HParentNode::append_h_child (HNode * h) {
        this->children.push_back(h);
    }
}
