/**
    @file
    @author  Alexander Sherikov

    @copyright 2017-2018 Alexander Sherikov, Licensed under the Apache License, Version 2.0.
    (see @ref LICENSE or http://www.apache.org/licenses/LICENSE-2.0)

    @brief
*/


#include "utility.h"

#ifdef ARILES_BRIDGE_yaml_cpp03
#include "ariles/formats/yaml_cpp03.h"
#endif

#ifdef ARILES_BRIDGE_yaml_cpp
#include "ariles/formats/yaml_cpp.h"
#endif

#ifdef ARILES_BRIDGE_msgpack
#include "ariles/formats/msgpack.h"
#endif

#ifdef ARILES_BRIDGE_ros
#include "ariles/formats/ros.h"
#endif

#include "ariles/adapters_all.h"
#include "ariles/ariles.h"


// ===============================================================
// TYPES
// ===============================================================

#include "types/pointers.h"



// ===============================================================
// FIXTURES
// ===============================================================


#include "fixtures/initializers.h"
#include "fixtures/000_basic_interface.h"
#include "fixtures/001_constructor_interface.h"
#include "fixtures/002_comparison.h"
#include "fixtures/004_comparison_equivalence.h"


// ===============================================================
// TESTS
// ===============================================================

#define ARILES_TESTS(NAMESPACE, INITIALIZER) \
    ARILES_FIXTURE_TEST_CASE(BasicInterfaceFixture, NAMESPACE, ConfigurablePointers, INITIALIZER) \
    ARILES_FIXTURE_TEST_CASE(ConstructorInterfaceFixture, NAMESPACE, ConfigurablePointers, INITIALIZER) \
    ARILES_FIXTURE_TEST_CASE(ComparisonSimpleFixture, NAMESPACE, ConfigurablePointers, INITIALIZER) \
    ARILES_FIXTURE_TEST_CASE(ComparisonMultiFixture, NAMESPACE, ConfigurablePointers, INITIALIZER)

#include "instantiate.h"
