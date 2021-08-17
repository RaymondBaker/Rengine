
# add the executable
# TODO check if on windows WIN32
IF (MSVC)
	add_executable(game WIN32 game.cpp)
	set_property(TARGET game PROPERTY LINK_FLAGS /SUBSYSTEM:CONSOLE)
	target_compile_options(game PRIVATE /W4 /WX)
ELSE ()
	add_executable(game game.cpp)
	target_compile_options(game PRIVATE -Wall -Wextra -pedantic -Werror)
ENDIF ()
target_link_libraries(game rengine SDL2main)
set_property(TARGET game PROPERTY CXX_STANDARD 17)
