cmake_minimum_required(VERSION 3.5)
project(hpx_exercises CXX)

find_package(HPX REQUIRED)

file(GLOB hpx_program_files
  "${PROJECT_SOURCE_DIR}/exercises/*.cpp"
  "${PROJECT_SOURCE_DIR}/solutions/*.cpp")

foreach(hpx_program_file ${hpx_program_files})
  get_filename_component(hpx_program ${hpx_program_file} NAME_WE)
  set(sources ${hpx_program_file})

  add_hpx_executable(
    ${hpx_program}
    SOURCES ${sources}
    COMPONENT_DEPENDENCIES iostreams)
endforeach()
