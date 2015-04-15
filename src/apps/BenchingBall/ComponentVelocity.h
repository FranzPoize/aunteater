//
//  ComponentVelocity.h
//
//  Created by Adrien David.
//
//

#ifndef BenchingBall_ComponentVelocity_h
#define BenchingBall_ComponentVelocity_h

#include "Vec2.h"

#include <aunteater/Component.h>

namespace BenchingBall {

struct ComponentVelocity : public aunteater::Component, public Vec2
{
    ComponentVelocity(double x, double y) : Vec2{x, y}
    {}

private:
    COMP_CLONE(ComponentVelocity)
};

} // namespace BenchingBall

#endif
