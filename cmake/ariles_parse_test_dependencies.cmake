function(ariles_parse_test_dependencies DEPENDENCIES LINK_TO_LIBRARIES TGT_DEPENDS)
    set(MISSING_DEPENDENCY OFF)

    foreach(DEPENDENCY ${DEPENDENCIES})
        list (FIND ARILES_BRIDGES "${DEPENDENCY}" INDEX)

        if (${INDEX} GREATER -1)
            if (ARILES_BRIDGE_${DEPENDENCY})
                list(APPEND TGT_DEPENDS "${BRIDGE_TARGET_PREFIX}_${DEPENDENCY}")
                list(APPEND LINK_TO_LIBRARIES "${ARILES_BRIDGE_${DEPENDENCY}_LIBS}")
            else()
                set(MISSING_DEPENDENCY ON)
            endif()
        else()
            string(COMPARE NOTEQUAL "${DEPENDENCY}" "DIFF_WITH_REFERENCE" COMPARE_RESULT)
            if (COMPARE_RESULT)
                set(MISSING_DEPENDENCY ON)
            endif(COMPARE_RESULT)
        endif()
    endforeach(DEPENDENCY)


    set(LINK_TO_LIBRARIES   "${LINK_TO_LIBRARIES}"  PARENT_SCOPE)
    set(TGT_DEPENDS         "${TGT_DEPENDS}"        PARENT_SCOPE)
    set(MISSING_DEPENDENCY  "${MISSING_DEPENDENCY}" PARENT_SCOPE)
endfunction()
