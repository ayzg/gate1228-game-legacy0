#include "../engine/ent_com_sys/EntityManager.hpp"
#include <cassert>

#pragma region EntityManagerAccessors

/*!
* @method: entities()
* @purpose: direct read access to dynamic array of initialized enitties.
* @note: 
*/
EntityManager::entity_uptr_list& EntityManager::entities()
{
	return entities_;
}

#pragma endregion

#pragma region EntityManagerMethods

/*!
* @method: update()
* @purpose: calls update() on all initialized entities.
* @note: used in the update phase of the main loop.
*/
void EntityManager::update(const float m_ft)
{
	for (auto& e : entities_) e->update(m_ft);
}

/*!
* @method: update(sf::RenderWindow& target)
* @param: sf::RenderWindow& : window to
* @purpose: calls draw() on all initialized entities.
* @note: used in the update phase of the main loop.
*/
void EntityManager::draw(sf::RenderWindow& target)
{
	for (auto& e : entities_) e->draw(target);
}


/*!
* @method:entities()
* @purpose: deletes entities in entities_ vector, if their exists() flag is true.
* @usage: call at the end of a frame to delete unused entities.
*/
void EntityManager::refresh()
{
	entities_.erase(
		std::remove_if(std::begin(entities_), std::end(entities_),
		[](const std::unique_ptr<Entity>& t_entity)
		{ return !t_entity->exists(); }),
		std::end(entities_));
	entities().shrink_to_fit();
}

#pragma endregion

#pragma region EntityManagerModifiers
/*!
* @method:entities()
* @purpose: deletes entities in entities_ vector, if their exists() flag is true.
* @usage: call at the end of a frame to delete unused entities.
*/
Entity& EntityManager::add(EntityFrame* eframe)
{
	auto entptr = eframe->create();
	std::unique_ptr<Entity> uPtr(entptr);
	entities_.emplace_back(std::move(uPtr));
	return *entptr;
}
#pragma endregion

#pragma endregion