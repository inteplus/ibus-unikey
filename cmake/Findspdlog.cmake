IF(spdlog_FOUND)
  RETURN()
ENDIF()

FIND_PATH(SPDLOG_INCLUDE_DIR spdlog/spdlog.h HINT ${EXTERNAL_ROOT}/include)

SET(SPDLOG_INCLUDE_DIRS ${SPDLOG_INCLUDE_DIR} )

INCLUDE(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set spdlog_FOUND to TRUE
# if all listed variables are TRUE
FIND_PACKAGE_HANDLE_STANDARD_ARGS(spdlog DEFAULT_MSG SPDLOG_INCLUDE_DIR)
