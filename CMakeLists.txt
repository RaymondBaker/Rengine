cmake_minimum_required(VERSION 3.11)

# set the project name
project(Rengine VERSION 0.1)


# Dependancies
include(FetchContent)
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG        release-2.0.16
)
FetchContent_Declare(
  sol2
  GIT_REPOSITORY https://github.com/ThePhD/sol2.git
  GIT_TAG        v3.2.2
)
#FetchContent_Declare(
#  lua_static
#  GIT_REPOSITORY https://github.com/walterschell/Lua.git
#  GIT_TAG        v5.4.2
#)

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG        0.9.9.8
)

FetchContent_MakeAvailable(SDL2 sol2 glm)


add_subdirectory(Rengine)

