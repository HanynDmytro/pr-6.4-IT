#include "pch.h"
#include "CppUnitTest.h"
#include "../pr6.4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[] = { 1, 2, 3, 4, 5, 6 }; // Непарні індекси: 2, 4, 6
			int size = 6;
			int expectedSum = 2 + 4 + 6;

			Assert::AreEqual(expectedSum, sumOddIndexElements(arr, size));
		}
	};
}
