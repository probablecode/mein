cmake_minimum_required(VERSION 3.23)
project(jiyun)

set(CMAKE_CXX_STANDARD 98)
include_directories(.)
include_directories(./config)
include_directories(./utils)

add_executable(test
        utils/CustomException.hpp
        utils/CustomException.cpp
        utils/MyString.hpp
        utils/MyString.cpp
        Client.hpp
        Client.cpp
        ClientSocket.hpp
        ClientSocket.cpp
        Config.hpp
        Config.cpp
        ConfigDefines.hpp
        ConfigUtils.cpp
        ConfigUtils.hpp
        ListeningSocket.hpp
        ListeningSocket.cpp
        LocationConfig.hpp
        LocationConfig.cpp
        main.cpp
        Location.hpp
        Location.cpp
        Server.hpp
        Server.cpp
        ServerConfig.hpp
        ServerConfig.cpp
        ServerBlock.hpp
        ServerBlock.cpp
        Socket.hpp
        Socket.cpp
        Udata.hpp
        Udata.cpp
        Webserv.hpp
        Webserv.cpp
        defines.hpp
        )