#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_8.1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

	TEST_METHOD(TestCountFunction)
		{
			char str[] = "abcabcfhg";
			int result = Count(str);
			Assert::AreEqual(2, result); // Очікується, що функція Count поверне 2
		}

		TEST_METHOD(TestChangeFunction)
		{
			char str[] = "abcabcfhg";
			char dest[151];
			dest[0] = '\0';
			char* result = Change(dest, str, dest);
			Assert::AreEqual("****fhg", result); // Очікується, що функція Change замінить  входження "abc" на "**"
		}
	};
}
