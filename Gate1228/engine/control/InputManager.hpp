#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <SFML/Graphics.hpp>

static bool s_window_has_focus = true;
static bool s_mouse_pressed[3] = { false, false, false };
static bool s_mouse_moved = false;
static sf::Vector2i s_touch_pos;

class input_manager
{
public:
	input_manager();
	~input_manager();

	static void process_event(const sf::Event& event);

};

#endif // INPUT_MANAGER_HPP
