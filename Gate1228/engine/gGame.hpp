#ifndef G_GAME_HPP
#define G_GAME_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include <cassert>
#include <type_traits>
#include <chrono> 
#include <functional>

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

//ImGUI
#include "imgui.h"
#include "imgui-SFML.h"


#include "Engine.hpp"
#include <imgui_internal.h>
#include "control/SceneController.h"


namespace g_core {

	constexpr float ftStep{ 1.f }, ftSlice{ 1.f };
	constexpr float windowX{ 1920.f }, windowY{ 1080.f };


	class gGame
	{
	public:
		bool isRun{ false };

		sf::Clock deltaClock;
		sf::RenderWindow window_;
		sf::View view_;

		gGame();
		~gGame();

		void run();

		void input_phase();
		void update_phase();
		void render_phase();

		void render(const sf::Drawable& mDrawable) { window_.draw(mDrawable); }
	};

}
#endif //G_GAME_HPP