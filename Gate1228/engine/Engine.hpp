#pragma once
#include "../core/strictSingleton.hpp"
#include "ent_com_sys/EntityManager.hpp"
#include "data/DataManager.hpp"
#include "control/InputManager.hpp"

class Engine : public StrictSingleton<Engine>
{
public:
	Engine();
	~Engine();

protected:
	std::unique_ptr<EntityManager> g_entity_manager_;
	std::unique_ptr<DataManager> g_data_manager_;
	//std::unique_ptr<input_manager> g_input_manager_;
};


