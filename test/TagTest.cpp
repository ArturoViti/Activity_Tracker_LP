#include <gtest/gtest.h>
#include "../model/Tag.h"

class TagTest : public ::testing::Test {
    protected:
        std::string name;

        void SetUp() override {
            name = "Lavoro";
        }
};

TEST_F( TagTest, TagNoException ) {
    Tag tag(name);
    ASSERT_EQ( name, tag.getName() );
}

TEST_F( TagTest, EmptyNameException ) {
    ASSERT_THROW( new Tag( "" ), EmptyTagNameException );
}

TEST_F( TagTest, TagEqualOperator ) {
    Tag tag(name);
    Tag tag2(name);
    ASSERT_EQ( tag, tag2 );
}