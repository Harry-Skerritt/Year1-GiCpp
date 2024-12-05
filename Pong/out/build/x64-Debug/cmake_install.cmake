# Install script for directory: C:/Users/Harry/OneDrive/Documents/Education/University/Year 1/Games in C++/Assignments/Pong/pong-24-25-Harry-Skerritt

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Harry/OneDrive/Documents/Education/University/Year 1/Games in C++/Assignments/Pong/pong-24-25-Harry-Skerritt/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Harry/OneDrive/Documents/Education/University/Year 1/Games in C++/Assignments/Pong/pong-24-25-Harry-Skerritt/out/build/x64-Debug/_deps/sfml-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Harry/OneDrive/Documents/Education/University/Year 1/Games in C++/Assignments/Pong/pong-24-25-Harry-Skerritt/out/build/x64-Debug/src/AI/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Harry/OneDrive/Documents/Education/University/Year 1/Games in C++/Assignments/Pong/pong-24-25-Harry-Skerritt/out/build/x64-Debug/src/Ball/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Harry/OneDrive/Documents/Education/University/Year 1/Games in C++/Assignments/Pong/pong-24-25-Harry-Skerritt/out/build/x64-Debug/src/Menu/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Harry/OneDrive/Documents/Education/University/Year 1/Games in C++/Assignments/Pong/pong-24-25-Harry-Skerritt/out/build/x64-Debug/src/Option Menu/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Harry/OneDrive/Documents/Education/University/Year 1/Games in C++/Assignments/Pong/pong-24-25-Harry-Skerritt/out/build/x64-Debug/src/Paddle/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Harry/OneDrive/Documents/Education/University/Year 1/Games in C++/Assignments/Pong/pong-24-25-Harry-Skerritt/out/build/x64-Debug/src/Score/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Harry/OneDrive/Documents/Education/University/Year 1/Games in C++/Assignments/Pong/pong-24-25-Harry-Skerritt/out/build/x64-Debug/src/Vector/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/Harry/OneDrive/Documents/Education/University/Year 1/Games in C++/Assignments/Pong/pong-24-25-Harry-Skerritt/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
