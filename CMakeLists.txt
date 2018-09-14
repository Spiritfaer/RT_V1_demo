cmake_minimum_required(VERSION 3.12)
project(RT_V1_demo C)

set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

include_directories(libft src)
include_directories(~/.brew/Cellar/sdl2/2.0.8/include/SDL2/)
include_directories(~/.brew/Cellar/sdl2_image/2.0.3/include/SDL2/)
include_directories(~/.brew/Cellar/sdl2_mixer/2.0.2_3/include/SDL2/)
include_directories(~/.brew/Cellar/sdl2_ttf/2.0.14/include/SDL2/)

link_directories(libft src)
link_directories(~/.brew/Cellar/sdl2/2.0.8/lib/)
link_directories(~/.brew/Cellar/sdl2_image/2.0.3/lib/)
link_directories(~/.brew/Cellar/sdl2_mixer/2.0.2_3/lib/)
link_directories(~/.brew/Cellar/sdl2_ttf/2.0.14/lib/)

set(SOURCE_FILE main.c)

add_executable(RT_V1_demo ${SOURCE_FILE})
target_link_libraries(RT_V1_demo -lft
		-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
		"-framework OpenGL" "-framework AppKit")