
#pragma once
//sample components
class cMainTitleBar : public Component
{
private:
	int test_num_;
public:

	cMainTitleBar(int test_num)
	{
		test_num_ = test_num;
	};
	void init() override {}
	void update(float m_ft) override
	{


		if (ImGui::BeginMainMenuBar())
		{
			ImGui::PushMultiItemsWidths(6, 20.0f);

			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("New Game"))
				{

				};

				if (ImGui::MenuItem("Save Game"))
				{

				};

				if (ImGui::MenuItem("Load Game"))
				{

				};


				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("other"))
			{
				if (ImGui::MenuItem("menu item"))
					ImGui::OpenPopup("popup");
				if (ImGui::MenuItem("menu item"))
					ImGui::OpenPopup("popup");
				ImGui::EndMenu();
			}


			ImGui::PopItemWidth();

			ImGui::EndMainMenuBar();
		}
	};
	void draw(sf::RenderWindow& target) override {}
	void recieve(int message) override
	{
		if (message == test_num_)
		{
			std::cout << "Message 1 Recieved";
		}
	};

	~cMainTitleBar() = default;

};

class CPosition : public Component
{
public:
	sf::Vector2f position;

	CPosition() = default;
	CPosition(const sf::Vector2f& m_position) : position{ m_position } {}

	float x() const noexcept { return position.x; }
	float y() const noexcept { return position.y; }
};

class cEconomyBar : public Component
{
private:
	int wood_;
	int crystal_;
	int alloy_;
	int plastic_;
	int food_;

public:
	cEconomyBar()
	{
		wood_ = 10;
		food_ = 20;
	};

	void init() override {}
	void update(float m_ft) override
	{
		ImGui::SetNextWindowPos(ImVec2(0.0f, 20.0f));
		ImGui::SetNextWindowSize(ImVec2(1920.0f, 100));
		if (ImGui::Begin("economy_bar", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove
			| ImGuiWindowFlags_NoScrollbar))
		{
			ImGui::Button("Wood", ImVec2(100, 25));
			ImGui::SameLine();

			ImGui::Button(ITCSTR(wood_), ImVec2(30, 25));

			ImGui::SameLine();
			ImGui::Button("Food", ImVec2(100, 25));
			ImGui::Button(ITCSTR(food_), ImVec2(30, 25));

			ImGui::SameLine();
			ImGui::Button("Crystal", ImVec2(100, 25));
			ImGui::Button(ITCSTR(crystal_), ImVec2(30, 25));

			ImGui::SameLine();
			ImGui::Button("Alloy", ImVec2(100, 25));
			ImGui::Button(ITCSTR(alloy_), ImVec2(30, 25));

		}

		ImGui::ShowDemoWindow();

		ImGui::End();
	};
	void draw(sf::RenderWindow& target) override {}
	void recieve(int message) override {};

	~cEconomyBar() = default;

};

//sample entityframe
class ConcreteFrame : public EntityFrame
{
public:
	ConcreteFrame()
	{
		frame_->addComponent<cMainTitleBar>(1);
		frame_->addComponent<cEconomyBar>();
	}
};

//sample scene
class MyScene : public Scene
{
	ConcreteFrame myframe;
	Entity* e;
public:
	MyScene(sf::RenderWindow& window) : Scene(window)
	{
		e = &EntityManager::get().add(&myframe);
	};

	void init() override
	{

	};

	void input() override
	{

	};

	void update() override
	{

	};

	void render() override
	{
	};

	void refresh() override
	{
	};

};