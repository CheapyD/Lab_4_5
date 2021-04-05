#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_4_5/FuzzyNumber.cpp"
#include "../Lab_4_5/Pair.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Labtest45
{
	TEST_CLASS(Labtest45)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Pair* A = new FuzzyNumber(4, 1, 7);
			Pair* B = new FuzzyNumber(6, 3, 9);
			Pair* C = new FuzzyNumber();
			C = *A + B;
			Assert::AreEqual(((FuzzyNumber*)C)->GetX(), 10.0);
		}
	};
}
