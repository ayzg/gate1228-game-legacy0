//include game class
#include "../engine/gGame.hpp"

//Include your game-specific files here
#include "../engine/samples.hpp"

#include "../game/gate_components.hpp"
#include "../game/gate_ent_frames.hpp"
#include "../game/gate_scenes.hpp"



namespace g_core {

	using namespace std;

	gGame::gGame()
	{
		// 1. Load Game Data from Project Folder
		//dmanager_.load("");

		//2. Create SFML Render Target
		window_.create(sf::VideoMode(windowX, windowY), "");
		view_.setSize(sf::Vector2f(windowX, windowY));
		window_.setFramerateLimit(60);

		// 3. Create ImGUI Context
		ImGui::CreateContext();

		// 4. Initialize ImGUI to the SFML window
		ImGui::SFML::Init(window_);

	}

	gGame::~gGame()
	{
		//Destroy ImGUI context attached to SFML window 
		ImGui::SFML::Shutdown();
	}

	void gGame::run()
	{
		MyScene scene(window_);

		scene.init();

		while (window_.isOpen()) {

			//Restart frame clock
			deltaClock.restart();

			//Clear previous frame
			window_.clear();

			update_phase();

			input_phase();

			render_phase();

		}
	};

	void gGame::input_phase()
	{
		sf::Event user_event;

		while (window_.pollEvent(user_event))
		{
			//Process imGUI events
			ImGui::SFML::ProcessEvent(user_event);

			//Process SFML game events
			if (user_event.type == sf::Event::Closed)
			{
				window_.close();
				break;
			}
		}
	};

	void gGame::update_phase()
	{
		//Update imGUi
		ImGui::SFML::Update(window_, deltaClock.restart());
		
		//Update Entities
		EntityManager::get().update(deltaClock.restart().asSeconds());

		//Refresh Entities
		EntityManager::get().refresh();

		//SceneController::get->update();


	};

	void gGame::render_phase()
	{
		window_.setView(view_);

		//Draw all entities by entitiy manager
		EntityManager::get().draw(window_);

		//Render imGUI last
		ImGui::SFML::Render(window_);

		//Display rendered window
		window_.display();
	};



}
