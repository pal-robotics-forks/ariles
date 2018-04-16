/**
    @file
    @author  Alexander Sherikov

    @copyright 2017-2018 Alexander Sherikov, Licensed under the Apache License, Version 2.0.
    (see @ref LICENSE or http://www.apache.org/licenses/LICENSE-2.0)

    @brief
*/

#include "utility.h"

// Enable ROS configuration files (must be first)
#include "ariles/formats/ros.h"

#include "ariles/adapters_all.h"

// definition of ariles::ConfigurableBase
#include "ariles/ariles.h"


// ===============================================================
// TYPES
// ===============================================================


/**
 * @brief Short definition of a configurable class -- types of members are
 * passed to Ariles for automatic declaration.
 */
class Configurable : public ariles::ConfigurableBase
{
    #define ARILES_SECTION_ID "Configurable"
    #define ARILES_CONSTRUCTOR Configurable
    #define ARILES_ENTRIES \
        ARILES_TYPED_ENTRY_(real,        double)
    #include ARILES_INITIALIZE


    public:
        Configurable()
        {
            setDefaults();
        }


        /**
         * @brief This method must be defined
         */
        virtual void setDefaults()
        {
            real_ = 1.33;
        }


        void randomize()
        {
            real_    = GET_RANDOM_REAL;
            finalize();
        }
};


// ===============================================================
// FIXTURES
// ===============================================================

#include "fixtures/base_ros.h"
#include "fixtures/008_read_write.h"


// ===============================================================
// TESTS
// ===============================================================

#define ARILES_TESTS(NAMESPACE) \
    ARILES_FIXTURE_TEST_CASE(ReadWriteFixture, NAMESPACE, Configurable)

ARILES_TESTS(ros)