#include "Battle.hpp"

namespace game
{
	Battle::Battle(const InitData& init) : IScene(init)
	{
		for (int i = 0; i < 2; i++)
		{
			this->fighter[i] = getData().fighter[i];
			this->fighterY[i] = 300;
		}
		this->fighterX[0] = 300;
		this->fighterX[1] = 1000;
	}

	void Battle::update()
	{
		for (int i = 0; i < 2; i++)
		{
			if (const auto gamepad = Gamepad(i))
			{
				switch (this->fighter[i].getMotionNum())
				{
				case 1:
					motion::jump(this->fighter[i], this->fighterX[i], this->fighterY[i]);
					break;
				default:
					break;
				}

				// L(ç∂âE)
				if (gamepad.axes[0] > 0.5)
				{
					this->fighterX[i] += 10;
				}
				else if (gamepad.axes[0] < -0.5)
				{
					this->fighterX[i] -= 10;
				}
				// L(è„)
				else if (gamepad.axes[1] < -0.5)
				{
					this->fighter->setMotionNum(1);
				}
			}
		}

		Battle::inField();
	}

	void Battle::draw() const
	{
		for (int i = 0; i < 2; i++)
		{
			this->fighter[i].draw(this->fighterX[i], this->fighterY[i]);
		}
	}

	void Battle::inField()
	{
		for (int i = 0; i < 2; i++)
		{
			if (this->fighterX[i] < 50) this->fighterX[i] = 50;
			if (this->fighterX[i] > 1300) this->fighterX[i] = 1300;
			if (this->fighterY[i] < 0) this->fighterY[i] = 0;
			if (this->fighterY[i] > 300) this->fighterY[0] = 300;
		}
	}
}