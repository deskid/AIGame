#include "stdafx.h"
#include "CppUnitTest.h"
#include "Fighter.hpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{		
	TEST_CLASS(FighterTest)
	{
		static const AIGame::FighterTemplate* tpl;

	public:
		TEST_CLASS_INITIALIZE(init) {
			using namespace AIGame;
			 static FighterTemplate tpls[4] = {
				{"������", 102, 20, 30, 40, 10, 20 ,30 , explode, {&tpls[2], &tpls[1], &tpls[3], nullptr}},
				{"��������", 20, 20, 30, 40, 10, 20 ,30 , normal, {&tpls[3], nullptr, nullptr, nullptr}},
				{"����������", 30, 20, 30, 40, 10, 20 ,30 , penetrate, {&tpls[3], nullptr, nullptr, nullptr}},
				{"�������", 120, 20, 30, 40, 10, 20 ,30 , beatback, {&tpls[1], nullptr, nullptr, nullptr}}
			};

			tpl = tpls;
		}

		TEST_METHOD(FighterMethods)
		{
			using namespace AIGame;
			Fighter f(&tpl[1], "���µĿ�����");
			Fighter f1(&tpl[2], "�����µĳ���������", 10, 30, 10, 30 ,50, 10 ,30, normal, idle ,nullptr ,30, 30);
		}
		
		TEST_CLASS_CLEANUP(cleanup) {
		}
	};
}