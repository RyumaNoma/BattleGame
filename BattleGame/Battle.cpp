#include "Battle.hpp"

namespace game
{
	Battle::Battle(const InitData& init) : IScene(init)
	{
		for (int i = 0; i < 2; i++)
		{
			this->fighter[i] = getData().fighter[i];
			this->fighterY[i] = 600;
		}
		this->fighterX[0] = Scene::Center().x - 700;
		this->fighterX[1] = Scene::Center().x + 700;

		this->fighter[1].setDirection(Direction::Left);

		this->punchAudio = Audio(U"./data/punch.mp3");
	}

	void Battle::update()
	{
		// �U��������������
		for (int i = 0; i < 2; i++)
		{
			// fighter[i]�̍U����fighter[1-i]�ɂ�������
			// �܂��U���𓖂ĂĂ��Ȃ��Ȃ�
			if (Battle::isHit(i, 1 - i) && !this->fighter[i].getGiveDamage())
			{
				// grab�Ȃ�
				// �V�[���h�𒣂��Ă��Ȃ�������
				if (this->fighter[i].getMotionNum() == 3 ||
					this->fighter[1 - i].getState() != FighterState::Shield)
				{
					// ���[�V����������
					Battle::resetMotion(this->fighter[1 - i], 1 - i);

					this->fighter[i].setGiveDamage(true);
					this->fighter[1 - i].hitDamage(motion::motionTable[this->fighter[i].getMotionNum()][1]);
					// �ӂ��Ƃ�
					this->fighter[1 - i].setState(FighterState::Blast);
					this->fighter[1 - i].setBlastCount(15);
					this->fighter[1 - i].setBlastDirection(this->fighter[i].getDirection());
				}
			}

			// ��ѓ����������
			// �V�[���h�����Ă��Ȃ�
			int firearmID = -1;
			if (Battle::isHitToFirearm(i, 1 - i, firearmID) &&
				this->fighter[1 - i].getState() != FighterState::Shield)
			{
				// ���[�V����������
				Battle::resetMotion(this->fighter[1 - i], 1 - i);

				this->fighter[1 - i].hitDamage(motion::motionTable[firearmID][1]);
				debug("firearmID", firearmID);
				debug("state", int(this->fighter[1 - i].getState()));
				// �ӂ��Ƃ�
				this->fighter[1 - i].setState(FighterState::Blast);
				this->fighter[1 - i].setBlastCount(15);
				this->fighter[1 - i].setBlastDirection(this->fighter[i].getDirection());
			}
		}

		//��ѓ���
		for (int i = 0; i < this->firearm.size(); i++)
		{
			switch (this->firearm[i].id)
			{
			case 4:
				motion::slashWave(this->firearm[i]);
				break;
			default:
				break;
			}
		}

		for (int i = 0; i < 2; i++)
		{
			// �V�[���h����
			if (this->fighter[i].getState() == FighterState::Shield)
			{
				this->fighter[i].setState(FighterState::None);
			}

			if (const auto gamepad = Gamepad(i))
			{
				// �W�����v��
				if (this->fighter[i].getInAirTime() > 0)
				{
					motion::jump(this->fighter[i], this->fighterX[i], this->fighterY[i]);
				}

				// ������ђ�
				if (this->fighter[i].getState() == FighterState::Blast)
				{
					if (this->fighter[i].getBlastCount() == 15)
					{
						this->punchAudio.play();
					}
					this->fighter[i].decBlastCount();
					motion::blast(this->fighter[i], this->fighterX[i], this->fighterY[i], this->fighter[i].getBlastDirection(), 30, 20);
				}
				// ���[�V������
				else if (this->fighter[i].getState() == FighterState::InMotion)
				{
					switch (this->fighter[i].getMotionNum())
					{
					case 1:
						motion::rotateSord(this->fighter[i], this->fighterX[i], this->fighterY[i]);
						break;
					case 2:
						motion::throwSord(this->fighter[i], this->fighterX[i], this->fighterY[i]);
						break;
					case 3:
						motion::grab(this->fighter[i], this->fighterX[i], this->fighterY[i]);
						break;
					case 5:
						this->firearm.push_back(Firearm());
						// fighterID�̐ݒ�
						this->firearm[this->firearm.size() - 1].fighterID = i;
						motion::slashWave(this->fighter[i], this->fighterX[i], this->fighterY[i], this->fighter[i].getDirection(), this->firearm[this->firearm.size() - 1]);
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
				// �f�t�H���g�̏��
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

					int skillID = -1;
					// A�{�^��
					if (gamepad.buttons[0].pressed())
					{
						skillID = this->fighter[i].getSkill(0);
						this->fighter[i].setMotionNum(skillID);
					}
					// B�{�^��
					if (gamepad.buttons[1].pressed())
					{
						skillID = this->fighter[i].getSkill(1);
						this->fighter[i].setMotionNum(skillID);
					}
					// X�{�^��
					if (gamepad.buttons[2].pressed())
					{
						skillID = this->fighter[i].getSkill(2);
						this->fighter[i].setMotionNum(skillID);
					}
					// Y�{�^��
					if (gamepad.buttons[3].pressed())
					{
						skillID = this->fighter[i].getSkill(3);
						this->fighter[i].setMotionNum(skillID);
					}
					// ZR�{�^��
					if (gamepad.buttons[5].pressed())
					{
						skillID = this->fighter[i].getSkill(4);
						this->fighter[i].setMotionNum(skillID);
					}

					if (skillID == 4)
					{
						motion::shield(this->fighter[i], this->fighterX[i], this->fighterY[i]);
					}
				}

				if (this->fighter[i].getState() != FighterState::InMotion)
				{
					this->fighter[i].setGiveDamage(false);
				}
			}
		}

		// �����I��
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
		Battle::firearmInField();
		Battle::gravity();
		Battle::eraseFirearm();
	}

	void Battle::draw() const
	{
		// �̗̓Q�[�W
		// 1P
		Rect(0, 0, 800, 100).draw(Palette::Gray);
		Rect(0, 0, this->fighter[0].getHP() * 8, 100).draw(Palette::Skyblue);
		// 2P
		Rect(1180, 0, 800, 100).draw(Palette::Gray);
		Rect(1980 - this->fighter[1].getHP() * 8, 0, this->fighter[1].getHP() * 8, 100).draw(Palette::Skyblue);

		// �n��
		Line(0, 1000, 1980, 1000).draw(Palette::Brown);

		// Fighter
		for (int i = 0; i < 2; i++)
		{
			this->fighter[i].draw(this->fighterX[i], this->fighterY[i]);
		}

		// ��ѓ���
		for (int i = 0; i < this->firearm.size(); i++)
		{
			this->firearm[i].draw();
		}
	}

	bool Battle::isHit(int from, int to) const
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

				// ���������Ȃ�
				if (Rect(p2.base.x + this->fighterX[to], p2.base.y + this->fighterY[to], p2.width, p2.height).rotatedAt(p2.center + Point(this->fighterX[to], this->fighterY[to]), p2.rotate).rotatedAt(Point(static_cast<int>(p2.sordCenterX), static_cast<int>(p2.sordCenterY)) + Point(this->fighterX[to], this->fighterY[to]), p2.sordRotate).intersects(rect))
				{
					return true;
				}
			}
		}

		return false;
	}

	bool Battle::isHitToFirearm(int from, int to, int& firearmID)
	{
		// from
		for (int i = 0; i < this->firearm.size(); i++)
		{
			if (this->firearm[i].fighterID != from) continue;

			const BodyPart p = this->firearm[i].body;
			const auto& firearm = Rect(p.base + this->firearm[i].pos, p.width, p.height)
				.rotatedAt(p.center + this->firearm[i].pos, p.rotate)
				.rotatedAt(Point(static_cast<int>(p.sordCenterX), static_cast<int>(p.sordCenterY)) + this->firearm[i].pos, p.sordRotate);
			// to
			for (int j = 0; j < 7; j++)
			{
				const BodyPart& p2 = this->fighter[to].getPart(j);
				if (!p2.isVisible) continue;
				if (p2.isAttack) continue;

				// ���������Ȃ�
				if (Rect(p2.base.x + this->fighterX[to], p2.base.y + this->fighterY[to], p2.width, p2.height)
					.rotatedAt(p2.center + Point(this->fighterX[to], this->fighterY[to]), p2.rotate)
					.rotatedAt(Point(static_cast<int>(p2.sordCenterX), static_cast<int>(p2.sordCenterY)) + Point(this->fighterX[to], this->fighterY[to]), p2.sordRotate)
					.intersects(firearm))
				{
					// �U������𖳂���
					this->firearm[i].body.isAttack = false;
					firearmID = this->firearm[i].id;
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
			if (this->fighterX[i] > 1930) this->fighterX[i] = 1930;
			if (this->fighterY[i] < 0) this->fighterY[i] = 0;
			if (this->fighterY[i] > 600) this->fighterY[i] = 600;
		}
	}

	void Battle::firearmInField()
	{
		for (int i = 0; i < this->firearm.size(); i++)
		{
			int x = this->firearm[i].pos.x;
			int y = this->firearm[i].pos.y;
			if (x < 0 || 1980 < x ||
				y < 0 || 1000 < y)
			{
				this->firearm.erase(this->firearm.begin() + i);
			}
		}
	}

	// ���t���[��3����������
	void Battle::gravity()
	{
		for (int i = 0; i < 2; i++)
		{
			//�󒆂ɂ���
			// �W�����v�͂��Ă��Ȃ�
			if (this->fighterY[i] < 600 && this->fighter[i].getInAirTime() == 0)
			{
				this->fighterY[i] = std::min(600, this->fighterY[i] + 3);
			}
		}
	}

	void Battle::eraseFirearm()
	{
		for (int i = 0; i < this->firearm.size(); i++)
		{
			if (!this->firearm[i].body.isAttack)
			{
				this->firearm.erase(this->firearm.begin() + i);
			}
		}
	}

	void Battle::resetMotion(Fighter& fighter, int fighterNum)
	{
		fighter.setDirection(Direction::Left);
		getData().fighter[fighterNum].setDirection(Direction::Left);

		for (int i = 0; i < 7; i++)
		{
			fighter.setPart(i, getData().fighter[fighterNum].getPart(i));
		}

		fighter.resetFlame();
		fighter.resetMotionNum();
	}
}