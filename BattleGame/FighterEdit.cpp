#include "FighterEdit.hpp"

namespace game
{
	FighterEdit::FighterEdit(const InitData& init) : IScene(init)
	{
		this->a = 0;
	}

	void FighterEdit::update()
	{
	}

	void FighterEdit::draw() const
	{
		Fighter fighter;
		fighter.draw(300, 100);
	}
}
