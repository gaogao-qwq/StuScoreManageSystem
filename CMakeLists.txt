project(StuScoreManageSystem)
add_executable(StuScoreManageSystem main.c StuScoreManageSystem.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=GBK")