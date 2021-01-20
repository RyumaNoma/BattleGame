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

		this->fighter[1].setDirection(Direction::Left);
	}

	void Battle::update()
	{
		for (int i = 0; i < 2; i++)
		{
			if (const auto gamepad = Gamepad(i))
			{
				// �W�����v��
				if (this->fighter[i].getInAirTime() > 0)
				{
					motion::jump(this->fighter[i], this->fighterX[i], this->fighterY[i]);
				}

				// ���[�V������
				if (this->fighter[i].getState() == FighterState::InMotion)
				{
					switch (this->fighter[i].getMotionNum())
					{
					case 1:
						motion::rotateSord(this->fighter[i], this->fighterX[i], this->fighterY[i]);
						break;
					default:
						break;
					}
				}
				// �d����
				else if (this->fighter[i].getState() == FighterState::Rigidity)
				{
					this->fighter[i].decRigidity();
				}
				else if (this->fighter[i].getState() == FighterState::None)
				{
					// L(�E)
					if (gamepad.axes[0] > 0.5)
					{
						this->fighterX[i] += 10;
						this->fighter[i].setDirection(Direction::Right);
					}
					// L(��)
					else if (gamepad.axes[0] < -0.5)
					{
						this->fighterX[i] -= 10;
						this->fighter[i].setDirection(Direction::Left);
					}
					// L(��)
					else if (gamepad.axes[1] < -0.5)
					{
						if (this->fighter[i].getInAirTime() == 0)
						{
							this->fighter[i].setInAirTime(1);
						}
					}
					// A�{�^��
					if (gamepad.buttons[0].pressed())
					{
						this->fighter[i].setMotionNum(1);
					}
				}
			}
		}

		Battle::inField();
	}

	void Battle::draw() const
	{
		Line(0, 700, 1367, 700).draw(Palette::Brown);
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