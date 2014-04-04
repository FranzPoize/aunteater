#include "Family.h"

#include "Engine.h"
#include "Entity.h"

#include <algorithm>

using namespace aunteater;

Family::Family(Engine & aEngine, ComponentIds aComponentsTypeInfo):
        mEngine(aEngine),
        mComponentsTypeInfo(aComponentsTypeInfo)
{
    
}

void Family::testEntityInclusion(Entity &aEntity)
{
    addIfMatch(aEntity);
}

void Family::addIfMatch(Entity &aEntity)
{
    if (std::all_of(mComponentsTypeInfo.begin(), mComponentsTypeInfo.end(),
                    [&aEntity](const std::type_info *compId){return aEntity.has(compId);}))
    {
        mNodes.emplace_back(mComponentsTypeInfo, aEntity, Node::family_access());
    }
}
/*
void Family::removeEntity(std::shared_ptr<Entity> aEntity)
{
    removeIfMatch(aEntity);
}

void Family::componentAddedToEntity(std::shared_ptr<Entity> aEntity, <#std::type_info *aComponent#>)
{
    
}
*/