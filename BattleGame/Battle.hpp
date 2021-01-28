#pragma once

#include <Siv3D.hpp>
#include <vector>
#include "SceneData.hpp"
#include "Fighter.hpp"
#include"Motion.hpp"
#include "Direction.hpp"
#include "FighterState.hpp"
#include "Debug.hpp"
#include "BodyPart.hpp"
#include "Firearm.hpp"

namespace game
{
	using App = SceneManager<int, SceneData>;
	class Battle : public App::Scene
	{
	private:
		Fighter fighter[2];
		int fighterX[2];
		int fighterY[2];
		Audio punchAudio;
		std::vector<Firearm> firearm;
	public:
		Battle(const InitData& init);
		void update() override;
		void draw() const override;

		bool isHit(int from, int to) const;
		bool isHitToFirearm(int from, int to, int& firearmID);

		void inField();
		void firearmInField();
		void gravity();
		// �U�����肪�Ȃ��Ȃ�����ѓ��������
		void eraseFirearm();
		void resetMotion(Fighter& fighter, int fighterNum);
	};
}

