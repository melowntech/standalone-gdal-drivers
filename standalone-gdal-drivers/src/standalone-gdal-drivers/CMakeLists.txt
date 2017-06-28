define_module(BINARY standalone-gdal-drivers
  DEPENDS gdal-drivers GDAL)

buildsys_position_independent(${MODULE_LIBRARIES})

# create standalone library
add_library(standalone-gdal-drivers MODULE standalone-gdal-drivers.cpp)
buildsys_library(standalone-gdal-drivers)
buildsys_target_compile_definitions(standalone-gdal-drivers ${MODULE_DEFINITIONS})
target_link_libraries(standalone-gdal-drivers ${MODULE_LIBRARIES})
set_target_properties(standalone-gdal-drivers PROPERTIES
  PREFIX "" OUTPUT_NAME "gdal_Melown"
  )
