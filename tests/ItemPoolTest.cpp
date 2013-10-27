#include "stdafx.h"
#using <system.dll>
#include "CppUnitTest.h"
#include "ItemPool.hpp"
#include "Equipment.hpp"
#include <iostream>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	struct S {
		int a;
		float b;
	};

	TEST_CLASS(ItemPoolTest)
	{
	public:
		
		TEST_METHOD(ItemPoolTest1)
		{
			using namespace System::Diagnostics;
			using namespace System;
			using namespace AIGame;
			cout << is_id_object<Equipment>::value;
			// TODO: Your test code here
			ItemPool<S> pool;
			S s[3] = {{1, 2}, {2, 3}, {3, 4}};
			pool.insert(s[0]);
			pool.insert(s[1]);
			pool.insert(s[2]);
			for (auto iter = pool.begin(); iter != pool.end(); ++iter ) {
				cout << iter->a << "\t" << iter->b << endl;
				Debug::WriteLine(iter->a);
				Debug::WriteLine(iter->b);
				Debug::WriteLine("\n");
			}
		}

	};
}