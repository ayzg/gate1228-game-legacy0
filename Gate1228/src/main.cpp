#define RUN_GAME true
#include "Windows.h"
#include "../engine/gGame.hpp"

#if RUN_GAME

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

//BOX2D
#include "Box2D\Box2D.h"

//ImGUI
#include "imgui.h"
#include "imgui-SFML.h"

////
//#include "DataManager.hpp"
//#include "entitycomp.hpp"
//#include "gComponents.hpp"
//
//#include "gGame.hpp"

int main()
{

	g_core::gGame s0;

	s0.run();


	////Load Game Data from Project Folder
	//DataManager data;
	//data.load("");

	////Create Render Target
	//sf::RenderWindow window(sf::VideoMode(1000, 500), "");
	//window.setFramerateLimit(240);

	////Entity Manager
	//g_core::EntityManager entityManager;


	//sf::Sprite testsprite(data.findTexture("warrior.png"));
	//
	////Enter game loop
	//	// Play Loading Cutscene
	//	// Enter Main Menu GAMESTATE::MainMenu
	//		// Play
	//			//Enter world creation setting ->
	//				// GAMETSATE::World - Generate World 
	//					// Event::Escape -> Pause World
	//						// Continue..
	//							//Continue game
	//						// Save
	//							//Parse world into bin file
	//						// Exit
	//							//Exit to GAMESTATE::MainMenu
	//		// Load
	//			//Enter loading menu
	//				//Choose world to load
	//					//GAMESTATE::World 
	//				//Exit - go to main menu
	return EXIT_SUCCESS;
}
#endif // RUN_GAME


