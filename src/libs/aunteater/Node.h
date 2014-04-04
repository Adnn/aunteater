#ifndef _IDG_AE_Node
#define _IDG_AE_Node

#include "Component.h"
#include <set>
#include <typeinfo>
#include <map>

namespace aunteater
{

    class Entity;
    class Family;
    
    typedef std::set<const std::type_info *> ComponentIds;
    
    class Node
    {
    public:
        class family_access
        {
            friend class Family;
            
            family_access() {};
            family_access(const family_access &) = delete;
            family_access & operator=(const family_access &) = delete;
        };
        
    public:
        explicit Node(const ComponentIds & aIds, Entity & aAssignedEntity, const family_access &);
        
        /// It is an undefined behavior to give a ComponentId that is not present in the collection
        Component & get(const std::type_info *aComponentId);
        
        //std::set<std::type_info * > getComponentsTypeInfo();
        
    private:
        /// \todo Same as with Entity::get() : it would be nice to avoir sharing ownership.
        std::map<const std::type_info *, std::shared_ptr<Component>> mTypedComponents;
        
    };
    
} // namespace aunteater

#endif  // #ifdef