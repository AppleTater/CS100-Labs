CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
	unit_test.cpp
	container.hpp
	ListContainer.hpp
	VectorContainer.hpp
	preorder_iterator.cpp
	unary_iterator.cpp
	binary_iterator.cpp
)

ADD_EXECUTABLE(lab
	main.cpp
	container.hpp
        ListContainer.hpp
        VectorContainer.hpp
        preorder_iterator.cpp
        unary_iterator.cpp
        binary_iterator.cpp	
)

TARGET_LINK_LIBRARIES(test gtest)

TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
