
add_library(rengine 

		"include/Scene/Node.h"
		"src/Scene/Node.cpp"
		"include/Util/File.h"

		"include/Events/EventManager.h"
		"src/Events/EventManager.cpp"
		"include/Events/EventHandler.h"
		"src/Events/EventHandler.cpp"
		"include/Events/CollisionEvent.h"
		"include/Events/KeyEvent.h"
		"include/Events/Event.h"
		"src/Events/Event.cpp"

		"include/Scripting/ScriptEngine.h"
		"src/Scripting/ScriptEngine.cpp"
		"include/Scripting/SchemeBindings.h"
		"src/Scripting/SchemeBindings.cpp"

		"include/Rendering/Renderer.h"
		"src/Rendering/Renderer.cpp" 
		"include/Rendering/SpriteBatch.h"
		"src/Rendering/SpriteBatch.cpp"

		"include/Scene/EntityManager.h" 
		"src/Scene/EntityManager.cpp" 
		
		"include/Components/Components.h" 
		"include/Util/Logging.h")
target_include_directories(rengine PUBLIC
                           "include/"
                           )
target_link_libraries(rengine SDL2-static sol2 glm lua_static EnTT spdlog)
IF (MSVC)
	set_property(TARGET rengine PROPERTY CXX_STANDARD 17)
	target_compile_options(rengine PRIVATE /W4 /WX)
ELSE ()
	target_compile_options(rengine PRIVATE -Wall -Wextra -pedantic -Werror)
ENDIF ()
