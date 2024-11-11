# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\gestionservice_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\gestionservice_autogen.dir\\ParseCache.txt"
  "gestionservice_autogen"
  )
endif()
