#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ATestingTime/calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Addition) //each unit test
		{
			calculator calc;
			float answer = calc.add(3.2f, 1.1f);

			// assert that the result of adding 3.2 and 1.1 is 4.3
			Assert::AreEqual(4.3f, answer);
		}

		TEST_METHOD(Subtraction)
		{
			calculator calc;
			float answer = calc.sub(3.1f, 0.8f);

			// assert that the result of subtracting 0.8 from 3.1 is 2.3
			Assert::AreEqual(2.3f, answer);
		}

		TEST_METHOD(Multiplication)
		{
			calculator calc;
			float answer = calc.mul(3.2f, 4.0f);

			// assert that the result of multiplying 3.2 by 4.0 is 12.8
			Assert::AreEqual(12.8f, answer);
		}

		TEST_METHOD(Division)
		{
			calculator calc;
			float answer = calc.div(5.2f, 2.6f);

			// assert that the result of dividing 5.2 by 2.6 is 2
			Assert::AreEqual(2.0f, answer);
		}

	};
}