﻿#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include "Header.hpp"

using App = SceneManager<int, game::SceneData>;

void Main()
{
	constexpr Size sceneSize = DisplayResolution::FHD_1920x1080;
	Scene::Resize(sceneSize);
	Window::Resize(sceneSize, WindowResizeOption::KeepSceneSize);
	// 全画面化
	(void)Window::SetFullscreen(true, unspecified, WindowResizeOption::KeepSceneSize);

	game::debugReset();
	Scene::SetBackground(Palette::White);
	FontAsset::Register(U"Title", 60, Typeface::Heavy);
	FontAsset::Register(U"Normal", 30);

	App manager;
	manager.add<game::MainMenu>(0);
	manager.add<game::FighterEditMenu>(1);
	manager.add<game::FighterEdit>(2);
	manager.add<game::FighterSelect>(3);
	manager.add<game::Battle>(4);
	manager.add<game::Result>(5);
	

	while (System::Update())
	{
		manager.update();
	}
}