/**
    @file
    @author  Alexander Sherikov
    @copyright

    @brief Loosely based on
        https://github.com/opencv/opencv/blob/3.0.0/modules/hal/include/opencv2/hal/defs.h
*/

#pragma once

#include <stdint.h>
#include <string.h>

namespace ariles
{
    inline int isNaN( double value )
    {
        uint64_t raw;
        memcpy(&raw, &value, sizeof(double));
        return (    ((uint32_t)(raw >> 32) & 0x7fffffff)
                    + ((uint32_t)raw != 0) > 0x7ff00000 );
    }


    inline int isInfinity( double value )
    {
        uint64_t raw;
        memcpy(&raw, &value, sizeof(double));
        return (    ((uint32_t)(raw >> 32) & 0x7fffffff) == 0x7ff00000
                    && (uint32_t)raw == 0 );
    }


    inline int isNaN( float value )
    {
        uint32_t raw;
        memcpy(&raw, &value, sizeof(float));
        return ( (raw & 0x7fffffff) > 0x7f800000 );
    }


    inline int isInfinity( float value )
    {
        uint32_t raw;
        memcpy(&raw, &value, sizeof(float));
        return ( (raw & 0x7fffffff) == 0x7f800000 );
    }
}
