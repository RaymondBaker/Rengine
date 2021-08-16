
add_library(rengine 
		"include/Events/EventManager.h"
		"include/Scene/Node.h"
		"include/Events/EventHandler.h"
		"include/Util/file.h"
		"include/Events/CollisionEvent.h"
		"include/Events/KeyEvent.h"
		"include/Events/Event.h"
		"include/Scripting/ScriptEngine.h"
		"include/Scripting/SchemeBindings.h"
		"include/Rendering/Renderer.h"
		"include/Rendering/SpriteBatch.h"
		"src/Events/EventHandler.cpp"
		"src/Events/EventManager.cpp"
		"src/Scene/Node.cpp"
		"src/Scripting/ScriptEngine.cpp"
		"src/Events/Event.cpp"
		"src/Scripting/SchemeBindings.cpp"
		"src/Rendering/SpriteBatch.cpp"
		"src/Rendering/Renderer.cpp")
target_include_directories(rengine PUBLIC
                           "include/"
                           )
target_link_libraries(rengine SDL2 sol2 glm )
set_property(TARGET rengine PROPERTY CXX_STANDARD 17)



# add the executable
add_executable(game game.cpp)
target_link_libraries(game rengine)
set_property(TARGET game PROPERTY CXX_STANDARD 17)