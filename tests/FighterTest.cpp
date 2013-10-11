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
				{100000, "������", 102, 20, 30, 40, 10, 20 ,30 , explode, {100001, 100002, 100004, 0}},
				{100001, "��������", 20, 20, 30, 40, 10, 20 ,30 , normal, {100004, 0, 0, 0}},
				{100002, "����������", 30, 20, 30, 40, 10, 20 ,30 , penetrate, {100004, 0, 0, 0}},
				{100004, "�������", 120, 20, 30, 40, 10, 20 ,30 , beatback, {100001, 100000, 0, 0}}
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