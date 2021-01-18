#pragma once

#include <Siv3D.hpp>
#include <fstream>
#include <string>
#include <vector>
#include "Fighter.hpp"
#include "Function.hpp"
#include "SceneData.hpp"
#include "Button.hpp"
#include "FighterData.hpp"

namespace game
{
	using App = SceneManager<int, SceneData>;

	class FighterEdit : public App::Scene
	{
	private:
		std::string out;
		// �\���p�̃t�@�C�^�[
		Fighter fighter;
		// �I�΂ꂽ�t�@�C�^�[�̔ԍ�
		int fighterNum;
		// �S�t�@�C�^�[��FighterData
		std::vector<FighterData> allFighterData;
		// �I�΂ꂽ����
		int selectPart;
		// ���̕��ʂ̐F
		Color selectColor;
		// �e�L�X�g�{�b�N�X
		TextEditState red;
		TextEditState green;
		TextEditState blue;
	public:
		FighterEdit(const InitData& init);
		void update() override;
		void draw() const override;

		void saveFighterData();
	};
}

