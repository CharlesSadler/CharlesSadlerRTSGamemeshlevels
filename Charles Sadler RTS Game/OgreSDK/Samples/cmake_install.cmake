# Install script for directory: C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/BSP/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/CelShading/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/BezierPatch/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/CameraTrack/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Character/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Compositor/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/CubeMapping/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Dot3Bump/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/DynTex/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/FacialAnimation/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Fresnel/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Grass/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Instancing/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Lighting/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/OceanDemo/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/ParticleFX/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/ShaderSystem/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Shadows/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/SkeletalAnimation/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/SkyBox/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/SkyDome/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/SkyPlane/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Smoke/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/SphereMapping/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/TextureFX/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Transparency/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/VolumeTex/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Water/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/DeferredShading/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Isosurf/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/ParticleGS/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Terrain/cmake_install.cmake")
  INCLUDE("C:/builds/ogre/sources/v1-7/SDK/Win32/vc10/sdk/Samples/Browser/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

