
#define BOOST_TEST_MODULE ut_init

#define TEST_INITIALIZATION false


#define TEST_DATA_MANAGER false

#define TEST_ENTITY_COMPONENT false



#if TEST_INITIALIZATION
BOOST_AUTO_TEST_CASE(sfml_init)
{
	sf::RenderWindow window({ 1, 1 }, "sfml_graphics");
	BOOST_ASSERT(window.isOpen());
}

BOOST_AUTO_TEST_CASE(box2d_init)
{
	b2Vec2 gravity(0.0f,-10.0f);
	b2World world(gravity);
}

BOOST_AUTO_TEST_CASE(imgui_sfml_init)
{

	sf::RenderWindow window(sf::VideoMode(1, 1), "");
	ImGui::CreateContext();
	ImGui::SFML::Init(window);

	window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.

	sf::Clock deltaClock;
	while (window.isOpen()) {

		ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::Begin("Sample window"); // begin window
		ImGui::End(); 

		window.clear(); 
		ImGui::SFML::Render(window);
		window.display();
		break;
	}

	ImGui::SFML::Shutdown();
}

#endif // TEST_INITIALIZATION

#if TEST_DATA_MANAGER
BOOST_AUTO_TEST_CASE(data_manager_find_texture_predefined_not_loaded)
{
	DataManager data;

	//Find texture predefined, not loaded
	try {
		data.findTexture("warrior.png");
	}
	catch (std::exception e)
	{
		std::string s = "DataManager: Texture file warrior.png is empty.";
		BOOST_CHECK(s == e.what());
	}
}

BOOST_AUTO_TEST_CASE(data_manager_find_texture_predefined_loaded)
{
	DataManager data;
	//Load data
	data.load("");

	//Find texture loaded and exists
	sf::Texture warriortexture = data.findTexture("warrior.png");
	BOOST_CHECK(warriortexture.getSize() == sf::Vector2u(256, 256));

	//Find texture not exists
	try {
		data.findTexture("abcdtest");
	}
	catch (std::exception e)
	{
		std::string s = "DataManager: Texture abcdtest not found.";
		BOOST_CHECK(s == e.what());
	}

}

BOOST_AUTO_TEST_CASE(data_manager_find_sound_predefined_not_loaded)
{
	DataManager data;

	//Find texture predefined, not loaded
	try {
		data.findSound("whoo.wav");
	}
	catch (std::exception e)
	{
		std::string s = "DataManager: Sound file whoo.wav is empty.";
		BOOST_CHECK(s == e.what());
	}
}

BOOST_AUTO_TEST_CASE(data_manager_find_sound_predefined_loaded)
{
	DataManager data;
	//Load data
	data.load("");

	//Find sound loaded and exists
	sf::SoundBuffer whoosound = data.findSound("whoo.wav");
	BOOST_CHECK(whoosound.getDuration().asSeconds() > 4);

	//Find sound not exists
	try {
		data.findSound("abcdtest");
	}
	catch (std::exception e)
	{
		std::string s = "DataManager: Sound abcdtest not found.";
		BOOST_CHECK(s == e.what());
	}

}
#endif

#if TEST_ENTITY_COMPONENT
BOOST_AUTO_TEST_CASE(entitycomp_init)
{

	enum EntityGroup : std::size_t
	{
		TestEntity
	};

	//Create entity manager 
	g_core::Manager manager;

	//create a new entity and add it to manager
	auto& entity(manager.addEntity());

	//add components to entity
	entity.addComponent<g_core::CPosition>();

	//add group to which entity belongs to
	entity.addGroup(EntityGroup::TestEntity);

	//call draw on all components of entity
	manager.draw();

}
#endif



