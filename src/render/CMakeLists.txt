include_directories(${CMAKE_SOURCE_DIR}/include)
find_package(assimp)
find_package(glm)
find_package(glfw3)

set(GLAD_DIR C:/library/glad/0.1.34/x64-windows)
add_library(glad ${GLAD_DIR}/src/glad.c)
target_include_directories(glad PRIVATE ${GLAD_DIR}/include)

set(OPENGL_LIB assimp::assimp glad glm glfw -lXrandr -lX11 -lXxf86vm -lpthread -lXcursor -lXinerama -ldl)
set(RENDER_LIB ${CMAKE_SOURCE_DIR}/lib/stb_image.cpp)


file(GLOB_RECURSE RENDER_SRC *.cpp *.h)
get_filename_component(MAIN main.cpp ABSOLUTE)
get_filename_component(GENERATOR shader/helper/shader_literal_generator.cpp ABSOLUTE)
list(REMOVE_ITEM RENDER_SRC ${MAIN} ${GENERATOR})


add_executable(shader_literal_generator shader/helper/shader_literal_generator.cpp)

set(V_SHADER_LITERAL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/shader/helper/vertex_literal.cpp)
add_custom_command (OUTPUT ${V_SHADER_LITERAL_PATH}
                    COMMAND shader_literal_generator ../vertex.glsl
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shader/helper
                    DEPENDS shader_literal_generator ${CMAKE_SOURCE_DIR}/src/render/shader/vertex.glsl)

set(F_SHADER_LITERAL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/shader/helper/fragment_literal.cpp)
add_custom_command (OUTPUT ${F_SHADER_LITERAL_PATH}
                    COMMAND shader_literal_generator ../fragment.glsl
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shader/helper
                    DEPENDS shader_literal_generator ${CMAKE_SOURCE_DIR}/src/render/shader/fragment.glsl)


add_library(Render ${RENDER_SRC} ${RENDER_LIB} ${V_SHADER_LITERAL_PATH} ${F_SHADER_LITERAL_PATH})
target_link_libraries(Render ${OPENGL_LIB})
