# Collects all .cpp files from current and subdirectories into SOURCE_FILES
file(GLOB_RECURSE SOURCE_FILES "*.cpp")

# Creates a static library named QuestionsLib from the collected source files
add_library(QuestionsLib ${SOURCE_FILES})
target_include_directories(QuestionsLib PUBLIC ../include) # Use ../include here

# Creates the main executable for the project.
add_executable(Questions ${SOURCE_FILES})
target_include_directories(Questions PUBLIC "../include")