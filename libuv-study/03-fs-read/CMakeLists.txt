project(study-uv LANGUAGES C)

set(sources main.c)

include_directories(~/code/github.com/libuv/libuv/include)
link_directories(~/code/github.com/libuv/libuv/build)
link_libraries(uv)


add_executable(main ${sources})
