# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "algo: 4 messages, 0 services")

set(MSG_I_FLAGS "-Ialgo:/home/sab3r/ws/src/algo/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg;-Ivisualization_msgs:/opt/ros/melodic/share/visualization_msgs/cmake/../msg;-Ialgo:/home/sab3r/ws/src/algo/msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(algo_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/vector_msg.msg" NAME_WE)
add_custom_target(_algo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "algo" "/home/sab3r/ws/src/algo/msg/vector_msg.msg" ""
)

get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/point_msg.msg" NAME_WE)
add_custom_target(_algo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "algo" "/home/sab3r/ws/src/algo/msg/point_msg.msg" "std_msgs/Float32:geometry_msgs/Vector3"
)

get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/vector_array.msg" NAME_WE)
add_custom_target(_algo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "algo" "/home/sab3r/ws/src/algo/msg/vector_array.msg" "algo/vector_msg"
)

get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/Encoder_msg.msg" NAME_WE)
add_custom_target(_algo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "algo" "/home/sab3r/ws/src/algo/msg/Encoder_msg.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(algo
  "/home/sab3r/ws/src/algo/msg/point_msg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Float32.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/algo
)
_generate_msg_cpp(algo
  "/home/sab3r/ws/src/algo/msg/Encoder_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/algo
)
_generate_msg_cpp(algo
  "/home/sab3r/ws/src/algo/msg/vector_array.msg"
  "${MSG_I_FLAGS}"
  "/home/sab3r/ws/src/algo/msg/vector_msg.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/algo
)
_generate_msg_cpp(algo
  "/home/sab3r/ws/src/algo/msg/vector_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/algo
)

### Generating Services

### Generating Module File
_generate_module_cpp(algo
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/algo
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(algo_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(algo_generate_messages algo_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/vector_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_cpp _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/point_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_cpp _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/vector_array.msg" NAME_WE)
add_dependencies(algo_generate_messages_cpp _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/Encoder_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_cpp _algo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(algo_gencpp)
add_dependencies(algo_gencpp algo_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS algo_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(algo
  "/home/sab3r/ws/src/algo/msg/point_msg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Float32.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/algo
)
_generate_msg_eus(algo
  "/home/sab3r/ws/src/algo/msg/Encoder_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/algo
)
_generate_msg_eus(algo
  "/home/sab3r/ws/src/algo/msg/vector_array.msg"
  "${MSG_I_FLAGS}"
  "/home/sab3r/ws/src/algo/msg/vector_msg.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/algo
)
_generate_msg_eus(algo
  "/home/sab3r/ws/src/algo/msg/vector_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/algo
)

### Generating Services

### Generating Module File
_generate_module_eus(algo
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/algo
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(algo_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(algo_generate_messages algo_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/vector_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_eus _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/point_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_eus _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/vector_array.msg" NAME_WE)
add_dependencies(algo_generate_messages_eus _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/Encoder_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_eus _algo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(algo_geneus)
add_dependencies(algo_geneus algo_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS algo_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(algo
  "/home/sab3r/ws/src/algo/msg/point_msg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Float32.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/algo
)
_generate_msg_lisp(algo
  "/home/sab3r/ws/src/algo/msg/Encoder_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/algo
)
_generate_msg_lisp(algo
  "/home/sab3r/ws/src/algo/msg/vector_array.msg"
  "${MSG_I_FLAGS}"
  "/home/sab3r/ws/src/algo/msg/vector_msg.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/algo
)
_generate_msg_lisp(algo
  "/home/sab3r/ws/src/algo/msg/vector_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/algo
)

### Generating Services

### Generating Module File
_generate_module_lisp(algo
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/algo
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(algo_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(algo_generate_messages algo_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/vector_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_lisp _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/point_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_lisp _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/vector_array.msg" NAME_WE)
add_dependencies(algo_generate_messages_lisp _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/Encoder_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_lisp _algo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(algo_genlisp)
add_dependencies(algo_genlisp algo_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS algo_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(algo
  "/home/sab3r/ws/src/algo/msg/point_msg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Float32.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/algo
)
_generate_msg_nodejs(algo
  "/home/sab3r/ws/src/algo/msg/Encoder_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/algo
)
_generate_msg_nodejs(algo
  "/home/sab3r/ws/src/algo/msg/vector_array.msg"
  "${MSG_I_FLAGS}"
  "/home/sab3r/ws/src/algo/msg/vector_msg.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/algo
)
_generate_msg_nodejs(algo
  "/home/sab3r/ws/src/algo/msg/vector_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/algo
)

### Generating Services

### Generating Module File
_generate_module_nodejs(algo
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/algo
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(algo_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(algo_generate_messages algo_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/vector_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_nodejs _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/point_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_nodejs _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/vector_array.msg" NAME_WE)
add_dependencies(algo_generate_messages_nodejs _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/Encoder_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_nodejs _algo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(algo_gennodejs)
add_dependencies(algo_gennodejs algo_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS algo_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(algo
  "/home/sab3r/ws/src/algo/msg/point_msg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Float32.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/algo
)
_generate_msg_py(algo
  "/home/sab3r/ws/src/algo/msg/Encoder_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/algo
)
_generate_msg_py(algo
  "/home/sab3r/ws/src/algo/msg/vector_array.msg"
  "${MSG_I_FLAGS}"
  "/home/sab3r/ws/src/algo/msg/vector_msg.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/algo
)
_generate_msg_py(algo
  "/home/sab3r/ws/src/algo/msg/vector_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/algo
)

### Generating Services

### Generating Module File
_generate_module_py(algo
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/algo
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(algo_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(algo_generate_messages algo_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/vector_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_py _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/point_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_py _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/vector_array.msg" NAME_WE)
add_dependencies(algo_generate_messages_py _algo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sab3r/ws/src/algo/msg/Encoder_msg.msg" NAME_WE)
add_dependencies(algo_generate_messages_py _algo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(algo_genpy)
add_dependencies(algo_genpy algo_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS algo_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/algo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/algo
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(algo_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET visualization_msgs_generate_messages_cpp)
  add_dependencies(algo_generate_messages_cpp visualization_msgs_generate_messages_cpp)
endif()
if(TARGET algo_generate_messages_cpp)
  add_dependencies(algo_generate_messages_cpp algo_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/algo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/algo
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(algo_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET visualization_msgs_generate_messages_eus)
  add_dependencies(algo_generate_messages_eus visualization_msgs_generate_messages_eus)
endif()
if(TARGET algo_generate_messages_eus)
  add_dependencies(algo_generate_messages_eus algo_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/algo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/algo
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(algo_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET visualization_msgs_generate_messages_lisp)
  add_dependencies(algo_generate_messages_lisp visualization_msgs_generate_messages_lisp)
endif()
if(TARGET algo_generate_messages_lisp)
  add_dependencies(algo_generate_messages_lisp algo_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/algo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/algo
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(algo_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET visualization_msgs_generate_messages_nodejs)
  add_dependencies(algo_generate_messages_nodejs visualization_msgs_generate_messages_nodejs)
endif()
if(TARGET algo_generate_messages_nodejs)
  add_dependencies(algo_generate_messages_nodejs algo_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/algo)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/algo\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/algo
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(algo_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET visualization_msgs_generate_messages_py)
  add_dependencies(algo_generate_messages_py visualization_msgs_generate_messages_py)
endif()
if(TARGET algo_generate_messages_py)
  add_dependencies(algo_generate_messages_py algo_generate_messages_py)
endif()
