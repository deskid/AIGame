#include "stdafx.h"
/*
#include "CppUnitTest.h"
#include "Fighter.hpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{		
	TEST_CLASS(FighterTest)
	{
		static AIGame::FighterPrototype* tpl;

	public:
		TEST_CLASS_INITIALIZE(init) {
			using namespace AIGame;
			 static FighterPrototype tpls[4] = {
				 {"������", {102, 20, 30, 40, 10, 20 ,30} , {1, 2, 30}, explode, {&tpls[2], &tpls[1], &tpls[3], nullptr}},
				 {"��������", {20, 20, 30, 40, 10, 20 ,30} , {4, 6, 0}, normal, {&tpls[3], nullptr, nullptr, nullptr}},
				 {"����������", {30, 20, 30, 40, 10, 20 ,30} , {10, 10, 10}, penetrate, {&tpls[3], nullptr, nullptr, nullptr}},
				 {"�������", {120, 20, 30, 40, 10, 20 ,30} , {1, 1, 1}, beatback, {&tpls[1], nullptr, nullptr, nullptr}}
			};

			tpl = tpls;
		}

		TEST_METHOD(FighterMethods)
		{
			using namespace AIGame;
			Fighter f(&tpl[1], "���µĿ�����");
		}
		
		TEST_CLASS_CLEANUP(cleanup) {
		}
	};

	AIGame::FighterPrototype* FighterTest::tpl;
}

*/