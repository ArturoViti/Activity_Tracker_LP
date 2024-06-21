#include <gtest/gtest.h>
#include "../model/Place.h"

class PlaceTest : public ::testing::Test {
    protected:
        std::string location;
        std::string name;

        void SetUp() override {
            location = "Università di Firenze";
            name = "Aula 006";
        }
};

TEST_F( PlaceTest, PlaceNoException ) {
    Place place(name, location);
    std::string serialized = name + " - " + location;
    ASSERT_EQ( serialized, place.serializePlace() );
}

TEST_F( PlaceTest, EmptyNameException ) {
    ASSERT_THROW( new Place( "", location ), EmptyPlaceNameException );
}