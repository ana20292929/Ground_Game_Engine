set(SOURCE_FILES
	Event.cpp
	OpenGLcode/OpenGLPicture.cpp
	OpenGLcode/OpenGLShader.cpp
	OpenGLcode/OpenGLRenderer.cpp
	Picture.cpp
	Shader.cpp
	Renderer.cpp
	Unit.cpp
	GroundApp.cpp
	GroundWindow.cpp
	GLFWcode/GLFWwindowImplementation.cpp
   )

set(HEADER_FILES
	Event.h
	Keys.h
	OpenGLcode/OpenGLPicture.h
	OpenGLcode/OpenGLShader.h
	OpenGLcode/OpenGLRenderer.h
	Picture.h
	Shader.h
	Renderer.h
	PictureImplementation.h
	ShaderImplementation.h
	RendererImplementation.h
	Unit.h
	Ground.h
	GroundApp.h
	GroundUtil.h
	GroundWindow.h
	WindowImplementation.h
	GLFWcode/GLFWwindowImplementation.h
   )

add_library(Ground SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DGROUND_LIB)

target_precompile_headers(Ground PRIVATE pch.h)

include_directories(../glfw/include)
include_directories(../Ground)
include_directories(../glad/include)
include_directories(../stbi)

target_link_libraries(Ground glfw glad stbi)