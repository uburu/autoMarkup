project(auto-markup-app)

set(CMAKE_CXX_STANDART 17)

include_directories(
        ../inc/dict_handler
        ../inc/common
        ../inc/datahub
        ../inc/datastructs
        ../inc/controller
        ../inc/markup
        )

set(COMMON_INC
        ../inc/common/types.hpp
        ../inc/common/exceptions.hpp
        ../inc/common/not_implemented_exception.hpp)


set(HEADERS
        ../inc/datahub/DataHub.hpp
        ../inc/datahub/DataHubBuilder.hpp
        ../inc/controller/controller.hpp
        ../inc/datastructs/dataStructs.hpp
        ../inc/dict_handler/model.hpp
        ../inc/dict_handler/dict_handler.hpp
        )

set(SOURCES
        ../src/datahub/DataHub.cpp
        ../src/datahub/DataHubBuilder.cpp
        ../src/controller/controller.cpp
        ../src/datastructs/dataStructs.cpp
        
        dict_handler/dict_handler.cpp
        main.cpp
        )

add_executable(main ${SOURCES} ${HEADERS})
