foreach(ARILES_COMPONENT  core yaml-cpp octave ros)
    find_package(ariles-${ARILES_COMPONENT} REQUIRED)

    list(APPEND pal_ariles_LIBRARIES     "${ariles-${ARILES_COMPONENT}_LIBRARIES}")
    list(APPEND pal_ariles_INCLUDE_DIRS  "${ariles-${ARILES_COMPONENT}_INCLUDE_DIRS}")
endforeach()
