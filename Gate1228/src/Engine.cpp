
#include "../engine/Engine.hpp"


Engine::Engine()
{
	g_data_manager_.reset(new DataManager);
	g_entity_manager_.reset(new EntityManager);
	//g_input_manager_.reset(new input_manager);
}


Engine::~Engine()
{
}

Engine g_engine;