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
			 FighterTemplate tpls[4] = { 
				{100000, "可怕兽", 102, 20, 30, 40, 10, 20 ,30 , explode, {100001, 100002, 100004, 0}},
				{100001, "更可怕兽", 20, 20, 30, 40, 10, 20 ,30 , normal, {100004, 0, 0, 0}},
				{100002, "超级可怕兽", 30, 20, 30, 40, 10, 20 ,30 , penetrate, {100004, 0, 0, 0}},
				{100004, "最可怕兽", 120, 20, 30, 40, 10, 20 ,30 , beatback, {100001, 100000, 0, 0}}
			};

			tpl = tpls;
		}

		TEST_METHOD(FighterMethods)
		{
			using namespace AIGame;
			Fighter f(&tpl[1], "可怕的可怕兽");
			Fighter f1(&tpl[2], "不可怕的超级可怕兽", 10, 30, 10, 30 ,50, 10 ,30, normal, idle ,nullptr ,30, 30);
		}
		
		TEST_CLASS_CLEANUP(cleanup) {
		}
	};
}