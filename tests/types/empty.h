/**
    @file
    @author  Alexander Sherikov

    @copyright 2018 Alexander Sherikov, Licensed under the Apache License, Version 2.0.
    (see @ref LICENSE or http://www.apache.org/licenses/LICENSE-2.0)

    @brief
*/

#pragma once



/**
 * @brief Configurable class without extra constructors.
 */
class ConfigurableEmpty : public ariles::ConfigurableBase
{
    #define ARILES_SECTION_ID "unique_id_on_a_particular_level_in_a_configuration_file"
    #define ARILES_ENTRIES
    #include ARILES_INITIALIZE


    public:
        ConfigurableEmpty()
        {
            setDefaults();
        }


        /**
         * @brief This method must be defined
         */
        virtual void setDefaults()
        {
        }


        void randomize()
        {
            finalize();
        }
};
