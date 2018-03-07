/**
    @file
    @author  Alexander Sherikov

    @copyright 2017-2018 Alexander Sherikov, Licensed under the Apache License, Version 2.0.
    (see @ref LICENSE or http://www.apache.org/licenses/LICENSE-2.0)

    @brief
*/

#pragma once

class StrictnessFixture : public FixtureBase
{
    protected:
        template<class t_Configurable1, class t_Configurable2, class t_Reader, class t_Writer>
            void test()
        {
            // Exlicit instantiation of reader and writer classes
            BOOST_CHECK_NO_THROW(
                t_Configurable1 configurable;

                t_Writer writer(getInitializer("configurable.cfg"));
                configurable.writeConfig(writer);
            );

            BOOST_CHECK_THROW(
                t_Configurable2 configurable;

                t_Reader reader(getInitializer("configurable.cfg"));
                configurable.readConfig(reader);
                ,
                std::runtime_error
            );

            // --------------------------------

            // Implicit instantiation of reader and writer classes

            BOOST_CHECK_NO_THROW(
                t_Configurable1 configurable;
                configurable.template writeConfig<t_Writer>(getInitializer("configurable2.cfg"));
            );

            BOOST_CHECK_THROW(
                t_Configurable2 configurable;
                configurable.template readConfig<t_Reader>(getInitializer("configurable2.cfg"));
                ,
                std::runtime_error
            );
        }
};