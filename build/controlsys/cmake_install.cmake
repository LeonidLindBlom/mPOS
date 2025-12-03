# Install script for directory: /home/mpos/mpos-lab/kos/controlsys/controlsys

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/mpos/mpos-lab/kos/controlsys/build/../install")
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
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/opt/KasperskyOS-Community-Edition-1.2.0.89/toolchain/bin/aarch64-kos-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/InputGuardInterface.idl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/InputGuardInterface.idl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/OutputControllerInterface.idl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/OutputControllerInterface.idl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/CardVerifierInterface.idl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/CardVerifierInterface.idl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/TransactionGeneratorInterface.idl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/TransactionGeneratorInterface.idl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/StatusVerifierInterface.idl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/StatusVerifierInterface.idl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/AuthInterface.idl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/AuthInterface.idl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/JournalInterface.idl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/JournalInterface.idl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateLoaderInterface.idl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateLoaderInterface.idl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateStorageInterface.idl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateStorageInterface.idl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateVerifierInterface.idl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateVerifierInterface.idl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateInstallerInterface.idl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateInstallerInterface.idl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/ControlSys.edl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/ControlSys.edl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/InputGuard.edl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/InputGuard.edl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/OutputController.edl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/OutputController.edl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/CardVerifier.edl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/CardVerifier.edl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/TransactionGenerator.edl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/TransactionGenerator.edl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/StatusVerifier.edl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/StatusVerifier.edl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/AuthModule.edl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/AuthModule.edl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/Journal.edl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/Journal.edl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateLoader.edl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateLoader.edl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateStorage.edl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateStorage.edl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateVerifier.edl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateVerifier.edl.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "nk_headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/controlsys" TYPE FILE FILES
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateInstaller.edl"
    "/home/mpos/mpos-lab/kos/controlsys/build/_headers_/controlsys/../controlsys/UpdateInstaller.edl.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/mpos/mpos-lab/kos/controlsys/build/controlsys/domains/InputGuard/cmake_install.cmake")
  include("/home/mpos/mpos-lab/kos/controlsys/build/controlsys/domains/OutputController/cmake_install.cmake")
  include("/home/mpos/mpos-lab/kos/controlsys/build/controlsys/domains/CardVerifier/cmake_install.cmake")
  include("/home/mpos/mpos-lab/kos/controlsys/build/controlsys/domains/TransactionGenerator/cmake_install.cmake")
  include("/home/mpos/mpos-lab/kos/controlsys/build/controlsys/domains/StatusVerifier/cmake_install.cmake")
  include("/home/mpos/mpos-lab/kos/controlsys/build/controlsys/domains/AuthModule/cmake_install.cmake")
  include("/home/mpos/mpos-lab/kos/controlsys/build/controlsys/domains/Journal/cmake_install.cmake")
  include("/home/mpos/mpos-lab/kos/controlsys/build/controlsys/domains/UpdateLoader/cmake_install.cmake")
  include("/home/mpos/mpos-lab/kos/controlsys/build/controlsys/domains/UpdateStorage/cmake_install.cmake")
  include("/home/mpos/mpos-lab/kos/controlsys/build/controlsys/domains/UpdateVerifier/cmake_install.cmake")
  include("/home/mpos/mpos-lab/kos/controlsys/build/controlsys/domains/UpdateInstaller/cmake_install.cmake")

endif()

