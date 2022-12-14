//headers
#include "Data_Parser_And_Converter_Tests.h"
#include "Data_Parser_And_Converter.h"
#include "../gtest/gtest.h"
#include <map>

/// <summary>
/// 
/// </summary>
Data_Parser_And_Converter_Tests::Data_Parser_And_Converter_Tests() {
    RUN_ALL_TESTS();
}
// test map converter

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(DataParserAndConverter, PositiveMapConverter) {
    std::map<std::string , std::string> testedMap = Data_Parser_And_Converter::parseDataThenConvertToMap("," , "::" , "Name::Ahmed,Age::27");
    EXPECT_EQ("Ahmed", testedMap["Name"]);
    EXPECT_EQ(testedMap["Age"], "27");
    EXPECT_EQ(testedMap.size(), 2);
}

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(DataParserAndConverter, PositiveMapConverterNoFirstDelimiterInString) {
    std::map<std::string, std::string> testedMap = Data_Parser_And_Converter::parseDataThenConvertToMap(",", "::", "Age::27");
    EXPECT_EQ(testedMap["Age"], "27");
    EXPECT_EQ(testedMap.size(), 1);
}

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(DataParserAndConverter, PositiveMapConverterNoDelimitersInString) {
    std::map<std::string, std::string> testedMap = Data_Parser_And_Converter::parseDataThenConvertToMap(",", "::", "Age");
    EXPECT_EQ(testedMap["Age"], "");
    EXPECT_EQ(testedMap.size(), 1);
}

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(DataParserAndConverter, PositiveMapConverterNoString) {
    std::map<std::string, std::string> testedMap = Data_Parser_And_Converter::parseDataThenConvertToMap(",", "::", "");
    EXPECT_EQ(testedMap.size(), 0);
}

// test pair converter

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(DataParserAndConverter, PositivePairConverter) {
    std::pair<std::string, std::string> testedPair = Data_Parser_And_Converter::parseDataThenConvertToPair("::", "Name::Ahmed");
    EXPECT_EQ(testedPair.first, "Name");
    EXPECT_EQ(testedPair.second, "Ahmed");
}

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(DataParserAndConverter, PositivePairConverterManyDelimiterInString) {
    std::pair<std::string, std::string> testedPair = Data_Parser_And_Converter::parseDataThenConvertToPair("::", "Name::Ahmed::Eldakhly");
    EXPECT_EQ(testedPair.first, "Name");
    EXPECT_EQ(testedPair.second, "Ahmed::Eldakhly");
}

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(DataParserAndConverter, PositivePairConverterNoDelimitersInString) {
    std::pair<std::string, std::string> testedPair = Data_Parser_And_Converter::parseDataThenConvertToPair("::", "Eldakhly");
    EXPECT_EQ(testedPair.first, "Eldakhly");
    EXPECT_EQ(testedPair.second, "");
}

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(DataParserAndConverter, PositivePairConverterNoString) {
    std::pair<std::string, std::string> testedPair = Data_Parser_And_Converter::parseDataThenConvertToPair(",", "");
    EXPECT_EQ(testedPair.first, "");
    EXPECT_EQ(testedPair.second, "");
}

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(DataParserAndConverter, NegativePairConverterWrongDelimiter) {
    std::pair<std::string, std::string> testedPair = Data_Parser_And_Converter::parseDataThenConvertToPair(",", "Name::Eldakhly");
    EXPECT_EQ(testedPair.first, "Name::Eldakhly");
    EXPECT_EQ(testedPair.second, "");
}

// test vector converter

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(DataParserAndConverter, PositiveVectorConverter) {
    std::vector<std::string> testedvector = Data_Parser_And_Converter::parseDataThenConvertToVector(",", "Ahmed,Abdaallah,Eldakhly");
    EXPECT_EQ(testedvector[0], "Ahmed");
    EXPECT_EQ(testedvector[1], "Abdaallah");
    EXPECT_EQ(testedvector[2], "Eldakhly");
    EXPECT_EQ(testedvector.size(), 3);
}

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(DataParserAndConverter, NegativeVectorConverterWrongDelimiter) {
    std::vector<std::string> testedvector = Data_Parser_And_Converter::parseDataThenConvertToVector("::", "Ahmed,Abdaalah,Eldakhly");
    EXPECT_EQ(testedvector[0], "Ahmed,Abdaalah,Eldakhly");
    EXPECT_EQ(testedvector.size(), 1);
}

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(DataParserAndConverter, NegativeVectorConverterEmptyString) {
    std::vector<std::string> testedvector = Data_Parser_And_Converter::parseDataThenConvertToVector("::", "");
    EXPECT_EQ(testedvector.size(), 0);
}