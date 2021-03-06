/**
    @file
    @author  Alexander Sherikov

    @copyright 2018 Alexander Sherikov, Licensed under the Apache License, Version 2.0.
    (see @ref LICENSE or http://www.apache.org/licenses/LICENSE-2.0)

    @brief
*/

#pragma once


class ConfigurableMember : virtual public ariles::ConfigurableBase
{
    #define ARILES_SECTION_ID "ConfigurableMember"
    #define ARILES_ENTRIES \
        ARILES_TYPED_ENTRY_(integer, int) \
        ARILES_TYPED_ENTRY_(real   , double)
    #include ARILES_INITIALIZE


    public:
        ConfigurableMember()
        {
            setDefaults();
        }

        virtual ~ConfigurableMember() {}


        virtual void setDefaults()
        {
            integer_ = 10;
            real_ = 1.33;
        }


#ifndef ARILES_TESTS_BOOST_UTF_DISABLED
        void randomize()
        {
            integer_ = GET_RANDOM_INT;
            real_    = GET_RANDOM_REAL;
            finalize();
        }
#endif
};


class ConfigurableBase : virtual public ariles::ConfigurableBase
{
    #define ARILES_SECTION_ID "ConfigurableBase"
    #define ARILES_ENTRIES \
        ARILES_TYPED_ENTRY_(member,         ConfigurableMember)
    #include ARILES_INITIALIZE


    public:
        ConfigurableBase()
        {
            setDefaults();
        }

        virtual ~ConfigurableBase() {}


        virtual void setDefaults()
        {
            member_.setDefaults();
        }


#ifndef ARILES_TESTS_BOOST_UTF_DISABLED
        void randomize()
        {
            member_.randomize();
            finalize();
        }
#endif
};


class ConfigurableDerived : public ConfigurableBase, public ConfigurableMember
{
    #define ARILES_SECTION_ID "ConfigurableDerived"
    #define ARILES_ENTRIES \
        ARILES_PARENT(ConfigurableBase) \
        ARILES_PARENT(ConfigurableMember) \
        ARILES_TYPED_ENTRY_(another_member,         ConfigurableMember)
    #include ARILES_INITIALIZE


    public:
        ConfigurableDerived()
        {
            setDefaults();
        }


        void setDefaults()
        {
            another_member_.setDefaults();
            ConfigurableBase::setDefaults();
            ConfigurableMember::setDefaults();
        }


#ifndef ARILES_TESTS_BOOST_UTF_DISABLED
        void randomize()
        {
            another_member_.randomize();
            ConfigurableBase::randomize();
            ConfigurableMember::randomize();
            finalize();
        }
#endif
};
