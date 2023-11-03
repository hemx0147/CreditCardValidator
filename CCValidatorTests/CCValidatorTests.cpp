#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "CCValidator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CCValidatorTests
{
	TEST_CLASS(CCValidatorTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(ccval::digitSum(12), 3);
		}
	};
}
