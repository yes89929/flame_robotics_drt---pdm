#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rbpodo_hardware::rbpodo_hardware" for configuration "Release"
set_property(TARGET rbpodo_hardware::rbpodo_hardware APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rbpodo_hardware::rbpodo_hardware PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librbpodo_hardware.so"
  IMPORTED_SONAME_RELEASE "librbpodo_hardware.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS rbpodo_hardware::rbpodo_hardware )
list(APPEND _IMPORT_CHECK_FILES_FOR_rbpodo_hardware::rbpodo_hardware "${_IMPORT_PREFIX}/lib/librbpodo_hardware.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
