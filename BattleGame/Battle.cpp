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
			if (Battle::isHit(i, 1 - i) && !this->fighter[i].getGiveDamage())
			{
				this->fighter[i].setGiveDamage(true);
				this->fighter[1 - i].hitDamage(motion::motionTable[this->fighter[i].getMotionNum()][1]);
			}

			if (const auto gamepad = Gamepad(i))
			{
				// ジャンプ中
				if (this->fighter[i].getInAirTime() > 0)
				{
					motion::jump(this->fighter[i], this->fighterX[i], this->fighterY[i]);
				}

				// モーション中
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
				// 硬直中
				else if (this->fighter[i].getState() == FighterState::Rigidity)
				{
					this->fighter[i].decRigidity();
				}
				else if (this->fighter[i].getState() == FighterState::None)
				{
					// L(右)
					if (gamepad.axes[0] > 0.5)
					{
						this->fighterX[i] += 10;
						this->fighter[i].setDirection(Direction::Right);
					}
					// L(左)
					else if (gamepad.axes[0] < -0.5)
					{
						this->fighterX[i] -= 10;
						this->fighter[i].setDirection(Direction::Left);
					}
					// L(上)
					else if (gamepad.axes[1] < -0.5)
					{
						if (this->fighter[i].getInAirTime() == 0)
						{
							this->fighter[i].setInAirTime(1);
						}
					}
					// Aボタン
					if (gamepad.buttons[0].pressed())
					{
						this->fighter[i].setMotionNum(1);
					}
				}

				if (this->fighter[i].getState() != FighterState::InMotion)
				{
					this->fighter[i].setGiveDamage(false);
				}
			}
		}

		// 試合終了
		if (this->fighter[0].getHP() == 0 || this->fighter[1].getHP() == 0)
		{
			if (this->fighter[0].getHP() == 0)
			{
				getData().winner = 1;
			}
			else
			{
				getData().winner = 0;
			}

			changeScene(5);
		}

		Battle::inField();
	}

	void Battle::draw() const
	{
		// 体力ゲージ
		// 1P
		Rect(0, 0, 400, 50).draw(Palette::Gray);
		Rect(0, 0, this->fighter[0].getHP() * 4, 50).draw(Palette::Skyblue);
		// 2P
		Rect(966, 0, 400, 50).draw(Palette::Gray);
		Rect(1366 - this->fighter[1].getHP() * 4, 0, this->fighter[1].getHP() * 4, 50).draw(Palette::Skyblue);

		// 地面
		Line(0, 700, 1367, 700).draw(Palette::Brown);
		// Fighter
		for (int i = 0; i < 2; i++)
		{
			this->fighter[i].draw(this->fighterX[i], this->fighterY[i]);
		}
	}

	bool Battle::isHit(int from, int to)
	{
		// from
		for (int i = 0; i < 7; i++)
		{
			const BodyPart& p = this->fighter[from].getPart(i);
			if (!p.isVisible) continue;
			if (!p.isAttack) continue;
			const auto& rect = Rect(p.base.x + this->fighterX[from], p.base.y + this->fighterY[from], p.width, p.height).rotatedAt(p.center + Point(this->fighterX[from], this->fighterY[from]), p.rotate).rotatedAt(Point(static_cast<int>(p.sordCenterX), static_cast<int>(p.sordCenterY)) + Point(this->fighterX[from], this->fighterY[from]), p.sordRotate);
			// to
			for (int j = 0; j < 7; j++)
			{
				const BodyPart& p2 = this->fighter[to].getPart(j);
				if (!p2.isVisible) continue;
				if (p2.isAttack) continue;

				// 当たったなら
				if (Rect(p2.base.x + this->fighterX[to], p2.base.y + this->fighterY[to], p2.width, p2.height).rotatedAt(p2.center + Point(this->fighterX[to], this->fighterY[to]), p2.rotate).rotatedAt(Point(static_cast<int>(p2.sordCenterX), static_cast<int>(p2.sordCenterY)) + Point(this->fighterX[to], this->fighterY[to]), p2.sordRotate).intersects(rect))
				{
					return true;
				}
			}
		}

		return false;
	}

	void Battle::inField()
	{
		for (int i = 0; i < 2; i++)
		{
			if (this->fighterX[i] < 50) this->fighterX[i] = 50;
			if (this->fighterX[i] > 1300) this->fighterX[i] = 1300;
			if (this->fighterY[i] < 0) this->fighterY[i] = 0;
			if (this->fighterY[i] > 300) this->fighterY[i] = 300;
		}
	}
}