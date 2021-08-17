cmake_minimum_required(VERSION 3.15)

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
FetchContent_Declare(
  lua_static
  GIT_REPOSITORY https://github.com/walterschell/Lua.git
  GIT_TAG        v5.4.2
)
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG        0.9.9.8
)
FetchContent_Declare(
  EnTT 
  GIT_REPOSITORY https://github.com/skypjack/entt.git
  GIT_TAG        v3.8.1
)
FetchContent_Declare(
  spdlog 
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
	GIT_TAG      v1.9.2  
)

FetchContent_MakeAvailable(SDL2 sol2 glm lua_static EnTT spdlog)


add_subdirectory(Rengine)
add_subdirectory(Game)

