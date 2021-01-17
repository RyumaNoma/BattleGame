#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "Header.hpp"

using App = SceneManager<int>;

void Main()
{
	game::debugReset();
	Scene::SetBackground(Palette::White);

	App manager;

	manager.add<game::FighterEdit>(0);

	game::Fighter fighter;
	fighter.setDirection(Direction::Left);
	fighter.setRotate(6, 30);

	double r = 0;
	while (System::Update())
	{
		fighter.draw(200, 100);

		r += Scene::DeltaTime();
		if (r >= 0.1)
		{
			r = 0;
			fighter.addRotate(2, 10);
		}
	}
}