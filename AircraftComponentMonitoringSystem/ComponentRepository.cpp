#include "ComponentRepository.h"
#include <utility>

const std::vector<std::unique_ptr<AircraftComponent>>& ComponentRepository::getAll() const {  // returns a read only list of all the components in the repository.
    return m_components;                                                                      // caller cannot change the list or the components themselves.
}

AircraftComponent* ComponentRepository::findComponent(const std::string& id) {           // returns a pointer to the component with the matching ID, or nullptr if not found.
    for (const auto& component : m_components) {
        if (component->getId() == id) return component.get();
    }
    return nullptr;
}

bool ComponentRepository::addComponent(std::unique_ptr<AircraftComponent> component) {  // rejects null or duplicate IDs, returns true if successfully added.
    if (!component) return false;
    if (findComponent(component->getId()) != nullptr) return false;
    m_components.push_back(std::move(component));
    return true;
}

bool ComponentRepository::removeComponent(const std::string& id) {                      // returns true if component with this ID was found and removed and false if not found.
    for (auto it = m_components.begin(); it != m_components.end(); ++it) {
        if ((*it)->getId() == id) {
            m_components.erase(it);
            return true;
        }
    }
    return false;
}