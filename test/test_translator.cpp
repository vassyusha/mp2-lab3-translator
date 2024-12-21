#include "Translator.h"

#include <gtest.h>

TEST(TranslatorInput, canTakeAnIntegerNumber) {
	std::map<std::string, double> m;
	std::string s = "123";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
}

TEST(TranslatorInput, canTakeRealNumbersOnlyIn2Ways) {
	std::map<std::string, double> m;
	std::string s1 = "1.";
	std::string s2 = "0.1";
	std::string s3 = ".1";
	std::string s4 = "1.2.3";

	Translator t;
	ASSERT_NO_THROW(t.translate(s1, m));
	ASSERT_NO_THROW(t.translate(s2, m));
	ASSERT_ANY_THROW(t.translate(s3, m));
	ASSERT_ANY_THROW(t.translate(s4, m));
}

TEST(TranslatorInput, canTakeANegativeIntegerOrRealNumber) {
	std::map<std::string, double> m;
	std::string s1 = "-1";
	std::string s2 = "-1.0";
	std::string s3 = "-2.";


	Translator t;
	ASSERT_NO_THROW(t.translate(s1, m));
	ASSERT_NO_THROW(t.translate(s2, m));
	ASSERT_NO_THROW(t.translate(s3, m));
}

TEST(TranslatorInput, cantTakeOnlyAnOperationSymbol) {
	std::map<std::string, double> m;
	std::string s1 = "+";
	std::string s2 = "-";
	std::string s3 = "*";
	std::string s4 = "/";

	Translator t;
	ASSERT_ANY_THROW(t.translate(s1, m));
	ASSERT_ANY_THROW(t.translate(s2, m));
	ASSERT_ANY_THROW(t.translate(s3, m));
	ASSERT_ANY_THROW(t.translate(s4, m));
}

TEST(TranslatorAddition, canAdd2IntegerNumbers) {
	std::map<std::string, double> m;
	std::string s = "2+3";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_EQ(5, t.translate(s, m));
}

TEST(TranslatorAddition, canAddMoreThan2IntegerNumbers) {
	std::map<std::string, double> m;
	std::string s = "2+3+7";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_EQ(12, t.translate(s, m));
}

TEST(TranslatorAddition, canAddIntegerAndRealNumbersInBothOrders) {
	std::map<std::string, double> m;
	std::string s = "2+3.5";
	std::string s1 = "2.6+3";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_EQ(5.5, t.translate(s, m));

	ASSERT_NO_THROW(t.translate(s1, m));
	EXPECT_EQ(5.6, t.translate(s1, m));
}

TEST(TranslatorAddition, canAddRealNumbers) {
	std::map<std::string, double> m;
	std::string s = "2.1+3.5";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_EQ(5.6, t.translate(s, m));
}

TEST(TranslatorSubstraction, canSubstract2IntegerNumbers) {
	std::map<std::string, double> m;
	std::string s = "2-3";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_EQ(-1, t.translate(s, m));
}

TEST(TranslatorSubstraction, canSubstractMoreThan2IntegerNumbers) {
	std::map<std::string, double> m;
	std::string s = "2-3-7";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_EQ(-8, t.translate(s, m));
}

TEST(TranslatorSubstraction, canSubstractIntegerAndRealNumbersInBothOrders) {
	std::map<std::string, double> m;
	std::string s = "2-3.5";
	std::string s1 = "2.6-3";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_GE(1e-7, t.translate(s, m)+1.5);

	ASSERT_NO_THROW(t.translate(s1, m));
	EXPECT_GE(1e-7, t.translate(s1, m)+0.4);
}

TEST(TranslatorSubstraction, canSubstractRealNumbers) {
	std::map<std::string, double> m;
	std::string s = "2.1-3.5";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_GE(1e-7, t.translate(s, m)+1.4);
}

TEST(TranslatorMultiplication, canMultiply2IntegerNumbers) {
	std::map<std::string, double> m;
	std::string s = "2*3";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_EQ(6, t.translate(s, m));
}

TEST(TranslatorMultiplication, canMultiplyMoreThan2IntegerNumbers) {
	std::map<std::string, double> m;
	std::string s = "2*3*7";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_EQ(42, t.translate(s, m));
}

TEST(TranslatorMultiplication, canMultiplyIntegerAndRealNumbersInBothOrders) {
	std::map<std::string, double> m;
	std::string s = "2*3.5";
	std::string s1 = "2.6*3";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_GE(1e-7, t.translate(s, m) -7);

	ASSERT_NO_THROW(t.translate(s1, m));
	EXPECT_GE(1e-7, t.translate(s1, m) -7.8);
}

TEST(TranslatorMultiplication, canMultiplyRealNumbers) {
	std::map<std::string, double> m;
	std::string s = "2.1*3.5";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_GE(1e-7, t.translate(s, m) -(2.1*3.5));
}

TEST(TranslatorDivision, canDivide2IntegerNumbers) {
	std::map<std::string, double> m;
	std::string s = "2/3";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_EQ((2./3), t.translate(s, m));
}

TEST(TranslatorDivision, canDivideMoreThan2IntegerNumbers) {
	std::map<std::string, double> m;
	std::string s = "2/3/7";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_EQ((2./3/7), t.translate(s, m));
}

TEST(TranslatorDivision, canDivideIntegerAndRealNumbersInBothOrders) {
	std::map<std::string, double> m;
	std::string s = "2/3.5";
	std::string s1 = "2.6/3";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_GE(1e-7, t.translate(s, m) - 2/3.5);

	ASSERT_NO_THROW(t.translate(s1, m));
	EXPECT_GE(1e-7, t.translate(s1, m) - 2.6/3);
}

TEST(TranslatorDivision, canDivideRealNumbers) {
	std::map<std::string, double> m;
	std::string s = "2.1/3.5";

	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_GE(1e-7, t.translate(s, m) - (2.1/3.5));
}

TEST(TranslatorDivision, cantDivideBy0) {
	std::map<std::string, double> m;
	std::string s1 = "2.1/0";
	std::string s2 = "2/0";

	Translator t;
	ASSERT_ANY_THROW(t.translate(s1, m));
	ASSERT_ANY_THROW(t.translate(s2, m));
}

TEST(TranslatorDivision, cantDivideByCalculated0) {
	std::map<std::string, double> m;
	std::string s1 = "2.1/(1-1)";
	std::string s2 = "2/(1/3*3-1)";

	Translator t;
	ASSERT_ANY_THROW(t.translate(s1, m));
	ASSERT_ANY_THROW(t.translate(s2, m));
}

TEST(TranslatorBrackets, canTakeCorrectExpressionWithBrackets) {
	std::map<std::string, double> m;
	std::string s = "(1-2)*3/4";


	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_GE(1e-7, t.translate(s,m) +0.75);
}

TEST(TranslatorBrackets, cantTakeOnlyBracketsEvenIfItIsCorrectBracketSequence) {
	std::map<std::string, double> m;
	std::string s = "(()())";


	Translator t;
	ASSERT_ANY_THROW(t.translate(s, m));

}

TEST(TranslatorBrackets, cantTakeOnlyANumberInBrackets) {
	std::map<std::string, double> m;
	std::string s = "(2)";


	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));

}

TEST(TranslatorBrackets, cantTakeAnExpressionWithIncorrectBracketSequence) {
	std::map<std::string, double> m;
	std::string s = "(1+2)*)/(7+(";


	Translator t;
	ASSERT_ANY_THROW(t.translate(s, m));

}

TEST(TranslatorNegation, canNegateExpressionInBracket) {
	std::map<std::string, double> m;
	std::string s = "-(2*7+9/11)";


	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_GE(1e-7, t.translate(s, m) + (2./7+9./11));
}

TEST(TranslatorNegation, canBeUsedAfterAnOpeningBracket) {
	std::map<std::string, double> m;
	std::string s = "2+(-1)";


	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_GE(1e-7, t.translate(s, m) -1);
}

TEST(TranslatorNegation, simpleNegationTest) {
	std::map<std::string, double> m;
	std::string s = "2+-1";


	Translator t;
	ASSERT_NO_THROW(t.translate(s, m));
	EXPECT_GE(1e-7, t.translate(s, m) - 1);
}

TEST(TranslatorVariable, canAssignANumberToAVariable) {
	std::map<std::string, double> m;
	std::string s1 = "a1 = 1.8";
	std::string s2 = "a1";


	Translator t;
	ASSERT_NO_THROW(t.translate(s1, m));
	EXPECT_GE(1e-7, t.translate(s2, m) - 1.8);
}

TEST(TranslatorVariable, canAssignCalculatedValueToAVariable) {
	std::map<std::string, double> m;
	std::string s1 = "a1 = 1.8+3/7";
	std::string s2 = "a1";


	Translator t;
	ASSERT_NO_THROW(t.translate(s1, m));
	EXPECT_GE(1e-7, t.translate(s2, m) - (1.8+3./7));
}

TEST(TranslatorVariable, cantAssignANumberToANumber) {
	std::map<std::string, double> m;
	std::string s1 = "3 = 1.8";

	Translator t;
	ASSERT_ANY_THROW(t.translate(s1, m));

}

TEST(TranslatorVariable, cantUseUndefinedVariable) {
	std::map<std::string, double> m;
	std::string s1 = "3 + a1";

	Translator t;
	ASSERT_ANY_THROW(t.translate(s1, m));
}

TEST(TranslatorVariable, canChangeVariablesValue) {
	std::map<std::string, double> m;
	std::string s1 = "a1 = 3";
	std::string s2 = "a1 = 5.7";
	std::string s3 = "a1";

	Translator t;
	t.translate(s1, m);
	ASSERT_NO_THROW(t.translate(s2, m));
	EXPECT_GE(1e-7, t.translate(s3, m) - 5.7);
}

TEST(TranslatorVariable, canUseDefinedValueInCalculations) {
	std::map<std::string, double> m;
	std::string s1 = "a1 = 2";
	std::string s2 = "3/a1 + 4";


	Translator t;
	ASSERT_NO_THROW(t.translate(s1, m));
	EXPECT_GE(1e-7, t.translate(s2, m) - (5.5));
}

TEST(TranslatorVariable, canAssignCalculatedWithAVariableExpressionToTheSameVariable) {
	std::map<std::string, double> m;
	std::string s1 = "a1 = 2";
	std::string s2 = "a1 = 2*a1-7/3";
	std::string s3 = "a1";

	Translator t;
	t.translate(s1, m);
	ASSERT_NO_THROW(t.translate(s2, m));
	EXPECT_GE(1e-7, t.translate(s3, m) - (4-7./3));
}